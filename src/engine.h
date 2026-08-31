#ifndef ENGINE_H
#define ENGINE_H

#include <map>
#include <string>
#include <vector>
#include <set>
#include <functional>
#include <iostream>

using EngineData = std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>>;
using EngineFunc = std::function<std::pair<std::string, std::set<std::string>>(const EngineData&, const std::string&)>;

void printResult(std::pair<std::string, std::set<std::string>> result, std::string seq) {
	const std::string ITALIC = "\033[3m";
	const std::string RESET = "\033[0m";
	std::string key = result.first;
	std::string plain = "[ " + key + " ] " + seq;
	std::string filter = gray(ITALIC + " (Type " + ("." == key ? "content" : "#" == key ? "tag" : "key") + " to filter...)" + RESET);
	std::string indicator = purple("[ ") + blue(key) + purple(" ] ") + ("" == seq ? filter : green(seq));
	std::cout << indicator << "\r\n";
	for (const auto r : result.second) {
		std::cout << "\t" << yellow(r) << "\r\n";
	}
	size_t lines = result.second.size() + 1;
	if (lines > 0) {
		std::cout << "\033[" << lines << "A";// up
	}
	std::cout << "\033[" << plain.size() << "C";// right
	std::cout << std::flush;
}

void engine(const EngineData& data, const EngineFunc& func) {

	// clear bufor
	int discard;
	while ((discard = getchar()) != EOF) {
		if (discard == '\n' || discard == '\r') break;
	}
	
	system("clear");
	std::string seq = "";	
	std::pair<std::string, std::set<std::string>> result = func(data, seq);
	printResult(result, seq);

	system("stty raw");
	while(true) {
		char c = getchar();
		if (c == '\x1B') {
			break;
		} else if (c == 127) {
			if (!seq.empty()) {
				seq.pop_back();
			}
		} else {
			seq.push_back(c);
		}
		result = func(data, seq);
		system("clear");
		printResult(result, seq);
	}
	system("stty cooked");
	system("clear");
}

#endif // ENGINE_H
