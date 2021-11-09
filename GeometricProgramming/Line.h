#include "Point.h"

#ifndef LINE_H
#define LINE_H

class Line
{
	public:
		Line(Point Left, Point Right, int PolygonId);
		Point Left();
		Point Right();
		int PolygonId();

	private:
		Point left;
		Point right;
		int polygonId;
};

#endif
