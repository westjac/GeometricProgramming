
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
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
    else
    {
        cout << "Wrong number of arguments" << endl;
        return -1;
    }

    if (!inFile.is_open())
        {
            cout << "Failed to open file!" << endl;
            return -1;
        }

    //Creating the line objects
    string line = "";
    vector<Line> lines;
    
    //Gets a line for each polygon
    while(getline(inFile, line))
    {    
        int polygonId = 0;
        vector<Point> points;
        stringstream ss(line);
        int x = 0;
        int y = 0;
        points.clear();
        //Get all points for the given line
        while(ss >> x >> y)
        {
            points.push_back(Point(x, y));
        }
    
        //create line segments
        for(int i = 0; i < points.size(); i++)
        {
            if( i == points.size() - 1) //Special case for last item
            {
                lines.push_back(Line(points[i], points[0], polygonId));
            }
            else
            {
                lines.push_back(Line(points[i], points[i+1], polygonId));
            }
        }
    }
    
    //At this point I now have a vector of lines read in from file,
    //    where each line has a polygon id.




}

