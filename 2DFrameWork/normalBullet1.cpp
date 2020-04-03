#include "stdafx.h"
#include "normalBullet1.h"


normalBullet1::normalBullet1()
{
}


normalBullet1::~normalBullet1()
{
}


HRESULT normalBullet1::init(){
	//IMAGEMANAGER->addFrameImage("fireball1", "이미지/소서리스/fireball1.bmp", 6120, 400, 17, 1,true,RGB(255,0,255));
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
void normalBullet1::update(){
	if (_start){
		if (_frameTime > FRAMESPEED){ _frameX++; _frameTime = 0; }
		_frameTime++;
		if (_frameX > 2){
			_rc.left = _rcShadow.left;
			_rc.top = _rcShadow.top - 400;
			_rc.right = _rcShadow.right;
			_rc.bottom = _rcShadow.bottom;
		}

		if (_frameX == 17){
			_start = false;
			_rc = RectMake(0, 0, 0, 0);
			_rcShadow = RectMake(0, 0, 0, 0);
		}
	}

	//_rc = RectMake(_x, _y, 360, 400);
	//zOrder용
}
void normalBullet1::render(){
	if (_start){
		IMAGEMANAGER->findAlphaImage("shadow1")->alphaRender(getMemDC(), _x + 40, _y + 345,100);
		IMAGEMANAGER->findImage("fireball1")->frameRender(getMemDC(), _x, _y, _frameX, 0);
		//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
		//IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _x+60, _y+385, 300, 20, 0, 0, 235, 16);
		
	}

	if (_debug){
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void normalBullet1::release(){}

void normalBullet1::start(int x, int y){
	_x = x, _y = y + 60;
	_start = true;
	_frameTime = 0;
	_frameX = 0;
	_rcShadow = RectMake(x+100, y+430, 200, 40);
	_rc = RectMake(0, 0, 0, 0);
	setRect(RectMake(_rcShadow.left, _rcShadow.bottom, 100,20));

	_isAttack = false;
	RECT _r = getRect();
	int a = 4;

}