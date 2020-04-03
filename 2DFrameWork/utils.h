#pragma once
#include <cmath>

#define DEG_TO_RAD 0.017453f //1도의 라디안 값
#define PI 3.141592654f
#define PI2 (PI * 2)

//프레임 이미지 회전 시킬때
//총 프레임의 절반 프레임 만큼이 필요함
#define PI8 float(PI / 8.0f)
#define PI16 float(PI / 16.0f)
#define PI18 float(PI / 18.0f)
#define PI32 float(PI / 32.0f)
#define PI36 float(PI / 36.0f)
#define PI64 float(PI / 64.0f)
#define PI128 float(PI / 128.0f)


//픽셀 충돌 용
#define X_AXIS 0
#define Y_AXIS 1

#define FLOAT_EPSILON 0.001f //실수의 가장 작은 단위를 그리스어로 엡실론 입실론이라고 함

namespace DENIALBOY_UTIL	//원하는대로
{
	//거리 가져오는 공식
	float getDistance(float startX, float startY, float endX, float endY);

	//각도 가져오는 공식
	float getAngle(float x1, float y1, float x2, float y2);

	//미니맵 만들기
	void minimapRender(HDC hdc, int rate, int bgWidth, int bgHeight);

	//이미지 흑백으로 만들기
	void MakeBlackAndWhite(HDC hdc, int startX, int startY, int endX, int endY);

	//픽셀 충돌
	bool pixelCollision(char* imgKey, int axis, int x, int y, int scale1, int scale2, COLORREF color0, int* coordinate_of_pixel);

	//보여지는 화면에서의 픽셀 충돌
	bool pixelCollision(HDC hdc, int axis, int x, int y, int scale1, int scale2, COLORREF color0, int* coordinate_of_pixel);

}