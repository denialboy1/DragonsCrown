#pragma once
#include "gameNode.h"
#include "menu.h"
class menuScene : public gameNode
{
private:
	menu* _menu;
public:
	menuScene();
	~menuScene();

	HRESULT init();
	void update();
	void render();
	void release();

};

