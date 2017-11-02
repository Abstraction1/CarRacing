#pragma once

#include "Player.h"
#include "Cash.h"
#include "CarEnemy.h"
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
		racing::Cash* cash_;
		racing::CarEnemy* carEnemy_;

		constant::e_direction DIR;

		bool isGameOver;

		int speed_;
		int pointsCount_;
		
		int playerX_;
		int playerY_;
		
		int cashX_;
		int cashY_;
		
		int carEnemyX_;
		int carEnemyY_;
	};
}