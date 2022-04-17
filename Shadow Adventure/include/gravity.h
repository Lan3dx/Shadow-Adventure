#pragma once

#include <vector>
#include "entity.h"
#include "spawn.h"

std::map <std::string, Entity> animatedDrop(EntityMap entity, std::vector<std::vector<char>>& board);