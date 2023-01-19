#include "../../include/entities/mob.h"

MOB::MOB(std::vector<int> stdX, std::vector<int> stdY, char stdChar, bool stdGravity, bool stdMobile, char Gt, cooldowns cd) // constructor
{
	gravity = stdGravity; // gravity (t) (f) 
	mobile = stdMobile; // can be moved
	GType = Gt; // gravity type (u,d,l,r)
	x = stdX; // pos x
	y = stdY; // pos y
	character = stdChar; // symbol
	cooldown = cd;
	std_COOLDOWN = cd;
}

void MOB::spawn(std::vector<std::vector<block>>& board) // place entity on map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]].character = character;
	}
}
void MOB::kill(std::vector<std::vector<block>>& board) // delete entity from map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]].character = ' ';
	}
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
void MOB::setPos(std::vector<int> std_x, std::vector<int> std_y) // set MOB pos
{
	x = std_x; // set x
	y = std_y; // set y
}

void MOB::setCAD() // set cooldown for (A) (D)
{
	cooldown.AD = std_COOLDOWN.AD;
}
void MOB::setCWS() // set cooldown for (W) (S)
{
	cooldown.WS = std_COOLDOWN.WS;
}
void MOB::setCG() // set cooldown of gravity
{
	cooldown.gravity = std_COOLDOWN.gravity;
}
void MOB::setCAD(int lcad) // set cooldown for (A) (D) over
{
	cooldown.AD = lcad;
}
void MOB::setCWS(int lcws) // set cooldown for (W) (S) over
{
	cooldown.WS = lcws;
}
void MOB::setCG(int lcg) // set cooldown of gravity over
{
	cooldown.gravity = lcg;
}
void MOB::setCHAR(char ch) // set character of MOB
{
	character = ch;
}

bool MOB::voidUnder(std::vector<std::vector<block>>& board) // if MOB hit the floor
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
bool MOB::collisions(std::vector<std::vector<block>>& board, int type) // if the MOB touched a solid block
{
	if (type == 80)
	{
		if (board[x[x.size() - 1] + 1][y[y.size() - 1]].character == '#' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'F' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'M' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == '+' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'S' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]].character == character) return true;
	}
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every MOB's element
	{
		if (type == 77) if (board[x[dot]][y[dot] + 1].character == 'M' ||
			board[x[dot]][y[dot] + 1].character == '#' ||
			board[x[dot]][y[dot] + 1].character == 'D' ||
			board[x[dot]][y[dot] + 1].character == 'F' ||
			board[x[dot]][y[dot] + 1].character == 'S' ||
			board[x[dot]][y[dot] + 1].character == character || y[0] == board[0].size() - 2) return true;

		if (type == 75) if (board[x[dot]][y[dot] - 1].character == 'M' ||
			board[x[dot]][y[dot] - 1].character == '#' ||
			board[x[dot]][y[dot] - 1].character == 'D' ||
			board[x[dot]][y[dot] - 1].character == 'F' ||
			board[x[dot]][y[dot] - 1].character == 'S' ||
			board[x[dot]][y[dot] - 1].character == character || y[0] == 1) return true;
	}
	return false;
}
bool MOB::getGravity() // get MOB gravity (t) (f)
{
	return gravity;
}
bool MOB::ladder(std::vector<std::vector<block>>& board) // check MOB on ladder
{
	if (board[x[x.size() - 1]][y[y.size() - 1]].character == '|') // if MOB on ladder then return true
		return true;
	return false;
}
bool MOB::limit(std::vector<std::vector<block>>& board) // if the MOB is in prohibited territory
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'D' || board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'B') return true;
	return false;
}
bool MOB::onspeedbooster(std::vector<std::vector<block>>& board) // if MOB stay on speed booster element
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]].character == 'S') return true;
	return false;
}
bool MOB::onstairs(std::vector<std::vector<block>>& board, int type) // if MOB stay on stairs
{
	if (type == 77)
	{
		for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every MOB's element
		{
			if (board[x[dot]][y[dot] + 1].character == '+') return true;
		}
	}
	if (type == 75)
	{
		for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every MOB's element
		{
			if (board[x[dot]][y[dot] - 1].character == '+') return true;
		}
	}
	return false;
}
bool MOB::getMobile()
{
	return mobile;
}

char MOB::getGType() // get gravity type
{
	return GType;
}