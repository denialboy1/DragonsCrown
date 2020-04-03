#include "stdafx.h"
#include "ghost.h"


ghost::ghost()
{
}


ghost::~ghost()
{
}

HRESULT ghost::init(){
	motherEnemy::init();

	IMAGEMANAGER->addImage("빨강", "damageBuffer1.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaFrameImage("ghost_stand", "이미지/몬스터/고스트/ghost_stand.bmp", 3000, 1100, 6, 2, true, RGB(0,0,0));
	IMAGEMANAGER->addAlphaFrameImage("ghost_damage", "이미지/몬스터/고스트/ghost_damage.bmp", 1500, 1100, 3, 2, true, RGB(0, 0, 0));
	IMAGEMANAGER->addAlphaImage("ghost_shadow", "이미지/소서리스/shadow.bmp", 300, 250, true, RGB(255, 0, 255));
	


	int arr1[] = { 0, 1, 2 };
	_aniDamageRgiht = new animation;
	_aniDamageRgiht->init(1500, 1100, 500, 550);
	_aniDamageRgiht->setPlayFrame(arr1, sizeof(arr1) / sizeof(int), true);
	_aniDamageRgiht->setFPS(10);

	int arr2[] = { 3,4,5};
	_aniDamageLeft = new animation;
	_aniDamageLeft->init(1500, 1100, 500, 550);
	_aniDamageLeft->setPlayFrame(arr2, sizeof(arr2) / sizeof(int), true);
	_aniDamageLeft->setFPS(10);

	int arr3[] = { 0, 1, 2, 3, 4 };
	_aniStandRight = new animation;
	_aniStandRight->init(3000, 1100, 500, 550);
	_aniStandRight->setPlayFrame(arr3, sizeof(arr3) / sizeof(int), true);
	_aniStandRight->setFPS(10);

	int arr4[] = { 5,6,7,8,9};
	_aniStandLeft = new animation;
	_aniStandLeft->init(3000, 1100, 500, 550);
	_aniStandLeft->setPlayFrame(arr4, sizeof(arr4) / sizeof(int), true);
	_aniStandLeft->setFPS(10);

	_state = STAND;
	_isRight = true;
	_isLeft = false;
	_ani = _aniStandRight;
	_ani->start();
	_deadAlpha = 255;

	//DC얻어온다
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//비트맵을 출력하기 위해서 메모리 DC를 만들어 주는 것

	//CreateCompatibleBitMap
	//원본 DC와 호환되는 비트맵 생성

	//이미지 정보 생성
	_ghostMemDC = CreateCompatibleDC(hdc);
	_ghostBitmap = (HBITMAP)CreateCompatibleBitmap(hdc, 600, 600);
	_hOldBitMap = (HBITMAP)SelectObject(_ghostMemDC, _ghostBitmap);

	_ghostMemDC2 = CreateCompatibleDC(hdc);
	_ghostBitmap2 = (HBITMAP)CreateCompatibleBitmap(hdc, 600, 600);
	_hOldBitMap2 = (HBITMAP)SelectObject(_ghostMemDC2, _ghostBitmap2);

	//얻은 DC 해제
	ReleaseDC(_hWnd, hdc);

	_actionTimer = 0;
	_directionTimer = 0;
	_actionRnd = 0;
	_directionRnd = 0;

	_isGhostSound=false;
	_isDeadSound=false;
	_soundTimer = 0;
	return S_OK;
}
void ghost::update(int playerX, int playerY, RECT rcPlayer, RECT rcShadow){
	motherEnemy::update();
	_ani->frameUpdate(TIMEMANAGER->getElapsedTime()*1.0f);


	if (!_isDamage){
		_rcEnemy = RectMake(_enemyX + 150, _enemyY+100, 250, 250);
		_flicker = false;
	}
	else{
		_rcEnemy = RectMake(0, 0, 0, 0);
	}
	_rcAttack = RectMake(_enemyX + 150, _enemyY + 280, 250, 200);
	_rcShadow = RectMake(_rcAttack.left, _rcAttack.bottom, 250, 50);
	setRect(_rcShadow);

	if (_hp <= 0){
		_deadAlpha -= 2;
		if (!_isDeadSound){
			SOUNDMANAGER->play("유령비명", 0.1F);
			_isDeadSound = true;
		}
	}
	else{
		if (_state == WALK){
			_directionTimer++;
			if (_directionTimer > DIRECTION_TIMER){
				_directionRnd = RND->getInt(4);
				_directionTimer = 0;
				
			}

			switch (_directionRnd){
			case 0:
				if (!_isDamage){
					_isRight = true;
					_isLeft = false;
				}
				break;
			case 1:
				if (!_isDamage){
					_isRight = false;
					_isLeft = true;
				}
				break;
			case 2:
				_enemyY += 2;
				break;
			case 3:
				_enemyY -= 2;
				break;
			}
			if (_isRight){
				_ani = _aniStandRight;
				_enemyX += 4;
				if (!_ani->isPlay()){
					_ani->start();
				}
			}
			if (_isLeft){ 
				_ani = _aniStandLeft;
				_enemyX -= 4;
				if (!_ani->isPlay()){
					_ani->start();
				}
			}
			
		}

	}
	if (_deadAlpha < 10){
		setShow(false);
	}

	//행동랜덤
	if (!_isDamage && !_isDie){
		_isDamageSound = false;
		if (_actionTimer > GHOST_ACTION_TIMER){
			_actionRnd = RND->getInt(4);
			_actionTimer = 0;

		}
		_actionTimer++;
		switch (_actionRnd){
		case 0:
			_state = STAND;
			break;
		case 1:
		case 2:
		case 3:
			_state = WALK;
			break;
		}
	}
	notScreenOut();
	if (!_isDeadSound && !_isDamageSound && !_isGhostSound){
		SOUNDMANAGER->play("유령", 0.7F);
		_isGhostSound = true;
	}
	if (_isDamage){
		if (playerX > _enemyX){
			_isLeft = false;
			_isRight = true;
		}
		if (playerX < _enemyX){
			_isRight = false;
			_isLeft = true; 
		}
		_state = DAMAGE; 
		if (!_isDamageSound){
			SOUNDMANAGER->play("유령비명", 0.1F);
			_isDamageSound = true;
		}
	}

	if (_isGhostSound){ _soundTimer++; }
	if (_soundTimer > SOUND_TIMER){
		_soundTimer = 0;
		_isGhostSound = false;
	}

	
	//_state = DAMAGE;
}

void ghost::render(){

	switch (_state){
	case STAND:
	case WALK:
		IMAGEMANAGER->findAlphaImage("ghost_shadow")->alphaRender(getMemDC(), _rcShadow.left -50, _rcShadow.top - 100, 150);
		IMAGEMANAGER->findAlphaImage("ghost_stand")->alphaAniRender(getMemDC(), _enemyX, _enemyY, _ani, 255);
		break;
	case DAMAGE:
		IMAGEMANAGER->findAlphaImage("ghost_shadow")->alphaRender(getMemDC(), _rcShadow.left -50, _rcShadow.top - 100, 150);
		IMAGEMANAGER->findAlphaImage("ghost_damage")->alphaAniRender(_ghostMemDC, 0, 0, _ani, _deadAlpha);
		if (_flicker){
			IMAGEMANAGER->findImage("빨강")->render(getDamage1DC());
			BitBlt(_ghostMemDC, 0, 0, 600, 600, getDamage1DC(), 0, 0, SRCPAINT);
			TransparentBlt(getMemDC(), _enemyX + 0, _enemyY + 0, 600, 600, _ghostMemDC, 0, 0, 600, 600, RGB(255, 0, 0));
		}
		else{
			TransparentBlt(getMemDC(), _enemyX + 0, _enemyY + 0, 600, 600, _ghostMemDC, 0, 0, 600, 600, RGB(0, 0, 0));
		}
		PatBlt(_ghostMemDC, 0, 0, 600, 600, BLACKNESS);
		break;
	}
	

	if (_debug){
		Rectangle(getMemDC(), _rcEnemy.left, _rcEnemy.top, _rcEnemy.right, _rcEnemy.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}

void ghost::release(){}
void ghost::notScreenOut(){
	if (_enemyX < 0){ _enemyX = 0; }
	if (_enemyX > WINSIZEX - 300) { _enemyX = WINSIZEX - 300; }
	if (_enemyY > WINSIZEY - 520) { _enemyY = WINSIZEY - 520; }
	if (_enemyY < 100) { _enemyY = 100; }
}

void ghost::damage(int damage){
	if (!_isDamage){
		motherEnemy::damage(damage);
		_isDamage = true;
		_rcEnemy = { 0, 0, 0, 0 };
	}
}

void ghost::create(int x, int y, int playerX){
	_enemyX = x;
	_enemyY = y;

	_hp = 100;
	_attackDamage = 5;
	_rcEnemy = RectMake(_enemyX + 150, _enemyY + 280, 250, 200);
	_rcAttack = RectMake(_enemyX + 150, _enemyY + 280, 250, 200);
	_rcShadow = RectMake(_rcEnemy.left, _rcEnemy.bottom, 250, 30);

}