#include "../../../include/entities/sys/dlistener.h"

int getDamage(int X, int Y, PMAP* players, MMAP* mobs, std::vector<animation> &animations)
{
	int returned = 0;

	// player
	auto entityMap = players->get();
	std::map < std::string, PLAYER > npm = {}; // new player map
	for (auto& entityS : entityMap)
	{
		PLAYER entity = entityS.second;
		BMAP ebulletMap = entity.getBullets();
		auto bullets = ebulletMap.get();

		std::map < std::string, BULLET > nbm = {}; // new bullet map
		for (auto& entityB : bullets)
		{
			BULLET bullet = entityB.second;
			if (Y == bullet.getY() && X == bullet.getX())
			{
				returned = bullet.getDMG();
				std::string s = "-";
				s += std::to_string(returned);
				animation a = { X-2, Y-1, 30, s};
				animations.push_back(a);
				continue;
			}
			nbm.insert(std::make_pair(entityB.first, bullet)); // add bullet to new bullets map
		}
		entity.setBullets(nbm);
		npm.insert(std::make_pair(entityS.first, entity)); // add player to new players map
	}
	players->set(npm);

	// mob
	auto entityMap1 = mobs->get();
	std::map < std::string, MOB > nmm = {}; // new mob map
	for (auto& entityS : entityMap1)
	{
		MOB entity1 = entityS.second;

		BMAP ebulletMap = entity1.getBullets();
		auto bullets1 = ebulletMap.get();

		std::map < std::string, BULLET > nbm1 = {}; // new bullet map
		for (auto& entityB1 : bullets1)
		{
			BULLET bullet1 = entityB1.second;
			if (X == bullet1.getY() && Y == bullet1.getX())
			{
				returned = bullet1.getDMG();
				std::string s = "-";
				s += std::to_string(returned);
				animation a = { X-2, Y-1, 30, s };
				animations.push_back(a);
				continue;
			}
			nbm1.insert(std::make_pair(entityB1.first, bullet1)); // add bullet to new bullets map
		}
		entity1.setBullets(nbm1);
		nmm.insert(std::make_pair(entityS.first, entity1));
	}
	mobs->set(nmm);

	return returned;
}

std::string listenerD(PMAP* players, MMAP* mobs, std::vector<std::vector<block>>& board, std::vector<animation>& animations)
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
				entity.setHP(entity.getHP() - getDamage(entity.getX()[dot], entity.getY()[dot], players, mobs, std::ref(animations)));
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
				entity.setHP(entity.getHP() - getDamage(entity.getX()[dot], entity.getY()[dot], players, mobs, std::ref(animations)));
			}
		}
		nmm.insert(std::make_pair(entityS1.first, entity)); // add player to new mobs map
	}
	mobs->set(nmm); // set old mobs map

	return returned;
}