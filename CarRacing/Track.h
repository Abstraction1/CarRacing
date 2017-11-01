#pragma once

#include "Player.h"
#include "Points.h"
#include "Obstacle.h"
#include <conio.h>
#include "Const.h"

namespace racing
{
	class Track
	{
	public:
		Track();
		void Print();
		void Logic();
		void GameCreater();
		void Run();
		void Input();
		void clearScreen();
		
	private:
		char area[constant::TRACK_WIDTH][constant::TRACK_HEIGHT];
		
		racing::Player* player_;
		racing::Points* points_;
		racing::Obstacle* obst_;

		constant::e_direction DIR;

		bool isGameOver;

		int speed_;
		int pointsCount_;
		
		int playX_;
		int playY_;
		
		int pointsX_;
		int pointsY_;
		
		int obstX_;
		int obstY_;
	};
}