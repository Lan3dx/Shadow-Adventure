#include "../../../include/entities/sys/change.h"

void change(PMAP* players, std::string* selected)
{
	if (*selected == "")
	{
		*selected = ("player" + std::to_string(0));
		return;
	}
	int b = 0;
	for (auto& entityS : players->get())
	{
		if (*selected == ("player" + std::to_string(b)))
		{
			if (players->get().contains("player" + std::to_string(b + 1)))
			{
				*selected = ("player" + std::to_string(b + 1));
				break;
			}
			else
			{
				*selected = ("player" + std::to_string(0));
				break;
			}
		}
		b += 1;
	}
}