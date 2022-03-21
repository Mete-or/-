
#include "ShootingGame.h"

void Bitmap::ReadBMP(const char* fileName, Image* img)
{
	//비트맵 구조체
	BITMAPFILEHEADER fileHeader; //비트맵 파일헤더
	BITMAPINFOHEADER infoHeader; //비트맵 인포헤더

	//비트맵(bmp) 파일 로드하기//
	FILE* stream;
	errno_t err;

	err = fopen_s(&stream, fileName, "rb");

	if (err == 0 && stream != nullptr)
	{
		//비트맵 파일헤더 구조체 로드하기//
		fread(&fileHeader, sizeof(BITMAPFILEHEADER), 1, stream);

		printf("--------비트맵 파일 헤더 구조체--------\n");
		printf("bfType : 0x%x\n", fileHeader.bfType);  //파일내부에서 bmp파일인지를 재확인하는 코드(매직코드)
		printf("bfSize : %d\n", fileHeader.bfSize);  //파일 크기
		printf("bfReserved1 : %d\n", fileHeader.bfReserved1); //사용안되는 예약
		printf("bfReserved2 : %d\n", fileHeader.bfReserved2); //사용안되는 예약
		printf("bfOffBits   : %d\n", fileHeader.bfOffBits);   //픽셀데이타 까지의 Offset(처음부터..떨어진 간격)


		//비트맵 인포헤더 구조체 로드하기//
		fread(&infoHeader, sizeof(BITMAPINFOHEADER), 1, stream);

		printf("------비트맵 인포 헤더 구조체 ------\n");
		printf("biWidth : %d\n", infoHeader.biWidth);
		printf("biHeight: %d\n", infoHeader.biHeight);
		printf("biBitCount : %d\n", infoHeader.biBitCount);

		//이미지 데이타(픽셀데이타) 로드하기//
		int length = infoHeader.biWidth * infoHeader.biHeight;
		unsigned int* rgb = new unsigned int[length];

		fread(rgb, sizeof(unsigned int), length, stream);

		//파일닫기
		fclose(stream);

		//이미지 구조체에..필요한 정보만 저장함//
		img->width = infoHeader.biWidth;
		img->height = infoHeader.biHeight;
		img->rgb = rgb;

	}
	else {
		printf("파일 열기 실패\n");
	}
}


void Bitmap::DrawBMP(float px, float py, Image* img)
{
	for (int y = 0; y < img->height; y++)
	{
		for (int x = 0; x < img->width; x++)
		{
			unsigned int pixel = img->rgb[y * img->width + x];
			SetPixel(x + px, y + py, pixel);
		}
	}
}

