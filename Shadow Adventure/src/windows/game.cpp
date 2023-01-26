#include "../../include/windows/game.h"
#include "../../include/sys/includes.h"
#include "../../include/sys/constants.h"
#include "../../include/windows/transition.h"

void render(std::vector<std::vector<block>>& map, std::string selected, float fps) // output
{
	std::cout << "    FPS: " << round(int(1.0f / fps)) << " | SELECTED: " << selected << "                       " << std::endl; // selected player
	for (int y = 1; y < map.size()-1; y++) // columns
	{
		std::cout << ' ';
		std::string line;
		for (int x = 1; x < map[y].size()-1; x++) // lines
		{
			line += map[y][x].character;
			line += " ";
			if (y == 5 && x == map[y].size()-2) line += "W - jump";
			if (y == 6 && x == map[y].size() - 2) line += "S - down";
			if (y == 7 && x == map[y].size() - 2) line += "A - left";
			if (y == 8 && x == map[y].size() - 2) line += "D - right";
			if (y == 10 && x == map[y].size() - 2) line += "R - spawn";
			if (y == 11 && x == map[y].size() - 2) line += "K - kill";
			if (y == 12 && x == map[y].size() - 2) line += "C - change";
			if (y == 13 && x == map[y].size() - 2) line += "Q/E - shoot";
			if (y == 15 && x == map[y].size() - 2) line += "ESC - exit";
		}
		std::cout << line;
		std::cout << '\n'; // next column
	}
}

int game() // Game
{
	auto g_board = map_init();
	auto tp1 = std::chrono::system_clock::now(); // Get now time
	auto tp2 = std::chrono::system_clock::now();
	auto shot_cd = SHOT_CD; // Cooldown for shot
	auto key_cd = KEY_CD;
	auto fps_cd = FPS_CD;
	auto mob_shot_cd = 120;
	auto avgfps = 0;
	auto avgfpscount = 0;
	auto fps = 1.0f; // frame per second
	PMAP players; // players map
	MMAP mobs; // mobs map
	std::string selected; // active player
	std::vector<std::vector<block>> board = g_board;  // Define board
	PlaySound(music::MAIN, NULL, SND_FILENAME | SND_ASYNC);

	MOB mob1(std::vector<int>{ 25, 26, 25, 26  }, std::vector<int>{ 6, 6, 5, 5 }, 'M', true,true, 'd', { 14,28,14 });
	MOB mob2(std::vector<int>{ 20, 21, 20, 21  }, std::vector<int>{ 40, 40, 39, 39 }, 'O', false, false, 'd', { 14,28,14 });
	mobs.add("rock", mob1);
	mobs.add("gun", mob2);

	clog("INFO", "Game started");
	while (true) // main program loop
	{
		tp2 = std::chrono::system_clock::now(); // get elapsed time for FPS
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();
		if (fps_cd <= 0)
		{
			avgfps += int(round(int(1.0f / fps)));
			avgfpscount += 1;
			fps = fElapsedTime;
			fps_cd = FPS_CD;
		}

		if (GetAsyncKeyState((unsigned short)VK_ESCAPE))
		{
			clog("INFO", "Game stopped");
			clog("DEBUG", "Avg FPS: " + std::to_string((avgfps / avgfpscount))); 
			return 0;
		}
		if (GetAsyncKeyState((unsigned short)'W') || GetAsyncKeyState((unsigned short)VK_UP))
		{
			control(&players, selected, std::ref(board), std::ref(g_board), 72);
		}
		if (GetAsyncKeyState((unsigned short)'A') || GetAsyncKeyState((unsigned short)VK_LEFT))
		{
			control(&players, selected, std::ref(board), std::ref(g_board), 75);
		}
		if (GetAsyncKeyState((unsigned short)'S') || GetAsyncKeyState((unsigned short)VK_DOWN))
		{
			control(&players, selected, std::ref(board), std::ref(g_board), 80);
		}
		if (GetAsyncKeyState((unsigned short)'D') || GetAsyncKeyState((unsigned short)VK_RIGHT))
		{
			control(&players, selected, std::ref(board), std::ref(g_board), 77);
		}
		if (GetAsyncKeyState((unsigned short)'R'))
		{
			if (!(key_cd > 0))
			{
				for (int b = 0; b < MAX_PLAYERS; b++)
				{
					if (!players.get().contains("player" + std::to_string(b)))
					{
						clog("INFO", "Spawn entity: player" + std::to_string(b));
						PLAYER player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, '>', true, 'd', { 14,28,14 });
						players.add("player" + std::to_string(b), player);
						break;
					}
				}
				key_cd = KEY_CD;
			}
		}
		if (GetAsyncKeyState((unsigned short)'K'))
		{
			if (!(key_cd > 0))
			{
				clog("INFO", "Kill entity: " + selected);
				PlaySound(music::DEATH, NULL, SND_FILENAME | SND_ASYNC);
				players.rem(selected);
				board = g_board;
				change(&selected);
				key_cd = KEY_CD;
			}
		}
		if (GetAsyncKeyState((unsigned short)'E'))
		{
			if (players.get().contains(selected))
			{
				if (shot_cd <= 0)
				{
					PLAYER pl = players.find(selected);
					pl.shoot('r');
					players.rem(selected);
					players.add(selected, pl);
					shot_cd = SHOT_CD;
				}
			}
		}
		if (GetAsyncKeyState((unsigned short)'Q'))
		{
			if (players.get().contains(selected))
			{
				if (shot_cd <= 0)
				{
					PLAYER pl = players.find(selected);
					pl.shoot('l');
					players.rem(selected);
					players.add(selected, pl);
					shot_cd = SHOT_CD;
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
		listenerM(&mobs, std::ref(board), &mob_shot_cd);

		gravitationP(&players, std::ref(board), std::ref(g_board));
		gravitationB(&players, &mobs, std::ref(board), std::ref(g_board));
		gravitationM(&mobs, std::ref(board), std::ref(g_board));

		cdSet(&players, &mobs, &shot_cd, &key_cd, &fps_cd, &mob_shot_cd); // -1 cooldown for all entities

		clear(); // clear screen

		entitiesRender(players, mobs, std::ref(board), std::ref(g_board)); // output all entitis
		render(std::ref(board), selected, fps); // screen output 
	}

	return 0;
}