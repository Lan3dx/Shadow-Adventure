#include "include/sys/includes.h"
#include "include/sys/constants.h"
#include "include/windows/game.h"
#include "include/windows/menu.h"

#pragma comment (lib, "winmm.lib")

int main()
{
	std_config(); // Customizes the console window

	while (true) // program loop
	{
		int status = menu(); // launch menu form
		if (status == 0) game(); // if menu form return 0 then start game
	}

	return 0;
}