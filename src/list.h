#ifndef LIST_H
#define LIST_H

void printList(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data) {
	std::cout << purple("[ LIST ]") << std::endl;
	if (0 < data.size()) {
		for (std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>>::iterator it = data.begin(); it != data.end(); ++it) {
			std::string dataText = "\t" + it->second.first.first;
			std::cout << purple(dataText) << std::endl;
		}
	} else {
		std::cout << "\t" << purple("Nothing.") << std::endl;
	}
}

#endif// LIST_H
