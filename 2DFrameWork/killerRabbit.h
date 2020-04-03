#pragma once
#include "motherEnemy.h"
#include "jump.h"

#define RABBIT_SKILL_TIMER 200
class killerRabbit : public motherEnemy
{
private:
	enum STATE{APPEAR,STAND,WALK,DEAD,NORMAL_ATTACK,DEATH_ATTACK,DEAD_AFTER};

private:
	jump* _jump;
private:
	STATE _state;

	bool _isDeathAttack;

	int _skillTimer;	//행동타이머

	int _jumpY;

	RECT _rcDeathAttack;
	//여분 DC//
	HBITMAP _rabbitBitmap, _hOldBitMap;
	HDC _rabbitMemDC;

	//2번째 여분DC
	HBITMAP _rabbitBitmap2, _hOldBitMap2;
	HDC _rabbitMemDC2;

	animation* _ani;
	animation* _aniStandLeft;
	animation* _aniStandRight;
	animation* _aniWalkLeft;
	animation* _aniWalkRight;
	animation* _aniAttackLeft;
	animation* _aniAttackRight;
	animation* _aniDeathAttackLeft;
	animation* _aniDeathAttackRight;
	animation* _aniDeadLeft;
	animation* _aniDeadRight;

	bool _isDeathSound;
public:
	killerRabbit();
	~killerRabbit();

	HRESULT init();
	void update(RECT rcPlayer,RECT rcShadow);
	void render();
	void release();

	void action(RECT rcPlayer, RECT rcShadow);
	void create(int x, int y);

public:
	bool getIsDeathAttack(){ return _isDeathAttack; }
	void setIsDeathAttack(bool deathAttack){ _isDeathAttack = deathAttack; }


};

