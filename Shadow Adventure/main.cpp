#include "include/sys/includes.h"
#include "include/sys/constants.h"

#include "include/windows/game.h"
#include "include/windows/menu.h"
#include "include/windows/author.h"
#include "include/windows/mapdrawer.h"
#include "include/windows/mapchanger.h"
#include "include/windows/transition.h"

#pragma comment (lib, "winmm.lib")

bool game_status = true; // is started game or not

int main()
{
	srand(time(NULL));
	std::ios::sync_with_stdio(false);
	std_config(); // Customizes the console window

	while (game_status) // program loop
	{
		int status = menu(); // launch menu form=
		if (status == 0) game(); // if menu form return 0 then start game
		else if (status == 1) mapdrawer(); // if menu form return 1 then start mapchanger
		else if (status == 2) author();  // if menu form return 2 then open author window
	}

	return 0;
}