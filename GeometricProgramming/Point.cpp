#include "Point.h"

Point::Point(float X, float Y) {
	x = X;
	y = Y;
}

Point::Point() {
	x = 0;
	y = 0;
}

float Point::X() {
	return x;
}

float Point::Y() {
	return y;
}

int Point::Segment()
{
	return segment;
}

string Point::EndPoint()
{
	return endPoint;
}

void Point::AddMetadata(int Segment, string EndPoint)
{
	segment = Segment;
	endPoint = EndPoint;
}

