#include "../../../include/entities/sys/cooldowns_s.h"
#include "../../../include/sys/logger.h"
#include "../../../include/sys/constants.h"
#include <string>

void cdSet(PMAP* players, MMAP* mobs, int* shot_cd, int* key_cd, int* fps_cd, int* mob_shot_cd) // minus cooldown for all entities
{
	std::map < std::string, PLAYER > npm = {}; // new player map
	for (auto& entityP : players->get())
	{
		PLAYER player = entityP.second;
		std::map < std::string, BULLET > nbm = {}; // new bullet map
		for (auto& entityB : player.getBullets().get())
		{
			BULLET bullet = entityB.second;
			if (bullet.getCG() > 0) { bullet.setCG(bullet.getCG() - 1); }
			if (bullet.getCS() > 0) { bullet.setCS(bullet.getCS() - 1); }
			nbm.insert(std::make_pair(entityB.first, bullet)); // add bullet to new bullets map
		}
		player.setBullets(nbm);

		if (player.getCAD() > 0) { player.setCAD(player.getCAD() - 1); }
		if (player.getCWS() > 0) { player.setCWS(player.getCWS() - 1); }
		if (player.getCG() > 0) { player.setCG(player.getCG() - 1); }
		npm.insert(std::make_pair(entityP.first, player)); // add player to new player map
	}
	players->set(npm); // set player map

	std::map < std::string, MOB > nmm = {}; // new mob map
	for (auto& entityM : mobs->get())
	{
		MOB mob = entityM.second;
		std::map < std::string, BULLET > nbm = {}; // new bullet map
		for (auto& entityB : mob.getBullets().get())
		{
			BULLET bullet = entityB.second;
			if (bullet.getCG() > 0) { bullet.setCG(bullet.getCG() - 1); }
			if (bullet.getCS() > 0) { bullet.setCS(bullet.getCS() - 1); }
			nbm.insert(std::make_pair(entityB.first, bullet)); // add bullet to new bullets map
		}
		mob.setBullets(nbm);

		if (mob.getCAD() > 0) { mob.setCAD(mob.getCAD() - 1); }
		if (mob.getCWS() > 0) { mob.setCWS(mob.getCWS() - 1); }
		if (mob.getCG() > 0) { mob.setCG(mob.getCG() - 1); }
		nmm.insert(std::make_pair(entityM.first, mob)); // add player to new player map
	}
	mobs->set(nmm); // set mobs map

	if (*shot_cd > 0)
	{
		if (!(*shot_cd == 0))
			*shot_cd -= 1;
	}
	if (*key_cd > 0)
	{
		if (!(*key_cd == 0))
			*key_cd -= 1;
	}
	if (*fps_cd > 0)
	{
		if (!(*fps_cd == 0))
			*fps_cd -= 1;
	}
	if (*mob_shot_cd > 0)
	{
		if (!(*mob_shot_cd == 0))
			*mob_shot_cd -= 1;
	}
}