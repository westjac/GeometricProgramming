#include "Point.h"

#ifndef LINE_H
#define LINE_H

class Line
{
	public:
		Line(Point Start, Point End, int PolygonId);
		Point Start();
		Point End();
		int PolygonId();

	private:
		Point start;
		Point end;
		int polygonId;
};

#endif
