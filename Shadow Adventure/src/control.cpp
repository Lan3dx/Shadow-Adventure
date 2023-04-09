#include <iostream>

#include "../include/sys/includes.h"
#include "../include/control.h"

std::string control(PMAP* players, std::string selected, std::vector<std::vector<block>>& board, std::vector<std::vector<block>>& g_board, int key, PlayerFrame* pframe, Corners* corners) // control func for selected player
{
	std::string returned = "null";

	if (players->get().contains(selected)) // if players map have selected player
	{
		std::map < std::string, PLAYER > npm; // new player map

		PLAYER player = players->find(selected); // get selected player from players map
		
		if (!player.collisions(board, key)) // if there are no walls near the player
		{
			player.kill(std::ref(board)); // kill a character on the map

			if (key == 72) // up
			{
				player.setCHAR('^');
				if (player.voidUnder(std::ref(board))) // if under player void
				{
					if (player.getX()[1] == pframe->y - pframe->length + 1)
					{
						pframe->y -= 1;
						pframe->ischanged = true;
						corners->lt = 50;
					}
					if (player.inwater(std::ref(g_board)))
					{
						if (!(player.getCWS() > 4))
						{
							for (int j = 0; j < 2; j++)
							{
								player.move('u');
							}
						}
						player.setCWS();
						returned = "water";
					}
					else if (player.ladder(std::ref(g_board))) // if the player is on the ladder, then raise him by 1 element
					{
						if (!(player.getCWS() > 4))
						{
							for (int j = 0; j < 2; j++)
							{
								player.move('u');
							}
							player.setCWS();
							returned = "ladder";
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
							returned = "jump";
							player.setCWS();
						}
					}
				}
			}
			else if (key == 80) // down
			{ 
				if (player.getX()[1] == pframe->y + pframe->length + 1)
				{
					pframe->y += 1;
					pframe->ischanged = true;
					corners->lt = 50;
				}
				if (player.limit(std::ref(board))) // if the player is in prohibited territory
				{
					player.setPos({ 39, 40, 41 }, { 5, 5, 5 }); // change player cords
					player.kill(std::ref(board)); // kill player
					player.move(player.getGType()); // move player
					player.spawn(std::ref(board)); // spawn player
					pframe->x = 5;
					pframe->y = 40;
					pframe->ischanged = true;
					corners->lt = 50;
				}
				else
				{
					if (!(player.getCWS() > 4))
					{
						if (player.ladder(std::ref(g_board))) // if the player is on the ladder, then play sound
						{
							returned = "ladder";
						}
						player.move('d'); // move player
						player.setCWS();
					}
				}
			}
			else if (key == 75)  // Left
			{ 
				if (!(player.getCAD() > 0))
				{
					player.setCHAR('<');
					if (player.getY()[1] == pframe->x - pframe->length)
					{
						pframe->x -= 1;
						pframe->ischanged = true;
						corners->lt = 50;
					}
					if (player.onstairs(std::ref(board), 75))
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
					if (player.getY()[1] == pframe->x + pframe->length)
					{
						pframe->x += 1;
						pframe->ischanged = true;
					}
					player.setCHAR('>');
					if (player.onstairs(std::ref(board), 77))
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
	return returned;
}