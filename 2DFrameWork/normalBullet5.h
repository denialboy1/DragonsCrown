#pragma once
#include "bulletPF.h"

class normalBullet5 : public bulletPF
{
private:
	bool _isAttack;

public:
	normalBullet5();
	~normalBullet5();

	HRESULT init();
	void update();
	void render();
	void release();

	void fire(float x, float y, float shadowX, float shadowY, float angle, float speed, int frameX, int frameY);

};

