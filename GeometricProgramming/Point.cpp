#include "Point.h"

Point::Point(float X, float Y) {
	x = X;
	y = Y;
	segment = 0;
	endPoint = "N";
	lineId = 0;
}

Point::Point() {
	x = 0;
	y = 0;
	segment = 0;
	endPoint = "N";
	lineId = 0;
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

int Point::LineId()
{
	return lineId;
}

void Point::AddMetadata(int Segment, string EndPoint, int LineId)
{
	segment = Segment;
	endPoint = EndPoint;
	lineId = LineId;
}

