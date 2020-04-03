#include "stdafx.h"
#include "bullet.h"


bullet::bullet()
{
}


bullet::~bullet()
{
}

HRESULT bullet::init(){
	_frameTime = 0;
	_frameX = 0;
	_start = true;
	_x = 100;
	_y = 100;
	_rcShadow = RectMake(0, 0, 0, 0);
	_rc = RectMake(0, 0, 0, 0);
	_isAttack = false;
	setRect(_rc);
	return S_OK;
}
void bullet::update(){
	_rc = RectMake(_x, _y, 100, 300);
	//zOrder¿ë
	setRect(_rc);
}
void bullet::render(){
}
void bullet::release(){}

void bullet::start(int x, int y){
	_x = x, _y = y;
	_start = true;
	_frameTime = 0;
}