#include "stdafx.h"
#include "trap.h"


trap::trap()
{
}


trap::~trap()
{
}

HRESULT trap::init(){
	IMAGEMANAGER->addFrameImage("trap", "ÀÌ¹ÌÁö/¹«´ý/trap.bmp", 264, 310, 6, 1, true, RGB(255, 0, 255));
	_frameX = 0;
	_isAttack = false;
	return S_OK;
}
void trap::update(RECT _rcPlayer, RECT _rcShadow){
	if (!_isAttack){
		_frameX = 0;
		_reverse1 = 1;
		_actionTimer = 0;
		_rcAttack = RectMake(0, 0, 0, 0);
		_rcShadow = RectMake(_rcAttack.left + 5, _rcAttack.bottom - 7, 30, 30);
	}
	else{
		_rcAttack = RectMake(_enemyX + 5, _enemyY, 30, 300);
		_rcShadow = RectMake(_rcAttack.left + 5, _rcAttack.bottom - 7, 30, 30);
		_actionTimer++;
		if (_actionTimer > TRAP_ACTION_TIMER){
			_frameX += _reverse1;
			if (_frameX == 6){
				_reverse1 *= -1;
			}
			if (_frameX < 0){
				_isAttack = false;
				_rcAttack = RectMake(0, 0, 0, 0);
			}
		}
	}
}
void trap::render(){
	if (!_isAttack){
		IMAGEMANAGER->findImage("trap")->frameRender(getMemDC(), _enemyX, _enemyY, 0, 0);
	}
	else{
		IMAGEMANAGER->findImage("trap")->frameRender(getMemDC(), _enemyX, _enemyY, _frameX, 0);
	}

	if (_debug){
		Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
		//Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void trap::release(){}

void trap::create(int x, int y){
	_enemyX = x;
	_enemyY = y;

	_rcAttack = RectMake(_enemyX+5 , _enemyY , 30, 300);
	_rcShadow = RectMake(_rcAttack.left + 5, _rcAttack.bottom - 7, 30, 30);
	setRect(_rcShadow);
	_attackDamage = 70;
}

void trap::start(){
	_isAttack = true;
}