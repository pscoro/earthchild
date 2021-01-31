#include "gameobjects/entityobject.h"

EntityObject::EntityObject() {
	GameObject();
}

EntityObject::EntityObject(std::string objName, Position pos) {
	EntityObject::objName = objName;
	EntityObject::pos = pos;
	EntityObject::name = "unnamed";
}

EntityObject::EntityObject(std::string objName, Position pos, std::string name) {
	EntityObject::objName = objName;
	EntityObject::pos = pos;
	EntityObject::name = name;
}

EntityObject::EntityObject(std::string objName, Position pos, std::string name, char prefChar) {
	EntityObject::objName = objName;
	EntityObject::pos = pos;
	EntityObject::name = name;
	EntityObject::prefChar = prefChar;
}

EntityObject::~EntityObject()
{
}
