#pragma once
#include "attackSkill.h"

#define FRAME_TIME   4
#define GRAVITY_TIME 200
class gravity : public attackSkill
{
private:
	int _gravityTime;
public:
	gravity();
	~gravity();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x, float y, float shadowX, float shadowY);
	float getShadowY(){ return _shadowY; }
	RECT getRcShadow(){ return _rcShadow; }
};

