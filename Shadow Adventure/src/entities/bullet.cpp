#include "../../include/entities/bullet.h"

BULLET::BULLET(int stdX, int stdY, char stdChar, bool stdGravity, char Gt, cooldowns cd, int cdmg) // constructor
{
	gravity = stdGravity; // gravity
	GType = Gt; // gravity type
	x = stdX; // pos x
	y = stdY; // pos y
	character = stdChar; // symbol
	cooldown = cd;
	std_COOLDOWN = cd;
	damage = cdmg;
}

void BULLET::move(char type) // move entity on map
{
	if (type == 'r') {y += 1;} // right
	if (type == 'l') {y -= 1;} // left
	if (type == 'u'){x -= 1;} // up
	if (type == 'd') {x += 1;} // down
}

void BULLET::setX(int stdx) { x = stdx; } // set x
void BULLET::setY(int stdy) { y = stdy; } // set y
void BULLET::setCG() // set cooldown for gravity
{
	cooldown.CG = std_COOLDOWN.CG;
}
void BULLET::setCG(int lc) // set cooldown for gravity !over
{
	cooldown.CG = lc;
}
void BULLET::setCS() // set cooldown for gravity
{
	cooldown.CS = std_COOLDOWN.CS;
}
void BULLET::setCS(int lc) // set cooldown for gravity !over
{
	cooldown.CS = lc;
}
void BULLET::setDMG(int cdmg)
{
	damage = cdmg;
}

int BULLET::getX() { return x; } // get x
int BULLET::getY() { return y; } // get y

int BULLET::getCG() // get cooldown for gravity
{
	return cooldown.CG;
}
int BULLET::getCS() // get cooldown for gravity
{
	return cooldown.CS;
}
int BULLET::getDMG()
{
	return damage;
}

bool BULLET::getGravity() { return gravity; } // get gravity (t) (f)
bool BULLET::touch(std::vector<std::vector<block>>& board) // if the bullet hit the wall
{
	if (board[x][y].character != ' ' &&  // if bullet touch ' ' or '|' then return false
		board[x][y].character != '|') return false;
	return true;
}

char BULLET::getGType() { return GType; } // get gravity type

void BULLET::spawn(std::vector<std::vector<block>> &board) { board[x][y].character = character; } // spawn bullet
void BULLET::kill(std::vector<std::vector<block>> &board) { board[x][y].character = ' '; } // kill bullet

void BMAP::add(std::string key, BULLET bullet) // add some element in map
{
	list.insert(std::make_pair(key, bullet));
}
void BMAP::rem(std::string key) // remove some element from map
{
	if (list.contains(key))
	{
		std::map <std::string, BULLET>::iterator iter;
		iter = list.find(key);
		list.erase(iter);
	}
}
BULLET BMAP::find(std::string key) // find some element of map
{
	std::map <std::string, BULLET>::iterator iter;
	iter = list.find(key);
	return iter->second;
}
void BMAP::set(std::map <std::string, BULLET> t_map) // set map
{
	list = t_map;
}
std::map<std::string, BULLET> BMAP::get() // get some element from map
{
	return list;
}