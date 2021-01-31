#include <string>
#include <algorithm>
#include <cctype>
#include <vector>

#include "response.h"
#include "input.h"
#include "player.h"
#include "util.h"
//#include "objecthashmap.h"

 int CLASS_COUNT = 0;

int main() {
	
	res::sendValid("Hello Earthchild");
	res::sendLine();
	res::pause();
	res::sendError("\nDo not move\n");
	res::pause(3000);
	res::sendWarning("What is your name");

	std::string name = inp::getLine();
   	Player *player = new Player(name, Position(), util::CARDINAL::SOUTH);


	res::sendValid("Welcome " + player->getName());
	res::sendWarning("Would you like to look around?");

	if (inp::getBool()) {
		res::sendValid("You are in a room");
		res::pause();
		res::sendValid("You stand in the corner");
		res::pause();
		res::sendValid("You don't see far");
		res::pause();
		res::sendWarning("\nHere is a compass");
	}
	else {
		res::sendDefault("Alright then");
	}

	bool stop = false;
	bool prompt = false;

	while (!stop) {
		if (prompt) {
			res::sendValid("What do you want to do");
			prompt = false;
		}
		std::string str = inp::ngetLine();
		if (str.empty()) {
			prompt = true;
		}
		else {
			std::istringstream iss(str);
			int paramCount = 0;
			std::vector<std::string> param;
			
			do {
				std::string subs;
					iss >> subs;

					param.push_back(subs);
					paramCount++;
			} while (iss);

			if (!param.empty()) {
				if (param[param.size() - 1] == "") {
					param.pop_back();
					paramCount--;
				}
				
				/*face, look*/
				if (param[0] == "face" || param[0] == "look") {
					if (paramCount > 2) {
						res::sendError("Too many parameters, I don't understand which direction you want to face.");
					}
					else if (paramCount < 2) {
						res::sendError("Which cardinal direction should I face");
					}
					else {
						/*north*/
						if (param[1] == "north") {
							player->setFacing(util::CARDINAL::NORTH);
							res::sendValid("Facing North");
						}

						/*east*/
						if (param[1] == "east") {
							player->setFacing(util::CARDINAL::EAST);
							res::sendValid("Facing East");
						}

						/*south*/
						if (param[1] == "south") {
							player->setFacing(util::CARDINAL::SOUTH);
							res::sendValid("Facing South");
						}

						/*west*/
						if (param[1] == "west") {
							player->setFacing(util::CARDINAL::WEST);
							res::sendValid("Facing West");
						}
					}
				}

				/*turn*/
				if (param[0] == "turn") {
					if (paramCount > 2) {
						res::sendError("Too many parameters, I don't understand which direction you want to turn");
					}
					else if (paramCount < 2) {
						res::sendError("Which direction should I turn");
					}
					else {
						/*left*/
						if (param[1] == "left") {
							player->turnLeft();
							res::sendValid("Turning Left");
						}

						/*right*/
						else if (param[1] == "right") {
							player->turnRight();
							res::sendValid("Turning Right");
						}

						/*around*/
						else if (param[1] == "around") {
							player->turnAround();
							res::sendValid("Turning around");
						}
					}
				}

				/*north*/
				if (param[0] == "north") {
					player->setFacing(util::CARDINAL::NORTH);
					res::sendValid("Facing North");
				}

				/*east*/
				if (param[0] == "east") {
					player->setFacing(util::CARDINAL::EAST);
					res::sendValid("Facing East");
				}

				/*south*/
				if (param[0] == "south") {
					player->setFacing(util::CARDINAL::SOUTH);
					res::sendValid("Facing South");
				}

				/*west*/
				if (param[0] == "west") {
					player->setFacing(util::CARDINAL::WEST);
					res::sendValid("Facing West");
				}

				/*left*/
				if (param[0] == "left") {
					player->turnLeft();
					res::sendValid("Turning Left");
				}

				/*right*/
				else if (param[0] == "right") {
					player->turnRight();
					res::sendValid("Turning Right");
				}

				/*around*/
				else if (param[0] == "around") {
					player->turnAround();
					res::sendValid("Turning around");
				}

				/*move, walk, travel, go*/
				if (param[0] == "move" || param[0] == "walk" || param[0] == "travel" || param[0] == "go") {
					for (int j = 0; j < paramCount; j++) {
						if (param[j] == "feet") {
							param.erase(param.begin()+j);
							paramCount--;
						}
					}
					if (paramCount != 3) {
						res::sendError("I am confused where you want to go, try \"walk 2 feet forward\" or \"go left 1\"");
					}
					else {
						if (param[1] == "forward" || param[1] == "forwards" || param[2] == "forward" || param[2] == "forwards" || param[1] == "forword" || param[1] == "forwords" || param[2] == "forword" || param[2] == "forwords") {
							if (std::find_if(param[1].begin(), param[1].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[1].end()) {
								player->move(std::stoi(param[1]), Player::DIRECTION::FORWARD);
							}
							else if (std::find_if(param[2].begin(), param[2].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[2].end()) {
								player->move(std::stoi(param[2]), Player::DIRECTION::FORWARD);
							}
						}
						if (param[1] == "backward" || param[1] == "backwards" || param[2] == "backward" || param[2] == "backwards" || param[1] == "backword" || param[1] == "backwords" || param[2] == "backword" || param[2] == "backwords") {
							if (std::find_if(param[1].begin(), param[1].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[1].end()) {
								player->move(std::stoi(param[1]), Player::DIRECTION::BACKWARD);
							}
							else if (std::find_if(param[2].begin(), param[2].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[2].end()) {
								player->move(std::stoi(param[2]), Player::DIRECTION::BACKWARD);
							}
						}
						if (param[1] == "left" || param[0] == "leftward" || param[0] == "leftwards") {
							if (std::find_if(param[1].begin(), param[1].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[1].end()) {
								player->move(std::stoi(param[1]), Player::DIRECTION::LEFT);
							}
							else if (std::find_if(param[2].begin(), param[2].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[2].end()) {
								player->move(std::stoi(param[2]), Player::DIRECTION::LEFT);
							}
						}
						if (param[1] == "right" || param[0] == "rightward" || param[0] == "rightwards") {
							if (std::find_if(param[1].begin(), param[1].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[1].end()) {
								player->move(std::stoi(param[1]), Player::DIRECTION::RIGHT);
							}
							else if (std::find_if(param[2].begin(), param[2].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[2].end()) {
								player->move(std::stoi(param[2]), Player::DIRECTION::RIGHT);
							}
						}
						if (param[1] == "north" || param[0] == "northward" || param[0] == "northwards") {
							if (std::find_if(param[1].begin(), param[1].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[1].end()) {
								player->move(std::stoi(param[1]), util::CARDINAL::NORTH);
							}
							else if (std::find_if(param[2].begin(), param[2].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[2].end()) {
								player->move(std::stoi(param[2]), util::CARDINAL::NORTH);
							}
						}
						if (param[1] == "east" || param[0] == "eastward" || param[0] == "eastwards") {
							if (std::find_if(param[1].begin(), param[1].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[1].end()) {
								player->move(std::stoi(param[1]), util::CARDINAL::EAST);
							}
							else if (std::find_if(param[2].begin(), param[2].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[2].end()) {
								player->move(std::stoi(param[2]), util::CARDINAL::EAST);
							}
						}
						if (param[1] == "south" || param[0] == "southward" || param[0] == "southwards") {
							if (std::find_if(param[1].begin(), param[1].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[1].end()) {
								player->move(std::stoi(param[1]), util::CARDINAL::SOUTH);
							}
							else if (std::find_if(param[2].begin(), param[2].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[2].end()) {
								player->move(std::stoi(param[2]), util::CARDINAL::SOUTH);
							}
						}
						if (param[1] == "west" || param[0] == "westward" || param[0] == "westwards") {
							if (std::find_if(param[1].begin(), param[1].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[1].end()) {
								player->move(std::stoi(param[1]), util::CARDINAL::WEST);
							}
							else if (std::find_if(param[2].begin(), param[2].end(), [](unsigned char c) { return !std::isdigit(c); }) == param[2].end()) {
								player->move(std::stoi(param[2]), util::CARDINAL::WEST);
							}
						}
					}
				}
				/*where*/
				if (param[0] == "where") {
					if (paramCount > 3) {
						for (int i = 3; i < paramCount; i++) {
							param[2] = param[2] + " " + param[i];
						}
						paramCount = 3;
					}
					if (paramCount != 3) {
						res::sendError("Where is what, try something like \"where am i\" or \"where is the rock\"");
					}
					else {
						if (param[1] == "am") {

						}
						else if (param[1] == "are") {

						}
						else if (param[1] == "is") {

						}
					}
				}
			}
		}
	}


	res::sendWordByWord("YOU ARE A DEAD MAN WALKING \nA VILE BYPRODUCT OF THE SIN OF OUR ANCESTORS", 250);

	res::sendDefault("\n\nPress any key to continue...");
	std::getchar();


	
	delete player;
	return 0;
}