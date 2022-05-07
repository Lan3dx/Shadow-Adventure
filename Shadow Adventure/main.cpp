#include "include/sys/includes.h"
#include "include/sys/constants.h"

int main()
{
	std_config(); // Customizes the console window

	auto board = board_init();  // Define board
	auto shot_cd = SHOT_CD; // Cooldown for shot
	auto key_cd = KEY_CD;
	std::string selected;

	PMAP players; // players map
	BMAP bullets; // bullets map
	MMAP mobs; // mobs map

	while (true) // Main program loop
	{
		if (GetAsyncKeyState((unsigned short)'W')) 
		{ 
			control (&players, selected, std::ref(board), 72);
		}
		if (GetAsyncKeyState((unsigned short)'A')) 
		{ 
			control(&players, selected, std::ref(board), 75);
		}
		if (GetAsyncKeyState((unsigned short)'S')) 
		{
			control(&players, selected, std::ref(board), 80);
		}
		if (GetAsyncKeyState((unsigned short)'D'))
		{
			control(&players, selected, std::ref(board), 77);
		}
		if (GetAsyncKeyState((unsigned short)'R'))
		{
			if (!(key_cd > 0))
			{
				for (int b = 0; b < 5; b++)
				{
					if (!players.get().contains("player" + std::to_string(b)))
					{
						PLAYER player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, 'P', true, 'd', { 2,7,2 });
						players.add("player" + std::to_string(b), player);
						break;
					}
				}
				key_cd = KEY_CD;
			}
		}
		if (GetAsyncKeyState((unsigned short)'K')) 
		{ 
			players.rem(selected);
			bullets.set({}); 
			board = board_init(); 
		}
		if (GetAsyncKeyState((unsigned short)'E'))
		{
			if (players.get().contains(selected))
			{
				if (!bullets.get().empty())
				{
					if (shot_cd <= 0)
					{
						shot_cd = SHOT_CD;
						for (int b = 0; b < MAX_AMMO; b++)
						{
							if (!bullets.get().contains("bullet" + std::to_string(b)))
							{
								BULLET bullet(players.find(selected).getX()[0], players.find(selected).getY()[0] + 1, 'B', true, 'r', { 1,10 });
								bullets.add("bullet" + std::to_string(b), bullet);
								break;
							}
						}
					}
				}
				else
				{
					shot_cd = SHOT_CD;
					for (int b = 0; b < MAX_AMMO; b++)
					{
						if (!bullets.get().contains("bullet" + std::to_string(b)))
						{
							BULLET bullet(players.find(selected).getX()[0], players.find(selected).getY()[0] + 1, 'B', true, 'r', { 1,10 });
							bullets.add("bullet" + std::to_string(b), bullet);
							break;
						}
					}
				}
			}
		}
		if (GetAsyncKeyState((unsigned short)'Q'))
		{
			if (players.get().contains(selected))
			{
				if (!bullets.get().empty())
				{
					if (shot_cd <= 0)
					{
						shot_cd = SHOT_CD;
						for (int b = 0; b < MAX_AMMO; b++)
						{
							if (!bullets.get().contains("bullet" + std::to_string(b)))
							{
								BULLET bullet(players.find(selected).getX()[0], players.find(selected).getY()[0] - 1, 'B', true, 'l', { 1,10 });
								bullets.add("bullet" + std::to_string(b), bullet);
								break;
							}
						}
					}
				}		
				else
				{
					shot_cd = SHOT_CD;
					for (int b = 0; b < MAX_AMMO; b++)
					{
						if (!bullets.get().contains("bullet" + std::to_string(b)))
						{
							BULLET bullet(players.find(selected).getX()[0], players.find(selected).getY()[0] - 1, 'B', true, 'l', { 1,10 });
							bullets.add("bullet" + std::to_string(b), bullet);
							break;
						}
					}
				}
			}
		}
		if (GetAsyncKeyState((unsigned short)'C'))
		{
			if (!(key_cd > 0))
			{
				change(&players, &selected);
				key_cd = KEY_CD;
			}
		}

		gravitationP(&players, std::ref(board));
		gravitationB(&bullets, std::ref(board));
		gravitationM(&mobs, std::ref(board));

		clear(); // clear screen
		cdSet(&players, &bullets, &mobs, &shot_cd, &key_cd); // -1 cooldown for all entities
		entitiesRender(players, bullets, mobs, std::ref(board)); // output all entitis
		render(board); // screen output
		std::cout << "Selected: " << selected << std::endl; // selected player
	}

	return 0;

}