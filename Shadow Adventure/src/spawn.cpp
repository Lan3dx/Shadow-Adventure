#include "../include/spawn.h"

void PMAP::add(std::string key, PLAYER player) // add some element in map
{
	list.insert(std::make_pair(key, player));
}
void PMAP::rem(std::string key) // remove some element from map
{
	if (list.contains(key))
	{
		std::map <std::string, PLAYER>::iterator iter;
		iter = list.find(key);
		list.erase(iter);
	}
}
PLAYER PMAP::find(std::string key) // find some element of map
{
	if (list.contains(key))
	{
		std::map <std::string, PLAYER>::iterator iter;
		iter = list.find(key);
		return iter->second;
	}
}
void PMAP::set(std::map <std::string, PLAYER> t_map) // set map
{
	list = t_map;
}
std::map<std::string, PLAYER> PMAP::get() // get some element from map
{
	return list;
}

void BMAP::add(std::string key, BULLET bullet) // add some element in map
{
	list.insert(std::make_pair(key, bullet));
}
void BMAP::rem(std::string key) // remove some element from map
{
	if (list.contains(key))
	{
		std::map <std::string, BULLET>::iterator iter;
		iter = list.find(key);
		list.erase(iter);
	}
}
BULLET BMAP::find(std::string key) // find some element of map
{
	if (list.contains(key))
	{
		std::map <std::string, BULLET>::iterator iter;
		iter = list.find(key);
		return iter->second;
	}
}
void BMAP::set(std::map <std::string, BULLET> t_map) // set map
{
	list = t_map;
}
std::map<std::string, BULLET> BMAP::get() // get some element from map
{
	return list;
}