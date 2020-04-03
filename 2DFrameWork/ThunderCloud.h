#pragma once
#include "attackSkill.h"

#define FRAMETIMER 5
#define THUNDERCOUNT 5
#define THUNDERTIMER 100
#define SHOWTIMER 3
#define CLOUDSPEEDX 4
#define CLOUDSPEEDY 2
#define CLOUD_MOVE_TIMER 30
class ThunderCloud : public attackSkill
{
private:
	int _cloudX, _cloudY;
	int _thunderFrame;
	int _thunderCount;
	int _thunderTimer;
	int _showTimer;
	bool _isAttack;
	int _direction;
	int _moveTimer;
public:
	ThunderCloud();
	~ThunderCloud();

	HRESULT init();
	void update();
	void render();
	void release();

	void start(float x, float y, float shadowX, float shadowY);
};

