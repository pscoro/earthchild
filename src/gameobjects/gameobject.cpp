#include "gameobjects/gameobject.h"

// root game object file

GameObject::GameObject() {
	GameObject::objName = "nullobj";
}

GameObject::GameObject(std::string objName, Position pos)
{
	GameObject::objName = objName;
	GameObject::pos = pos;
}

GameObject::GameObject(std::string objName, Position pos, char prefChar)
{
	GameObject::objName = objName;
	GameObject::pos = pos;
	GameObject::prefChar = prefChar;
}

GameObject::~GameObject()
{

}

std::string GameObject::to_String() {
	return objName;
}

Position GameObject::getPos() {
	return pos;
}


std::string GameObject::getName() {
	return objName;
}

void GameObject::addRefMap(ObjectHashmap* hashmap) {
	refMaps.push_back(hashmap);
}
