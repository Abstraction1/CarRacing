#pragma once
#include "Const.h"

using namespace constant;

namespace racing
{
	class Player
	{
	public:
		Player();
		inline int GetX() const;
		inline int GetY() const;
		inline void SetX(const int coordX);
		void PlayerInit(const int& coordX, const int& coordY,
			char track[TRACK_WIDTH][TRACK_HEIGHT]);
	private:
		int coordX_;
		int coordY_;
	};

	inline int Player::GetX() const
	{
		return coordX_;
	}

	inline int Player::GetY() const
	{
		return coordY_;
	}

	inline void Player::SetX(const int coordX)
	{
		coordX_ = coordX;
	}
}

