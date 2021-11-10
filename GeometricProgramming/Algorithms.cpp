#include <vector>
#include <algorithm>
#include "Algorithms.h"

int SegIntersect(Line s1, Line s2)
{
	Point p1 = s1.Left();
	Point p2 = s1.Right();
	Point p3 = s2.Left();
	Point p4 = s2.Right();

	int dir1 = Direction(p3, p4, p1);
	int dir2 = Direction(p3, p4, p2);
	int dir3 = Direction(p1, p2, p3);
	int dir4 = Direction(p1, p2, p4);

	if (((dir1 > 0 && dir2 < 0) || (dir1 < 0 && dir2 > 0)) &&
		((dir3 > 0 && dir4 < 0) || (dir3 < 0 && dir4 > 0)))
		return true;
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

	return signOf(crossProduct(p1, p2, p3));
}

float crossProduct(Point p1, Point p2, Point p3)
{
	return (p2.Y() - p1.Y()) * (p3.X() - p2.X()) - ((p3.Y() - p2.Y()) * (p2.X() - p1.X()));
}

int signOf(float crossProductResult)
{
	if (crossProductResult == 0) //Same Segment
		return 0;
	else if (crossProductResult > 0) //Right
		return 1;
	else if (crossProductResult < 0) //Left
		return -1;
	else
		return 404; //Error
}

bool OnSegment(Point p1, Point p2, Point p3)
{
	if ((min(p1.X(), p2.X()) <= p3.X() && p3.X() <= max(p1.X(), p3.X())) &&
		(min(p1.Y(), p2.Y()) <= p3.Y() && p3.Y() <= max(p1.Y(), p3.Y())))
		return true;
	else
		return false;
}

bool AnySegmentIntersect(vector<Line> lines)
{
	//set T - Active points
	set<Point> T;
	//unordered map

	//Push all sweep line events to a vector of Points
	vector<Point> sortedPoints;
	for (Line line : lines)
	{
		sortedPoints.push_back(Point(line.Left().X(), line.Left().Y(), line.PolygonId(), "L", line.LineId()));
		sortedPoints.push_back(Point(line.Right().X(), line.Right().Y(), line.PolygonId(), "R", line.LineId()));
	}

	//Sort endpoints of the lines
	sort(sortedPoints.begin(), sortedPoints.end(), cmpPts);

	//Walk through all points
	for (Point point : sortedPoints)
	{
		if (point.EndPoint() == "L")
		{
			T.insert(point);
			set<Point>::iterator above = T.lower_bound(point);
			set<Point>::iterator below = BELOW(T, above);
			if ((above != T.end() && SegIntersect(lines[((above)->LineId())], lines[point.LineId()])) ||
				(below != T.end() && SegIntersect(lines[(below)->LineId()], lines[point.LineId()])))
				return true;
		}
		if (point.EndPoint() == "R")
		{
			//Get the iterator
			int index = point.LineId();
			auto itr = T.find(Point(lines[index].Left().X(), lines[index].Left().Y(), point.Polygon(), "L", point.LineId()));
			
			set<Point>::iterator above = ABOVE(T, itr);
			set<Point>::iterator below = BELOW(T, itr);

			if ((above != T.end() && below != T.end()) && SegIntersect(lines[(below)->LineId()], lines[point.LineId()]))
				return true;
			
			//Remove current segment
			T.erase(itr);
		}
	}
	return false;
}

// Find predecessor of iterator in s.
set<Point>::iterator BELOW(set<Point>& T, set<Point>::iterator it) {
	if (it == T.begin())
		return T.end();
	else
		return --it;
}

// Find successor of iterator in s.
set<Point>::iterator ABOVE(set<Point>& T, set<Point>::iterator it) {
	return ++it;
}

//Line ABOVE(set<Point> T, Point p)
//{
//	int lineId = s.LineId()
//		return Line AB();
//}
//
//Line BELOW(set<Point> T, Point p)
//{
//	return Line();
//}

//bool AnySegmentIntersect(vector<Line> lines, vector<Point> points)
//{
//	//T = 0 the RB tree set
//	map<int, Line> T;
//	
//	//Sort the line segments
//	auto pointCompare = [](Point a, Point b)
//	{
//		if (a.X() == b.X()) //If the Xs are the same
//			return a.Y() < b.Y(); //Lowest Y first
//		else
//			return a.X() < b.X(); //Lowest X
//	};
//
//	vector<Point> sortedPoints;
//
//	for(Line l : lines)
//	{
//		Point left = l.Left();
//		left.AddMetadata(l.PolygonId(), "L", l.LineId());
//		Point right = l.Right();
//		right.AddMetadata(l.PolygonId(), "R", l.LineId());
//		sortedPoints.push_back(left);
//		sortedPoints.push_back(right);
//	}
//	//Sort the endpoints from left to right
//	sort(sortedPoints.begin(), sortedPoints.end(), cmpPts);
//
//	int z = 0;
//	for (Point p : sortedPoints)
//	{
//		Line s = lines[p.LineId()];
//		if (p.EndPoint() == "L")
//		{
//			T.insert(pair<int, Line>(p.LineId(), s));
//			if ((ABOVE(T, s).L().X() != -1 && SegIntersect(s.Left(), s.Right(), ABOVE(T, s).L(), ABOVE(T, s).R()) == true) ||
//				(BELOW(T, s).L().X() != -1 && SegIntersect(s.Left(), s.Right(), BELOW(T, s).L(), BELOW(T, s).R()) == true))
//			{
//				return true;
//
//			};
//		}
//		if (p.EndPoint() == "R")
//		{
//			if ((ABOVE(T, s).L().X() != -1 && BELOW(T, s).L().X() != -1) &&
//				SegIntersect(s.Left(), s.Right(), ABOVE(T, s).L(), ABOVE(T, s).R()) == true))
//				{
//				return true;
//
//				};
//		}
//		return false;
//	}
//}
//

