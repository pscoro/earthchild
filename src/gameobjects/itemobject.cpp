#include "gameobjects/itemobject.h"

ItemObject::ItemObject(std::string objName, EntityObject * owner) {
	ItemObject::objName = objName;
	ItemObject::owner = owner;
	ItemObject::pos = owner->getPos();
}

ItemObject::ItemObject(std::string objName, EntityObject* owner, char prefChar) {
	ItemObject::objName = objName;
	ItemObject::owner = owner;
	ItemObject::pos = owner->getPos();
	ItemObject::prefChar = prefChar;
}

ItemObject::~ItemObject() {

}