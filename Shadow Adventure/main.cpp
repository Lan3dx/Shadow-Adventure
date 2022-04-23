#include "include/sys/includes.h"

int main()
{
	std_config(); // Customizes the console window

	auto board = board_init();  // Define board

	PMAP players;
	BMAP bullets;

	while (true) // Main program loop
	{
		
		if (GetAsyncKeyState((unsigned short)'W')) players.set(control(std::ref(players), "player", std::ref(board), 72));
		if (GetAsyncKeyState((unsigned short)'A')) players.set(control(std::ref(players), "player", std::ref(board), 75));
		if (GetAsyncKeyState((unsigned short)'S')) players.set(control(std::ref(players), "player", std::ref(board), 80));
		if (GetAsyncKeyState((unsigned short)'D')) players.set(control(std::ref(players), "player", std::ref(board), 77));
		if (GetAsyncKeyState((unsigned short)'R')) { players.rem("player"); PLAYER player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, 'P', true, 'd'); players.add("player", player); }
		if (GetAsyncKeyState((unsigned short)'K')) { players.rem("player"); board = board_init(); }
		if (GetAsyncKeyState((unsigned short)'Q'))
		{
			if (!bullets.get().contains("bullet"))
			{
				BULLET bullet(players.find("player").getX()[0], players.find("player").getY()[0], 'B', true, 'r');
				bullets.add("bullet", bullet);
			}
		}
		bullets.set(gravitation(std::ref(bullets), std::ref(board)));
		players.set(gravitation(std::ref(players), std::ref(board)));

		//entitiesRender(std::ref(players), std::ref(bullets), std::ref(board));
		clear(); // clear screen
		render(board); // screen output
	}

	return 0;
}