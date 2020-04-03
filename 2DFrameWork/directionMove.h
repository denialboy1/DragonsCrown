#pragma once
#include "gameNode.h"

class directionMove : public gameNode
{
private:
	float* _x;
	float* _y;
	
	float _leftSpeed;
	float _rightSpeed;
	float _upSpeed;
	float _downSpeed;

	bool _isLeft;
	bool _isRight;
	bool _isUp;
	bool _isDown;
public:
	directionMove();
	~directionMove();

	HRESULT init();
	void update();
	void render();
	void release();

	void moveLeft(float* x, float speed);
	void moveRight(float* x, float speed);
	void moveUp(float* y, float speed);
	void moveDown(float* y, float speed);

	bool getIsLeft(){ return _isLeft; }
	bool getIsRight(){ return _isRight; }
	bool getIsUp(){ return _isUp; }
	bool getIsDown(){ return _isDown; }

	void setIsLeft(bool isLeft){ _isLeft = isLeft; }
	void setIsRight(bool isRight){ _isRight = isRight; }
	void setIsUp(bool isUp){ _isUp = isUp; }
	void setIsDown(bool isDown){ _isDown = isDown; }
};


