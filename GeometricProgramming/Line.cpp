#include "Line.h"

Line::Line(Point Start, Point End, int PolygonId)
{
	start = Start;
	end = End;
	polygonId = PolygonId;
}

Point Line::Start()
{
	return start;
}

Point Line::End()
{
	return end;
}

int Line::PolygonId()
{
	return polygonId;
}