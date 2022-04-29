#include "../../include/entities/bullet.h"

BULLET::BULLET(int stdX, int stdY, char stdChar, bool stdGravity, char Gt) // constructor
{
	gravity = stdGravity; // gravity
	GType = Gt; // ggravity type
	x = stdX; // pos x
	y = stdY; // pos y
	character = stdChar; // symbol
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

int BULLET::getX() { return x; } // get x
int BULLET::getY() { return y; } // get y

bool BULLET::getGravity() { return gravity; } // get gravity (t) (f)
bool BULLET::touch(std::vector<std::vector<char>> board) // if the bullet hit the wall
{
	if (board[x][y] != ' ' &&  // bullet touch ' ' or '|' then return false
		board[x][y] != '|')
		return false;
	return true;
}

char BULLET::getGType() { return GType; } // get gravity type

std::vector<std::vector<char>> BULLET::spawn(std::vector<std::vector<char>> board) { board[x][y] = character; return board; } // spawn bullet
std::vector<std::vector<char>> BULLET::kill(std::vector<std::vector<char>> board) { board[x][y] = ' '; return board; } // kill bullet