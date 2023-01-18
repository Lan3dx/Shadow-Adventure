#pragma once

#include <map>
#include <string>

#include "..\include\entities\bullet.h"
#include "..\include\entities\player.h"
#include "..\include\entities\mob.h" 

class MMAP // mobs map
{
private:
	std::map<std::string, MOB> list; // map
public:
	void set(std::map <std::string, MOB>); // set map
	void rem(std::string); // remove some element of map
	void add(std::string, MOB); // add some element in map
	MOB find(std::string); // find some element
	std::map<std::string, MOB> get(); // get some element in map
};

class PMAP // players map
{
private:
	std::map<std::string, PLAYER> list; // map
public:
	void set(std::map <std::string, PLAYER>); // set map
	void rem(std::string); // remove some element of map
	void add(std::string, PLAYER); // add some element in map
	PLAYER find(std::string); // find some element
	std::map<std::string, PLAYER> get(); // get some element in map
};

class BMAP // bullets map
{
private:
	std::map<std::string, BULLET> list; // map
public:
	void set(std::map <std::string, BULLET>); // set map
	void rem(std::string); // remove some element of map
	void add(std::string, BULLET); // add some element in map
	BULLET find(std::string); // find some element
	std::map<std::string, BULLET> get(); // get some element in map
};