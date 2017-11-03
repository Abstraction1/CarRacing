#include "CarEnemy.h"
#include "Const.h"

using namespace racing;
using namespace constant;

CarEnemy::CarEnemy() :
	coordX_(constant::CAR_ENEMY_START_X),
	coordY_(constant::CAR_ENEMY_MIN_Y)
	{ }

void CarEnemy::CarEnemyInit(const int & coordX, const int & coordY, 
	char track[TRACK_WIDTH][TRACK_HEIGHT])
{
	track[coordY][coordX] = CAR_ENEMY_CENTR_SYMB;
	track[coordY][coordX + 1] = CAR_ENEMY_BOARD_SYMB;
	track[coordY][coordX - 1] = CAR_ENEMY_CENTR_SYMB;
	track[coordY - 1][coordX + 1] = CAR_ENEMY_WHEELS_SYMB;
	track[coordY + 1][coordX + 1] = CAR_ENEMY_WHEELS_SYMB;
	track[coordY - 1][coordX - 1] = CAR_ENEMY_WHEELS_SYMB;
	track[coordY + 1][coordX - 1] = CAR_ENEMY_WHEELS_SYMB;
}
