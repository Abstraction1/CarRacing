#include "Cash.h"
#include "Const.h"

#include <iostream>
using namespace racing;
using namespace constant;

Cash::Cash() :
	coordX_(1),
	coordY_(0)
	{ }

void Cash::CashInit(const int & coordX, const int & coordY, char track[TRACK_WIDTH][TRACK_HEIGHT])
{
	track[coordY][coordX] = CASH_SYMB;
}