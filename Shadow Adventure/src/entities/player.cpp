#include "../../include/entities/player.h"

PLAYER::PLAYER(std::vector<int> stdX, std::vector<int> stdY, char stdChar, bool stdGravity, char Gt, cooldowns cd) // constructor
{
	gravity = stdGravity; // gravity (t) (f) 
	GType = Gt; // gravity type (u,d,l,r)
	x = stdX; // pos x
	y = stdY; // pos y
	character = stdChar; // symbol
	cooldown = cd;
	std_COOLDOWN = cd;
}

void PLAYER::spawn(std::vector<std::vector<block>> &board) // place entity on map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]].character = character;
	}
}
void PLAYER::kill(std::vector<std::vector<block>> &board) // delete entity from map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]].character = ' ';
	}
}

std::vector<int> PLAYER::getX() // get x
{
	return x;
}
std::vector<int> PLAYER::getY() // get y
{
	return y;
}

int PLAYER::getCAD() // get cooldown for (A) (D)
{
	return cooldown.AD;
}
int PLAYER::getCWS() // get cooldown for (W) (S)
{
	return cooldown.WS;
}
int PLAYER::getCG() // get cooldown of gravity
{
	return cooldown.gravity;
}

void PLAYER::move(char type) // move entity on map
{
	if (type == 'r') // right
	{
		for (int dot = 0; dot < x.size(); dot++)
		{
			y[dot] += 1;
		}
	}
	if (type == 'l') // left
	{
		for (int dot = 0; dot < x.size(); dot++)
		{
			y[dot] -= 1;
		}
	}
	if (type == 'u') // up
	{
		for (int dot = 0; dot < x.size(); dot++)
		{
			x.at(dot) -= 1;
		}
	}
	if (type == 'd') // down
	{
		for (int dot = 0; dot < x.size(); dot++)
		{
			x[dot] += 1;
		}
	}
}
void PLAYER::setPos(std::vector<int> std_x, std::vector<int> std_y) // set player pos
{
	x = std_x; // set x
	y = std_y; // set y
}

void PLAYER::setCAD() // set cooldown for (A) (D)
{
	cooldown.AD = std_COOLDOWN.AD;
}
void PLAYER::setCWS() // set cooldown for (W) (S)
{
	cooldown.WS = std_COOLDOWN.WS;
}
void PLAYER::setCG() // set cooldown of gravity
{
	cooldown.gravity = std_COOLDOWN.gravity;
}
void PLAYER::setCAD(int lcad) // set cooldown for (A) (D) over
{
	cooldown.AD = lcad;
}
void PLAYER::setCWS(int lcws) // set cooldown for (W) (S) over
{
	cooldown.WS = lcws;
}
void PLAYER::setCG(int lcg) // set cooldown of gravity over
{
	cooldown.gravity = lcg;
}
void PLAYER::setCHAR(char ch) // set character of player
{
	character = ch;
}

bool PLAYER::voidUnder(std::vector<std::vector<block>>& board) // if player hit the floor
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]].character == '#' || 
		board[x[x.size() - 1] + 1][y[y.size() - 1]].character == '|' || 
		board[x[x.size() - 1] + 1][y[y.size() - 1]].character == '-' ||  
		board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'S' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]].character == '+' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'M' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]].character == character ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'F') return true;

	return false;
}
bool PLAYER::collisions(std::vector<std::vector<block>>& board, int type) // if the player touched a solid block
{
	if (type == 80) 
	{
		if (board[x[x.size() - 1] + 1][y[y.size() - 1]].character == '#' || 
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'F' || 
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == '+' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'S' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == character) return true;
	}
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every player's element
	{
		if (type == 77) if (board[x[dot]][y[dot] + 1].character == '#' || 
							board[x[dot]][y[dot] + 1].character == 'D' || 
							board[x[dot]][y[dot] + 1].character == 'F' || 
							board[x[dot]][y[dot] + 1].character == 'S' ||
							board[x[dot]][y[dot] + 1].character == character || y[0] == board[0].size() - 2) return true;

		if (type == 75) if (board[x[dot]][y[dot] - 1].character == '#' || 
							board[x[dot]][y[dot] - 1].character == 'D' || 
							board[x[dot]][y[dot] - 1].character == 'F' || 
							board[x[dot]][y[dot] - 1].character == 'S' ||
							board[x[dot]][y[dot] - 1].character == character || y[0] == 1) return true;
	}
	return false;
}
bool PLAYER::getGravity() // get player gravity (t) (f)
{
	return gravity;
}
bool PLAYER::ladder(std::vector<std::vector<block>>& board) // check player on ladder
{
	if (board[x[x.size() - 1]][y[y.size() - 1]].character == '|') // if player on ladder then return true
		return true; 
	return false;
}
bool PLAYER::limit(std::vector<std::vector<block>>& board) // if the player is in prohibited territory
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'D') return true;
	return false;
}
bool PLAYER::onspeedbooster(std::vector<std::vector<block>>& board) // if player stay on speed booster element
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'S') return true;
	return false;
}
bool PLAYER::onstairs(std::vector<std::vector<block>>& board, int type) // if player stay on stairs
{
	if (type == 77)
	{
		for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every player's element
		{
			if (board[x[dot]][y[dot] + 1].character == '+') return true;
		}
	}
	if (type == 75)
	{
		for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every player's element
		{
			if (board[x[dot]][y[dot] - 1].character == '+') return true;
		}
	}
	return false;
}
char PLAYER::getGType() // get gravity type
{
	return GType;
}

void PMAP::add(std::string key, PLAYER player) // add some element in map
{
	list.insert(std::make_pair(key, player));
}
void PMAP::rem(std::string key) // remove some element from map
{
	if (list.contains(key))
	{
		std::map <std::string, PLAYER>::iterator iter;
		iter = list.find(key);
		list.erase(iter);
	}
}
PLAYER PMAP::find(std::string key) // find some element of map
{
	std::map <std::string, PLAYER>::iterator iter;
	iter = list.find(key);
	return iter->second;
}
void PMAP::set(std::map <std::string, PLAYER> t_map) // set map
{
	list = t_map;
}
std::map<std::string, PLAYER> PMAP::get() // get some element from map
{
	return list;
}