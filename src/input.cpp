#include "input.h"

namespace inp {

	std::string getLine() {
		std::string str;
		std::getline(std::cin, str);
		return str;
	}

	std::string ngetLine() {
		std::string str;
		std::getline(std::cin, str);
		std::transform(str.begin(), str.end(), str.begin(),
			[](unsigned char c) { return std::tolower(c); });
		return str;
	}

	int getInt() {
		std::string str;

		while (true) {
			std::getline(std::cin, str);
			if (!str.empty() && std::find_if(str.begin(),
				str.end(), [](unsigned char c) { return !std::isdigit(c); }) == str.end()) {
				return std::stoi(str);
			}
			res::sendError("Enter valid integer");
		}
	}

	bool getBool() {
		std::string str;

		while (true) {
			std::getline(std::cin, str);
			std::transform(str.begin(), str.end(), str.begin(),
				[](unsigned char c) { return std::tolower(c); });
			if (!str.empty() && (str == "yes" || str == "y")) {
				return true;
			}
			else if (!str.empty() && (str == "no" || str == "n")) {
				return false;
			}
			else
			{
				res::sendError("Enter yes or no");
			}
		}
	}
}