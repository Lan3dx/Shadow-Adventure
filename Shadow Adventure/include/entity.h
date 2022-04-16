#pragma once

#include <vector>

class Entity // main entity class
{
private:
	bool gravity; // gravity
	std::vector<int> x; // pos 
	std::vector<int> y; // pos
	char character; // symbol for entity

public:
	Entity(std::vector<int>, std::vector<int>, char, bool); // constructor
	std::vector<std::vector<char>> spawn(std::vector<std::vector<char>>);// place entity on map
	std::vector<std::vector<char>> kill(std::vector<std::vector<char>>);// delete entity from map
	void move(char, std::vector<std::vector<char>>); // move entity on map
	void setPos(std::vector<int>, std::vector<int>);
	bool voidUnder(std::vector<std::vector<char>>);
	bool collisions(std::vector<std::vector<char>>, int);
	bool getGravity();
	bool ladder(std::vector<std::vector<char>>);
	bool limit(std::vector<std::vector<char>>);
};