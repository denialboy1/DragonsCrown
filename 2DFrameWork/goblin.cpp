#include "stdafx.h"
#include "goblin.h"
#include "player.h"

goblin::goblin()
{
}


goblin::~goblin()
{
}

HRESULT goblin::init(){
	motherEnemy::init();

	IMAGEMANAGER->addFrameImage("goblin_attack", "이미지/몬스터/고블린/goblin_attack.bmp", 1800, 1000, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("goblin_down", "이미지/몬스터/고블린/goblin_down.bmp", 2328, 1200, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("goblin_damage", "이미지/몬스터/고블린/goblin_damage.bmp", 1500, 1000, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("goblin_run", "이미지/몬스터/고블린/goblin_run.bmp", 5500, 1000, 11, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("goblin_stand", "이미지/몬스터/고블린/goblin_stand.bmp", 2500, 1100, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("goblin_walk", "이미지/몬스터/고블린/goblin_walk.bmp", 2500, 1000, 5, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("goblin_shadow", "이미지/소서리스/shadow.bmp", 230, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("goblin_shadow2", "이미지/소서리스/shadow.bmp", 300, 250, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("빨강", "damageBuffer1.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("회색", "이미지/회색.bmp", 1600, 900, false, RGB(255, 0, 255));

	

	int arr1[] = { 0, 1, 2, 3, 4, 5 };
	int arr2[] = { 6,7,8,9,10,11 };
	int arr5[] = { 0,1,2,3 };
	int arr6[] = { 4, 5, 6, 7 };
	int arr7[] = { 0,1,2 };
	int arr8[] = { 3,4,5 };
	int arr9[] = {0,1,2,3,4,5,6,7,8,9,10 };
	int arr10[] = { 11,12,13,14,15,16,17,18,19,20,21 };
	int arr11[] = { 0,1,2,3,4,3,2,1 };
	int arr12[] = {5,6,7,8,9,8,7,6 };
	int arr13[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arr14[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21 };

	_aniAttackRight = new animation;
	_aniAttackRight->init(1800, 1000, 300, 500);
	_aniAttackRight->setPlayFrame(arr1, sizeof(arr1) / sizeof(int), false);
	_aniAttackRight->setFPS(10);

	_aniAttackLeft = new animation;
	_aniAttackLeft->init(1800, 1000, 300, 500);
	_aniAttackLeft->setPlayFrame(arr2, sizeof(arr2) / sizeof(int), false);
	_aniAttackLeft->setFPS(10);

	_aniDownRight = new animation;
	_aniDownRight->init(2328, 1200, 582, 600);
	_aniDownRight->setPlayFrame(arr5, sizeof(arr5) / sizeof(int), false);
	_aniDownRight->setFPS(10);

	_aniDownLeft = new animation;
	_aniDownLeft->init(2328, 1200, 582, 600);
	_aniDownLeft->setPlayFrame(arr6, sizeof(arr6) / sizeof(int), false);
	_aniDownLeft->setFPS(10);

	_aniDamageRight = new animation;
	_aniDamageRight->init(1500, 1000, 500, 500);
	_aniDamageRight->setPlayFrame(arr7, sizeof(arr7) / sizeof(int), false);
	_aniDamageRight->setFPS(10);

	_aniDamageLeft = new animation;
	_aniDamageLeft->init(1500, 1000, 500, 500);
	_aniDamageLeft->setPlayFrame(arr8, sizeof(arr8) / sizeof(int), false);
	_aniDamageLeft->setFPS(10);

	_aniRunRight = new animation;
	_aniRunRight->init(5500, 1000, 500, 500);
	_aniRunRight->setPlayFrame(arr9, sizeof(arr9) / sizeof(int), true);
	_aniRunRight->setFPS(15);

	_aniRunLeft = new animation;
	_aniRunLeft->init(5500,1000,500,500);
	_aniRunLeft->setPlayFrame(arr10, sizeof(arr10) / sizeof(int), true);
	_aniRunLeft->setFPS(15);

	_aniStandRight = new animation;
	_aniStandRight->init(2500, 1100, 500, 550);
	_aniStandRight->setPlayFrame(arr11, sizeof(arr11) / sizeof(int), true);
	_aniStandRight->setFPS(7);

	_aniStandLeft = new animation;
	_aniStandLeft->init(2500, 1100, 500, 550);
	_aniStandLeft->setPlayFrame(arr12, sizeof(arr12) / sizeof(int), true);
	_aniStandLeft->setFPS(7);

	_aniWalkRight = new animation;
	_aniWalkRight->init(5500, 1000, 500, 500);
	_aniWalkRight->setPlayFrame(arr13, sizeof(arr13) / sizeof(int), true);
	_aniWalkRight->setFPS(10);

	_aniWalkLeft = new animation;
	_aniWalkLeft->init(5500,1000,500,500);
	_aniWalkLeft->setPlayFrame(arr14, sizeof(arr14) / sizeof(int), true);
	_aniWalkLeft->setFPS(10);

	_goblinState = GOBLIN_STAND;

	_ani = _aniStandRight;
	EFFECTMANAGER->addEffect("goblin_effect_right", "이미지/몬스터/고블린/goblin_effect_right.bmp", 2000, 500, 500, 500, 1, 0.25, 10);
	EFFECTMANAGER->addEffect("goblin_effect_left", "이미지/몬스터/고블린/goblin_effect_left.bmp", 2000, 500, 500, 500, 1, 0.25, 10);

	//////////////고블린 이미지를 석화 또는 데미지 상태로 보여주기 위한 여분 DC////////////////
	//DC얻어온다
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//비트맵을 출력하기 위해서 메모리 DC를 만들어 주는 것

	//CreateCompatibleBitMap
	//원본 DC와 호환되는 비트맵 생성

	//이미지 정보 생성
	_goblinMemDC = CreateCompatibleDC(hdc);
	_goblinBitmap = (HBITMAP)CreateCompatibleBitmap(hdc, 600,600);
	_hOldBitMap = (HBITMAP)SelectObject(_goblinMemDC, _goblinBitmap);

	_goblinMemDC2 = CreateCompatibleDC(hdc);
	_goblinBitmap2 = (HBITMAP)CreateCompatibleBitmap(hdc, 600, 600);
	_hOldBitMap2 = (HBITMAP)SelectObject(_goblinMemDC2, _goblinBitmap2);

	//얻은 DC 해제
	ReleaseDC(_hWnd, hdc);


	//CreateCompatibleDC
	//비트맵을 출력하기 위해서 메모리 DC를 만들어 주는 것

	//CreateCompatibleBitMap
	//원본 DC와 호환되는 비트맵 생성

	//이미지 정보 생성
	

	//얻은 DC 해제

	//////////////////////////////////////////////////////////////////////////
	_maxX = 0;
	_isPetri = false;
	_isAttack = false;
	_isEffect = false;
	_actionTimer = 0;
	_actionRnd = 0;
	_isDown = false;
	_deadAlpha = 255;
	_isGhost = false;

	_isAttackSound = false;
	_isDamageSound = false;
	_isDeadSound = false;
	return S_OK;
}
void goblin::update(int playerX, int playerY,RECT rcPlayer,RECT rcShadow){
	motherEnemy::update();
	if (_isPetri){
		_ani->pause();
	}
	else { 
		_ani->resume(); }
	if (_isPetri){ return; }
	//행동
	action(playerX, playerY, rcPlayer, rcShadow);

	if (KEYMANAGER->isOnceKeyDown('1')){
		_goblinState = GOBLIN_STAND;
	}
	
	if (KEYMANAGER->isOnceKeyDown('2')){
		_goblinState = GOBLIN_WALK;
	}

	if (KEYMANAGER->isOnceKeyDown('3')){
		_goblinState = GOBLIN_RUN;
	}

	if (KEYMANAGER->isOnceKeyDown('4')){
		_goblinState = GOBLIN_ATTACK;
	}
	

	if (KEYMANAGER->isOnceKeyDown('5')){
		_goblinState = GOBLIN_DAMAGE;
	}

	if (KEYMANAGER->isOnceKeyDown('6')){
		_goblinState = GOBLIN_DOWN;
	}
	

	if (KEYMANAGER->isOnceKeyDown('I')){
		_isLeft = true;
		_isRight = false;
	}

	if (KEYMANAGER->isOnceKeyDown('O')){
		_isLeft = false;
		_isRight = true;
	}
	if (_goblinState != GOBLIN_RUN && _goblinState != GOBLIN_APPER && _goblinState != GOBLIN_DAMAGE_AFTER){
		//고블린 방향
		if (playerX > _enemyX){
			_isRight = true;
			_isLeft = false;
		}
		if (playerX < _enemyX){
			_isLeft = true;
			_isRight = false;
		}
	}
	//고블린 애니메이션 설정
	settingAnimation();

	//rect설정
	settingRect();
	setRect(_rcShadow);
	//이펙트
	if (_isEffect){
		_effectTimer += 1;
		if (_effectTimer > _effectTimerLimit){
			if (_isRight)
				EFFECTMANAGER->play("goblin_effect_right", _enemyX + 220, _enemyY + 200);
			else if (_isLeft)
				EFFECTMANAGER->play("goblin_effect_left", _enemyX + 180, _enemyY + 200);
			_isEffect = false;
		}
	}

	//화면 바깥으로 못나가게하기
	if (_goblinState != GOBLIN_APPER){
		notScreenOut();
	}
	
	//죽음
	if (_hp <= 0){
		_goblinState = GOBLIN_DOWN;
		if (!_isDeadSound){
			SOUNDMANAGER->play("고블린죽음", 0.1f);
			_isDeadSound = true;
		}
	}
	if (_isDown){
		setShow(false);
	}
}
void goblin::render(){
	if (_isGhost){ return; }
	IMAGEMANAGER->findImage("회색")->render(_goblinMemDC2, 0, 0);
	
	switch (_goblinState){
	case GOBLIN_STAND:
		IMAGEMANAGER->findAlphaImage("goblin_shadow")->alphaRender(getMemDC(), _rcShadow.left - 60, _rcShadow.top - 100, 150);
		IMAGEMANAGER->findImage("goblin_stand")->aniRender(_goblinMemDC, 0, 0, _ani);
		break;
	case GOBLIN_WALK:
		IMAGEMANAGER->findAlphaImage("goblin_shadow")->alphaRender(getMemDC(), _rcShadow.left - 60, _rcShadow.top - 100, 150);
		IMAGEMANAGER->findImage("goblin_run")->aniRender(_goblinMemDC, 0, 0, _ani);
		break;
	case GOBLIN_APPER:
	case GOBLIN_RUN:
		IMAGEMANAGER->findAlphaImage("goblin_shadow")->alphaRender(getMemDC(), _rcShadow.left - 60, _rcShadow.top - 100, 150);
		IMAGEMANAGER->findImage("goblin_run")->aniRender(_goblinMemDC, 0, 0, _ani);
		break;
	case GOBLIN_ATTACK:
		IMAGEMANAGER->findAlphaImage("goblin_shadow")->alphaRender(getMemDC(), _rcShadow.left - 60, _rcShadow.top - 100, 150);
		IMAGEMANAGER->findImage("goblin_attack")->aniRender(_goblinMemDC, 0, 0, _ani);
		break;
	case GOBLIN_DAMAGE:
		IMAGEMANAGER->findAlphaImage("goblin_shadow")->alphaRender(getMemDC(), _rcShadow.left - 60, _rcShadow.top - 100, 150);
		IMAGEMANAGER->findImage("goblin_damage")->aniRender(_goblinMemDC, 0, 0, _ani);
		break;
	case GOBLIN_DOWN:
		IMAGEMANAGER->findAlphaImage("goblin_shadow2")->alphaRender(getMemDC(), _rcShadow.left - 60, _rcShadow.top - 100, 150);
		IMAGEMANAGER->findImage("goblin_down")->aniRender(_goblinMemDC, 0, 0, _ani);
		break;
	case GOBLIN_DEAD:
		break;
	}

	if (_isPetri){
		BitBlt(_goblinMemDC, 0, 0, 600, 600, _goblinMemDC2, 0, 0, SRCPAINT);
	}
	//불값에 따라 고속복사종류가 다름
	switch (_goblinState){
	case GOBLIN_STAND:
		if (_isPetri){
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX - 10, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX - 70, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		}
		else{
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX - 10, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX - 70, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		}
		break;
	case GOBLIN_WALK:
		if (_isPetri){
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX, _enemyY + 18, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX - 100, _enemyY + 18, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		}
		else{
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX, _enemyY+18, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX-100, _enemyY+18, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		}
		break;
	case GOBLIN_APPER:
	case GOBLIN_RUN:
		if (_isPetri){
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX, _enemyY + 18, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX - 100, _enemyY + 18, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		}
		else{
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX, _enemyY+18, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX - 100, _enemyY+18, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		}
		break;
	case GOBLIN_ATTACK:
		if (_isPetri){
			if (_isRight){
				TransparentBlt(getMemDC(), _enemyX + 100, _enemyY + 20, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			}
			if (_isLeft){
				TransparentBlt(getMemDC(), _enemyX, _enemyY + 20, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			}
		}
		else{
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX +100, _enemyY+20, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX, _enemyY+20, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		}
		break;
	case GOBLIN_DAMAGE:
		if (_isPetri){
			if (_isRight){
				TransparentBlt(getMemDC(), _enemyX - 20, _enemyY + 30, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			}
			if (_isLeft){
				TransparentBlt(getMemDC(), _enemyX - 50, _enemyY + 30, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			}
		}
		else{
			if (_isRight){
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_goblinMemDC, 0, 0, 600, 600, getDamage1DC(), 0, 0, SRCAND);
					TransparentBlt(getMemDC(), _enemyX - 20, _enemyY + 30, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX - 20, _enemyY + 30, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
				}

			}
			if (_isLeft){
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_goblinMemDC, 0, 0, 600, 600, getDamage1DC(), 0, 0, SRCAND);
					TransparentBlt(getMemDC(), _enemyX - 50, _enemyY + 30, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX - 50, _enemyY + 30, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
				}

			}
		}
		break;
	case GOBLIN_DOWN:
		if (_isPetri){
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX - 100, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(125,125,125));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(125,125,125));
		}
		else{
			if (_isRight)
				TransparentBlt(getMemDC(), _enemyX - 100, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
			if (_isLeft)
				TransparentBlt(getMemDC(), _enemyX, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		}
		break;
	case GOBLIN_DEAD:
		if (_isRight)
			TransparentBlt(getMemDC(), _enemyX, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		if (_isLeft)
			TransparentBlt(getMemDC(), _enemyX, _enemyY, 600, 600, _goblinMemDC, 0, 0, 600, 600, RGB(255, 255, 255));
		break;
	}
	
	EFFECTMANAGER->render();

	PatBlt(_goblinMemDC, 0, 0, 600, 600, WHITENESS);
	if (_debug){
		Rectangle(getMemDC(), _rcEnemy.left, _rcEnemy.top, _rcEnemy.right, _rcEnemy.bottom);
		Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
		Rectangle(getMemDC(), _rcRange.left, _rcRange.top, _rcRange.right, _rcRange.bottom);
	}

}
void goblin::release(){}

void goblin::create(int x, int y,int playerX){
	_goblinState = GOBLIN_APPER;
	_enemyX = x;
	_enemyY = y;
	
	_hp = 300;
	_attackDamage = 10;
	if (playerX > x){
		_isRight = true;
		_isLeft = false;
		_ani = _aniRunRight;
	}
	if (playerX < x){
		_isLeft = true;
		_isRight = false;
		_ani = _aniRunLeft;
	}

	if (_isRight){ _maxX = _enemyX + 400; }
	if (_isLeft){ _maxX = _enemyX - 400; }
	_ani->start();
	
	if (_isGhost){ _rcEnemy = RectMake(0, 0, 0, 0); }
	else{
		_rcEnemy = RectMake(_enemyX + 150, _enemyY + 280, 250, 200);
	}
	_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 250, 30);
	
}

void goblin::effectStart(int timer){
	_isEffect = true;
	_effectTimer = 0;
	_effectTimerLimit = timer;
}

void goblin::settingRect(){
	switch (_goblinState){
	case GOBLIN_STAND:
		if (_isRight){
			_rcEnemy = RectMake(_enemyX + 150, _enemyY + 260, 150, 220);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(_enemyX + 160, _enemyY + 300, 200, 40);
		}
		if (_isLeft){
			_rcEnemy = RectMake(_enemyX + 120, _enemyY + 280, 150, 200);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(_enemyX + 0, _enemyY + 300, 200, 60);
		}
		break;
	case GOBLIN_WALK:
		if (_isRight){
			_rcEnemy = RectMake(_enemyX + 150, _enemyY + 260, 150, 220);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(_enemyX + 160, _enemyY + 300, 200, 40);
		}
		if (_isLeft){
			_rcEnemy = RectMake(_enemyX + 100, _enemyY + 280, 150, 200);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(_enemyX + 0, _enemyY + 300, 200, 60);
		}
		break;
	case GOBLIN_APPER:
	case GOBLIN_RUN:
		if (_isRight){
			_rcEnemy = RectMake(_enemyX + 150, _enemyY + 270, 150, 210);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(_enemyX + 160, _enemyY + 300, 200, 40);
		}
		if (_isLeft){
			_rcEnemy = RectMake(_enemyX + 100, _enemyY + 270, 150, 210);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(_enemyX + 0, _enemyY + 300, 200, 60);
		}
		break;
	case GOBLIN_ATTACK:
		if (_isRight){
			_rcEnemy = RectMake(_enemyX + 150, _enemyY + 270, 150, 210);
			_rcShadow = RectMake(_enemyX + 150, _rcEnemy.bottom, 150, 40);
			_rcAttack = RectMake(_enemyX + 160, _enemyY + 300, 200, 40);
			_rcRange = RectMake(_enemyX + 160, _enemyY + 300, 200, 40);
		}
		if (_isLeft){
			_rcEnemy = RectMake(_enemyX + 110, _enemyY + 270, 150, 210);
			_rcShadow = RectMake(_enemyX + 150, _rcEnemy.bottom, 150, 40);
			_rcAttack = RectMake(_enemyX + 0, _enemyY + 300, 200, 60);
			_rcRange = RectMake(_enemyX + 0, _enemyY + 300, 200, 60);
		}
		break;
	case GOBLIN_DAMAGE:
		if (_isRight){
			_rcEnemy = RectMake(_enemyX + 150, _enemyY + 270, 150, 210);
			_rcShadow = RectMake(_enemyX + 150, _rcEnemy.bottom, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(_enemyX + 160, _enemyY + 300, 200, 40);
		}
		if (_isLeft){
			_rcEnemy = RectMake(_enemyX + 150, _enemyY + 270, 150, 210);
			_rcShadow = RectMake(_enemyX + 150, _rcEnemy.bottom, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(_enemyX + 0, _enemyY + 300, 200, 60);
		}
		break;
	case GOBLIN_DOWN:
		if (_isRight){
			_rcEnemy = RectMake(0, 0, 0, 0);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(0,0,0,0);
		}
		if (_isLeft){
			_rcEnemy = RectMake(0, 0, 0, 0);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(0,0,0,0);
		}
		break;
	case GOBLIN_DEAD:
		if (_isRight){
			_rcEnemy = RectMake(0, 0, 0, 0);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(0,0,0,0);
		}
		if (_isLeft){
			_rcEnemy = RectMake(0, 0, 0, 0);
			_rcShadow = RectMake(_enemyX + 150, _enemyY + 480, 150, 40);
			_rcAttack = RectMake(0, 0, 0, 0);
			_rcRange = RectMake(0,0,0,0);
		}
		break;
	}
}

void goblin::settingAnimation(){
	
	switch (_goblinState){
	case GOBLIN_STAND:
		if (_isRight){ 
			_ani = _aniStandRight;
		}
		if (_isLeft){ 
			_ani = _aniStandLeft;
		}
		if (!_ani->isPlay()){ _ani->start(); }
		break;
	case GOBLIN_WALK:
		if (_isRight){ 
			_ani = _aniWalkRight;
		}
		if (_isLeft){
			_ani = _aniWalkLeft;
		}
		if (!_ani->isPlay()){ _ani->start(); }
		break;
	case GOBLIN_APPER:
	case GOBLIN_RUN:
		if (_isRight){
			_ani = _aniRunRight;
		}
		if (_isLeft){ 
			_ani = _aniRunLeft;
		}
		break;
	case GOBLIN_ATTACK:
		if (_isRight){ 
			_ani = _aniAttackRight;
		}
		if (_isLeft){ 
			_ani = _aniAttackLeft;
		}
		if (!_ani->isPlay()){ 
			_ani->start(); 
		}
		if (_ani->getNowPlayIdx() == 5){
			_goblinState = GOBLIN_ATTACK_AFTER;
			_ani->setNowPlayIdx(0);
		}
		break;
	case GOBLIN_DAMAGE:
		if (_isRight){ 
			_ani = _aniDamageRight;
		}
		if (_isLeft){ 
			_ani = _aniDamageLeft;
		}
		if (_ani->getNowPlayIdx() == 2){
			_goblinState = GOBLIN_DAMAGE_AFTER;
			_ani->setNowPlayIdx(0);
		}
		break;
	case GOBLIN_DOWN:
		if (_isRight){
			_ani = _aniDownRight;
		}
		if (_isLeft){
			_ani = _aniDownLeft;
		}
		if (_ani->getNowPlayIdx() == 3){
			_isDown = true;
			_ani->setNowPlayIdx(0);
		}
		break;
	case GOBLIN_DEAD:
		break;
	}
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 1.0f);
}

void goblin::action(int playerX, int playerY, RECT rcPlayer, RECT rcShadow){
	//행동랜덤
	if (_goblinState != GOBLIN_ATTACK && _goblinState != GOBLIN_DAMAGE && _goblinState != GOBLIN_RUN&&
		_goblinState != GOBLIN_ATTACK_AFTER && _goblinState != GOBLIN_DAMAGE_AFTER && _goblinState != GOBLIN_APPER
		&&_goblinState != GOBLIN_DOWN){
		if (_actionTimer > GOBLIN_ACTION_TIMER){
			_actionRnd = RND->getInt(3);
			_actionTimer = 0;
		}
		_actionTimer++;
		switch (_actionRnd){
		case 0:
			_goblinState = GOBLIN_STAND;
			break;
		case 1:
		case 2:
			_goblinState = GOBLIN_WALK;
			break;
		}
	}
	RECT temp;

	//공격
	if (_goblinState != GOBLIN_ATTACK && _goblinState != GOBLIN_DAMAGE && _goblinState!=GOBLIN_RUN &&
		_goblinState != GOBLIN_ATTACK_AFTER && _goblinState != GOBLIN_DAMAGE_AFTER&& _goblinState != GOBLIN_APPER
		&&_goblinState != GOBLIN_DOWN){
		if ((rcShadow.top + rcShadow.bottom) / 2 > _rcShadow.top &&
			(rcShadow.top + rcShadow.bottom) / 2 < _rcShadow.bottom){
			if (IntersectRect(&temp, &rcPlayer, &_rcRange)){
				_goblinState = GOBLIN_ATTACK;
				effectStart(10);
				if (!_isAttackSound){
					SOUNDMANAGER->play("고블린공격", 0.1F);
					_isAttackSound = true;
				}
			}
		}
	}
	if (_goblinState != GOBLIN_DAMAGE &&_goblinState != GOBLIN_DOWN){
		if (_isDamage){
			_goblinState = GOBLIN_DAMAGE;
		}
	}
	switch (_goblinState){
	case GOBLIN_APPER:
		//고블린 첫 등장때
		if (_isRight){
			_enemyX += GOBLIN_RUN_SPEED;
			if (_enemyX > _maxX){
				_goblinState = GOBLIN_STAND;
			}
		}
		if (_isLeft){
			_enemyX -= GOBLIN_RUN_SPEED;
			if (_enemyX < _maxX){ _goblinState = GOBLIN_STAND; }
		}
		break;
	case GOBLIN_RUN:
		if (_isRight){
			_enemyX += GOBLIN_RUN_SPEED;
			_maxX -= 5;
			if (_enemyX > _maxX){
				_goblinState = GOBLIN_STAND;
			}
		}
		if (_isLeft){
			_enemyX -= GOBLIN_RUN_SPEED;
			_maxX += 5;
			if (_enemyX < _maxX){ _goblinState = GOBLIN_STAND; }
		}
		break;
	case GOBLIN_ATTACK_AFTER:
		_goblinState = GOBLIN_RUN;
		if (_isRight){
			_isRight = false;
			_isLeft = true;
			_maxX = _enemyX - 400;
		}
		else if (_isLeft){
			_isLeft = false;
			_isRight = true;
			_maxX = _enemyX + 400;
		}
		break;
	case GOBLIN_DAMAGE:
		if (!_isDamageSound){
			SOUNDMANAGER->play("고블린데미지", 0.1f);
			_isDamageSound = true;
		}
		break;
	case GOBLIN_DAMAGE_AFTER:
		_goblinState = GOBLIN_RUN;
		if (_isRight){
			_isRight = false;
			_isLeft = true;
			_maxX = _enemyX - 200;
		}
		else if (_isLeft){
			_isLeft = false;
			_isRight = true;
			_maxX = _enemyX + 200;
		}
		break;
	case GOBLIN_STAND:
		_isDamage = false;
		_damageTimer = 0;
		_flicker = false;
		_isDamageSound = false;
		_isAttackSound = false;
		_isDeadSound = false;
		break;
	case GOBLIN_WALK:
		if (_isRight){ _enemyX += GOBLIN_WALK_SPEED; }
		if (_isLeft){ _enemyX -= GOBLIN_WALK_SPEED; }
		if ((_rcShadow.bottom + _rcShadow.top) / 2 > (rcShadow.top + rcShadow.bottom) / 2) _enemyY -= 1;
		if ((_rcShadow.bottom + _rcShadow.top) / 2 < (rcShadow.top + rcShadow.bottom) / 2) _enemyY += 1;
		break;
	}
}


void goblin::notScreenOut(){
	if (_enemyX < 0){ _enemyX = 0; }
	if (_enemyX > WINSIZEX-300) { _enemyX = WINSIZEX-300; }
}

void goblin::damage(int damage){
	if (!_isDamage){
		motherEnemy::damage(damage);
		_goblinState = GOBLIN_DAMAGE;
		
	}
}


