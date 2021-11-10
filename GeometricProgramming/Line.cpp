#include "Line.h"

Line::Line(Point Left, Point Right, int PolygonId, int LineId)
{
	left = Left;
	right = Right;
	polygonId = PolygonId;
	lineId = LineId;
}

Point Line::Left()
{
	return left;
}

Point Line::Right()
{
	return right;
}

int Line::LineId()
{
	return lineId;
}

int Line::PolygonId()
{
	return polygonId;
}