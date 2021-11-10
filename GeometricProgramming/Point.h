#include <string>
using namespace std;
#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		Point(float X, float Y);
		Point(float X, float Y, int Polygon, string EndPoint, int LineId);
		Point();
		float X();
		float Y();
		int Polygon();
		string EndPoint();
		int LineId();
		void AddMetadata(int polygon, string EndPoint, int LineId);

	private:
		float x;
		float y;
		int polygon;
		string endPoint;
		int lineId;
};

#endif

