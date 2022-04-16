#include <vector>
#include <Windows.h>

#include "../include/logger.h"
#include "../include/entity.h"
#include "../include/map.h"
#include "../include/gravity.h"

std::vector<Entity> Respawn(std::vector<Entity> entity, std::vector<std::vector<char>>& board, int pos)
{
	clog("info", "player respawned");
	entity[pos].setPos({ 39, 40, 41 }, { 5, 5, 5 });
	board = entity[pos].kill(board);
	board = board_init();
	board = entity[pos].spawn(board);

	return entity;
}

std::vector<Entity> animatedDrop(std::vector<Entity> entity, std::vector<std::vector<char>>& board, char type)
{	
	for (int i = 0; i < entity.size(); i++)
	{
		if (entity[i].limit(board))
		{
			clog("info", "player dead");
			entity[i].setPos({ 39, 40, 41 }, { 5, 5, 5 });
			board = entity[i].kill(board);
			board = board_init();
			entity[i].move(type, board);
			board = entity[i].spawn(board);
		}

		if (entity[i].getGravity())
		{
			if (!entity[i].voidUnder(board))
			{
				if (!entity[i].ladder(board))
				{
					if (!entity[i].collisions(board, type))
					{
						board = entity[i].kill(board);
						board = board_init();
						entity[i].move(type, board);
						board = entity[i].spawn(board);
						Sleep(30);
					}
				}
			}
		}
	}
	return entity;	
}