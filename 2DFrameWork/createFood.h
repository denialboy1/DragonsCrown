#pragma once
#include "attackSkill.h"
#define CREATEFOOD_TIME 400
class createFood : public attackSkill
{

private:
	int _foodTime;
	int _skillLV;
	int _food;

	RECT _rcObject;
	int _shadowAlpha;
public:
	createFood();
	~createFood();

	HRESULT init();
	void render();
	void update();
	void release();

	void start(float x, float y, float shadowX, float shadowY,int skillLV);
	RECT getRcOjbect(){ return _rcObject; }
};

