#include "../include/control.h"
#include <iostream>

void control(PMAP* players, std::string selected, std::vector<std::vector<char>>& board, int key) // control func for selected player
{
	board = board_init(); // board clear
	if (players->get().contains(selected)) // if players map have selected player
	{
		std::map < std::string, PLAYER > npm; // new player map

		PLAYER player = players->find(selected); // get selected player from players map


		if (!player.collisions(board, key)) // if there are no walls near the player
		{
			board = player.kill(board); // kill a character on the map

			if (key == 72) // up (jump)
			{
				if (player.voidUnder(board)) // if under player void
				{
					board = board_init(); // board clear
					if (player.ladder(board)) // if the player is on the ladder, then raise him by 1 element
					{
						player.move('u');
						Sleep(60);
					}
					else // else by 4 elements
					{
						for (int j = 0; j < 4; j++)
						{
							player.move('u'); // up player on 4 elements
						}
					}
				}
			}
			else if (key == 80) // down
			{ 
				if (player.limit(board)) // if the player is in prohibited territory
				{
					player.setPos({ 39, 40, 41 }, { 5, 5, 5 }); // change player cords
					board = player.kill(board); // kill player
					player.move(player.getGType()); // move player
					board = player.spawn(board); // spawn player
				}
				else
				{
					player.move('d'); // move player
				}
			}
			else if (key == 75) { player.move('l'); } // Left
			else if (key == 77) { player.move('r'); } // Right

			board = player.spawn(board); // spawn a character on the map
			npm.insert(std::make_pair(selected, player)); // add player to new players map

			players->set(npm); // set players map
		}
	}
}