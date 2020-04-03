#include "stdafx.h"
#include "fireRain.h"


fireRain::fireRain()
{
}


fireRain::~fireRain()
{
}

HRESULT fireRain::init(){
	enemySkill::init();
	IMAGEMANAGER->addAlphaFrameImage("fireRain", "�̹���/���巡��/firerain.bmp", 476, 276, 4, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("fireRain_shadow", "�̹���/�Ҽ�����/shadow.bmp", 150, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaFrameImage("������Ʈ2", "�̹���/���巡��/������Ʈ2.bmp", 1600, 150, 8, 1, true, RGB(255, 0, 255));

	
	_isFireRainEnd = false;
	_fireFrameTimer = 0;
	_fireTimer = 0;
	_fireFrameX = 0;
	return S_OK;
}
void fireRain::update(){
	if (!_start) return;

	if (!_isFireRainEnd){
		if (_timer <= 0)	{
			_y += FIRERAIN_SPEED;
			_timer = 0;
		}
		_timer--;
		_rcAttack = RectMake(_x, _y + 50, 100, 200);
		if (_y+250 >= _shadowY) {
			//		_start = false;
			_isFireRainEnd = true;
			SOUNDMANAGER->play("�巡�����2", 0.2F);
		}
	}
	else{

		//�� ����Ʈ
		_fireFrameTimer++;
		_fireTimer++;
		if (_fireFrameTimer > FIRE_FRAME_TIME){
			_fireFrameX++;
			_fireFrameTimer = 0;
			if (_fireFrameX > 7) _fireFrameX = 0;
		}

		if (_fireTimer > FIRE_TIME){
			_start = false;
		}

		if (_fireTimer > FIRE_TIME - 125){ _alpha -= 2; }
	}



	//���̾�� ������
	if (_frameTimer > FRAME_TIME){
		_frameTimer = 0;
		_frameX++;
		if (_frameX > 3){
			_frameX = 0;
		}
	}
	_frameTimer++;

}
void fireRain::render(){
	if (!_start) return;
	IMAGEMANAGER->findAlphaImage("fireRain_shadow")->alphaRender(getMemDC(), _rcShadow.left-25, _rcShadow.top-35, 100);
	if (!_isFireRainEnd){
		IMAGEMANAGER->findAlphaImage("fireRain")->alphaFrameRender(getMemDC(), _rcAttack.left, _rcAttack.top-40, _frameX, 0, 255);
	}
	else {
		IMAGEMANAGER->findAlphaImage("������Ʈ2")->alphaFrameRender(getMemDC(), _rcShadow.left-45, _rcShadow.top-110,_fireFrameX,0, _alpha);
	}

	if (_debug){
		Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void fireRain::release(){}

void fireRain::start(float x, float y, float shadowX, float shadowY, int time){
	enemySkill::start(x, y, shadowX, shadowY);
	_rcAttack = RectMake(_x, _y+50, 100, 170);
	_rcShadow = RectMake(_shadowX, _shadowY, 100, 20);
	setRect(_rcShadow);
	_timer = time;
	_isFireRainEnd = false;
	_fireFrameTimer = 0;
	_fireTimer = 0;
	_fireFrameX = 0;
}