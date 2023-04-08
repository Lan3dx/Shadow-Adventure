#pragma once
#include <vector>
#include <string>
#include <map>
#include "../sys/constants.h"
#include "bullet.h"

class PLAYER // main entity class
{
private:
	struct cooldowns
	{
		int AD;
		int WS;
		int gravity;
	};
	char GType;
	bool gravity; // gravity
	int HP; // health point
	std::vector<int> x; // pos 
	std::vector<int> y; // pos
	char character; // symbol for entity
	cooldowns cooldown; // cooldown for (A), (D), (W), (S), gravity
	cooldowns std_COOLDOWN;
	BMAP bullets;

public:
	PLAYER(std::vector<int>, std::vector<int>, char, bool, char, cooldowns, int); // constructor

	void spawn(std::vector<std::vector<block>>&);// place entity on map
	void kill(std::vector<std::vector<block>>&);// delete entity from map

	std::vector<int> getX(); // get x
	std::vector<int> getY(); // get y

	int getCAD(); // get cooldown for (A) (D)
	int getCWS(); // get cooldown for (W) (S)
	int getCG(); // get cooldown of gravity
	int getHP(); // get health point

	bool voidUnder(std::vector<std::vector<block>>&); // if the player hit the floor
	bool collisions(std::vector<std::vector<block>>&, int); // if the player touched a solid block
	bool getGravity(); // get gravity (t) (f)
	bool ladder(std::vector<std::vector<block>>&); // if player on ladder
	bool limit(std::vector<std::vector<block>>&); // if the player is in prohibited territory
	bool onspeedbooster(std::vector<std::vector<block>>&); // if player on speed booster element
	bool inwater(std::vector<std::vector<block>>&); // if player in water block
	bool onstairs(std::vector<std::vector<block>>&, int); // if player on stairs

	void setPos(std::vector<int>, std::vector<int>); // set player pos
	void move(char); // move entity on map
	void shoot(char); // player shoot

	void setCAD(); // set cooldown for (A) (D)
	void setCWS(); // set cooldown for (W) (S)
	void setCG(); // set cooldown of gravity
	void setCAD(int); // set cooldown for (A) (D) !over
	void setCWS(int); // set cooldown for (W) (S) !over
	void setCG(int); // set cooldown of gravity !over
	void setCHAR(char); // set character of player
	void setHP(int); // set health point

	char getGType(); // get gravity type

	BMAP getBullets(); // get bullets map
	void setBullets(std::map<std::string, BULLET>);
};

class PMAP // players map
{
private:
	std::map<std::string, PLAYER> list; // map
public:
	void set(std::map <std::string, PLAYER>); // set map
	void rem(std::string); // remove some element of map
	void add(std::string, PLAYER); // add some element in map
	PLAYER find(std::string); // find some element
	std::map<std::string, PLAYER> get(); // get some element in map
};