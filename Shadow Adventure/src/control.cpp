#include "../include/control.h"

void control(Entity& entity, std::vector<std::vector<char>>& board, int key)
{
	if (!entity.collisions(board, key)) // if there are no walls near the player
	{
		board = entity.kill(board); // kill a character on the map
		board = board_init(); // clear board

		if (key == 72) // jump
		{
			if (entity.voidUnder(board))
			{
				if (entity.ladder(board)) // if the player is on the ladder, then raise him by 1 element
				{
					entity.move('u', board);
					Sleep(60);
				}
				else // else by 3 elements
				{
					for (int i = 0; i < 3; i++)
					{
						entity.move('u', board);
					}
				}
			}
		}
		else if (key == 80) { entity.move('d', board); } // down
		else if (key == 75) { entity.move('l', board); } // Left
		else if (key == 77) { entity.move('r', board); } // Right
		Sleep(10);
		board = entity.spawn(board); // spawn a character on the map
	}
}