#include "Line.h"
#include "Utilities.h"
#include <queue> 
#include <map>
using namespace std;
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

int SegIntersect(Point p1, Point p2, Point p3, Point p4);

int Direction(Point p1, Point p2, Point p3);
float crossProduct(Point start, Point endLine1, Point endLine2);
int signOf(float crossProductResult);
bool OnSegment(Point p1, Point p2, Point p3);
bool AnySegmentIntersect(vector<Line> lines, vector<Point> points);
Line ABOVE(map<int, Line> T, Line s);
Line BELOW(map<int, Line> T, Line s);

#endif