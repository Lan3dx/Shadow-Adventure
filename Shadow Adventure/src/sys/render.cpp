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

void render(std::vector<std::vector<char>> map, std::string selected, float fps) // output
{
	std::cout << "    FPS: " << round(int(1.0f / fps)) << " | SELECTED: " << selected << "                       " << std::endl; // selected player
	for (int y = 0; y < map.size(); y++) // columns
	{
		std::cout << ' ';
		std::string line;
		for (int x = 0; x < map[y].size(); x++) // lines
		{
			line += map[y][x];
			line += " ";
		}
		std::cout << line;
		std::cout << '\n'; // next column
	}
}