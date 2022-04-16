#include "../include/entity.h"

Entity::Entity(std::vector<int> stdX, std::vector<int> stdY, char stdChar, bool stdGravity) // constructor
{
	gravity = stdGravity;
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
bool Entity::voidUnder(std::vector<std::vector<char>> board)
{
	if (board[x[x.size() - 1] + 1][y[y.size() - 1]] == '#' || board[x[x.size() - 1] + 1][y[y.size() - 1]] == '|' || board[x[x.size() - 1] + 1][y[y.size() - 1]] == '-') return true;

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