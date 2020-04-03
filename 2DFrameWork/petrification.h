#pragma once
#include "attackSkill.h"

#define FRAME_TIME 5

class petrification	: public attackSkill
{
private:
public:
	petrification();
	~petrification();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x, float y, float shadowX, float shadowY);
};

