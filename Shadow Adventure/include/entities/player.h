#pragma once
#include <vector>
class PLAYER // main entity class
{
private:
	char GType;
	bool gravity; // gravity
	std::vector<int> x; // pos 
	std::vector<int> y; // pos
	char character; // symbol for entity

public:
	PLAYER(std::vector<int>, std::vector<int>, char, bool, char); // constructor

	std::vector<std::vector<char>> spawn(std::vector<std::vector<char>>);// place entity on map
	std::vector<std::vector<char>> kill(std::vector<std::vector<char>>);// delete entity from map

	std::vector<int> getX();
	std::vector<int> getY();

	bool voidUnder(std::vector<std::vector<char>>);
	bool collisions(std::vector<std::vector<char>>, int);
	bool getGravity();
	bool ladder(std::vector<std::vector<char>>);
	bool limit(std::vector<std::vector<char>>);

	void move(char, std::vector<std::vector<char>>); // move entity on map
	void setPos(std::vector<int>, std::vector<int>);

	char getGType();
};