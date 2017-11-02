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

void Fence::info()
{
	std::cout << "FENCE";
}

void Stone::info()
{
	std::cout << "STONE";
}