#include <chrono>
#include <iostream>
#include <fstream>

#ifndef INSTANT_H
#define INSTANT_H

std::string leadingOptionalZero(std::string value) {
	if (1 == value.length()) {
		return '0' + value;
	}
	return value;
}

std::string instant() {
	// timestamp
	auto now = std::chrono::system_clock::now();
	std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
	std::tm* timeParts = std::gmtime(&timestamp);

	std::string year = leadingOptionalZero(std::to_string(timeParts->tm_year + 1900));
	std::string month = leadingOptionalZero(std::to_string(timeParts->tm_mon + 1));
	std::string day = leadingOptionalZero(std::to_string(timeParts->tm_mday));

	std::string hour = leadingOptionalZero(std::to_string(timeParts->tm_hour));
	std::string minute = leadingOptionalZero(std::to_string(timeParts->tm_min));
	std::string second = leadingOptionalZero(std::to_string(timeParts->tm_sec));

	std::string date = year + '-' + month + '-' + day;
	std::string time = hour + ':' + minute + ':' + second;
	std::string dateTime = date + ' ' + time;

	return dateTime;
}

#endif// INSTANT_H
