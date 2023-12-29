#ifndef ENGINE_H
#define ENGINE_H

void engine(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>> data, std::function<std::pair<std::string, std::set<std::string>>(std::map<std::string, std::pair<std::pair<std::string, std::vector<std::string>>, std::string>>, std::string)> func) {
	std::string seq(1, '\0');
	char c;
	system("stty raw");
	while (true) {
		c = getchar();
		system("clear");
		std::string cc(1, c);
		if ("\x1B" == cc) {
			system("stty cooked");
			break;
		} else if (127 == c) {
			if (1 <= seq.length()) {
				seq = seq.substr(0, seq.length() - 1);
			}
		} else {
			seq += cc;
		}
		std::pair<std::string, std::set<std::string>> result = func(data, seq);
		std::cout << purple(" [ ") << blue(result.first) << purple(" ] ") << green(seq) << "\r\n";
		for (const auto & r : result.second) {
			std::cout << "\t" << yellow(r) << "\r\n";
		}
	}
}

#endif// ENGINE_H
