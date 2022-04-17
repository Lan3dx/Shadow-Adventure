#include <map>
#include <string>
#include <vector>

#include "..\include\entity.h"
#include "..\include\spawn.h"

EntityMap::EntityMap()
{
	list = {};
}
void EntityMap::add(std::string key, Entity ent)
{
	list.insert(std::make_pair(key, ent));
}
void EntityMap::rem(std::string key)
{
	if (list.contains(key))
	{
		std::map <std::string, Entity>::iterator iter;
		iter = list.find(key);
		list.erase(iter);
	}
}
Entity EntityMap::find(std::string key)
{
	if (list.contains(key))
	{
		std::map <std::string, Entity>::iterator iter;
		iter = list.find(key);
		return iter->second;
	}
}
void EntityMap::set(std::map <std::string, Entity>mp)
{
	list = mp;
}
std::map<std::string, Entity> EntityMap::get()
{
	return list;
}

