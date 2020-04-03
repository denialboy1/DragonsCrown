#pragma once
#include "motherEnemy.h"

#define GOBLIN_WALK_SPEED 6
#define GOBLIN_RUN_SPEED 10
#define GOBLIN_ACTION_TIMER 10
enum GOBLIN_STATE{
	GOBLIN_APPER,
	GOBLIN_STAND,
	GOBLIN_WALK, 
	GOBLIN_RUN, 
	GOBLIN_ATTACK, 
	GOBLIN_ATTACK_AFTER,
	GOBLIN_DAMAGE, 
	GOBLIN_DAMAGE_AFTER,
	GOBLIN_DOWN, 
	GOBLIN_DEAD,
};

class goblin : public motherEnemy
{
public:
	GOBLIN_STATE _goblinState;
	bool _isDown;
	float _maxX;
	//여분 DC//
	HBITMAP _goblinBitmap, _hOldBitMap;
	HDC _goblinMemDC;

	//2번째 여분DC
	HBITMAP _goblinBitmap2, _hOldBitMap2;
	HDC _goblinMemDC2;


	
	bool _isAttack;		//공격
	bool _isEffect;
	int _effectTimer;
	int _effectTimerLimit;

	int _actionTimer;	//행동타이머
	int _actionRnd;

	int _deadAlpha;		//죽음

	bool _isAttackSound;
	bool _isDamageSound;
	bool _isDeadSound;
public:
	animation* _ani;	//에니메이션
	animation* _aniAttackRight;
	animation* _aniAttackLeft;
	animation* _aniDownRight;
	animation* _aniDownLeft;
	animation* _aniDamageRight;
	animation* _aniDamageLeft;
	animation* _aniRunRight;
	animation* _aniRunLeft;
	animation* _aniStandRight;
	animation* _aniStandLeft;
	animation* _aniWalkRight;
	animation* _aniWalkLeft;
public:
	goblin();
	~goblin();

	HRESULT init();
	void update(int playerX, int playerY, RECT rcPlayer, RECT rcShadow);
	void render();
	void release();

	void create(int x,int y,int playerX);
	void effectStart(int timer);
	void settingRect();
	void settingAnimation();
	void action(int playerX, int playerY, RECT rcPlayer, RECT rcShadow);
	void notScreenOut();
	void damage(int damage);
public:
	bool getAttack(){ return _isAttack; }
	void setAttack(bool isAttack){ _isAttack = isAttack; }
	void setMaxX(float x){ _maxX = x; }
	float getMaxX(){ return _maxX; }
	void setEnemyX(float x){ _enemyX = x; }
	float getEnemyX(){ return _enemyX; }
	void setEnemyY(float y){ _enemyY = y; }
	float getEnemyY(){ return _enemyY; }
	bool getIsRight(){ return _isRight; }
	bool getIsLeft(){ return _isLeft; }
	void setIsRight(bool isRight){ _isRight = isRight; }
	void setIsLeft(bool isLeft){ _isLeft = isLeft; }

};

