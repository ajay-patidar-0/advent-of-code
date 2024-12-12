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
    // cout << endl;
    // for (int i = 0; i < id_map.size(); i++)
    // {
    //     cout << id_map[i];
    // }

    int start = 0, end = id_map.size() - 1;
    while (start < end)
    {
        int countno = 0, countdot = 0;
        bool change = false;
        if (check_int(id_map[end]))
        {
            for (int i = end; i >= 0; i--)
            {
                if (check_int(id_map[i]) && id_map[i] == id_map[i - 1])
                {
                    continue;
                }
                else
                {
                    countno = end - i + 1;
                    break;
                }
            }
            for (int i = start; i < end; i++)
            {
                if (id_map[i] == ".")
                {
                    countdot++;
                }
                else
                {
                    countdot = 0;
                }
                if (countdot == countno)
                {
                    change = true;
                    while (countno)
                    {
                        swap(id_map[i], id_map[end]);
                        i--;
                        end--;
                        countno--;
                    }
                    break;
                }
            }
        }

        if (countno == 0 && change == true)
            continue;
        else if (countno == 0 && change == false)
            end--;
        else
            end -= countno;
    }

    // cout << endl;
    // for (int i = 0; i < id_map.size(); i++)
    // {
    //     cout << id_map[i];
    // }

    unsigned long long sum = 0;
    for (int i = 0; i < id_map.size(); i++)
    {
        if (id_map[i] == ".")
        {
            continue;
        }
        sum += (i * stoi(id_map[i]));
    }

    cout << sum;

    inputFile.close();
    return 0;
}