#include <string>

namespace command {

	bool isQuit(std::string input) {
		return ":q" == input;
	}

}
