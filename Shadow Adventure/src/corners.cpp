#include "../include/corners.h"

void cornerListener(PMAP players, std::string selected, std::vector<std::vector<block>> board, Corners* corners, PlayerFrame* pframe)
{
  if (players.get().contains(selected)) // if players map have selected player
  {
    if (pframe->ischanged)
    {
      pframe->ischanged = false;

      PLAYER player = players.find(selected);

      if (player.getY()[0] - corners->left < 24)
      {
        if (corners->left != 0)
        {
          corners->left -= 1;
        }
      }
      else if (player.getY()[0] - corners->left > 24)
      {
        if ((corners->left + 48.0) != (board[0].size()))
        {
          corners->left += 1;
        }
      }

      if (player.getX()[0] - corners->up < 24)
      {
        if (corners->up != 0)
        {
          corners->up -= 1;
        }
      }
      else if (player.getX()[0] - corners->up > 24)
      {
        if ((corners->up + 48.0) != (board[0].size()))
        {
          corners->up += 1;
        }
      }
    }
  }
}