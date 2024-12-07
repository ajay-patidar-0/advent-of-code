#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

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
    vector<int> list1;
    vector<int> list2;
    while (getline(inputFile, line))
    {
        // split the line
        istringstream iss(line);
        int num1, num2;
        // Split the line into two numbers
        if (iss >> num1 >> num2)
        {
            list1.push_back(num1);
            list2.push_back(num2);
        }
        else
        {
            cerr << "Error parsing line: " << line << endl;
        }
    }
    // sort list1
    sort(list1.begin(), list1.end());
    sort(list2.begin(), list2.end());
    int sum = 0;
    for (int i = 0; i < list1.size(); i++)
    {
        sum += (abs(list1[i] - list2[i]));
    }

    cout << sum << endl;
    // Close the file
    inputFile.close();

    return 0;
}