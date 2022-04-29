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

	std::vector<int> getX(); // get x
	std::vector<int> getY(); // get y

	bool voidUnder(std::vector<std::vector<char>>); // if the player hit the floor
	bool collisions(std::vector<std::vector<char>>, int); // if the player touched a solid block
	bool getGravity(); // get gravity (t) (f)
	bool ladder(std::vector<std::vector<char>>); // if player on ladder
	bool limit(std::vector<std::vector<char>>); // if the player is in prohibited territory

	void move(char); // move entity on map
	void setPos(std::vector<int>, std::vector<int>); // set player pos

	char getGType(); // get gravity type
};