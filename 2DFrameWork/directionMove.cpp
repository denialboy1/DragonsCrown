#include "stdafx.h"
#include "directionMove.h"


directionMove::directionMove()
{
}


directionMove::~directionMove()
{
}


HRESULT directionMove::init(){
	_isLeft = false;
	_isRight = false;
	_isUp = false;
	_isDown = false;
	
	_leftSpeed = 0;
	_rightSpeed = 0;
	_upSpeed = 0;
	_downSpeed = 0;
	return S_OK;
}
void directionMove::update(){

	//왼쪽 움직임
	if (_isLeft){
		*_x -= _leftSpeed;
	}

	//오른쪽 움직임
	if (_isRight){
		*_x += _rightSpeed;
	}

	//위로 움직임
	if (_isUp){
		*_y -= _upSpeed;
	}

	//아래로 움직임
	if (_isDown){
		*_y += _downSpeed;
	}
}


void directionMove::render(){

}

void directionMove::release(){}


void directionMove::moveLeft(float* x, float speed){
	_isLeft = true;
	
	_x = x;

	_leftSpeed = speed;

}
void directionMove::moveRight(float* x, float speed){
	_isRight = true;

	_x = x;

	_rightSpeed = speed;
}
void directionMove::moveUp(float* y, float speed){
	_isUp = true;

	_y = y;

	_upSpeed = speed;
}
void directionMove::moveDown(float* y, float speed){
	_isDown = true;

	_y = y;

	_downSpeed = speed;
}