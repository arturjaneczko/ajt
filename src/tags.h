#ifndef TAGS_H
#define TAGS_H

void printTags(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data) {
	std::cout << purple("[ TAGS ]") << std::endl;
	if (0 == data.size()) {
		std::cout << "\t" << purple("No tags.") << std::endl;
		return;
	}
	std::cout << "\t" << purple("[ normal ]") << std::endl;
	for (const auto & entry : data) {
		std::pair<std::pair<std::string, std::vector<std::string>>, std::string> pairs = entry.second;
		std::pair<std::string, std::vector<std::string>> fileNameWithTags = pairs.first;
		std::vector<std::string> tags = fileNameWithTags.second;
		if (0 < tags.size()) {
			std::cout << "\t" << green(fileNameWithTags.first) << std::endl;
			for (int i=0; i<tags.size(); i++) {
				std::cout << "\t" << "\t" << yellow(tags[i]) << std::endl;
			}
		}
	}
	std::cout << "\t" << purple("[ pivot ]") << std::endl;
	std::set<std::string> uniqueTags;
	for (const auto & entry : data) {
		std::pair<std::pair<std::string, std::vector<std::string>>, std::string> pairs = entry.second;
		std::pair<std::string, std::vector<std::string>> fileNameWithTags = pairs.first;
		std::vector<std::string> tags = fileNameWithTags.second;
		for (int i=0; i<tags.size(); i++) {
			uniqueTags.insert(tags[i]);
		}
	}
	for (auto u : uniqueTags) {
		std::vector<std::string> fileNames;
		for (const auto & entry : data) {
			std::pair<std::pair<std::string, std::vector<std::string>>, std::string> pairs = entry.second;
			std::pair<std::string, std::vector<std::string>> fileNameWithTags = pairs.first;
			std::vector<std::string> tags = fileNameWithTags.second;
			bool contains = std::find(tags.begin(), tags.end(), u) != tags.end();
			if (contains) {
				fileNames.push_back(fileNameWithTags.first);
			}
		}
		std::cout << "\t" << yellow(u) << std::endl;
		for (int i=0; i<fileNames.size(); i++) {
			std::cout << "\t" << "\t" << green(fileNames[i]) << std::endl;
		}
	}
}

#endif// TAGS_H
