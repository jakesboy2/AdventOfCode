#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Represents a unique character in the string and the number of occurences
struct UniqueNode {
    char c;
    int count;
};

// Get a vector of unique node structs for the current line
vector<UniqueNode> getUniqueNodeVector(string);

// Check if the line has exactly two or three occurences of a character
bool isExactlyTwo(vector<UniqueNode>*);
bool isExactlyThree(vector<UniqueNode>*);

// Look for the character in the vector
bool isCharacterAccountedFor(char, vector<UniqueNode>*);

// Get the number of occurances of the character in the line
int numOfOccur(char, string);

int main(){

    ifstream inputFile;
    inputFile.open("./input.txt");
    string line;
    int exactlyTwo = 0;
    int exactlyThree = 0;
    
    while(inputFile >> line) {
        vector<UniqueNode> lineNodes = getUniqueNodeVector(line);
        if(isExactlyTwo(&lineNodes)){
            exactlyTwo++;
        }
        if(isExactlyThree(&lineNodes)) {
            exactlyThree++;
        }
    }

    std::cout << exactlyTwo * exactlyThree << endl;
    return 0;    
}

vector<UniqueNode> getUniqueNodeVector(string line) {
    vector<UniqueNode> lineNodes;
    UniqueNode uNode;
    int num;
    char c;
    for(int i = 0; i < line.length(); ++i) {
        num = 0;
        c = line[i];
        if(!isCharacterAccountedFor(c, &lineNodes)){ 
            uNode.c = c;
            uNode.count = numOfOccur(c, line);
            lineNodes.push_back(uNode);
        }
    }
    return lineNodes;
}

bool isExactlyTwo(vector<UniqueNode> *lineNodes) {
    for(int i = 0; i < lineNodes->size(); ++i) {
        if(lineNodes->at(i).count == 2) {
            return true;
        }
    }
    return false;
}

bool isExactlyThree(vector<UniqueNode> *lineNodes) {
    for(int i = 0; i < lineNodes->size(); ++i) {
        if(lineNodes->at(i).count == 3) {
            return true;
        }
    }
    return false;
}

bool isCharacterAccountedFor(char c, vector<UniqueNode> *uniqueNodes) {
    for(int i = 0; i < uniqueNodes->size(); ++i) {
        if(uniqueNodes->at(i).c == c){
            return true;
        }
    }
    return false;
}

int numOfOccur(char c, string line) {
    int sum = 0;
    for(int i = 0; i < line.length(); ++i) {
        if(line[i] == c) {
            sum++;
        }
    }
    return sum;
}