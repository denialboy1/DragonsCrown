#include "stdafx.h"
#include "petrification.h"


petrification::petrification()
{
}


petrification::~petrification()
{
}

HRESULT petrification::init(){
	attackSkill::init();
	//IMAGEMANAGER->addAlphaFrameImage("석화", "이미지/소서리스/스킬/페트리픽케이션.bmp", 1500, 300, 5, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("석화효과", "이미지/소서리스/스킬/석화효과.bmp", 1600, 900, false,RGB(255,0,255));
	
	return S_OK;
}
void petrification::update(){
	if (!_start) return;

	_frameTimer++;
	if (_frameTimer > FRAME_TIME){
		_frameTimer = 0;
		_frameX++;
	}

	if (_frameX >= 6){ 
		_frameX = 6; 
		_alpha-=2;
		_rcAttack = RectMake(0, 0, 0,0);
		if (_alpha < 5){ _alpha = 0; }
		if (_alpha == 0){ _start = false; }
	}

	setRect(RectMake(0, 1000, 0, 0));
}
void petrification::render(){
	if (!_start) return;
	IMAGEMANAGER->findAlphaImage("석화")->alphaFrameRender(getMemDC(), _x, _y,_frameX,0, 200);

	if (_frameX >= 4){
		IMAGEMANAGER->findAlphaImage("석화효과")->alphaRender(getMemDC(),_alpha);
	}
}
void petrification::release(){}

void petrification::start(float x, float y, float shadowX, float shadowY){
	attackSkill::start(x, y, shadowX, shadowY);
	_alpha = 255;
	_rcAttack = RectMake(0, 0, 1600, 800);
	SOUNDMANAGER->play("페트리", 0.3f);
}