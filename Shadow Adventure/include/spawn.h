#pragma once

class EntityMap
{
private:
	std::map<std::string, Entity> list;

public:
	EntityMap();
	void set(std::map <std::string, Entity>);
	Entity find(std::string);
	void rem(std::string);
	void add(std::string, Entity);
	std::map<std::string, Entity> get();
};