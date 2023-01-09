#include "../../include/windows/author.h"
#include "../../include/sys/includes.h"

void render() // menu rendering
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
			std::cout << ".                                                C O D E                                                ." << std::endl;
			continue;
		}
		if (j == 21)
		{
			std::cout << ".                               L A N 3 - L A V R U K H I N   N I K I T A                               ." << std::endl;
			continue;
		}
		if (j == 23)
		{
			std::cout << ".                                               M U S I C                                               ." << std::endl;
			continue;
		}
		if (j == 24)
		{
			std::cout << ".                               L A N 3 - L A V R U K H I N   N I K I T A                               ." << std::endl;
			continue;
		}
		if (j == 26)
		{
			std::cout << ".                                              D E S I G N                                              ." << std::endl;
			continue;
		}
		if (j == 27)
		{
			std::cout << ".                               L A N 3 - L A V R U K H I N   N I K I T A                               ." << std::endl;
			continue;
		}
		if (j == 32)
		{
			std::cout << ".                                               G M A I L                                               ." << std::endl;
			continue;
		}
		if (j == 33)
		{
			std::cout << ".                           N I K I T A L A V R U K H I N U K @ G M A I L . C O M                       ." << std::endl;
			continue;
		}
		if (j == 35)
		{
			std::cout << ".                                                  T G                                                  ." << std::endl;
			continue;
		}
		if (j == 36)
		{
			std::cout << ".                                            @ L a n 3 _ T g                                            ." << std::endl;
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

int author() // open author window
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
	int key_cd = 40;

	while (true)
	{
		clear();
		if (key_cd != 0)
		{
			key_cd -= 1;
		}
		if (GetAsyncKeyState((unsigned short)VK_ESCAPE))
		{
			if (key_cd <= 0)
			{
				key_cd = 40;
				return 0;
			}
		}
		render();
	}
	return 0;
}