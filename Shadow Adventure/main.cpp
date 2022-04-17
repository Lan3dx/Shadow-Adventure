// Importing threads and vectors
#include <vector>
#include <map>
#include <iostream>
#include <windows.h>
#include <WinUser.h>

// Header Files
#include "include/config.h"
#include "include/map.h"
#include "include/entity.h"
#include "include/control.h"
#include "include/gravity.h"
#include "include/spawn.h"

int main()
{
	std_config(); // Customizes the console window

	auto board = board_init();  // Define board
	Entity player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, 'P', true, 'd'); // Player Creation
	EntityMap entMap;
	entMap.add("player", player);

	while (true) // Main program loop
	{
		if (GetAsyncKeyState((unsigned short)'W')) entMap.add("player", control(entMap.find("player"), std::ref(board), 72));
		if (GetAsyncKeyState((unsigned short)'A')) entMap.add("player", control(entMap.find("player"), std::ref(board), 75));
		if (GetAsyncKeyState((unsigned short)'S')) entMap.add("player", control(entMap.find("player"), std::ref(board), 80));
		if (GetAsyncKeyState((unsigned short)'D')) entMap.add("player", control(entMap.find("player"), std::ref(board), 77));
		if (GetAsyncKeyState((unsigned short)'R')) { entMap.rem("player"); entMap.add("player", control(entMap.find("player"), std::ref(board), 0)); }
		if (GetAsyncKeyState((unsigned short)'K')) { entMap.rem("player"); board = board_init(); }

		entMap.set(animatedDrop(std::ref(entMap),std::ref(board)));
		clear(); // clear screen
		render(board); // screen output
	}

	return 0;
}