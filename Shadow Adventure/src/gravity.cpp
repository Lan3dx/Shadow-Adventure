#include <Windows.h>
#include <map>
#include <iostream>

#include "../include/entity.h"
#include "../include/map.h"
#include "../include/gravity.h"

std::map <std::string, Entity> spawn(std::map <std::string, Entity> entMap, std::vector<std::vector<char>>& board)
{
	board = board_init();
	std::map <std::string, Entity> nentMap;
	for (auto& entityS : entMap)
	{
		Entity entity = entityS.second;
		board = entity.kill(board);
		board = entity.spawn(board);
		nentMap.insert(std::make_pair(entityS.first, entity));
	}
	return nentMap;
}

std::map <std::string, Entity> gravitation(std::map <std::string, Entity> entMap, std::vector<std::vector<char>>& board)
{
	std::map <std::string, Entity> nentMap;
	for (auto& entityS : entMap)
	{
		Entity entity = entityS.second;
		if (entity.limit(board))
		{
			if (entityS.first == "player")
			{
				entity.setPos({ 39, 40, 41 }, { 5, 5, 5 });
				board = entity.kill(board);
				entity.move(entity.getGType(), board);
				board = entity.spawn(board);
			}
		}
		if (entityS.first == "arrow")
		{
			if (entity.touch(board))
			{
				std::map <std::string, Entity>::iterator iter;
				iter = entMap.find(entityS.first);
				entMap.erase(iter);
				continue;
			}
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