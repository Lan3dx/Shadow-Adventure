#include "../include/gravity.h"
#include <vector>

std::map < std::string, BULLET > gravitation(BMAP& bullets, std::vector<std::vector<char>>& board)
{
	auto entityMap = bullets.get();
	std::map < std::string, BULLET > nbm = {};
	for (auto& entityS : entityMap)
	{
		BULLET entity = entityS.second;

		board = board_init();
		if (entity.touch(board))
		{
			bullets.rem(entityS.first);
			return nbm;
		}
		board = entity.kill(board);
		entity.move(entity.getGType());
		board = entity.spawn(board);
		nbm.insert(std::make_pair(entityS.first, entity));
	}
	return nbm;
}
std::map < std::string, PLAYER > gravitation(PMAP& players, std::vector<std::vector<char>>& board)
{
	auto entityMap = players.get();
	std::map < std::string, PLAYER > npm = {};
	for (auto& entityS : entityMap)
	{
		PLAYER entity = entityS.second;
		if (entity.limit(board))
		{
			entity.setPos({ 39, 40, 41 }, { 5, 5, 5 });
			board = entity.kill(board);
			entity.move(entity.getGType());
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
						entity.move(entity.getGType());
						board = entity.spawn(board);
						Sleep(30);
					}
				}
			}
		}
		npm.insert(std::make_pair(entityS.first, entity));
	}
	return npm;
}