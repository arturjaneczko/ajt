#include <string>

#ifndef MANUAL_H
#define MANUAL_H

std::string manual() {
	std::string manual = "";
	manual += purple(" AJT allows you to search the contents of files by key or tags.\n");
	manual += "\n";
	manual += purple(" The AJT supports only files with 'ajt' extension (for ex. 'foobar.ajt').\n");
	manual += purple(" Each file must own unique key (1'st line, 1'st position)\n");
	manual += purple(" Each file can own multiple tags (1'st line, 2'nd..n positions). A 'tag' is recognized by '#' (hash) prefix.\n");
	manual += "\n";
	manual += purple(" (The first line example: 'foobar #foo #bar #foobar #realted #foobar #abc')\n");
	manual += "\n";
	manual += purple(" Incorrect keys must be fixed for correct directory mapping (recursive).\n");
	manual += purple(" Invalid tags will be skipped.\n");
	manual += "\n";
	return manual;
}

#endif// MANUAL_H
