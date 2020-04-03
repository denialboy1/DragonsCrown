#pragma once
#include "gameNode.h"
#include "bag.h"
#include "inven.h"
#include "state.h"
#include "skillInfo.h"
class menu : public gameNode
{
	enum WINDOW{MENU,INVEN,BAG,STATE,SKILL};

private:
	WINDOW _window;
	bag* _bag;
	inven* _inven;
	state* _state;
	skillInfo* _skillInfo;

	int _windowChoice;

public:
	menu();
	~menu();

	HRESULT init();
	void update();
	void render();
	void release();

	void keyInput();
};

