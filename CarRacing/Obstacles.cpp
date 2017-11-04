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

void Hole::ObstaclesCreator(const int & coordX, const int & coordY,
	char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT])
{
	arr[coordY][coordX + 1] = constant::OBSTACLES_HOLE_SYMB;
	arr[coordY][coordX + 2] = constant::OBSTACLES_HOLE_SYMB;
	arr[coordY][coordX + 3] = constant::OBSTACLES_HOLE_SYMB;
	arr[coordY + 1][coordX + 1] = constant::OBSTACLES_HOLE_SYMB;
	arr[coordY + 1][coordX + 2] = constant::OBSTACLES_HOLE_SYMB;
	arr[coordY + 1][coordX + 3] = constant::OBSTACLES_HOLE_SYMB;
	arr[coordY + 2][coordX + 1] = constant::OBSTACLES_HOLE_SYMB;
	arr[coordY + 2][coordX + 2] = constant::OBSTACLES_HOLE_SYMB;
	arr[coordY + 2][coordX + 3] = constant::OBSTACLES_HOLE_SYMB;
}

void Fence::info()
{
	std::cout << "FENCE";
}

void Fence::ObstaclesCreator(const int & coordX, const int & coordY,
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

void Stone::ObstaclesCreator(const int & coordX, const int & coordY,
	char arr[constant::TRACK_WIDTH][constant::TRACK_HEIGHT])
{
	for (int i = 0; i < constant::OBSTACLES_STONE_HEIGHT; i++)
	{
		for (int j = 0; j < constant::OBSTACLES_STONE_WIDTH; j++)
		{
			arr[coordY + j][coordX + i] = constant::OBSTACLES_STONE_SYMB;
		}
		std::cout << std::endl;
	}
}