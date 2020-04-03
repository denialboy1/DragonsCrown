#pragma once
#include "bulletPF.h"

class normalBullet4 : public bulletPF
{
private:
	bool _isAttack;
public:
	normalBullet4();
	~normalBullet4();

	HRESULT init();
	void update();
	void render();
	void release();

	void fire(float x, float y, float shadowX,float shadowY,float angle, float speed, int frameX, int frameY);

};

