#include "../../include/windows/gamesetup.h"
#include "../../include/sys/includes.h"
#include "../../include/windows/game.h"

void Render() // menu rendering
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
		if (j == 20)
		{
			std::cout << ".                                                W A I T                                                ." << std::endl;
			continue;
		}
		if (j == 24)
		{
			std::cout << ".                                        O P T I M I Z A T I O N                                        ." << std::endl;
			continue;
		}
		if (j == 26)
		{
			std::cout << ".                                     F O R   Y O U R   D E V I C E                                     ." << std::endl;
			continue;
		}
		if (j == 50)
		{
			std::cout << ".                                           2 0 2 2 - 2 0 2 3                                           ." << std::endl;
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

double gamesetup() // open author window
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


	Render();
	double fpsms = game(1, 5.0);


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

	return fpsms;
}