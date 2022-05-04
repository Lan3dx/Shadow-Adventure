#pragma once
#include <vector>

class BULLET
{
private:
	struct cooldowns
	{
		int CG;
		int CS;
	};

	char character; // symbol
	char GType; // u, d, r, l
	bool gravity; // gravity t/f
	int x; // pos x
	int y; // pos y
	cooldowns cooldown; // cooldown for bullet
	cooldowns std_COOLDOWN;

public:
	BULLET(int, int, char, bool, char, cooldowns); // constructor

	void setX(int); // set x
	void setY(int); // set y
	void move(char); // change player coord

	void setCG(); // set cooldown for gravity
	void setCG(int); // set cooldown for gravity !over
	void setCS(); // set cooldown for shot
	void setCS(int); // set cooldown for shot !over

	int getX(); // get x
	int getY(); // get y

	int getCG(); // get cooldown for gravity
	int getCS(); // get cooldown for shot

	bool getGravity(); // get gravity (t) (f)
	bool touch(std::vector<std::vector<char>>); // if the bullet hit the wall

	char getGType(); // get gravity type

	std::vector<std::vector<char>> kill(std::vector<std::vector<char>>);// place bullet on map
	std::vector<std::vector<char>> spawn(std::vector<std::vector<char>>);// place bullet on map
};