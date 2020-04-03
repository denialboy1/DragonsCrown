#include "stdafx.h"
#include "fireFloor.h"


fireFloor::fireFloor()
{
}


fireFloor::~fireFloor()
{
}

HRESULT fireFloor::init(){
	enemySkill::init();
	//IMAGEMANAGER->addAlphaFrameImage("firefloor", "이미지/고대드래곤/firefloor.bmp", 3072, 3072, 4, 4, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaFrameImage("불이펙트", "이미지/고대드래곤/불이펙트.bmp", 960, 124, 16, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("firefloor_shadow", "이미지/소서리스/shadow.bmp", 60, 100, true, RGB(255, 0, 255));
	
	
	_offY = 0;
	_isFireEnd = false;
	_fireTimer = 0;
	_fireFrameX = 0;
	_fireFloorFrameX = 0;
	_fireFloorFrameY = 0;
	_fireFloorTimer = 0;
	_rcFire = RectMake(0, 0, 0, 0);
	return S_OK;
}
void fireFloor::update(){
	if (!_start) {
		_rcAttack = RectMake(0, 0, 0, 0);
		_rcFire = RectMake(0, 0, 0, 0);
		return;
	}

	if (!_isFireEnd){
		_fireTimer++;
		if (_fireTimer > FIRE_FRAME){
			_fireFrameX++;
			_fireTimer = 0;
			if (_fireFrameX > 15) _fireFrameX = 0;
		}
		_offY+=4;
		_rcAttack = RectMake(_x, _y + _offY, 60, 100);
		_rcFire = RectMake(_x-100, _y + _offY, 260, 100);
		if (_rcAttack.bottom > (_rcShadow.top + _rcShadow.bottom) / 2){
			_isFireEnd = true;
		}
	}
	else{
		if (!SOUNDMANAGER->isPlaySound("burn"))
		SOUNDMANAGER->play("burn", 0.5f);
		_fireFloorTimer++;
		if (_fireFloorTimer > FLOOR_FRAME){
			_fireFloorFrameX++;
			_fireFloorTimer = 0;
			if (_fireFloorFrameX == 4){
				_fireFloorFrameX = 0;
				_fireFloorFrameY++;
				if (_fireFloorFrameY == 4){
					_fireFloorFrameY = 2;
					_fireFloorFrameX = 0;
				}
			}
		}
		
		_continuanceTime++;
		if (_continuanceTime > CONTINUANCE_TIME){
			_alpha--;
		}
		if (_alpha < 10){ _start = false; }

		_rcShadow = RectMake(0, 800, WINSIZEX, 100);
		_rcAttack = RectMake(0, 750, WINSIZEX, 150);
		_rcFire = RectMake(0, 0, 0, 0);
	}

	if (_hp <= 0) { _start = false; }
	setRect(_rcShadow);
}
void fireFloor::render(){
	if (!_start) return;

	if (!_isFireEnd){
		IMAGEMANAGER->findAlphaImage("불이펙트")->alphaFrameRender(getMemDC(),_rcAttack.left,_rcAttack.top, _fireFrameX, 0, 255);
		IMAGEMANAGER->findAlphaImage("firefloor_shadow")->alphaRender(getMemDC(),_rcShadow.left,_rcShadow.top-30, 200);
	}
	else{
		IMAGEMANAGER->findAlphaImage("firefloor")->alphaFrameRender(getMemDC(), _rcShadow.left, _rcShadow.top - 300, _fireFloorFrameX, _fireFloorFrameY, _alpha);
		IMAGEMANAGER->findAlphaImage("firefloor")->alphaFrameRender(getMemDC(), _rcShadow.left + 512, _rcShadow.top - 300, _fireFloorFrameX, _fireFloorFrameY, _alpha);
		IMAGEMANAGER->findAlphaImage("firefloor")->alphaFrameRender(getMemDC(), _rcShadow.left + 1024, _rcShadow.top - 300, _fireFloorFrameX, _fireFloorFrameY, _alpha);
	}

	if (_debug){
		//Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
		Rectangle(getMemDC(), _rcFire.left, _rcFire.top, _rcFire.right, _rcFire.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void fireFloor::release(){}

void fireFloor::start(float x, float y, float shadowX, float shadowY){
	enemySkill::start(x, y, shadowX, shadowY);
	_offY = 0;
	_isFireEnd = false;
	_fireTimer = 0;
	_fireFrameX = 0;
	_fireFloorFrameX = 0;
	_fireFloorFrameY = 0;
	_fireFloorTimer = 0;
	_continuanceTime = 0;
	_rcAttack = RectMake(_x, _y, 60, 100);
	_rcFire = _rcAttack;
	_rcShadow = RectMake(_shadowX, _shadowY, 60, 20);
	_hp = 100;
}