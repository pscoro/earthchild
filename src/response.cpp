#include "response.h"
#include "color.hpp"

namespace res {

	void sendDefault(std::string response) {
		std::cout << response << std::endl;
	}

	void sendValid(std::string response) {
		std::cout << dye::green(response) << std::endl;
	}

	void sendWarning(std::string response) {
		std::cout << dye::yellow(response) << std::endl;
	}

	void sendError(std::string response) {
		std::cout << dye::red(response) << std::endl;
	}

	void sendImportant(std::string response) {
		std::cout << dye::on_white(response) << std::endl;
	}

	void sendLine() {
		std::cout << dye::grey("----------------------------------------------") << std::endl;
	}

	void pause() {
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}

	void pause(int milliseconds) {
		std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
	}

	void sendWordByWord(std::string response, int milliseconds) {
		std::istringstream iss(response);
		do
		{
			std::string subs;
			iss >> subs;
			std::cout << dye::red(subs) << " ";
			pause(milliseconds);
		} while (iss);
		std::cout << std::endl;
	}
}