#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class ObjectManager
{
private:
	static vector<GameObject*> gameObjects;
public:

	//게임 Instance 추가 및 제거 //
	static void Instantiate(GameObject* obj);
	static void Destroy(GameObject* obj);

	//게임 목록 업데이트 함수
	static void Update();

	//게임 목록 그리기
	static void Draw();

	//게임 목록 모두 삭제하기 함수
	static void Clear();
};

