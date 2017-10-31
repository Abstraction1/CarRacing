#pragma once

const char POINTS_SYMB = '$';
const int POINTS_MIN_X = 2;
const int POINTS_MAX_X = 17;
const int POINTS_MAX_Y = 18;
const int POINTS_SPEED = 2;

namespace racing
{
	class Points
	{
	public:
		Points();
		inline int GetX() const;
		inline int GetY() const;
		int SetRandCoord();
	private:
		int coordX_;
		int coordY_;
	};
}

inline int racing::Points::GetX() const
{
	return coordX_;
}

inline int racing::Points::GetY() const
{
	return coordY_;
}