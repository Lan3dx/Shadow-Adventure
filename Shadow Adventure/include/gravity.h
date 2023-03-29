#pragma once

#include <map>
 
#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/mob.h"
#include "map.h"

std::string gravitationB(PMAP*, MMAP*, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&); // gravity for bullets 
std::string gravitationP(PMAP*, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&); // gravity for players
std::string gravitationM(MMAP*, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&); // gravity func for mob