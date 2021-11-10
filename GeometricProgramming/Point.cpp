#include "Point.h"

Point::Point(float X, float Y) {
	x = X;
	y = Y;
	polygon = 0;
	endPoint = "N";
	lineId = 0;
}

Point::Point(float X, float Y, int Polygon, string EndPoint, int LineId)
{
	x = X;
	y = Y;
	polygon = Polygon;
	endPoint = EndPoint;
	lineId = LineId;
}

Point::Point() {
	x = 0;
	y = 0;
	polygon = 0;
	endPoint = "N";
	lineId = 0;
}

float Point::X() {
	return x;
}

float Point::Y() {
	return y;
}

int Point::Polygon()
{
	return polygon;
}

string Point::EndPoint()
{
	return endPoint;
}

int Point::LineId()
{
	return lineId;
}

void Point::AddMetadata(int Polygon, string EndPoint, int LineId)
{
	polygon = Polygon;
	endPoint = EndPoint;
	lineId = LineId;
}

