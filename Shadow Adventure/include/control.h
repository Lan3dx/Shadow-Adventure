#pragma once

#include <vector>
#include <Windows.h>
#include <map>
#include <string>

#include "sys/musicloader.h"
#include "entities/player.h"
#include "spawn.h"
#include "map.h"

void control(PMAP*, std::string, std::vector<std::vector<char>>&, std::vector<std::vector<char>>, int); // selected player control func