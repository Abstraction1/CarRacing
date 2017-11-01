#pragma once
#include "Const.h"

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

	inline int Points::GetX() const
	{
		return coordX_;
	}

	inline int Points::GetY() const
	{
		return coordY_;
	}
}