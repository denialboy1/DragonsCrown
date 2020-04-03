#pragma once
#include <cmath>

#define DEG_TO_RAD 0.017453f //1���� ���� ��
#define PI 3.141592654f
#define PI2 (PI * 2)

//������ �̹��� ȸ�� ��ų��
//�� �������� ���� ������ ��ŭ�� �ʿ���
#define PI8 float(PI / 8.0f)
#define PI16 float(PI / 16.0f)
#define PI18 float(PI / 18.0f)
#define PI32 float(PI / 32.0f)
#define PI36 float(PI / 36.0f)
#define PI64 float(PI / 64.0f)
#define PI128 float(PI / 128.0f)


//�ȼ� �浹 ��
#define X_AXIS 0
#define Y_AXIS 1

#define FLOAT_EPSILON 0.001f //�Ǽ��� ���� ���� ������ �׸������ ���Ƿ� �ԽǷ��̶�� ��

namespace DENIALBOY_UTIL	//���ϴ´��
{
	//�Ÿ� �������� ����
	float getDistance(float startX, float startY, float endX, float endY);

	//���� �������� ����
	float getAngle(float x1, float y1, float x2, float y2);

	//�̴ϸ� �����
	void minimapRender(HDC hdc, int rate, int bgWidth, int bgHeight);

	//�̹��� ������� �����
	void MakeBlackAndWhite(HDC hdc, int startX, int startY, int endX, int endY);

	//�ȼ� �浹
	bool pixelCollision(char* imgKey, int axis, int x, int y, int scale1, int scale2, COLORREF color0, int* coordinate_of_pixel);

	//�������� ȭ�鿡���� �ȼ� �浹
	bool pixelCollision(HDC hdc, int axis, int x, int y, int scale1, int scale2, COLORREF color0, int* coordinate_of_pixel);

}