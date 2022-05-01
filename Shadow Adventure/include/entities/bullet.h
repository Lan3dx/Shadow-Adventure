#pragma once
#include <vector>

class BULLET
{
private:
	char character; // symbol
	char GType; // u, d, r, l
	bool gravity; // gravity t/f
	int x; // pos x
	int y; // pos y
	int cooldown; // cooldown for bullet
	int std_COOLDOWN;

public:
	BULLET(int, int, char, bool, char, int); // constructor

	void setX(int); // set x
	void setY(int); // set y
	void move(char); // change player coord

	void setC(); // set cooldown 
	void setC(int); // set cooldown !over

	int getX(); // get x
	int getY(); // get y
	int getC(); // get cooldown

	bool getGravity(); // get gravity (t) (f)
	bool touch(std::vector<std::vector<char>>); // if the bullet hit the wall

	char getGType(); // get gravity type

	std::vector<std::vector<char>> kill(std::vector<std::vector<char>>);// place bullet on map
	std::vector<std::vector<char>> spawn(std::vector<std::vector<char>>);// place bullet on map
};