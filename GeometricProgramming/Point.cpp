#include "Point.h"

Point::Point(int X, int Y) {
	x = X;
	y = Y;
}

Point::Point() {
	x = 0;
	y = 0;
}

int Point::X() {
	return x;
}

int Point::Y() {
	return y;
}
