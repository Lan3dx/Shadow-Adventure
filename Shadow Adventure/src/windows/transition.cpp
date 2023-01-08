#include "../../include/windows/transition.h"
#include "../../include/sys/includes.h"

void render(std::vector<std::vector<char>> map)
{
    clear();
    for (int y = 6; y < map.size() - 8; y++) // columns
    {
        std::string line = " ";
        for (int x = 1; x < map[y].size() - 1; x++) // lines
        {
            line += map[y][x];
            line += " ";
        }
        std::cout << line << '\n';
    }
}

int line_transition(std::vector<std::vector<char>> map)
{
    for (int y = 6; y < map.size() - 8; y++) // columns
    {
        for (int x = 1; x < map[y].size() - 1; x++) // lines
        {
            map[y][x] = ' ';
        }
        render(map);
        Sleep(10);
    }
    return 0;
}

int spiral_transition(std::vector<std::vector<char>> board)
{
    size_t top = 6, bottom = board.size() - 8;
    size_t left = 1, right = board[0].size() - 1;

    int index = 0;

    while (1)
    {
        if (left > right) 
        {
            break;
        }

        for (size_t i = left; i <= right; i++)
        {
            board[top][i] = ' ';
            render(board);
        }
        top++;

        if (top > bottom) 
        {
            break;
        }

        for (size_t i = top; i <= bottom; i++)
        {
            board[i][right] = ' ';
            render(board);
        }
        right--;


        if (left > right) {
            break;
        }

        for (size_t i = right; i >= left; i--)
        {
            board[bottom][i] = ' ';
            render(board);
        }
        bottom--;

        if (top > bottom) 
        {
            break;
        }

        for (size_t i = bottom; i >= top; i--)
        {
            board[i][left] = ' ';
            render(board);
        }
        left++;
    }
    return 0;
}