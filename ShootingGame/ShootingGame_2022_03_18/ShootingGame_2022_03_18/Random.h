#pragma once
class Random
{
private:
public:
	//랜덤씨드 초기화 함수//
	static void Init();

	//정수 랜덤 발생함수//
	static int Range(int min, int max);
};

