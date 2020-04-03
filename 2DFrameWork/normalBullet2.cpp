#include "stdafx.h"
#include "normalBullet2.h"


normalBullet2::normalBullet2()
{
}


normalBullet2::~normalBullet2()
{
}


HRESULT normalBullet2::init(){
	//IMAGEMANAGER->addFrameImage("fireball2", "이미지/소서리스/fireball2.bmp", 6750, 450, 15, 1, true, RGB(255, 0, 255));
	_frameTime = 0;
	_frameX = 0;
	_start = false;
	_x = 100;
	_y = 100;
	_rcShadow = RectMake(0, 0, 0, 0);
	_rc = RectMake(0, 0, 0, 0);
	setRect(_rc);
	return S_OK;
}
void normalBullet2::update(){
	if (_start){
		if (_frameTime > FRAMESPEED){ _frameX++; _frameTime = 0; }
		_frameTime++;
		if (_frameX == 25){
			_start = false;
			_rc = RectMake(0, 0, 0, 0);
		}
	}

	
	//zOrder용
	setRect(_rcShadow);
}
void normalBullet2::render(){
	if (_start){
		IMAGEMANAGER->findAlphaImage("shadow2")->alphaRender(getMemDC(), _x + 65, _y + 360, 150);
		IMAGEMANAGER->findImage("fireball2")->frameRender(getMemDC(), _x, _y, _frameX%15, 0);
		//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	}

	if (_debug){
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void normalBullet2::release(){}

void normalBullet2::start(int x, int y){
	_x = x, _y = y + 60;
	_start = true;
	_frameTime = 0;
	_frameX = 0;
	_rc = RectMake(_x+100, _y, 250, 400);
	_rcShadow = RectMake(_x + 100, _y+380, 100, 40);
	_isAttack = false;
}