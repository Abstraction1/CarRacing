#pragma once

namespace racing
{
	class Player
	{
	public:
		Player();
		inline int GetX() const;
		inline int GetY() const;
		inline void SetX(const int coordX);
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

