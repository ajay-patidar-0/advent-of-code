#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class guard
{
public:
    int x, y;
    int dir_x = 0, dir_y = -1;
    bool found = false;
    int movecount=1;
    void move_to(int x, int y)
    {
        this->x = x;
        this->y = y;
    }

    bool is_on_border(int width, int height)
    {
        if (x == 0 || x == width - 1 || y == 0 || y == height - 1)
        {
            return true;
        }
        return false;
    }
    void move(vector<vector<char>> &map)
    {
        if (map[y + dir_y][x + dir_x] == '.' || map[y + dir_y][x + dir_x] == 'X')
        {
             if (map[y + dir_y][x + dir_x] == '.')
             {
                movecount++;
             }
            x += dir_x;
            y += dir_y;
            map[y][x] = 'X';
        }
        else if (map[y + dir_y][x + dir_x] == '#')
        {
            if (dir_x == 0 && dir_y == -1)
            {
                dir_x = 1;
                dir_y = 0;
            }
            else if (dir_x == 1 && dir_y == 0)
            {
                dir_x = 0;
                dir_y = 1;
            }
            else if (dir_x == 0 && dir_y == 1)
            {
                dir_x = -1;
                dir_y = 0;
            }
            else if (dir_x == -1 && dir_y == 0)
            {
                dir_x = 0;
                dir_y = -1;
            }
        }
    }
};

// bool check_loop(vector<vector<char>> map, int guard_x, int guard_y, int obstacle_x, int obstacle_y)
// {
//     if (guard_x == obstacle_x && guard_y == obstacle_y)
//     {
//         return false;
//     }

//     else if (guard_x == obstacle_x && guard_y - 1 == obstacle_y)
//     {
//         return false;
//     }
//     map[obstacle_y][obstacle_x] = '#';
//     guard ratnabai;
//     ratnabai.move_to(guard_x, guard_y);
//     map[ratnabai.y][ratnabai.x] = 'X';
//     int movecount = 0;
//     while (!ratnabai.is_on_border(map[0].size(), map.size()))
//     {
//         movecount++;
//         ratnabai.move(map);
//         if (movecount > 3 * map.size() * map[0].size())
//         {
//             return true;
//         }
//     }
//     return false;
// }
int main()
{
    guard ratnabai;
    // Create an ifstream object to read from a file
    ifstream inputFile("data.txt");

    // Check if the file was opened successfully
    if (!inputFile)
    {
        cerr << "Unable to open file for reading";
        return 1;
    }

    // Read from the file
    string line;

    vector<vector<char>> map;
    while (getline(inputFile, line))
    {
        vector<char> row;
        for (int i = 0; i < line.size(); i++)
        {
            row.push_back(line[i]);
        }
        map.push_back(row);
    }
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            if (map[i][j] == '^')
            {
                ratnabai.move_to(j, i);
                ratnabai.found = true;
                break;
            }
        }
        if (ratnabai.found)
        {
            break;
        }
    }
    map[ratnabai.y][ratnabai.x]='X';
    
    // for (int i = 0; i < map.size(); i++)
    // {
    //     for (int j = 0; j < map[i].size(); j++)
    //     {
    //         if (check_loop(map, ratnabai.x, ratnabai.y, j, i))
    //         {
    //             sum++;
    //         }
    //     }
    // }
    while(!ratnabai.is_on_border(map.size(), map[0].size())){
        ratnabai.move(map);
        
    }
    cout<<ratnabai.movecount;

    inputFile.close();
    return 0;
}