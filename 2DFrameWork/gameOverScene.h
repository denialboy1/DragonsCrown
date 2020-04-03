#pragma once
#include "gameNode.h"
class gameOverScene : public gameNode
{
public:
	int _alpha1;
	int _alpha2;
	//bool _

public:
	gameOverScene();
	~gameOverScene();

	HRESULT init();
	void update();
	void render();
	void release();
};

