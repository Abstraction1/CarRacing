#pragma once

namespace racing
{
	class CarEnemy
	{
	public:
		CarEnemy();
		inline int GetX() const;
		inline int GetY() const;
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
