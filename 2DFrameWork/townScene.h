#pragma once
#include "gameNode.h"
#include "player.h"
#include "menu.h"
#include "normalBullet1.h"
#include "normalBullet2.h"
#include "normalBullet3.h"
#include "normalBullet4.h"
#include "normalBullet5.h"
#include "mamaball.h"
#include "UI.h"
#include "skillManager.h"
#include "objectCollision.h"

class townScene : public gameNode
{
	enum WINDOW{TOWN,MENU};
private:
	WINDOW _window;

	menu* _menu;
	UI* _ui;
private:
	normalBullet1* _normalBullet1[8];
	normalBullet1* _normalBullet2[5];
	normalBullet2* _normalBullet3;
	normalBullet3* _normalBullet4;
	normalBullet4* _normalBullet5;
	normalBullet5* _normalBullet6;
	mamaball* _manaball1;
	mamaball* _manaball2;
	rockPress* _rockPress;
	skillManager* _skillManager;
	objectCollision* _objectCollision;
private:
	float _loopX;		//배경 루프용

	float _townX, _townY;	//마을 좌표
	float _lucainTowerX, lucainTowerY;
	float _castleX, _castleY;
	float _villege1X,_villege1Y;
	float _villege2X, _villege2Y;
	float _villege3X, _villege3Y;
	float _villege4X, _villege4Y;
	float _villege5X, _villege5Y;

	//간판 등장
	RECT _rcBarSignBoard;
	RECT _rcGuildSignBoard;
	RECT _rcShopSignBoard;
	RECT _rcDungeonSignBoard;

	//float _villege6X, _villege5Y;
	player* _player; //플레이어
	
	bool _screenMove;	//화면 움직임 불값
	float _townSpeedRate;
	bool _edgeEnd;		//화면 끝에 닿을경우

	RECT _rcBar;
	RECT _rcShop;
	RECT _rcGuild;
	RECT _rcDungeon;

	int _position;
	
	//zOrder용#in
	vector<gameNode*> _zOrder;
	vector<gameNode*>::iterator _viZOrder;

	//룬
	int _lightFrameX;
	int _lightFrameY;
	int _lightX, _lightY;
	float _frameTimer;
	RECT _rcZRune;
	bool _isZClick;
	bool _isClickCount;
	int _rmz[3];
	bool _rmzAction;
	bool _blackAction;
	float _blackActionTimer;
	bool _lightAction;
	bool _showRoom[3];
	int _runeRoom[3];		//1 : D , 2 : E , 3 : M , 4 : R, 5 : S , 6 : T, 7 : Z
	int _runeRoomCount;
	RECT _rcDRune;
	RECT _rcERune;
	RECT _rcMRune;
	RECT _rcRRune;
	RECT _rcSRune;
	RECT _rcTRune;
	int _runeAlpha;
	int _rmzOffX;
public:
	townScene();
	~townScene();

	HRESULT init();
	void update();
	void render();
	void release();

	void dataSave(int x,int y,int absX,int absY);

	void skill();

	void rune();
};

