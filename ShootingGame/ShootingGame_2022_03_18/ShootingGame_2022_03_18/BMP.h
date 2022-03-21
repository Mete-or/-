#pragma once

//게임에서 실제로 사용되는 이미지 정보 구조체//
struct Image
{
	int width;
	int height;
	unsigned int* rgb;
};

class Bitmap
{
private:
public:
	static void ReadBMP(const char* fileName, Image* img);
	static void DrawBMP(float px, float py, Image* img);
};


