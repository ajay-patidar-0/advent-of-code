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
    regex pattern("XMAS");
    regex pattern2("SAMX");
    // Count occurrences of "XMAS" in each line
    for (const auto &row : data)
    {
        auto words_begin = sregex_iterator(row.begin(), row.end(), pattern);
        auto words_end = sregex_iterator();
        sum += distance(words_begin, words_end);
        auto words_begin1 = sregex_iterator(row.begin(), row.end(), pattern2);
        auto words_end1 = sregex_iterator();
        sum += distance(words_begin1, words_end1);
    }
    for (int i = 0; i < data.size(); i++)
    {
        for (int j = 0; j < data[i].size(); j++)
        {
            if (i <= data.size() - 4 && data[i][j] == 'X' && data[i + 1][j] == 'M' && data[i + 2][j] == 'A' && data[i + 3][j] == 'S')
            {
                sum++;
            }
            else if (i <= data.size() - 4 && data[i][j] == 'S' && data[i + 1][j] == 'A' && data[i + 2][j] == 'M' && data[i + 3][j] == 'X')
            {
                sum++;
            }
            if (i <= data.size() - 4 && j <= data[i].size() - 4 && data[i][j] == 'X' && data[i + 1][j + 1] == 'M' && data[i + 2][j + 2] == 'A' && data[i + 3][j + 3] == 'S')
            {
                sum++;
            }
            else if (i <= data.size() - 4 && j <= data[i].size() - 4 && data[i][j] == 'S' && data[i + 1][j + 1] == 'A' && data[i + 2][j + 2] == 'M' && data[i + 3][j + 3] == 'X')
            {
                sum++;
            }
            if (i <= data.size() - 4 && j >= 3 && data[i][j] == 'X' && data[i + 1][j - 1] == 'M' && data[i + 2][j - 2] == 'A' && data[i + 3][j - 3] == 'S')
            {
                sum++;
            }
            else if (i <= data.size() - 4 && j >= 3 && data[i][j] == 'S' && data[i + 1][j - 1] == 'A' && data[i + 2][j - 2] == 'M' && data[i + 3][j - 3] == 'X')
            {
                sum++;
            }
        }
    }
    cout << sum;
    inputFile.close();
    return 0;
}