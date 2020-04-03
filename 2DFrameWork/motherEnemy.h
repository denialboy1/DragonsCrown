#pragma once
#include "gameNode.h"
class motherEnemy : public gameNode
{
protected:
	int _hp, _hpMax;
	int _attackDamage;
	float _enemyX, _enemyY;

	RECT _rcEnemy;
	RECT _rcShadow;
	RECT _rcAttack;
	RECT _rcRange;
	bool _isDamage;
	bool _isDie;

	bool _isRight;
	bool _isLeft;

	bool _flicker;
	bool _isPetri;
	bool _isGhost;
	int _petriTimer;
	int _damageTimer;

public:
	motherEnemy();
	~motherEnemy();

	HRESULT init();
	void update();

	void damage(int damage);

public:
	int getHp(){ return _hp; }
	void setHp(int hp){ _hp = hp; }
	int getMaxHp(){ return _hpMax; }
	void setMaxHp(int hpMax){ _hpMax = hpMax; }
	bool getIsDamage(){ return _isDamage; }
	void setIsDamage(bool isDamage){ _isDamage = isDamage; }
	bool getIsDie(){ return _isDie; }
	void setIsDie(bool isDie){ _isDie = isDie; }
	RECT getRcEnemy(){ return _rcEnemy; }
	RECT getRcShadow() { return _rcShadow; }
	RECT getRcAttack(){ return _rcAttack; }
	bool getIsRight(){ return _isRight; }
	bool getIsLeft(){ return _isLeft; }
	float getEnemyX(){ return _enemyX; }
	void setEnemyX(float enemyX){ _enemyX = enemyX; }
	float getEnemyY(){ return _enemyY; }
	void setEnemyY(float enemyY){ _enemyY = enemyY; }
	void setIsPetri(bool isPetri){ _isPetri = isPetri; }
	bool getIsPetri(){ return _isPetri; }
	bool getIsGhost(){ return _isGhost; }
	void setIsGhost(bool isGhost){ _isGhost = isGhost; }
	int getAttackDamage(){ return _attackDamage; }
};

