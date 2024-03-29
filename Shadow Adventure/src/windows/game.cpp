#include "../../include/windows/game.h"
#include "../../include/sys/includes.h"
#include "../../include/sys/constants.h"
#include "../../include/windows/transition.h"

void render(std::vector<std::vector<block>>& map, std::string selected, double fps, Corners corners, int hp, std::vector<animation>& animations, int mode) // output
{
	int y1 = 1;
	int x1 = 1;
	if (mode != 1) {
		std::cout << "    FPS: " << round(int(1.0 / fps)) << " | SELECTED: " << selected << " | HP: " << hp << "                       " << std::endl; // selected player
	}
	std::string s = "";
	for (size_t i = 0; i < 48; i++)
	{
		s += ". ";
	}
	for (size_t g = 0; g < animations.size(); g++)
	{
		animations[g].counter = 0;
	}
	if (mode != 1) {
		std::cout << s << '\n';
	}
	for (int y = corners.up; y < corners.up + 48 - 1; y++) // columns
	{
		std::string line;
		x1 = 1;
		for (int x = corners.left; x < corners.left + 48 - 1; x++) // lines
		{
			if ((x1 < 5 && map[y][x].character == '#') || (y1 < 5 && map[y][x].character == '#')) 
			{
				line += '"';
			}
			else if ((x1 > 43 && map[y][x].character == '#') || (y1 > 43 && map[y][x].character == '#')) 
			{
				line += '"';
			}
			else 
			{ 
				line += map[y][x].character; 
			}
			if (y1 == 5 && x1 == 48 - 1) line += "W - jump";
			if (y1 == 6 && x1 == 48 - 1) line += "S - down";
			if (y1 == 7 && x1 == 48 - 1) line += "A - left";
			if (y1 == 8 && x1 == 48 - 1) line += "D - right";
			if (y1 == 10 && x1 == 48 - 1) line += "R - spawn";
			if (y1 == 11 && x1 == 48 - 1) line += "K - kill";
			if (y1 == 12 && x1 == 48 - 1) line += "C - change";
			if (y1 == 13 && x1 == 48 - 1) line += "Q/E - shoot";
			if (y1 == 15 && x1 == 48 - 1) line += "ESC - exit";
			x1 += 1;
			bool isspaced = false;
			if (animations.size() != 0)
			{
				for (size_t g = 0; g < animations.size(); g++)
				{
					bool iscord = false;
					for (size_t v = 0; v < animations.size(); v++)
					{
						if (v != g)
						{
							if (animations[v].X == animations[g].X)
							{
								if (animations[v].Y == animations[g].Y)
								{
									iscord = true;
									break;
								}
							}
						}
					}
					if (!iscord)
					{
						if (animations[g].X == y)
						{
							if (animations[g].Y == x - animations[g].counter)
							{
								if (animations[g].counter < animations[g].Text.length())
								{
									line += animations[g].Text[animations[g].counter];
									animations[g].counter += 1;
									continue;
								}
								else
								{
									if (!isspaced) {
										line += " ";
										isspaced = true;
									}
								}
							}
							else
							{
								if (!isspaced) {
									line += " ";
									isspaced = true;
								}
							}
						}
						else
						{
							if (!isspaced) {
								line += " ";
								isspaced = true;
							}
						}
					}
					else
					{
						if (!isspaced) {
							line += " ";
							isspaced = true;
						}
					}
				}
			}
			else
			{
				if (!isspaced) {
					line += " ";
					isspaced = true;
				}
			}
		}
		y1 += 1;
		if (mode != 1) {
			std::cout << line;
			std::cout << '\n'; // next column
		}
	}
	s = "";
	for (size_t i = 0; i < 48; i++)
	{
		s += ". ";
	}
	if (mode != 1) {
		std::cout << s << '\n';
	}
}

// mode:
// 0 - default
// 1 - optimization for device
double game(int mode, double sleep_fps) // Game
{
	Sounds* snds = new Sounds();
	auto g_board = map_init();
	std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
	std::chrono::system_clock::time_point b = std::chrono::system_clock::now();
	auto shot_cd = SHOT_CD; // Cooldown for shot
	auto key_cd = KEY_CD;
	auto fps_cd = FPS_CD;
	auto mob_shot_cd = 90;
	auto avgfps = 0;
	auto avgfpscount = 0;
	auto selectedhp = 0;
	auto fallh = 0;
	double fps = 1; // frame per second
	double fpsms = 0.05;
	int modeiterations = 0;
	PMAP players; // players map
	MMAP mobs; // mobs map
	std::vector<animation> animations; // all animations
	std::string selected; // active player
	std::vector<std::vector<block>> board = g_board;  // Define board
	Corners corners{ 5, 5, 50 };
	PlayerFrame pframe{ 0, 0, 6, true };

	if (mode != 1) {
		snds->play("main");
		snds->update();
	}

	// MOB args
	//	1 arg - X cords
	//	2 arg - Y cords
	//	3 arg - mob's symbol
	//	4 arg - gravity (t/f)
	//	5 arg - mobile (t/f)
	//	6 arg - gravity type (up(u)/down(d)/left(l)/right(r))
	//	7 arg - cooldowns (AD keys cd, WS keys cd, gravity cd)
	//  8 arg - health points
	//
	//	Have fun ;D

	MOB mob1(std::vector<int>{ 25, 26, 25, 26  }, std::vector<int>{ 6, 6, 5, 5 }, 'M', true, true, 'd', { 5,10,5 }, 10);
	MOB mob2(std::vector<int>{ 20, 21, 20, 21  }, std::vector<int>{ 40, 40, 39, 39 }, 'O', true, true, 'd', { 5,10,5 }, 10);
	mobs.add("rock", mob1);
	mobs.add("gun", mob2); // if name is "gun" then mob can shoot

	std::string s = "null";
	std::string s1 = "null";

	if (mode != 1) {
		clog("INFO", "Game started");
	}
	else {
		clog("INFO", "----------------------------------");
		clog("INFO", "Optimization for the device");
	}
	while (true) // main program loop
	{
		a = std::chrono::system_clock::now();
		std::chrono::duration<double> work_time = a - b;
		if (mode == 0) {
			if (work_time.count() < 5)
			{
				std::chrono::duration<double, std::milli> delta_ms(sleep_fps - work_time.count());
				auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
				std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
			}
		}
		else {
			if (work_time.count() < 5)
			{
				std::chrono::duration<double, std::milli> delta_ms(fpsms - work_time.count());
				auto delta_ms_duration = std::chrono::duration_cast<std::chrono::milliseconds>(delta_ms);
				std::this_thread::sleep_for(std::chrono::milliseconds(delta_ms_duration.count()));
			}
		}

		b = std::chrono::system_clock::now();
		std::chrono::duration<double> sleep_time = b - a;

		if (fps_cd <= 0)
		{
			avgfps += int(round(int(1.0f / fps)));
			avgfpscount += 1;
			fps = (work_time + sleep_time).count();
			fps_cd = FPS_CD;
		}

		if (mode == 0) {
			if (GetAsyncKeyState((unsigned short)VK_ESCAPE))
			{
				clog("INFO", "Game stopped");
				clog("DEBUG", "Avg FPS: " + std::to_string((avgfps / avgfpscount)));
				snds->~Sounds();
				return 0;
			}
			if (GetAsyncKeyState((unsigned short)'W') || GetAsyncKeyState((unsigned short)VK_UP))
			{
				s = control(&players, selected, std::ref(board), std::ref(g_board), 72, &pframe, &corners);
			}
			if (GetAsyncKeyState((unsigned short)'A') || GetAsyncKeyState((unsigned short)VK_LEFT))
			{
				auto s = control(&players, selected, std::ref(board), std::ref(g_board), 75, &pframe, &corners);
			}
			if (GetAsyncKeyState((unsigned short)'S') || GetAsyncKeyState((unsigned short)VK_DOWN))
			{
				s = control(&players, selected, std::ref(board), std::ref(g_board), 80, &pframe, &corners);
			}
			if (GetAsyncKeyState((unsigned short)'D') || GetAsyncKeyState((unsigned short)VK_RIGHT))
			{
				control(&players, selected, std::ref(board), std::ref(g_board), 77, &pframe, &corners);
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
							PLAYER player(std::vector<int>{ 39, 40, 41 }, std::vector<int>{ 5, 5, 5 }, '>', true, 'd', { 5,10,5 }, 10);
							players.add("player" + std::to_string(b), player);
							pframe.x = 5;
							pframe.y = 40;
							pframe.ischanged = true;
							corners.lt = 50;
							change(&players, &selected);
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
					snds->play("death");
					players.rem(selected);
					board = g_board;
					change(&selected);
					if ((players.get().size() != 0) && selected != "")
					{
						pframe.x = players.find(selected).getY()[1];
						pframe.y = players.find(selected).getX()[1];
						pframe.ischanged = true;
						corners.lt = 50;
					}
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
						snds->play("shot");
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
						snds->play("shot");
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
					snds->play("change");
					change(&players, &selected);
					if ((players.get().size() != 0) && selected != "")
					{
						pframe.x = players.find(selected).getY()[1];
						pframe.y = players.find(selected).getX()[1];
						pframe.ischanged = true;
						corners.lt = 50;
					}
					key_cd = KEY_CD;
				}
			}
		}

		// entities listeners
		s1 = listenerP(&players, std::ref(board), selected, &pframe, &corners);
		if (s1 == "death") { snds->play("death"); s1 = "null"; } else if (s1 == "boost") { snds->play("boost"); s1 = "null"; }
		s1 = listenerM(&mobs, std::ref(board), &mob_shot_cd);
		if (s1 == "death") { snds->play("death"); s1 = "null"; } else if (s1 == "boost") { snds->play("boost"); s1 = "null"; }

		// entities gravitation
		s1 = gravitationP(&players, std::ref(board), std::ref(g_board), selected, &pframe, &corners);
		if (s1 == "death") { snds->play("death"); s1 = "null"; } 
		s1 = gravitationB(&players, &mobs, std::ref(board), std::ref(g_board)); 
		if (s1 == "death") { snds->play("death"); s1 = "null"; } 
		s1 = gravitationM(&mobs, std::ref(board), std::ref(g_board)); 
		if (s1 == "death") { snds->play("death"); s1 = "null"; } 

		// damage listener
		s1 = listenerD(&players, &mobs, std::ref(board), std::ref(animations));
		if (s1 == "death") { snds->play("death"); s1 = "null"; }

		listenerA(std::ref(animations)); // animation listener

		if ((players.get().size() != 0) && selected != "")
		{
			selectedhp = players.find(selected).getHP();
			fallh = players.find(selected).getFL();
		}

		cdSet(&players, &mobs, &shot_cd, &key_cd, &fps_cd, &mob_shot_cd); // -1 cooldown for all entities

		clear(); // clear screen

		cornerListener(players,selected,board,&corners, &pframe); // move camera to player
		entitiesRender(players, mobs, std::ref(board), std::ref(g_board)); // output all entitis
		render(std::ref(board), selected, fps, corners, selectedhp, std::ref(animations), mode); // screen output 

		if (s == "jump") {
			snds->play("jump");
			s = "null";
		}
		else if (s == "ladder") {
			snds->play("ladder");
			s = "null";
		}
		else if (s == "death") {
			snds->play("death");
			s = "null";
		}
		else if (s == "water") {
			snds->play("water");
			s = "null";
		}

		snds->update();

		if (mode == 1) {
			if ((round(int(1.0 / fps)) >= 70) && (round(int(1.0 / fps)) <= 80)) {
				modeiterations += 1;
				if (modeiterations == 10) {
					clog("INFO", "Successfully optimized!");
					clog("INFO", "The FPSms value is set to: " + std::to_string(fpsms));
					clog("INFO", "----------------------------------");
					snds->~Sounds();
					return fpsms;
				}
			}
			else {
				fpsms += 0.01;
				modeiterations = 0;
			}
		}
	}

	return 0;
}