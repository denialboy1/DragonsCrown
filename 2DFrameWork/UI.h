#pragma once
#include "gameNode.h"
#include "progressBar.h"

class player;
class UI : public gameNode
{
private: 
	RECT _rc;
	player* _player;
	progressBar* _hpBar;
public:
	UI();
	~UI();

	HRESULT init();
	void update();
	void render();
	void release();

	void addPlayerAddress(player* player){ _player = player; }
};

