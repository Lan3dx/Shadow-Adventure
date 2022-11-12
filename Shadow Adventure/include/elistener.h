#pragma once

#include <map>

#include "entities/player.h"
#include "entities/bullet.h"
#include "entities/mob.h"
#include "spawn.h"
#include "sys/musicloader.h"
#include "map.h"

void listenerB(BMAP*, std::vector<std::vector<char>>&); // listener for bullets 
void listenerP(PMAP*, std::vector<std::vector<char>>&); // listener for players
void listenerM(MMAP*, std::vector<std::vector<char>>&); // listener func for mob