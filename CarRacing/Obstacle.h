#pragma once

const char OBSTACLE_CENTR_SYMB = 'X';
const char OBSTACLE_BOARD_SYMB = '|';
const char OBSTACLE_WHEELS_SYMB = 'o';

const int OBSTACLE_STEP = 1;

const int OBSTACLE_MAX_X = 16;
const int OBSTACLE_MIN_X = 2;

const int OBSTACLE_MAX_Y = 17;
const int OBSTACLE_MIN_Y = 1;

namespace racing
{
	class Obstacle
	{
	public:
		Obstacle();
		inline int GetX() const;
		inline int GetY() const;
	private:
		int coordX_;
		int coordY_;
	};
}

inline int racing::Obstacle::GetX() const
{
	return coordX_;
}

inline int racing::Obstacle::GetY() const
{
	return coordY_;
}