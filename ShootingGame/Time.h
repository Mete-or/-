#pragma once
#include "ShootingGame.h"

class Time
{
private:	
	static float startTime;
	static float endTime;
	
public:
	static void  Init();
	static void  Update();

	static float deltaTime;	
};

