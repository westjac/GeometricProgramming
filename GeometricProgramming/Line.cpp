#include "Line.h"

Line::Line(Point Left, Point Right, int PolygonId)
{
	left = Left;
	right = Right;
	polygonId = PolygonId;
}

Point Line::Left()
{
	return left;
}

Point Line::Right()
{
	return right;
}

int Line::PolygonId()
{
	return polygonId;
}