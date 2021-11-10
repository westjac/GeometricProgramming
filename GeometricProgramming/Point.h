#include <string>
using namespace std;
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
		int LineId();
		void AddMetadata(int Segment, string EndPoint, int LineId);

	private:
		float x;
		float y;
		int segment;
		string endPoint;
		int lineId;
};

#endif

