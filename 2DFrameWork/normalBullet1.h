#pragma once
#include "bullet.h"
#define FRAMESPEED 2

class normalBullet1 : public bullet
{
private:

public:
	normalBullet1();
	~normalBullet1();

	HRESULT init();
	void update();
	void render();
	void release();

	//터트리는 위치
	void start(int x, int y);

public:


};

