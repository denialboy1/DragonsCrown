#pragma once
#include "gameNode.h"
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

//몬스터
#include "goblin.h"
#include "trap.h"
#include "slime.h"
#include "ghost.h"
#include "killerRabbit.h"
#include "deathAttack.h"
//배틀
#include "battle.h"

#define EXP 1000 
class graveScene : public gameNode
{
	enum STAGE{ STAGE1, STAGE2, STAGE3, STAGE4};
public:
	//스테이지
	STAGE _stage;
	float _stageOffX;
	float _bgOffX;
	bool _isScreenFix;
	bool _stage1_1Start;
	bool _stage1_2Start;
	bool _stage1_3Start;
	bool _stage1_4Start;
	bool _stage2Start;
	bool _stage3_1Start;
	bool _stage3_2Start;
	bool _stage3_3Start;
	bool _stage3_4Start;
	bool _stage4Start;
	bool _stage1_1Clear;
	bool _stage1_2Clear;
	bool _stage1_3Clear;
	bool _stage1_4Clear;
	bool _stage2Clear;
	bool _stage3_1Clear;
	bool _stage3_2Clear;
	bool _stage3_3Clear;
	bool _stage3_4Clear;
	bool _stage4Clear;
	int _stageChangeAlpha;			//스테이지화면 바꾸는 연출을 위한 알파값
	bool _isStageChange;
	bool _isAlphaUp;
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
	progressBar* _expBar;
	//고블린
	goblin* _goblin1;
	goblin* _goblin2;
	goblin* _goblin3;
	goblin* _goblin4;
	vector<goblin*> _vGoblin;
	vector<goblin*>::iterator _viGoblin;

	//함정
	trap* _trap1[9];
	trap* _trap2[9];
	trap* _trap3[9];
	trap* _trap4[9];
	vector<trap*> _vTrap;
	vector<trap*>::iterator _viTrap;

	//슬라임
	slime* _slime1;
	slime* _slime2;
	slime* _slime3;
	slime* _slime4;
	slime* _slime5;
	slime* _slime6;
	slime* _slime7;
	slime* _slime8;
	slime* _slime9;
	slime* _slime10;
	vector<slime*> _vSlime;
	vector<slime*>::iterator _viSlime;

	//고스트
	ghost* _ghost1;
	ghost* _ghost2;
	vector<ghost*> _vGhost;
	vector<ghost*>::iterator _viGhost;

	//킬러레빗
	killerRabbit* _killerRabbit;
	deathAttack* _deathAttack;
	//배틀
	battle* _battle;

	//룬
	int _lightFrameX;
	int _lightFrameY;
	int _lightX, _lightY;
	float _frameTimer;
	RECT _rcZRune;
	bool _isZClick;
	bool _isIClick;
	bool _isClickCount;
	int _die[3];
	bool _rmzAction;
	bool _dieAction;
	bool _blackAction;
	float _blackActionTimer;
	bool _lightAction;
	bool _showRoom[3];
	int _runeRoom[3];		//1 : D , 2 : E , 3 : M , 4 : R, 5 : S , 6 : T, 7 : Z, 8:I
	int _runeRoomCount;
	RECT _rcDRune;
	RECT _rcERune;
	RECT _rcMRune;
	RECT _rcRRune;
	RECT _rcSRune;
	RECT _rcTRune;
	RECT _rcIRune;
	int _runeAlpha;
	int _dieOffX;
	bool _isDie;

	//zOrder용#in
	vector<gameNode*> _zOrder;
	vector<gameNode*>::iterator _viZOrder;

	motherEnemy* _mother;
	vector<motherEnemy*> _vMother;
	vector<motherEnemy*>::iterator _viMother;

	int _exp;

	int _talizman[9];
	int _isGain;

	progressBar* _hpBar;
public:
	graveScene();
	~graveScene();

	HRESULT init();
	void render();
	void update();
	void release();

	//플레이어
	void skill();
	void save();
	void trapSetup(trap** trap,int x, int y);

	bool getDieAction(){ return _dieAction; }
};

