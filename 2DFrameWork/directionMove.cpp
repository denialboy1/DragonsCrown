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

	//���� ������
	if (_isLeft){
		*_x -= _leftSpeed;
	}

	//������ ������
	if (_isRight){
		*_x += _rightSpeed;
	}

	//���� ������
	if (_isUp){
		*_y -= _upSpeed;
	}

	//�Ʒ��� ������
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