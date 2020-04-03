#pragma once
#include "gameNode.h"
class damageShow : public gameNode
{
public:
	struct tagDamage{
		int x, y;
		int limitY;
		int damage;
		bool enemy;
	};

	vector<tagDamage> _vDamage;
	vector<tagDamage>::iterator _viDamage;
public:
	damageShow();
	~damageShow();

	HRESULT init();
	void update();
	void render();
	void release();
	void start(int x, int y, int damage,bool enemy);
};

