#include "../../include/entities/bullet.h"

BULLET::BULLET(int stdX, int stdY, char stdChar, bool stdGravity, char Gt) // constructor
{
	gravity = stdGravity;
	GType = Gt;
	x = stdX;
	y = stdY;
	character = stdChar;
}

void BULLET::setX(int stdx) { x = stdx; }
void BULLET::setY(int stdy) { y = stdy; }

int BULLET::getX() { return x; }
int BULLET::getY() { return y; }

bool BULLET::getGravity() { return gravity; }
bool BULLET::touch(std::vector<std::vector<char>> board)
{
	if (board[x][y] != ' ' &&
		board[x][y] != character)
		return true;
	return false;
}

char BULLET::getGType() { return GType; }