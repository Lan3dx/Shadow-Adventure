#include "../include/gravity.h"

void gravitationB(PMAP* players, std::vector<std::vector<block>>& board, std::vector<std::vector<block>>& g_board) // gravity func for bullets
{
	auto playerMap = players->get(); // old player map
	std::map < std::string, PLAYER > npm = {}; // new player map

	for (auto& entityP : playerMap)
	{
		PLAYER player = entityP.second;

		auto bulletMap = player.getBullets().get(); // old bullet map
		std::map < std::string, BULLET > nbm = {}; // new bullet map

		for(auto& entityB : bulletMap)
		{
			BULLET bullet = entityB.second;
			bullet.kill(std::ref(board));
			board = g_board;

			if (!bullet.touch(g_board)) // if the bullet hit the wall
			{
				if (g_board[bullet.getX()][bullet.getY()].durability == 0)
				{
					g_board[bullet.getX()][bullet.getY()].character = ' ';
				}
				else
				{
					g_board[bullet.getX()][bullet.getY()].durability -= 1;
					if (g_board[bullet.getX()][bullet.getY()].durability == 0)
					{
						g_board[bullet.getX()][bullet.getY()].character = ' ';
					}
				}
				player.getBullets().rem(entityB.first);
			}
			else
			{
				if (bullet.getGravity()) // if bullet have gravity
				{
					if (!(bullet.getCG() > 0))
					{
						bullet.kill(std::ref(board)); // kill bullet
						bullet.move(bullet.getGType()); // move bullet
						bullet.spawn(std::ref(board)); // spawn bullet
						bullet.setCG();
					}
				}
				nbm.insert(std::make_pair(entityB.first, bullet)); // add bullet to new bullets map
			}
		}
		player.setBullets(nbm);
		npm.insert(std::make_pair(entityP.first, player));
	}
	players->set(npm);
}

void gravitationM(MMAP* mobs, std::vector<std::vector<block>>& board, std::vector<std::vector<block>>& g_board) // gravity func for mob
{
	auto entityMap = mobs->get(); // old mob map
	std::map < std::string, MOB > nmm = {}; // new mob map
	for (auto& entityS : entityMap)
	{
		MOB entity = entityS.second;
		if (entity.limit(board)) // if the mob is in prohibited territory
		{
			entity.kill(std::ref(board)); // kill mob
			continue;
		}

		if (entity.getGravity()) // if mob have gravity
		{
			if (!entity.voidUnder(board)) // if under mob void
			{
				if (!entity.ladder(board)) // if mob NOT on ladder
				{
					if (!entity.collisions(board, entity.getGType())) // if mob not in the map
					{
						if (!(entity.getCG() > 0)) // CG - gravity cooldown
						{
							board = g_board; // clear map
							entity.kill(std::ref(board)); // kill mob
							entity.move(entity.getGType()); // move mob
							entity.spawn(std::ref(board)); // spawn mob
							entity.setCG();
						}
					}
				}
			}
		}
		nmm.insert(std::make_pair(entityS.first, entity)); // add to new mobs map
	}
	mobs->set(nmm); // set old mob map
}
void gravitationP(PMAP* players, std::vector<std::vector<block>>& board, std::vector<std::vector<block>>& g_board) // gravity func for player
{
	auto entityMap = players->get(); // old players map
	std::map < std::string, PLAYER > npm = {}; // new players map
	for (auto& entityS : entityMap)
	{
		PLAYER entity = entityS.second;
		if (entity.limit(board)) // if the player is in prohibited territory
		{
			entity.setPos({ 39, 40, 41 }, { 5, 5, 5 }); // change coords player
			entity.kill(std::ref(board)); // kill player
			PlaySound(music::DEATH, NULL, SND_FILENAME | SND_ASYNC);
			entity.move(entity.getGType()); // move player
			entity.spawn(std::ref(board)); // spawn player
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
							board = g_board; // clear map
							entity.kill(std::ref(board)); // kill player
							entity.move(entity.getGType()); // move player
							entity.spawn(std::ref(board)); // spawn player
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