#pragma once

#include <map>
#include <string>

#include "..\include\entities\bullet.h"
#include "..\include\entities\player.h"

class PMAP
{
private:
	std::map<std::string, PLAYER> list;
public:
	void set(std::map <std::string, PLAYER>);
	void rem(std::string);
	void add(std::string, PLAYER);
	PLAYER find(std::string);
	std::map<std::string, PLAYER> get();
};
class BMAP
{
private:
	std::map<std::string, BULLET> list;
public:
	void set(std::map <std::string, BULLET>);
	void rem(std::string);
	void add(std::string, BULLET);
	BULLET find(std::string);
	std::map<std::string, BULLET> get();
};