#pragma once
#include "motherEnemy.h"

#define DAMAGE_TIMER 10

//첫 등장 불값
static bool _isOpening;

enum DRAGON_STATE{ NORMAL, DEAD, FIRE_FLOOR, FIRE_RAIN, FIRE_WORLD };
static DRAGON_STATE _dragonState;
class ancientDragon : public motherEnemy
{	
public:
	

	bool _isFireFloor;
	bool _isFireRain;
	bool _isFireWorld;
	int _y;

	int _attackTimer;

	int _damageTimer;
	bool _flicker;
public:
	ancientDragon();
	~ancientDragon();

	HRESULT init();
	void update();
	void render();
	void release();

	static void cbAppear();
	static void cbNormal();
	static void cbDead();
	void pattern();

public:
	bool getIsFireFloor(){ return _isFireFloor; }
	void setIsFireFloor(bool fireFloor){ _isFireFloor = fireFloor; }
	bool getIsFireRain(){ return _isFireRain; }
	void setIsFireRain(bool fireRain){ _isFireRain = fireRain; }
	bool getIsFireWorld(){ return _isFireWorld; }
	void setIsFireWorld(bool fireWorld){ _isFireWorld = fireWorld; }
};

