#pragma once

#include <vector>
#include <Windows.h>
#include <map>
#include <string>

#include "entities/player.h"
#include "spawn.h"
#include "map.h"

std::map < std::string, PLAYER > control(PMAP&, std::string, std::vector<std::vector<char>>&, int);