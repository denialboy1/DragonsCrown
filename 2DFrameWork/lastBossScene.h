#pragma once
#include "gameNode.h"
//고대드래곤
#include "ancientDragon.h"
#include "fireRain.h"
#include "fireWorld.h"
#include "fireFloor.h"
#include "progressBar.h"
//플레이어
#include "player.h"
#include "normalBullet1.h"
#include "normalBullet2.h"
#include "normalBullet3.h"
#include "normalBullet4.h"
#include "normalBullet5.h"
#include "mamaball.h"
#include "UI.h"
#include "skillManager.h"
#include "objectCollision.h"


#include "battle.h"

#define DEAD_EFFECT_SHOW 60

class lastBossScene : public gameNode
{
private:
	//고대 드래곤
	ancientDragon* _dragon;
	fireRain* _fireRain;
	vector<fireRain> _vFireRain;
	vector<fireRain>::iterator _viFireRain;
	fireWorld* _fireWorld;
	fireFloor* _fireFloor;
	progressBar* _hpBar;

	//플레이어
	UI* _ui;
	normalBullet1* _normalBullet1[8];
	normalBullet1* _normalBullet2[5];
	normalBullet2* _normalBullet3;
	normalBullet3* _normalBullet4;
	normalBullet4* _normalBullet5;
	normalBullet5* _normalBullet6;
	mamaball* _manaball1;
	mamaball* _manaball2;
	skillManager* _skillManager;
	objectCollision* _objectCollision;
	player* _player; 
	int _position;

	//배경 움직임
	int _offX;

	//보스죽음 프레임
	float _deadFrameX;
	int _deadEffectTimer;
	bool _deadEffectEnd;
	int _deadEffectAlpha;
	//배틀
	battle* _battle;

	//zOrder용#in
	vector<gameNode*> _zOrder;
	vector<gameNode*>::iterator _viZOrder;

	
public:
	lastBossScene();
	~lastBossScene();

	HRESULT init();
	void update();
	void render();
	void release();

	void fireFloorAttack();
	void fireRainAttack();
	void fireWorldAttack();

	//플레이어
	void skill();
};

