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
