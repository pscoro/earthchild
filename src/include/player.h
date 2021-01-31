#pragma once
#include <iostream>

#include "position.h"
#include "response.h"
#include "util.h"
#include "gameobjects/entityobject.h"

class Player : public EntityObject
{
public:

	enum DIRECTION {
		FORWARD,
		RIGHT,
		BACKWARD,
		LEFT
	};

	Player(std::string name);
	Player(std::string name, Position pos, util::CARDINAL facing);
	~Player();

	std::string getName();

	Position getPos();
	void setPos(Position pos);

	util::CARDINAL getFacing();
	void setFacing(util::CARDINAL facing);

	void move(int feet, Player::DIRECTION direction);
	void move(int feet, util::CARDINAL cardinal);

	void turnLeft();
	void turnAround();
	void turnRight();

private:
	Position pos;
	std::string name;
	util::CARDINAL facing;
};
