#pragma once
#include <vector>
#include <iostream>
#include "..\map.h"
#include "..\spawn.h"

void render(std::vector<std::vector<char>> map, std::string*); // render board
void entitiesRender(PMAP, BMAP, MMAP, std::vector<std::vector<char>>&); // render players