#pragma once

/*!
 * \file Const.h
 *
 * \author default
 * 
 *
 * Constant List
 */

namespace constant
{
	const int OBSTACLES_NUMBER = 3;
	const int OBSTACLES_HOLE = 0;
	const int OBSTACLES_FENCE = 1;
	const int OBSTACLES_STONE = 2;

	const char OBSTACLES_FENCE_SYMB = '#';
	const int OBSTACLES_FENCE_LENGTH = 5;

	const char CAR_ENEMY_CENTR_SYMB = 'X';
	const char CAR_ENEMY_BOARD_SYMB = '|';
	const char CAR_ENEMY_WHEELS_SYMB = 'o';
	const int CAR_ENEMY_STEP = 1;
	const int CAR_ENEMY_MAX_X = 16;
	const int CAR_ENEMY_MIN_X = 2;
	const int CAR_ENEMY_START_X = 10;
	const int CAR_ENEMY_MAX_Y = 17;
	const int CAR_ENEMY_MIN_Y = 1;

	const char PLAYER_CENTR_SYMB = 'X';
	const char PLAYER_BOARD_SYMB = '|';
	const char PLAYER_WHEELS_SYMB = 'o';
	const int PLAYER_STEP = 1;
	const int PLAYER_SPEED_CHANGER = 5;
	const int PLAYER_START_COORD_X = 16;
	const int PLAYER_START_COORD_Y = 16;
	const int PLAYER_MAX_X = 16;
	const int PLAYER_MIN_X = 2;

	const char POINTS_SYMB = '$';
	const int POINTS_START_X = 10;
	const int POINTS_MIN_X = 2;
	const int POINTS_MAX_X = 17;
	const int POINTS_MAX_Y = 18;
	const int POINTS_SPEED = 2;
	const int POINTS_START_COUNT = 0;

	const int TRACK_WIDTH = 20;
	const int TRACK_HEIGHT = 20;
	const int TRACK_CURRENT_HEIGHT = 18;
	const int SPEED_INIT = 150;

	const char TRACK_BOARD_SYMB = '|';
	const char TRACK_FREE_SPACE_SYMB = ' ';
	const char EXIT_GAME = 27;

	enum e_direction
	{
		DIR_STOP,
		DIR_UP,
		DIR_DOWN,
		DIR_LEFT,
		DIR_RIGHT,
		DIR_EXIT
	};
}