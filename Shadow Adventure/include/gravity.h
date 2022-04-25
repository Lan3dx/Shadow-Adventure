#pragma once

#include <Windows.h>
#include <map>
#include <iostream>

#include "../include/entities/player.h"
#include "../include/entities/bullet.h"
#include "../include/spawn.h"
#include "../include/map.h"

std::map < std::string, PLAYER > gravitationP(PMAP& players, std::vector<std::vector<char>>& board);
std::map < std::string, BULLET > gravitationB(BMAP& bullets, std::vector<std::vector<char>>& board);