#include "Line.h"
#include "Utilities.h"
#include <queue> 
#include <map>
#include <set>
#include <unordered_map>
using namespace std;
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

int SegIntersect(Line s1, Line s2);

int Direction(Point p1, Point p2, Point p3);
float crossProduct(Point start, Point endLine1, Point endLine2);
int signOf(float crossProductResult);
bool OnSegment(Point p1, Point p2, Point p3);
bool AnySegmentIntersect(vector<Line> lines);
set<Point>::iterator BELOW(set<Point, ComparePoints>& T, set<Point>::iterator it);
set<Point>::iterator ABOVE(set<Point, ComparePoints>& T, set<Point>::iterator it);
void AddIntersection(unordered_map<int, int>& map, int s1, int s2);

#endif