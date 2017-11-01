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
	const char OBSTACLE_CENTR_SYMB = 'X';
	const char OBSTACLE_BOARD_SYMB = '|';
	const char OBSTACLE_WHEELS_SYMB = 'o';
	const int OBSTACLE_STEP = 1;
	const int OBSTACLE_MAX_X = 16;
	const int OBSTACLE_MIN_X = 2;
	const int OBSTACLE_START_X = 10;
	const int OBSTACLE_MAX_Y = 17;
	const int OBSTACLE_MIN_Y = 1;

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