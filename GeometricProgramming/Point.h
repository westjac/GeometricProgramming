#include <string>
#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		Point(float X, float Y);
		Point();
		float X();
		float Y();
		int Segment();
		string EndPoint();
		void AddMetadata(int Segment, string EndPoint);

	private:
		float x;
		float y;
		int segment;
		string endPoint;
		//Line Id
};

#endif

