//#include "Track.h"
#include "Obstacles.h"
#include "Const.h"

int main()
{
	/*racing::Track game;*/
	//game.Run();
	
	racing::Obstacles* obst[constant::OBSTACLES_NUMBER];

	obst[constant::OBSTACLES_HOLE] = new racing::Hole;
	obst[constant::OBSTACLES_HOLE]->info();
	system("pause");

	return 0;
}