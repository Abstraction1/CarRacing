#pragma once

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

	inline int Obstacle::GetX() const
	{
		return coordX_;
	}

	inline int Obstacle::GetY() const
	{
		return coordY_;
	}
}
