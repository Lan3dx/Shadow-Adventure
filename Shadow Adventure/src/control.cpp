#include <iostream>

#include "../include/control.h"
#include "../include/sys/constants.h"

void control(PMAP* players, std::string selected, std::vector<std::vector<char>>& board, std::vector<std::vector<char>> g_board, int key) // control func for selected player
{
	if (players->get().contains(selected)) // if players map have selected player
	{
		std::map < std::string, PLAYER > npm; // new player map

		PLAYER player = players->find(selected); // get selected player from players map
		
		if (!player.collisions(board, key)) // if there are no walls near the player
		{
			player.kill(std::ref(board)); // kill a character on the map

			if (key == 72) // up (jump)
			{
				if (player.voidUnder(board)) // if under player void
				{
					if (player.ladder(g_board)) // if the player is on the ladder, then raise him by 1 element
					{
						if (!(player.getCWS() > 4))
						{
							for (int j = 0; j < 2; j++)
							{
								player.move('u');
							}
							PlaySound(music::LADDER, NULL, SND_FILENAME | SND_ASYNC);
							player.setCWS();
						}
					}
					else
					{
						if (!(player.getCWS() > 0))
						{
							for (int j = 0; j < JUMP_HEIGHT; j++)
							{
								player.move('u');
							}
							PlaySound(music::JUMP, NULL, SND_FILENAME | SND_ASYNC);
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
					player.kill(std::ref(board)); // kill player
					player.move(player.getGType()); // move player
					player.spawn(std::ref(board)); // spawn player
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
			else if (key == 75)  // Left
			{ 
				if (!(player.getCAD() > 0))
				{
					if (player.onstairs(board, 75))
					{
						player.move('u');
						player.move('l');
						player.setCAD();
					}
					else
					{
						player.move('l');
						player.setCAD();
					}
				}
			}
			else if (key == 77)  // Right
			{
				if (!(player.getCAD() > 0))
				{
					if (player.onstairs(board, 77))
					{
						player.move('u');
						player.move('r');
						player.setCAD();
					}
					else
					{
						player.move('r');
						player.setCAD();
					}
				}
			}

			players->rem(selected);
			players->add(selected, player);
		}
	}
}