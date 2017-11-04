#pragma once

#include "Player.h"
#include "Cash.h"
#include "CarEnemy.h"
#include "Obstacles.h"
#include "Const.h"

#include <conio.h>

using namespace racing;

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
		void TrackCreator();
	private:
		char area[constant::TRACK_WIDTH][constant::TRACK_HEIGHT];

		Player* player_;
		Cash* cash_;
		CarEnemy* carEnemy_;
		Obstacles* obstacles_[constant::OBSTACLES_NUMBER];

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

		int obstaclesX_;
		int obstaclesY_;
	};
}