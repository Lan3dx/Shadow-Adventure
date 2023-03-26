#pragma once

#include <map>

#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/mob.h"
#include "map.h"

void listenerB(BMAP*, std::vector<std::vector<block>>&); // listener for bullets 
void listenerP(PMAP*, std::vector<std::vector<block>>&); // listener for players
void listenerM(MMAP*, std::vector<std::vector<block>>&, int*); // listener func for mob