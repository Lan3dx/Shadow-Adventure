#include "../../include/windows/game.h"
#include "../../include/sys/includes.h"
#include "../../include/sys/constants.h"

int start()
{
	auto board = board_init();  // Define board
	auto shot_cd = SHOT_CD; // Cooldown for shot
	auto key_cd = KEY_CD;
	auto fps_cd = FPS_CD;
	auto fps = 1.0f; // frame per second
	std::string selected;
	PMAP players; // players map
	BMAP bullets; // bullets map 
	MMAP mobs; // mobs map
	auto tp1 = std::chrono::system_clock::now(); // get now time
	auto tp2 = std::chrono::system_clock::now();
	PlaySound(music::MAIN, NULL, SND_FILENAME | SND_ASYNC);

	while (true) // Main program loop
	{
		tp2 = std::chrono::system_clock::now(); // get elapsed time for FPS
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();
		if (fps_cd <= 0)
		{
			fps = fElapsedTime;
			fps_cd = FPS_CD;
		}

		if (GetAsyncKeyState((unsigned short)'W'))
		{
			control(&players, selected, std::ref(board), 72);
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
						PLAYER player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, 'p', true, 'd', { 14,28,14 });
						players.add("player" + std::to_string(b), player);
						break;
					}
				}
				key_cd = KEY_CD;
			}
		}
		if (GetAsyncKeyState((unsigned short)'K'))
		{
			PlaySound(music::DEATH, NULL, SND_FILENAME | SND_ASYNC);
			players.rem(selected);
			bullets.set({});
			board = board_init();
			change(&selected);
		}
		if (GetAsyncKeyState((unsigned short)'E'))
		{
			if (players.get().contains(selected))
			{
				if (!bullets.get().empty())
				{
					if (shot_cd <= 0)
					{
						PlaySound(music::SHOT, NULL, SND_FILENAME | SND_ASYNC);
						shot_cd = SHOT_CD;
						for (int b = 0; b < MAX_AMMO; b++)
						{
							if (!bullets.get().contains("bullet" + std::to_string(b)))
							{
								BULLET bullet(players.find(selected).getX()[0], players.find(selected).getY()[0] + 1, 'B', true, 'r', { 4,2 });
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
							PlaySound(music::SHOT, NULL, SND_FILENAME | SND_ASYNC);
							BULLET bullet(players.find(selected).getX()[0], players.find(selected).getY()[0] + 1, 'B', true, 'r', { 4,2 });
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
						PlaySound(music::SHOT, NULL, SND_FILENAME | SND_ASYNC);
						shot_cd = SHOT_CD;
						for (int b = 0; b < MAX_AMMO; b++)
						{
							if (!bullets.get().contains("bullet" + std::to_string(b)))
							{
								BULLET bullet(players.find(selected).getX()[0], players.find(selected).getY()[0] - 1, 'B', true, 'l', { 4,2 });
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
							PlaySound(music::SHOT, NULL, SND_FILENAME | SND_ASYNC);
							BULLET bullet(players.find(selected).getX()[0], players.find(selected).getY()[0] - 1, 'B', true, 'l', { 4,2 });
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
				PlaySound(music::CHANGE, NULL, SND_FILENAME | SND_ASYNC);
				change(&players, &selected);
				key_cd = KEY_CD;
			}
		}

		listenerP(&players, std::ref(board));
		listenerB(&bullets, std::ref(board));
		listenerM(&mobs, std::ref(board));

		gravitationP(&players, std::ref(board));
		gravitationB(&bullets, std::ref(board));
		gravitationM(&mobs, std::ref(board));

		cdSet(&players, &bullets, &mobs, &shot_cd, &key_cd, &fps_cd); // -1 cooldown for all entities
		clear(); // clear screen
		entitiesRender(players, bullets, mobs, std::ref(board)); // output all entitis
		render(board, selected, fps); // screen output 
	}

	return 0;
}