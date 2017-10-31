#pragma once

const char PLAYER_CENTR_SYMB = 'X';
const char PLAYER_BOARD_SYMB = '|';
const char PLAYER_WHEELS_SYMB = 'o';

const int PLAYER_STEP = 1;
const int PLAYER_SPEED_CHANGER = 25;
const int PLAYER_START_COORD_X = 16;
const int PLAYER_START_COORD_Y = 16;

const int PLAYER_MAX_X = 16;
const int PLAYER_MIN_X = 2;

namespace racing
{
	class Player
	{
	public:
		Player();
		inline int GetX() const;
		inline int GetY() const;
		void SetX(const int coordX);
	private:
		int coordX_;
		int coordY_;
	};
}

inline racing::Player::Player()
{
	coordX_ = PLAYER_START_COORD_X;
	coordY_ = PLAYER_START_COORD_Y;
}

inline int racing::Player::GetX() const
{
	return coordX_;
}

inline int racing::Player::GetY() const
{
	return coordY_;
}

inline void racing::Player::SetX(const int coordX)
{
	coordX_ = coordX;
}



