#pragma once
#include <vector>
#include <string>
#include <map>
#include "../sys/constants.h"

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
	void setCG(int); // set cooldown for gravity ! overload
	void setCS(); // set cooldown for shot
	void setCS(int); // set cooldown for shot ! overload

	int getX(); // get x
	int getY(); // get y

	int getCG(); // get cooldown for gravity
	int getCS(); // get cooldown for shot

	bool getGravity(); // get gravity (t) (f)
	bool touch(std::vector<std::vector<block>>&); // if the bullet hit the wall

	char getGType(); // get gravity type

	void kill(std::vector<std::vector<block>>&); // place bullet on map
	void spawn(std::vector<std::vector<block>>&); // place bullet on map
};

class BMAP // bullets map
{
private:
	std::map<std::string, BULLET> list; // map
public:
	void set(std::map <std::string, BULLET>); // set map
	void rem(std::string); // remove some element of map
	void add(std::string, BULLET); // add some element in map
	BULLET find(std::string); // find some element
	std::map<std::string, BULLET> get(); // get some element in map
};