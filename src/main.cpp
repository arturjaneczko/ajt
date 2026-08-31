#include <iostream>
#include <string>
#include "command.h"
#include "data.h"
#include "groups.h"
#include "keys.h"
#include "status.h"
#include "new.h"
#include "search.h"
#include "tags.h"

std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> filtered(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data, std::string filter) {
	std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> temp;
	for (auto d : data) {
		std::string path = d.second.first.first;
		if (path.find(filter) != std::string::npos) {
			temp[d.first] = d.second;
		}
	}
	return temp;
}

int main() {
	std::cout << info() << std::endl;
	std::cout << manual() << std::endl;
	std::filesystem::create_directory("AJT/");

	bool isNormalMode = true;
	std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> map = data(isNormalMode);
	std::string filter = "./";

	while (true) {
		std::cout << "\n";
		bool isRootFilter = filter == "./";
		std::string delimiter = "--------------------------------";
		std::cout << (isRootFilter ? delimiter : gray(delimiter)) << "\n";
		std::string ajtFilter = gray("[") + yellow(" --- ") + gray("AJT") + yellow(" --- ") + gray("]");
		std::string output = isRootFilter ? (purple("[") + blue(filter) + purple("]") + green("> ")) : (ajtFilter + green("> "));
		std::cout << output;
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
		} else if (command::isGroups(input)) {
			std::string group = printGroups(map);
			filter = group;
		} else if (command::isKeys(input)) {
			printKeys(filtered(map, filter));
		} else if (command::isTags(input)) {
			printTags(filtered(map, filter));
		} else if (command::isSearchCommand(input)) {
			printSearch();
		} else if (command::isStatus(input)) {
			printStatus(filtered(map, filter));
		} else if (command::isNew(input)) {
			createAndEditNew();
			map = data(isNormalMode);
		} else if (command::isAjt(input)) {
			isNormalMode = !isNormalMode;
			map = data(isNormalMode);
			filter = isNormalMode ? "./" : "./AJT";
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
