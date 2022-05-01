#include "../include/gravity.h"

void gravitationB(BMAP* bullets, std::vector<std::vector<char>>& board) // gravity func for bullets
{
	auto entityMap = bullets->get(); // old bullet map
	std::map < std::string, BULLET > nbm = {}; // new bullet map
	for (auto& entityS : entityMap)
	{
		BULLET entity = entityS.second;

		board = board_init(); // clear map
		if (!entity.touch(board)) // if the bullet hit the wall
		{
			bullets->rem(entityS.first); // remove entities from the map
		}
		else
		{
			if (entity.getGravity()) // if bullet have gravity
			{
				board = entity.kill(board); // kill bullet
				entity.move(entity.getGType()); // move bullet
				board = entity.spawn(board); // spawn bullet
				nbm.insert(std::make_pair(entityS.first, entity)); // add bullet to new bullets map
			}
		}
	}
	bullets->set(nbm); // set old bullets map
}

void gravitationP(PMAP* players, std::vector<std::vector<char>>& board) // gravity func for player
{
	auto entityMap = players->get(); // old players map
	std::map < std::string, PLAYER > npm = {}; // new players map
	for (auto& entityS : entityMap)
	{
		PLAYER entity = entityS.second;
		if (entity.limit(board)) // if the player is in prohibited territory
		{
			entity.setPos({ 39, 40, 41 }, { 5, 5, 5 }); // change coords player
			board = entity.kill(board); // kill player
			entity.move(entity.getGType()); // move player
			board = entity.spawn(board); // spawn player
		}

		if (entity.getGravity()) // if player have gravity
		{
			if (!entity.voidUnder(board)) // if under player void
			{
				if (!entity.ladder(board)) // if player NOT on ladder
				{
					if (!entity.collisions(board, entity.getGType())) // if player not in the map
					{
						if (!(entity.getCG() > 0))
						{
							board = board_init(); // clear map
							board = entity.kill(board); // kill player
							entity.move(entity.getGType()); // move player
							board = entity.spawn(board); // spawn player
							entity.setCG();
						}
					}
				}
			}
		}
		npm.insert(std::make_pair(entityS.first, entity)); // add to new players map
	}
	players->set(npm); // set old players map
}