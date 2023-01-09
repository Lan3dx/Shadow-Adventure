#include "../../include/windows/menu.h"
#include "../../include/sys/includes.h"

void render(std::vector<int> selected) // menu rendering
{
	std::string wall = "";
	for (int i = 0; i < 105; i++)
	{
		wall += ".";
	}
	std::cout << wall << std::endl;
	wall = "";
	for (int j = 0; j < 51; j++)
	{
		if (j == 2)
		{
			std::cout << ".			 	 ||||  ||  ||  ||||  |||||   ||||  ||   ||                              ." << std::endl;
			continue;
		}
		if (j == 3)
		{
			std::cout << ".			        ||     ||  || ||  || ||  || ||  || ||   ||                              ." << std::endl;
			continue;
		}
		if (j == 4)
		{
			std::cout << ".				 ||||  |||||| |||||| ||  || ||  || || | ||                              ." << std::endl;
			continue;
		}
		if (j == 5)
		{
			std::cout << ".		                    || ||  || ||  || ||  || ||  || |||||||                              ." << std::endl;
			continue;
		}
		if (j == 6)
		{
			std::cout << ".	                         ||||  ||  || ||  || |||||   ||||   || ||                               ." << std::endl;
			continue;
		}
		if (j == 9)
		{
			std::cout << ".		        ||||  |||||  ||  || ||||| ||  || |||||| ||  || |||||  ||||                      ." << std::endl;
			continue;
		}
		if (j == 10)
		{
			std::cout << ".		       ||  || ||  || ||  || ||    ||| ||   ||   ||  || ||  || ||                        ." << std::endl;
			continue;
		}
		if (j == 11)
		{
			std::cout << ".		       |||||| ||  || ||  || ||||  || |||   ||   ||  || |||||  ||||                      ." << std::endl;
			continue;
		}
		if (j == 12)
		{
			std::cout << ".		       ||  || ||  ||  ||||  ||    ||  ||   ||   ||  || ||  || ||                        ." << std::endl;
			continue;
		}
		if (j == 13)
		{
			std::cout << ".		       ||  || |||||    ||   ||||| ||  ||   ||    ||||  ||  || ||||                      ." << std::endl;
			continue;
		}
		if (j == 49)
		{
			std::cout << ".                                                L A N 3                                                ." << std::endl;
			continue;
		}
		if (j == 50)
		{
			std::cout << ".                                           2 0 2 2 - 2 0 2 3                                           ." << std::endl;
			continue;
		}

		if (j == 24)
		{
			if (selected[0] == 1)
			{
				std::cout << ".                - - >  G A M E                                                                         ." << std::endl;
			}
			else
			{
				std::cout << ".                       G A M E                                                                         ." << std::endl;
			}
			continue;
		}
		if (j == 26)
		{
			if (selected[1] == 1)
			{
				std::cout << ".                - - >  M A P   C H A N G E R                                                           ." << std::endl;
			}
			else
			{
				std::cout << ".                       M A P   C H A N G E R                                                           ." << std::endl;
			}
			continue;
		}
		if (j == 28)
		{
			if (selected[2] == 1)
			{
				std::cout << ".                - - >  A U T H O R                                                                     ." << std::endl;
			}
			else
			{
				std::cout << ".                       A U T H O R                                                                     ." << std::endl;
			}
			continue;
		}
		if (j == 30)
		{
			if (selected[3] == 1)
			{
				std::cout << ".                - - >  E X I T                                                                         ." << std::endl;
			}
			else
			{
				std::cout << ".                       E X I T                                                                         ." << std::endl;
			}
			continue;
		}

		for (int i = 0; i < 105; i++)
		{
			if (i == 0 || i == 104)
			{
				wall += ".";
			}
			else
			{
				wall += " ";
			}
		}
		std::cout << wall << std::endl;
		wall = "";
	}
	wall = "";
	for (int i = 0; i < 105; i++)
	{
		wall += ".";
	}
	std::cout << wall << std::endl;
	wall = "";
}

int menu() // open menu window
{
	clear();
	for (int i = 0; i < 60; i++) // clear screen
	{
		std::string line;
		for (int j = 0; j < 60; j++)
		{
			line += "  ";
		}
		std::cout << line << '\n';
	}
	std::vector<int> selected = { 1,0,0,0 };
	int key_cd = 40;
	PlaySound(music::MENU, NULL, SND_FILENAME | SND_ASYNC);
	while (true)
	{
		if (key_cd != 0)
		{
			key_cd -= 1;
		}
		if (GetAsyncKeyState((unsigned short)VK_RETURN))
		{
			if (key_cd <= 0)
			{
				key_cd = 40;
				system("cls");
				if (selected[0] == 1) { return 0; }
				else if (selected[1] == 1) { return 1; }
				else if (selected[2] == 1) { return 2; }
				else if (selected[3] == 1) { exit(0); }
			}
		}
		if (GetAsyncKeyState((unsigned short)'W'))
		{
			if (key_cd <= 0)
			{
				key_cd = 40;
				if (selected[0] == 1) { continue; }
				if (selected[1] == 1) { selected[1] = 0; selected[0] = 1; continue; }
				if (selected[2] == 1) { selected[2] = 0; selected[1] = 1; continue; }
				if (selected[3] == 1) { selected[3] = 0; selected[2] = 1; continue; }
			}
		}
		if (GetAsyncKeyState((unsigned short)'S'))
		{
			if (key_cd <= 0)
			{
				key_cd = 40;
				if (selected[3] == 1) { continue; }
				if (selected[2] == 1) { selected[2] = 0; selected[3] = 1; continue; }
				if (selected[1] == 1) { selected[1] = 0; selected[2] = 1; continue; }
				if (selected[0] == 1) { selected[0] = 0; selected[1] = 1; continue; }
			}
		}
		render(selected);

		clear();
	}
	return 0;
}