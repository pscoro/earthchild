#include "gameobjects/movableobject.h"

MovableObject::MovableObject() {
	GameObject();
}

MovableObject::MovableObject(std::string objName, Position pos)
{
	MovableObject::objName = objName;
	MovableObject::pos = pos;
}

MovableObject::MovableObject(std::string objName, Position pos, bool movable)
{
	MovableObject::objName = objName;
	MovableObject::pos = pos;
	MovableObject::movable = movable;
}

MovableObject::MovableObject(std::string objName, Position pos, bool movable, char prefChar)
{
	MovableObject::objName = objName;
	MovableObject::pos = pos;
	MovableObject::movable = movable;
	MovableObject::prefChar = prefChar;
}

MovableObject::~MovableObject()
{
}

void MovableObject::move(int feet, util::CARDINAL cardinal) {
	if (cardinal == util::CARDINAL::NORTH) pos.getArray()[1]++;
	else if (cardinal == util::CARDINAL::EAST) pos.getArray()[0]++;
	else if (cardinal == util::CARDINAL::SOUTH) pos.getArray()[1]--;
	else if (cardinal == util::CARDINAL::WEST) pos.getArray()[0]--;
}