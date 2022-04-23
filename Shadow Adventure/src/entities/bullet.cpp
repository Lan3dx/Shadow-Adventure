#include "../../include/entities/bullet.h"

BULLET::BULLET(int stdX, int stdY, char stdChar, bool stdGravity, char Gt) // constructor
{
	gravity = stdGravity;
	GType = Gt;
	x = stdX;
	y = stdY;
	character = stdChar;
}

void BULLET::move(char type) // move entity on map
{
	if (type == 'r') {y += 1;}
	if (type == 'l') {y -= 1;}
	if (type == 'u'){x -= 1;}
	if (type == 'd') {x += 1;}
}
void BULLET::setX(int stdx) { x = stdx; }
void BULLET::setY(int stdy) { y = stdy; }

int BULLET::getX() { return x; }
int BULLET::getY() { return y; }

bool BULLET::getGravity() { return gravity; }
bool BULLET::touch(std::vector<std::vector<char>> board)
{
	if (board[x][y] != ' ' &&
		board[x][y] != '|')
		return true;
	return false;
}

char BULLET::getGType() { return GType; }

std::vector<std::vector<char>> BULLET::spawn(std::vector<std::vector<char>> board) { board[x][y] = character; return board; }
std::vector<std::vector<char>> BULLET::kill(std::vector<std::vector<char>> board) { board[x][y] = ' '; return board; }