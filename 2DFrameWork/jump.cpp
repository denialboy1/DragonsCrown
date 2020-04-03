#include "stdafx.h"
#include "jump.h"


jump::jump()
{
}


jump::~jump()
{
}

HRESULT jump::init(void)
{
	_isJumping = false;

	_jumpPower = _gravity = 0.0f;

	//더블점프 초기화
	_isDoubleJumping = false;
	_isOne = false;
	_isTwo = false;

	return S_OK;
}

void jump::release(void)
{

}

void jump::update(void)
{
	//일반 점프
	if (_isJumping){
		*_y -= _jumpPower;
		_jumpPower -= _gravity;

		if (_startY < *_y)
		{
			*_y = _startY;
			_isJumping = false;
		}
	}

	//더블점프
	if (_isOne && !_isTwo){
		*_y -= _jumpPower;
		_jumpPower -= _gravity;
		if (_startY < *_y)
		{
			*_y = _startY;
			_isOne = false;
			_jumpPower = 0;
			_isDoubleJumping = false;
		}
	}

	if (_isTwo){
		*_y -= _jumpPower;
		_jumpPower -= _gravity;
		if (_startY < *_y)
		{
			*_y = _startY;
			_isTwo = false;
			_jumpPower = 0;
			_isDoubleJumping = false;
		}
	}
}

void jump::render(void)
{

}

void jump::jumping(float* x, float* y, float power, float gravity)
{
	if (_isJumping) return;

	_isJumping = true;

	_x = x;
	_y = y;

	_startX = *x;
	_startY = *y;

	_gravity = gravity;
	_jumpPower = power;

}

void jump::doubleJumping(float* x, float* y, float power, float gravity){
	if (_isOne && _isTwo) return;

	_isDoubleJumping = true;


	//두번쨰 점프 확인
	if (_isOne && !_isTwo){
		_isTwo = true;
		_gravity = gravity;
		_jumpPower = power;
	}


	//첫번쨰 점프 확인
	if (!_isOne){
		_isOne = true;
		_x = x;
		_y = y;

		_startX = *x;
		_startY = *y;

		_gravity = gravity;
		_jumpPower = power;
	}

}
