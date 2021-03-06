#include "../../include/entities/mob.h"

MOB::MOB(std::vector<int> stdX, std::vector<int> stdY, char stdChar, bool stdGravity, char Gt, cooldowns cd) // constructor
{
	gravity = stdGravity; // gravity (t) (f) 
	GType = Gt; // gravity type (u,d,l,r)
	x = stdX; // pos x
	y = stdY; // pos y
	character = stdChar; // symbol
	cooldown = cd;
	std_COOLDOWN = cd;
}

std::vector<std::vector<char>> MOB::spawn(std::vector<std::vector<char>> board) // place entity on map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]] = character;
	}

	return board;
}
std::vector<std::vector<char>> MOB::kill(std::vector<std::vector<char>> board) // delete entity from map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]] = ' ';
	}

	return board;
}

std::vector<int> MOB::getX() // get x
{
	return x;
}
std::vector<int> MOB::getY() // get y
{
	return y;
}

int MOB::getCAD() // get cooldown for (A) (D)
{
	return cooldown.AD;
}
int MOB::getCWS() // get cooldown for (W) (S)
{
	return cooldown.WS;
}
int MOB::getCG() // get cooldown of gravity
{
	return cooldown.gravity;
}

void MOB::move(char type) // move entity on map
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
			x[dot] -= 1;
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
void MOB::setPos(std::vector<int> std_x, std::vector<int> std_y) // set player pos
{
	x = std_x; // set x
	y = std_y; // set y
}

void MOB::setCAD() // get cooldown for (A) (D)
{
	cooldown.AD = std_COOLDOWN.AD;
}
void MOB::setCWS() // get cooldown for (W) (S)
{
	cooldown.WS = std_COOLDOWN.WS;
}
void MOB::setCG() // get cooldown of gravity
{
	cooldown.gravity = std_COOLDOWN.gravity;
}
void MOB::setCAD(int lcad) // get cooldown for (A) (D) over
{
	cooldown.AD = lcad;
}
void MOB::setCWS(int lcws) // get cooldown for (W) (S) over
{
	cooldown.WS = lcws;
}
void MOB::setCG(int lcg) // get cooldown of gravity over
{
	cooldown.gravity = lcg;
}

bool MOB::voidUnder(std::vector<std::vector<char>> board) // if player hit the floor
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == '#' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == '|' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == '-' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'F') return true;

	return false;
}
bool MOB::collisions(std::vector<std::vector<char>> board, int type) // if the player touched a solid block
{
	if (type == 80)
	{
		if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == '#' || board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'F') return true;
	}
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every player's element
	{
		if (type == 77) if (board[x[dot]][y[dot] + 1] == '#' || board[x[dot]][y[dot] + 1] == 'D' || board[x[dot]][y[dot] + 1] == 'F' || y[0] == board[0].size() - 2) return true;
		if (type == 75) if (board[x[dot]][y[dot] - 1] == '#' || board[x[dot]][y[dot] - 1] == 'D' || board[x[dot]][y[dot] - 1] == 'F' || y[0] == 1) return true;
	}

	return false;
}
bool MOB::getGravity() // get player gravity (t) (f)
{
	if (gravity) return true;
	else return false;
}
bool MOB::ladder(std::vector<std::vector<char>> board) // check player on ladder
{
	if (board[x[x.size() - 1]][y[y.size() - 1]] == '|') // if player on ladder then return true
		return true;
	return false;
}
bool MOB::limit(std::vector<std::vector<char>> board) // if the player is in prohibited territory
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'D') return true;
	return false;
}

char MOB::getGType() // get gravity type
{
	return GType;
}