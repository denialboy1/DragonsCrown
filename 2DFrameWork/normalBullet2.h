#pragma once
#include "bullet.h"

#define FRAMESPEED 3

class normalBullet2 : public bullet
{
public:
	normalBullet2();
	~normalBullet2();

	HRESULT init();
	void update();
	void render();
	void release();

	//��Ʈ���� ��ġ
	void start(int x, int y);
};

