#pragma once

#include <map>
 
#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/mob.h"
#include "spawn.h"
#include "sys/musicloader.h"
#include "map.h"

void gravitationB(BMAP*, std::vector<std::vector<char>>&, std::vector<std::vector<char>>); // gravity for bullets 
void gravitationP(PMAP*, std::vector<std::vector<char>>&, std::vector<std::vector<char>>); // gravity for players
void gravitationM(MMAP*, std::vector<std::vector<char>>&, std::vector<std::vector<char>>); // gravity func for mob