#include "include/sys/includes.h"
#include "include/sys/constants.h"

int main()
{
	std_config(); // Customizes the console window

	auto board = board_init();  // Define board
	auto shot_cd = SHOT_CD; // Cooldown for shot

	PMAP players; // players map
	BMAP bullets; // bullets map
	MMAP mobs; // mobs map

	while (true) // Main program loop
	{
		if (GetAsyncKeyState((unsigned short)'W')) 
		{ 
			control (&players, "player", std::ref(board), 72);
		}
		if (GetAsyncKeyState((unsigned short)'A')) 
		{ 
			control(&players, "player", std::ref(board), 75);
		}
		if (GetAsyncKeyState((unsigned short)'S')) 
		{
			control(&players, "player", std::ref(board), 80);
		}
		if (GetAsyncKeyState((unsigned short)'D'))
		{
			control(&players, "player", std::ref(board), 77);
		}
		if (GetAsyncKeyState((unsigned short)'R'))
		{
			players.rem("player");
			PLAYER player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, 'P', true, 'd', {2,7,2});
			players.add("player", player);
		}
		if (GetAsyncKeyState((unsigned short)'K')) 
		{ 
			players.rem("player"); 
			bullets.set({}); 
			board = board_init(); 
		}
		if (GetAsyncKeyState((unsigned short)'E'))
		{
			if (players.get().contains("player"))
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
								BULLET bullet(players.find("player").getX()[0], players.find("player").getY()[0] + 1, 'B', true, 'r', { 1,10 });
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
							BULLET bullet(players.find("player").getX()[0], players.find("player").getY()[0] + 1, 'B', true, 'r', { 1,10 });
							bullets.add("bullet" + std::to_string(b), bullet);
							break;
						}
					}
				}
			}
		}
		if (GetAsyncKeyState((unsigned short)'Q'))
		{
			if (players.get().contains("player"))
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
								BULLET bullet(players.find("player").getX()[0], players.find("player").getY()[0] - 1, 'B', true, 'l', { 1,10 });
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
							BULLET bullet(players.find("player").getX()[0], players.find("player").getY()[0] - 1, 'B', true, 'l', { 1,10 });
							bullets.add("bullet" + std::to_string(b), bullet);
							break;
						}
					}
				}
			}
		}
		if (GetAsyncKeyState((unsigned short)'J'))
		{
			players.rem("mob");
			PLAYER mob(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, 'M', true, 'd', { 2,7,2 });
			players.add("mob", mob);
		}

		gravitationP(&players, std::ref(board));
		gravitationB(&bullets, std::ref(board));
		gravitationM(&mobs, std::ref(board));

		clear(); // clear screen
		cdSet(&players, &bullets, &mobs, &shot_cd); // -1 cooldown for all entities
		entitiesRender(players, bullets, mobs, std::ref(board)); // output all entitis
		render(board); // screen output
	}

	return 0;

}