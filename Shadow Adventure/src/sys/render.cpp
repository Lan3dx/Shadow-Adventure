#include "..\..\include\sys\render.h"

void entitiesRender(PMAP players, BMAP bullets, MMAP mobs, std::vector<std::vector<char>>& board) // render all entities
{
	board = board_init(); // board clear
	for (auto& entityS : players.get())
	{
		board = entityS.second.kill(board);
		board = entityS.second.spawn(board);
	}
	for (auto& entityS : bullets.get())
	{
		board = entityS.second.kill(board);
		board = entityS.second.spawn(board);
	}
	for (auto& entityS : mobs.get())
	{
		board = entityS.second.kill(board);
		board = entityS.second.spawn(board);
	}
}

void render(std::vector<std::vector<char>> map, std::string selected) // output
{
	std::cout << "Selected: " << selected << "                       " << std::endl; // selected player
	for (int y = 6; y < map.size() - 8; y++) // columns
	{
		std::cout << ' ';
		std::string line;
		for (int x = 1; x < map[y].size() - 1; x++) // lines
		{
			line += map[y][x];
			line += " ";
		}
		std::cout << line;
		std::cout << '\n'; // next column
	}
}