#include <iostream>
#include <string>
#include "command.h"
#include "help.h"
#include "info.h"
#include "manual.h"

void print(std::string value) {
	std::cout << value << std::endl;
}

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
			print(help());
		} else if (command::isManual(input)) {
			print(manual());
		} else if (command::isInfo(input)) {
			print(info());
		} else if (command::isClear(input)) {
			system("clear");
		} else {
			print("ajt");
		}
	}
	return 0;
}
