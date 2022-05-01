#include "../../../include/entities/sys/cooldowns_s.h"

void cdSet(PMAP* players, BMAP* bullets) // minus cooldown for all entities
{
	std::map < std::string, PLAYER > npm = {}; // new player map
	for (auto& entityS : players->get())
	{
		PLAYER entity = entityS.second;
		if (entity.getCAD() > 0) { entity.setCAD(entity.getCAD() - 1); }
		if (entity.getCWS() > 0) { entity.setCWS(entity.getCWS() - 1); }
		if (entity.getCG() > 0) { entity.setCG(entity.getCG() - 1); }
		npm.insert(std::make_pair(entityS.first, entity)); // add player to new players map
	}
	players->set(npm); // set players map

	std::map < std::string, BULLET > nbm = {}; // new bullets map
	for (auto& entityS : bullets->get())
	{
		BULLET entity = entityS.second;
		if (entity.getC() > 0) { entity.setC(entity.getC() - 1); }
		nbm.insert(std::make_pair(entityS.first, entity)); // add bullet to new bullets map
	}
	bullets->set(nbm); // set bullets map
}