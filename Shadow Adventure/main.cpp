#include "include/sys/includes.h"
#include "include/sys/constants.h"

int main()
{
	std_config(); // Customizes the console window

	auto board = board_init();  // Define board
	int cooldown = 0;

	PMAP players;
	BMAP bullets; 

	while (true) // Main program loop
	{
		if (GetAsyncKeyState((unsigned short)'W')) { auto afunc = std::async(control, std::ref(players), "player", std::ref(board), 72); players.set(afunc.get()); }
		if (GetAsyncKeyState((unsigned short)'A')) { if (cooldown == 0) { cooldown = 2; auto afunc = std::async(control, std::ref(players), "player", std::ref(board), 75); players.set(afunc.get()); } }
		if (GetAsyncKeyState((unsigned short)'S')) { auto afunc = std::async(control, std::ref(players), "player", std::ref(board), 80); players.set(afunc.get()); }
		if (GetAsyncKeyState((unsigned short)'D')) { if (cooldown == 0) { cooldown = 2; auto afunc = std::async(control, std::ref(players), "player", std::ref(board), 77); players.set(afunc.get()); } }
		if (GetAsyncKeyState((unsigned short)'R')) { players.rem("player"); PLAYER player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, 'P', true, 'd'); players.add("player", player); }
		if (GetAsyncKeyState((unsigned short)'K')) { players.rem("player"); bullets.set({}); board = board_init(); }
		if (GetAsyncKeyState((unsigned short)'E'))
		{
			if (players.get().contains("player"))
			{
				for (int b = 0; b < MAX_AMMO; b++)
				{
					if (!bullets.get().contains("bullet" + std::to_string(b)))
					{
						BULLET bullet(players.find("player").getX()[0], players.find("player").getY()[0] + 1, 'B', true, 'r');
						bullets.add("bullet" + std::to_string(b), bullet);
						break;
					}
				}
			}
		}
		if (GetAsyncKeyState((unsigned short)'Q'))
		{
			if (players.get().contains("player"))
			{
				for (int b = 0; b < MAX_AMMO; b++)
				{
					if (!bullets.get().contains("bullet" + std::to_string(b)))
					{
						BULLET bullet(players.find("player").getX()[0], players.find("player").getY()[0] - 1, 'B', true, 'l');
						bullets.add("bullet" + std::to_string(b), bullet);
						break;
					}
				}
			}
		}

		auto a_bulletG = std::async(gravitationB, std::ref(bullets), std::ref(board));
		bullets.set(a_bulletG.get());

		auto a_playerG = std::async(gravitationP, std::ref(players), std::ref(board));
		players.set(a_playerG.get());

		if (cooldown > 0)
			cooldown -= 1;

		entitiesRender(players, bullets, std::ref(board));
		clear(); // clear screen
		render(board); // screen output
	}

	return 0;
}