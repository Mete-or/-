#pragma once
#include "Sprite.h"


class Game_BG : public Sprite 
{
private:

public:
	Game_BG(float px, float py);
	virtual ~Game_BG();
	

	//�����Լ� �������̵�//
	void Start();
	void Update();
	
};

