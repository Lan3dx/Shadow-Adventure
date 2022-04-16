#include <vector>

#include "..\include\entity.h"
#include "..\include\spawn.h"

EntityList::EntityList()
{
	list = {};
}
void EntityList::add(Entity ent)
{
	list.push_back(ent);
}
void EntityList::set(std::vector<Entity> entList)
{
	list = entList;
}
std::vector<Entity> EntityList::get()
{
	return list;
}
