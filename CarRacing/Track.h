#pragma once

#include "Player.h"
#include "Points.h"
#include "Obstacle.h"
#include <conio.h>


const int TRACK_WIDTH = 20;
const int TRACK_HEIGHT = 20;
const int TRACK_CURRENT_HEIGHT = 18;

const char TRACK_BOARD_SYMB = '|';
const char TRACK_FREE_SPACE_SYMB = ' ';

enum e_direction
{
	DIR_STOP = 0,
	DIR_UP,
	DIR_DOWN,
	DIR_LEFT,
	DIR_RIGHT
};

namespace racing
{
	class Track
	{
	public:
		Track();
		void Initialization();
		void Print();
		void Logic();
		void GameCreater();
		void Run();
		void Input();
	private:
		char area[TRACK_WIDTH][TRACK_HEIGHT];
		
		racing::Player* player_;
		racing::Points* points_;
		racing::Obstacle* obst_;

		e_direction dir;

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