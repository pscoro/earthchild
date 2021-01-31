#pragma once

#include <iostream>
#include <vector>

//#include "objecthashmap.h"
#include "headers.h"
#include "position.h"

class GameObject
{
public:

	std::string getName();

	GameObject();
	GameObject(std::string objName, Position pos);
	GameObject(std::string objName, Position pos, char prefChar);
	virtual ~GameObject();

	virtual std::string to_String();
	inline bool hasChar() { return (prefChar != NULL); }

	Position getPos();
	void addRefMap(ObjectHashmap * hashmap);

protected:
	std::string objName;
	Position pos;
	char prefChar;
	std::vector<ObjectHashmap*> refMaps;
};