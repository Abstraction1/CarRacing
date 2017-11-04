#include <iostream>
#include "Player.h"
#include "Const.h"

using namespace racing;

Player::Player() :
	coordX_(constant::PLAYER_START_COORD_X),
	coordY_(constant::PLAYER_START_COORD_Y)
{ }

void Player::PlayerInit(const int& coordX, const int& coordY,
	char track[constant::TRACK_WIDTH][constant::TRACK_HEIGHT])
{
	track[coordY][coordX] = constant::PLAYER_CENTR_SYMB;
	track[coordY][coordX + 1] = constant::PLAYER_BOARD_SYMB;
	track[coordY][coordX - 1] = constant::PLAYER_BOARD_SYMB;

	track[coordY + 1][coordX + 1] = constant::PLAYER_WHEELS_SYMB;
	track[coordY - 1][coordX - 1] = constant::PLAYER_WHEELS_SYMB;
	track[coordY - 1][coordX + 1] = constant::PLAYER_WHEELS_SYMB;
	track[coordY + 1][coordX - 1] = constant::PLAYER_WHEELS_SYMB;
}