#include "framework.h"
#include "ShootingGame_2022_03_18.h"

void Random::Init()
{
	srand(time(nullptr));
}

int Random::Range(int min, int max)
{
	int r  = rand() % (max - min) + min;
	return r;
}
