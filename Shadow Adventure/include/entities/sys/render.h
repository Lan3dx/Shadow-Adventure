#pragma once
#include <vector>
#include <iostream>
#include "..\..\spawn.h"
#include "..\..\map.h"

void render(std::vector<std::vector<char>> map, std::string, float); // render board
void entitiesRender(PMAP, BMAP, MMAP, std::vector<std::vector<char>>&); // render players