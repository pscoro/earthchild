#pragma once
#include "gameobjects/movableobject.h"

class EntityObject : public MovableObject
{
public:
	EntityObject();
	EntityObject(std::string objName, Position pos);
	EntityObject(std::string objName, Position pos, std::string name);
	EntityObject(std::string objName, Position pos, std::string name, char prefChar);
	~EntityObject();

	inline std::string getName() { return EntityObject::name; };
	inline void setName(std::string name) { EntityObject::name = name; };

protected:
	std::string name;
};
