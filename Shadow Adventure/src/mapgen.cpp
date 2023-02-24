#include "../include/mapgen.h"

std::vector<std::vector<char>> gen()
{
	std::vector<std::vector<char>> map(100, std::vector<char>(101));

	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 101; x++)
		{
			if (x == 0 || x == 100) // walls have durability is -1, player can't destroy them
			{
				map[y][x] = '#';
			}
			else
			{
				map[y][x] = ' ';
			}
		}
	}
	for (int x = 0; x < 101; x++)
	{
		map[0][x] = 'D';
		map[99][x] = 'D';
	}

	int ladders = rand() % (15 + 1 - 7) + 7;
	int platforms = rand() % (30 + 1 - 10) + 10;

	for (int p = 0; p < platforms; p++)
	{
		int yrand = rand() % (80 + 1 - 10) + 10;
		for (int i = rand() % (60 + 1 - 3) + 3; i < rand() % (60 + 1 - 20) + 20; i++)
		{
			map[yrand][i] = '#';
		}
	}
	for (int l = 0; l < ladders; l++)
	{
		int xrand = rand() % (80 + 1 - 10) + 10;
		for (int i = rand() % (60 + 1 - 3) + 3; i < rand() % (60 + 1 - 20) + 20; i++)
		{
			map[i][xrand] = '|';
		}
	}

	return map;
}