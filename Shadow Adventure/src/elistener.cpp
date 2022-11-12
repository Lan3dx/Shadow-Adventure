#include "../include/elistener.h"

void listenerB(BMAP* bullets, std::vector<std::vector<char>>& board) // listener func for bullets
{
	auto entityMap = bullets->get(); // old bullet map
	std::map < std::string, BULLET > nbm = {}; // new bullet map
	for (auto& entityS : entityMap)
	{
		BULLET entity = entityS.second;
		nbm.insert(std::make_pair(entityS.first, entity)); // add bullet to new bullets map
	}
	bullets->set(nbm); // set old bullets map
}
void listenerM(MMAP* mobs, std::vector<std::vector<char>>& board) // listener func for mob
{
	auto entityMap = mobs->get(); // old mob map
	std::map < std::string, MOB > nmm = {}; // new mob map
	for (auto& entityS : entityMap)
	{
		MOB entity = entityS.second;
		nmm.insert(std::make_pair(entityS.first, entity)); // add to new mobs map
	}
	mobs->set(nmm); // set old mob map
}
void listenerP(PMAP* players, std::vector<std::vector<char>>& board) // listener func for player
{
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
			PlaySound(music::BOOST, NULL, SND_FILENAME | SND_ASYNC);
		}
		npm.insert(std::make_pair(entityS.first, entity)); // add to new players map
	}
	players->set(npm); // set old players map
}