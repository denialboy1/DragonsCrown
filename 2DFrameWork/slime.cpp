#include "stdafx.h"
#include "slime.h"


slime::slime()
{
}


slime::~slime()
{
}

HRESULT slime::init(){
	motherEnemy::init();

	IMAGEMANAGER->addImage("빨강", "damageBuffer1.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaFrameImage("슬라임", "이미지/몬스터/슬라임/슬라임.bmp", 1024, 1024, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("slime_shadow", "이미지/소서리스/shadow.bmp", 230, 250, true, RGB(255, 0, 255));

	
	_ani = new animation;
	_ani->init(1024, 1024, 256, 256);
	_ani->setDefPlayFrame(false, true);
	_ani->setFPS(10);
	_ani->start();
	_deadAlpha = 255;

	//DC얻어온다
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//비트맵을 출력하기 위해서 메모리 DC를 만들어 주는 것

	//CreateCompatibleBitMap
	//원본 DC와 호환되는 비트맵 생성

	//이미지 정보 생성
	_slimeMemDC = CreateCompatibleDC(hdc);
	_slimeBitmap = (HBITMAP)CreateCompatibleBitmap(hdc, 256, 256);
	_hOldBitMap = (HBITMAP)SelectObject(_slimeMemDC, _slimeBitmap);

	_slimeMemDC2 = CreateCompatibleDC(hdc);
	_slimeBitmap2 = (HBITMAP)CreateCompatibleBitmap(hdc, 256, 256);
	_hOldBitMap2 = (HBITMAP)SelectObject(_slimeMemDC2, _slimeBitmap2);

	//얻은 DC 해제
	ReleaseDC(_hWnd, hdc);

	_isSlimeSound = false;
	_soundTimer = 0;
	return S_OK;
}
void slime::update(int playerX, int playerY, RECT rcPlayer, RECT rcShadow){
	motherEnemy::update();
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime()*1.0f);

	if (!_isSlimeSound){ 
		SOUNDMANAGER->play("슬라임", 0.1f); 
	_isSlimeSound = true;
	}
	if (_isSlimeSound){ _soundTimer++; }
	if (_soundTimer > SOUNDTIMER){
		_soundTimer = 0;
		_isSlimeSound = false;
	}
	
	if (!_isDamage){
		_rcEnemy = RectMake(_enemyX + 150, _enemyY + 280, 250, 200);
		_flicker = false;
	}
	else{
		_rcEnemy = RectMake(0, 0, 0, 0);
	}
	_rcAttack = RectMake(_enemyX + 150, _enemyY + 280, 250, 200);
	_rcShadow = RectMake(_rcAttack.left, _rcAttack.bottom, 250, 30);
	setRect(_rcShadow);

	if (_hp <= 0){
		_deadAlpha -= 2;
	}
	else{
		//이동
		if ((_rcShadow.left + _rcShadow.right) / 2 > (rcShadow.left + rcShadow.right) / 2){ _enemyX -= 1; }
		if ((_rcShadow.left + _rcShadow.right) / 2 < (rcShadow.left + rcShadow.right) / 2){ _enemyX += 1; }
		if ((_rcShadow.bottom + _rcShadow.top) / 2 > (rcShadow.top + rcShadow.bottom) / 2) _enemyY -= 1;
		if ((_rcShadow.bottom + _rcShadow.top) / 2 < (rcShadow.top + rcShadow.bottom) / 2) _enemyY += 1;

	}
	if (_deadAlpha < 10){
		setShow(false);
	}
}

void slime::render(){
	if (_isGhost){ return; }
	IMAGEMANAGER->findAlphaImage("slime_shadow")->alphaRender(getMemDC(), _rcShadow.left+15 , _rcShadow.top - 100, 150);
	IMAGEMANAGER->findAlphaImage("슬라임")->alphaAniRender(_slimeMemDC, 0, 0, _ani,_deadAlpha);
	if (_flicker){
		IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
		BitBlt(_slimeMemDC, 0, 0, 256, 256, getDamage1DC(), 0, 0, SRCPAINT);
		TransparentBlt(getMemDC(), _enemyX + 150, _enemyY + 260, 256, 256, _slimeMemDC, 0, 0, 256, 256, RGB(255, 0, 0));
	}
	else{
		TransparentBlt(getMemDC(), _enemyX +150, _enemyY + 260, 256, 256, _slimeMemDC, 0, 0, 256, 256, RGB(0, 0, 0));
	}
	PatBlt(_slimeMemDC, 0, 0, 256, 256, BLACKNESS);

	if (_debug){
		Rectangle(getMemDC(), _rcEnemy.left, _rcEnemy.top, _rcEnemy.right, _rcEnemy.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}

void slime::release(){}
void slime::notScreenOut(){
	if (_enemyX < 0){ _enemyX = 0; }
	if (_enemyX > WINSIZEX - 300) { _enemyX = WINSIZEX - 300; }
}

void slime::damage(int damage){
	if (!_isDamage){
		motherEnemy::damage(damage);
		_isDamage = true;
		_rcEnemy = { 0, 0, 0, 0 };
	}
}

void slime::create(int x, int y, int playerX){
	_enemyX = x;
	_enemyY = y;

	_hp = 100;

	_rcEnemy = RectMake(_enemyX + 150, _enemyY + 280, 250, 200);
	_rcAttack = RectMake(_enemyX + 150, _enemyY + 280, 250, 200);
	_rcShadow = RectMake(_rcEnemy.left, _rcEnemy.bottom, 250, 30);
	_attackDamage = 4;
	_isGhost = false;
	_soundTimer = RND->getInt(30);
}