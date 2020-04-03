#pragma once
#include "singletonBase.h"
#include "image.h"

class destroyPixelManager : public singletonBase<destroyPixelManager>
{
public:
	destroyPixelManager();
	~destroyPixelManager();

	// �ȼ�ũ���ı�(�ı��� ��ǥ, ĥ���� ����, ĥ�� �̹���)
	void destroyPixel(int x, int y, COLORREF rgb, image* img);
	//��ũ���ı�(�ı��� ��ǥ,ĥ���� ����, ĥ�� �̹���)
	void destroyEllipse(int x, int y, int width, int hiehgt, COLORREF rgb, image* img);
	//�簢��ũ���ı�(�ı��� ��ǥ,ĥ���� ����, ĥ�� �̹���)
	void destroyRect(int x, int y, int width, int height, COLORREF rgb, image* img);
};

