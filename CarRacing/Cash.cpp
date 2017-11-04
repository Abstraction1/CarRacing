#include "Cash.h"
#include "Const.h"

#include <iostream>

using namespace racing;

Cash::Cash() :
	coordX_(1),
	coordY_(0)
{ }

void Cash::CashCreator(const int & coordX, const int & coordY,
	char track[constant::TRACK_WIDTH][constant::TRACK_HEIGHT])
{
	track[coordY][coordX] = constant::CASH_SYMB;
}