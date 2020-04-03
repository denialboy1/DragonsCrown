#pragma once
#include "gameNode.h"
#include "damageShow.h"
class player;
class mamaball;
class normalBullet1;
class normalBullet2;
class normalBullet3;
class normalBullet4;
class normalBullet5;
class skillManager;

class motherEnemy;
class fireFloor;
class fireRain;
class fireWorld;

#define NORMAL1_TIMER 30
#define NORMAL2_TIMER 30
#define BLIZZARD_TIMER 10
#define GRAVITY_TIMER 10
#define THUNDERCLOUD_TIMER 5

#define DAMAGE_EFFECT_TIMER 13
class battle : public gameNode
{
private:
	//�÷��̾�
	player* _player;
	mamaball* _manaball;
	normalBullet1* _normalBullet1;
	normalBullet2* _normalBullet2;
	int _normal1Timer;
	int _normal2Timer;
	normalBullet3* _normalBullet3;
	normalBullet4* _normalBullet4;
	normalBullet5* _normalBullet5;
	skillManager* _skillManager;
	int _blizzardTimer;
	int _gravityTimer;
	int _thunderCloudTimer;
	//���ʹ�
	motherEnemy* _enemy;

	//���巡�ｺų
	fireFloor* _fireFloor;
	fireRain* _fireRain;
	fireWorld* _fireWorld;


	//ų������
	
	//�ǰ�
	struct tagDamageEffect{
		bool isCollision;
		RECT rcCollision;
		int frameX;
		int frameY;
		int alpha1;
		int alpha2;
		int frameTimer;
	};
	int _damage;

	typedef vector<tagDamageEffect> VTagDamageEffect;
	typedef vector<tagDamageEffect>::iterator VITagDamageEffect;

	VTagDamageEffect _vTagDamageEffect;
	VITagDamageEffect _viTagDamageEffect;
	
	damageShow* _damageShow;
public:
	battle();
	~battle();

	HRESULT init();
	void update(void);
	void render();

	void playerAttack();
	void playerVSDragonSkillAttack();
	void enemyAttack();
	void dragonSkillAttack();

	
public:
	void linkPlayerAddress(player* player1){ _player = player1; }
	void linkManaballAddress(mamaball* manaball){ _manaball = manaball; }
	void linkNormalBullet1Address(normalBullet1* normalBullet1){ _normalBullet1 = normalBullet1; }
	void linkNormalBullet2Address(normalBullet2* normalBullet2){ _normalBullet2 = normalBullet2; }
	void linkNormalBullet3Address(normalBullet3* normalBullet3){ _normalBullet3 = normalBullet3; }
	void linkNormalBullet4Address(normalBullet4* normalBullet4){ _normalBullet4 = normalBullet4; }
	void linkNormalBullet5Address(normalBullet5* normalBullet5){ _normalBullet5 = normalBullet5; }
	void linkSkillManagerAddress(skillManager* skillManager){ _skillManager = skillManager; }

	void linkEnemyAddress(motherEnemy* enemy){ _enemy = enemy; }
	void linkFireFloorAddress(fireFloor* fireFloor){ _fireFloor = fireFloor; }
	void linkFireRainAddress(fireRain* fireRain){ _fireRain = fireRain; }
	void linkFireWorldAddress(fireWorld* fireWorld){ _fireWorld = fireWorld; }

public:
	//�÷��̾� vs enemy
	void manaball();
	void normalBullet1();
	void normalBullet2();
	void normalBullet3();
	void normalBullet4();
	void normalBullet5();
	void skillManager();
	//�÷��̾� vs floor
	void floorVSmanaball();
	void floorVSnormalBullet1();
	void floorVSnormalBullet2();
	void floorVSnormalBullet3();
	void floorVSnormalBullet4();
	void floorVSnormalBullet5();
	void floorVSskillManager();

	//���巡��
	void fireFloor();
	void fireRain();
	void fireWorld();
};

