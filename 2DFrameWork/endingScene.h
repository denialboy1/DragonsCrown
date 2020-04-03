#pragma once
#include "gameNode.h"
class endingScene : public gameNode
{
public:
	endingScene();
	~endingScene();

	HRESULT init();
	void update();
	void render();
	void release();
};

