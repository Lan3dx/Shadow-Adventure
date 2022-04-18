#pragma once

#include <vector>
#include "entity.h"
#include "spawn.h"

std::map <std::string, Entity> spawn(std::map <std::string, Entity>  entity, std::vector<std::vector<char>>& board);
std::map <std::string, Entity> gravitation(std::map <std::string, Entity>  entity, std::vector<std::vector<char>>& board);