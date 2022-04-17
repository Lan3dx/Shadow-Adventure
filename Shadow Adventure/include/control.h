#pragma once

#include <vector>
#include <Windows.h>
#include <map>
#include <string>

#include "entity.h"
#include "map.h"

std::map <std::string, Entity> control(std::map <std::string, Entity>, std::vector<std::vector<char>>&, int);