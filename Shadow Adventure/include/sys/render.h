#pragma once
#include <vector>
#include <iostream>
#include "..\map.h"
#include "..\spawn.h"

void render(std::vector<std::vector<char>> map);
void entitiesRender(PMAP, BMAP, std::vector<std::vector<char>>&);