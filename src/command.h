#include <set>
#include <string>
#include "help.h"
#include "info.h"
#include "manual.h"

#ifndef COMMAND_H
#define COMMAND_H

bool eq(std::string keyword, std::string input) {
	return keyword == input;
}

void print(std::string value) {
	std::cout << value << std::endl;
}

namespace command {

	bool isQuit(std::string input) {
		return eq(":q", input);
	}

	bool isHelp(std::string input) {
		return eq(":h", input);
	}

	bool isManual(std::string input) {
		return eq(":m", input);
	}

	bool isInfo(std::string input) {
		return eq(":i", input);
	}

	bool isClear(std::string input) {
		return eq(":c", input);
	}

	bool isKeys(std::string input) {
		return eq(":k", input);
	}

	bool isTags(std::string input) {
		return eq(":t", input);
	}

	bool isSearchCommand(std::string input) {
		return eq(":?", input);
	}

	bool isSearch(std::string input) {
		return 0 < input.length() && '?' == input[0];
	}

	bool isKeySearch(std::string input) {
		return isSearch(input) && 1 == input.length();
	}

	bool isTagSearch(std::string input) {
		return isSearch(input) && (2 == input.length()) && '#' == input[1];
	}

	bool isContentSearch(std::string input) {
		return isSearch(input) && (2 == input.length()) && '.' == input[1];
	}

	bool isAnySearch(std::string input) {
		return isKeySearch(input) || isTagSearch(input) || isContentSearch(input);
	}

	void printHelp() {
		print(help());
	}

	void printManual() {
		print(manual());
	}

	void printInfo() {
		print(info());
	}

	std::set<std::string> keywords() {
		std::set<std::string> keywords;
		for (const auto & entry : helpData()) {
			keywords.insert(entry.first);
		}
		return keywords;
	}

	bool isKeyword(std::string input) {
		std::set<std::string> keys = keywords();
		return keys.find(input) != keys.end();
	}

}

#endif// COMMAND_H
