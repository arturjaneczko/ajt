#include <string>

#ifndef COMMAND_H
#define COMMAND_H

bool eq(std::string keyword, std::string input) {
	return keyword == input;
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

}

#endif// COMMAND_H
