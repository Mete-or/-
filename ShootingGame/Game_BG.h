#pragma once
#include "Sprite.h"


class Game_BG : public Sprite 
{
private:

public:
	Game_BG(float px, float py);
	virtual ~Game_BG();
	

	//가상함수 오버라이딩//
	void Start();
	void Update();
	
};

