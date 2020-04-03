#include "stdafx.h"
#include "killerRabbit.h"


killerRabbit::killerRabbit()
{
}


killerRabbit::~killerRabbit()
{
}


HRESULT killerRabbit::init(){
	motherEnemy::init();
	IMAGEMANAGER->addFrameImage("rabbit_stand", "이미지/몬스터/킬러레빗/killerRabbit_stand.bmp", 1200, 574, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("rabbit_walk", "이미지/몬스터/킬러레빗/killerRabbit_walk.bmp", 900, 574, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("rabbit_deathAttack", "이미지/몬스터/킬러레빗/killerRabbit_attack1.bmp", 4800, 574, 16, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("rabbit_attack2", "이미지/몬스터/킬러레빗/killerRabbit_attack2.bmp", 2100, 574, 7, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("rabbit_dead", "이미지/몬스터/킬러레빗/killerRabbit_dead.bmp", 900, 574, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("빨강", "damageBuffer1.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("rabbit_shadow", "이미지/소서리스/shadow.bmp", 150, 250, true, RGB(255, 0, 255));
	


	int arr1[] = { 4, 5, 6, 7 };
	_aniStandLeft = new animation;
	_aniStandLeft->init(1200, 574, 300, 287);
	_aniStandLeft->setPlayFrame(arr1,sizeof(arr1)/sizeof(int),true);
	_aniStandLeft->setFPS(8);

	int arr2[] = { 0,1,2,3};
	_aniStandRight = new animation;
	_aniStandRight->init(1200, 574, 300, 287);
	_aniStandRight->setPlayFrame(arr2, sizeof(arr2) / sizeof(int), true);
	_aniStandRight->setFPS(8);

	int arr3[] = { 0,1,2 };
	_aniWalkRight = new animation;
	_aniWalkRight->init(900, 574, 300, 287);
	_aniWalkRight->setPlayFrame(arr3, sizeof(arr3) / sizeof(int), true);
	_aniWalkRight->setFPS(10);

	int arr4[] = {3,4,5 };
	_aniWalkLeft = new animation;
	_aniWalkLeft->init(900, 574, 300, 287);
	_aniWalkLeft->setPlayFrame(arr4, sizeof(arr4) / sizeof(int), true);
	_aniWalkLeft->setFPS(10);

	int arr5[] = { 0,1,2,3,4,5,6 };
	_aniAttackRight = new animation;
	_aniAttackRight->init(2100, 574, 300, 287);
	_aniAttackRight->setPlayFrame(arr5, sizeof(arr5) / sizeof(int), false);
	_aniAttackRight->setFPS(10);

	int arr6[] = { 7,8,9,10,11,12,13 };
	_aniAttackLeft = new animation;
	_aniAttackLeft->init(2100, 574, 300, 287);
	_aniAttackLeft->setPlayFrame(arr6, sizeof(arr6) / sizeof(int), false);
	_aniAttackLeft->setFPS(10);

	int arr7[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
	_aniDeathAttackRight = new animation;
	_aniDeathAttackRight->init(4800, 574, 300, 287);
	_aniDeathAttackRight->setPlayFrame(arr7, sizeof(arr7) / sizeof(int), false);
	_aniDeathAttackRight->setFPS(10);

	int arr8[] = { 16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
	_aniDeathAttackLeft = new animation;
	_aniDeathAttackLeft->init(4800, 574, 300, 287);
	_aniDeathAttackLeft->setPlayFrame(arr8, sizeof(arr8) / sizeof(int), false);
	_aniDeathAttackLeft->setFPS(10);

	int arr9[] = { 0,1,2};
	_aniDeadRight = new animation;
	_aniDeadRight->init(900, 574, 300, 287);
	_aniDeadRight->setPlayFrame(arr9, sizeof(arr9) / sizeof(int), false);
	_aniDeadRight->setFPS(10);

	int arr10[] = { 3,4,5 };
	_aniDeadLeft = new animation;
	_aniDeadLeft->init(900, 574, 300, 287);
	_aniDeadLeft->setPlayFrame(arr10, sizeof(arr10) / sizeof(int), false);
	_aniDeadLeft->setFPS(10);

	_ani = _aniStandRight;
	_isRight = true;
	_isLeft = false;
	//DC얻어온다
	HDC hdc = GetDC(_hWnd);

	//이미지 정보 생성
	_rabbitMemDC = CreateCompatibleDC(hdc);
	_rabbitBitmap = (HBITMAP)CreateCompatibleBitmap(hdc, 300, 300);
	_hOldBitMap = (HBITMAP)SelectObject(_rabbitMemDC, _rabbitBitmap);

	_rabbitMemDC2 = CreateCompatibleDC(hdc);
	_rabbitBitmap2 = (HBITMAP)CreateCompatibleBitmap(hdc, 300, 300);
	_hOldBitMap2 = (HBITMAP)SelectObject(_rabbitMemDC2, _rabbitBitmap2);

	//얻은 DC 해제
	ReleaseDC(_hWnd, hdc);

	_skillTimer = 0;
	_isDeathAttack = false;
	_state = APPEAR;
	_jump = new jump;
	_jump->init();

	_isDeathSound = false;
	return S_OK;
}
void killerRabbit::update(RECT rcPlayer, RECT rcShadow){
	motherEnemy::update();
	action(rcPlayer,rcShadow);

	//방향정하기
	if (_state != NORMAL_ATTACK && _state != DEATH_ATTACK && _state != DEAD){
		if ((rcShadow.left+rcShadow.right)/2 > (_rcShadow.left+_rcShadow.right)/2){
			_isRight = true;
			_isLeft = false;
		}
		if ((rcShadow.left + rcShadow.right) / 2 < (_rcShadow.left + _rcShadow.right) / 2){
			_isLeft = true;
			_isRight = false;
		}
	}
	_jump->update();
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime()*1.0f);

	if (_state != DEATH_ATTACK){
		_attackDamage = 20;
	}
	else{
		_attackDamage = 9999;
	}
}
void killerRabbit::render(){
	IMAGEMANAGER->findAlphaImage("rabbit_shadow")->alphaRender(getMemDC(), _rcShadow.left + 15, _rcShadow.top - 100, 150);
	switch (_state){
	case APPEAR:
		IMAGEMANAGER->findImage("rabbit_walk")->frameRender(getMemDC(), _enemyX+110, _enemyY-130, 2, 1);
		break;
	case STAND:
		if (_isRight){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_stand")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_stand")->aniRender(getMemDC(), _enemyX + 100, _enemyY - 130, _ani);
			}
		}
		if (_isLeft){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_stand")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_stand")->aniRender(getMemDC(), _enemyX + 75, _enemyY - 130, _ani);
			}
		}
		break;
	case WALK:
		if (_isRight){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_walk")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_walk")->aniRender(getMemDC(), _enemyX + 100, _enemyY - 130, _ani);
			}
		}
		if (_isLeft){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_walk")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_walk")->aniRender(getMemDC(), _enemyX + 75, _enemyY - 130, _ani);
			}
		}
		break;
	case NORMAL_ATTACK:
		if (_isRight){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_attack2")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_attack2")->aniRender(getMemDC(), _enemyX + 100, _enemyY - 130, _ani);
			}
		}
		if (_isLeft){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_attack2")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_attack2")->aniRender(getMemDC(), _enemyX + 75, _enemyY - 130, _ani);
			}
		}
		break;
	case DEATH_ATTACK:
		if (_isRight){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_deathAttack")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_deathAttack")->aniRender(getMemDC(), _enemyX + 100, _enemyY - 130, _ani);
			}
		}
		if (_isLeft){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_deathAttack")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_deathAttack")->aniRender(getMemDC(), _enemyX + 75, _enemyY - 130, _ani);
			}
		}
		break;
	case DEAD:
	case DEAD_AFTER:
		if (_isRight){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_dead")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 100, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_dead")->aniRender(getMemDC(), _enemyX + 130, _enemyY - 130, _ani);
			}
		}
		if (_isLeft){
			if (_isDamage){
				IMAGEMANAGER->findImage("rabbit_dead")->aniRender(_rabbitMemDC, 0, 0, _ani);
				if (_flicker){
					IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
					BitBlt(_rabbitMemDC, 0, 0, 300, 300, getDamage1DC(), 0, 0, SRCPAINT);
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(255, 0, 0));
				}
				else{
					TransparentBlt(getMemDC(), _enemyX + 75, _enemyY - 130, 300, 300, _rabbitMemDC, 0, 0, 300, 300, RGB(0, 0, 0));
				}
				PatBlt(_rabbitMemDC, 0, 0, 300, 300, BLACKNESS);
			}
			else{
				IMAGEMANAGER->findImage("rabbit_dead")->aniRender(getMemDC(), _enemyX + 75, _enemyY - 130, _ani);
			}
		}
		break;
	}

	EFFECTMANAGER->render();

	if (_debug){
		Rectangle(getMemDC(), _rcEnemy.left, _rcEnemy.top, _rcEnemy.right, _rcEnemy.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
		Rectangle(getMemDC(), _rcRange.left, _rcRange.top, _rcRange.right, _rcRange.bottom);
		Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
	}
}
void killerRabbit::release(){}

void killerRabbit::action(RECT rcPlayer, RECT rcShadow){
	//스킬 쓰기
	_skillTimer++;
	if (_skillTimer > RABBIT_SKILL_TIMER){
		if (_state == WALK || _state == STAND){
			_skillTimer = 0;
			_state = DEATH_ATTACK;
			_jumpY = _enemyY;
			if (_isRight) {
				_ani = _aniDeathAttackRight;
				if (!_ani->isPlay()){ _ani->start(); }
			}
			if (_isLeft) {
				_ani = _aniDeathAttackLeft;
				if (!_ani->isPlay()){ _ani->start(); }
			}
		}
	}

	if (_state == STAND){
		if (_skillTimer % 30 == 0){ _state = WALK; }
	}

	if (_state == WALK){
		if (_skillTimer % 120 == 0){ _state = STAND; }
	}


	//공격범위에 들어오면 일반 공격!
	if (_state == WALK || _state == STAND){
		RECT temp;
		if ((rcShadow.top + rcShadow.bottom) / 2 > _rcShadow.top &&
			(rcShadow.top + rcShadow.bottom) / 2 < _rcShadow.bottom){
			if (IntersectRect(&temp, &rcPlayer, &_rcRange)){
				_state = NORMAL_ATTACK;
			}
		}
	}

	if (_isDie && _state != DEAD_AFTER){
		_state = DEAD;
	}

	

	switch (_state){
	case APPEAR:
		if (!_jump->getIsJumping()){ _state = STAND; 
		if (_isRight) {
			_ani = _aniStandRight;
			if (!_ani->isPlay()){ _ani->start(); }
		}
		if (_isLeft) {
			_ani = _aniStandLeft;
			if (!_ani->isPlay()){ _ani->start(); }
		}
		}
		break;
	case STAND:
		if (_isRight) {
			_ani = _aniStandRight;
			if (!_ani->isPlay()){ _ani->start(); }
		}
		if (_isLeft) {
			_ani = _aniStandLeft;
			if (!_ani->isPlay()){ _ani->start(); }
		}
		break;
	case WALK:
		if (_isRight) {
			_ani = _aniWalkRight;
			if (!_ani->isPlay()){ _ani->start(); }
			_rcRange = RectMake(_enemyX + 300, _enemyY - 100, 30, 100);
			_enemyX += 4;
		}
		if (_isLeft) {
			_ani = _aniWalkLeft;
			if (!_ani->isPlay()){ _ani->start(); }
			_rcRange = RectMake(_enemyX+120 , _enemyY - 100, 30, 100);
			_enemyX -= 4;
		}
		if ((_rcShadow.bottom + _rcShadow.top) / 2 > (rcShadow.top + rcShadow.bottom) / 2) _enemyY -= 1;
		if ((_rcShadow.bottom + _rcShadow.top) / 2 < (rcShadow.top + rcShadow.bottom) / 2) _enemyY += 1;
		_rcEnemy = RectMake(_enemyX + 150, _enemyY-100, 150, 100);
		_rcShadow = RectMake(_enemyX + 150, _enemyY , 150, 50);
		
		break;
	case NORMAL_ATTACK:
		if (_isRight) {
			_ani = _aniAttackRight;
			if (!_ani->isPlay()){ _ani->start();
			}
		}
		if (_isLeft) {
			_ani = _aniAttackLeft;
			if (!_ani->isPlay()){ _ani->start(); 
			}
		}
		if (!SOUNDMANAGER->isPlaySound("토끼공격"))
		SOUNDMANAGER->play("토끼공격", 0.1F);
		
		//렉트 설정
		if (_ani->getNowPlayIdx() == 3){
			if (_isRight)_rcAttack = RectMake(_enemyX + 300, _enemyY - 100, 30, 100);
			if (_isLeft)_rcAttack = RectMake(_enemyX + 120, _enemyY - 100, 30, 100);
		}
		if (_ani->getNowPlayIdx() == 6){
			_rcAttack = RectMake(0, 0, 0, 0);
			_state = STAND;
			_ani->setNowPlayIdx(0);
			SOUNDMANAGER->stop("토끼공격");
		}

		break;
	case DEATH_ATTACK:
		_rcEnemy = RectMake(0, 0, 0, 0);
		if (_ani->getNowPlayIdx() > 8){
			if (!_isDeathSound){
				SOUNDMANAGER->play("토끼공격", 0.1F);
				_isDeathSound = true;
			}
			_jump->jumping(&_enemyX, &_enemyY, 18, 1);
			if (_isRight) {
				_enemyX += 10;
			}
			if (_isLeft) {
				_enemyX -= 10;
			}
			if (!_jump->getIsJumping()){
				_state = STAND;
				_rcEnemy = RectMake(_enemyX + 150, _enemyY - 100, 150, 100);
				_ani->setNowPlayIdx(0);
			}
			_rcShadow = RectMake(_enemyX + 150, _jumpY, 150, 50);
			_rcDeathAttack = RectMake(_enemyX + 100, _enemyY, 250, 50);
			_rcAttack = RectMake(_enemyX + 100, _enemyY, 250, 50);
			if ((rcShadow.top + rcShadow.bottom) / 2 > _rcShadow.top &&
				(rcShadow.top + rcShadow.bottom) / 2 < _rcShadow.bottom){
				RECT temp;
				if (IntersectRect(&temp, &rcPlayer, &_rcDeathAttack)){
					_isDeathAttack=true;
				}
			}
		}

		if (_ani->getNowPlayIdx() == 15){
			_state = STAND;
			_rcEnemy = RectMake(_enemyX + 150, _enemyY - 100, 150, 100);
			_rcDeathAttack = RectMake(0,0,0,0);
			_rcAttack = RectMake(0,0,0,0);
			_ani->setNowPlayIdx(0);
			_isDeathSound = false;
		}

		
		break;
	case DEAD:
		if (_isRight) {
			_ani = _aniDeadRight;
			if (!_ani->isPlay()){ _ani->start(); }
		}
		if (_isLeft) {
			_ani = _aniDeadLeft;
			if (!_ani->isPlay()){ _ani->start(); }
		}
		if (_ani->getNowPlayIdx() == 2){
			_state = DEAD_AFTER;
			_ani->resume();
		}
		if (!SOUNDMANAGER->isPlaySound("토끼죽음")){
			SOUNDMANAGER->play("토끼죽음",0.1F);
		}
		break;
	}
}

void killerRabbit::create(int x, int y){
	_enemyX = x;
	_enemyY = y;

	_hp = 500;
	_hpMax = 500;
	_rcEnemy = RectMake(_enemyX + 150, _enemyY - 100, 150, 100);
	_rcShadow = RectMake(_enemyX+150, _enemyY+800, 150, 50);

	_jump->jumping(&_enemyX, &_enemyY, 10, 2);
	_jump->setStartY(_rcShadow.top);

	EFFECTMANAGER->addEffect("rabbit_left", "이미지/몬스터/킬러레빗/killerRabbit_effect_left.bmp", 2856, 500, 357, 500, 1, 0.1, 1);
	EFFECTMANAGER->addEffect("rabbit_right", "이미지/몬스터/킬러레빗/killerRabbit_effect_right.bmp", 2856, 500, 357, 500, 1, 0.1, 1);
}

