#include "stdafx.h"
#include "blizzard.h"


blizzard::blizzard()
{
}


blizzard::~blizzard()
{
}

HRESULT blizzard::init(){
	attackSkill::init();
	//IMAGEMANAGER->addAlphaImage("���ڵ�", "�̹���/�Ҽ�����/��ų/���ڵ�.bmp", 1600, 900, false, RGB(255, 0, 255));
	_blizzardTime = 0;
	_offX = 0;
	_offY = 0;
	setRect(RectMake(-3000, 0, WINSIZEX, WINSIZEY + 100));
	
	return S_OK;
}
void blizzard::update(){
	if (!_start) {
		_rcAttack = RectMake(0, 0, 0, 0);
		return;
	}

	if (!SOUNDMANAGER->isPlaySound("���ڵ�")){
		SOUNDMANAGER->play("���ڵ�",0.3f);
	}

	_rcAttack = _rcShadow;
	_offX+=10;
	_offY-=3;

	if (_blizzardTime >= BLIZZARDTIME + INIDATA->loadDataInterger("PlayerData", "Skill", "blizzard")*20){
		_start = false;
	}
	_blizzardTime++;
}
void blizzard::render(){
	if (!_start) return;
	IMAGEMANAGER->findAlphaImage("���ڵ�")->alphaLoopRender(getMemDC(), &_rcAttack, _offX, _offY, 125);
}
void blizzard::release(){}

void blizzard::start(float x, float y, float shadowX, float shadowY){
	attackSkill::start(x, y, shadowX, shadowY);
	_blizzardTime = 0;
	_rcShadow = RectMake(0, 0, WINSIZEX, WINSIZEY + 100);
	_rcAttack = _rcShadow;
	_offX = 0;
	_offY = 0;
	setRect(RectMake(0, 0, WINSIZEX, WINSIZEY + 100));
}
