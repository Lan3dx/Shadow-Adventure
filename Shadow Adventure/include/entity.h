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
	Entity(std::vector<int> stdX, std::vector<int> stdY, char stdChar, bool stdGravity); // constructor
	std::vector<std::vector<char>> spawn(std::vector<std::vector<char>> board);// place entity on map
	std::vector<std::vector<char>> kill(std::vector<std::vector<char>> board);// delete entity from map
	void move(char type, std::vector<std::vector<char>> board); // move entity on map
	bool voidUnder(std::vector<std::vector<char>> board);
	bool collisions(std::vector<std::vector<char>> board, int type);
	bool getGravity();
	bool ladder(std::vector<std::vector<char>> board);
};