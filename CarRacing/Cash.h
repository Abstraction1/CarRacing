#pragma once
#include "Const.h"

namespace racing
{
	class Cash
	{
	public:
		Cash();
		inline int GetX() const;
		inline int GetY() const;
		int SetRandCoord();
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