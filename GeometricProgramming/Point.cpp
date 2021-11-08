
class Point
{
	public:
		Point() {
			x = 0;
			y = 0;
		}

		Point(int X, int Y) {
			x = X;
			y = Y;
		}

		int X() {
			return x;
		}

		int Y() {
			return y;
		}

	private:
		int x;
		int y;
};