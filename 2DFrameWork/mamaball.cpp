#include "stdafx.h"
#include "mamaball.h"


mamaball::mamaball()
{
}


mamaball::~mamaball()
{
}

HRESULT mamaball::init(){
	//IMAGEMANAGER->addFrameImage("manaball", "이미지/소서리스/manaball.bmp", 1542, 200, 6, 1, true, RGB(255, 0, 255));
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
void mamaball::update(){
	if (!_start){ _rc = RectMake(0, 0, 0, 0); }
	if (_start){
		if (_frameTime > FRAMESPEED){ _frameX++; _frameTime = 0; }
		_frameTime++;
		if (_frameX == 6){
			_start = false;
		}
		_rc = RectMake(_x + 50, _y + 30, 150, 150);
	}

	
	//zOrder용
	setRect(_rcShadow);
}
void mamaball::render(){
	if (_start){
		
		IMAGEMANAGER->findImage("manaball")->frameRender(getMemDC(), _x, _y, _frameX, 0);
		//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _x+30, _rcShadow.top, 200, 20, 0, 0, 235, 16);

		if (_debug){
			Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
			Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
		}

	}
}
void mamaball::release(){}

void mamaball::start(int x, int y,int shadowX,int shadowY){
	_x = x, _y = y + 60;
	_start = true;
	_frameTime = 0;
	_frameX = 0;
	_rcShadow = RectMake(shadowX-150, shadowY, 100, 30);
	_isAttack = false;
}
