#pragma once
#include "motherEnemy.h"

#define GHOST_ACTION_TIMER 30
#define DIRECTION_TIMER 30
#define SOUND_TIMER 50
class ghost : public motherEnemy
{
	enum STATE{STAND,WALK,DAMAGE};

public:
	//���� DC//
	HBITMAP _ghostBitmap, _hOldBitMap;
	HDC _ghostMemDC;

	//2��° ����DC
	HBITMAP _ghostBitmap2, _hOldBitMap2;
	HDC _ghostMemDC2;


	int _deadAlpha;		//����

	animation* _ani;
	animation* _aniDamageRgiht;
	animation* _aniDamageLeft;
	animation* _aniStandRight;
	animation* _aniStandLeft;

	STATE _state;

	int _actionTimer;	//�ൿŸ�̸�
	int _actionRnd;

	int _directionTimer;
	int _directionRnd;

	bool _isGhostSound;
	bool _isDeadSound;
	bool _isDamageSound;
	int _soundTimer;
public:
	ghost();
	~ghost();

	HRESULT init();
	void update(int playerX, int playerY, RECT rcPlayer, RECT rcShadow);
	void render();
	void release();

	void create(int x, int y, int playerX);
	void damage(int damage);
	void notScreenOut();
};

