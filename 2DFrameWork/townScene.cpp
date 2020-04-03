#include "stdafx.h"
#include "townScene.h"


townScene::townScene()
{
}


townScene::~townScene()
{
}

HRESULT townScene::init(){
	//IMAGEMANAGER->addImage("����1", "�̹���/����/town1.bmp", 788, 120, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����2", "�̹���/����/town2.bmp", 905, 143, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����3", "�̹���/����/town3.bmp", 1501, 813, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����4", "�̹���/����/town4.bmp", 1443, 300, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����5", "�̹���/����/town5.bmp", 1700, 250, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����6", "�̹���/����/town6.bmp", 1500, 300, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����7", "�̹���/����/town7.bmp", 1449, 303, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����8", "�̹���/����/town8.bmp", 800, WINSIZEY+100, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����9", "�̹���/����/town9.bmp", WINSIZEX, WINSIZEY+300, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����10", "�̹���/����/town10.bmp", 159, 297, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����11", "�̹���/����/town11.bmp", 6083, 1500, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����12", "�̹���/����/stone.bmp", 300, 1200, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����13", "�̹���/����/town12.bmp", 105, 890, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("�����浹", "�̹���/����/collision.bmp", 6083, 1500, false, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("z", "�̹���/��/z.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("zClick", "�̹���/��/zŬ��.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("z����", "�̹���/��/z����.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t����", "�̹���/��/t����.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s����", "�̹���/��/s����.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("d����", "�̹���/��/d����.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("e����", "�̹���/��/e����.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("r����", "�̹���/��/r����.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("m����", "�̹���/��/m����.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("z�ߵ�", "�̹���/��/z�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t�ߵ�", "�̹���/��/t�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s�ߵ�", "�̹���/��/s�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("d�ߵ�", "�̹���/��/d�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("e�ߵ�", "�̹���/��/e�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("r�ߵ�", "�̹���/��/r�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("m�ߵ�", "�̹���/��/m�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("i", "�̹���/��/i.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("i����", "�̹���/��/i����.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("i�ߵ�", "�̹���/��/i�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("rune_room", "�̹���/��/��ĭ.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("rune_black", "�̹���/��/black.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaFrameImage("light", "�̹���/��/light.bmp", 595 * 2, 595 * 2, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("rmz_info", "�̹���/��/rmz_info.bmp", 1600, 113, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("rmz_bg", "�̹���/���巡��/���巡����.bmp", 1600, 900, false, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("����", "����/����.mp3", true, true);
	SOUNDMANAGER->addSound("�޴�����", "����/�Ҽ�����/�޴�����.wav", false, false);
	SOUNDMANAGER->addSound("�޴��ݱ�", "����/�Ҽ�����/�޴��ݱ�.wav", false, false);

	SOUNDMANAGER->addSound("�����", "����/�Ҽ�����/�����.wav", false, false);
	SOUNDMANAGER->addSound("��Ϸ�", "����/�Ҽ�����/��Ϸ�.wav", false, false);

	SOUNDMANAGER->play("����", 0.1f);
	

	_loopX = 0;

	_townX = INIDATA->loadDataInterger("PlayerData", "Position", "������ǥX");
	_townY = INIDATA->loadDataInterger("PlayerData", "Position", "������ǥY");

	//��ī��Ÿ��
	_lucainTowerX = INIDATA->loadDataInterger("PlayerData","Position","��ī��X");

	//��
	_castleX = INIDATA->loadDataInterger("PlayerData", "Position", "��X");

	//����
	_villege1X = INIDATA->loadDataInterger("PlayerData", "Position", "����1X");
	_villege1Y = INIDATA->loadDataInterger("PlayerData", "Position", "����1Y");
	_villege2X = INIDATA->loadDataInterger("PlayerData", "Position", "����2X");
	_villege2Y = INIDATA->loadDataInterger("PlayerData", "Position", "����2Y");
	_villege3X = INIDATA->loadDataInterger("PlayerData", "Position", "����3X");
	_villege3Y = INIDATA->loadDataInterger("PlayerData", "Position", "����3Y");
	_villege4X = INIDATA->loadDataInterger("PlayerData", "Position", "����4X");
	_villege4Y = INIDATA->loadDataInterger("PlayerData", "Position", "����4Y");
	_villege5X = INIDATA->loadDataInterger("PlayerData", "Position", "����5X");
	_villege5Y = INIDATA->loadDataInterger("PlayerData", "Position", "����5Y");

	_player = new player;
	_player->init();
	_player->setPlayerX(INIDATA->loadDataInterger("PlayerData", "Position", "X"));
	_player->setPlayerY(INIDATA->loadDataInterger("PlayerData", "Position", "Y"));
	_player->setShadowX(INIDATA->loadDataInterger("PlayerData", "Position", "�׸���X"));
	_player->setShadowY(INIDATA->loadDataInterger("PlayerData", "Position", "�׸���Y"));

	_window = TOWN;

	_menu = new menu;
	_menu->init();

	_screenMove = false;
	_townSpeedRate = 3;

	//���Կ� RECT
	_rcBar = RectMake(-20, 650, 60, 60);
	_rcShop = RectMake(1500, 600, 200, 70);
	_rcGuild = RectMake(0, 0, 0, 0);
	_rcDungeon = RectMake(0, 0, 0, 0);

	//���� RECT
	_rcBarSignBoard = RectMake(-20, 100, 60, 700);
	_rcShopSignBoard = RectMake(1500, 100, 200, 700);
	_rcGuildSignBoard = RectMake(0, 0, 0, 0);
	_rcDungeonSignBoard = RectMake(0, 0, 0, 0);

	_zOrder.clear();
	//��ų
	//normalBullet1
	for (int i = 0; i < 8; i++){
		_normalBullet1[i] = new normalBullet1;
		_normalBullet1[i]->init();
		_zOrder.push_back(_normalBullet1[i]);
	}
	//normalBullet2
	for (int i = 0; i < 5; i++){
		_normalBullet2[i] = new normalBullet1;
		_normalBullet2[i]->init();
		_zOrder.push_back(_normalBullet2[i]);
	}
	//normalBullet3
	_normalBullet3 = new normalBullet2;
	_normalBullet3->init();
	_zOrder.push_back(_normalBullet3);
	
	//normalBullet4
	_normalBullet4 = new normalBullet3;
	_normalBullet4->init();
	_zOrder.push_back(_normalBullet4);

	//normalBullet5
	_normalBullet5 = new normalBullet4;
	_normalBullet5->init();
	_zOrder.push_back(_normalBullet5);

	//normalBullet6
	_normalBullet6 = new normalBullet5;
	_normalBullet6->init();
	_zOrder.push_back(_normalBullet6);


	//manaball
	_manaball1 = new mamaball;
	_manaball1->init();
	_zOrder.push_back(_manaball1);

	//manaball
	_manaball2 = new mamaball;
	_manaball2->init();
	_zOrder.push_back(_manaball2);

	//zOrder
	_zOrder.push_back(_player);

	//UI
	_ui = new UI;
	_ui->addPlayerAddress(_player);
	_ui->init();
	
	_skillManager = new skillManager;
	_skillManager->addPlayerAddress(_player);
	_skillManager->init();
	
	//å ��ų
	_zOrder.push_back(_skillManager->getRockPress());
	_zOrder.push_back(_skillManager->getIcePrision());
	_zOrder.push_back(_skillManager->getThunderCloud());
	_zOrder.push_back(_skillManager->getBlizzard());
	_zOrder.push_back(_skillManager->getCreateFood());
	_zOrder.push_back(_skillManager->getProtection());
	_zOrder.push_back(_skillManager->getGravity());
	_zOrder.push_back(_skillManager->getCuss());
	_zOrder.push_back(_skillManager->getPetrification());


	//���̽�������� �浹
	_objectCollision = new objectCollision;
	_objectCollision->init(_player, _skillManager->getIcePrision());


	//��
	_lightFrameX = 0;
	_lightFrameY = 0;
	_lightX = 500;
	_lightY = 300;
	_frameTimer = 0;
	_rcZRune = RectMake(0, 0, 0, 0);
	_rcDRune = RectMake(0, 0, 0, 0);
	_rcERune = RectMake(0, 0, 0, 0);
	_rcMRune = RectMake(0, 0, 0, 0);
	_rcRRune = RectMake(0, 0, 0, 0);
	_rcSRune = RectMake(0, 0, 0, 0);
	_rcTRune = RectMake(0, 0, 0, 0);
	_runeRoomCount = 0;
	_rmz[0] = 4;
	_rmz[1] = 3;
	_rmz[2] = 7;
	_isZClick = false;
	_isClickCount = 0;
	_rmzAction = false;
	_lightAction = false;
	_blackAction = false;
	_blackActionTimer = 0;
	_showRoom[0] = false;
	_showRoom[1] = false;
	_showRoom[2] = false;
	_runeAlpha = 0;
	_rmzOffX = 0;
	return S_OK;
}
void townScene::update(){

	KEYANIMANAGER->update();
	

	//��� ����
	_loopX += 0.1;
	if (_loopX >= WINSIZEX) _loopX = 0;

	if (_player->getUpButton() || _player->getDownButton()){
		_townSpeedRate = 0;
	}

	if (_townX >= 0){
		_player->setSpeedRate(0);
		if (_player->getPlayerX() > 1200){
			_townX -= 5;
		}
		else{
			_townX = 0;
		}
	}
	else if (_townX <= -4465){
		_player->setSpeedRate(0);
		if (_player->getPlayerX() < 80){
			_townX += 5;
		}
		else{
			_townX = -4465;
		}
	}
	else{
		//���� �����̱�
		if (_player->getLeftButton() && (_player->getIsRavitation() || _player->getIsRun() || _player->getIsWalk())&&!_player->getIsTeleport()){
			if (_player->getPlayerX() >= 1130){
				if (!_edgeEnd){
					_player->setPlayerX(1150);
					_player->setShadowX(1150);
				}
				if (_player->getIsRun()){
					_townSpeedRate = 15;
				}
				else{
					_townSpeedRate = 0;
					_player->setSpeedRate(0);
				}
				
			}
			else{
				if (_player->getIsRun()){
					_townSpeedRate = 15;
					_player->setSpeedRate(14);
				}else if (_player->getIsRavitation()){
					_townSpeedRate = 20;
					_player->setSpeedRate(18);
				}
				else{
					_townSpeedRate = 7;
					_player->setSpeedRate(18);
				}
				
			}
			_townX += (7 + _townSpeedRate);

			//��ī�� Ÿ��
			if (_townX >= -2525){ _lucainTowerX -= (1 + _townSpeedRate*0.18); }

			//��
			if (_townX >= -3000){ _castleX -= (0.08); }

			//����1
			if (_townX >= -4465){ _villege1X += 1 + _townSpeedRate*0.18; }

			//����2
			if (_townX >= -4465){ _villege2X += 1.3 + _townSpeedRate*0.28; }

			//����3
			if (_townX >= -4465){ _villege3X += 1.5 + _townSpeedRate*0.28; }

			//����4
			if (_townX >= -4465){ _villege4X += 1.7 + _townSpeedRate*0.28; }

			//����5
			if (_townX >= -1600 && _townX<0){ _villege5X += (8 + _townSpeedRate*0.68); }
		}
		else if (_player->getRightButton() && (_player->getIsRavitation() || _player->getIsRun() || _player->getIsWalk()) && !_player->getIsTeleport()){
			
			if (_player->getPlayerX() <= 120){
				if (!_edgeEnd){
					_player->setPlayerX(100);
					_player->setShadowX(100);
				}
				if (_player->getIsRun()){
					_townSpeedRate = 15;
				}
				else{
					_townSpeedRate = 0;
				}
				_player->setSpeedRate(0);
			}
			else{
				if (_player->getIsRun()){
					_townSpeedRate = 15;
					_player->setSpeedRate(-14);
				}
				else if (_player->getIsRavitation()){
					_townSpeedRate = 20;
					_player->setSpeedRate(-18);
				}
				else{
					_townSpeedRate = 7;
					_player->setSpeedRate(-18);
				}
				
			}
			_townX -= (7+_townSpeedRate);

			//��ī�� Ÿ��
			if (_townX <= -1065 && _townX >= -2525){ _lucainTowerX += 1 + _townSpeedRate*0.2; }

			//��
			if (_townX <= -1405 && _townX >= -3000){ _castleX += 0.1; }

			//����1
			if (_townX <= -1405 && _townX >= -4465){ _villege1X -= (1 + _townSpeedRate*0.2); }

			//����2
			if (_townX <= -1405 && _townX >= -4465){ _villege2X -= (1.3 + _townSpeedRate*0.3); }

			//����3
			if (_townX <= -1405 && _townX >= -4465){ _villege3X -= (1.5 + _townSpeedRate*0.3); }

			//����4
			if (_townX >= -4465){ _villege4X -= (1.7 + _townSpeedRate*0.3); }

			//����5
			if (_townX >= -1600 && _townX<0){ _villege5X -= (8 + _townSpeedRate*0.7); }
		}
		else{
			_edgeEnd = true;
			_player->setSpeedRate(0);

			if (_player->getPlayerX() >= 1130){
				if (_player->getIsRavitation()){
					_townSpeedRate = -20;
					_townX += (7 + _townSpeedRate);

					//��ī�� Ÿ��
					if (_townX >= -2525){ _lucainTowerX -= (1 + _townSpeedRate*0.2); }

					//��
					if (_townX >= -3000){ _castleX -= (0.1); }

					//����1
					if (_townX >= -4465){ _villege1X += 1 + _townSpeedRate*0.2; }

					//����2
					if (_townX >= -4465){ _villege2X += 1.3 + _townSpeedRate*0.3; }

					//����3
					if (_townX >= -4465){ _villege3X += 1.5 + _townSpeedRate*0.3; }

					//����4
					if (_townX >= -4465){ _villege4X += 1.7 + _townSpeedRate*0.3; }

					//����5
					if (_townX >= -1600 && _townX<0){ _villege5X += (8 + _townSpeedRate*0.8); }

				}
			}
		
			if (_player->getPlayerX() <= 100){
				if (_player->getIsRavitation()){
					_townSpeedRate = -20;


					_townX -= (7 + _townSpeedRate);

					//��ī�� Ÿ��
					if (_townX >= -2525){ _lucainTowerX += (1 + _townSpeedRate*0.2); }

					//��
					if (_townX >= -3000){ _castleX += (0.1); }

					//����1
					if (_townX >= -4465){ _villege1X -= 1 + _townSpeedRate*0.2; }

					//����2
					if (_townX >= -4465){ _villege2X -= 1.3 + _townSpeedRate*0.3; }

					//����3
					if (_townX >= -4465){ _villege3X -= 1.5 + _townSpeedRate*0.3; }

					//����4
					if (_townX >= -4465){ _villege4X -= 1.7 + _townSpeedRate*0.3; }

					//����5
					if (_townX >= -1600 && _townX<0){ _villege5X -= (8 + _townSpeedRate*0.8); }

				}
			}

		}
	}

	if (_player->getPlayerX() > 120 && _player->getPlayerX() < 1150){
		_edgeEnd = false;
	}

	//ĳ���Ͱ� ȭ������� �������� �ϱ�
	if (_player->getPlayerX() < -100){
		_player->setPlayerX(-100);
		_player->setShadowX(-100);
	}
	if (_player->getPlayerX() > 1350){
		_player->setPlayerX(1350);
		_player->setShadowX(1350);
	}
	if (_player->getShadowY() > 900){
		_player->setShadowY(900);
	}

	

	//���� ��ü ����
	if (_townX >= 0) _townX = 0;
	if (_townX <= -4465) _townX =-4465;
	//if (_townY <= -600) _townY = -600;
	
	
	if (KEYMANAGER->isOnceKeyDown(VK_LSHIFT)){
		if (_window == TOWN){
			_window = MENU;
			SOUNDMANAGER->play("�޴�����", 0.3f);
		}
		else if (_window == MENU){
			_window = TOWN;
			_player->bagInit();
			SOUNDMANAGER->play("�޴��ݱ�", 0.3f);
		}

	}

	if (_window == MENU){
		_menu->update();
	}
	else{
		_player->update();
	}

	
	if (pixelCollision(getPixelMemDC(), 1, _player->getShadowX()+140, _player->getShadowY(), 0, 60, RGB(0, 255, 255), &_position) ||
		pixelCollision(getPixelMemDC(), 1, _player->getShadowX() + 140, _player->getShadowY(), 10, 30, RGB(255, 255, 0), &_position)){
		_player->setShadowY(_position);
		_player->setPixelCollision(true);
	}
	else{
		_player->setPixelCollision(false);
	}


	//���Կ� RECT
	_rcBar.left = _townX;
	_rcBar.right = _townX+60;

	_rcShop.left = _townX + 1500;
	_rcShop.right = _rcShop.left + 600;

	_rcGuild.left = _townX + 4200;
	_rcGuild.right = _rcGuild.left + 250;
	_rcGuild.top = 550;
	_rcGuild.bottom = 670;


	_rcDungeon.left = _townX + 5650;
	_rcDungeon.right = _rcDungeon.left + 250;
	_rcDungeon.top = 550;
	_rcDungeon.bottom = 670;

	//���ǿ� RECT
	_rcBarSignBoard.left = _townX;
	_rcBarSignBoard.right = _townX + 500;

	_rcShopSignBoard.left = _townX + 1100;
	_rcShopSignBoard.right = _rcShopSignBoard.left + 1350;

	_rcGuildSignBoard.left = _townX + 3900;
	_rcGuildSignBoard.right = _rcGuildSignBoard.left + 850;
	_rcGuildSignBoard.top = 100;
	_rcGuildSignBoard.bottom = 800;

	_rcDungeonSignBoard.left = _townX + 5450;
	_rcDungeonSignBoard.right = _rcDungeonSignBoard.left + 650;
	_rcDungeonSignBoard.top = 100;
	_rcDungeonSignBoard.bottom = 800;

	//��
	if (INIDATA->loadDataInterger("PlayerData", "Talizman", "red")==1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "orange") == 1 && 
		INIDATA->loadDataInterger("PlayerData", "Talizman", "yellow") == 1 && 
		INIDATA->loadDataInterger("PlayerData", "Talizman", "green") == 1 && 
		INIDATA->loadDataInterger("PlayerData", "Talizman", "skyblue") == 1 && 
		INIDATA->loadDataInterger("PlayerData", "Talizman", "blue") == 1 && 
		INIDATA->loadDataInterger("PlayerData", "Talizman", "pupple") == 1 && 
		INIDATA->loadDataInterger("PlayerData", "Talizman", "white") == 1 && 
		INIDATA->loadDataInterger("PlayerData", "Talizman", "black") == 1){
	_rcZRune.left = _townX + 5590;
	_rcZRune.right = _rcZRune.left + 64;
	_rcZRune.top = 520;
	_rcZRune.bottom = _rcZRune.top+64;
	}

	if (_rmzAction){ _rcZRune = RectMake(0, 0, 0, 0); }

	if (INIDATA->loadDataInterger("PlayerData", "A��", "num") != 0){
		_rcERune = RectMake(_player->getPlayerX(), _player->getPlayerY() + 250, 64, 64); 
	}
	if (INIDATA->loadDataInterger("PlayerData", "B��", "num") != 0){
		_rcTRune = RectMake(_player->getPlayerX() + 140, _player->getPlayerY() + 250, 64, 64);
	}
	if (INIDATA->loadDataInterger("PlayerData", "C��", "num") != 0){
		_rcSRune = RectMake(_player->getPlayerX() + 70, _player->getPlayerY() + 250, 64, 64); 
	}
	if (INIDATA->loadDataInterger("PlayerData", "D��", "num") != 0){
		_rcDRune = RectMake(_player->getPlayerX() - 70, _player->getPlayerY() + 250, 64, 64); 
	}
	if (INIDATA->loadDataInterger("PlayerData", "E��", "num") != 0){
		_rcMRune = RectMake(_player->getPlayerX() + 210, _player->getPlayerY() + 250, 64, 64);
	}
	if (INIDATA->loadDataInterger("PlayerData", "F��", "num") != 0){
		_rcRRune = RectMake(_player->getPlayerX() + 280, _player->getPlayerY() + 250, 64, 64);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)){
		if (PtInRect(&_rcZRune, _ptMouse)){
			if (_runeRoom[0] != 7 && _runeRoom[1] != 7 && _runeRoom[2] != 7){
				_isZClick = true;
				_runeRoom[_runeRoomCount] = 7;
				_runeRoomCount++;
			}
		}

		if (PtInRect(&_rcDRune, _ptMouse)){
			if (_runeRoom[0] != 1 && _runeRoom[1] != 1 && _runeRoom[2] != 1){
				_runeRoom[_runeRoomCount] = 1;
				_runeRoomCount++;
			}
		}

		if (PtInRect(&_rcERune, _ptMouse)){
			if (_runeRoom[0] != 2 && _runeRoom[1] != 2 && _runeRoom[2] != 2){
				_runeRoom[_runeRoomCount] = 2;
				_runeRoomCount++;
			}
		}

		if (PtInRect(&_rcMRune, _ptMouse)){
			if (_runeRoom[0] != 3 && _runeRoom[1] != 3 && _runeRoom[2] != 3){
				_runeRoom[_runeRoomCount] = 3;
				_runeRoomCount++;
			}
		}

		if (PtInRect(&_rcRRune, _ptMouse)){
			if (_runeRoom[0] != 4 && _runeRoom[1] != 4 && _runeRoom[2] != 4){
				_runeRoom[_runeRoomCount] = 4;
				_runeRoomCount++;
			}
		}

		if (PtInRect(&_rcSRune, _ptMouse)){
			if (_runeRoom[0] != 5 && _runeRoom[1] != 5 && _runeRoom[2] != 5){
				_runeRoom[_runeRoomCount] = 5;
				_runeRoomCount++;
			}
		}

		if (PtInRect(&_rcTRune, _ptMouse)){
			if (_runeRoom[0] != 6 && _runeRoom[1] != 6 && _runeRoom[2] != 6){
				_runeRoom[_runeRoomCount] = 6;
				_runeRoomCount++;
			}
		}

		
		if (_runeRoomCount == 3){
			if ((_runeRoom[0] == _rmz[0] || _runeRoom[1] == _rmz[0] || _runeRoom[2] == _rmz[0] )&&
				(_runeRoom[0] == _rmz[1] || _runeRoom[1] == _rmz[1] || _runeRoom[2] == _rmz[1]) &&
				(_runeRoom[0] == _rmz[2] || _runeRoom[1] == _rmz[2] || _runeRoom[2] == _rmz[2])){
				_rmzAction = true;
				_lightAction = true;
				_blackAction = true;
			}
			else{
				_runeRoomCount = 0;
				_runeRoom[0] = -1;
				_runeRoom[1] = -1;
				_runeRoom[2] = -1;
				_isZClick = false;
			}
		}
	}

	if (_lightAction){
		_frameTimer += 0.5f;
		if (_frameTimer >= 2){
			_frameTimer = 0;
			_lightFrameX++;
			if (_lightFrameX == 4){
				_lightFrameX = 0;
				_lightFrameY++;
				if (_lightFrameY == 4){
					_lightFrameY = 0;
					_lightX += 150;
					if (_lightX == 650){
						SOUNDMANAGER->play("�����", 0.3f);
						_showRoom[0] = true;
					} 
					if (_lightX == 800){
						SOUNDMANAGER->play("�����", 0.3f);
						_showRoom[1] = true;
					}
					if (_lightX == 950){
						SOUNDMANAGER->play("�����", 0.3f);
						_showRoom[2] = true;
					}
					if (_lightX >= 950){
						SOUNDMANAGER->play("��Ϸ�", 0.3f);
						_lightAction = false;
						_lightX = 500;
					}
				}
			}
		}
	}

	if (_rmzAction){
		if (!_lightAction){
			_blackActionTimer += 0.01f;
			_runeAlpha+=2;
			if (_runeAlpha > 250){ _runeAlpha = 250; }
			if (_blackActionTimer > 2){
				_blackAction = false;
				_blackActionTimer = 0;
				_isZClick = false;
				_runeRoomCount = 0;
				_runeRoom[0] = -1;
				_runeRoom[1] = -1;
				_runeRoom[2] = -1;
			}
		}
		_rcZRune = RectMake(0, 0, 0, 0);
		_rmzOffX++;
	}
	////////
	RECT _rcTemp;
	if (IntersectRect(&_rcTemp, &_player->getShadowRect(), &_rcShop)) { 
		dataSave(_player->getPlayerX(),_player->getPlayerY()+100,_townX,_townY);
		SOUNDMANAGER->allRemove();
		SCENEMANAGER->changeScene("������"); 
	}
	if (IntersectRect(&_rcTemp, &_player->getShadowRect(), &_rcBar)) {
		dataSave(_player->getPlayerX() + 100, _player->getPlayerY() + 50, _townX, _townY);
		SOUNDMANAGER->allRemove();
		SCENEMANAGER->changeScene("������");
	}
	if (IntersectRect(&_rcTemp, &_player->getShadowRect(), &_rcGuild)) {
		dataSave(_player->getPlayerX(), _player->getPlayerY() + 100, _townX, _townY);
		SOUNDMANAGER->allRemove();
		SCENEMANAGER->changeScene("����"); 
	}

	if (_rmzAction){
		if (IntersectRect(&_rcTemp, &_player->getShadowRect(), &_rcDungeon)) {
			dataSave(_player->getPlayerX(), _player->getPlayerY() + 100, _townX, _townY);
			SOUNDMANAGER->allRemove();
			SCENEMANAGER->changeScene("��Ʈ�����ε���");
		}
	}
	else{
		if (IntersectRect(&_rcTemp, &_player->getShadowRect(), &_rcDungeon)) {
			dataSave(_player->getPlayerX(), _player->getPlayerY() + 100, _townX, _townY);
			SOUNDMANAGER->allRemove();
			SCENEMANAGER->changeScene("�����ε���");
		}
	}

	_objectCollision->collision();
	skill();

	//zOrder���� ���ϱ�
	for (int i = 0; i < _zOrder.size() - 1; i++){
		for (int j = i + 1; j < _zOrder.size(); j++){
			gameNode* _temp;
			if (_zOrder[i]->getRect().bottom>_zOrder[j]->getRect().bottom){
				_temp = _zOrder[i];
				_zOrder[i] = _zOrder[j];
				_zOrder[j] = _temp;
			}
		}
	}

}
void townScene::render(){
	IMAGEMANAGER->findImage("����9")->loopRender(getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY + 300), _loopX, 0);
	IMAGEMANAGER->findImage("����3")->render(getMemDC(), 0 + _castleX, -120);
	IMAGEMANAGER->findImage("����4")->render(getMemDC(), 800 + _villege1X, 400);
	IMAGEMANAGER->findImage("����7")->render(getMemDC(), 800 + _villege2X, 500);
	IMAGEMANAGER->findImage("����6")->render(getMemDC(), 600 + _villege3X, 550);
	IMAGEMANAGER->findImage("����5")->render(getMemDC(), 1000 + _villege4X, 570);
	IMAGEMANAGER->findImage("����8")->render(getMemDC(), 2200 + _townX + _lucainTowerX, _townY + 300);
	if (_rmzAction){
		if (!_blackAction){
			RECT rc = RectMake(0, 0, 1800, 900);
			IMAGEMANAGER->findAlphaImage("rmz_bg")->alphaLoopRender(getMemDC(), &rc, _rmzOffX, 0, 255);
		}
	}
	IMAGEMANAGER->findImage("����11")->render(getMemDC(), _townX, _townY);


	RECT temp;
	if (IntersectRect(&temp, &_rcBarSignBoard, &_player->getRcPlayer())){
		IMAGEMANAGER->findImage("��������1")->render(getMemDC(), _rcBarSignBoard.left + 100, 100);
		IMAGEMANAGER->findImage("������ũ")->render(getMemDC(), _rcBarSignBoard.left + 190, 200);
	}

	if (IntersectRect(&temp, &_rcGuildSignBoard, &_player->getRcPlayer())){
		IMAGEMANAGER->findImage("��尣��1")->render(getMemDC(), _rcGuildSignBoard.left + 230, 100);
		IMAGEMANAGER->findImage("��帶ũ")->render(getMemDC(), _rcGuildSignBoard.left + 320, 160);
	}

	if (IntersectRect(&temp, &_rcShopSignBoard, &_player->getRcPlayer())){
		IMAGEMANAGER->findImage("������ũ")->render(getMemDC(), _rcShopSignBoard.left + 530, 200);
		IMAGEMANAGER->findImage("��������")->render(getMemDC(), _rcShopSignBoard.left + 500, 100);
	}

	if (!_rmzAction){
		if (IntersectRect(&temp, &_rcDungeonSignBoard, &_player->getRcPlayer())){
			IMAGEMANAGER->findImage("������ũ")->render(getMemDC(), _rcDungeonSignBoard.left + 180, 200);
			IMAGEMANAGER->findImage("��������")->render(getMemDC(), _rcDungeonSignBoard.left + 100, 100);
		}
	}
	//��
	if (INIDATA->loadDataInterger("PlayerData", "Talizman", "red") == 1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "orange") == 1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "yellow") == 1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "green") == 1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "skyblue") == 1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "blue") == 1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "pupple") == 1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "white") == 1 &&
		INIDATA->loadDataInterger("PlayerData", "Talizman", "black") == 1){
		if (!_rmzAction){
			if (!_isZClick){
				IMAGEMANAGER->findImage("z")->render(getMemDC(), _rcZRune.left, _rcZRune.top);
			}
			else{
				IMAGEMANAGER->findImage("zClick")->render(getMemDC(), _rcZRune.left, _rcZRune.top);
			}
		}
	}

	//zorder���ֱ�
	//_player->render();
	for (int i = 0; i < _zOrder.size(); i++){
		_zOrder[i]->render();
	}

	///
	IMAGEMANAGER->findImage("����12")->render(getMemDC(), 900 + _villege5X, -250);
	IMAGEMANAGER->findImage("����13")->render(getMemDC(), _townX, 10);

	if (_window == MENU){
		_menu->render();
	}
	
	IMAGEMANAGER->findImage("�����浹")->render(getPixelMemDC(), _townX, _townY);
	if (_debug){
		IMAGEMANAGER->findImage("�����浹")->render(getMemDC(), _townX, _townY);
		Rectangle(getMemDC(), _rcBar.left, _rcBar.top, _rcBar.right, _rcBar.bottom);
		Rectangle(getMemDC(), _rcShop.left, _rcShop.top, _rcShop.right, _rcShop.bottom);
		Rectangle(getMemDC(), _rcGuild.left, _rcGuild.top, _rcGuild.right, _rcGuild.bottom);
		Rectangle(getMemDC(), _rcDungeon.left, _rcDungeon.top, _rcDungeon.right, _rcDungeon.bottom);
		Rectangle(getMemDC(), _player->getShadowX() + 140, _player->getShadowY(), _player->getShadowX() + 150, _player->getShadowY() + 10);

		Rectangle(getMemDC(), _rcBarSignBoard.left, _rcBarSignBoard.top, _rcBarSignBoard.right, _rcBarSignBoard.bottom);
		Rectangle(getMemDC(), _rcShopSignBoard.left, _rcShopSignBoard.top, _rcShopSignBoard.right, _rcShopSignBoard.bottom);
		Rectangle(getMemDC(), _rcGuildSignBoard.left, _rcGuildSignBoard.top, _rcGuildSignBoard.right, _rcGuildSignBoard.bottom);
		Rectangle(getMemDC(), _rcDungeonSignBoard.left, _rcDungeonSignBoard.top, _rcDungeonSignBoard.right, _rcDungeonSignBoard.bottom);
	}

	if (_skillManager->getRockPress()->getStart()){
		if (_skillManager->getRockPress()->getFrameX() == 3){
			if (_skillManager->getRockPress()->getAlpha() == 255){
				BitBlt(getMemDC2(), 0, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
				BitBlt(getMemDC(), 10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			}
			if (_skillManager->getRockPress()->getAlpha() == 254)	BitBlt(getMemDC(), -10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			if (_skillManager->getRockPress()->getAlpha() == 253)	BitBlt(getMemDC(), 10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			if (_skillManager->getRockPress()->getAlpha() == 252)	BitBlt(getMemDC(), -10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			if (_skillManager->getRockPress()->getAlpha() == 251)	BitBlt(getMemDC(), 10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			if (_skillManager->getRockPress()->getAlpha() == 250)	BitBlt(getMemDC(), -10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			if (_skillManager->getRockPress()->getAlpha() == 249)	BitBlt(getMemDC(), 10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			if (_skillManager->getRockPress()->getAlpha() == 248)	BitBlt(getMemDC(), -10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			if (_skillManager->getRockPress()->getAlpha() == 247)	BitBlt(getMemDC(), 10, 0, WINSIZEX, WINSIZEY, getMemDC(), 0, 0, SRCCOPY);
			//if (_skillManager->getRockPress()->getAlpha() == 246)	BitBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, getMemDC2(), 0, 0, SRCCOPY);
		}
	}
	
	

	_ui->render();

	//��UI
	if (_isZClick){
		IMAGEMANAGER->findAlphaImage("rune_room")->alphaRender(getMemDC(), _player->getPlayerX()-10, _player->getPlayerY()+120, 200);
		IMAGEMANAGER->findAlphaImage("rune_room")->alphaRender(getMemDC(), _player->getPlayerX()+90, _player->getPlayerY()+120, 200);
		IMAGEMANAGER->findAlphaImage("rune_room")->alphaRender(getMemDC(), _player->getPlayerX()+190, _player->getPlayerY()+120, 200);

		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), _rcDRune.left, _rcDRune.top, 3, 5);
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), _rcERune.left, _rcERune.top, 0, 5);
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), _rcSRune.left, _rcSRune.top, 2, 5);
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), _rcTRune.left, _rcTRune.top, 1, 5);
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), _rcMRune.left, _rcMRune.top, 4, 5);
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), _rcRRune.left, _rcRRune.top, 5, 5);

		for (int i = 0; i < 3; i++){
			switch (_runeRoom[i]){
			case 1:
				IMAGEMANAGER->findImage("d����")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 2:
				IMAGEMANAGER->findImage("e����")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 3:
				IMAGEMANAGER->findImage("m����")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 4:
				IMAGEMANAGER->findImage("r����")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 5:
				IMAGEMANAGER->findImage("s����")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 6:
				IMAGEMANAGER->findImage("t����")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 7:
				IMAGEMANAGER->findImage("z����")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			}
		}
	}

	if (_blackAction){
		IMAGEMANAGER->findAlphaImage("rune_black")->alphaRender(getMemDC(), 0, 0, 220);
		if (_lightAction)
			IMAGEMANAGER->findAlphaImage("light")->alphaFrameRender(getMemDC(), _lightX, _lightY, _lightFrameX, _lightFrameY, 180);
		if (_showRoom[0]){
			IMAGEMANAGER->findImage("r�ߵ�")->render(getMemDC(), 600, 450);
		}
		if (_showRoom[1]){
			IMAGEMANAGER->findImage("m�ߵ�")->render(getMemDC(), 750, 450);
		}
		if (_showRoom[2]){
			IMAGEMANAGER->findImage("z�ߵ�")->render(getMemDC(), 900, 450);
		}

		if (_showRoom[2]){
			IMAGEMANAGER->findAlphaImage("rmz_info")->alphaRender(getMemDC(), 0, 600, _runeAlpha);
		}
	}

}
void townScene::release(){
	
}
void townScene::dataSave(int x, int y, int absX, int absY){
	char str1[50];
	sprintf(str1, "%d", (int)x);
	INIDATA->addData("Position", "X", str1);
	sprintf(str1, "%d", (int)y);
	INIDATA->addData("Position", "Y", str1);
	sprintf(str1, "%d", (int)x + 15);
	INIDATA->addData("Position", "�׸���X", str1);
	sprintf(str1, "%d", (int)y + 440);
	INIDATA->addData("Position", "�׸���Y", str1);
	sprintf(str1, "%d", (int)absX);
	INIDATA->addData("Position", "������ǥX", str1);
	sprintf(str1, "%d", (int)absY);
	INIDATA->addData("Position", "������ǥY", str1);
	sprintf(str1, "%d", (int)_castleX);
	INIDATA->addData("Position", "��X", str1);
	sprintf(str1, "%d", (int)_castleY);
	INIDATA->addData("Position", "��Y", str1);
	sprintf(str1, "%d", (int)_villege1X);
	INIDATA->addData("Position", "����1X", str1);
	sprintf(str1, "%d", (int)_villege1Y);
	INIDATA->addData("Position", "����1Y", str1);
	sprintf(str1, "%d", (int)_villege2X);
	INIDATA->addData("Position", "����2X", str1);
	sprintf(str1, "%d", (int)_villege2Y);
	INIDATA->addData("Position", "����2Y", str1);
	sprintf(str1, "%d", (int)_villege3X);
	INIDATA->addData("Position", "����3X", str1);
	sprintf(str1, "%d", (int)_villege3Y);
	INIDATA->addData("Position", "����3Y", str1);
	sprintf(str1, "%d", (int)_villege4X);
	INIDATA->addData("Position", "����4X", str1);
	sprintf(str1, "%d", (int)_villege4Y);
	INIDATA->addData("Position", "����4Y", str1);
	sprintf(str1, "%d", (int)_villege5X);
	INIDATA->addData("Position", "����5X", str1);
	sprintf(str1, "%d", (int)_villege5Y);
	INIDATA->addData("Position", "����5Y", str1);
	sprintf(str1, "%d", (int)_lucainTowerX);
	INIDATA->addData("Position", "��ī��X", str1);

	string str = INIDATA->loadDataString("PlayerData", "State", "LEVEL").c_str();
	INIDATA->addData("State", "LEVEL", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "EXP").c_str();
	INIDATA->addData("State", "EXP", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "HP").c_str();
	INIDATA->addData("State", "HP", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "MP").c_str();
	INIDATA->addData("State", "MP", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "STR").c_str();
	INIDATA->addData("State", "STR", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "INT").c_str();
	INIDATA->addData("State", "INT", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "CON").c_str();
	INIDATA->addData("State", "CON", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "MGR").c_str();
	INIDATA->addData("State", "MGR", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "DEX").c_str();
	INIDATA->addData("State", "DEX", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "LUC").c_str();
	INIDATA->addData("State", "LUC", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "Money").c_str();
	INIDATA->addData("State", "Money", str.c_str());

	//����	-- �������� ����� �������� ���
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag1").c_str();
	INIDATA->addData("Bag", "bag1", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag2").c_str();
	INIDATA->addData("Bag", "bag2", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag3").c_str();
	INIDATA->addData("Bag", "bag3", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag4").c_str();
	INIDATA->addData("Bag", "bag4", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag5").c_str();
	INIDATA->addData("Bag", "bag5", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag6").c_str();
	INIDATA->addData("Bag", "bag6", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag7").c_str();
	INIDATA->addData("Bag", "bag7", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag8").c_str();
	INIDATA->addData("Bag", "bag8", str.c_str());

	//��ų
	str = INIDATA->loadDataString("PlayerData", "Skill", "SKILLPOINT").c_str();
	INIDATA->addData("Skill", "SKILLPOINT", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "mental_absorb").c_str();
	INIDATA->addData("Skill", "mental_absorb", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "extract").c_str();
	INIDATA->addData("Skill", "extract", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "concentrate").c_str();
	INIDATA->addData("Skill", "concentrate", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "magic_point_up").c_str();
	INIDATA->addData("Skill", "magic_point_up", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "ice_prision").c_str();
	INIDATA->addData("Skill", "ice_prision", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "protection").c_str();
	INIDATA->addData("Skill", "protection", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "gravity").c_str();
	INIDATA->addData("Skill", "gravity", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "thunder_cloud").c_str();
	INIDATA->addData("Skill", "thunder_cloud", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "rock_press").c_str();
	INIDATA->addData("Skill", "rock_press", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "blizzard").c_str();
	INIDATA->addData("Skill", "blizzard", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "animate_skelton").c_str();
	INIDATA->addData("Skill", "animate_skelton", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "ravitation").c_str();
	INIDATA->addData("Skill", "ravitation", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "create_food").c_str();
	INIDATA->addData("Skill", "create_food", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "curse").c_str();
	INIDATA->addData("Skill", "curse", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "petrification").c_str();
	INIDATA->addData("Skill", "petrification", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "sliding").c_str();
	INIDATA->addData("Skill", "sliding", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "gold_healing").c_str();
	INIDATA->addData("Skill", "gold_healing", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "gold_scoring").c_str();
	INIDATA->addData("Skill", "gold_scoring", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "hit_point_up").c_str();
	INIDATA->addData("Skill", "hit_point_up", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "food_psytology").c_str();
	INIDATA->addData("Skill", "food_psytology", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "maintenance").c_str();
	INIDATA->addData("Skill", "maintenance", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "item_user").c_str();
	INIDATA->addData("Skill", "item_user", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "evade").c_str();
	INIDATA->addData("Skill", "evade", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Skill", "extra_pocket").c_str();
	INIDATA->addData("Skill", "extra_pocket", str.c_str());


	str = INIDATA->loadDataString("PlayerData", "��ī������ ������", "num");
	INIDATA->addData("��ī������ ������", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "��ī������ ������", "currentCon");
	INIDATA->addData("��ī������ ������", "currentCon", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "������Ʈ ������", "num");
	INIDATA->addData("������Ʈ ������", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�̱״� ������", "num");
	INIDATA->addData("�̱״� ������", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "ũ��� ������", "num");
	INIDATA->addData("ũ��� ������", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "ũ��� ������", "seal");
	INIDATA->addData("ũ��� ������", "seal", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���� ����", "num");
	INIDATA->addData("���� ����", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "������ ����", "num");
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�븶���� ����", "num");
	INIDATA->addData("�븶���� ����", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�븶���� ����", "seal");
	INIDATA->addData("�븶���� ����", "seal", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���� �尩", "num");
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���� �尩", "num");
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���� �Ź�", "num");
	INIDATA->addData("���� �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "������ �Ź�", "num");
	INIDATA->addData("������ �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���޶��� �ͰŸ�", "num");
	INIDATA->addData("���޶��� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�������� �ͰŸ�", "num");
	INIDATA->addData("�������� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "A��", "num");
	INIDATA->addData("A��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "B��", "num");
	INIDATA->addData("B��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "C��", "num");
	INIDATA->addData("C��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "D��", "num");
	INIDATA->addData("D��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "E��", "num");
	INIDATA->addData("E��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "F��", "num");
	INIDATA->addData("F��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "������ ����", "num");
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���̽� �������� ��", "num");
	INIDATA->addData("���̽� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�����ؼ��� ��", "num");
	INIDATA->addData("�����ؼ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�׷���Ƽ�� ��", "num");
	INIDATA->addData("�׷���Ƽ�� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "��� Ŭ������ ��", "num");
	INIDATA->addData("��� Ŭ������ ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�� �������� ��", "num");
	INIDATA->addData("�� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���ڵ��� ��", "num");
	INIDATA->addData("���ڵ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "ũ������Ʈ Ǫ���� ��", "num");
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Ŀ���� ��", "num");
	INIDATA->addData("Ŀ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "��Ʈ�������̼��� ��", "num");
	INIDATA->addData("��Ʈ�������̼��� ��", "num", str.c_str());

	//Ż���
	str = INIDATA->loadDataString("PlayerData", "Talizman", "red").c_str();
	INIDATA->addData("Talizman", "red", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "orange").c_str();
	INIDATA->addData("Talizman", "orange", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "yellow").c_str();
	INIDATA->addData("Talizman", "yellow", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "green").c_str();
	INIDATA->addData("Talizman", "green", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "skyblue").c_str();
	INIDATA->addData("Talizman", "skyblue", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "blue").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "pupple").c_str();
	INIDATA->addData("Talizman", "pupple", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "white").c_str();
	INIDATA->addData("Talizman", "white", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "black").c_str();
	INIDATA->addData("Talizman", "black", str.c_str());

	INIDATA->iniSave("PlayerData");
}

void townScene::skill(){
	//��ų 
	for (int i = 0; i < 8; i++){
		_normalBullet1[i]->update();
	}

	if (_player->getIsRight()){
		if (_player->getIsFireball1()){
			_player->setIsFireball1(false);
			_normalBullet1[0]->start(_player->getPlayerX() + 100, _player->getPlayerY());
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet1[0]->getFrameX() == 2){
			_normalBullet1[1]->start(_normalBullet1[0]->getX() - 70, _normalBullet1[0]->getY()-20);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}
		
		if (_normalBullet1[1]->getFrameX() == 2){
			_normalBullet1[2]->start(_normalBullet1[1]->getX() - 70, _normalBullet1[1]->getY()-20);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}
		
		if (_normalBullet1[2]->getFrameX() == 2){
			_normalBullet1[3]->start(_normalBullet1[2]->getX() - 70, _normalBullet1[2]->getY() -100 );
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}
		
		if (_normalBullet1[3]->getFrameX() == 2){
			_normalBullet1[4]->start(_normalBullet1[3]->getX() - 70, _normalBullet1[3]->getY()-100);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}
		
		if (_normalBullet1[4]->getFrameX() == 2){
			_normalBullet1[5]->start(_normalBullet1[4]->getX() + 70, _normalBullet1[4]->getY() -100);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
			//_normalBullet1[5]->setRect(RectMake(_normalBullet1[5]->getRc().left + 300,
			//	_normalBullet1[5]->getRc().top,
			//	_normalBullet1[5]->getRc().right,
			//	_normalBullet1[5]->getRc().bottom));
		}
		
		if (_normalBullet1[5]->getFrameX() == 2){
			_normalBullet1[6]->start(_normalBullet1[5]->getX() + 70, _normalBullet1[5]->getY() -100);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
			//_normalBullet1[6]->setRect(RectMake(_normalBullet1[6]->getRc().left + 300,
			//	_normalBullet1[6]->getRc().top,
			//	_normalBullet1[6]->getRc().right,
			//	_normalBullet1[6]->getRc().bottom));
		}
		
		if (_normalBullet1[6]->getFrameX() == 2){
			_normalBullet1[7]->start(_normalBullet1[6]->getX() + 70, _normalBullet1[6]->getY()-20);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball1()){
			_player->setIsFireball1(false);
			_normalBullet1[0]->start(_player->getPlayerX() - 160, _player->getPlayerY()-20);
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet1[0]->getFrameX() == 2){
			_normalBullet1[1]->start(_normalBullet1[0]->getX() + 70, _normalBullet1[0]->getY() -20);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet1[1]->getFrameX() == 2){
			_normalBullet1[2]->start(_normalBullet1[1]->getX() + 70, _normalBullet1[1]->getY() -20);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet1[2]->getFrameX() == 2){
			_normalBullet1[3]->start(_normalBullet1[2]->getX() + 70, _normalBullet1[2]->getY() -100);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet1[3]->getFrameX() == 2){
			_normalBullet1[4]->start(_normalBullet1[3]->getX() + 70, _normalBullet1[3]->getY()-100);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet1[4]->getFrameX() == 2){
			_normalBullet1[5]->start(_normalBullet1[4]->getX() -70, _normalBullet1[4]->getY() -100);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet1[5]->getFrameX() == 2){
			_normalBullet1[6]->start(_normalBullet1[5]->getX() - 70, _normalBullet1[5]->getY() - 100);
			//_normalBullet1[6]->setRect(RectMake(_normalBullet1[6]->getRc().left + 300,
			//	_normalBullet1[6]->getRc().top,
			//	_normalBullet1[6]->getRc().right,
			//	_normalBullet1[6]->getRc().bottom));
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet1[6]->getFrameX() == 2){
			_normalBullet1[7]->start(_normalBullet1[6]->getX() - 70, _normalBullet1[6]->getY() - 20);
			//_normalBullet1[7]->setRect(RectMake(_normalBullet1[7]->getRc().left + 300,
			//	_normalBullet1[7]->getRc().top,
			//	_normalBullet1[7]->getRc().right,
			//	_normalBullet1[7]->getRc().bottom));
		}
	}

	for (int i = 0; i < 5; i++){
		_normalBullet2[i]->update();
	}

	if (_player->getIsRight()){
		if (_player->getIsFireball2()){
			_player->setIsFireball2(false);
			_normalBullet2[0]->start(_player->getPlayerX() + 100, _player->getPlayerY());
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet2[0]->getFrameX() == 2){
			_normalBullet2[1]->start(_normalBullet2[0]->getX() + 200, _normalBullet2[0]->getY()-60);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet2[1]->getFrameX() == 2){
			_normalBullet2[2]->start(_normalBullet2[1]->getX() + 200, _normalBullet2[1]->getY()-60);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet2[2]->getFrameX() == 2){
			_normalBullet2[3]->start(_normalBullet2[2]->getX() + 200, _normalBullet2[2]->getY()-60);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet2[3]->getFrameX() == 2){
			_normalBullet2[4]->start(_normalBullet2[3]->getX() + 200, _normalBullet2[3]->getY()-60);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball2()){
			_player->setIsFireball2(false);
			_normalBullet2[0]->start(_player->getPlayerX() - 200, _player->getPlayerY());
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet2[0]->getFrameX() == 2){
			_normalBullet2[1]->start(_normalBullet2[0]->getX() - 200, _normalBullet2[0]->getY()-60);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet2[1]->getFrameX() == 2){
			_normalBullet2[2]->start(_normalBullet2[1]->getX() - 200, _normalBullet2[1]->getY()-60);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet2[2]->getFrameX() == 2){
			_normalBullet2[3]->start(_normalBullet2[2]->getX() - 200, _normalBullet2[2]->getY()-60);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}

		if (_normalBullet2[3]->getFrameX() == 2){
			_normalBullet2[4]->start(_normalBullet2[3]->getX() -200, _normalBullet2[3]->getY()-60);
			SOUNDMANAGER->stop("����");
			SOUNDMANAGER->play("����", 0.15F);
		}
	}


	//normalBullet3;
	_normalBullet3->update();

	if (_player->getIsRight()){
		if (_player->getIsFireball3()){
			_player->setIsFireball3(false);
			_normalBullet3->start(_player->getPlayerX() + 100, _player->getPlayerY()-10);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball3()){
			_player->setIsFireball3(false);
			_normalBullet3->start(_player->getPlayerX() - 300, _player->getPlayerY()-10);

		}
	}

	//normalBullet4;
	_normalBullet4->update();
	if (_player->getIsRight()){
		if (_player->getIsFireball4()){
			_player->setIsFireball4(false);
			_normalBullet4->fire(_player->getPlayerX() + 300, _player->getPlayerY() + 200, _player->getShadowX(), _player->getShadowY(), 0, 600, 0, 0);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball4()){
			_player->setIsFireball4(false);
			_normalBullet4->fire(_player->getPlayerX() - 100, _player->getPlayerY() + 200, _player->getShadowX(), _player->getShadowY(), PI, 600, 0, 1);
		}
	}

	//normalBullet5;
	_normalBullet5->update();
	if (_player->getIsRight()){
		if (_player->getIsFireball5()){
			_player->setIsFireball5(false);
			_normalBullet5->fire(_player->getPlayerX() + 450, _player->getPlayerY() + 300, _player->getShadowX(), _player->getShadowY(), PI + PI * 3 / 4, 600, 0, 0);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball5()){
			_player->setIsFireball5(false);
			_normalBullet5->fire(_player->getPlayerX() - 100, _player->getPlayerY() + 350,_player->getShadowX(),_player->getShadowY(), PI + PI / 4, 600, 0, 1);
		}
	}

	//normalBullet6;
	_normalBullet6->update();
	if (_player->getIsRight()){
		if (_player->getIsFireball6()){
			_player->setIsFireball6(false);
			_normalBullet6->fire(_player->getPlayerX() + 450, _player->getPlayerY() + 300, _player->getShadowX(), _player->getShadowY(), PI + PI * 3 / 4, 600, 0, 0);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball6()){
			_player->setIsFireball6(false);
			_normalBullet6->fire(_player->getPlayerX() - 100, _player->getPlayerY() + 350, _player->getShadowX(), _player->getShadowY(), PI + PI / 4, 600, 0, 1);
		}
	}



	//manaball1
	_manaball1->update();

	if (_player->getIsRight()){
		if (_player->getIsManaball1()){
			_player->setIsManaball1(false);
			_manaball1->start(_player->getPlayerX() + 250, _player->getPlayerY() - 10,  _player->getShadowX(), _player->getShadowY());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsManaball1()){
			_player->setIsManaball1(false);
			_manaball1->start(_player->getPlayerX() - 200, _player->getPlayerY() - 10,  _player->getShadowX(), _player->getShadowY());
		}
	}

	//manaball2
	_manaball2->update();

	if (_player->getIsRight()){
		if (_player->getIsManaball2()){
			_player->setIsManaball2(false);
			_manaball2->start(_player->getPlayerX() + 320, _player->getPlayerY() + 150,_player->getShadowX(),_player->getShadowY());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsManaball2()){
			_player->setIsManaball2(false);
			_manaball2->start(_player->getPlayerX() - 200, _player->getPlayerY() + 150, _player->getShadowX(), _player->getShadowY());
		}
	}

	//rockPress
	_skillManager->getRockPress()->update();

	if (_player->getIsRight()){
		if (_player->getIsRockPress()){
			_player->setIsRockPress(false);
			_skillManager->getRockPress()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 300, _player->getShadowX()+320, _player->getShadowY());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsRockPress()){
			_player->setIsRockPress(false);
			_skillManager->getRockPress()->start(_player->getPlayerX() - 400, _player->getPlayerY() - 300, _player->getShadowX(), _player->getShadowY());
		}
	}

	//icePrision
	_skillManager->getIcePrision()->update();
	if (_player->getIsRight()){
		if (_player->getIsIcePrision()){
			_player->setIsIcePrision(false);
			_skillManager->getIcePrision()->start(_player->getPlayerX() + 320, _player->getPlayerY() -100
				, _player->getShadowX() + 320, _player->getShadowY());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsIcePrision()){
			_player->setIsIcePrision(false);
			_skillManager->getIcePrision()->start(_player->getPlayerX() - 400, _player->getPlayerY() , _player->getShadowX(), _player->getShadowY());
		}
	}

	if ((_player->getRcPlayer().right+_player->getRcPlayer().left)/2 < _skillManager->getIcePrision()->getRcDeffence()[2].left){
		_skillManager->getIcePrision()->setRect(RectMake(_skillManager->getIcePrision()->getRect().left, _skillManager->getIcePrision()->getRect().top,	300, -500));
	}

	//thunderCloud
	_skillManager->getThunderCloud()->update();

	if (_player->getIsRight()){
		if (_player->getIsThunderCloud()){
			_player->setIsThunderCloud(false);
			_skillManager->getThunderCloud()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 100
				, _player->getShadowX() + 320, _player->getShadowY());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsThunderCloud()){
			_player->setIsThunderCloud(false);
			_skillManager->getThunderCloud()->start(_player->getPlayerX() - 400, _player->getPlayerY(), 
				_player->getShadowX()-300, _player->getShadowY());
		}
	}

	//blizzard
	_skillManager->getBlizzard()->update();

	if (_player->getIsRight()){
		if (_player->getIsBlizzard()){
			_player->setIsBlizzard(false);
			_skillManager->getBlizzard()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 100
				, _player->getShadowX() + 320, _player->getShadowY());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsBlizzard()){
			_player->setIsBlizzard(false);
			_skillManager->getBlizzard()->start(_player->getPlayerX() - 400, _player->getPlayerY(),
				_player->getShadowX() - 300, _player->getShadowY());
		}
	}

	//createFood
	_skillManager->getCreateFood()->update();

	if (_player->getIsRight()){
		if (_player->getIsCreateFood()){
			_player->setIsCreateFood(false);
			_skillManager->getCreateFood()->start(_player->getPlayerX() + 320, _player->getPlayerY() +380
				, _player->getShadowX() + 320, _player->getShadowY()-35,0);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsCreateFood()){
			_player->setIsCreateFood(false);
			_skillManager->getCreateFood()->start(_player->getPlayerX() - 170, _player->getPlayerY()+380,
				_player->getShadowX() - 170, _player->getShadowY()-35,0);
		}
	}

	RECT temp;
	if ((_player->getRcShadow().bottom+_player->getRcShadow().top)/2 > _skillManager->getCreateFood()->getRcShadow().top && 
		(_player->getRcShadow().bottom + _player->getRcShadow().top) / 2< _skillManager->getCreateFood()->getRcShadow().bottom){
		if (IntersectRect(&temp, &_player->getRcPlayer(), &_skillManager->getCreateFood()->getRcOjbect())){
			_player->setIsFoddEat(true);
			_skillManager->getCreateFood()->setStart(false);
		}
	}

	//protection
	_skillManager->getProtection()->update(_player->getPlayerX(),_player->getPlayerY());

	if (_player->getIsRight()){
		if (_player->getIsProtection()){
			_player->setIsProtection(false);
			_skillManager->getProtection()->start(_player->getPlayerX() + 320, _player->getPlayerY() + 380
				, _player->getShadowX() + 320, _player->getShadowY() - 35);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsProtection()){
			_player->setIsProtection(false);
			_skillManager->getProtection()->start(_player->getPlayerX() - 170, _player->getPlayerY() + 380,
				_player->getShadowX() - 170, _player->getShadowY() - 35);
		}
	}

	//gravity
	_skillManager->getGravity()->update();

	if (_player->getIsRight()){
		if (_player->getIsGravity()){
			_player->setIsGravity(false);
			_skillManager->getGravity()->start(_player->getPlayerX() + 180, _player->getPlayerY()
				, _player->getShadowX() + 260, _player->getShadowY()+10);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsGravity()){
			_player->setIsGravity(false);
			_skillManager->getGravity()->start(_player->getPlayerX() - 350, _player->getPlayerY(),
				_player->getShadowX()-280 , _player->getShadowY()+10);
		}
	}

	if (_player->getShadowRect().bottom > _skillManager->getGravity()->getRcShadow().bottom){
		_skillManager->getGravity()->setRect(RectMake(_skillManager->getGravity()->getRcShadow().left + 1500,
			_skillManager->getGravity()->getRcShadow().top, 
			_skillManager->getGravity()->getRcShadow().right - _skillManager->getGravity()->getRcShadow().left,
			_skillManager->getGravity()->getRcShadow().bottom - _skillManager->getGravity()->getRcShadow().top));
	}
	else{
		_skillManager->getGravity()->setRect(RectMake(_skillManager->getGravity()->getRcShadow().left - 1500, 
			_skillManager->getGravity()->getRcShadow().top,
			_skillManager->getGravity()->getRcShadow().right - _skillManager->getGravity()->getRcShadow().left, 
			_skillManager->getGravity()->getRcShadow().bottom - _skillManager->getGravity()->getRcShadow().top));
	}

	//cuss
	_skillManager->getCuss()->update();

	if (_player->getIsRight()){
		if (_player->getIsCuss()){
			_player->setIsCuss(false);
			_skillManager->getCuss()->start(_player->getPlayerX() + 250, _player->getPlayerY()+30
				, _player->getShadowX() + 290, _player->getShadowY() - 45,0);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsCuss()){
			_player->setIsCuss(false);
			_skillManager->getCuss()->start(_player->getPlayerX() - 170, _player->getPlayerY()+30,
				_player->getShadowX() - 140, _player->getShadowY() - 45,1);
		}
	}

	//petrification
	_skillManager->getPetrification()->update();

	if (_player->getIsRight()){
		if (_player->getIsPtetrification()){
			_player->setIsPtetrification(false);
			_skillManager->getPetrification()->start(_player->getPlayerX() +120, _player->getPlayerY()-230
				, _player->getShadowX() + 290, _player->getShadowY() - 45);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsPtetrification()){
			_player->setIsPtetrification(false);
			_skillManager->getPetrification()->start(_player->getPlayerX() - 120, _player->getPlayerY() -230,
				_player->getShadowX() - 140, _player->getShadowY() - 45);
		}
	}
}