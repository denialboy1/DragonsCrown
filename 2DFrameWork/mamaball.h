#pragma once
#include "bullet.h"

#define FRAMESPEED 2

class mamaball : public bullet
{
public:
	mamaball();
	~mamaball();

	HRESULT init();
	void update();
	void render();
	void release();

	//��Ʈ���� ��ġ
	void start(int x, int y, int shadowX, int shadowY);
};

