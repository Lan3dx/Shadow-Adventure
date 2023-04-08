#include "../../include/windows/mapdrawer.h"
#include "../../include/windows/mapchanger.h"
#include "../../include/sys/includes.h"
#include "../../include/mapgen.h"

namespace constants
{
	const int xlim = 19; // array smoothing variables relative to screen coordinates
	const int ylim = 11;
}

std::vector<std::vector<char>> g_board(100, std::vector<char>(101));

void render(std::vector<std::vector<char>> board, int x, int y, char tool, float fps, int left_corner, int up_corner) // render
{
	std::string str = "";
	for (int x = left_corner; x < left_corner + 50; x++)
	{
		str += ". ";
	}
	std::cout << str << '\n';
	for (int y = up_corner; y < up_corner + 48; y++)
	{
		str = ". ";
		for (int x = left_corner; x < left_corner + 48; x++)
		{
			str += board[y][x];
			if (x == left_corner + 47)
			{
				str += " .";
			}
			else
			{
				str += " ";
			}
		}
		std::cout << str << '\n';
	}
	str = "";
	for (int x = left_corner; x < left_corner + 50; x++)
	{
		str += ". ";
	}
	std::cout << str << '\n';
	std::cout << "        X: " << x << " | Y: " << y << " | tool: " << tool << " | FPS: " << round(int(1.0f / fps)) << " | Use your mouse - middle mouse button           " << '\n';
	std::cout << "  (#) - wall   (|) - ladder   (-) - scaffold   (+) - stairs   (S) -  booster   (W) - water   (D) - death" << '\n';
	std::cout << "  [ENTER] - save map  [TAB] - other maps  [ARROWS] - move camera  [R] - random gen  [ESC] - exit" << '\n';
}

char toolchanger(char ctool, char type) // change the active character to draw
{
	std::vector<char> tools = { '#','|','-','+','S','W','D',' ' };
	char tool = ctool;
	for (size_t i = 0; i < tools.size(); i++)
	{
		if (ctool == tools[i])
		{
			if (type == 'u')
			{
				if (i == 0)
				{
					tool = tools[tools.size() - 1];
				}
				else
				{
					tool = tools[i - 1];
				}
			}
			if (type == 'd')
			{
				if (i == tools.size() - 1)
				{
					tool = tools[0];
				}
				else
				{
					tool = tools[i + 1];
				}
			}
		}
	}
	return tool;
}

int mapdrawer()
{
	POINT pos;
	std::vector<std::vector<char>> board(100, std::vector<char>(101));

	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 0; x < board[y].size(); x++)
		{
			g_board[y][x] = ' ';
		}
	}
	for (int x = 0; x < board[0].size(); x++)
	{
		g_board[0][x] = 'D';
		g_board[board.size() - 1][x] = 'D';
	}

	std::ifstream fin("resources/maps/active.txt");
	char sym;
	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 0; x < board[y].size(); x++)
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

	int left_corner = 0;
	int up_corner = 0;

	char tool = '#';
	int cooldownfps = 1;
	float fps = 80;
	int keyCd = 20;
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

		for (int x = 0; x < board[0].size(); x++)
		{
			g_board[0][x] = 'D';
			g_board[board.size() - 1][x] = 'D';
		}
		for (int y = 0; y < board.size(); y++)
		{
			g_board[y][0] = '#';
			g_board[y][board[0].size() - 1] = '#';
		}

		clear();
		GetCursorPos(&pos);

		if (GetAsyncKeyState((unsigned short)VK_ESCAPE))
		{
			return 0;
		}
		if (GetAsyncKeyState((unsigned short)VK_TAB))
		{
			std::vector<std::vector<char>> t_board = g_board;
			for (int y = 0; y < board.size(); y++)
			{
				for (int x = 0; x < board[y].size(); x++)
				{
					if (t_board[y][x] == ' ')
					{
						t_board[y][x] = '~';
					}
				}
			}
			std::ofstream fout("resources/maps/active.txt");
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < board[0].size(); j++)
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
			std::vector<std::vector<char>> t_board = g_board;
			for (int y = 0; y < board.size(); y++)
			{
				for (int x = 0; x < board[0].size(); x++)
				{
					if(t_board[y][x] == ' ')
					{
						t_board[y][x] = '~';
					}
				}
			}
			std::ofstream fout("resources/maps/active.txt");
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < board[0].size(); j++)
				{
					fout << t_board[i][j];
				}
				fout << std::endl;
			}
			fout.close();
		}
		if (GetAsyncKeyState((unsigned short)VK_MBUTTON))
		{
			g_board[pos.y / constants::ylim][pos.x / constants::xlim] = tool;
		}
		if (GetAsyncKeyState((unsigned short)'W'))
		{
			if (keyCd <= 0)
			{
				tool = toolchanger(tool, 'u');
				keyCd = 20;
			}
		}
		if (GetAsyncKeyState((unsigned short)'S'))
		{
			if (keyCd <= 0)
			{
				tool = toolchanger(tool, 'd');
				keyCd = 20;
			}
		}
		if (GetAsyncKeyState((unsigned short)'R'))
		{
			if (keyCd <= 0)
			{
				g_board = gen();
				keyCd = 20;
			}
		}
		if (GetAsyncKeyState((unsigned short)VK_RIGHT))
		{
			if (keyCd <= 0)
			{
				if (left_corner + 48.0 != board[0].size())
				{
					left_corner += 1;
				}
				keyCd = 20;
			}
		}
		if (GetAsyncKeyState((unsigned short)VK_LEFT))
		{
			if (keyCd <= 0)
			{
				if (left_corner != 0)
				{
					left_corner -= 1;
				}
				keyCd = 20;
			}
		}
		if (GetAsyncKeyState((unsigned short)VK_UP))
		{
			if (keyCd <= 0)
			{
				if (up_corner != 0)
				{
					up_corner -= 1;
				}
				keyCd = 20;
			}
		}
		if (GetAsyncKeyState((unsigned short)VK_DOWN))
		{
			if (keyCd <= 0)
			{
				if (up_corner + 48.0 != board.size())
				{
					up_corner += 1;
				}
				keyCd = 20;
			}
		}

		for (int y = 0; y < board.size(); y++)
		{
			for (int x = 0; x < board[0].size(); x++)
			{
				board[y][x] = g_board[y][x];
			}
		}
		board[pos.y / constants::ylim][pos.x / constants::xlim] = 'Q';
		if (keyCd > 0)
		{
			keyCd -= 1;
		}

		render(board, int(pos.x / constants::xlim), int(pos.y / constants::ylim), tool, fps, left_corner, up_corner);
	}

	return 0;
}