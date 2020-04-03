#include "stdafx.h"
#include "enemySkill.h"


enemySkill::enemySkill()
{
}


enemySkill::~enemySkill()
{
}


HRESULT enemySkill::init(){
	_rcShadow = RectMake(0, 0, 0, 0);
	_rcAttack = RectMake(0, 0, 0, 0);

	_x = 0;
	_y = 0;

	_shadowX = 0;
	_shadowY = 0;

	setRect(_rcShadow);

	_frameX = 0;
	_frameTimer = 0;

	_start = false;

	_alpha = 255;
	return S_OK;
}

void enemySkill::start(float x, float y, float shadowX, float shadowY){
	_start = true;
	_frameX = 0;
	_frameTimer = 0;

	_x = x;
	_y = y;

	_shadowX = shadowX;
	_shadowY = shadowY;

	_alpha = 255;

	_rcShadow = RectMake(_shadowX, _shadowY, 400, 20);
	setRect(_rcShadow);
}