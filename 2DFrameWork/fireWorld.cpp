#include "stdafx.h"
#include "fireWorld.h"


fireWorld::fireWorld()
{
}


fireWorld::~fireWorld()
{
}

HRESULT fireWorld::init(){
	enemySkill::init();
	IMAGEMANAGER->addAlphaFrameImage("전체불공격이펙트", "이미지/고대드래곤/전체불공격이펙트.bmp", 24000, 1800, 15, 2, true, RGB(255, 0, 255));
	_frameY = 0;
	_rcShadow = RectMake(0, 0, 0, 2000);
	return S_OK;
}
void fireWorld::update(){
	if (!_start){
		_rcDeffence1 = RectMake(0, 0, 2000, 0);
		return;
	}
	_timer--;
	if (_timer > 0)return;

	_frameTimer++;
	if (_frameTimer > FRAME_TIME){
		_frameX++;
		_frameTimer = 0;
		if (_frameX == 15){

			if (_frameX == 15 && _frameY == 1)
				_start = false;
			_frameX = 0;
			_frameY = 1;
		}
	}
	if (_frameY == 1 && _frameX > 10) _alpha--;

	if (_frameY == 1 || _frameX > 11){
		_rcDeffence1 = RectMake(0, 150, 200, 500);
		_rcDeffence2 = RectMake(1400, 150, 200, 500);
	}

}
void fireWorld::render(){
	if (!_start){ return; }
	if (_timer > 0) return;
	IMAGEMANAGER->findAlphaImage("전체불공격이펙트")->alphaFrameRender(getMemDC(), 0, 0, _frameX, _frameY, _alpha);

	if (_debug){
		Rectangle(getMemDC(), _rcDeffence1.left, _rcDeffence1.top, _rcDeffence1.right, _rcDeffence1.bottom);
		Rectangle(getMemDC(), _rcDeffence2.left, _rcDeffence2.top, _rcDeffence2.right, _rcDeffence2.bottom);
	}
}
void fireWorld::release(){}

void fireWorld::start(float x, float y, float shadowX, float shadowY,int timer){
	enemySkill::start(x, y, shadowX, shadowY); 
	_frameY = 0;
	_rcShadow = RectMake(0, 0, 0, 2000);
	_timer = timer;
	setRect(_rcShadow);
	_rcDeffence1 = RectMake(0, 0, 2000, 0);
	_rcDeffence2 = RectMake(1400, 150, 200, 500);
}