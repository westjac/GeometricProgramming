#include "Line.h"
using namespace std;
#ifndef UTILITIES_H
#define UTILITIES_H

bool lineCompareator(Line &a, Line &b);
bool cmpPts(Point a, Point b);

class ComparePoints
{
public:
    bool operator() (Point a, Point b) const;
};

#endif
