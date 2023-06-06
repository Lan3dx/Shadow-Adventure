#include "include/sys/includes.h"
#include "include/sys/constants.h"

#include "include/windows/game.h"
#include "include/windows/menu.h"
#include "include/windows/author.h"
#include "include/windows/mapdrawer.h"
#include "include/windows/mapchanger.h"
#include "include/windows/transition.h"

bool game_status = true; // is started game or not

int main()
{
	srand((unsigned int)time(NULL));
	std::ios::sync_with_stdio(false);
	screen_config(); // Customizes the console window
	file_config("settings/settings.ini"); // check settings

	while (game_status) // program loop
	{
		int status = menu(); // launch menu form
		if (status == 0) // if menu form return 0 then start game
		{ 
			int gs = game(1, 5.2); 
		}
		else if (status == 1) mapdrawer(); // if menu form return 1 then start mapchanger
		else if (status == 2) author();  // if menu form return 2 then open author window
		else if (status == 3) game_status = false; // if menu form return 3 then end game
	}

	return 0;
}