#pragma once
#include "attackSkill.h"

//#define CUSS_TIME
#define FRAME_TIME 5

class cuss : public attackSkill
{
private:
	int _frameY;
public:
	cuss();
	~cuss();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x, float y, float shadowX, float shadowY,int frameY);
};

