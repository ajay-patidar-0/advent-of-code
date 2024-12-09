#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
using namespace std;

string get_binary(unsigned long long n, unsigned long long size)
{
    string binary = "";
    while (n)
    {
        binary = to_string(n % 2) + binary;
        n /= 2;
    }
    while (size)
    {
        if (binary.length() >= size - 2)
            return binary;
        else
            binary = "0" + binary;
    }
    return binary;
}
bool valid_calib_eq(vector<unsigned long long> row)
{

    unsigned long long size = row.size();
    for (unsigned long long i = 0; i < pow(2, size - 2); i++)
    {
        string binary = get_binary(i, size);
        unsigned long long result = row[1];
        for (unsigned long long j = 0; j < row.size() - 2; j++)
        {

            if (binary[j] == '0')
            {
                result += row[j + 2];
            }
            else
            {
                result *= row[j + 2];
            }
        }
        if (result == row[0])
        {
            return true;
        }
    }
    return false;
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

    vector<vector<unsigned long long>> calib_eq;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string word;
        vector<unsigned long long> row;
        while (ss >> word)
        {
            try
            {
                row.push_back(stoll(word));
            }
            catch (const invalid_argument &)
            {
            }
        }
        calib_eq.push_back(row);
    }
    unsigned long long sum = 0;
    for (unsigned long long i = 0; i < calib_eq.size(); i++)
    {
        if (valid_calib_eq(calib_eq[i]))
        {
            sum += calib_eq[i][0];
        }
    }
    cout << sum;

    inputFile.close();
    return 0;
}