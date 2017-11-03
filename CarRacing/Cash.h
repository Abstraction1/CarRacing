#pragma once
#include "Const.h"

using namespace constant;

namespace racing
{
	class Cash
	{
	public:
		Cash();
		inline int GetX() const;
		inline int GetY() const;
		void CashInit(const int& coordX, const int& coordY,
			char track[TRACK_WIDTH][TRACK_HEIGHT]);
	private:
		int coordX_;
		int coordY_;
	};

	inline int Cash::GetX() const
	{
		return coordX_;
	}

	inline int Cash::GetY() const
	{
		return coordY_;
	}
}