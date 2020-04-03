#pragma once
#include "gameNode.h"

class openingScene : public gameNode
{
	//세이브 위치
	enum SAVESTATE{ SAVE1, SAVE2, SAVE3 };
	enum WINDOWSTATE{ OPENING, SAVELOAD };
private:
	SAVESTATE _saveState;
	int _saveChoice;

	WINDOWSTATE _windowState;
public:
	openingScene();
	~openingScene();

	HRESULT init();
	void update();
	void render();
	void release();

	void createData(char* fileName);
	void loadData(char* fileName);
};

