#include "Point.cpp"
#include "Algorithms.h"
#include <vector>
#include "Line.cpp"

using namespace std;

int SegIntersect(Point p1, Point p2, Point p3, Point p4)
{
	int dir1 = Direction(p3, p4, p1);
	int dir2 = Direction(p3, p4, p2);
	int dir3 = Direction(p1, p2, p3);
	int dir4 = Direction(p1, p2, p4);

	if ((dir1 > 0 && dir2 < 0) || (dir1 < 0 && dir2 > 0) &&
		(dir3 > 0 && dir4 < 0) || (dir3 < 0 && dir4 > 0))
	{
		return true;
	}
	else if (dir1 == 0 && OnSegment(p3, p4, p1))
		return true;
	else if (dir2 == 0 && OnSegment(p3, p4, p2))
		return true;
	else if (dir3 == 0 && OnSegment(p1, p2, p3))
		return true;
	else if (dir4 == 0 && OnSegment(p1, p2, p4))
		return true;
	else 
		return false;
}

int Direction(Point p1, Point p2, Point p3)
{
	//assume sign_of()
	//returns +1, 0, or -1 to indicate direction

	return signOf(crossProduct(p1, p3, p1, p2));
}

int crossProduct(Point startLine1, Point endLine1, Point startLine2, Point endLine2)
{
	return 0;
}

int signOf(int crossProductResult)
{
	if (crossProductResult == 0) //Same Segment
		return 0;
	else if (crossProductResult > 0)
		return 1;
	else if (crossProductResult < 0)
		return -1;
	else
		return 404; //Error
}

bool OnSegment(Point p1, Point p2, Point p3)
{
	return false;
}

bool AnySegmentIntersect(vector<Line> lines)
{
	//T = 0 the RB tree
	//Sort the line segments
	vector<Line> sortedSegments = lines;

	for (Line point : sortedSegments)
	{
		//If p is a left end point of segment s
			//INSERT(T, s)
			//If (ABOVE(T,s) exisits && intersects s) OR (BELOW(T,s) exists && interests s)
				//return true
		//If p is a right end point of segment s
			//if(ABOVE(T,s) and BELOW(T,s) exist) and (ABOVE(T,s) intersects BELOW(T, s))
				//return true
			//DELETE(T,s)
		//Return false
	}
}