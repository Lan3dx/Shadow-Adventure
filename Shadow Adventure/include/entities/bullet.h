#pragma once
#include <vector>

class BULLET
{
private:
	char character; // symbol
	char GType; // u, d, r, l
	bool gravity; // gravity t/f
	int x; // pos 
	int y; // pos 
public:
	BULLET(int, int, char, bool, char); // constructor

	void setX(int);
	void setY(int);
	void move(char);

	int getX();
	int getY();

	bool getGravity();
	bool touch(std::vector<std::vector<char>>);

	char getGType();

	std::vector<std::vector<char>> kill(std::vector<std::vector<char>>);// place entity on map
	std::vector<std::vector<char>> spawn(std::vector<std::vector<char>>);// place entity on map
};