#include "../include/control.h"
#include <iostream>

std::map < std::string, PLAYER > control(PMAP& players, std::string selected, std::vector<std::vector<char>>& board, int key)
{
	if (players.get().contains(selected))
	{
		std::map < std::string, PLAYER > npm;
		PLAYER player = players.find(selected);

		if (!player.collisions(board, key)) // if there are no walls near the player
		{
			board = player.kill(board); // kill a character on the map

			if (key == 72) // jump
			{
				if (player.voidUnder(board))
				{
					board = board_init();
					if (player.ladder(board)) // if the player is on the ladder, then raise him by 1 element
					{
						player.move('u');
						Sleep(60);
					}
					else // else by 3 elements
					{
						for (int j = 0; j < 3; j++)
						{
							player.move('u');
						}
					}
				}
			}
			else if (key == 80) { player.move('d'); } // down
			else if (key == 75) { player.move('l'); } // Left
			else if (key == 77) { player.move('r'); } // Right

			Sleep(10);
			board = board_init();
			board = player.spawn(board); // spawn a character on the map
			npm.insert(std::make_pair(selected, player));

			return npm;
		}
	}
	return players.get();
}