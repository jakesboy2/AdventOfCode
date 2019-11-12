#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int* getLineArray(string, int);

int main(){

    ifstream inputFile;
    inputFile.open("./input.txt");
    string line;
    int lineNumber = 1;
    
    while(getline(inputFile, line)) {
        int* lineArray = getLineArray(line, lineNumber);
        ++lineNumber;
    }

    return 0;    
}

int* getLineArray(string line, int lineNumber) {
    int* lineArray = new int[5];
    lineArray[0] = lineNumber;

    // Get the information we need for splitting the string
    int coordXStart = 5;
    int coordXEnd = 0;
    int coordYEnd = 0;
    int coordYStart = 0;
    int startLocXStart = 0;
    int startLocXEnd = 0;
    int startLocYStart = 0;
    int startLocYEnd = line.length() - 1;
    for(int i = coordXStart; i < line.length(); ++i) {
        if(line[i] == ',') {
            coordXEnd = i-1;
            coordYStart = i+1;
        }
        else if(line[i] == ':') {
            coordYEnd = i-1;
            startLocXStart = i+2;
        }
        else if(line[i] == 'x') {
            startLocXEnd = i-1;
            startLocYStart = i+1;
        }
    }

    // Get coordinates size
    lineArray[1] = stoi(line.substr(coordXStart,  coordXEnd - coordXStart + 1));
    lineArray[2] = stoi(line.substr(coordYStart,  coordYEnd - coordYStart + 1));
    // Get the starting location
    lineArray[3] = stoi(line.substr(startLocXStart,  startLocXEnd - startLocXStart + 1));
    lineArray[4] = stoi(line.substr(startLocYStart,  startLocYEnd - startLocYStart + 1));

    return lineArray;
}