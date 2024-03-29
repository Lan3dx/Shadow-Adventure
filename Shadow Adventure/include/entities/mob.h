#pragma once
#include <vector>
#include <string>
#include <map>
#include "../sys/constants.h"
#include "bullet.h"

class MOB // main entity class
{
private:
	struct cooldowns
	{
		int AD;
		int WS;
		int gravity;
	};
	char GType;
	bool mobile; // can be moved
	bool gravity; // gravity
	int HP; // health point
	std::vector<int> x; // pos 
	std::vector<int> y; // pos
	char character; // symbol for entity
	cooldowns cooldown; // cooldown for (A), (D), (W), (S), gravity
	cooldowns std_COOLDOWN;
	BMAP bullets;

public:
	MOB(std::vector<int>, std::vector<int>, char, bool, bool, char, cooldowns, int); // constructor

	void spawn(std::vector<std::vector<block>>&);// place entity on map
	void kill(std::vector<std::vector<block>>&);// delete entity from map
	void shoot(char); // mob shoot
	
	std::vector<int> getX(); // get x
	std::vector<int> getY(); // get y

	int getCAD(); // get cooldown for (A) (D)
	int getCWS(); // get cooldown for (W) (S)
	int getCG(); // get cooldown of gravity
	int getHP(); // get health point

	bool voidUnder(std::vector<std::vector<block>>&); // if the mob hit the floor
	bool collisions(std::vector<std::vector<block>>&, int); // if the mob touched a solid block
	bool getGravity(); // get gravity (t) (f)
	bool ladder(std::vector<std::vector<block>>&); // if mob on ladder
	bool limit(std::vector<std::vector<block>>&); // if the mob is in prohibited territory
	bool onspeedbooster(std::vector<std::vector<block>>&); // if mob on speed booster element
	bool onstairs(std::vector<std::vector<block>>&, int); // if mob on stairs
	bool getMobile();

	void move(char); // move entity on map
	void setPos(std::vector<int>, std::vector<int>); // set mob pos

	void setCAD(); // set cooldown for (A) (D)
	void setCWS(); // set cooldown for (W) (S)
	void setCG(); // set cooldown of gravity
	void setCAD(int); // set cooldown for (A) (D) !over
	void setCWS(int); // set cooldown for (W) (S) !over
	void setCG(int); // set cooldown of gravity !over
	void setCHAR(char); // set character of mob
	void setHP(int); // set health point

	char getGType(); // get gravity type

	BMAP getBullets(); // get bullets map
	void setBullets(std::map<std::string, BULLET>);
};

class MMAP // mobs map
{
private:
	std::map<std::string, MOB> list; // map
public:
	void set(std::map <std::string, MOB>); // set map
	void rem(std::string); // remove some element of map
	void add(std::string, MOB); // add some element in map
	MOB find(std::string); // find some element
	std::map<std::string, MOB> get(); // get some element in map
};