#include <vector>
#include <fstream>

#include "../include/map.h"

std::vector<std::vector<block>> map_init() // return clear map
{
	// Create a map

	std::ifstream fin("resources/maps/active.txt");
	std::vector<std::vector<block> > map(48, std::vector<block>(48));
	char sym;
	for (int y = 0; y < 48; y++)
	{
		for (int x = 0; x < 48; x++)
		{
			fin >> sym;
			if (sym == '~')
			{
				map[y][x]. character = ' ';
			}
			else
			{
				map[y][x].character = sym;
			}
			map[y][x].durability = 2;
		}
	}
	return map;
}