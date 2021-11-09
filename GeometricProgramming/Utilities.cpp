#include "Utilities.h"

bool lineCompareator(Line &a, Line &b)
{
	if(a.Left().X() == b.Left().X()) //If the Xs are the same
		return a.Left().Y() < b.Left().Y(); //Lowest Y first
	else
		return a.Left().X() < b.Left().X(); //Lowest X
}

