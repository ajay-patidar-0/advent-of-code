#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

bool check_int(string str)
{
    if (str.empty())
        return false; // Handle empty string
    for (char ch : str)
    {
        if (!std::isdigit(ch))
        {
            return false;
        }
    }
    return true;
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

    ostringstream buffer;
    buffer << inputFile.rdbuf();

    // Read from the file
    string line = buffer.str();
    vector<int> diskmap;

    for (int i = 0; i < line.length(); i++)
    {
        diskmap.push_back(line[i] - '0');
    }

    // for (int i = 0; i < diskmap.size(); i++)
    // {
    //     cout << diskmap[i];
    // }
    vector<string> id_map;
    int count = 0;
    for (int i = 0; i < diskmap.size(); i++)
    {
        if (i % 2 == 1)
        {
            for (int j = 0; j < diskmap[i]; j++)
            {
                id_map.push_back(".");
            }
        }
        else
        {
            for (int j = 0; j < diskmap[i]; j++)
            {
                id_map.push_back(to_string(count));
            }
            count++;
        }
    }

    //  for (int i = 0; i < id_map.size(); i++)
    // {
    //     cout << id_map[i];
    // }

    int start = 0, end = id_map.size() - 1;
    while (start < end)
    {
        if (id_map[start] == "." && check_int(id_map[end]))
        {
            swap(id_map[start], id_map[end]);
            start++;
            end--;
        }
        else
        {
            if (id_map[start] != ".")
                start++;
            if (!check_int(id_map[end]))
                end--;
        }
    }

    //  for (int i = 0; i < id_map.size(); i++)
    // {
    //     cout << id_map[i];
    // }

    unsigned long long sum = 0;
    for (int i = 0; i < id_map.size(); i++)
    {
        if (id_map[i] == ".")
        {
            break;
        }
        sum += (i * stoi(id_map[i]));
    }

    cout << sum;

    inputFile.close();
    return 0;
}