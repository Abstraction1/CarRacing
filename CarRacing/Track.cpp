#include "Track.h"
#include "Player.h"
#include "Points.h"
#include "Obstacle.h"

#include <iostream>
#include <Windows.h>
#include <random>

racing::Track::Track()
{
	Initialization();
}

void racing::Track::GameCreater()
{
	for (auto & i : area)
	{
		for (char & j : i)
		{
			i[0] = TRACK_BOARD_SYMB;
			i[TRACK_CURRENT_HEIGHT] = TRACK_BOARD_SYMB;
			j = TRACK_FREE_SPACE_SYMB;
		}
	}

	area[playY_][playX_] = PLAYER_CENTR_SYMB;
	area[playY_][playX_ + 1] = PLAYER_BOARD_SYMB;
	area[playY_][playX_ - 1] = PLAYER_BOARD_SYMB;
	area[playY_ - 1][playX_ + 1] = PLAYER_WHEELS_SYMB;
	area[playY_ + 1][playX_ + 1] = PLAYER_WHEELS_SYMB;
	area[playY_ - 1][playX_ - 1] = PLAYER_WHEELS_SYMB;
	area[playY_ + 1][playX_ - 1] = PLAYER_WHEELS_SYMB;

	area[pointsY_][pointsX_] = POINTS_SYMB;

	area[obstY_][obstX_] = OBSTACLE_CENTR_SYMB;
	area[obstY_][obstX_ + 1] = OBSTACLE_BOARD_SYMB;
	area[obstY_][obstX_ - 1] = OBSTACLE_BOARD_SYMB;
	area[obstY_ - 1][obstX_ + 1] = OBSTACLE_WHEELS_SYMB;
	area[obstY_ + 1][obstX_ + 1] = OBSTACLE_WHEELS_SYMB;
	area[obstY_ - 1][obstX_ - 1] = OBSTACLE_WHEELS_SYMB;
	area[obstY_ + 1][obstX_ - 1] = OBSTACLE_WHEELS_SYMB;
}

void racing::Track::Initialization()
{
	pointsCount_ = 0;
	speed_ = 100;
	player_ = new racing::Player;
	points_ = new racing::Points;
	obst_ = new racing::Obstacle;

	dir = DIR_STOP;

	playX_ = player_->GetX();
	playY_ = player_->GetY();	

	pointsX_ = points_->GetX();
	pointsY_ = points_->GetY();

	obstX_ = obst_->GetX();
	obstY_ = obst_->GetY();
}

void racing::Track::Print()
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
	std::cout << "Obst X " << obstX_ << '\n';
	std::cout << "Obst Y " << obstY_ << '\n';
	std::cout << "Obst Y " << speed_ << '\n';
}

void racing::Track::Run()
{	
	Initialization();
	while (true)
	{
		Input();
		Logic();
		GameCreater();
		Print();
		Sleep(speed_);
		system("cls");
	}
}

void racing::Track::Input()
{
	while (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			dir = DIR_LEFT;
			break;
		case 'd':
			dir = DIR_RIGHT;
			break;
		case 'w':
			dir = DIR_UP;
			break;
		case 's':
			dir = DIR_DOWN;
			break;
		}
	}
}

void racing::Track::Logic()
{
	std::random_device random_device; 
	std::mt19937 generator(random_device());
	std::uniform_int_distribution<> GenForPointXcoord(POINTS_MIN_X, POINTS_MAX_X);
	std::uniform_int_distribution<> GenForObstXcoord(OBSTACLE_MIN_X, OBSTACLE_MAX_X);

	switch (dir)
	{
	case DIR_LEFT:
		playX_ -= PLAYER_STEP;
		player_->SetX(playX_);
		dir = DIR_STOP;
		break;
	case DIR_RIGHT:
		playX_ += PLAYER_STEP;
		player_->SetX(playX_);
		dir = DIR_STOP;
		break;
	case DIR_UP:
		speed_ = speed_ - PLAYER_SPEED_CHANGER;
		dir = DIR_STOP;
	case DIR_DOWN:
		speed_ = speed_ + PLAYER_SPEED_CHANGER;
		dir = DIR_STOP;
		break;
	}

	if (playX_ < PLAYER_MIN_X)
	{
		playX_ = PLAYER_MIN_X;
	}
	else if (playX_ > PLAYER_MAX_X)
	{
		playX_ = PLAYER_MAX_X;
	}

	pointsY_+= POINTS_SPEED;
	if (pointsY_ > POINTS_MAX_Y)
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
	
	if (obstY_ > OBSTACLE_MAX_Y)
	{
		obstX_ = GenForObstXcoord(generator);
		obstY_ = OBSTACLE_MIN_Y;
	}


}