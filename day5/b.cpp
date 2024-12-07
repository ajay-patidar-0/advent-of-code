#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <regex>
using namespace std;
bool check_invalid_order(vector<vector<int>> data, vector<int> row)
{
    bool flag = true;
    for (int i = 0; i < data.size(); i++)
    {
        for (int b = 0; b < row.size(); b++)
        {
            if (data[i][1] == row[b])
            {
                for (int c = b + 1; c < row.size(); c++)
                {
                    if (data[i][0] == row[c])
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                {
                    break;
                }
            }
            if (flag == false)
            {
                break;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
    return flag == false;
}

int main()
{
    // Create an ifstream object to read from a file
    ifstream inputFile("data.txt");
    ifstream inputFile2("data2.txt");
    // Check if the file was opened successfully
    if (!inputFile || !inputFile2)
    {
        cerr << "Unable to open file for reading";
        return 1;
    }

    // Read from the file
    string line;
    int sum = 0;
    vector<vector<int>> data;
    while (getline(inputFile, line))
    {
        size_t pos = line.find('|');
        if (pos != string::npos)
        {
            // Extract substrings before and after '|'
            string num1_str = line.substr(0, pos);
            string num2_str = line.substr(pos + 1);

            // Convert strings to integers
            vector<int> row;
            row.push_back(stoi(num1_str));
            row.push_back(stoi(num2_str));
            data.push_back(row);
        }
    }
    vector<vector<int>> data2;
    while (getline(inputFile2, line))
    {
        vector<int> row;
        size_t start = 0;
        size_t end = line.find(',');

        // Process each number separated by commas
        while (end != string::npos)
        {
            string num_str = line.substr(start, end - start);
            if (!num_str.empty())
            {
                row.push_back(stoi(num_str));
            }
            start = end + 1;
            end = line.find(',', start);
        }

        // Process the last number after the last comma
        string last_num = line.substr(start);
        if (!last_num.empty())
        {
            row.push_back(stoi(last_num));
        }

        if (!row.empty())
        {
            data2.push_back(row);
        }
    }

    for (int a = 0; a < data2.size(); a++)
    {

        if (check_invalid_order(data, data2[a]))
        {
        

            while (check_invalid_order(data, data2[a]))
            {
                for (int i = 0; i < data2[a].size(); i++)
                {
                    for (int p = 0; p < data.size(); p++)
                    {
                        for (int j = i + 1; j < data2[a].size(); j++)
                        {
                            if (data[p][1] == data2[a][i])
                            {
                                if (data[p][0] == data2[a][j])
                                {
                                    swap(data2[a][i], data2[a][j]);
                                }
                            }
                        }
                    }
                }
            }
           
            sum += data2[a][data2[a].size() / 2];
        }
        cout << endl;
    }
    cout << sum;
    inputFile.close();
    return 0;
}