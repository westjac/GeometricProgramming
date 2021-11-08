#include "Point.cpp"

class Line
{
	public:
		Line(Point Start, Point End)
		{
			start = Start;
			end = End;
		}

		Point Start()
		{
			return start;
		}

		Point End()
		{
			return end;
		}

	private:
		Point start;
		Point end;
};