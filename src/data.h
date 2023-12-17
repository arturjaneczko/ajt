#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

#ifndef DATA_H
#define DATA_H

bool isFileNameValid(std::string fileName) {
	return fileName.length() > 6 && ".ajt" == fileName.substr(fileName.length() - 4, 4);
}

std::vector<std::string> split(std::string value) {
	std::stringstream ss(value);
	std::istream_iterator<std::string> begin(ss);
	std::istream_iterator<std::string> end;
	std::vector<std::string> splitted(begin, end);
	//std::copy(splitted.begin(), splitted.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
	return splitted;
}

std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data() {
    std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data;
    for (const auto & entry : std::filesystem::recursive_directory_iterator(".")) {
        std::string fileName = entry.path();
        if (std::filesystem::is_regular_file(fileName)) {
            if(isFileNameValid(fileName)) {
                std::fstream file(fileName);
                std::string line;
                std::getline(file, line);

                std::vector<std::string> keyAndTags = split(line);
                std::string key = keyAndTags[0];
                if ('#' == key[0]) {
                    std::string error = "!!! The key can't start with '#' (" + fileName + ")!";
                    std::cout << red(error) << std::endl;
                    exit(-1);
                }
                bool hasTags = keyAndTags.size() > 1;
                std::vector<std::string> tags;
                if (hasTags) {
                    std::vector<std::string>::const_iterator first = keyAndTags.begin() + 1;
                    std::vector<std::string>::const_iterator last = keyAndTags.end();
                    std::vector<std::string> rest = std::vector<std::string>(first, last);
                    for (int i=0; i<rest.size(); i++) {
                        std::string candidate = rest[i];
                        if ('#' == candidate[0]) {
                            tags.push_back(candidate);
                        }
                    }
                }
                if (data.count(key)) {
                    std::string error = "!!! The key: '" + key + "' duplicates found in files: (" + data[key].first.first + ", " + fileName + ")!";
                    std::cout << red(error) << std::endl;
                    std::cout << red("!!! Change one of them!") << std::endl;
                    exit(-1);
                } else if (command::isKeyword(key)) {
                    std::string error = "!!! The '" + key + "' is an keyword and can't be used as a key - file: '" + fileName + "'!";
                    std::cout << red(error) << std::endl;
                    exit(-1);
                } else {
                    data[key] = std::make_pair(std::make_pair(fileName, tags), "");
                    while(std::getline(file, line)) {
                        std::string value = data[key].second + (data[key].second == "" ? "" : "\n") + line;
                        data[key].second = value;
                    }
                }
            }
        }
    }
    return data;
}

#endif// DATA_H
