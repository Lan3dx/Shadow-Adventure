#pragma once
#include <vector>
struct cooldowns
{
	int AD;
	int WS;
	int gravity;
};

class PLAYER // main entity class
{
private:
	char GType;
	bool gravity; // gravity
	std::vector<int> x; // pos 
	std::vector<int> y; // pos
	char character; // symbol for entity
	cooldowns cooldown; // cooldown for (A), (D), (W), (S), gravity
	cooldowns std_COOLDOWN;

public:
	PLAYER(std::vector<int>, std::vector<int>, char, bool, char, cooldowns); // constructor

	std::vector<std::vector<char>> spawn(std::vector<std::vector<char>>);// place entity on map
	std::vector<std::vector<char>> kill(std::vector<std::vector<char>>);// delete entity from map

	std::vector<int> getX(); // get x
	std::vector<int> getY(); // get y

	int getCAD(); // get cooldown for (A) (D)
	int getCWS(); // get cooldown for (W) (S)
	int getCG(); // get cooldown of gravity

	bool voidUnder(std::vector<std::vector<char>>); // if the player hit the floor
	bool collisions(std::vector<std::vector<char>>, int); // if the player touched a solid block
	bool getGravity(); // get gravity (t) (f)
	bool ladder(std::vector<std::vector<char>>); // if player on ladder
	bool limit(std::vector<std::vector<char>>); // if the player is in prohibited territory

	void move(char); // move entity on map
	void setPos(std::vector<int>, std::vector<int>); // set player pos

	void setCAD(); // set cooldown for (A) (D)
	void setCWS(); // set cooldown for (W) (S)
	void setCG(); // set cooldown of gravity
	void setCAD(int); // set cooldown for (A) (D) !over
	void setCWS(int); // set cooldown for (W) (S) !over
	void setCG(int); // set cooldown of gravity !over

	char getGType(); // get gravity type
};