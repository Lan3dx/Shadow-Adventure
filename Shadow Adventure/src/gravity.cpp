#include <vector>
#include <Windows.h>
#include <map>
#include <iostream>

#include "../include/entity.h"
#include "../include/map.h"
#include "../include/gravity.h"

std::map <std::string, Entity> animatedDrop(std::map <std::string, Entity> entMap, std::vector<std::vector<char>>& board)
{
	std::map <std::string, Entity> nentMap;
	for (auto& entityS : entMap)
	{
		Entity entity = entityS.second;
		if (entity.limit(board))
		{
			entity.setPos({ 39, 40, 41 }, { 5, 5, 5 });
			board = entity.kill(board);
			board = board_init();
			entity.move(entity.getGType(), board);
			board = entity.spawn(board);
		}

		if (entity.getGravity())
		{
			if (!entity.voidUnder(board))
			{
				if (!entity.ladder(board))
				{
					if (!entity.collisions(board, entity.getGType()))
					{
						board = entity.kill(board);
						board = board_init();
						entity.move(entity.getGType(), board);
						board = entity.spawn(board);
						Sleep(30);
					}
				}
			}
		}
		nentMap.insert(std::make_pair(entityS.first, entity));
	}
	return nentMap;
}