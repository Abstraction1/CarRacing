#include "Points.h"
#include <iostream>


racing::Points::Points()
{
	coordX_ = SetRandCoord();
	coordY_ = 0;
}

int racing::Points::SetRandCoord()
{
	return rand() % 18;
}
