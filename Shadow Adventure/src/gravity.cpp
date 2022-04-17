#include <vector>
#include <Windows.h>
#include <map>

#include "../include/logger.h"
#include "../include/entity.h"
#include "../include/map.h"
#include "../include/gravity.h"

std::map <std::string, Entity> animatedDrop(EntityMap entMap, std::vector<std::vector<char>>& board)
{
	auto entityMp = entMap.get();
	for (auto& entityS : entityMp)
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
		entMap.add(entityS.first, entityS.second);
	}
	return entityMp;
}