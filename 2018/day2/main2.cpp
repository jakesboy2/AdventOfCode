#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main(){

    ifstream inputFile;
    inputFile.open("./input.txt");
    string line;
    vector<string> ids;
    ids.reserve(250);
    int numDifferent = 0;
    
    while(inputFile >> line) {
        ids.push_back(line);
    }
    cout << "Array length: " << ids.size() << endl;

    // For every line
    for(int i = 0; i < ids.size() - 1; ++i) {
        numDifferent = 0;
        // Check every line after it
        for(int j = i + 1; j < ids.size(); ++j) {
            numDifferent = 0;
            // Count the number of lines that are different
            for(int k = 0; k < line.length(); ++k) {
                string compOne = ids.at(i);
                string compTwo = ids.at(j);
                if(compOne[k] != compTwo[k]) {
                    numDifferent++;
                }
            }
            // cout << "i: " << i << " - numDifferent: " << numDifferent << endl;
            if(numDifferent == 1) {
                cout << "1: " << ids.at(i) << endl;
                cout << "2: " << ids.at(j) << endl;
            }
        }
    }

    return 0;    
}