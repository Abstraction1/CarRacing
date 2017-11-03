#pragma once
#include "Const.h"

using namespace constant;

namespace racing
{
	class CarEnemy
	{
	public:
		CarEnemy();
		inline int GetX() const;
		inline int GetY() const;
		void CarEnemyInit(const int& coordX, const int& coordY,
			char track[TRACK_WIDTH][TRACK_HEIGHT]);
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
