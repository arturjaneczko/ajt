#include <iostream>
#include <string>
#include "command.h"
#include "data.h"
#include "keys.h"
#include "search.h"
#include "tags.h"

int main() {
	std::cout << info() << std::endl;
	std::cout << manual() << std::endl;
	std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> map = data();
	while (true) {
		std::cout << green("> ");
		std::string input = "";
		std::cin >> input;
		if (command::isQuit(input)) {
			exit(0);
		} else if (command::isHelp(input)) {
			command::printHelp();
		} else if (command::isManual(input)) {
			command::printManual();
		} else if (command::isInfo(input)) {
			command::printInfo();
		} else if (command::isClear(input)) {
			system("clear");
		} else if (command::isKeys(input)) {
			printKeys(map);
		} else if (command::isTags(input)) {
			printTags(map);
		} else {
			if (command::isSearch(input)) {
				search(map, input);
			} else if ('#' != input[0]) {
				if (map.count(input)) {
					std::cout << yellow(map[input].second) << std::endl;
					std::cout << green("---") << std::endl;
					std::string file = "(" + map[input].first.first + ")";
					std::cout << green(file) << std::endl;
				} else {
					std::string error = "|- Data for key: '" + input + "' not found!";
					std::cout << red(error) << std::endl;
				}
			} else if ('#' == input[0] && input.length() > 1) {
				std::vector<std::string> filesWithTags;
				for (const auto & entry : map) {
					std::string fileNameCandidate = entry.second.first.first;
					std::vector<std::string> tagCandidates = entry.second.first.second;
					bool contains = (std::find(tagCandidates.begin(), tagCandidates.end(), input) != tagCandidates.end());
					if (contains) {
						filesWithTags.push_back(fileNameCandidate);
					}
				}
				for (int i=0; i<filesWithTags.size(); i++) {
					std::cout << green("(" + filesWithTags[i] + ")") << std::endl;
				}
				if (filesWithTags.size() == 0) {
					std::string error = "|- Data for tag: '" + input + "' not found!";
					std::cout << red(error) << std::endl;
				}
			} else {
				if ('#' == input[0] && input.length() < 2) {
					std::string error = "|- Define tag!";
					std::cout << red(error) << std::endl;
				} else {
					std::cout << red("!!! UNKNOWN ERROR !!!") << std::endl;
				}
			}
		}
	}
	return 0;
}
