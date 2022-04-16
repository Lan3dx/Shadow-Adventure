#pragma once

class EntityList
{
private:
	std::vector<Entity> list;

public:
	EntityList();
	void add(Entity);
	void set(std::vector<Entity>);
	std::vector<Entity> get();
};