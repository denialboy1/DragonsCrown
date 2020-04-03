#pragma once
#include "enemySkill.h"

#define FIRERAIN_SPEED 10
#define FRAME_TIME 7
#define FIRE_FRAME_TIME 7
#define FIRE_TIME 250
class fireRain : public enemySkill
{
public : 
	int _timer;
	int _fireFrameTimer;
	int _fireTimer;
	bool _isFireRainEnd;

	int _fireFrameX;
public:
	fireRain();
	~fireRain();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x, float y, float shadowX, float shadowY,int time);
};

