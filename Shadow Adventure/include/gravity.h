#pragma once

#include <map>
 
#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/mob.h"
#include "map.h"

void gravitationB(PMAP*, MMAP*, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&); // gravity for bullets 
void gravitationP(PMAP*, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&); // gravity for players
void gravitationM(MMAP*, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&); // gravity func for mob