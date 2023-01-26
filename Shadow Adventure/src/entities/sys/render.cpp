#include "..\..\..\include\entities\sys\render.h"

void entitiesRender(PMAP players, MMAP mobs, std::vector<std::vector<block>>& board, std::vector<std::vector<block>>& g_board) // render all entities
{
	board = g_board; // board clear
	for (auto& entityP : players.get())
	{
		for (auto& entityB : entityP.second.getBullets().get())
		{
			entityB.second.kill(std::ref(board));
			entityB.second.spawn(std::ref(board));
		}
		entityP.second.kill(std::ref(board));
		entityP.second.spawn(std::ref(board));
	}
	for (auto& entityM : mobs.get())
	{
		entityM.second.kill(std::ref(board));
		entityM.second.spawn(std::ref(board));
	}
}