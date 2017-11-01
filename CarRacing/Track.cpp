#include "Track.h"
#include "Player.h"
#include "Points.h"
#include "Obstacle.h"
#include "Const.h"

#include <iostream>
#include <Windows.h>
#include <random>

using namespace racing;

Track::Track() :
	isGameOver(false),
	pointsCount_(constant::POINTS_START_COUNT),
	speed_(constant::SPEED_INIT),
	DIR(constant::DIR_STOP),

	player_(new racing::Player),
	points_(new racing::Points),
	obst_(new racing::Obstacle),

	playX_(player_->GetX()),
	playY_(player_->GetY()),

	pointsX_(points_->GetX()),
	pointsY_(points_->GetY()),

	obstX_(obst_->GetX()),
	obstY_(obst_->GetY())
	{ }

void Track::GameCreater()
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

	area[playY_][playX_] = constant::PLAYER_CENTR_SYMB;
	area[playY_][playX_ + 1] = constant::PLAYER_BOARD_SYMB;
	area[playY_][playX_ - 1] = constant::PLAYER_BOARD_SYMB;
	area[playY_ - 1][playX_ + 1] = constant::PLAYER_WHEELS_SYMB;
	area[playY_ + 1][playX_ + 1] = constant::PLAYER_WHEELS_SYMB;
	area[playY_ - 1][playX_ - 1] = constant::PLAYER_WHEELS_SYMB;
	area[playY_ + 1][playX_ - 1] = constant::PLAYER_WHEELS_SYMB;

	area[pointsY_][pointsX_] = constant::POINTS_SYMB;

	area[obstY_][obstX_] = constant::OBSTACLE_CENTR_SYMB;
	area[obstY_][obstX_ + 1] = constant::OBSTACLE_BOARD_SYMB;
	area[obstY_][obstX_ - 1] = constant::OBSTACLE_BOARD_SYMB;
	area[obstY_ - 1][obstX_ + 1] = constant::OBSTACLE_WHEELS_SYMB;
	area[obstY_ + 1][obstX_ + 1] = constant::OBSTACLE_WHEELS_SYMB;
	area[obstY_ - 1][obstX_ - 1] = constant::OBSTACLE_WHEELS_SYMB;
	area[obstY_ + 1][obstX_ - 1] = constant::OBSTACLE_WHEELS_SYMB;
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
	std::cout << "points =  " << pointsCount_ << '\n';
	std::cout << "Point X " << pointsX_ << '\n';
	std::cout << "Point Y " << pointsY_ << '\n';
	std::cout << "Obstacle X " << obstX_ << '\n';
	std::cout << "Obstacle X " << obstY_ << '\n';
	std::cout << "Obstacle Y " << speed_ << '\n';
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
	std::uniform_int_distribution<> GenForPointXcoord(constant::POINTS_MIN_X, 
		constant::POINTS_MAX_X);
	std::uniform_int_distribution<> GenForObstXcoord(constant::OBSTACLE_MIN_X, 
		constant::OBSTACLE_MAX_X);

	switch (DIR)
	{
	case constant::DIR_LEFT:
		playX_ -= constant::PLAYER_STEP;
		player_->SetX(playX_);
		DIR = constant::DIR_STOP;
		break;
	case constant::DIR_RIGHT:
		playX_ += constant::PLAYER_STEP;
		player_->SetX(playX_);
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

	if (playX_ < constant::PLAYER_MIN_X)
	{
		playX_ = constant::PLAYER_MIN_X;
	}
	else if (playX_ > constant::PLAYER_MAX_X)
	{
		playX_ = constant::PLAYER_MAX_X;
	}

	pointsY_+= constant::POINTS_SPEED;
	if (pointsY_ > constant::POINTS_MAX_Y)
	{
		pointsX_ = GenForPointXcoord(generator);
		pointsY_ = 0;
	}

	bool isCatchLeft = pointsY_ == playY_ && pointsX_ == playX_ - 1;
	bool isCatchRight = pointsY_ == playY_ && pointsX_ == playX_ + 1;
	bool isCatchCentr = pointsY_ == playY_ && pointsX_ == playX_;

	if (isCatchLeft || isCatchRight || isCatchCentr)
	{
		pointsCount_++;
		pointsX_ = GenForPointXcoord(generator);
		pointsY_ = 0;
	}
	
	obstY_++;
	if (obstY_ > constant::OBSTACLE_MAX_Y)
	{
		obstX_ = GenForObstXcoord(generator);
		obstY_ = constant::OBSTACLE_MIN_Y;
	}
	
	/*!
	 * \file Track.cpp
	 *
	 * \author default
	 * 
	 *
	 * Need to fix bug 
	 */

	bool isCrashCentr = playY_ + 1 == obstY_ - 1;
	if (isCrashCentr)
	{
		isGameOver = true;
		std::cout << "CRASH!";
		system("pause");
	}
}