#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
using namespace std;
bool is_number(const char s)
{
    return s >= '0' && s <= '9';
}

int main()
{
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
    int sum = 0;
    vector<string> data;
    while (getline(inputFile, line))
    {
        data.push_back(line);
    }

    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            if (i <= data.size() - 3 && j <= data[i].size() - 3 && data[i][j] == 'M' && data[i + 1][j + 1] == 'A' && data[i + 2][j + 2] == 'S')
            {
                if (data[i][j + 2] == 'M' && data[i + 1][j + 1] == 'A' && data[i + 2][j] == 'S')
                {
                    sum++;
                }
                else if (data[i + 2][j] == 'M' && data[i + 1][j + 1] == 'A' && data[i][j + 2] == 'S')
                {
                    sum++;
                }
            }
            else if (i <= data.size() - 3 && j <= data[i].size() - 3 && data[i][j] == 'S' && data[i + 1][j + 1] == 'A' && data[i + 2][j + 2] == 'M')
            {
                if (data[i][j + 2] == 'S' && data[i + 1][j + 1] == 'A' && data[i + 2][j] == 'M')
                {
                    sum++;
                }
                else if (data[i + 2][j] == 'S' && data[i + 1][j + 1] == 'A' && data[i][j + 2] == 'M')
                {
                    sum++;
                }
            }
        }
    }
    cout << sum;
    inputFile.close();
    return 0;
}