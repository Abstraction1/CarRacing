#include "Track.h"
#include "Player.h"
#include "Cash.h"
#include "CarEnemy.h"
#include "Const.h"

#include <iostream>
#include <Windows.h>
#include <random>
#include <ctime>

using namespace racing;

Track::Track() :
	isGameOver(false),
	pointsCount_(constant::CASH_START_COUNT),
	speed_(constant::SPEED_INIT),
	DIR(constant::DIR_STOP),

	player_(new Player),
	cash_(new Cash),
	carEnemy_(new CarEnemy),

	playerX_(player_->GetX()),
	playerY_(player_->GetY()),

	cashX_(cash_->GetX()),
	cashY_(cash_->GetY()),

	carEnemyX_(carEnemy_->GetX()),
	carEnemyY_(carEnemy_->GetY())
{ }

void Track::TrackCreator()
{
	for (auto & i : area)
	{
		for (char & j : i)
		{
			i[0] = constant::TRACK_BOARD_SYMB;
			i[constant::TRACK_CURRENT_HEIGHT] = constant::TRACK_BOARD_SYMB;
			j = constant::TRACK_FREE_SPACE_SYMB;
		}
	}
}

void Track::GameCreater()
{
	TrackCreator();
	player_->PlayerCreator(playerX_, playerY_, area);
	cash_->CashCreator(cashX_, cashY_, area);
	carEnemy_->CarEnemyCreator(carEnemyX_, carEnemyY_, area);
}

void Track::Print()
{
	for (auto & i : area)
	{
		for (char j : i)
		{
			std::cout << j;
		}
		std::cout << std::endl;
	}
}

void Track::Run()
{
	while (!isGameOver)
	{
		Input();
		Logic();
		GameCreater();
		Print();
		Sleep(speed_);
		clearScreen();
	}
}

void Track::Input()
{
	while (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			DIR = constant::DIR_LEFT;
			break;
		case 'd':
			DIR = constant::DIR_RIGHT;
			break;
		case 'w':
			DIR = constant::DIR_UP;
			break;
		case 's':
			DIR = constant::DIR_DOWN;
			break;
		case constant::EXIT_GAME:
			DIR = constant::DIR_EXIT;
		}
	}
}

void Track::clearScreen()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

void Track::Logic()
{
	std::random_device random_device;
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> GenForPointXcoord(constant::CASH_MIN_X,
		constant::CASH_MAX_X);
	std::uniform_int_distribution<> GenForObstXcoord(constant::CAR_ENEMY_MIN_X,
		constant::CAR_ENEMY_MAX_X);

	switch (DIR)
	{
	case constant::DIR_LEFT:
		playerX_ -= constant::PLAYER_STEP;
		player_->SetX(playerX_);
		DIR = constant::DIR_STOP;
		break;
	case constant::DIR_RIGHT:
		playerX_ += constant::PLAYER_STEP;
		player_->SetX(playerX_);
		DIR = constant::DIR_STOP;
		break;
	case constant::DIR_UP:
		speed_ = speed_ - constant::PLAYER_SPEED_CHANGER;
		DIR = constant::DIR_STOP;
		break;
	case constant::DIR_DOWN:
		speed_ = speed_ + constant::PLAYER_SPEED_CHANGER;
		DIR = constant::DIR_STOP;
		break;
	case constant::DIR_EXIT:
		isGameOver = true;
	}

	/*!
	 * \file Track.cpp
	 *
	 * \author defa`ult
	 *
	 *
	 * Player Board's
	 */

	if (playerX_ < constant::PLAYER_MIN_X)
	{
		playerX_ = constant::PLAYER_MIN_X;
	}
	else if (playerX_ > constant::PLAYER_MAX_X)
	{
		playerX_ = constant::PLAYER_MAX_X;
	}

	/*!
	 * \file Track.cpp
	 *
	 * \author default
	 *
	 *
	 * Cash Catcher
	 */

	cashY_ += constant::CASH_SPEED;
	if (cashY_ > constant::CASH_MAX_Y)
	{
		cashX_ = GenForPointXcoord(generator);
		cashY_ = 0;
	}

	bool isCatchLeft = cashY_ == playerY_ && cashX_ == playerX_ - 1;
	bool isCatchRight = cashY_ == playerY_ && cashX_ == playerX_ + 1;
	bool isCatchCentr = cashY_ == playerY_ && cashX_ == playerX_;

	if (isCatchLeft || isCatchRight || isCatchCentr)
	{
		pointsCount_++;
		cashX_ = GenForPointXcoord(generator);
		cashY_ = 0;
	}

	//carEnemyY_++;
	//if (carEnemyY_ > constant::CAR_ENEMY_MAX_Y)
	//{
	//	carEnemyX_ = GenForObstXcoord(generator);
	//	carEnemyY_ = constant::CAR_ENEMY_MIN_Y;
	//}

	/*!
	 * \file Track.cpp
	 *
	 * \author default
	 *
	 *
	 * fixed
	 */

	 /*bool isCrashCentr = playerY_ - 1 == carEnemyY_ + 1 && playerX_ == carEnemyX_;
	 bool isCrashLeft = playerY_ - 1 == carEnemyY_ + 1 && playerX_ - 1 == carEnemyX_ - 1;
	 bool isCrashRight = playerY_ - 1 == carEnemyY_ + 1 && playerX_ + 1 == carEnemyX_ - 1;


	 if (isCrashCentr || isCrashLeft || isCrashRight)
	 {
		 isGameOver = true;
		 std::cout << "CRASH!";
		 system("pause");
	 }*/
}