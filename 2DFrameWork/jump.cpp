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

	//�������� �ʱ�ȭ
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
	//�Ϲ� ����
	if (_isJumping){
		*_y -= _jumpPower;
		_jumpPower -= _gravity;

		if (_startY < *_y)
		{
			*_y = _startY;
			_isJumping = false;
		}
	}

	//��������
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


	//�ι��� ���� Ȯ��
	if (_isOne && !_isTwo){
		_isTwo = true;
		_gravity = gravity;
		_jumpPower = power;
	}


	//ù���� ���� Ȯ��
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
