#include "../include/control.h"

std::vector<Entity> control(std::vector<Entity> entity, std::vector<std::vector<char>>& board, int key)
{
	for (int i = 0; i < entity.size(); i++)
	{
		if (!entity[i].collisions(board, key)) // if there are no walls near the player
		{
			board = entity[i].kill(board); // kill a character on the map
			board = board_init(); // clear board

			if (key == 72) // jump
			{
				if (entity[i].voidUnder(board))
				{
					if (entity[i].ladder(board)) // if the player is on the ladder, then raise him by 1 element
					{
						entity[i].move('u', board);
						Sleep(60);
					}
					else // else by 3 elements
					{
						for (int j = 0; j < 3; j++)
						{
							entity[i].move('u', board);
						}
					}
				}
			}
			else if (key == 80) { entity[i].move('d', board); } // down
			else if (key == 75) { entity[i].move('l', board); } // Left
			else if (key == 77) { entity[i].move('r', board); } // Right
			Sleep(10);
			board = entity[i].spawn(board); // spawn a character on the map
		}
	}

	return entity;
}