#include "stdafx.h"
#include "cuss.h"


cuss::cuss()
{
}


cuss::~cuss()
{
}

HRESULT cuss::init(){
	attackSkill::init();

	//IMAGEMANAGER->addAlphaFrameImage("cuss", "이미지/소서리스/스킬/커즈.bmp", 3600, 1000, 12, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("shadow5", "이미지/소서리스/shadow.bmp", 200, 100, true, RGB(255, 0, 255));
	_frameY = 0;
	
	return S_OK;
}
void cuss::update(){
	if (!_start){
		RectMake(0, 0, 0, 0);
		return;
	}

	if (_frameTimer > FRAME_TIME){
		_frameX++;
		_frameTimer = 0;
	}
	_frameTimer++;

	if (_frameX == 12){
		_frameX = 12;
		_start = false;
		RectMake(0, 0, 0, 0);
		SOUNDMANAGER->play("커즈", 0.3f);
	}
	if (_frameY == 0){
		_x += 5;
		_shadowX += 5;
	}
	else{
		_x -= 5;
		_shadowX -= 5;
	}

	if (_frameX >= 9){
		_alpha -= 10;
	}
	
	if (_frameX < 9 && _isAttack) _frameX = 9;

	_rcShadow = RectMake(_shadowX+40, _shadowY+40, 150, 20);
	_rcAttack = RectMake(_x+80, _y+50, 150, 370);
	setRect(_rcShadow);
}
void cuss::render(){
	if (!_start) return;
	IMAGEMANAGER->findAlphaImage("shadow5")->alphaRender(getMemDC(), _shadowX, _shadowY, 100);
	IMAGEMANAGER->findAlphaImage("cuss")->alphaFrameRender(getMemDC(), _x, _y,_frameX,_frameY, _alpha);

	if (_debug){
		Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void cuss::release(){}

void cuss::start(float x, float y, float shadowX, float shadowY,int frameY){
	attackSkill::start(x, y, shadowX, shadowY);
	_frameY = frameY;
	_alpha = 200;
	_rcShadow = RectMake(_shadowX + 40, _shadowY + 40, 150, 20);
	_rcAttack = RectMake(_x + 80, _y + 50, 150, 370);
}