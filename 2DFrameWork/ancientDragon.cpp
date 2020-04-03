#include "stdafx.h"
#include "ancientDragon.h"


ancientDragon::ancientDragon()
{
}


ancientDragon::~ancientDragon()
{
}


HRESULT ancientDragon::init(){
	motherEnemy::init();
	_isOpening = false;
	//IMAGEMANAGER->addFrameImage("���巡�����", "�̹���/���巡��/���巡�����.bmp", 28800, 1800, 18, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("���巡�ｺ�ĵ�1", "�̹���/���巡��/���巡�ｺ�ĵ�1.bmp", 17600, 1200, 11, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("���巡��Ұ���1", "�̹���/���巡��/���巡��Ұ���1.bmp", 17600, 900, 11, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("���巡����ü�Ұ���", "�̹���/���巡��/���巡����ü�Ұ���.bmp", 28800, 2700, 18, 3, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����", "damageBuffer1.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("���巡������", "�̹���/���巡��/���巡������1.bmp", 17600, 1800, 11, 2, true, RGB(255, 0, 255));

	EFFECTMANAGER->addEffect("���ݸ��2", "�̹���/���巡��/���ݸ��2.bmp", 3936, 501, 492, 501, 2, 0.025, 2,80);
	EFFECTMANAGER->addEffect("���ݸ��3", "�̹���/���巡��/���ݸ��3.bmp", 3936, 501, 492, 501, 2, 0.025, 2, 80);
	KEYANIMANAGER->addDefaultFrameAnimation("���巡�����", "���巡�����", 10, false, false,cbAppear);
	KEYANIMANAGER->start("���巡�����");
	
	int arr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,7,6,5,4,3,2,1 };
	KEYANIMANAGER->addArrayFrameAnimation("���巡�ｺ�ĵ�1", "���巡�ｺ�ĵ�1", arr1, sizeof(arr1) / sizeof(int), 10, true);

	int arr2[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	KEYANIMANAGER->addArrayFrameAnimation("���巡��Ұ���1", "���巡��Ұ���1", arr2, sizeof(arr2)/sizeof(int), 8, false,cbNormal);
	
	int arr3[] = { 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46 };
	KEYANIMANAGER->addArrayFrameAnimation("���巡����ü����", "���巡����ü�Ұ���", arr3, sizeof(arr3) / sizeof(int), 7, false, cbNormal);

	int arr4[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10,11,12,13,14,15,16,17,18,19,20,21 };
	KEYANIMANAGER->addArrayFrameAnimation("���巡������", "���巡������", arr4, sizeof(arr4) / sizeof(int), 10, false,cbDead);

	_dragonState = NORMAL;
	_attackTimer = 0;

	_isFireRain = false;
	_isFireFloor = false;
	_isFireWorld = false;

	_y = 0;
	_damageTimer = 0;
	_flicker = false;
	_hp = 50000;
	_hpMax = 50000;
	
	return S_OK;
}
void ancientDragon::update(){
	if (KEYANIMANAGER->findAnimation("���巡�����")->getNowPlayIdx() == 10){
		if (!SOUNDMANAGER->isPlaySound("�巡�����"))
		SOUNDMANAGER->play("�巡�����", 0.2F);
	}
	if (!_isOpening) return;
	if (_hp <= 0){
		_dragonState = DEAD;
		if (!KEYANIMANAGER->findAnimation("���巡������")->isPlay()){
			KEYANIMANAGER->findAnimation("���巡������")->start();
			SOUNDMANAGER->play("�巡������", 0.3F);
		}
	}
	motherEnemy::update();
	pattern();

	if (_isDamage){
		if (_damageTimer > DAMAGE_TIMER){
			_isDamage = false;
			_damageTimer = 0;
		}
		if (_damageTimer % 2 == 0){
			_flicker ? _flicker = false : _flicker = true;
		}
		_damageTimer++;
	}
	
	
}
void ancientDragon::render(){
	if (!_isOpening){
		IMAGEMANAGER->findImage("���巡�����")->aniRender(getMemDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡�����"));
		return;
	}

	if (_isDamage){
		switch (_dragonState){
		case NORMAL:
			IMAGEMANAGER->findImage("���巡�ｺ�ĵ�1")->aniRender(getDamageDC(), 0, _y, KEYANIMANAGER->findAnimation("���巡�ｺ�ĵ�1"));
			break;
		case DEAD:
			IMAGEMANAGER->findImage("���巡������")->aniRender(getMemDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡������"));
			break;
		case FIRE_RAIN:
			IMAGEMANAGER->findImage("���巡��Ұ���1")->aniRender(getDamageDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡��Ұ���1"));
			break;
		case FIRE_FLOOR:
			IMAGEMANAGER->findImage("���巡��Ұ���1")->aniRender(getDamageDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡��Ұ���1"));
			break;
		case FIRE_WORLD:
			IMAGEMANAGER->findImage("���巡����ü�Ұ���")->aniRender(getDamageDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡����ü����"));
			break;
		}

		if (_flicker){
			IMAGEMANAGER->findImage("����")->render(getDamage1DC());
			BitBlt(getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, getDamage1DC(), 0, 0, SRCAND);
			TransparentBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, RGB(255, 0, 0));
		}
		else{
			TransparentBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, RGB(255, 255, 255));
		}
		PatBlt(getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	}
	else{
		switch (_dragonState){
		case NORMAL:
			IMAGEMANAGER->findImage("���巡�ｺ�ĵ�1")->aniRender(getMemDC(), 0, _y, KEYANIMANAGER->findAnimation("���巡�ｺ�ĵ�1"));
			break;
		case DEAD:
			IMAGEMANAGER->findImage("���巡������")->aniRender(getMemDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡������"));
			break;
		case FIRE_RAIN:
			IMAGEMANAGER->findImage("���巡��Ұ���1")->aniRender(getMemDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡��Ұ���1"));
			break;
		case FIRE_FLOOR:
			IMAGEMANAGER->findImage("���巡��Ұ���1")->aniRender(getMemDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡��Ұ���1"));
			break;
		case FIRE_WORLD:
			IMAGEMANAGER->findImage("���巡����ü�Ұ���")->aniRender(getMemDC(), 0, 0, KEYANIMANAGER->findAnimation("���巡����ü����"));
			break;
		}
	}

	//������ ������ �����Ÿ��� �ϱ�!
	//if (_isDamage){
	//	IMAGEMANAGER->findImage("����")->render(getDamage1DC());
	//	//BitBlt(getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, getDamage1DC(), 0, 0,SRCAND);
	//	//TransparentBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, RGB(255, 0, 0));
	//}
	//else{
	//	TransparentBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, RGB(255, 255, 255));
	//}
	//PatBlt(getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//IMAGEMANAGER->findImage("����")->render(getDamage1DC());
	//BitBlt(getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, getDamage1DC(), 0, 0, SRCAND);
	//BitBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, getDamageDC(), 0, 0, SRCCOPY);
	//TransparentBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, RGB(255, 0, 0));
	//PatBlt(getDamageDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);

	EFFECTMANAGER->render();


	char str1[10];
	sprintf(str1, "%d", _attackTimer);
	TextOut(getMemDC(), 0, 0, str1, strlen(str1));

	if (_debug){
		Rectangle(getMemDC(), _rcEnemy.left, _rcEnemy.top, _rcEnemy.right, _rcEnemy.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void ancientDragon::release(){

}

void ancientDragon::cbAppear(){
	if (_dragonState == DEAD) return;
	_isOpening = true;
	KEYANIMANAGER->start("���巡�ｺ�ĵ�1");
}

void ancientDragon::cbNormal(){
	if (_dragonState == DEAD) return;
	KEYANIMANAGER->stop("���巡��Ұ���1");


	KEYANIMANAGER->start("���巡�ｺ�ĵ�1");
	_dragonState = NORMAL;
}

void ancientDragon::pattern(){
	if (_dragonState == DEAD) return;
	if (_dragonState == NORMAL){
		_attackTimer++;


		if (_attackTimer == 100){
			_dragonState = FIRE_FLOOR;
			_attackTimer++;
			_isFireFloor = true;
			KEYANIMANAGER->start("���巡��Ұ���1");
			EFFECTMANAGER->playAlpha("���ݸ��2", 300, 500);
			EFFECTMANAGER->playAlpha("���ݸ��3", 300, 500);

			EFFECTMANAGER->playAlpha("���ݸ��2", 1250, 500);
			EFFECTMANAGER->playAlpha("���ݸ��3", 1250, 500);
			SOUNDMANAGER->play("�巡���Ǿ�", 0.2F);
		}

		if (_attackTimer == 600){
			_dragonState = FIRE_RAIN;
			_attackTimer++;
			KEYANIMANAGER->start("���巡��Ұ���1");
			EFFECTMANAGER->playAlpha("���ݸ��2", 300, 500);
			EFFECTMANAGER->playAlpha("���ݸ��3", 300, 500);

			EFFECTMANAGER->playAlpha("���ݸ��2", 1250, 500);
			EFFECTMANAGER->playAlpha("���ݸ��3", 1250, 500);
			SOUNDMANAGER->play("�巡�����1",0.2F);
			_isFireRain = true;
		}

		

		if (_attackTimer >= 1000){
			_y-=2;
			if (_y < -1300){
				_y = 0;
				_dragonState = FIRE_WORLD;
				_attackTimer = 0;
				_isFireWorld = true;
				KEYANIMANAGER->start("���巡����ü����");
				SOUNDMANAGER->play("�巡��극��", 0.2F);
			}
		}
	}

	_rcEnemy = RectMake(550, 300+_y, 500, 350);
	_rcShadow = RectMake(550, 700, 500, 150);
}

void ancientDragon::cbDead(){
	SOUNDMANAGER->allRemove();
	SCENEMANAGER->changeScene("������");
}