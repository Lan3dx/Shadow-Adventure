#include "include/sys/includes.h"
#include "include/sys/constants.h"
#include "include/windows/game.h"
#include "include/windows/menu.h"
#include "include/windows/mapchanger.h"
#include "include/windows/transition.h"

#pragma comment (lib, "winmm.lib")

bool game_status = true; // is started game or not

int main()
{
	std_config(); // Customizes the console window

	while (game_status) // program loop
	{
		int status = menu(); // launch menu form
		if (status == 0) game(); // if menu form return 0 then start game
		else if (status == 1) mapchanger(); // if menu form return 1 then start mapchanger
	}

	return 0;
}