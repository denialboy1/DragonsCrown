#pragma once
#include "attackSkill.h"

#define PROTECTION_TIME 200
#define FRAMEX_TIME 5
class protection : public attackSkill
{
private:
	int _protectionTime;
	int _frameX2;
	int _frameX3;
public:
	protection();
	~protection();

	HRESULT init();
	void update(float x,float y);
	void render();
	void release();


	void start(float x, float y, float shadowX, float shadowY);
};

