#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct InputLine{
    char modifier;
    int value;
};

// Get the value we should add to sum for the current iteration
int getIterationSumValue(char modifer, int value);
// create the input struct from the current line
InputLine createInputLineStruct(string inputLine);
// Search for the current frequency in the list
bool searchForRepeatFrequency(vector<int> *foundFrequencies, int currentSum);

int main(){

    ifstream inputFile;
    inputFile.open("./input.txt");
    string line;
    int sum = 0;
    vector<int> foundFrequencies;
    int foundValue = 0;

    while(true) {
        inputFile >> line;
        if(line[0] == 'e'){
            inputFile.clear();
            inputFile.seekg(0);
            continue;
        }

        InputLine currentLine = createInputLineStruct(line);
        sum += getIterationSumValue(currentLine.modifier, currentLine.value);
        if(searchForRepeatFrequency(&foundFrequencies, sum) == true){
            foundValue = sum;
            break;
        }
        else {
            foundFrequencies.push_back(sum);
        }
    }

    cout << foundValue << endl;
    return 0;    
}

int getIterationSumValue(char modifer, int value) {
    return modifer == '+' ? value : value * -1;
}

InputLine createInputLineStruct(string input) {
    InputLine currentLine;
    currentLine.modifier = input[0];
    currentLine.value = stoi(input.substr(1));
    return currentLine;
}

bool searchForRepeatFrequency(vector<int> *foundFrequencies, int currentSum) {
    if(foundFrequencies->size() < 1){
        return false;
    }
    for(int i = 0; i < foundFrequencies->size(); ++i) {
        if(foundFrequencies->at(i) == currentSum){
            return true;
        }
    }
    return false;
}