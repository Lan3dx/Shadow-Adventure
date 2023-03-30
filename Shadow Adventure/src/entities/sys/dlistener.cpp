#include "../../../include/entities/sys/dlistener.h"

int getDamage(int X, int Y, PMAP* players, MMAP* mobs)
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
	auto entityMap1 = mobs->get();
	for (auto& entityS : entityMap1)
	{
		MOB entity1 = entityS.second;

		BMAP ebulletMap = entity1.getBullets();
		auto bullets1 = ebulletMap.get();

		for (auto& entityB1 : bullets1)
		{
			BULLET bullet1 = entityB1.second;
			if (X == bullet1.getY() && Y == bullet1.getX())
			{
				return bullet1.getDMG();
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
				entity.setHP(entity.getHP() - getDamage(entity.getX()[dot], entity.getY()[dot], players, mobs));
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
				entity.setHP(entity.getHP() - getDamage(entity.getX()[dot], entity.getY()[dot], players, mobs));
			}
		}
		nmm.insert(std::make_pair(entityS1.first, entity)); // add player to new mobs map
	}
	mobs->set(nmm); // set old mobs map

	return returned;
}