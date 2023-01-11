#include "../../include/windows/mapchanger.h"
#include "../../include/sys/includes.h"

std::string ws2s(const std::wstring& s)
{
    int len;
    int slength = (int)s.length() + 1;
    len = WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, 0, 0, 0, 0);
    std::string r(len, '\0');
    WideCharToMultiByte(CP_ACP, 0, s.c_str(), slength, &r[0], len, 0, 0);
    return r;
}

std::string random_txt(int a, int b)
{
    srand(time((NULL)));
    std::string res = "resources/maps/";
    if (a > 0) res += std::to_string(a + rand() % (b - a));
    else res += std::to_string(a + rand() % (abs(a) + b));
    res += ".txt";
    return res;
}

void map_render(std::vector<std::vector<char>> map)
{
    clear();
    std::cout << '\n'; // next column
    std::cout << '\n';
    for (int y = 1; y < 47; y++) // columns
    {
        std::string line;
        if (y != 24 && y != 23 && y != 25) line += "      ";
        else line += "";
        for (int x = 1; x < 47; x++) // lines
        {
            if (y == 23 && x == 1) line += " <<<  ";
            if (y == 24 && x == 1) line += " <<<  ";
            if (y == 25 && x == 1) line += " <<<  ";
            line += map[y][x];
            line += " ";
            if (y == 23 && x == map[y].size() - 2) line += "  >>> ";
            if (y == 24 && x == map[y].size() - 2) line += "  >>> ";
            if (y == 25 && x == map[y].size() - 2) line += "  >>> ";
        }
        if (y != 24 && y != 23 && y != 25) line += "      ";
        else line += "";
        std::cout << line;
        std::cout << '\n'; // next column
    }
    std::cout << "         [ENTER] - change map           [A] - left           [D] - right           [ESC] - exit " << '\n';
}

std::vector<std::vector<char>> mapchanger()
{
    clear();
    for (int i = 0; i < 60; i++) // clear screen
    {
        std::string line;
        for (int j = 0; j < 60; j++)
        {
            line += "  ";
        }
        std::cout << line << '\n';
    }
    std::vector<std::vector<char> > map(48, std::vector<char>(51));
    for (int y = 0; y < 48; y++)
    {
        for (int x = 0; x < 51; x++)
        {
            map[y][x] = ' ';
        }
    }
    std::vector<std::string> maps;
    int key_cd = 50;
    std::string path = "resources/maps";
    for (const auto& entry : std::filesystem::directory_iterator(path))
    {
        std::wstring map = entry.path().native();
        std::string ecranum = R"(\)";
        maps.push_back(ws2s(map));
    }

    size_t selected = 0;
    std::ifstream fin(maps[selected]);
    char sym;
    for (int y = 0; y < 48; y++)
    {
        for (int x = 0; x < 48; x++)
        {
            fin >> sym;
            if (sym == '~')
            {
                map[y][x] = ' ';
            }
            else
            {
                map[y][x] = sym;
            }
        }
    }
    fin.close();
    while (true)
    {
        if (key_cd != 0)
        {
            key_cd -= 1;
        }
        if (GetAsyncKeyState((unsigned short)'A'))
        {
            if (key_cd == 0)
            {
                key_cd = 50;
                if (selected == 0)
                {
                    selected = maps.size() - 1;
                }
                else
                {
                    selected -= 1;
                }
                std::ifstream fin(maps[selected]);
                char sym;
                for (int y = 0; y < 48; y++)
                {
                    for (int x = 0; x < 48; x++)
                    {
                        fin >> sym;
                        if (sym == '~')
                        {
                            map[y][x] = ' ';
                        }
                        else
                        {
                            map[y][x] = sym;
                        }
                    }
                }
                fin.close();
            }
        }
        if (GetAsyncKeyState((unsigned short)'D'))
        {
            if (key_cd == 0)
            {
                key_cd = 50;
                if (selected == maps.size() - 1)
                {
                    selected = 0;
                }
                else
                {
                    selected += 1;
                }
                std::ifstream fin(maps[selected]);
                char sym;
                for (int y = 0; y < 48; y++)
                {
                    for (int x = 0; x < 48; x++)
                    {
                        fin >> sym;
                        if (sym == '~')
                        {
                            map[y][x] = ' ';
                        }
                        else
                        {
                            map[y][x] = sym;
                        }
                    }
                }
                fin.close();
            }
        }
        if (GetAsyncKeyState((unsigned short)VK_RETURN))
        {
            if (key_cd == 0)
            {
                fin.close();
                key_cd = 50;
                std::string active = "resources/maps/active.txt";
                auto status0 = std::rename(active.c_str(), random_txt(1000,10000).c_str());
                if (status0 != 0) exit(0);
                auto status1 = std::rename(maps[selected].c_str(), "resources/maps/active.txt");
                return map;
            }
        }
        if (GetAsyncKeyState((unsigned short)VK_ESCAPE))
        {
            return map;
        }
        map_render(map);
    }

    return map;
}