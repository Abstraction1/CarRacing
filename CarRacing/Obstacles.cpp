#include "Obstacles.h"
using namespace racing;

Hole::Hole() :
	coordX_(1),
	coordY_(1)
	{ }

Fence::Fence() : 
	coordX_(3),
	coordY_(3)
	{ }

Stone::Stone() :
	coordX_(5),
	coordY_(5)
	{ }

void Hole::info()
{
	std::cout << "HOLE";
}

void racing::Hole::DrawObstacle(const int & coordX, const int & coordY, 
	char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT])
{
	
}

void Fence::info()
{
	std::cout << "FENCE";
}

void racing::Fence::DrawObstacle(const int & coordX, const int & coordY,
	char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT])
{
	for (int i = 0; i < constant::OBSTACLES_FENCE_LENGTH; i++)
	{
		arr[coordY][coordX + i] = constant::OBSTACLES_FENCE_SYMB;
	}
}

void Stone::info()
{
	std::cout << "STONE";
}

void racing::Stone::DrawObstacle(const int & coordX, const int & coordY,
	char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT])
{
	
}