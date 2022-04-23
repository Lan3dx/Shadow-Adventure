#include "..\..\include\sys\render.h"

void entitiesRender(std::vector<std::vector<char>> map, PMAP, BMAP)
{

}

void render(std::vector<std::vector<char>> map) // output
{
	for (int y = 6; y < map.size() - 8; y++) // columns
	{
		std::cout << ' ';
		for (int x = 1; x < map[y].size() - 1; x++) // lines
		{
			std::cout << map[y][x] << ' ';
		}
		std::cout << '\n'; // next column
	}
}