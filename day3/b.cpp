#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

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
    bool flag = true;
    while (getline(inputFile, line))
    {
        for (int i = 0; i < line.size(); i++)
        {
            if ("don't()" == line.substr(i, 7))
            {
                flag = false;
            }
            else if ("do()" == line.substr(i, 4))
            {
                flag = true;
            }
            if (flag == false)
            {
                continue;
            }
            if (line[i] == 'm' && line[i + 1] == 'u' && line[i + 2] == 'l' && line[i + 3] == '(' && is_number(line[i + 4]))
            {
                if (is_number(line[i + 5]))
                {
                    if (is_number(line[i + 6]) && line[i + 7] == ',')
                    {
                        if (is_number(line[i + 8]))
                        {
                            if (is_number(line[i + 9]))
                            {
                                if (is_number(line[i + 10]) && line[i + 11] == ')')
                                {
                                    int a = (line[i + 4] - '0') * 100;
                                    a += (line[i + 5] - '0') * 10;
                                    a += (line[i + 6] - '0');
                                    int b = (line[i + 8] - '0') * 100;
                                    b += (line[i + 9] - '0') * 10;
                                    b += (line[i + 10] - '0');
                                    sum += a * b;
                                }
                                else if (line[i + 10] == ')')
                                {
                                    int a = (line[i + 4] - '0') * 100;
                                    a += (line[i + 5] - '0') * 10;
                                    a += (line[i + 6] - '0');
                                    int b = (line[i + 8] - '0') * 10;
                                    b += (line[i + 9] - '0');
                                    sum += a * b;
                                }
                            }
                            else if (line[i + 9] == ')')
                            {
                                int a = (line[i + 4] - '0') * 100;
                                a += (line[i + 5] - '0') * 10;
                                a += (line[i + 6] - '0');
                                int b = (line[i + 8] - '0');
                                sum += a * b;
                            }
                        }
                    }
                    else if (line[i + 6] == ',')
                    {
                        if (is_number(line[i + 7]))
                        {
                            if (is_number(line[i + 8]))
                            {
                                if (is_number(line[i + 9]) && line[i + 10] == ')')
                                {
                                    int a = (line[i + 4] - '0') * 10;
                                    a += (line[i + 5] - '0');
                                    int b = (line[i + 7] - '0') * 100;
                                    b += (line[i + 8] - '0') * 10;
                                    b += (line[i + 9] - '0');
                                    sum += a * b;
                                }
                                else if (line[i + 9] == ')')
                                {
                                    int a = (line[i + 4] - '0') * 10;
                                    a += (line[i + 5] - '0');
                                    int b = (line[i + 7] - '0') * 10;
                                    b += (line[i + 8] - '0');
                                    sum += a * b;
                                }
                            }
                            else if (line[i + 8] == ')')
                            {
                                int a = (line[i + 4] - '0') * 10;
                                a += (line[i + 5] - '0');
                                int b = (line[i + 7] - '0');
                                sum += a * b;
                            }
                        }
                    }
                }
                else if (line[i + 5] == ',')
                {
                    if (is_number(line[i + 6]))
                    {
                        if (is_number(line[i + 7]))
                        {
                            if (is_number(line[i + 8]) && line[i + 9] == ')')
                            {
                                int a = (line[i + 4] - '0');
                                int b = (line[i + 6] - '0') * 100;
                                b += (line[i + 7] - '0') * 10;
                                b += (line[i + 8] - '0');
                                sum += a * b;
                            }
                            else if (line[i + 8] == ')')
                            {
                                int a = (line[i + 4] - '0');
                                int b = (line[i + 6] - '0') * 10;
                                b += (line[i + 7] - '0');
                                sum += a * b;
                            }
                        }
                        else if (line[i + 7] == ')')
                        {
                            int a = (line[i + 4] - '0');
                            int b = (line[i + 6] - '0');
                            sum += a * b;
                        }
                    }
                }
            }
        }
    }
    cout << sum;
    inputFile.close();
    return 0;
}