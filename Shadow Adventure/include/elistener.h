#pragma once

#include <map>

#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/mob.h"
#include "map.h"

std::string listenerB(BMAP*, std::vector<std::vector<block>>&); // listener for bullets 
std::string listenerP(PMAP*, std::vector<std::vector<block>>&); // listener for players
std::string listenerM(MMAP*, std::vector<std::vector<block>>&, int*); // listener func for mob