#include "objecthashmap.h"

ObjectHashmap::ObjectHashmap() {

}

ObjectHashmap::ObjectHashmap(std::unordered_map<std::string, std::vector<GameObject*> > oldMap) {
	map = oldMap;
}

ObjectHashmap::ObjectHashmap(ObjectHashmap* oldHashmap) {
	map = oldHashmap->getMap();
}

ObjectHashmap::~ObjectHashmap() {

}

ObjectHashmap ObjectHashmap::getByType(std::type_info type) { // typeid and type_info usage not tested
	ObjectHashmap subMap = ObjectHashmap();
	for (auto& it : map) {
		for (auto& entry : it.second) {
			if (typeid(entry) == type) {
				subMap.addObject(entry);
			}
		}
	}
	return subMap;
}

int ObjectHashmap::addObject(GameObject* object) {
	for (auto& it : map) {
		if (it.first == object->getName()) {
			it.second.push_back(object);
			return it.second.size(); //untested
		}
	}
	std::vector<GameObject*> newVec = std::vector<GameObject*>();
	newVec.push_back(object);
	std::pair<std::string, std::vector<GameObject*> > pair(object->getName(), newVec);
	map.insert(pair);
	return 1;
}

int ObjectHashmap::removeObject(GameObject* object) {
	for (auto& it : map) {
		if (it.first == object->getName()) {
			for (int i = 0; i < it.second.size(); i++) {
				if (it.second.at(i) == object) {
					it.second.erase(it.second.begin() + i);
					return it.second.size();
				}
			}
		}
	}
	return -1;
}

int ObjectHashmap::removeAllByName(std::string name) {
	for (auto& it : map) {
		if (it.first == name) {
			map.erase(name);
			return 0;
		}
	}
	return 1;
}

int ObjectHashmap::removeLastByName(std::string name) {
	for (auto& it : map) {
		if (it.first == name) {
			if (it.second.size() > 0) {
				it.second.pop_back();
				return it.second.size();
			}
		}
	}
	return -1;
}

int ObjectHashmap::removeByIndex(std::string name, int index) {
	for (auto& it : map) {
		if (it.first == name) {
			if (it.second.size() > index) {
				it.second.erase(it.second.begin() + index);
				return it.second.size();
			}
		}
	}
	return -1;
}

std::vector<GameObject*> ObjectHashmap::getObjectVector(std::string name) {
	return map[name];
}

GameObject* ObjectHashmap::getObjectAtIndex(std::string name, int index) {
	return map[name].at(index);
}