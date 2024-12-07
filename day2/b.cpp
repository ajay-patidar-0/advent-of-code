#include <iostream>
#include <fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include <cmath>

using namespace std;
bool check_difference(vector<int> a)
{
    
    for(int i=0; i<a.size()-1; i++){
        if(1>abs(a[i]-a[i+1]) || 3<abs(a[i]-a[i+1])){
            return false;
        }
    }
    return true;
}

int main() {
    // Create an ifstream object to read from a file
    ifstream inputFile("data.txt");

    // Check if the file was opened successfully
    if (!inputFile) {
        cerr << "Unable to open file for reading";
        return 1;
    }

    // Read from the file
    string line;
    vector<vector<int>> list;
    while (getline(inputFile, line)) {
      // split the line
         istringstream iss(line);
         vector<int>temp;
        int num;
        while(iss>> num){
            temp.push_back(num);
        }
        list.push_back(temp);
        
    }
    int count=0;
    for(const auto& row : list){
         if ((is_sorted(row.begin(), row.end()) || is_sorted(row.begin(), row.end(), greater<int>())) && check_difference(row)) {
            count++;
        }
         else{
        for(int i=0; i<row.size(); i++){
            vector<int>temp=row;
            temp.erase(temp.begin()+i);
       if ((is_sorted(temp.begin(), temp.end()) || is_sorted(temp.begin(), temp.end(), greater<int>())) && check_difference(temp)) {
            count++;
            break;
        }}
        }
       

    }
    cout<<count;
    // Close the file
    inputFile.close();

    

    return 0;
}