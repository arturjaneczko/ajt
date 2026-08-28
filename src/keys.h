#ifndef KEYS_H
#define KEYS_H

void printKeys(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data) {
	std::cout << purple("[ KEYS ]") << std::endl;
	if (0 < data.size()) {
		for (std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>>::iterator it = data.begin(); it != data.end(); ++it) {

			std::string path = it->second.first.first;
			std::string s = "\t" + it->first + " (" + path + ")";
			std::cout << purple(s) << std::endl;
		}
	} else {
		std::cout << "\t" << purple("No keys.") << std::endl;
	}
}

#endif// KEYS_H
