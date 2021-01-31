#pragma once
#include <unordered_map>
#include <typeinfo>
#include <vector>

//#include "gameobjects\gameobject.h"
#include "headers.h"

class ObjectHashmap
{
public:
	ObjectHashmap();
	ObjectHashmap(std::unordered_map<std::string, std::vector<GameObject *> > oldMap);
	ObjectHashmap(ObjectHashmap* oldHashmap);
	~ObjectHashmap();

	ObjectHashmap getByType(std::type_info type);

	inline std::unordered_map<std::string, std::vector<GameObject*> > getMap() { return map; }

	std::vector<GameObject*> getObjectVector(std::string name);
	GameObject* getObjectAtIndex(std::string name, int index);

	int addObject(GameObject* object); // new size of vector *NOT INDEX OF OBJECT*
	int removeObject(GameObject* object); // -1 if not found, new size of vector if found
	int removeAllByName(std::string name); // -1 if not found, 0 if found
	int removeLastByName(std::string name); // -1 if not found, new size of vector if found
	int removeByIndex(std::string name, int index); // -1 if not found, new size of vector if found

private:
	std::unordered_map<std::string, std::vector<GameObject*> > map;
};
