
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Line.h"
#include "Algorithms.h"

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
    int polygonId = 0;
    
    //Gets a line for each polygon
    while(getline(inFile, line))
    {    
        vector<Point> points;
        stringstream ss(line);
        float x = 0;
        float y = 0;
        points.clear();
        //Get all points for the given line
        while(ss >> x >> y)
        {
            points.push_back(Point(x, y));
        }
    
        //create line segments, makes sure the leftmost point is set correctly
        for(int i = 0; i < points.size(); i++)
        {
            if( i == points.size() - 1) //Special case for last item
            {
                if(points[i].X() <= points[0].X())
                    lines.push_back(Line(points[i], points[0], polygonId));
                else
                    lines.push_back(Line(points[0], points[i], polygonId));
            }
            else
            {
                if(points[i].X() <= points[i+1].X())
                    lines.push_back(Line(points[i], points[i+1], polygonId));
                else
                    lines.push_back(Line(points[i+1], points[i], polygonId));
            }
        }
        polygonId++;
    }
    
    //At this point I now have a vector of lines read in from file,
    //    where each line has a polygon id.

    //Convert vector<Line> lines to a heap
    //make_heap(lines.begin(), lines.end(), lineCompareator);
    
    //Sort heap start from lowest value leftX point on the lines
    //sort_heap(lines.begin(), lines.end(), lineCompareator);

    AnySegmentIntersect(lines);
}

