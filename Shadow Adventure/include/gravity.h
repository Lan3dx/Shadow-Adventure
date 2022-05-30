#pragma once

#include <map>
 
#include "../include/entities/player.h"
#include "../include/entities/bullet.h"
#include "../include/entities/mob.h"
#include "../include/spawn.h"
#include "../include/map.h"

void gravitationB(BMAP*, std::vector<std::vector<char>>&); // gravity for bullets 
void gravitationP(PMAP*, std::vector<std::vector<char>>&); // gravity for players
void gravitationM(MMAP*, std::vector<std::vector<char>>&); // gravity func for mob