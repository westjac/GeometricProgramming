
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
        //Line Test 1
        /*Point a1 = Point(-2, 2);
        Point a2 = Point(2, 0);
        Point b1 = Point(2, 2);
        Point b2 = Point(-2, 0);*/

        //line Test 2 AB and CD (No cross)
        /*Point a1 = Point(-2, 1);
        Point a2 = Point(2, 0);
        Point b1 = Point(-3.48, 2.47);
        Point b2 = Point(-0.54, 0.95);*/

        //line Test 2 AB and EF (Point on Line)
        Point a1 = Point(-2, 1);
        Point a2 = Point(2, 0);
        Line s1 = Line(a1, a2, 0, 0);
        Point b1 = Point(-1, 4);
        Point b2 = Point(0, 0.5);
        Line s2 = Line(b1, b2, 0, 0);

        bool intersect = SegIntersect(s1, s2);
        
        //cout << "Wrong number of arguments" << endl;
        return 0;
    }

    if (!inFile.is_open())
        {
            cout << "Failed to open file!" << endl;
            return -1;
        }

    //Creating the line objects
    string line = "";
    vector<Line> lines;
    vector<Point> points;
    vector<Point> allPoints;

    int polygonId = 0;
    int lineId = 0;
    int indexOffset = 0;
    
    //Gets a line for each polygon
    while(getline(inFile, line))
    {    
        stringstream ss(line);
        float x = 0;
        float y = 0;
        points.clear();
        //Get all points for the given line
        while(ss >> x >> y)
        {
            points.push_back(Point(x, y));
            allPoints.push_back(Point(x, y));
        }
    
        //create line segments, makes sure the leftmost point is set correctly
        for(int i = 0; i < points.size(); i++)
        {
            if( i == points.size() - 1) //Special case for last item
            {
                if(points[i].X() <= points[0].X())
                {
                    lines.push_back(Line(points[i], points[0], polygonId, lineId));
                    allPoints[i+indexOffset].AddMetadata(polygonId, "L", lineId);
                }
                else
                {
                    lines.push_back(Line(points[0], points[i], polygonId, lineId));
                    allPoints[i + indexOffset].AddMetadata(polygonId, "R", lineId);
                }
            }
            else
            {
                if (points[i].X() <= points[i + 1].X())
                {
                    lines.push_back(Line(points[i], points[i+1], polygonId, lineId));
                    allPoints[i + indexOffset].AddMetadata(polygonId, "L", lineId);
                }
                else
                {
                    lines.push_back(Line(points[i+1], points[i], polygonId, lineId));
                    allPoints[i + indexOffset].AddMetadata(polygonId, "R", lineId);
                }
            }
            lineId++;
        }
        indexOffset += points.size();
        polygonId++;
    }
    
    //At this point I now have a vector of lines read in from file,
    //    where each line has a polygon id.

    //Convert vector<Line> lines to a heap
    //make_heap(lines.begin(), lines.end(), lineCompareator);
    
    //Sort heap start from lowest value leftX point on the lines
    //sort_heap(lines.begin(), lines.end(), lineCompareator);

    //AnySegmentIntersect(lines, allPoints);
}

