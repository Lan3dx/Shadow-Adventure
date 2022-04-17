#pragma once

#include <vector>
#include "entity.h"
#include "spawn.h"

std::map <std::string, Entity> animatedDrop(std::map <std::string, Entity>  entity, std::vector<std::vector<char>>& board);