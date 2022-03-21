#include "ShootingGame_2022_03_18.h"

float Time::startTime = 0;
float Time::endTime   = 0;
float Time::deltaTime = 0;

void Time::Init()
{
	startTime = GetTickCount64() / 1000.0;
	endTime = 0;
	deltaTime = 0;
}

void Time::Update()
{
	endTime = GetTickCount64() / 1000.0;
	deltaTime = endTime - startTime;
	startTime = GetTickCount64() / 1000.0;
}