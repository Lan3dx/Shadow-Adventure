#include "../include/elistener.h"

std::string listenerB(BMAP* bullets, std::vector<std::vector<block>>& board) // listener func for bullets
{
	std::string returned = "null";
	auto entityMap = bullets->get(); // old bullet map
	std::map < std::string, BULLET > nbm = {}; // new bullet map
	for (auto& entityS : entityMap)
	{
		BULLET entity = entityS.second;
		nbm.insert(std::make_pair(entityS.first, entity)); // add bullet to new bullets map
	}
	bullets->set(nbm); // set old bullets map
	return returned;
}
std::string listenerM(MMAP* mobs, std::vector<std::vector<block>>& board, int* mob_shot_cd) // listener func for mob
{
	std::string returned = "null";
	auto entityMap = mobs->get(); // old mob map
	std::map < std::string, MOB > nmm = {}; // new mob map
	for (auto& entityS : entityMap)
	{
		MOB entity = entityS.second;
		if (entity.getHP() <= 0)
		{
			entity.kill(std::ref(board));
			continue;
		}
		if (entity.getMobile())
		{
			for (int dot = 0; dot < entity.getY().size(); dot++)
			{
				if (board[entity.getX()[dot] - (uint64_t)2][entity.getY()[dot]].character == '>')
				{
					if (!entity.collisions(board, 77)) // if there are no walls near the mob
					{
						if (entity.onstairs(std::ref(board), 77))
						{
							entity.move('u');
						}
						entity.move('r');
					}
					break;
				}
				if (board[entity.getX()[dot] - (uint64_t)2][entity.getY()[dot]].character == '<')
				{
					if (!entity.collisions(board, 75)) // if there are no walls near the mob
					{
						if (entity.onstairs(std::ref(board), 75))
						{
							entity.move('u');
						}
						entity.move('l');
					}
					break;
				}
			}
		}
		if (entity.onspeedbooster(board))
		{
			for (int i = 0; i < 7; i++)
			{
				entity.move('u');
			}
		}
		if (!(*mob_shot_cd > 0) && entityS.first == "gun")
		{
			entity.shoot('l');
			*mob_shot_cd = 90;
		}
		if (entity.getHP() <= 0)
		{
			entity.kill(std::ref(board));
		}
		nmm.insert(std::make_pair(entityS.first, entity)); // add to new mobs map
	}
	mobs->set(nmm); // set old mob map
	return returned;
}
std::string listenerP(PMAP* players, std::vector<std::vector<block>>& board, std::string selected, PlayerFrame* pframe, Corners* corners) // listener func for player
{
	std::string returned = "null";
	auto entityMap = players->get(); // old players map
	std::map < std::string, PLAYER > npm = {}; // new players map
	for (auto& entityS : entityMap)
	{
		PLAYER entity = entityS.second;	
		if (entity.onspeedbooster(board))
		{
			for (int i = 0; i < 7; i++)
			{
				entity.move('u');
			}
			entity.setFL(0);
			returned = "boost";
		}
		if (entity.getHP() <= 0)
		{
			if (entityS.first == selected)
			{
				pframe->x = 5;
				pframe->y = 40;
				pframe->ischanged = true;
				corners->lt = 50;
			}
			entity.setPos({ 39, 40, 41 }, { 5, 5, 5 }); // change player cords
			entity.kill(std::ref(board)); // kill player
			entity.move(entity.getGType()); // move player
			entity.spawn(std::ref(board)); // spawn player
			entity.setHP(10);
			entity.setFL(0);
			returned = "death";
		}
		npm.insert(std::make_pair(entityS.first, entity)); // add to new players map
	}
	players->set(npm); // set old players map
	return returned;
}