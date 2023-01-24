#pragma once
#include <vector>
#include <iostream>
#include "..\player.h"
#include "..\mob.h"
#include "..\bullet.h"
#include "..\..\sys\constants.h"

void entitiesRender(PMAP, MMAP, std::vector<std::vector<block>>&, std::vector<std::vector<block>>&); // render players