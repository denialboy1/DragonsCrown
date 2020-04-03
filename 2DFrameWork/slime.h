#pragma once
#include "motherEnemy.h"

#define SOUNDTIMER 15
class slime : public motherEnemy
{
public :
	//���� DC//
	HBITMAP _slimeBitmap, _hOldBitMap;
	HDC _slimeMemDC;

	//2��° ����DC
	HBITMAP _slimeBitmap2, _hOldBitMap2;
	HDC _slimeMemDC2;


	int _deadAlpha;		//����

	animation* _ani;
	
	bool _isSlimeSound;
	int _soundTimer;
public:
	slime();
	~slime();

	HRESULT init();
	void update(int playerX, int playerY, RECT rcPlayer, RECT rcShadow);
	void render();
	void release();

	void create(int x, int y, int playerX);
	void damage(int damage);
	void notScreenOut();
};

