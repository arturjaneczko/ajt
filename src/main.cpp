#include <iostream>
#include <string>
#include "command.h"

int main() {
	std::cout << info() << std::endl;
	std::cout << manual() << std::endl;
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
		} else {
			std::cout << "ajt" << std::endl;
		}
	}
	return 0;
}
