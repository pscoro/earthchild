#pragma once
#include "gameobject.h"
#include "entityobject.h"

class ItemObject : public GameObject
{
public:
	ItemObject(std::string objName, EntityObject * owner);
	ItemObject(std::string objName, EntityObject * owner, char prefChar);
	~ItemObject();

protected:
	EntityObject * owner;

};
