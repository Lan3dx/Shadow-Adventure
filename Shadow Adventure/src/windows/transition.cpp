#include "../../include/windows/transition.h"
#include "../../include/sys/includes.h"

// deprecated
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
// deprecated
int line_transition()
{
    for (int y = 6; y < 54; y++) // columns
    {
        std::string line;
        for (int x = 1; x < 52; x++) // lines
        {
            line += "* ";
        }
        std::cout << line << '\n';
        Sleep(5);
    }
    for (int y = 6; y < 60; y++) // columns
    {
        std::string line;
        for (int x = 1; x < 30; x++) // lines
        {
            line += "  ";
        }
        std::cout << line << '\n';
    }
    return 0;
}
// deprecated
int spiral_transition(std::vector<std::vector<char>> board)
{
    size_t top = 6, bottom = board.size() - 2;
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