// Importing threads and vectors
#include <vector>
#include <iostream>
#include <windows.h>
#include <WinUser.h>

// Header Files
#include "include/config.h"
#include "include/map.h"
#include "include/entity.h"
#include "include/control.h"
#include "include/spawn.h"

int main()
{
	std_config(); // Customizes the console window

	auto board = board_init();  // Define board
	Entity player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, 'P', true); // Player Creation

	while (true) // Main program loop
	{
		if (GetAsyncKeyState((unsigned short)'W')) control(std::ref(player), std::ref(board), 72);
		if (GetAsyncKeyState((unsigned short)'A')) control(std::ref(player), std::ref(board), 75);
		if (GetAsyncKeyState((unsigned short)'S')) control(std::ref(player), std::ref(board), 80);
		if (GetAsyncKeyState((unsigned short)'D')) control(std::ref(player), std::ref(board), 77);

		animatedDrop(std::ref(player), std::ref(board), 'd');
		clear(); // clear screen
		render(board); // screen output
	}

	return 0;
}