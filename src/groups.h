#include <algorithm>

#ifndef GROUPS_H
#define GROUPS_H

std::string printGroups(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data) {
	std::cout << purple("[ GROUPS ]") << std::endl;

	std::vector<std::string> paths;
	std::map<int, std::string> groups;
	int index = 0;
	groups[index++] = "./";
	if (0 < data.size()) {
		for (std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>>::iterator it = data.begin(); it != data.end(); ++it) {
			std::string dataText = it->second.first.first;
			auto lastPositionOfSlash = dataText.rfind('/');
			std::string path = dataText.substr(0, lastPositionOfSlash);
			bool hasValue = std::any_of(paths.begin(), paths.end(), [&](const auto& v) {
				return v == path;
			});
			if (!hasValue) {
				paths.push_back(path);
			}
		}
	}

	std::sort(paths.begin(), paths.end());
	for (auto p : paths) {
		groups[index++] = p;
	}
	
	for (const auto group : groups) {
		std::string key = purple("[ ") + blue(std::to_string(group.first)) + purple(" ]");
		std::string separator = yellow(" -> ");
		std::string value = green(group.second);
		std::string s = key + separator + value;
		std::cout << "\t" << s << "\n";
	}

	std::cout << blue("Select group:") << "\n";
	std::cout << green(">") << " ";
	std::string input = "";
	int nr = -1;
	do {
		std::cin >> input;
		bool isDigit = !input.empty() && std::all_of(input.begin(), input.end(), ::isdigit);
		if (isDigit) {
			nr = std::stoi(input);
			if (nr < 0 || nr >= groups.size()) {
				std::cout << red("Invalid group - ") << red(input) << red("!") << "\n";
				std::cout << blue("Select group:") << "\n";
			}
		} else {
			std::cout << red("Invalid group - ") << red(input) << red("!") << "\n";
			std::cout << blue("Select group:") << "\n";
			continue;
		}
	} while (nr < 0 || nr >= groups.size());
	return groups[nr];
}

#endif// GROUPS_H
