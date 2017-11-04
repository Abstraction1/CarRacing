#include "CarEnemy.h"
#include "Const.h"

using namespace racing;

CarEnemy::CarEnemy() :
	coordX_(constant::CAR_ENEMY_START_X),
	coordY_(constant::CAR_ENEMY_MIN_Y)
{ }

void CarEnemy::CarEnemyInit(const int & coordX, const int & coordY,
	char track[constant::TRACK_WIDTH][constant::TRACK_HEIGHT])
{
	track[coordY][coordX] = constant::CAR_ENEMY_CENTR_SYMB;
	track[coordY][coordX + 1] = constant::CAR_ENEMY_BOARD_SYMB;
	track[coordY][coordX - 1] = constant::CAR_ENEMY_CENTR_SYMB;
	track[coordY - 1][coordX + 1] = constant::CAR_ENEMY_WHEELS_SYMB;
	track[coordY + 1][coordX + 1] = constant::CAR_ENEMY_WHEELS_SYMB;
	track[coordY - 1][coordX - 1] = constant::CAR_ENEMY_WHEELS_SYMB;
	track[coordY + 1][coordX - 1] = constant::CAR_ENEMY_WHEELS_SYMB;
}
