#pragma once
#include "motherEnemy.h"

#define TRAP_ACTION_TIMER 10

class trap : public motherEnemy
{
	
private:
	bool _isAttack;		//����
	int _actionTimer;	//�ൿŸ�̸�

	int _frameX;
	int _reverse1;
public:
	trap();
	~trap();

	HRESULT init();
	void update(RECT _rcPlayer, RECT _rcShadow);
	void render();
	void release();
	void create(int x, int y);
	void start();
public:
	bool getAttack(){ return _isAttack; }
	void setAttack(bool isAttack){ _isAttack = isAttack; }
};

