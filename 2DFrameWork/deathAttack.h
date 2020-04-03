#pragma once
#include "enemySkill.h"

#define RABBIT_FRAME_TIMER	10
class deathAttack : public enemySkill
{
public:
	int frameX;
	int frameTimer;
public:
	deathAttack();
	~deathAttack();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x, float y, float shadowX, float shadowY, int time);
};

