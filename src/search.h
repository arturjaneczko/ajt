#include <functional>
#include "engine.h"

#ifndef SEARCH_H
#define SEARCH_H

bool contains(std::string seq, std::string value) {
	return seq.find(value) != std::string::npos;
}

std::pair<std::string, std::set<std::string>> keySearch(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data, std::string input) {
	std::set<std::string> result;
	for (const auto & entry : data) {
		std::string key = entry.first;
		if (contains(key, input)) {
			std::pair<std::pair<std::string, std::vector<std::string>>, std::string> fileNameWithTagsAndContent = entry.second;
			std::pair<std::string, std::vector<std::string>> fileNameWithTags = fileNameWithTagsAndContent.first;
			std::string fileName = fileNameWithTags.first;
			result.insert(fileName);
		}
	}
	return std::make_pair("?", result);
}

std::pair<std::string, std::set<std::string>> tagSearch(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data, std::string input) {
	std::set<std::string> result;
	for (const auto & entry : data) {
		std::pair<std::pair<std::string, std::vector<std::string>>, std::string> fileNameWithTagsAndContent = entry.second;
		std::pair<std::string, std::vector<std::string>> fileNameWithTags = fileNameWithTagsAndContent.first;
		std::vector<std::string> tags = fileNameWithTags.second;
		for (const auto & tag : tags) {
			if (contains(tag, input)) {
				std::string fileName = fileNameWithTags.first;
				result.insert(fileName);
			}
		}
	}
	return std::make_pair("#", result);
}

std::pair<std::string, std::set<std::string>> contentSearch(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data, std::string input) {
	std::set<std::string> result;
	for (const auto & entry : data) {
		std::pair<std::pair<std::string, std::vector<std::string>>, std::string> fileNameWithTagsAndContent = entry.second;
		std::string content = fileNameWithTagsAndContent.second;
		std::vector<std::string> splitted = split(content);
		for (const auto & s : splitted) {
			if (contains(s, input)) {
				std::pair<std::string, std::vector<std::string>> fileNameWithTags = fileNameWithTagsAndContent.first;
				std::string fileName = fileNameWithTags.first;
				result.insert(fileName);
			}
		}
	}
	return std::make_pair(".", result);
}

void search(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data, std::string input) {
	if (command::isContentSearch(input)) {
		engine(data, &contentSearch);
	} else if (command::isTagSearch(input)) {
		engine(data, &tagSearch);
	} else if (command::isKeySearch(input)) {
		engine(data, &keySearch);
	}
}

void printSearch() {
	std::cout << " " << purple("[ SEARCH ]") << std::endl;
	std::cout << "\t" << green("?") << " " << yellow("<key>") << purple(" - key search | ") << purple("[") << " " << blue("?") << " " << purple("] indicator") << std::endl;
	std::cout << "\t" << green("?#") << " " << yellow("<tag>") << purple(" - tag search | ") << purple("[") << " " << blue("#") << " " << purple("] indicator") << std::endl;
	std::cout << "\t" << green("?.") << " " << yellow("<sequence>") << purple(" - content search | ") << purple("[") << " " << blue(".") << " " << purple("] indicator") << std::endl;
}

#endif// SEARCH_H
