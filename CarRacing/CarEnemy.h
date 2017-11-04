#pragma once

#include "Const.h"

namespace racing
{
	class CarEnemy
	{
	public:
		CarEnemy();
		inline int GetX() const;
		inline int GetY() const;
		void CarEnemyCreator(const int& coordX, const int& coordY,
			char track[constant::TRACK_WIDTH][constant::TRACK_HEIGHT]);
	private:
		int coordX_;
		int coordY_;
	};

	inline int CarEnemy::GetX() const
	{
		return coordX_;
	}

	inline int CarEnemy::GetY() const
	{
		return coordY_;
	}
}
