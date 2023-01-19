#pragma once

#include <vector>
#include <Windows.h>
#include <map>
#include <string>

#include "sys/musicloader.h"
#include "sys/constants.h"
#include "entities/player.h"
#include "entities/mob.h"
#include "spawn.h"
#include "map.h"

void control(PMAP*, std::string, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&, int);