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

std::vector<std::vector<char>> PLAYER::spawn(std::vector<std::vector<char>> board) // place entity on map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]] = character;
	}

	return board;
}
std::vector<std::vector<char>> PLAYER::kill(std::vector<std::vector<char>> board) // delete entity from map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]] = ' ';
	}

	return board;
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

bool PLAYER::voidUnder(std::vector<std::vector<char>> board) // if player hit the floor
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == '#' || 
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == '|' || 
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == '-' ||  
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'S' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == '+' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'M' ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == character ||
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'F') return true;

	return false;
}
bool PLAYER::collisions(std::vector<std::vector<char>> board, int type) // if the player touched a solid block
{
	if (type == 80) 
	{
		if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == '#' || 
			board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'F' || 
			board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'M' || 
			board[x[x.size() - 1] + 1][y[y.size() - 1]] == '+' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'S' ||
			board[x[x.size() - 1] + 1][y[y.size() - 1]] == character) return true;
	}
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every player's element
	{
		if (type == 77) if (board[x[dot]][y[dot] + 1] == 'M' || 
							board[x[dot]][y[dot] + 1] == '#' || 
							board[x[dot]][y[dot] + 1] == 'D' || 
							board[x[dot]][y[dot] + 1] == 'F' || 
							board[x[dot]][y[dot] + 1] == 'S' ||
							board[x[dot]][y[dot] + 1] == character || y[0] == board[0].size() - 2) return true;

		if (type == 75) if (board[x[dot]][y[dot] - 1] == 'M' || 
							board[x[dot]][y[dot] - 1] == '#' || 
							board[x[dot]][y[dot] - 1] == 'D' || 
							board[x[dot]][y[dot] - 1] == 'F' || 
							board[x[dot]][y[dot] - 1] == 'S' ||
							board[x[dot]][y[dot] - 1] == character || y[0] == 1) return true;
	}
	return false;
}
bool PLAYER::getGravity() // get player gravity (t) (f)
{
	return gravity;
}
bool PLAYER::ladder(std::vector<std::vector<char>> board) // check player on ladder
{
	if (board[x[x.size() - 1]][y[y.size() - 1]] == '|') // if player on ladder then return true
		return true; 
	return false;
}
bool PLAYER::limit(std::vector<std::vector<char>> board) // if the player is in prohibited territory
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'D' || board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'B') return true;
	return false;
}
bool PLAYER::onspeedbooster(std::vector<std::vector<char>> board) // if player stay on speed booster element
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'S') return true;
	return false;
}
bool PLAYER::onstairs(std::vector<std::vector<char>> board, int type) // if player stay on stairs
{
	if (type == 77)
	{
		for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every player's element
		{
			if (board[x[dot]][y[dot] + 1] == '+') return true;
		}
	}
	if (type == 75)
	{
		for (int dot = 0; dot < x.size() || dot < y.size(); dot++) // check every player's element
		{
			if (board[x[dot]][y[dot] - 1] == '+') return true;
		}
	}
	return false;
}
char PLAYER::getGType() // get gravity type
{
	return GType;
}