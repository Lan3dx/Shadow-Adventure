#pragma once

#include <vector>
#include "entity.h"

std::vector<Entity> Respawn(std::vector<Entity>, std::vector<std::vector<char>>&, int);
std::vector<Entity> animatedDrop(std::vector<Entity>, std::vector<std::vector<char>>&, char);