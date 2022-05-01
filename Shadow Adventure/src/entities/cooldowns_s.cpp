#include "../../include/entities/cooldowns_s.h"

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
	/*for (auto& entityS : bullets.get())
	{
		if (entityS.second.getCAD() > 0) { entityS.second.setCAD(entityS.second.getCAD() - 1); }
		if (entityS.second.getCWS() > 0) {entityS.second.setCWS(entityS.second.getCWS() - 1);}
		if (entityS.second.getCG() > 0) { entityS.second.setCG(entityS.second.getCG() - 1); }
	}*/
}