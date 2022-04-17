#pragma once

#include <vector>
#include <Windows.h>

#include "entity.h"
#include "map.h"

Entity control(Entity entity, std::vector<std::vector<char>>& board, int key);