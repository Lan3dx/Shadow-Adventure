#include "../include/alistener.h"

void listenerA(std::vector<animation>& animations)
{
  for (auto it = animations.begin(); it != animations.end(); ++it)
  {
    it->LT -= 1;
  }
  for (auto it = animations.begin(); it != animations.end();)
  {
    if (it->LT <= 0)
    {
      it = animations.erase(it);
    }
    else
    {
      ++it;
    }
  }
}