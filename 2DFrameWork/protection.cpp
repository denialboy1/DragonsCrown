#include "stdafx.h"
#include "protection.h"


protection::protection()
{
}


protection::~protection()
{
}

HRESULT protection::init(){
	attackSkill::init();

	//IMAGEMANAGER->addAlphaFrameImage("프로텍션", "이미지/소서리스/스킬/프로텍션.bmp", 5400, 900, 6, 1, true, RGB(255, 0, 255));
	_protectionTime = 0;
	

	return S_OK;
}
void protection::update(float x, float y){
	if (!_start) return;
	_x = x;
	_y = y;

	if (_frameTimer > FRAMEX_TIME){
		while (1){
			int temp = RND->getInt(6);
			if (temp == _frameX) continue;
			_frameX = temp;
			break;
		}

		while (1){
			int temp = RND->getInt(6);
			if (temp == _frameX2) continue;
			_frameX2 = temp;
			break;
		}

		while (1){
			int temp = RND->getInt(6);
			if (temp == _frameX3) continue;
			_frameX3 = temp;
			break;
		}
		_frameTimer = 0;
	}
	_frameTimer++;

	if (_protectionTime > PROTECTION_TIME + INIDATA->loadDataInterger("PlayerData", "Skill", "protection")*50){
		_start = false;
	}

	if (_protectionTime == PROTECTION_TIME + INIDATA->loadDataInterger("PlayerData", "Skill", "protection") * 50 - 10){
		SOUNDMANAGER->play("쉴드해제", 0.4f);
	}
	_protectionTime++;
	setRect(RectMake(_x, _y, 100, 500));
}
void protection::render(){
	if (!_start) return;
	IMAGEMANAGER->findAlphaImage("프로텍션")->alphaFrameRender(getMemDC(), _x-240, _y-180,_frameX,0, 125);
	//IMAGEMANAGER->findAlphaImage("프로텍션")->alphaFrameRender(getMemDC(), _x - 240, _y - 180, _frameX2, 0, 125);
	//IMAGEMANAGER->findAlphaImage("프로텍션")->alphaFrameRender(getMemDC(), _x - 240, _y - 180, _frameX3, 0, 125);
}
void protection::release(){}


void protection::start(float x, float y, float shadowX, float shadowY){
	attackSkill::start(x, y, shadowX, shadowY);
	_protectionTime = 0;
	SOUNDMANAGER->play("쉴드시작", 0.3f);
	
}