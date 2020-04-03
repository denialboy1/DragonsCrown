#pragma once
#include "gameNode.h"

class jump : public gameNode
{
private:
	float _jumpPower;
	float _gravity;

	float* _x;
	float* _y;

	float _startX;
	float _startY;

	bool _isJumping;

	bool _isDoubleJumping;
	bool _isOne;
	bool _isTwo;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void jumping(float* x, float* y, float power, float gravity);
	void doubleJumping(float* x, float* y, float power, float gravity);
	//점프중이냐 여부에 따른 불 게터, 세터
	bool getIsJumping(void) { return _isJumping; }
	void setIsJumping(bool isJumping) { _isJumping = isJumping; }
	bool getIsOne(){ return _isOne; }
	void setIsOne(bool isOne){ _isOne = isOne; }
	bool getIsTwo(){ return _isTwo; }
	void setIsTwo(bool isTwo){ _isTwo = isTwo; }
	bool getIsDoubleJumping(){ return _isDoubleJumping; }
	void setIsDoubleJumping(bool isDoubleJumping){ _isDoubleJumping = isDoubleJumping; }

	//점프파워 getter,setter
	float getJumpPower(){ return _jumpPower; }
	void setJumpPower(float jumpPower){ _jumpPower = jumpPower; }

	//시작점 Y 게터
	float getIsStartY(){ return _startY; }
	void setStartY(float startY){ _startY = startY; }

	//중력 게터세터
	float getGravity(){ return _gravity; }
	void setGravity(float gravity){ _gravity = gravity; }

	
	
	jump();
	~jump();
};

