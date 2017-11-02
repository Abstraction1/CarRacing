//#include "Track.h"
#include "Obstacles.h"
#include "Const.h"
#include <iostream>

using namespace constant;

int main()
{
	/*racing::Track game;*/
	//game.Run();
	
	char a[20][20];

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			a[i][0] = '|';
			a[i][18] = '|';
			a[i][j] = ' ';
		}
	}

	racing::Obstacles* obst[OBSTACLES_NUMBER];
	obst[OBSTACLES_FENCE] = new racing::Fence;
	
	int fenceX_ = obst[OBSTACLES_FENCE]->GetX();
	int fenceY_ = obst[OBSTACLES_FENCE]->GetY();

	obst[OBSTACLES_FENCE]->DrawObstacle(fenceY_, fenceX_, a);
	
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			std::cout << a[i][j];
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}