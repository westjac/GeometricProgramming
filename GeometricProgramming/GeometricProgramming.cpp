
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Line.h"
#include "Algorithms.h"
#include <chrono>

using namespace std;

int randNumber()
{
    return (rand() % 2000 - 1000);
}

void runTests()
{
    int numberOfTests = 800;
    ofstream file;
    file.open("sortTests.csv", std::ofstream::out | std::ofstream::trunc);
    file << "Time values are in nanoseconds\n";
    file << "Test Length, Time (ns), answer size\n";

    for (int i = 2; i < numberOfTests + 1; i++)
    {
        //Generate the random pairs
        vector<pair<int, int>> lines(i);
        vector<pair<int, int>> strength(i);
        vector<int> answer; //Answer Array
        srand(time(NULL));

        for (int j = 0; j < i; j++)
        {
            //Creating the line objects
            string line = "";
            vector<Line> lines;
            vector<Point> points;

            float x = 0;
            float y = 0;
            points.clear();
            //Get all points for the given line
            while (ss >> x >> y)
            {
                points.push_back(Point(randNumber(), randNumber()));
                points.push_back(Point(randNumber(), randNumber()));
            }

            //create line segments, makes sure the leftmost point is set correctly
            for (int i = 0; i < points.size(); i++)
            {
                if (i == points.size() - 1) //Special case for last item
                {
                    if (points[i].X() <= points[0].X())
                    {
                        lines.push_back(Line(points[i], points[0], polygonId, lineId));
                    }
                    else
                    {
                        lines.push_back(Line(points[0], points[i], polygonId, lineId));
                    }
                }
                else
                {
                    if (points[i].X() <= points[i + 1].X())
                    {
                        lines.push_back(Line(points[i], points[i + 1], polygonId, lineId));
                    }
                    else
                    {
                        lines.push_back(Line(points[i + 1], points[i], polygonId, lineId));
                    }
                }
                lineId++;
            }
            polygonId++;

        }

        //Time Tests
        auto start = chrono::high_resolution_clock::now();
        LCS_LENGTH(sortedDiameter, sortedStrength, direction, cost);
        GET_LCS(direction, sortedDiameter, answer, sortedDiameter.size(), sortedDiameter.size());
        int duplicateCount = Remove_Duplicates(answer, diameter, strength);
        auto end = chrono::high_resolution_clock::now();
        auto elapsedTime = end - start;

        file << i << "," << elapsedTime.count() << "," << answer.size() - duplicateCount << "\n";
    }

    file.close();
    return 0;
}

int main(int argc, char *argv[])
{
    //Loading the file
    ifstream inFile;
    if(argc == 2)
    {
        if (argv[1] == "test")
        {
            runTests();
            return 0;
        }
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

    unordered_map<int, int> foundIntersections = AnySegmentIntersect(lines);

    cout << foundIntersections.size() << endl;
    for (auto x : foundIntersections)
    {
        cout << x.first << " " << x.second << endl;
    }
}

