#include <map>
#include <string>
#include "color.h"

#ifndef HELP_H
#define HELP_H

std::map<std::string, std::string> helpData() {
	std::map<std::string, std::string> data;
	data[":q"] = "quit";
	data[":c"] = "clear";
	data[":h"] = "help";
	data[":m"] = "manual";
	data[":i"] = "info";
	data[":k"] = "keys";
	data[":t"] = "tags";
	return data;
}

std::string help() {
	std::string help = "";
	help += blue(" [ HELP ]");
	help += "\n\t";
	for (const auto & entry : helpData()) {
		help += blue(entry.first + " - " + entry.second);
		help += "\n\t";
	}
	return help;
}

#endif// HELP_H
