#include <iostream>
#include <string>
#include "color.h"
#include "version.h"

#ifndef INFO_H
#define INFO_H

std::string labels() {
	return "\033[1;30;30m \033[0m\033[1;44;37minfo\033[0m\033[1;41;37merror\033[0m\033[1;42;37minput\033[0m\033[1;43;37moutput\033[0m\033[1;45;37mmeta\033[0m";
}

std::string info() {
	std::string info = "";
	info += "     _       _ _____ ";
	info += "\n";
	info += "    / \\     | |_   _|";
	info += "\n";
	info += "   / _ \\ _  | | | |  ";
	info += "\n";
	info += "  / ___ \\ |_| | | |  ";
	info += "\n";
	info += " /_/   \\_\\___/  |_|  " + cyan("ver: " + version());
	info += "\n";
	info += cyan(" ------------------------------");
	info += "\n";
	info += " " + white(black("[ @ ]")) + cyan(" janeczko.artur@gmail.com");
	info += "\n";
	info += " " + white(black("[ ? ]")) + labels();
	info += "\n";
	info += "\n";
	return info;
}

#endif// INFO_H
