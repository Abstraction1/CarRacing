#pragma once
#include <iostream>
#include "Const.h"

namespace racing
{
	class Obstacles
	{
	public:
		virtual int GetX() = 0;
		virtual int GetY() = 0;
		virtual void SetX(int coordX) = 0;
		virtual void SetY(int coordY) = 0;
		virtual void info()
		{
			std::cout << "base";
		}
		virtual void DrawObstacle(const int& width, const int& height,
			char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT]) = 0;
	};

	class Hole : public Obstacles
	{
	public:
		Hole();
		inline int GetX();
		inline int GetY();
		inline void SetX(int coordX);
		inline void SetY(int coordY);
		void info();
		void DrawObstacle(const int& width, const int& height,
			char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT]);
	private:
		int coordX_;
		int coordY_;
	};

	class Fence :public Obstacles
	{
	public:
		Fence();
		inline int GetX();
		inline int GetY();
		inline void SetX(int coordX);
		inline void SetY(int coordY);
		void info();
		void DrawObstacle(const int& width, const int& height,
			char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT]);
	private:
		int coordX_;
		int coordY_;
	};

	class Stone : public Obstacles
	{
	public:
		Stone();
		inline int GetX();
		inline int GetY();
		inline void SetX(int coordX);
		inline void SetY(int coordY);
		void DrawObstacle(const int& width, const int& height,
			char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT]);
		void info();
	private:
		int coordX_;
		int coordY_;
	};

	inline int Hole::GetX()
	{
		return coordX_;
	}

	inline int Hole::GetY()
	{
		return coordY_;
	}

	inline int Fence::GetX()
	{
		return coordX_;
	}

	inline int Fence::GetY()
	{
		return coordY_;
	}

	inline int Stone::GetX()
	{
		return coordX_;
	}

	inline int Stone::GetY()
	{
		return coordY_;
	}

	inline void Hole::SetX(int coordX)
	{
		coordX_ = coordX;
	}

	inline void Hole::SetY(int coordY)
	{
		coordY_ = coordY_;
	}

	inline void Fence::SetX(int coordX)
	{
		coordX_ = coordX;
	}

	inline void Fence::SetY(int coordY)
	{
		coordY_ = coordY_;
	}

	inline void Stone::SetX(int coordX)
	{
		coordX_ = coordX;
	}

	inline void Stone::SetY(int coordY)
	{
		coordY_ = coordY_;
	}
}