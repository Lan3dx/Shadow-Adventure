#include "../../include/windows/mapdrawer.h"
#include "../../include/windows/mapchanger.h"
#include "../../include/sys/includes.h"

namespace constants
{
	const int size_X = 51; // array size
	const int size_Y = 48;

	const int xlim = 38; // array smoothing variables relative to screen coordinates
	const int ylim = 23;
}

std::vector<std::vector<char>> g_board(constants::size_Y, std::vector<char>(constants::size_X));

void render(std::vector<std::vector<char>> board, int x, int y, char tool, float fps) // render
{
	std::string str = "";
	for (int x = 0; x < constants::size_X+1; x++)
	{
		str += ". ";
	}
	std::cout << str << '\n';
	for (int y = 0; y < constants::size_Y; y++)
	{
		str = ". ";
		for (int x = 0; x < constants::size_X; x++)
		{
			str += board[y][x];
			if (x == constants::size_X - 2)
			{
				if (y == 2)
				{
					str += "#";
				}
				if (y == 8)
				{
					str += "|";
				}
				if (y == 14)
				{
					str += "-";
				}
				if (y == 20)
				{
					str += "+";
				}
				if (y == 26)
				{
					str += "S";
				}
				if (y == 32)
				{
					str += "F";
				}
				if (y == 38)
				{
					str += "D";
				}
				if (y == 44)
				{
					str += "C";
				}
			}
			else if (x == constants::size_X - 1)
			{
				if (y == 50 || y == 44 || y == 38 || y == 32 || y == 26 || y == 20 || y == 14 || y == 8 || y == 2)
				{
					str += ".";
				}
				else
				{
					str += " .";
				}
			}
			else
			{
				str += " ";
			}
		}
		std::cout << str << '\n';
	}
	str = "";
	for (int x = 0; x < constants::size_X+1; x++)
	{
		str += ". ";
	}
	std::cout << str << '\n';
	std::cout << "        X: " << x << " | Y: " << y << " | tool: " << tool << " | FPS: " << round(int(1.0f / fps)) << " | Use your mouse - middle mouse button           " << '\n';
	std::cout << "  [#] - wall   [|] - ladder   [-] - scaffold   [+] - stairs   [S] -  booster   [F] - wall   [D] - death" << '\n';
	std::cout << "  [ENTER] - save map     [TAB] - change active map     [ESC] - exit" << '\n';
}

void toolchanger(POINT pos, char *tool) // change the active character to draw
{
	if (pos.y / constants::ylim >= 0 && pos.y / constants::ylim <= 4)
	{
		*tool = '#';
	}
	if (pos.y / constants::ylim >= 6 && pos.y / constants::ylim <= 10)
	{
		*tool = '|';
	}
	if (pos.y / constants::ylim >= 12 && pos.y / constants::ylim <= 16)
	{
		*tool = '-';
	}
	if (pos.y / constants::ylim >= 18 && pos.y / constants::ylim <= 22)
	{
		*tool = '+';
	}
	if (pos.y / constants::ylim >= 24 && pos.y / constants::ylim <= 28)
	{
		*tool = 'S';
	}
	if (pos.y / constants::ylim >= 30 && pos.y / constants::ylim <= 34)
	{
		*tool = 'F';
	}
	if (pos.y / constants::ylim >= 36 && pos.y / constants::ylim <= 40)
	{
		*tool = 'D';
	}
	if (pos.y / constants::ylim >= 42 && pos.y / constants::ylim <= 46)
	{
		*tool = ' ';
	}
}

int mapdrawer()
{
	POINT pos;
	std::vector<std::vector<char>> board(constants::size_Y, std::vector<char>(constants::size_X));

	for (int y = 0; y < constants::size_Y; y++)
	{
		for (int x = 0; x < constants::size_X; x++)
		{
			g_board[y][x] = ' ';
		}
	}
	for (int x = 0; x < 48; x++)
	{
		g_board[0][x] = 'D';
		g_board[47][x] = 'D';
	}

	std::ifstream fin("resources/maps/active.txt");
	char sym;
	for (int y = 0; y < 48; y++)
	{
		for (int x = 0; x < 48; x++)
		{
			fin >> sym;
			if (sym == '~')
			{
				g_board[y][x] = ' ';
			}
			else
			{
				g_board[y][x] = sym;
			}
		}
	}
	fin.close();
	auto tp1 = std::chrono::system_clock::now();
	auto tp2 = std::chrono::system_clock::now();

	tp2 = std::chrono::system_clock::now();
	std::chrono::duration<float> elapsedTime = tp2 - tp1;
	tp1 = tp2;
	float fElapsedTime = elapsedTime.count();

	char tool = '#';
	int cooldownfps = 1;
	float fps = 80;
	while (true)
	{
		tp2 = std::chrono::system_clock::now();
		std::chrono::duration<float> elapsedTime = tp2 - tp1;
		tp1 = tp2;
		float fElapsedTime = elapsedTime.count();

		if (cooldownfps <= 0)
		{
			fps = fElapsedTime;
			cooldownfps = 80;
		}
		else
		{
			cooldownfps -= 1;
		}

		for (int x = 0; x < constants::size_X - 2; x++)
		{
			g_board[0][x] = 'D';
		}
		for (int y = 0; y < constants::size_Y; y++)
		{
			g_board[y][0] = '#';
			g_board[y][47] = '#';
		}

		clear();
		GetCursorPos(&pos);

		if (GetAsyncKeyState((unsigned short)VK_ESCAPE))
		{
			return 0;
		}
		if (GetAsyncKeyState((unsigned short)VK_TAB))
		{
			auto t_board = g_board;
			for (int y = 0; y < 48; y++)
			{
				for (int x = 0; x < 48; x++)
				{
					if (t_board[y][x] == ' ')
					{
						t_board[y][x] = '~';
					}
				}
			}
			std::ofstream fout("resources/maps/active.txt");
			for (int i = 0; i < 48; i++)
			{
				for (int j = 0; j < 48; j++)
				{
					fout << t_board[i][j];
				}
				fout << std::endl;
			}
			fout.close();

			g_board = mapchanger();
		}
		if (GetAsyncKeyState((unsigned short)VK_RETURN))
		{
			auto t_board = g_board;
			for (int y = 0; y < 48; y++)
			{
				for (int x = 0; x < 48; x++)
				{
					if(t_board[y][x] == ' ')
					{
						t_board[y][x] = '~';
					}
				}
			}
			std::ofstream fout("resources/maps/active.txt");
			for (int i = 0; i < 48; i++)
			{
				for (int j = 0; j < 48; j++)
				{
					fout << t_board[i][j];
				}
				fout << std::endl;
			}
			fout.close();
		}
		if (GetAsyncKeyState((unsigned short)VK_MBUTTON))
		{
			if (pos.x / constants::xlim >= 47)
			{
				toolchanger(pos, &tool);
			}
			else
			{
				g_board[pos.y / constants::ylim][pos.x / constants::xlim] = tool;
			}
		}

		for (int y = 0; y < constants::size_Y; y++)
		{
			for (int x = 0; x < constants::size_X; x++)
			{
				board[y][x] = g_board[y][x];
			}
		}
		board[pos.y / constants::ylim][pos.x / constants::xlim] = 'Q';

		render(board, int(pos.x / constants::xlim), int(pos.y / constants::ylim), tool, fps);
	}

	return 0;
}