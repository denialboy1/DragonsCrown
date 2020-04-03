#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include "player.h"
class state : public gameNode
{
private:
	progressBar* _expBar;
	player* _player;
public:
	state();
	~state();

	HRESULT init();
	void render();
	void update();
	void release();

};

