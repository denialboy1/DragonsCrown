#include "stdafx.h"
#include "gravity.h"


gravity::gravity()
{
}


gravity::~gravity()
{
}


HRESULT gravity::init(){
	attackSkill::init();

	//IMAGEMANAGER->addAlphaFrameImage("gravity", "이미지/소서리스/스킬/그래비티.bmp", 10500, 500, 21, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("gravity_arrage", "이미지/소서리스/스킬/그래비티범위.bmp", 1000, 700, true, RGB(255, 0, 255));
	
	return S_OK;
}
void gravity::update(){
	if (!_start) {
		_rcAttack = RectMake(0, 0, 0, 0);
		return;
	}
	
	_frameTimer++;
	if (_frameTimer > FRAME_TIME){
		_frameX++;
		_frameTimer = 0;
		if (_frameX == 21){
			_frameX = 0;
		}
	}
	_gravityTime++;
	if (!SOUNDMANAGER->isPlaySound("gravity")){
		SOUNDMANAGER->play("gravity", 0.3f);
	}
	if (_gravityTime > GRAVITY_TIME + INIDATA->loadDataInterger("PlayerData","Skill","gravity")*50){
		_start = false;
		_gravityTime = 0;
		SOUNDMANAGER->stop("gravity");
	}
	
	_rcAttack = RectMake(_x-200, _y-180, 900, 650);
}
void gravity::render(){
	if (!_start) return;
	IMAGEMANAGER->findAlphaImage("gravity")->alphaFrameRender(getMemDC(), _x, _y,_frameX,0, 150);
	IMAGEMANAGER->findAlphaImage("gravity_arrage")->alphaRender(getMemDC(), _x-250, _y-200, 170);
	if (_debug){
		Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void gravity::release(){}

void gravity::start(float x, float y, float shadowX, float shadowY){
	attackSkill::start(x, y, shadowX, shadowY);
	_gravityTime = 0;
	setRect(RectMake(_rcShadow.left-1500,_rcShadow.top,_rcShadow.right-_rcShadow.left,_rcShadow.bottom-_rcShadow.top));
	_rcShadow = RectMake(shadowX-280, shadowY-50, 900, 70);
	SOUNDMANAGER->play("gravity", 0.3f);
}