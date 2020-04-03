#include "stdafx.h"
#include "motherEnemy.h"


motherEnemy::motherEnemy()
{
}


motherEnemy::~motherEnemy()
{
}

HRESULT motherEnemy::init(){
	_hp = 100;
	_hpMax = 100;

	_enemyX = 0;
	_enemyY = 0;

	_rcEnemy = RectMake(0, 0, 0, 0);
	_rcShadow = RectMake(0, 0, 0, 0);

	_isDamage = false;
	_isDie = false;
	_flicker = false;
	_damageTimer = 0;
	_isPetri = false;
	_petriTimer = 0;
	return S_OK;
}

void motherEnemy::update(){
	if (_hp <= 0){ _isDie = true; }

	//데미지
	if (_isDamage){
		if (_damageTimer > 10){
			_isDamage = false;
			_damageTimer = 0;
		}
		if (_damageTimer % 2 == 0){
			_flicker ? _flicker = false : _flicker = true;
		}
		_damageTimer++;
	}

	//석화
	if (_isPetri){
		_petriTimer++;
		if (_petriTimer > 200 + INIDATA->loadDataInterger("PlayerData", "Skill", "petrification")*50){
			_isPetri = false;
			_petriTimer = 0;
		}
	}
}

void motherEnemy::damage(int damage){
	_isDamage = true;
	_flicker = false;
	_damageTimer = 0;
	_hp -= damage;
}