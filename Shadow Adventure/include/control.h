#pragma once

#include <vector>
#include <Windows.h>
#include <map>
#include <string>

#include "sys/constants.h"
#include "entities/player.h"
#include "entities/mob.h"
#include "map.h"

std::string control(PMAP*, std::string, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&, int, PlayerFrame*, Corners*);