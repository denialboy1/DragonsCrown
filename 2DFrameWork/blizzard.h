#pragma once
#include "attackSkill.h"
#define BLIZZARDTIME 100
class blizzard : public attackSkill
{
	int _blizzardTime;

	int _offX;
	int _offY;
public:
	blizzard();
	~blizzard();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x, float y, float shadowX, float shadowY);
};

