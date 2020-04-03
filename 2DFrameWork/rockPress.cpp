#include "stdafx.h"
#include "rockPress.h"


rockPress::rockPress()
{
}


rockPress::~rockPress()
{
}

HRESULT rockPress::init(){
	//IMAGEMANAGER->addPngFrameImage("rockPress", L"이미지/소서리스/스킬/스톤.png", 900, 600, 3, 1);
	//IMAGEMANAGER->addAlphaImage("rockPress2", "이미지/소서리스/스킬/스톤3.bmp", 400, 500, true, RGB(255, 0, 255));
	
	attackSkill::init();

	
	return S_OK;
}
void rockPress::update(){
	if (_start){
		if (_frameTimer > FRAMETIME){
			_frameX++;
			_frameTimer = 0;
		}
		if ((_frameX == 1) && (_frameTimer == 0)){
			SOUNDMANAGER->play("stone", 0.3f);
		}
		_frameTimer++;

		if (_frameX == 3){
			_frameTimer = 0;
			_alpha--;
			if (_alpha < 4){
				_frameX = 4;
			}
		}

		if (_frameX == 4){
			_start = false;
			_frameX = 0;
			_frameTimer = 0;
			_alpha = 255;
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcShadow = RectMake(0, 0, 0, 0);
		}

		if (_frameX == 3){
			if (_alpha < 250){
				_rcAttack = RectMake(0,0,0,0);
			}
			else{
				_rcAttack = RectMake(_x, _y + 250, 400, 500);
			}
			_rcShadow = RectMake(_shadowX, _shadowY, 400, 20);
			setRect(_rcShadow);
			
		}
	}
}
void rockPress::render(){

	if (_start){
		if (_frameX <3)
			IMAGEMANAGER->findPngImage("rockPress")->frameRender(getMemDC(), _x, _y, _frameX, 0);
		if (_frameX == 3){
			IMAGEMANAGER->findAlphaImage("rockPress2")->alphaRender(getMemDC(), _x, _y+265,_alpha);
			
		}
	}

	if (_debug){
		Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void rockPress::release(){}

