#include "..\..\..\include\entities\sys\render.h"

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