#include "include/sys/includes.h"
#include "include/sys/constants.h"

#include "include/windows/game.h"
#include "include/windows/menu.h"
#include "include/windows/author.h"
#include "include/windows/mapdrawer.h"
#include "include/windows/mapchanger.h"
#include "include/windows/transition.h"
#include "include/windows/gamesetup.h"

bool game_status = true; // is started game or not

double gameDataCheck() 
{
	std::map<std::string, std::map<std::string, std::string>> iniData = parseIniFile("settings/settings.ini");
	for (const auto& section : iniData)
	{
		for (const auto& entry : section.second)
		{
			if (section.first == "main")
			{
				if (entry.first == "first_launched")
				{
					if (entry.second == "1")
					{
						double FPSms = gamesetup();
						iniData["main"]["FPSms"] = std::to_string(FPSms);
						iniData["main"]["first_launched"] = "0";
						writeIniFile(iniData, "settings/settings.ini");
					}
				}
				else if (entry.first == "already_started")
				{
					if (stoi(entry.second) >= 3) 
					{
						double FPSms = gamesetup();
						iniData["main"]["FPSms"] = std::to_string(FPSms);
						iniData["main"]["already_started"] = "0";
						writeIniFile(iniData, "settings/settings.ini");
					}
					else 
					{
						iniData["main"]["already_started"] = std::to_string(stoi(entry.second) + 1);
						writeIniFile(iniData, "settings/settings.ini");
					}
				}
			}
		}
	}
	for (const auto& section : iniData)
	{
		for (const auto& entry : section.second)
		{
			if (section.first == "main")
			{
				if (entry.first == "FPSms")
				{
					return std::stod(entry.second);
				}
			}
		}
	}
	return 5.0;
}

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
			double FPSms = gameDataCheck();
			game(0, FPSms);
		}
		else if (status == 1) mapdrawer(); // if menu form return 1 then start mapchanger
		else if (status == 2) author();  // if menu form return 2 then open author window
		else if (status == 3) game_status = false; // if menu form return 3 then end game
	}

	return 0;
}