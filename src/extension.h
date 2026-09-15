#ifndef EXTENSION_H
#define EXTENSION_H

void extension() {
	std::filesystem::path path("script.sh");
	if (std::filesystem::exists(path)) {
		std::system("bash script.sh");
	} else {
		std::cout << red("The 'script.sh' doesn't exists!") << "\n";
		std::cout << blue("Prepare your own ") << yellow("script.sh") << blue(" and do whatever you want - having ") << green(":x") << blue(" shortcut.") << "\n";
	}
}

#endif// EXTENSION_H
