#include "Utilities.h"

bool lineCompareator(Line &a, Line &b)
{
	if(a.Left().X() == b.Left().X()) //If the Xs are the same
		return a.Left().Y() < b.Left().Y(); //Lowest Y first
	else
		return a.Left().X() < b.Left().X(); //Lowest X
}

bool cmpPts(Point a, Point b)
{
	if (a.X() == b.X()) //If the Xs are the same
		return a.Y() < b.Y(); //Lowest Y first
	else
		return a.X() < b.X(); //Lowest X
}

bool ComparePoints::operator()(Point a, Point b)
{
	if (a.X() == b.X()) //If the Xs are the same
		return a.Y() < b.Y(); //Lowest Y first
	else
		return a.X() < b.X(); //Lowest X
}
