#include <iostream>
#include <fstream>
#include<sstream>
#include <vector>
using namespace std;

bool valid_calib_eq(vector<int>row){
    int sum=0;
    int product=1;
    for(int i=1; i<row.size(); i++){
        sum+=row[i];
        product*=row[i];
    }
    if(sum==row[0] || product==row[0])
    return true;
    else if(sum>row[0] || product<row[0])
    return false;

    

}
int main()
{
    // Create an ifstream object to read from a file
    ifstream inputFile("sample.txt");

    // Check if the file was opened successfully
    if (!inputFile)
    {
        cerr << "Unable to open file for reading";
        return 1;
    }

    // Read from the file
    string line;

    vector<vector<int>> calib_eq;

    while (getline(inputFile, line))
    {
       stringstream ss(line);
       string word;
       vector<int> row;
       while(ss >> word){
       try{ 
        row.push_back(stoi(word));
        }
       catch(const invalid_argument&){

       }
       }
       calib_eq.push_back(row);
    }
    
   
  
    inputFile.close();
    return 0;
}