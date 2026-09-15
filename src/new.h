#include <chrono>
#include <iostream>
#include <fstream>

#ifndef NEW_H
#define NEW_H

std::string leadingZero(std::string value) {
	if (1 == value.length()) {
		return '0' + value;
	}
	return value;
}

void createAndEditNew() {
	// timestamp
	auto now = std::chrono::system_clock::now();
	std::time_t timestamp = std::chrono::system_clock::to_time_t(now);
	std::tm* timeParts = std::gmtime(&timestamp);

	std::string year = leadingZero(std::to_string(timeParts->tm_year + 1900));
	std::string month = leadingZero(std::to_string(timeParts->tm_mon + 1));
	std::string day = leadingZero(std::to_string(timeParts->tm_mday));

	std::string hour = leadingZero(std::to_string(timeParts->tm_hour));
	std::string minute = leadingZero(std::to_string(timeParts->tm_min));
	std::string second = leadingZero(std::to_string(timeParts->tm_sec));

	std::string date = year + month + day;
	std::string time = hour + minute + second;
	std::string dateTime = date + '_' + time;

	// dir's
	std::string rootPath = "./";
	std::string ajtDir = "AJT/";
	std::string extension = ".ajt";
	std::string fileName = dateTime + extension;
	

	std::string yearDir = year + "/";
	std::string monthDir = month + "/";
	std::string dayDir = day + "/";

	std::string ajtPath = rootPath + ajtDir;

	std::filesystem::create_directory(ajtPath + yearDir);
	std::filesystem::create_directory(ajtPath + yearDir + monthDir);
	std::filesystem::create_directory(ajtPath + yearDir + monthDir + dayDir);

	// path
	std::string path = ajtPath + yearDir + monthDir + dayDir + fileName;
	std::cout << green(path) << "\n";
	

	// file
	std::ofstream outfile(path);
	outfile << dateTime;
	outfile << " ";
	outfile << "#" << dateTime;
	outfile << " ";
	outfile << "#year:" << year; 
	outfile << " ";
	outfile << "#month:" << month; 
	outfile << " ";
	outfile << "#day:" << day; 
	//outfile << " ";
	//outfile << "#hour:" << hour;
	//outfile << " ";
	//outfile << "#minute:" << minute;
	//outfile << " ";
	//outfile << "#second:" << second;
	outfile << std::endl;

	std::cin.ignore();// fix for important trap	
	std::cout << yellow("Content:") << "\n";
	std::string content;
	std::getline(std::cin, content);
	outfile << content << std::endl;
	
	outfile.close();

	//std::string yearDir = rootPath + ajtDir + year + "/";
	//std::string monthDir = yearDir + month + "/";
	//std::string dayDir = monthDir + day + "/";
	//std::string hourDir = dayDir +  hour + "/";
	//std::string minuteDir = dayDir + minute + "/";

	//std::filesystem::create_directory(yearDir);
	//std::filesystem::create_directory(monthDir);
	//std::filesystem::create_directory(dayDir);
	//std::filesystem::create_directory(hourDir);
	//std::filesystem::create_directory(minuteDir);

	//std::ifstream src(fileName, std::ios::binary);
	//std::cout << "src: " << fileName << "\n";
	//std::cout << "dst: " << yearDir + fileName << "\n";

	//std::ofstream dstYear(yearDir + fileName, std::ios::binary);
	//std::ofstream dstMonth(monthDir + fileName, std::ios::binary);
	//std::ofstream dstDay(dayDir + fileName, std::ios::binary);
	//std::ofstream dstHour(hourDir + fileName, std::ios::binary);
	//std::ofstream dstMinute(minuteDir + fileName, std::ios::binary);

	//dstYear << src.rdbuf();
	//dstMonth << src.rdbuf();
	//dstDay << src.rdbuf();
	//dstHour << src.rdbuf();
	//dstMinute << src.rdbuf();
}

#endif// NEW_H
