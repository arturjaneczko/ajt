#include <string>
#include "color.h"

#ifndef HELP_H
#define HELP_H

std::string help() {
	std::string help = "";
	help += blue(" [ HELP ]");
	help += "\n\t";
	help += blue(":q - quit");
	help += "\n\t";
	help += blue(":c - clear");
	help += "\n\t";
	help += blue(":h - help");
	help += "\n\t";
	help += blue(":m - manual");
	help += "\n\t";
	help += blue(":i - info");
	help += "\n\t";
	help += blue(":k - keys");
	help += "\n\t";
	help += blue(":t - tags");
	help += "\n";
	return help;
}

#endif// HELP_H
