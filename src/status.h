#include <map>
#include <string>
#include "color.h"

#ifndef STATUS_H
#define STATUS_H

void printStatus(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data) {
	std::cout << purple("[ STATUS ]") << "\n";

	int keysCount = data.size();
	std::cout << "\t" << blue(std::to_string(keysCount)) << purple(" keys.") << "\n";

	std::vector<std::string> tags;
	std::set<std::string> groups;
	for (auto entry : data) {
		std::vector<std::string> subTags = entry.second.first.second;
		std::string group = entry.second.first.first;
		std::string path = group.substr(0, group.rfind('/'));
		groups.insert(path);

		for (auto subTag : subTags) { 
			auto it = std::find(tags.begin(), tags.end(), subTag);
			bool exists = it != tags.end();
			if (!exists) {
				tags.push_back(subTag);
			}
		}
	}
	int tagsCount = tags.size();
	int groupsCount = groups.size() + 1;
	std::cout << "\t" << blue(std::to_string(tagsCount)) << purple(" tags.") << "\n";
	std::cout << "\t" << blue(std::to_string(groupsCount)) << purple(" groups.") << "\n";
}

#endif// STATUS_H
