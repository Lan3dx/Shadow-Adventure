#pragma once
#include <vector>
#include <iostream>
#include "..\spawn.h"

void render(std::vector<std::vector<char>> map); // output
void entitiesRender(std::vector<std::vector<char>> map, PMAP);
void entitiesRender(std::vector<std::vector<char>> map, BMAP);
void entitiesRender(std::vector<std::vector<char>> map, PMAP, BMAP);