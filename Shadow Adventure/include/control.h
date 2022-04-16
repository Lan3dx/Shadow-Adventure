#pragma once

#include <vector>
#include <Windows.h>

#include "entity.h"
#include "map.h"

std::vector<Entity> control(std::vector<Entity> entity, std::vector<std::vector<char>>& board, int key);