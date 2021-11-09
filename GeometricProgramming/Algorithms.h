#include "Line.h"
#include "Utilities.h"
using namespace std;
#ifndef ALGORITHMS_H
#define ALGORITHMS_H

int SegIntersect(Point p1, Point p2, Point p3, Point p4);

int Direction(Point p1, Point p2, Point p3);
int crossProduct(Point startLine1, Point endLine1, Point startLine2, Point endLine2);
int signOf(int crossProductResult);
bool OnSegment(Point p1, Point p2, Point p3);
bool AnySegmentIntersect(vector<Line> lines);

#endif