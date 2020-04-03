#pragma once
#include "enemySkill.h"

#define FIRE_FRAME 7
#define FLOOR_FRAME 7
#define CONTINUANCE_TIME 100
class fireFloor : public enemySkill
{
public:
	bool _isFireEnd;

	//��
	int _fireTimer;
	int _fireFrameX;
	float _offY;

	//���̾��÷ξ�
	int _fireFloorFrameX;
	int _fireFloorFrameY;
	int _fireFloorTimer;
	int _continuanceTime;

	//ü��
	int _hp;
	RECT _rcFire;
public:
	fireFloor();
	~fireFloor();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x,float y,float shadowX,float shadowY);
	void damage(int damage){ _hp -= damage; }
public:
	int getHp(){ return _hp; }
	RECT getRcFire(){ return _rcFire; }
};

