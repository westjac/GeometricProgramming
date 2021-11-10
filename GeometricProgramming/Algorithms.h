#include "Line.h"
#include "Utilities.h"
#include <queue> 
#include <map>
#include <set>
using namespace std;
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

int SegIntersect(Line s1, Line s2);

int Direction(Point p1, Point p2, Point p3);
float crossProduct(Point start, Point endLine1, Point endLine2);
int signOf(float crossProductResult);
bool OnSegment(Point p1, Point p2, Point p3);
bool AnySegmentIntersect(vector<Line> lines);
Line ABOVE(set<Point> T, Point p);
Line BELOW(set<Point> T, Point p);

#endif