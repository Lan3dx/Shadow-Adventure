#include <vector>
#include <fstream>

#include "../include/map.h"

std::vector<std::vector<char>> board_init() // return clear map
{
	// Create a map
	std::ifstream fin("resources/maps/active.txt");
	std::vector<std::vector<char> > map(48, std::vector<char>(48));
	char sym;
	for (int y = 0; y < 48; y++)
	{
		for (int x = 0; x < 48; x++)
		{
			fin >> sym;
			if (sym == '~')
			{
				map[y][x] = ' ';
			}
			else
			{
				map[y][x] = sym;
			}
		}
	}

	/*for (int y = 0; y < 48; y++)
	{
		for (int x = 0; x < 48; x++)
		{
			map[y][x] = ' ';
		}
	}
	for (int x = 0; x < 48; x++)
	{
		map[0][x] = 'D';
		map[47][x] = 'D';
	}
	for (int y = 0; y < 48; y++)
	{
		map[y][0] = '#';
		map[y][47] = '#';
	}*/

	return map;
}