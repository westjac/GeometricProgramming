#include "Point.h"

#ifndef LINE_H
#define LINE_H

class Line
{
	public:
		Line(Point Left, Point Right, int PolygonId, int lineId);
		Point Left();
		Point Right();
		int LineId();
		int PolygonId();

	private:
		Point left;
		Point right;
		int polygonId;
		int lineId;
};

#endif
