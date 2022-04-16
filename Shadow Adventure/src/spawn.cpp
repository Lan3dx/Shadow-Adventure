#include <vector>
#include <Windows.h>

#include "../include/logger.h"
#include "../include/entity.h"
#include "../include/map.h"

void animatedDrop(Entity& entity, std::vector<std::vector<char>>& board, char type)
{	
	if (entity.limit(board))
	{
		clog("info", "player dead");
		entity.setPos({ 39, 40, 41 }, { 5, 5, 5 });
		board = entity.kill(board);
		board = board_init();
		entity.move(type, board);
		board = entity.spawn(board);
	}

	if (entity.getGravity())
	{
		if (!entity.voidUnder(board))
		{
			if (!entity.ladder(board))
			{
				if (!entity.collisions(board, type))
				{
					board = entity.kill(board);
					board = board_init();
					entity.move(type, board);
					board = entity.spawn(board);
					Sleep(30);
				}
			}
		}
	}
}