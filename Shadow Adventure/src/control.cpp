#include "../include/control.h"
#include <iostream>

void control(PMAP* players, std::string selected, std::vector<std::vector<char>>& board, int key) // control func for selected player
{
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
					if (player.ladder(board_init())) // if the player is on the ladder, then raise him by 1 element
					{
						if (!(player.getCWS() > 4))
						{
							for (int j = 0; j < 2; j++)
							{
								player.move('u');
							}
							player.setCWS();
						}
					}
					else // else by 4 elements
					{
						if (!(player.getCWS() > 0))
						{
							for (int j = 0; j < 4; j++)
							{
								player.move('u'); // up player on 4 elements
							}
							player.setCWS();
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
					if (!(player.getCWS() > 4))
					{
						player.move('d'); // move player
						player.setCWS();
					}
				}
			}
			else if (key == 75) 
			{ 
				if (!(player.getCAD() > 0))
				{
					player.move('l');
					player.setCAD();
				}
			} // Left
			else if (key == 77) 
			{
				if (!(player.getCAD() > 0))
				{
					player.move('r');
					player.setCAD();
				}
			} // Right

			players->rem(selected);
			players->add(selected, player);
		}
	}
}