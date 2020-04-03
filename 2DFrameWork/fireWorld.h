#pragma once
#include "enemySkill.h"

#define FRAME_TIME 10
class fireWorld : public enemySkill
{
	int _frameY;
	int _timer;

	RECT _rcDeffence1;
	RECT _rcDeffence2;
public:
	fireWorld();
	~fireWorld();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x, float y, float shadowX, float shadowY,int timer);

	RECT getRcDeffence1(){ return _rcDeffence1; }
	RECT getRcDeffence2(){ return _rcDeffence2; }
};

