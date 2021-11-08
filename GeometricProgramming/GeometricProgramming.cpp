
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Line.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Loading the file
    ifstream inFile;
    if(argc == 2)
    {
        string fileName = argv[1];
        inFile.open(fileName);
    }

    if (!inFile.is_open())
        {
            cout << "Failed to open file!" << endl;
            return -1;
        }

    //Creating the line objects
    string line = "";
    vector<Line> lines;
    
    while(getline(inFile, line))
        cout << line << endl;
        //stringstream ss(line)

    Point point = Point(1, 1);
}

