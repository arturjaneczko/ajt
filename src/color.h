#include <algorithm>
#include <iostream>
#include <map>
#include <string>

#ifndef COLOR_H
#define COLOR_H

namespace ajtcolors {
	enum Color {RED, GREEN, YELLOW, BLUE, PURPLE, CYAN, WHITE, BLACK};
}

std::map<ajtcolors::Color, std::pair<std::string, std::string>> colors() {
	std::map<ajtcolors::Color, std::pair<std::string, std::string>> map;
	map[ajtcolors::Color::RED] = std::make_pair("\x1B[91m", "\033[0m");
	map[ajtcolors::Color::GREEN] = std::make_pair("\x1B[32m", "\033[0m");
	map[ajtcolors::Color::YELLOW] = std::make_pair("\x1B[33m", "\033[0m");
	map[ajtcolors::Color::BLUE] = std::make_pair("\x1B[94m", "\033[0m");
	map[ajtcolors::Color::PURPLE] = std::make_pair("\x1B[35m", "\033[0m");
	map[ajtcolors::Color::CYAN] = std::make_pair("\x1B[36m", "\033[0m");
	map[ajtcolors::Color::WHITE] = std::make_pair("\x1B[47m", "\033[0m");// WHITE color is exception here - B instead of F
	map[ajtcolors::Color::BLACK] = std::make_pair("\x1B[30m", "\033[0m");
	return map;
}

std::string color(std::string text, ajtcolors::Color color) {
	std::pair<std::string, std::string> pair = colors()[color];
	std::string prefix = pair.first;
	std::string postfix = pair.second;
	return prefix + text + postfix;
}

std::string red(std::string text) {
	return color(text, ajtcolors::Color::RED);
}

std::string green(std::string text) {
	return color(text, ajtcolors::Color::GREEN);
}

std::string yellow(std::string text) {
	return color(text, ajtcolors::Color::YELLOW);
}

std::string blue(std::string text) {
	return color(text, ajtcolors::Color::BLUE);
}

std::string purple(std::string text) {
	return color(text, ajtcolors::Color::PURPLE);
}

std::string cyan(std::string text) {
	return color(text, ajtcolors::Color::CYAN);
}

std::string white(std::string text) {
	return color(text, ajtcolors::Color::WHITE);
}

std::string black(std::string text) {
	return color(text, ajtcolors::Color::BLACK);
}

#endif// COLOR_H
