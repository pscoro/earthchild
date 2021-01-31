#pragma once


#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <sstream>

namespace res {

	void sendDefault(std::string response);
	void sendValid(std::string response);
	void sendWarning(std::string response);
	void sendError(std::string response);
	void sendImportant(std::string response);
	void sendLine();
	void pause();
	void pause(int milliseconds);
	void sendWordByWord(std::string response, int milliseconds);

}