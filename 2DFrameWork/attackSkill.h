#pragma once
#include "gameNode.h"
class attackSkill : public gameNode
{
protected:
	RECT _rcShadow;
	RECT _rcAttack;

	float _x, _y;
	float _shadowX, _shadowY;

	int _frameX;
	int _frameTimer;

	int _alpha;

	bool _start;
	bool _isAttack;
public:
	attackSkill();
	~attackSkill();

	HRESULT init();
	void start(float x, float y, float shadowX, float shadowY);

public:
	void setStart(bool start){ _start = start; }
	bool getStart(){ return _start; }
	int getFrameX(){ return _frameX; }
	int getAlpha(){ return _alpha; }
	RECT getRcShadow(){ return _rcShadow; }
	RECT getRcAttack(){ return _rcAttack; }

	void setIsAttack(bool isAttack) { _isAttack = isAttack; }
	bool getIsAttack(){ return _isAttack; }
};

