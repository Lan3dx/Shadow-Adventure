#include "../include/entity.h"

Entity::Entity(std::vector<int> stdX, std::vector<int> stdY, char stdChar, bool stdGravity, char Gt) // constructor
{
	gravity = stdGravity;
	GType = Gt;
	x = stdX;
	y = stdY;
	character = stdChar;
}
std::vector<std::vector<char>> Entity::spawn(std::vector<std::vector<char>> board) // place entity on map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]] = character;
	}

	return board;
}
std::vector<std::vector<char>> Entity::kill(std::vector<std::vector<char>> board) // delete entity from map
{
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		board[x[dot]][y[dot]] = ' ';
	}

	return board;
}
std::vector<int> Entity::getX()
{
	return x;
}
std::vector<int> Entity::getY()
{
	return y;
}
void Entity::move(char type, std::vector<std::vector<char>> board) // move entity on map
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
void Entity::setPos(std::vector<int> std_x, std::vector<int> std_y)
{
	x = std_x;
	y = std_y;
}
void Entity::setX(int stdx)
{
	x.clear();
	x.push_back(stdx);
}
void Entity::setY(int stdy)
{
	y.clear();
	y.push_back(stdy);
}
void Entity::setX(std::vector<int> stdx)
{
	x = stdx;
}
void Entity::setY(std::vector<int> stdy)
{
	y = stdy;
}
bool Entity::voidUnder(std::vector<std::vector<char>> board)
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == '#' || 
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == '|' || 
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == '-' ||  
		board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'F') return true;

	return false;
}
bool Entity::collisions(std::vector<std::vector<char>> board, int type)
{
	if (type == 80) if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == '#') return true;
	for (int dot = 0; dot < x.size() || dot < y.size(); dot++)
	{
		if (type == 77) if (board[x[dot]][y[dot] + 1] == '#' || board[x[dot]][y[dot] + 1] == 'D' || board[x[dot]][y[dot] + 1] == 'F' || y[0] == board[0].size() - 2) return true;
		if (type == 75) if (board[x[dot]][y[dot] - 1] == '#' || board[x[dot]][y[dot] - 1] == 'D' || board[x[dot]][y[dot] - 1] == 'F' || y[0] == 1) return true;
	}

	return false;
}
bool Entity::getGravity()
{
	if (gravity) return true;
	else return false;
}
bool Entity::ladder(std::vector<std::vector<char>> board)
{
	if (board[x[x.size() - 1]][y[y.size() - 1]] == '|') return true;

	return false;
}
bool Entity::limit(std::vector<std::vector<char>> board)
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == 'D') return true;
	return false;
}
bool Entity::touch(std::vector<std::vector<char>> board)
{
	if (board[x[x.size() - 1]][y[y.size() - 1]+1] != ' ' && board[x[x.size() - 1]][y[y.size() - 1]+1] != 'P') return true;
	if (board[x[x.size() - 1]][y[y.size() - 1]-1] != ' ' && board[x[x.size() - 1]][y[y.size() - 1]-1] != 'P') return true;
	return false;
}
char Entity::getGType()
{
	return GType;
}