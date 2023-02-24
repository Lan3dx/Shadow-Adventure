#include <vector>
#include <fstream>

#include "../include/map.h"

std::vector<std::vector<block>> map_init() // return clear map
{
	// Create a map

	std::ifstream fin("resources/maps/active.txt");
	std::vector<std::vector<block> > map(100, std::vector<block>(101));
	char sym;
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 101; x++)
		{
			fin >> sym;
			if (sym == '~')
			{
				map[y][x].character = ' ';
				map[y][x].color = 15;
			}
			else
			{
				map[y][x].character = sym;
				map[y][x].color = 10;
			}
			if (x == 0 || x == 100) // walls have durability is -1, player can't destroy them
			{
				map[y][x].durability = -1;
			}
			else
			{
				map[y][x].durability = 2;
			}
		}
	}
	return map;
}