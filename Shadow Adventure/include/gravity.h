#pragma once

#include <map>
 
#include "../include/entities/player.h"
#include "../include/entities/bullet.h"
#include "../include/spawn.h"
#include "../include/map.h"

void gravitationB(BMAP* bullets, std::vector<std::vector<char>>& board); // gravity for bullets
void gravitationP(PMAP* players, std::vector<std::vector<char>>& board); // gravity for players