#include "../../../include/entities/sys/cooldowns_s.h"
#include "../../../include/sys/constants.h"

void cdSet(PMAP* players, MMAP* mobs, int* shot_cd, int* key_cd, int* fps_cd) // minus cooldown for all entities
{
	auto playerMap = players->get(); // old player map
	std::map < std::string, PLAYER > npm = {}; // new player map

	for (auto& entityP : playerMap)
	{
		PLAYER player = entityP.second;

		auto bulletMap = player.getBullets().get(); // old bullet map
		std::map < std::string, BULLET > nbm = {}; // new bullet map

		for (auto& entityB : bulletMap)
		{
			BULLET bullet = entityB.second;
			if (bullet.getCG() > 0) { bullet.setCG(bullet.getCG() - 1); }
			if (bullet.getCS() > 0) { bullet.setCS(bullet.getCS() - 1); }
			nbm.insert(std::make_pair(entityB.first, bullet)); // add bullet to new bullets map
		}
		player.getBullets().set(nbm);

		if (player.getCAD() > 0) { player.setCAD(player.getCAD() - 1); }
		if (player.getCWS() > 0) { player.setCWS(player.getCWS() - 1); }
		if (player.getCG() > 0) { player.setCG(player.getCG() - 1); }

		npm.insert(std::make_pair(entityP.first, player)); // add player to new player map
	}
	players->set(npm); // set player map

	std::map < std::string, MOB > nmm = {}; // new mob map
	for (auto& entityS : mobs->get())
	{
		MOB entity = entityS.second;
		if (entity.getCAD() > 0) { entity.setCAD(entity.getCAD() - 1); }
		if (entity.getCWS() > 0) { entity.setCWS(entity.getCWS() - 1); }
		if (entity.getCG() > 0) { entity.setCG(entity.getCG() - 1); }
		nmm.insert(std::make_pair(entityS.first, entity)); // add mob to new mobs map
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
}