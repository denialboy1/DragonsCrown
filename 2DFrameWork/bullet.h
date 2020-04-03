#pragma once
#include "gameNode.h"
class bullet : public gameNode
{
protected:
	RECT _rcShadow;
	RECT _rc;


	int _frameTime;
	int _frameX;

	int _x, _y;
	bool _start;

	bool _isAttack;
public:
	bullet();
	~bullet();

	virtual HRESULT init();
	virtual void update();
	virtual void render();
	virtual void release();

	virtual void start(int x, int y);

public:
	RECT getRcShadow(){ return _rcShadow; }
	RECT getRc(){ return _rc; }
	void setRc(RECT rc){ _rc = rc; }
	bool getStart(){ return _start; }
	int getFrameX(){ return _frameX; }
	int getX(){ return _x;}
	int getY(){ return _y; }
	void setIsAttack(bool isAttack) { _isAttack = isAttack; }
	bool getIsAttack(){ return _isAttack; }
};

