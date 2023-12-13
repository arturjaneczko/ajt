#include <iostream>
#include <string>
#include "command.h"
#include "info.h"
#include "manual.h"

int main() {
	std::cout << info() << std::endl;
	std::cout << manual() << std::endl;
	std::string input = "";
	while (true) {
		std::cin >> input;
		if (command::isQuit(input)) {
			exit(0);
		}
	}
	return 0;
}
