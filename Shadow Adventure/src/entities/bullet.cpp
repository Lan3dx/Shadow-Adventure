#include "../../include/entities/bullet.h"

BULLET::BULLET(int stdX, int stdY, char stdChar, bool stdGravity, char Gt, cooldowns cd) // constructor
{
	gravity = stdGravity; // gravity
	GType = Gt; // ggravity type
	x = stdX; // pos x
	y = stdY; // pos y
	character = stdChar; // symbol
	cooldown = cd;
	std_COOLDOWN = cd;
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

bool BULLET::getGravity() { return gravity; } // get gravity (t) (f)
bool BULLET::touch(std::vector<std::vector<char>> board) // if the bullet hit the wall
{
	if (board[x][y] != ' ' &&  // if bullet touch ' ' or '|' then return false
		board[x][y] != '|') return false;
	return true;
}

char BULLET::getGType() { return GType; } // get gravity type

void BULLET::spawn(std::vector<std::vector<char>> &board) { board[x][y] = character; } // spawn bullet
void BULLET::kill(std::vector<std::vector<char>> &board) { board[x][y] = ' '; } // kill bullet