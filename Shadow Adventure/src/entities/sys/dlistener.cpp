#include "../../../include/entities/sys/dlistener.h"

int getDamage(int X, int Y, PMAP* players, MMAP* mobs, std::string type)
{
	if (type == "player")
	{
		auto entityMap = players->get();
		for (auto& entityS : entityMap)
		{
			PLAYER entity = entityS.second;

			BMAP ebulletMap = entity.getBullets();
			auto bullets = ebulletMap.get();

			for (auto& entityB : bullets)
			{
				BULLET bullet = entityB.second;
				if (Y == bullet.getY() && X == bullet.getX())
				{
					return bullet.getDMG();
				}
			}
		}
	}
	else if (type == "mob") 
	{
		auto entityMap = mobs->get();
		for (auto& entityS : entityMap)
		{
			MOB entity = entityS.second;

			BMAP ebulletMap = entity.getBullets();
			auto bullets = ebulletMap.get();

			for (auto& entityB : bullets)
			{
				BULLET bullet = entityB.second;
				if (X == bullet.getY() && Y == bullet.getX())
				{
					return bullet.getDMG();
				}
			}
		}
	}
	return 0;
}

std::string listenerD(PMAP* players, MMAP* mobs, std::vector<std::vector<block>>& board)
{
	std::string returned = "null";

	// player listener
	auto entityMap = players->get(); // old player map
	std::map < std::string, PLAYER > npm = {}; // new player map
	for (auto& entityS : entityMap)
	{
		PLAYER entity = entityS.second;
		for (int dot = 0; dot < entity.getX().size() || dot < entity.getY().size(); dot++) // check every player's element
		{
			if (board[entity.getX()[dot]][entity.getY()[dot]].character == 'B')
			{
				entity.setHP(entity.getHP() - getDamage(entity.getX()[dot], entity.getY()[dot], players, mobs, "player"));
				entity.setHP(entity.getHP() - getDamage(entity.getX()[dot], entity.getY()[dot], players, mobs, "mob"));
			}
		}
		npm.insert(std::make_pair(entityS.first, entity)); // add player to new players map
	}
	players->set(npm); // set old players map

	// mob listener
	auto entityMap1 = mobs->get(); // old mob map
	std::map < std::string, MOB > nmm = {}; // new mob map
	for (auto& entityS1 : entityMap1)
	{
		MOB entity = entityS1.second;
		for (int dot = 0; dot < entity.getX().size() || dot < entity.getY().size(); dot++) // check every mob's element
		{
			if (board[entity.getX()[dot]][entity.getY()[dot]].character == 'B')
			{
				entity.setHP(entity.getHP() - getDamage(entity.getX()[dot], entity.getY()[dot], players, mobs, "player"));
				entity.setHP(entity.getHP() - getDamage(entity.getX()[dot], entity.getY()[dot], players, mobs, "mob"));
			}
		}
		nmm.insert(std::make_pair(entityS1.first, entity)); // add player to new mobs map
	}
	mobs->set(nmm); // set old mobs map

	return returned;
}