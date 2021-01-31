#pragma once
#include "gameobject.h"
#include "util.h"

class MovableObject : public GameObject
{
public:
	MovableObject();
	MovableObject(std::string objName, Position pos);
	MovableObject(std::string objName, Position pos, bool movable);
	MovableObject(std::string objName, Position pos, bool movable, char prefChar);
	~MovableObject();

	inline bool isMovable() { return movable; };

	void move(int feet, util::CARDINAL cardinal);

protected:
	bool movable = true;

};

