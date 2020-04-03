#pragma once
#include "gameNode.h"
#include "animation.h"


class barScene : public gameNode
{
private:
	//맨 위에 있는 현재창
	enum BARSTATE{ BAR, GAMESAVE };
	//현재 어떤 메뉴를 선택하고잇는지
	enum MENUSTATE{ SAVE, BAREXIT };
	//세이브 위치
	enum SAVESTATE{ SAVE1, SAVE2, SAVE3 };

private:
	animation* _fairy;
	BARSTATE _choiceState;
	MENUSTATE _menuState;
	SAVESTATE _saveState;
	int _menuChoice;
	int _saveChoice;
public:
	barScene();
	~barScene();

	HRESULT init();
	void update();
	void render();
	void release();


	void save1(char* fileName);
	void save2(char* fileName);
	void save3(char* fileName);
};

