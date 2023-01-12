#include "..\..\..\include\entities\sys\render.h"

void entitiesRender(PMAP players, BMAP bullets, MMAP mobs, std::vector<std::vector<char>>& board, std::vector<std::vector<char>> g_board) // render all entities
{
	board = g_board; // board clear
	for (auto& entityS : players.get())
	{
		entityS.second.kill(std::ref(board));
		entityS.second.spawn(std::ref(board));
	}
	for (auto& entityS : bullets.get())
	{
		entityS.second.kill(std::ref(board));
		entityS.second.spawn(std::ref(board));
	}
	for (auto& entityS : mobs.get())
	{
		entityS.second.kill(std::ref(board));
		entityS.second.spawn(std::ref(board));
	}
}