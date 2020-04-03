#include "stdafx.h"
#include "graveScene.h"


graveScene::graveScene()
{
}


graveScene::~graveScene()
{
}


HRESULT graveScene::init(){
	//////////////////////////////////////////스테이지///////////////////////////
	IMAGEMANAGER->addImage("지하스테이지1", "이미지/무덤/지하스테이지1.bmp", 5415, 900,true,RGB(255,0,255));
	IMAGEMANAGER->addImage("지하스테이지1픽셀", "이미지/무덤/지하스테이지1픽셀.bmp", 5415, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하배경1", "이미지/무덤/지하배경.bmp", 1764,569, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("grave_black", "이미지/룬/black.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지2", "이미지/무덤/지하스테이지2.bmp", 1600, 940, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지2_2", "이미지/무덤/지하스테이지2_2.bmp", 1600, 940, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지2픽셀", "이미지/무덤/지하스테이지2픽셀.bmp", 1600, 940, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하배경2", "이미지/무덤/지하배경.bmp", 1764, 569, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지3", "이미지/무덤/지하스테이지3.bmp", 6000, 1000, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지3픽셀", "이미지/무덤/지하스테이지3픽셀.bmp", 6000, 1000, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지3_2", "이미지/무덤/지하스테이지3_2.bmp", 6000, 1000, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하배경3", "이미지/무덤/지하배경3.bmp", 1009*2, 821*2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지4", "이미지/무덤/지하스테이지4.bmp", 1600, 940, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지4픽셀", "이미지/무덤/지하스테이지4픽셀.bmp", 1600, 940, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("지하스테이지4_2", "이미지/무덤/지하스테이지4_2.bmp", 1600, 940, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("흑백", "이미지/소서리스/흑백.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("stateTop", "이미지/menu/스테이터스/스테이터스_top.bmp", 1600, 146, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("stateBottom", "이미지/menu/스테이터스/스테이터스_bottom.bmp", 1600, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("양피지1", "이미지/menu/스테이터스/스테이터스_양피지1.bmp", 840, 570, true, RGB(255, 0, 255));
	IMAGEMANAGER->addPngImage("bg_sorceress", L"이미지/menu/bg_sorceressout.png", 900, 900);
	IMAGEMANAGER->addAlphaImage("red_talizma", "이미지/무덤/레드탈리즈만획득.bmp", 1600, 900,false,RGB(255,0,255));
	IMAGEMANAGER->addAlphaImage("orange_talizma", "이미지/무덤/오렌지탈리즈만획득.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("yellow_talizma", "이미지/무덤/옐로우탈리즈만획득.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("green_talizma", "이미지/무덤/그린탈리즈만획득.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("bluesky_talizma", "이미지/무덤/스카이블루탈리즈만획득.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("blue_talizma", "이미지/무덤/블루탈리즈만획득.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("pupple_talizma", "이미지/무덤/퍼플탈리즈만획득.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("white_talizma", "이미지/무덤/화이트탈리즈만획득.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("black_talizma", "이미지/무덤/블랙탈리즈만획득.bmp", 1600, 900, false, RGB(255, 0, 255));
	//룬
	IMAGEMANAGER->addImage("z", "이미지/룬/z.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("zClick", "이미지/룬/z클릭.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("z선택", "이미지/룬/z선택.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t선택", "이미지/룬/t선택.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s선택", "이미지/룬/s선택.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("d선택", "이미지/룬/d선택.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("e선택", "이미지/룬/e선택.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("r선택", "이미지/룬/r선택.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("m선택", "이미지/룬/m선택.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("z발동", "이미지/룬/z발동.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("t발동", "이미지/룬/t발동.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("s발동", "이미지/룬/s발동.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("d발동", "이미지/룬/d발동.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("e발동", "이미지/룬/e발동.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("r발동", "이미지/룬/r발동.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("m발동", "이미지/룬/m발동.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("i", "이미지/룬/i.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("i선택", "이미지/룬/i선택.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("i발동", "이미지/룬/i발동.bmp", 64, 64, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("rune_room", "이미지/룬/룬칸.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("rune_black", "이미지/룬/black.bmp", 1600, 900, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaFrameImage("light", "이미지/룬/light.bmp", 595 * 2, 595 * 2, 4, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("die_info", "이미지/룬/die_info.bmp", 1600, 113, true, RGB(255, 0, 255));
	_expBar = new progressBar;
	_expBar->init("이미지/menu/스테이터스/expBarFull", "이미지/menu/스테이터스/expBar", WINSIZEX / 2, 700, 1600, 200);
	_expBar->setGauge(50, 100);

	SOUNDMANAGER->addSound("룬생성", "사운드/소서리스/룬생성.wav", false, false);
	SOUNDMANAGER->addSound("룬완료", "사운드/소서리스/룬완료.wav", false, false);

	IMAGEMANAGER->addImage("killerRabbitName", "이미지/몬스터/킬러레빗/killerrabbitName.bmp", 468, 63, true, RGB(255, 0, 255));
	
	SOUNDMANAGER->play("무덤스테이지", 0.3f);
	_stage = STAGE1;
	_stageOffX = 0;
	_bgOffX = 0;
	_isScreenFix = true;
	_stage1_1Clear = false;
	_stage1_2Clear = false;
	_stage1_3Clear = false;
	_stage1_4Clear = false;
	_stage2Clear = false;
	_stage3_1Clear = false;
	_stage3_2Clear = false;
	_stage3_3Clear = false;
	_stage3_4Clear = false;
	_stage4Clear = false;

	_stage1_1Start = false;
	_stage1_2Start = false;
	_stage1_3Start = false;
	_stage1_4Start = false;
	_stage2Start = false;
	_stage3_1Start = false;
	_stage3_2Start = false;
	_stage3_3Start = false;
	_stage3_4Start = false;
	_stage4Start = false;
	_isStageChange = false;
	///////////////////////////////////////플레이어//////////////////////////////
	_player = new player;
	_player->init();
	_player->setPlayerX(0);
	_player->setPlayerY(400);
	_player->setShadowX(0);
	_player->setShadowY(400);
	_player->setShow(true);
	_zOrder.clear();

	//룬
	_lightFrameX = 0;
	_lightFrameY = 0;
	_lightX = 500;
	_lightY = 300;
	_frameTimer = 0;
	_rcZRune = RectMake(-100, -100, -100, -100);
	_rcDRune = RectMake(-100, -100, -100, -100);
	_rcERune = RectMake(-100, -100, -100, -100);
	_rcMRune = RectMake(-100, -100, -100, -100);
	_rcRRune = RectMake(-100, -100, -100, -100);
	_rcSRune = RectMake(-100, -100, -100, -100);
	_rcTRune = RectMake(-100, -100, -100, -100);
	_rcIRune = RectMake(-100, -100, -100, -100);
	_runeRoomCount = 0;
	_die[0] = 1;
	_die[1] = 8;
	_die[2] = 2;
	_isZClick = false;
	_isIClick = false;
	_isClickCount = 0;
	_rmzAction = false;
	_dieAction = false;
	_lightAction = false;
	_blackAction = false;
	_blackActionTimer = 0;
	_showRoom[0] = false;
	_showRoom[1] = false;
	_showRoom[2] = false;
	_runeAlpha = 0;
	_dieOffX = 0;
	_isDie = false;
	//스킬
	//normalBullet1
	for (int i = 0; i < 8; i++){
		_normalBullet1[i] = new normalBullet1;
		_normalBullet1[i]->init();
		//_zOrder.push_back(_normalBullet1[i]);
	}
	//normalBullet2
	for (int i = 0; i < 5; i++){
		_normalBullet2[i] = new normalBullet1;
		_normalBullet2[i]->init();
		//_zOrder.push_back(_normalBullet2[i]);
	}
	//normalBullet3
	_normalBullet3 = new normalBullet2;
	_normalBullet3->init();
	//_zOrder.push_back(_normalBullet3);

	//normalBullet4
	_normalBullet4 = new normalBullet3;
	_normalBullet4->init();
	//_zOrder.push_back(_normalBullet4);

	//normalBullet5
	_normalBullet5 = new normalBullet4;
	_normalBullet5->init();
	//_zOrder.push_back(_normalBullet5);

	//normalBullet6
	_normalBullet6 = new normalBullet5;
	_normalBullet6->init();
	//_zOrder.push_back(_normalBullet6);


	//manaball
	_manaball1 = new mamaball;
	_manaball1->init();
	//_zOrder.push_back(_manaball1);

	//manaball
	_manaball2 = new mamaball;
	_manaball2->init();
	//_zOrder.push_back(_manaball2);

	//zOrder
	_zOrder.push_back(_player);

	//UI
	_ui = new UI;
	_ui->addPlayerAddress(_player);
	_ui->init();

	_skillManager = new skillManager;
	_skillManager->addPlayerAddress(_player);
	_skillManager->init();

	//책 스킬
	//_zOrder.push_back(_skillManager->getRockPress());
	//_zOrder.push_back(_skillManager->getIcePrision());
	//_zOrder.push_back(_skillManager->getThunderCloud());
	//_zOrder.push_back(_skillManager->getBlizzard());
	//_zOrder.push_back(_skillManager->getCreateFood());
	//_zOrder.push_back(_skillManager->getProtection());
	//_zOrder.push_back(_skillManager->getGravity());
	//_zOrder.push_back(_skillManager->getCuss());
	//_zOrder.push_back(_skillManager->getPetrification());


	//아이스프리즌과 충돌
	_objectCollision = new objectCollision;
	_objectCollision->init(_player, _skillManager->getIcePrision());
	////////////////////////////////////////////////////////////////////////////////


	////////////고블린////////////////
	//_goblin1 = new goblin;
	//_goblin1->init();
	//_goblin1->create(-200, 100,(_player->getRcPlayer().left+_player->getRcPlayer().right)/2);
	//_vGoblin.push_back(_goblin1);
	//_zOrder.push_back(_vGoblin[_vGoblin.size()-1]);
	//_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);

	///////////////////////////////

	//////////배틀//////////////
	_battle = new battle;
	_battle->init();
	_battle->linkPlayerAddress(_player);
	_battle->linkManaballAddress(_manaball1);
	_battle->linkNormalBullet1Address(_normalBullet1[0]);
	_battle->linkNormalBullet2Address(_normalBullet3);
	_battle->linkNormalBullet3Address(_normalBullet4);
	_battle->linkNormalBullet4Address(_normalBullet5);
	_battle->linkNormalBullet5Address(_normalBullet6);
	_battle->linkSkillManagerAddress(_skillManager);
	


	//_mother
	_mother = new motherEnemy;
	_mother->init();

	_killerRabbit = new killerRabbit;
	_killerRabbit->init();

	_exp = 0;
	_isGain = false;
	_talizman[0] = INIDATA->loadDataInterger("PlayerData", "Talizman", "red");
	_talizman[1] = INIDATA->loadDataInterger("PlayerData", "Talizman", "orange");
	_talizman[2] = INIDATA->loadDataInterger("PlayerData", "Talizman", "yellow");
	_talizman[3] = INIDATA->loadDataInterger("PlayerData", "Talizman", "green");
	_talizman[4] = INIDATA->loadDataInterger("PlayerData", "Talizman", "skyblue");
	_talizman[5] = INIDATA->loadDataInterger("PlayerData", "Talizman", "blue");
	_talizman[6] = INIDATA->loadDataInterger("PlayerData", "Talizman", "pupple");
	_talizman[7] = INIDATA->loadDataInterger("PlayerData", "Talizman", "white");
	_talizman[8] = INIDATA->loadDataInterger("PlayerData", "Talizman", "black");

	_hpBar = new progressBar;
	_hpBar->init("이미지/고대드래곤/dragonHPTop", "이미지/고대드래곤/dragonHPBottom", 800, 800, 1340, 58);

	_vMother.clear();
	return S_OK;
}

void graveScene::update(){
	
	////////////////////////스테이지//////////////////////
	if (_isStageChange){
		
		if (_isAlphaUp){
			_stageChangeAlpha+=2;
		}
		else{
			_stageChangeAlpha-=2;
		}
		if (_stageChangeAlpha >= 253){
			_isAlphaUp = false;
			_stageChangeAlpha = 250;
			if (_stage == STAGE1){
				_stage = STAGE2;
				_player->setPlayerX(-350);
				_player->setShadowX(-350);
				_player->setPlayerY(211);
				_player->setShadowY(651);
			}
			else if (_stage == STAGE2){
				_stage = STAGE3;
				_player->setPlayerX(-350);
				_player->setShadowX(-350);
				_player->setPlayerY(245);
				_player->setShadowY(685);
			}
			else if (_stage == STAGE3){
				_stage = STAGE4;
				_player->setPlayerX(-350);
				_player->setShadowX(-350);
				_player->setPlayerY(190);
				_player->setShadowY(630);
			}
			_stageOffX = 0;
			_bgOffX = 0;
			
		}
		
		if (_player->getIsRun()){
			if (_stageChangeAlpha < 100){
				_player->setPlayerX(_player->getPlayerX() + 10);
				_player->setShadowX(_player->getShadowX() + 10);
			}
		}

		if (_player->getIsWalk()){
			if (_stageChangeAlpha < 150){
				_player->setPlayerX(_player->getPlayerX() + 7);
				_player->setShadowX(_player->getShadowX() + 7);
			}
		}


		if (_stageChangeAlpha < 10){
			_isStageChange = false;
		}
	}
	else{
		switch (_stage){
		case STAGE1:
			//맵 움직이기
			if (_stageOffX < 0){ _stageOffX = 0; }
			if (_stageOffX > 3700){ _stageOffX = 3700; }
			if (!_stage1_2Clear){
				if (_stageOffX > 1580 && _stageOffX < 1620){ _isScreenFix = true; }
			}
			if (!_stage1_3Clear){
				if (_stageOffX > 3180 && _stageOffX <= 3220){ _isScreenFix = true; }
			}
			if (_stage1_4Clear && _player->getPlayerX() > 1630){
				_isStageChange = true;
				_isAlphaUp = true;
				_stageChangeAlpha = 125;
			}
			_rcIRune = RectMake(0, 0, 0, 0);
			//몬스터소환
			if (!_stage1_1Start && _player->getPlayerX() < 1350){
				_stage1_1Start = true;
				_goblin1 = new goblin;
				_goblin1->init();
				_goblin1->create(1600, 300, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin1);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);
			}

			if (!_stage1_2Start && _player->getPlayerX() < 3180&& _stage1_1Clear && _isScreenFix){
				_stage1_2Start = true;
				
				_goblin1 = new goblin;
				_goblin1->init();
				_goblin1->create(1600, 150, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin1);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_goblin2 = new goblin;
				_goblin2->init();
				_goblin2->create(1600, 250, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin2);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_goblin3 = new goblin;
				_goblin3->init();
				_goblin3->create(1600, 350, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin3);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);
			}

			if (!_stage1_3Start && _player->getPlayerX() < 4000 && _stage1_2Clear && _isScreenFix){
				_stage1_3Start = true;
				_stage1_4Start = true;

				_goblin1 = new goblin;
				_goblin1->init();
				_goblin1->create(-200, 150, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin1);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_goblin2 = new goblin;
				_goblin2->init();
				_goblin2->create(-200, 250, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin2);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_goblin3 = new goblin;
				_goblin3->init();
				_goblin3->create(-200, 350, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin3);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_goblin4 = new goblin;
				_goblin4->init();
				_goblin4->create(-200, 450, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin4);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);
			}

			if (_player->getPlayerX() > 1350){
				if (_player->getRightButton()){
					if (!_isScreenFix){
						if (_player->getIsWalk()){
							_stageOffX += 10;
							_bgOffX += 0.1;
						}
						if (_player->getIsRun()){
							_stageOffX += 20;
							_bgOffX += 0.2;
						}
						if (_player->getIsRavitation()){
							_stageOffX += 30;
							_bgOffX += 0.3;
						}

					}
				}
			}
			if (_vMother.size()==0){
				_isScreenFix = false;
				if (_stageOffX > 0 && _stage1_1Start) _stage1_1Clear = true;
				if (_stageOffX >= 1590&& _stage1_2Start) _stage1_2Clear = true;
				if (_stageOffX >= 3180&& _stage1_3Start) _stage1_3Clear = true;
				if (_stageOffX >= 3700&& _stage1_4Start) _stage1_4Clear = true;
			}

				


			


			//캐릭터가 화면밖으로 못나가게 하기
			if (_player->getPlayerX() < -100){
				_player->setPlayerX(-100);
				_player->setShadowX(-100);
			}

			if (!_stage1_4Clear){
				if (_player->getPlayerX() > 1350){
					_player->setPlayerX(1350);
					_player->setShadowX(1350);
				}
			}
			if (_player->getShadowY() > 900){
				_player->setShadowY(900);
			}
			break;
		case STAGE2:
			if (!_stage2Start){
				_rcIRune = RectMake(0, 0, 0, 0);
				_stage2Start = true;
				//생성
				trapSetup(_trap1,330,300);
				trapSetup(_trap2, 750, 240);
				trapSetup(_trap2, 1050, 400);
				trapSetup(_trap2, 720, 500);

				_slime1 = new slime;
				_slime1->init();
				_slime1->create(800, 50, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vSlime.push_back(_slime1);
				_zOrder.push_back(_vSlime[_vSlime.size() - 1]);
				_vMother.push_back(_vSlime[_vSlime.size() - 1]);
				_battle->linkEnemyAddress(_vSlime[_vSlime.size() - 1]);

				_slime2 = new slime;
				_slime2->init();
				_slime2->create(400, 100, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vSlime.push_back(_slime2);
				_zOrder.push_back(_vSlime[_vSlime.size() - 1]);
				_vMother.push_back(_vSlime[_vSlime.size() - 1]);
				_battle->linkEnemyAddress(_vSlime[_vSlime.size() - 1]);

				_slime3 = new slime;
				_slime3->init();
				_slime3->create(300,350, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vSlime.push_back(_slime3);
				_zOrder.push_back(_vSlime[_vSlime.size() - 1]);
				_vMother.push_back(_vSlime[_vSlime.size() - 1]);
				_battle->linkEnemyAddress(_vSlime[_vSlime.size() - 1]);

				_slime4 = new slime;
				_slime4->init();
				_slime4->create(200, 450, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vSlime.push_back(_slime4);
				_zOrder.push_back(_vSlime[_vSlime.size() - 1]);
				_vMother.push_back(_vSlime[_vSlime.size() - 1]);
				_battle->linkEnemyAddress(_vSlime[_vSlime.size() - 1]);

				_slime5 = new slime;
				_slime5->init();
				_slime5->create(600, 250, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vSlime.push_back(_slime5);
				_zOrder.push_back(_vSlime[_vSlime.size() - 1]);
				_vMother.push_back(_vSlime[_vSlime.size() - 1]);
				_battle->linkEnemyAddress(_vSlime[_vSlime.size() - 1]);

				_slime6 = new slime;
				_slime6->init();
				_slime6->create(800, 450, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vSlime.push_back(_slime6);
				_zOrder.push_back(_vSlime[_vSlime.size() - 1]);
				_vMother.push_back(_vSlime[_vSlime.size() - 1]);
				_battle->linkEnemyAddress(_vSlime[_vSlime.size() - 1]);



			}

			//함정 발동
			RECT temp;
			if ((IntersectRect(&temp, &_vTrap[0]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[0]->getRcShadow(), &_player->getRcPlayer()))||
				(IntersectRect(&temp, &_vTrap[1]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[1]->getRcShadow(), &_player->getRcPlayer())) || 
				(IntersectRect(&temp, &_vTrap[2]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[2]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[3]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[3]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[4]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[4]->getRcShadow(), &_player->getRcPlayer())) || 
				(IntersectRect(&temp, &_vTrap[5]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[5]->getRcShadow(), &_player->getRcPlayer())) || 
				(IntersectRect(&temp, &_vTrap[6]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[6]->getRcShadow(), &_player->getRcPlayer())) || 
				(IntersectRect(&temp, &_vTrap[7]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[7]->getRcShadow(), &_player->getRcPlayer())) || 
				(IntersectRect(&temp, &_vTrap[8]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[8]->getRcShadow(), &_player->getRcPlayer())) ){
				for (int i = 0; i < 9; i++){ _vTrap[i]->start(); }
			}

			if ((IntersectRect(&temp, &_vTrap[9]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[9]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[10]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[10]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[11]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[11]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[12]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[12]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[13]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[13]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[14]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[14]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[15]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[15]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[16]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[16]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[17]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[17]->getRcShadow(), &_player->getRcPlayer()))){
				for (int i = 9; i < 18; i++){ _vTrap[i]->start(); }
			}

			if ((IntersectRect(&temp, &_vTrap[18]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[18]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[19]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[19]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[20]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[20]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[21]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[21]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[22]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[22]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[23]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[23]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[24]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[24]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[25]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[25]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[26]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[26]->getRcShadow(), &_player->getRcPlayer()))){
				for (int i = 18; i < 27; i++){ _vTrap[i]->start(); }
			}

			if ((IntersectRect(&temp, &_vTrap[27]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[27]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[28]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[28]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[29]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[29]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[30]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[30]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[31]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[31]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[32]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[32]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[33]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[33]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[34]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[34]->getRcShadow(), &_player->getRcPlayer())) ||
				(IntersectRect(&temp, &_vTrap[35]->getRcShadow(), &_player->getRcShadow()) && IntersectRect(&temp, &_vTrap[35]->getRcShadow(), &_player->getRcPlayer()))){
				for (int i = 27; i < 36; i++){ _vTrap[i]->start(); }
			}

			if (_vSlime.size() == 0){
				_stage2Clear = true;
			}

			//캐릭터가 화면밖으로 못나가게 하기
			if (_player->getPlayerX() < -100){
				_player->setPlayerX(-100);
				_player->setShadowX(-100);
			}

			if (!_stage2Clear || (_player->getPlayerY() < 190 || _player->getPlayerY() > 220)){
				if (_player->getPlayerX() > 1350){
					_player->setPlayerX(1350);
					_player->setShadowX(1350);
				}
			}
			if (_player->getShadowY() > 900){
				_player->setShadowY(900);
			}

			if (_stage2Clear && _player->getPlayerX() > 1630){
				_isStageChange = true;
				_isAlphaUp = true;
				_stageChangeAlpha = 125;
				for (int i = 0; i < _vTrap.size(); i++){
					_vTrap[i]->setShow(false);
				}
			}
			break;
		case STAGE3:
			//맵 움직이기
			if (_stageOffX < 0){ _stageOffX = 0; }
			if (_stageOffX > 4400){ _stageOffX = 4400; }
			if (!_stage3_2Clear){
				if (_stageOffX > 1580 && _stageOffX < 1620){ _isScreenFix = true; }
			}
			if (!_stage3_3Clear){
				if (_stageOffX > 3180 && _stageOffX <= 3220){ _isScreenFix = true; }
			}
			if (_stage3_4Clear && _player->getPlayerX() > 1630){
				_isStageChange = true;
				_isAlphaUp = true;
				_stageChangeAlpha = 125;
			}
			_rcIRune.left = -_stageOffX + 4500;
			_rcIRune.right = _rcIRune.left + 64;
			_rcIRune.top = 320;
			_rcIRune.bottom = _rcIRune.top + 64;

			//몬스터 소환
			if (!_stage3_1Start && _player->getPlayerX() < 1350){
				_stage3_1Start = true;
				_ghost1 = new ghost;
				_ghost1->init();
				_ghost1->create(800, 300, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGhost.push_back(_ghost1);
				_zOrder.push_back(_vGhost[_vGhost.size() - 1]);
				_vMother.push_back(_vGhost[_vGhost.size() - 1]);
				_battle->linkEnemyAddress(_vGhost[_vGhost.size() - 1]);
			}

			if (!_stage3_2Start && _player->getPlayerX() < 3180 && _stage3_1Clear && _isScreenFix){
				_stage3_2Start = true;
				_ghost1 = new ghost;
				_ghost1->init();
				_ghost1->create(800, 300, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGhost.push_back(_ghost1);
				_zOrder.push_back(_vGhost[_vGhost.size() - 1]);
				_vMother.push_back(_vGhost[_vGhost.size() - 1]);
				_battle->linkEnemyAddress(_vGhost[_vGhost.size() - 1]);


				_goblin1 = new goblin;
				_goblin1->init();
				_goblin1->create(1600, 150, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin1);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_goblin2 = new goblin;
				_goblin2->init();
				_goblin2->create(1600, 250, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin2);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);
			}

			if (!_stage3_3Start && _player->getPlayerX() < 4000 && _stage3_2Clear && _isScreenFix){
				_stage3_3Start = true;
				_stage3_4Start = true;

				_goblin1 = new goblin;
				_goblin1->init();
				_goblin1->create(-200, 150, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin1);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_goblin2 = new goblin;
				_goblin2->init();
				_goblin2->create(-200, 250, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin2);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_goblin3 = new goblin;
				_goblin3->init();
				_goblin3->create(-200, 350, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGoblin.push_back(_goblin3);
				_zOrder.push_back(_vGoblin[_vGoblin.size() - 1]);
				_vMother.push_back(_vGoblin[_vGoblin.size() - 1]);
				_battle->linkEnemyAddress(_vGoblin[_vGoblin.size() - 1]);

				_ghost1 = new ghost;
				_ghost1->init();
				_ghost1->create(800, 300, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vGhost.push_back(_ghost1);
				_zOrder.push_back(_vGhost[_vGhost.size() - 1]);
				_vMother.push_back(_vGhost[_vGhost.size() - 1]);
				_battle->linkEnemyAddress(_vGhost[_vGhost.size() - 1]);

				_slime1 = new slime;
				_slime1->init();
				_slime1->create(800, 50, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vSlime.push_back(_slime1);
				_zOrder.push_back(_vSlime[_vSlime.size() - 1]);
				_vMother.push_back(_vSlime[_vSlime.size() - 1]);
				_battle->linkEnemyAddress(_vSlime[_vSlime.size() - 1]);

				_slime2 = new slime;
				_slime2->init();
				_slime2->create(400, 100, (_player->getRcPlayer().left + _player->getRcPlayer().right) / 2);
				_vSlime.push_back(_slime2);
				_zOrder.push_back(_vSlime[_vSlime.size() - 1]);
				_vMother.push_back(_vSlime[_vSlime.size() - 1]);
				_battle->linkEnemyAddress(_vSlime[_vSlime.size() - 1]);
			}

			if (_dieAction){ _rcIRune = RectMake(0, 0, 0, 0); }
			if (INIDATA->loadDataInterger("PlayerData", "A룬", "num") != 0){
				_rcERune = RectMake(_player->getPlayerX(), _player->getPlayerY() + 250, 64, 64);
			}
			if (INIDATA->loadDataInterger("PlayerData", "B룬", "num") != 0){
				_rcTRune = RectMake(_player->getPlayerX() + 140, _player->getPlayerY() + 250, 64, 64);
			}
			if (INIDATA->loadDataInterger("PlayerData", "C룬", "num") != 0){
				_rcSRune = RectMake(_player->getPlayerX() + 70, _player->getPlayerY() + 250, 64, 64);
			}
			if (INIDATA->loadDataInterger("PlayerData", "D룬", "num") != 0){
				_rcDRune = RectMake(_player->getPlayerX() - 70, _player->getPlayerY() + 250, 64, 64);
			}
			if (INIDATA->loadDataInterger("PlayerData", "E룬", "num") != 0){
				_rcMRune = RectMake(_player->getPlayerX() + 210, _player->getPlayerY() + 250, 64, 64);
			}
			if (INIDATA->loadDataInterger("PlayerData", "F룬", "num") != 0){
				_rcRRune = RectMake(_player->getPlayerX() + 280, _player->getPlayerY() + 250, 64, 64);
			}
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)){
				if (PtInRect(&_rcIRune, _ptMouse)){
					if (_runeRoom[0] != 7 && _runeRoom[1] != 7 && _runeRoom[2] != 7){
						_isIClick = true;
						_runeRoom[_runeRoomCount] = 8;
						_runeRoomCount++;
					}
				}else if (PtInRect(&_rcDRune, _ptMouse)){
					if (_runeRoom[0] != 1 && _runeRoom[1] != 1 && _runeRoom[2] != 1){
						_runeRoom[_runeRoomCount] = 1;
						_runeRoomCount++;
					}
				}else if (PtInRect(&_rcERune, _ptMouse)){
					if (_runeRoom[0] != 2 && _runeRoom[1] != 2 && _runeRoom[2] != 2){
						_runeRoom[_runeRoomCount] = 2;
						_runeRoomCount++;
					}
				}else if (PtInRect(&_rcMRune, _ptMouse)){
					if (_runeRoom[0] != 3 && _runeRoom[1] != 3 && _runeRoom[2] != 3){
						_runeRoom[_runeRoomCount] = 3;
						_runeRoomCount++;
					}
				}else if (PtInRect(&_rcRRune, _ptMouse)){
					if (_runeRoom[0] != 4 && _runeRoom[1] != 4 && _runeRoom[2] != 4){
						_runeRoom[_runeRoomCount] = 4;
						_runeRoomCount++;
					}
				}else if (PtInRect(&_rcSRune, _ptMouse)){
					if (_runeRoom[0] != 5 && _runeRoom[1] != 5 && _runeRoom[2] != 5){
						_runeRoom[_runeRoomCount] = 5;
						_runeRoomCount++;
					}
				}else if (PtInRect(&_rcTRune, _ptMouse)){
					if (_runeRoom[0] != 6 && _runeRoom[1] != 6 && _runeRoom[2] != 6){
						_runeRoom[_runeRoomCount] = 6;
						_runeRoomCount++;
					}
				}
				else{
					_isIClick = false;
				}


				if (_runeRoomCount == 3){
					if ((_runeRoom[0] == _die[0] || _runeRoom[1] == _die[0] || _runeRoom[2] == _die[0]) &&
						(_runeRoom[0] == _die[1] || _runeRoom[1] == _die[1] || _runeRoom[2] == _die[1]) &&
						(_runeRoom[0] == _die[2] || _runeRoom[1] == _die[2] || _runeRoom[2] == _die[2])){
						_dieAction = true;
						_lightAction = true;
						_blackAction = true;
					}
					else{
						_runeRoomCount = 0;
						_runeRoom[0] = -1;
						_runeRoom[1] = -1;
						_runeRoom[2] = -1;
						_isIClick = false;
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
								SOUNDMANAGER->play("룬생성", 0.3f);
								_showRoom[0] = true;
							}
							if (_lightX == 800){
								SOUNDMANAGER->play("룬생성", 0.3f);
								_showRoom[1] = true;
							}
							if (_lightX == 950){
								SOUNDMANAGER->play("룬생성", 0.3f);
								_showRoom[2] = true;
							}
							if (_lightX >= 950){
								SOUNDMANAGER->play("룬완료", 0.3f);
								_lightAction = false;
								_lightX = 500;
							}
						}
					}
				}
			}

			if (_dieAction){
				if (!_lightAction){
					_blackActionTimer += 0.01f;
					_runeAlpha += 2;
					if (_runeAlpha > 250){ _runeAlpha = 250; }
					if (_blackActionTimer > 2){
						_blackAction = false;
						_blackActionTimer = 0;
						_isIClick = false;
						_runeRoomCount = 0;
						_runeRoom[0] = -1;
						_runeRoom[1] = -1;
						_runeRoom[2] = -1;
						_isDie = true;
					}
				}
				_rcIRune = RectMake(0, 0, 0, 0);
				_dieOffX++;
			}


			if (_player->getPlayerX() > 1350){
				if (_player->getRightButton()){
					if (!_isScreenFix){
						if (_player->getIsWalk()){
							_stageOffX += 10;
							_bgOffX += 0.1;
						}
						if (_player->getIsRun()){
							_stageOffX += 20;
							_bgOffX += 0.2;
						}
						if (_player->getIsRavitation()){
							_stageOffX += 30;
							_bgOffX += 0.3;
						}

					}
				}
			}

			if (_vMother.size() == 0){
				_isScreenFix = false;
				if (_stageOffX > 0 && _stage3_1Start) _stage3_1Clear = true;
				if (_stageOffX >= 1590 && _stage3_2Start) _stage3_2Clear = true;
				if (_stageOffX >= 3180 && _stage3_3Start) _stage3_3Clear = true;
				if (_stageOffX >= 3700 && _stage3_4Start) _stage3_4Clear = true;
			}


			


			//캐릭터가 화면밖으로 못나가게 하기
			if (_player->getPlayerX() < -100){
				_player->setPlayerX(-100);
				_player->setShadowX(-100);
			}

			if (!_stage3_4Clear){
				if (_player->getPlayerX() > 1350){
					_player->setPlayerX(1350);
					_player->setShadowX(1350);
				}
			}
			if (_player->getShadowY() > 900){
				_player->setShadowY(900);
			}

			//화면 검게하기
			if (_vGhost.size() > 0){
				for (int i = 0; i < _vMother.size(); i++){
					_vMother[i]->setIsGhost(true);
				}
			}
			else{
				for (int i = 0; i < _vMother.size(); i++){
					_vMother[i]->setIsGhost(false);
				}
			}

			break;
		case STAGE4:
			if (!_stage4Start){
				_rcIRune = RectMake(0, 0, 0, 0);
				_stage4Start = true;
				//생성

				_killerRabbit = new killerRabbit;
				_killerRabbit->init();
				_killerRabbit->create(800, -300);
				_zOrder.push_back(_killerRabbit);
				_vMother.push_back(_killerRabbit);
				_battle->linkEnemyAddress(_killerRabbit);
				SOUNDMANAGER->stop("무덤스테이지");
				SOUNDMANAGER->play("토끼보스",0.1F);
			}

			_hpBar->setGauge(_killerRabbit->getHp(), _killerRabbit->getMaxHp());

			//캐릭터가 화면밖으로 못나가게 하기
			if (_player->getPlayerX() < -100){
				_player->setPlayerX(-100);
				_player->setShadowX(-100);
			}

			if (!_stage3_4Clear){
				if (_player->getPlayerX() > 1350){
					_player->setPlayerX(1350);
					_player->setShadowX(1350);
				}
			}
			if (_player->getShadowY() > 900){
				_player->setShadowY(900);
			}

			if (_killerRabbit->getIsDie()){
				_stage4Clear = true;
				SOUNDMANAGER->stop("토끼보스");
				if (!SOUNDMANAGER->isPlaySound("전투결과")){
					SOUNDMANAGER->play("전투결과", 0.1F);
				}
			}

			break;

		}
	}
	/////////////////////////////////////////////////////////


	////////////////플레이어/////////////////

	
	if (!_isStageChange)
		_player->update();
	if (pixelCollision(getPixelMemDC(), 1, _player->getShadowX() + 140, _player->getShadowY(), 0, 60, RGB(0, 255, 255), &_position) ||
		pixelCollision(getPixelMemDC(), 1, _player->getShadowX() + 140, _player->getShadowY(), 10, 30, RGB(255, 255, 0), &_position)){
		_player->setShadowY(_position);
		_player->setPixelCollision(true);
	}
	else{
		_player->setPixelCollision(false);
	}
	skill();
	//ui
	_ui->update();
	_expBar->update();

	//아이스프리즌과 충돌
	_objectCollision->collision();
	for (int i = 0;i< _vMother.size(); i++){
		_objectCollision->collision(_vMother[i]);
	}
	///////////////////////////////////////

	/////////////////////////////몬스터//////////////////////////////
	
	//몬스터 삭제
	for (_viGoblin = _vGoblin.begin(); _viGoblin != _vGoblin.end();){
		if (!(*_viGoblin)->getShow()){
			_vGoblin.erase(_viGoblin);
			int mp = _player->getMp() + INIDATA->loadDataInterger("PlayerData", "Skill", "mental_absorb") * 10;
			if (mp > _player->getMpMax()){ mp = _player->getMpMax(); }
			_player->setMp(mp);
			break;
		}
		else{
			_viGoblin++;
		}
	}

	for (_viSlime = _vSlime.begin(); _viSlime != _vSlime.end();){
		if (!(*_viSlime)->getShow()){
			_vSlime.erase(_viSlime);
			int mp = _player->getMp() + INIDATA->loadDataInterger("PlayerData", "Skill", "mental_absorb") * 10;
			if (mp > _player->getMpMax()){ mp = _player->getMpMax(); }
			_player->setMp(mp);
			break;
		}
		else{
			_viSlime++;
		}
	}

	for (_viGhost = _vGhost.begin(); _viGhost != _vGhost.end();){
		if (!(*_viGhost)->getShow()){
			_vGhost.erase(_viGhost);
			int mp = _player->getMp() + INIDATA->loadDataInterger("PlayerData", "Skill", "mental_absorb") * 10;
			if (mp > _player->getMpMax()){ mp = _player->getMpMax(); }
			_player->setMp(mp);
			break;
		}
		else{
			_viGhost++;
		}
	}

	if (_stage == STAGE3 && _isDie){
		for (int i = 0; i < _vMother.size(); i++){
			_vMother[i]->damage(9999);
		}
	}
	

	for (int i = 0; i < _vGoblin.size(); i++){		//고블린
		_vGoblin[i]->update(_player->getPlayerX(),_player->getPlayerY(),_player->getRcPlayer(),_player->getRcShadow());
	}

	for (int i = 0; i < _vSlime.size(); i++){		//슬라임
		_vSlime[i]->update(_player->getPlayerX(), _player->getPlayerY(), _player->getRcPlayer(), _player->getRcShadow());
	}

	for (int i = 0; i < _vTrap.size(); i++){		//함정
		_vTrap[i]->update(_player->getRcPlayer(), _player->getRcShadow());
	}

	for (int i = 0; i < _vGhost.size(); i++){		//고스트
		_vGhost[i]->update(_player->getPlayerX(), _player->getPlayerY(), _player->getRcPlayer(), _player->getRcShadow());
	}
	

	if (_stage==STAGE4)
	_killerRabbit->update(_player->getRcPlayer(), _player->getRcShadow());
	////////////////////////////////////////////////////////////////




	//////////////////////////////전투/////////////////////////////

	
	//몬스터
	//삭제
	for (_viMother = _vMother.begin(); _viMother != _vMother.end();){
		if (!(*_viMother)->getShow()){
			_vMother.erase(_viMother);
			break;
		}
		else{
			_viMother++;
		}
	}
	
	if (_vMother.size() > 0){
		for (int i = 0; i < _vMother.size(); i++){
			_battle->linkEnemyAddress(_vMother[i]);
			_battle->enemyAttack();
			
			//플레이어
			_battle->linkManaballAddress(_manaball1);
			_battle->manaball();
			_battle->linkManaballAddress(_manaball2);
			_battle->manaball();
			for (int i = 0; i < 8; i++){
				_battle->linkNormalBullet1Address(_normalBullet1[i]);
				_battle->normalBullet1();
			}

			for (int i = 0; i <5; i++){
				_battle->linkNormalBullet1Address(_normalBullet2[i]);
				_battle->normalBullet1();
			}
			_battle->playerAttack();
		}
	}
	else{
		_battle->linkEnemyAddress(_mother);
	}
	////////////////////////////////
	_battle->update();
	//몬스터 죽으면 show를 false로 만들기



	//zOrder안쓰는거 삭제
	for (_viZOrder = _zOrder.begin(); _viZOrder != _zOrder.end();){
		if (!(*_viZOrder)->getShow()){
			_zOrder.erase(_viZOrder);
			break;
		}
		else{
			_viZOrder++;
		}
	}

	//zOrder순서 정하기
	for (int i = 0; i < _zOrder.size() - 1; i++){
		if (_zOrder.size() == 0)break;
		for (int j = i + 1; j < _zOrder.size(); j++){
			gameNode* _temp;
			if (_zOrder[i]->getRect().bottom>_zOrder[j]->getRect().bottom){
				_temp = _zOrder[i];
				_zOrder[i] = _zOrder[j];
				_zOrder[j] = _temp;
			}
		}
	}
	KEYANIMANAGER->update();

	if (!_stage4Start){
		_killerRabbit->setIsDeathAttack(false);
	}

	if (_stage4Clear){
		if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "red") == 0) && _exp < EXP){
			_player->setExp(_player->getExp() + 10);
			_exp += 10;
		}
		else if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "orange") == 0) && _exp < EXP*2){
			_player->setExp(_player->getExp() + 20);
			_exp += 20;
		}
		else if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "yellow") == 0) && _exp < EXP * 3){
			_player->setExp(_player->getExp() + 30);
			_exp += 30;
		}
		else if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "green") == 0) && _exp < EXP * 4){
			_player->setExp(_player->getExp() + 40);
			_exp += 40;
		}
		else if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "skyblue") == 0) && _exp < EXP * 5){
			_player->setExp(_player->getExp() + 50);
			_exp += 50;
		}
		else if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "blue") == 0) && _exp < EXP * 6){
			_player->setExp(_player->getExp() + 60);
			_exp += 60;
		}
		else if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "pupple") == 0) && _exp < EXP * 7){
			_player->setExp(_player->getExp() + 70);
			_exp += 70;
		}
		else if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "white") == 0) && _exp < EXP * 8){
			_player->setExp(_player->getExp() + 80);
			_exp += 80;
		}
		else if ((INIDATA->loadDataInterger("PlayerData", "Talizman", "black") == 0) && _exp < EXP * 9){
			_player->setExp(_player->getExp() + 90);
			_exp += 90;
		}
		else{
			if (KEYMANAGER->isOnceKeyDown('R')){
				if (!_isGain){
					_isGain = true;
				}else if (_isGain){
					SOUNDMANAGER->allRemove();
					if (_talizman[0] == 0){ _talizman[0] = 1; }
					else if (_talizman[1] == 0){ _talizman[1] = 1; }
					else if (_talizman[2] == 0){ _talizman[2] = 1; }
					else if (_talizman[3] == 0){ _talizman[3] = 1; }
					else if (_talizman[4] == 0){ _talizman[4] = 1; }
					else if (_talizman[5] == 0){ _talizman[5] = 1; }
					else if (_talizman[6] == 0){ _talizman[6] = 1; }
					else if (_talizman[7] == 0){ _talizman[7] = 1; }
					else if (_talizman[8] == 0){ _talizman[8] = 1; }
					save();
					SCENEMANAGER->changeScene("마을로딩씬");
				}
			}
		}
	}
}

void graveScene::render(){
	switch (_stage){
	case STAGE1:
		IMAGEMANAGER->findImage("지하배경1")->render(getMemDC(), -_bgOffX, 0);
		IMAGEMANAGER->findImage("지하스테이지1")->render(getMemDC(), -_stageOffX, 0);
		PatBlt(getPixelMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
		IMAGEMANAGER->findImage("지하스테이지1픽셀")->render(getPixelMemDC(), -_stageOffX, 60);
		
		break;
	case STAGE2:
		IMAGEMANAGER->findImage("지하스테이지2")->render(getMemDC(), 0, -40);
		IMAGEMANAGER->findImage("지하스테이지2픽셀")->render(getPixelMemDC(), 0, 30);
		break;
	case STAGE3:
		IMAGEMANAGER->findImage("지하배경3")->render(getMemDC(), -_bgOffX, 0);
		IMAGEMANAGER->findImage("지하스테이지3")->render(getMemDC(), -_stageOffX, -70);
		IMAGEMANAGER->findImage("지하스테이지3픽셀")->render(getPixelMemDC(), -_stageOffX,0 );
		if (!_dieAction){
			if (!_isIClick){
				IMAGEMANAGER->findImage("i")->render(getMemDC(), _rcIRune.left, _rcIRune.top);
			}
			else{
				IMAGEMANAGER->findImage("i발동")->render(getMemDC(), _rcIRune.left, _rcIRune.top);
			}
		}
		if (_vGhost.size()>0)
			IMAGEMANAGER->findAlphaImage("흑백")->alphaRender(getMemDC(), 0, 0, 220);
		break;
	case STAGE4:
		IMAGEMANAGER->findImage("지하스테이지4")->render(getMemDC(), 0, -40);
		IMAGEMANAGER->findImage("지하스테이지4픽셀")->render(getPixelMemDC(), 0, 0);
		break;
		
	}
	for (int i = 0; i < _zOrder.size(); i++){
		_zOrder[i]->render();
	}
	//플레이어
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
	switch (_stage){
	case STAGE1:
		break;
	case STAGE2:
		if (_player->getPlayerY() <= 223){
			IMAGEMANAGER->findImage("지하스테이지2_2")->render(getMemDC(), 0, -40);
		}
		break;
	case STAGE3:
		if (_player->getPlayerY() <= 265 && _stageOffX == 0){
			IMAGEMANAGER->findImage("지하스테이지3_2")->render(getMemDC(), 0, -70);
		}
		break;
	case STAGE4:
		if (_player->getPlayerY() <= 226){
			IMAGEMANAGER->findImage("지하스테이지4_2")->render(getMemDC(), 0, -40);
		}
		break;

	}
	_battle->render();

	if (_isStageChange){
		IMAGEMANAGER->findAlphaImage("grave_black")->alphaRender(getMemDC(), 0, 0, _stageChangeAlpha);
	}

	if (_killerRabbit->getIsDeathAttack()){
		IMAGEMANAGER->findAlphaImage("grave_black")->alphaRender(getMemDC(), 0, 0, 150);
		if (_player->getIsRight()){
			EFFECTMANAGER->play("rabbit_right", _player->getRcPlayer().left, _player->getRcPlayer().top);
		}
		if (_player->getIsLeft()){
			EFFECTMANAGER->play("rabbit_left", _player->getRcPlayer().left+150, _player->getRcPlayer().top);
		}
		_killerRabbit->setIsDeathAttack(false);
	}
	EFFECTMANAGER->render();
	
	if (_stage == STAGE4){
		_hpBar->render();
		IMAGEMANAGER->findImage("killerRabbitName")->render(getMemDC(), 100, 730);
	}

	if (_stage4Clear){
		if (!_isGain){
			IMAGEMANAGER->findAlphaImage("grave_black")->alphaRender(getMemDC(), 0, 0, 240);
			IMAGEMANAGER->findPngImage("bg_sorceress")->render(getMemDC(), 730, 150);
			IMAGEMANAGER->findAlphaImage("stateTop")->render(getMemDC(), 0, 0);
			IMAGEMANAGER->findAlphaImage("stateBottom")->alphaRender(getMemDC(), 0, 700, 200);
			IMAGEMANAGER->findAlphaImage("양피지1")->alphaRender(getMemDC(), 0, 140, 400);
			_expBar->setGauge(_player->getExp(), _player->getLevelExp()[_player->getLv()]);
			_expBar->render();


			//스탯 
			SetBkMode(getMemDC(), TRANSPARENT);
			HFONT hFont, oldFont;
			char str[100];
			hFont = CreateFont(35, 13, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), hFont);
			SetTextColor(getMemDC(), RGB(230, 10, 92));
			TextOut(getMemDC(), 300, 230, "Sorceress", strlen("Sorceress"));
			TextOut(getMemDC(), 270, 280, "LV", strlen("LV"));
			TextOut(getMemDC(), 270, 320, "EXP", strlen("EXP"));
			TextOut(getMemDC(), 270, 360, "NEXT", strlen("NEXT"));
			TextOut(getMemDC(), 200, 420, "HP", strlen("HP"));
			TextOut(getMemDC(), 200, 460, "STR", strlen("STR"));
			TextOut(getMemDC(), 200, 500, "CON", strlen("CON"));
			TextOut(getMemDC(), 200, 540, "DEX", strlen("DEX"));
			TextOut(getMemDC(), 500, 460, "INT", strlen("INT"));
			TextOut(getMemDC(), 500, 500, "MGR", strlen("MGR"));
			TextOut(getMemDC(), 500, 540, "LUC", strlen("LUC"));
			TextOut(getMemDC(), 270, 600, "스킬 포인트", strlen("스킬 포인트"));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(hFont);

			hFont = CreateFont(35, 13, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), hFont);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			sprintf(str, "%d", _player->getLv());
			TextOut(getMemDC(), 400, 280, str, strlen(str));
			sprintf(str, "%d", _player->getExp());
			TextOut(getMemDC(), 400, 320, str, strlen(str));
			sprintf(str, "%d", _player->getLevelExp()[_player->getLv()]);
			TextOut(getMemDC(), 400, 360, str, strlen(str));
			sprintf(str, "%d", _player->getHp());
			TextOut(getMemDC(), 330, 420, str, strlen(str));
			sprintf(str, "%d", _player->getStr());
			TextOut(getMemDC(), 330, 460, str, strlen(str));
			sprintf(str, "%d", _player->getCon());
			TextOut(getMemDC(), 330, 500, str, strlen(str));
			sprintf(str, "%d", _player->getDex());
			TextOut(getMemDC(), 330, 540, str, strlen(str));
			sprintf(str, "%d", _player->getInt());
			TextOut(getMemDC(), 630, 460, str, strlen(str));
			sprintf(str, "%d", _player->getMgr());
			TextOut(getMemDC(), 630, 500, str, strlen(str));
			sprintf(str, "%d", _player->getLuc());
			TextOut(getMemDC(), 630, 540, str, strlen(str));
			sprintf(str, "%d", _player->getSkillPoint());
			TextOut(getMemDC(), 500, 600, str, strlen(str));;
			SelectObject(getMemDC(), oldFont);
			DeleteObject(hFont);
		}
		if (_isGain){
			if (_talizman[0] == 0) IMAGEMANAGER->findAlphaImage("red_talizma")->alphaRender(getMemDC(), 255);
			else if (_talizman[1] == 0) IMAGEMANAGER->findAlphaImage("orange_talizma")->alphaRender(getMemDC(), 255);
			else if (_talizman[2] == 0) IMAGEMANAGER->findAlphaImage("yellow_talizma")->alphaRender(getMemDC(), 255);
			else if (_talizman[3] == 0) IMAGEMANAGER->findAlphaImage("green_talizma")->alphaRender(getMemDC(), 255);
			else if (_talizman[4] == 0) IMAGEMANAGER->findAlphaImage("bluesky_talizma")->alphaRender(getMemDC(), 255);
			else if (_talizman[5] == 0) IMAGEMANAGER->findAlphaImage("blue_talizma")->alphaRender(getMemDC(), 255);
			else if (_talizman[6] == 0) IMAGEMANAGER->findAlphaImage("pupple_talizma")->alphaRender(getMemDC(), 255);
			else if (_talizman[7] == 0) IMAGEMANAGER->findAlphaImage("white_talizma")->alphaRender(getMemDC(), 255);
			else if (_talizman[8] == 0) IMAGEMANAGER->findAlphaImage("black_talizma")->alphaRender(getMemDC(), 255);
		}
	}


	//룬UI
	if (_isIClick){
		IMAGEMANAGER->findAlphaImage("rune_room")->alphaRender(getMemDC(), _player->getPlayerX() - 10, _player->getPlayerY() + 120, 200);
		IMAGEMANAGER->findAlphaImage("rune_room")->alphaRender(getMemDC(), _player->getPlayerX() + 90, _player->getPlayerY() + 120, 200);
		IMAGEMANAGER->findAlphaImage("rune_room")->alphaRender(getMemDC(), _player->getPlayerX() + 190, _player->getPlayerY() + 120, 200);

		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), _rcDRune.left, _rcDRune.top, 3, 5);
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), _rcERune.left, _rcERune.top, 0, 5);
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), _rcSRune.left, _rcSRune.top, 2, 5);
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), _rcTRune.left, _rcTRune.top, 1, 5);
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), _rcMRune.left, _rcMRune.top, 4, 5);
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), _rcRRune.left, _rcRRune.top, 5, 5);

		for (int i = 0; i < 3; i++){
			switch (_runeRoom[i]){
			case 1:
				IMAGEMANAGER->findImage("d선택")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 2:
				IMAGEMANAGER->findImage("e선택")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 3:
				IMAGEMANAGER->findImage("m선택")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 4:
				IMAGEMANAGER->findImage("r선택")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 5:
				IMAGEMANAGER->findImage("s선택")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 6:
				IMAGEMANAGER->findImage("t선택")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 7:
				IMAGEMANAGER->findImage("z선택")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			case 8:
				IMAGEMANAGER->findImage("i선택")->render(getMemDC(), _player->getPlayerX() + 10 + i * 98, _player->getPlayerY() + 140);
				break;
			}
		}
	}

	if (_blackAction){
		IMAGEMANAGER->findAlphaImage("rune_black")->alphaRender(getMemDC(), 0, 0, 220);
		if (_lightAction)
			IMAGEMANAGER->findAlphaImage("light")->alphaFrameRender(getMemDC(), _lightX, _lightY, _lightFrameX, _lightFrameY, 180);
		if (_showRoom[0]){
			IMAGEMANAGER->findImage("d발동")->render(getMemDC(), 600, 450);
		}
		if (_showRoom[1]){
			IMAGEMANAGER->findImage("i발동")->render(getMemDC(), 750, 450);
		}
		if (_showRoom[2]){
			IMAGEMANAGER->findImage("e발동")->render(getMemDC(), 900, 450);
		}

		if (_showRoom[2]){
			IMAGEMANAGER->findAlphaImage("die_info")->alphaRender(getMemDC(), 0, 600, _runeAlpha);
		}
	}

	

}

void graveScene::release(){}

void graveScene::skill(){
	//스킬 
	for (int i = 0; i < 8; i++){
		_normalBullet1[i]->update();
	}

	if (_player->getIsRight()){
		if (_player->getIsFireball1()){
			_player->setIsFireball1(false);
			_normalBullet1[0]->start(_player->getPlayerX() + 100, _player->getPlayerY());
			_normalBullet1[0]->setShow(true);
			_zOrder.push_back(_normalBullet1[0]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[0]->getFrameX() == 2){
			_normalBullet1[1]->start(_normalBullet1[0]->getX() - 70, _normalBullet1[0]->getY() - 20);
			_normalBullet1[1]->setShow(true);
			_zOrder.push_back(_normalBullet1[1]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[1]->getFrameX() == 2){
			_normalBullet1[2]->start(_normalBullet1[1]->getX() - 70, _normalBullet1[1]->getY() - 20);
			_normalBullet1[2]->setShow(true);
			_zOrder.push_back(_normalBullet1[2]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[2]->getFrameX() == 2){
			_normalBullet1[3]->start(_normalBullet1[2]->getX() - 70, _normalBullet1[2]->getY() - 100);
			_normalBullet1[3]->setShow(true);
			_zOrder.push_back(_normalBullet1[3]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[3]->getFrameX() == 2){
			_normalBullet1[4]->start(_normalBullet1[3]->getX() - 70, _normalBullet1[3]->getY() - 100);
			_normalBullet1[4]->setShow(true);
			_zOrder.push_back(_normalBullet1[4]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[4]->getFrameX() == 2){
			_normalBullet1[5]->start(_normalBullet1[4]->getX() + 70, _normalBullet1[4]->getY() - 100);
			_normalBullet1[5]->setShow(true);
			_zOrder.push_back(_normalBullet1[5]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
			//_normalBullet1[5]->setRect(RectMake(_normalBullet1[5]->getRc().left + 300,
			//	_normalBullet1[5]->getRc().top,
			//	_normalBullet1[5]->getRc().right,
			//	_normalBullet1[5]->getRc().bottom));
		}

		if (_normalBullet1[5]->getFrameX() == 2){
			_normalBullet1[6]->start(_normalBullet1[5]->getX() + 70, _normalBullet1[5]->getY() - 100);
			//_normalBullet1[6]->setRect(RectMake(_normalBullet1[6]->getRc().left + 300,
			//	_normalBullet1[6]->getRc().top,
			//	_normalBullet1[6]->getRc().right,
			//	_normalBullet1[6]->getRc().bottom));
			_normalBullet1[6]->setShow(true);
			_zOrder.push_back(_normalBullet1[6]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[6]->getFrameX() == 2){
			_normalBullet1[7]->start(_normalBullet1[6]->getX() + 70, _normalBullet1[6]->getY() - 20);
			_normalBullet1[7]->setShow(true);
			_zOrder.push_back(_normalBullet1[7]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball1()){
			_player->setIsFireball1(false);
			_normalBullet1[0]->start(_player->getPlayerX() - 160, _player->getPlayerY() - 20);
			_normalBullet1[0]->setShow(true);
			_zOrder.push_back(_normalBullet1[0]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[0]->getFrameX() == 2){
			_normalBullet1[1]->start(_normalBullet1[0]->getX() + 70, _normalBullet1[0]->getY() - 20);
			_normalBullet1[1]->setShow(true);
			_zOrder.push_back(_normalBullet1[1]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[1]->getFrameX() == 2){
			_normalBullet1[2]->start(_normalBullet1[1]->getX() + 70, _normalBullet1[1]->getY() - 20);
			_normalBullet1[2]->setShow(true);
			_zOrder.push_back(_normalBullet1[2]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[2]->getFrameX() == 2){
			_normalBullet1[3]->start(_normalBullet1[2]->getX() + 70, _normalBullet1[2]->getY() - 100);
			_normalBullet1[3]->setShow(true);
			_zOrder.push_back(_normalBullet1[3]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[3]->getFrameX() == 2){
			_normalBullet1[4]->start(_normalBullet1[3]->getX() + 70, _normalBullet1[3]->getY() - 100);
			_normalBullet1[4]->setShow(true);
			_zOrder.push_back(_normalBullet1[4]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[4]->getFrameX() == 2){
			_normalBullet1[5]->start(_normalBullet1[4]->getX() - 70, _normalBullet1[4]->getY() - 100);
			_normalBullet1[5]->setShow(true);
			_zOrder.push_back(_normalBullet1[5]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet1[5]->getFrameX() == 2){
			_normalBullet1[6]->start(_normalBullet1[5]->getX() - 70, _normalBullet1[5]->getY() - 100);
			_normalBullet1[6]->setShow(true);
			_zOrder.push_back(_normalBullet1[6]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
			//_normalBullet1[6]->setRect(RectMake(_normalBullet1[6]->getRc().left + 300,
			//	_normalBullet1[6]->getRc().top,
			//	_normalBullet1[6]->getRc().right,
			//	_normalBullet1[6]->getRc().bottom));
		}

		if (_normalBullet1[6]->getFrameX() == 2){
			_normalBullet1[7]->start(_normalBullet1[6]->getX() - 70, _normalBullet1[6]->getY() - 20);
			_normalBullet1[7]->setShow(true);
			_zOrder.push_back(_normalBullet1[7]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
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
			_normalBullet2[0]->setShow(true);
			_zOrder.push_back(_normalBullet2[0]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet2[0]->getFrameX() == 2){
			_normalBullet2[1]->start(_normalBullet2[0]->getX() + 200, _normalBullet2[0]->getY() - 60);
			_normalBullet2[1]->setShow(true);
			_zOrder.push_back(_normalBullet2[1]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet2[1]->getFrameX() == 2){
			_normalBullet2[2]->start(_normalBullet2[1]->getX() + 200, _normalBullet2[1]->getY() - 60);
			_normalBullet2[2]->setShow(true);
			_zOrder.push_back(_normalBullet2[2]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet2[2]->getFrameX() == 2){
			_normalBullet2[3]->start(_normalBullet2[2]->getX() + 200, _normalBullet2[2]->getY() - 60);
			_normalBullet2[3]->setShow(true);
			_zOrder.push_back(_normalBullet2[3]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet2[3]->getFrameX() == 2){
			_normalBullet2[4]->start(_normalBullet2[3]->getX() + 200, _normalBullet2[3]->getY() - 60);
			_normalBullet2[4]->setShow(true);
			_zOrder.push_back(_normalBullet2[4]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball2()){
			_player->setIsFireball2(false);
			_normalBullet2[0]->start(_player->getPlayerX() - 200, _player->getPlayerY());
			_normalBullet2[0]->setShow(true);
			_zOrder.push_back(_normalBullet2[0]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet2[0]->getFrameX() == 2){
			_normalBullet2[1]->start(_normalBullet2[0]->getX() - 200, _normalBullet2[0]->getY() - 60);
			_normalBullet2[1]->setShow(true);
			_zOrder.push_back(_normalBullet2[1]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet2[1]->getFrameX() == 2){
			_normalBullet2[2]->start(_normalBullet2[1]->getX() - 200, _normalBullet2[1]->getY() - 60);
			_normalBullet2[2]->setShow(true);
			_zOrder.push_back(_normalBullet2[2]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet2[2]->getFrameX() == 2){
			_normalBullet2[3]->start(_normalBullet2[2]->getX() - 200, _normalBullet2[2]->getY() - 60);
			_normalBullet2[3]->setShow(true);
			_zOrder.push_back(_normalBullet2[3]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}

		if (_normalBullet2[3]->getFrameX() == 2){
			_normalBullet2[4]->start(_normalBullet2[3]->getX() - 200, _normalBullet2[3]->getY() - 60);
			_normalBullet2[4]->setShow(true);
			_zOrder.push_back(_normalBullet2[4]);
			SOUNDMANAGER->stop("폭발");
			SOUNDMANAGER->play("폭발", 0.15F);
		}
	}


	//normalBullet3;
	_normalBullet3->update();

	if (_player->getIsRight()){
		if (_player->getIsFireball3()){
			_player->setIsFireball3(false);
			_normalBullet3->start(_player->getPlayerX() + 100, _player->getPlayerY() - 10);
			_normalBullet3->setShow(true);
			_zOrder.push_back(_normalBullet3);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball3()){
			_player->setIsFireball3(false);
			_normalBullet3->start(_player->getPlayerX() - 300, _player->getPlayerY() - 10);
			_normalBullet3->setShow(true);
			_zOrder.push_back(_normalBullet3);
		}
	}

	//normalBullet4;
	_normalBullet4->update();
	if (_player->getIsRight()){
		if (_player->getIsFireball4()){
			_player->setIsFireball4(false);
			_normalBullet4->fire(_player->getPlayerX() + 300, _player->getPlayerY() + 200, _player->getShadowX(), _player->getShadowY(), 0, 600, 0, 0);
			_normalBullet4->setShow(true);
			_zOrder.push_back(_normalBullet4);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball4()){
			_player->setIsFireball4(false);
			_normalBullet4->fire(_player->getPlayerX(), _player->getPlayerY() + 200, _player->getShadowX(), _player->getShadowY(), PI, 600, 0, 1);
			_normalBullet4->setShow(true);
			_zOrder.push_back(_normalBullet4);
		}
	}

	//normalBullet5;
	_normalBullet5->update();
	if (_player->getIsRight()){
		if (_player->getIsFireball5()){
			_player->setIsFireball5(false);
			_normalBullet5->fire(_player->getPlayerX() + 450, _player->getPlayerY() + 300, _player->getShadowX(), _player->getShadowY(), PI + PI * 3 / 4, 600, 0, 0);
			_normalBullet5->setShow(true);
			_zOrder.push_back(_normalBullet5);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball5()){
			_player->setIsFireball5(false);
			_normalBullet5->fire(_player->getPlayerX() - 100, _player->getPlayerY() + 350, _player->getShadowX(), _player->getShadowY(), PI + PI / 4, 600, 0, 1);
			_normalBullet5->setShow(true);
			_zOrder.push_back(_normalBullet5);
		}
	}

	//normalBullet6;
	_normalBullet6->update();
	if (_player->getIsRight()){
		if (_player->getIsFireball6()){
			_player->setIsFireball6(false);
			_normalBullet6->fire(_player->getPlayerX() + 450, _player->getPlayerY() + 300, _player->getShadowX(), _player->getShadowY(), PI + PI * 3 / 4, 600, 0, 0);
			_normalBullet6->setShow(true);
			_zOrder.push_back(_normalBullet6);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball6()){
			_player->setIsFireball6(false);
			_normalBullet6->fire(_player->getPlayerX() - 100, _player->getPlayerY() + 350, _player->getShadowX(), _player->getShadowY(), PI + PI / 4, 600, 0, 1);
			_normalBullet6->setShow(true);
			_zOrder.push_back(_normalBullet6);
		}
	}



	//manaball1
	_manaball1->update();

	if (_player->getIsRight()){
		if (_player->getIsManaball1()){
			_player->setIsManaball1(false);
			_manaball1->start(_player->getPlayerX() + 250, _player->getPlayerY() - 10, _player->getShadowX(), _player->getShadowY());
			_manaball1->setShow(true);
			_zOrder.push_back(_manaball1);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsManaball1()){
			_player->setIsManaball1(false);
			_manaball1->start(_player->getPlayerX() - 200, _player->getPlayerY() - 10, _player->getShadowX(), _player->getShadowY());
			_manaball1->setShow(true);
			_zOrder.push_back(_manaball1);
		}
	}

	//manaball2
	_manaball2->update();

	if (_player->getIsRight()){
		if (_player->getIsManaball2()){
			_player->setIsManaball2(false);
			_manaball2->start(_player->getPlayerX() + 320, _player->getPlayerY() + 150, _player->getShadowX(), _player->getShadowY());
			_manaball2->setShow(true);
			_zOrder.push_back(_manaball2);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsManaball2()){
			_player->setIsManaball2(false);
			_manaball2->start(_player->getPlayerX() - 200, _player->getPlayerY() + 150, _player->getShadowX(), _player->getShadowY());
			_manaball2->setShow(true);
			_zOrder.push_back(_manaball2);
		}
	}

	//rockPress
	_skillManager->getRockPress()->update();

	if (_player->getIsRight()){
		if (_player->getIsRockPress()){
			_player->setIsRockPress(false);
			_skillManager->getRockPress()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 300, _player->getShadowX() + 320, _player->getShadowY());
			_skillManager->getRockPress()->setShow(true);
			_zOrder.push_back(_skillManager->getRockPress());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsRockPress()){
			_player->setIsRockPress(false);
			_skillManager->getRockPress()->start(_player->getPlayerX() - 400, _player->getPlayerY() - 300, _player->getShadowX(), _player->getShadowY());
			_skillManager->getRockPress()->setShow(true);
			_zOrder.push_back(_skillManager->getRockPress());
		}
	}

	//icePrision
	_skillManager->getIcePrision()->update();

	if (_player->getIsRight()){
		if (_player->getIsIcePrision()){
			_player->setIsIcePrision(false);
			_skillManager->getIcePrision()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 100
				, _player->getShadowX() + 320, _player->getShadowY());
			_skillManager->getIcePrision()->setShow(true);
			_zOrder.push_back(_skillManager->getIcePrision());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsIcePrision()){
			_player->setIsIcePrision(false);
			_skillManager->getIcePrision()->start(_player->getPlayerX() - 400, _player->getPlayerY(), _player->getShadowX(), _player->getShadowY());
			_skillManager->getIcePrision()->setShow(true);
			_zOrder.push_back(_skillManager->getIcePrision());
		}
	}

	RECT rc1;
	if (IntersectRect(&rc1, &_player->getRcPlayer(), &_skillManager->getIcePrision()->getRcDeffence()[2])){
		if ((_player->getRcPlayer().right + _player->getRcPlayer().left) / 2 < _skillManager->getIcePrision()->getRcDeffence()[2].left){
			_skillManager->getIcePrision()->setRect(RectMake(_skillManager->getIcePrision()->getRect().left, _skillManager->getIcePrision()->getRect().top, 300, -500));
		}
	}

	for (int i = 0; i < _vMother.size(); i++){
		if (IntersectRect(&rc1, &_vMother[i]->getRcEnemy(), &_skillManager->getIcePrision()->getRcDeffence()[2])){
			if ((_vMother[i]->getRcEnemy().right + _vMother[i]->getRcEnemy().left) / 2 < _skillManager->getIcePrision()->getRcDeffence()[2].left){
				_skillManager->getIcePrision()->setRect(RectMake(_skillManager->getIcePrision()->getRect().left, _skillManager->getIcePrision()->getRect().top, 300, -500));
			}
		}
	}
	//thunderCloud
	_skillManager->getThunderCloud()->update();

	if (_player->getIsRight()){
		if (_player->getIsThunderCloud()){
			_player->setIsThunderCloud(false);
			_skillManager->getThunderCloud()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 100
				, _player->getShadowX() + 320, _player->getShadowY());
			_skillManager->getThunderCloud()->setShow(true);
			_zOrder.push_back(_skillManager->getThunderCloud());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsThunderCloud()){
			_player->setIsThunderCloud(false);
			_skillManager->getThunderCloud()->start(_player->getPlayerX() - 400, _player->getPlayerY(),
				_player->getShadowX() - 300, _player->getShadowY());
			_skillManager->getThunderCloud()->setShow(true);
			_zOrder.push_back(_skillManager->getThunderCloud());
		}
	}

	//blizzard
	_skillManager->getBlizzard()->update();

	if (_player->getIsRight()){
		if (_player->getIsBlizzard()){
			_player->setIsBlizzard(false);
			_skillManager->getBlizzard()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 100
				, _player->getShadowX() + 320, _player->getShadowY());
			_skillManager->getBlizzard()->setShow(true);
			_zOrder.push_back(_skillManager->getBlizzard());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsBlizzard()){
			_player->setIsBlizzard(false);
			_skillManager->getBlizzard()->start(_player->getPlayerX() - 400, _player->getPlayerY(),
				_player->getShadowX() - 300, _player->getShadowY());
			_skillManager->getBlizzard()->setShow(true);
			_zOrder.push_back(_skillManager->getBlizzard());
		}
	}

	//createFood
	_skillManager->getCreateFood()->update();

	if (_player->getIsRight()){
		if (_player->getIsCreateFood()){
			_player->setIsCreateFood(false);
			_skillManager->getCreateFood()->start(_player->getPlayerX() + 320, _player->getPlayerY() + 380
				, _player->getShadowX() + 320, _player->getShadowY() - 35, 0);
			_skillManager->getCreateFood()->setShow(true);
			_zOrder.push_back(_skillManager->getCreateFood());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsCreateFood()){
			_player->setIsCreateFood(false);
			_skillManager->getCreateFood()->start(_player->getPlayerX() - 170, _player->getPlayerY() + 380,
				_player->getShadowX() - 170, _player->getShadowY() - 35, 0);
			_skillManager->getCreateFood()->setShow(true);
			_zOrder.push_back(_skillManager->getCreateFood());
		}
	}

	RECT temp;
	if ((_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 > _skillManager->getCreateFood()->getRcShadow().top &&
		(_player->getRcShadow().bottom + _player->getRcShadow().top) / 2< _skillManager->getCreateFood()->getRcShadow().bottom){
		if (IntersectRect(&temp, &_player->getRcPlayer(), &_skillManager->getCreateFood()->getRcOjbect())){
			_player->setIsFoddEat(true);
			_skillManager->getCreateFood()->setStart(false);
		}
	}

	//protection
	_skillManager->getProtection()->update(_player->getPlayerX(), _player->getPlayerY());

	if (_player->getIsRight()){
		if (_player->getIsProtection()){
			_player->setIsProtection(false);
			_skillManager->getProtection()->start(_player->getPlayerX() + 320, _player->getPlayerY() + 380
				, _player->getShadowX() + 320, _player->getShadowY() - 35);
			_skillManager->getProtection()->setShow(true);
			_zOrder.push_back(_skillManager->getProtection());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsProtection()){
			_player->setIsProtection(false);
			_skillManager->getProtection()->start(_player->getPlayerX() - 170, _player->getPlayerY() + 380,
				_player->getShadowX() - 170, _player->getShadowY() - 35);
			_skillManager->getProtection()->setShow(true);
			_zOrder.push_back(_skillManager->getProtection());
		}
	}

	//gravity
	_skillManager->getGravity()->update();

	if (_player->getIsRight()){
		if (_player->getIsGravity()){
			_player->setIsGravity(false);
			_skillManager->getGravity()->start(_player->getPlayerX() + 180, _player->getPlayerY()
				, _player->getShadowX() + 260, _player->getShadowY() + 10);
			_skillManager->getGravity()->setShow(true);
			_zOrder.push_back(_skillManager->getGravity());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsGravity()){
			_player->setIsGravity(false);
			_skillManager->getGravity()->start(_player->getPlayerX() - 350, _player->getPlayerY(),
				_player->getShadowX() - 280, _player->getShadowY() + 10);
			_skillManager->getGravity()->setShow(true);
			_zOrder.push_back(_skillManager->getGravity());
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
			_skillManager->getCuss()->start(_player->getPlayerX() + 250, _player->getPlayerY() + 30
				, _player->getShadowX() + 290, _player->getShadowY() - 45, 0);
			_skillManager->getCuss()->setShow(true);
			_zOrder.push_back(_skillManager->getCuss());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsCuss()){
			_player->setIsCuss(false);
			_skillManager->getCuss()->start(_player->getPlayerX() - 170, _player->getPlayerY() + 30,
				_player->getShadowX() - 140, _player->getShadowY() - 45, 1);
			_skillManager->getCuss()->setShow(true);
			_zOrder.push_back(_skillManager->getCuss());
		}
	}

	//petrification
	_skillManager->getPetrification()->update();

	if (_player->getIsRight()){
		if (_player->getIsPtetrification()){
			_player->setIsPtetrification(false);
			_skillManager->getPetrification()->start(_player->getPlayerX() + 120, _player->getPlayerY() - 230
				, _player->getShadowX() + 290, _player->getShadowY() - 45);
			_skillManager->getPetrification()->setShow(true);
			_zOrder.push_back(_skillManager->getPetrification());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsPtetrification()){
			_player->setIsPtetrification(false);
			_skillManager->getPetrification()->start(_player->getPlayerX() - 120, _player->getPlayerY() - 230,
				_player->getShadowX() - 140, _player->getShadowY() - 45);
			_skillManager->getPetrification()->setShow(true);
			_zOrder.push_back(_skillManager->getPetrification());
		}
	}

	//안쓰는거 꺼주기
	for (int i = 0; i < 8; i++){
		if (!_normalBullet1[i]->getStart()){ _normalBullet1[i]->setShow(false); }
	}

	for (int i = 0; i < 5; i++){
		if (!_normalBullet2[i]->getStart()){ _normalBullet2[i]->setShow(false); }
	}

	if (!_normalBullet3->getStart()){ _normalBullet3->setShow(false); }
	if (_normalBullet4->getVBullet().size()==0){ _normalBullet4->setShow(false); }
	if (_normalBullet5->getVBullet().size() == 0){ _normalBullet5->setShow(false); }
	if (_normalBullet6->getVBullet().size() == 0){ _normalBullet6->setShow(false); }
	if (!_manaball1->getStart()){ _manaball1->setShow(false); }
	if (!_manaball2->getStart()){ _manaball2->setShow(false); }
	if (!_skillManager->getRockPress()->getStart()){ _skillManager->getRockPress()->setShow(false); }
	if (!_skillManager->getIcePrision()->getStart()){ _skillManager->getIcePrision()->setShow(false); }
	if (!_skillManager->getThunderCloud()->getStart()){ _skillManager->getThunderCloud()->setShow(false); }
	if (!_skillManager->getBlizzard()->getStart()){ _skillManager->getBlizzard()->setShow(false); }
	if (!_skillManager->getCreateFood()->getStart()){ _skillManager->getCreateFood()->setShow(false); }
	if (!_skillManager->getProtection()->getStart()){ _skillManager->getProtection()->setShow(false); }
	if (!_skillManager->getGravity()->getStart()){ _skillManager->getGravity()->setShow(false); }
	if (!_skillManager->getCuss()->getStart()){ _skillManager->getCuss()->setShow(false); }
	if (!_skillManager->getPetrification()->getStart()){ _skillManager->getPetrification()->setShow(false); }
}

void graveScene::trapSetup(trap** tempTrap, int x, int y){
	tempTrap[0] = new trap;
	tempTrap[0]->init();
	tempTrap[0]->create(x, y);
	_vTrap.push_back(tempTrap[0]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);

	tempTrap[1] = new trap;
	tempTrap[1]->init();
	tempTrap[1]->create(x+50, y-20);
	_vTrap.push_back(tempTrap[1]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);

	tempTrap[2] = new trap;
	tempTrap[2]->init();
	tempTrap[2]->create(x+50, y+20);
	_vTrap.push_back(tempTrap[2]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);

	tempTrap[3] = new trap;
	tempTrap[3]->init();
	tempTrap[3]->create(x+100, y-40);
	_vTrap.push_back(tempTrap[3]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);

	tempTrap[4] = new trap;
	tempTrap[4]->init();
	tempTrap[4]->create(x+100, y+40);
	_vTrap.push_back(tempTrap[4]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);

	tempTrap[5] = new trap;
	tempTrap[5]->init();
	tempTrap[5]->create(x+100, y);
	_vTrap.push_back(tempTrap[5]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);


	tempTrap[6] = new trap;
	tempTrap[6]->init();
	tempTrap[6]->create(x+150, y-20);
	_vTrap.push_back(tempTrap[6]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);

	tempTrap[7] = new trap;
	tempTrap[7]->init();
	tempTrap[7]->create(x+150, y+20);
	_vTrap.push_back(tempTrap[7]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);

	tempTrap[8] = new trap;
	tempTrap[8]->init();
	tempTrap[8]->create(x+200, y);
	_vTrap.push_back(tempTrap[8]);
	_zOrder.push_back(_vTrap[_vTrap.size() - 1]);
	_vMother.push_back(_vTrap[_vTrap.size() - 1]);
	_battle->linkEnemyAddress(_vTrap[_vTrap.size() - 1]);

}

void graveScene::save(){
	char str1[50];

	//캐릭터 스테이터스
	sprintf(str1, "%d", _player->getLv());
	INIDATA->addData("State", "LEVEL", str1);
	sprintf(str1, "%d", _player->getExp());
	INIDATA->addData("State", "EXP", str1);
	sprintf(str1, "%d", _player->getHpMax());
	INIDATA->addData("State", "HP", str1);
	sprintf(str1, "%d", _player->getMpMax());
	INIDATA->addData("State", "MP", str1);
	sprintf(str1, "%d", _player->getStr());
	INIDATA->addData("State", "STR", str1);
	sprintf(str1, "%d", _player->getInt());
	INIDATA->addData("State", "INT", str1);
	sprintf(str1, "%d", _player->getCon());
	INIDATA->addData("State", "CON", str1);
	sprintf(str1, "%d", _player->getMgr());
	INIDATA->addData("State", "MGR", str1);
	sprintf(str1, "%d", _player->getDex());
	INIDATA->addData("State", "DEX", str1);
	sprintf(str1, "%d", _player->getLuc());
	INIDATA->addData("State", "LUC", str1);
	sprintf(str1, "%d", INIDATA->loadDataInterger("PlayerData","State","Money") + 10000);
	INIDATA->addData("State", "Money", str1);

	//인벤토리	-- 모든 아이템이들어있음
	//num = -1이면 봉인된 아이템
	INIDATA->addData("마카로프의 스태프", "num", INIDATA->loadDataString("PlayerData", "마카로프의 스태프", "num").c_str());
	INIDATA->addData("마카로프의 스태프", "currentCon", INIDATA->loadDataString("PlayerData", "마카로프의 스태프", "currentCon").c_str()-100);
	INIDATA->addData("문라이트 스태프", "num", INIDATA->loadDataString("PlayerData", "문라이트의 스태프", "num").c_str());
	INIDATA->addData("이그니 스태프", "num", INIDATA->loadDataString("PlayerData", "이그니 스태프", "num").c_str());
	INIDATA->addData("크라운 스태프", "num", INIDATA->loadDataString("PlayerData", "크라운 스태프", "num").c_str());
	INIDATA->addData("크라운 스태프", "seal", INIDATA->loadDataString("PlayerData", "크라운 스태프", "seal").c_str());
	INIDATA->addData("붉은 망토", "num", INIDATA->loadDataString("PlayerData", "붉은 망토", "num").c_str());
	INIDATA->addData("마법사 망토", "num", INIDATA->loadDataString("PlayerData", "마법사 망토","num").c_str());
	INIDATA->addData("대마법사 망토", "num", INIDATA->loadDataString("PlayerData", "대마법사 망토", "num").c_str());
	INIDATA->addData("대마법사 망토", "seal", INIDATA->loadDataString("PlayerData", "대마법사 망토", "seal").c_str());
	INIDATA->addData("가죽 장갑", "num", INIDATA->loadDataString("PlayerData", "가죽 장갑", "num").c_str());
	INIDATA->addData("요정 장갑", "num", INIDATA->loadDataString("PlayerData", "요정 장갑", "num").c_str());
	INIDATA->addData("가죽 신발", "num", INIDATA->loadDataString("PlayerData", "가죽 신발", "num").c_str());
	INIDATA->addData("마법사 신발", "num", INIDATA->loadDataString("PlayerData", "마법사 신발", "신발").c_str());
	INIDATA->addData("에메랄드 귀거리", "num", INIDATA->loadDataString("PlayerData", "에메랄드 귀거리", "num").c_str());
	INIDATA->addData("요정눈물 귀거리", "num", INIDATA->loadDataString("PlayerData", "요정눈물 귀거리", "num").c_str());
	INIDATA->addData("A룬", "num", INIDATA->loadDataString("PlayerData", "A룬", "num").c_str());
	INIDATA->addData("B룬", "num", INIDATA->loadDataString("PlayerData", "B룬", "num").c_str());
	INIDATA->addData("C룬", "num", INIDATA->loadDataString("PlayerData", "C룬", "num").c_str());
	INIDATA->addData("D룬", "num", INIDATA->loadDataString("PlayerData", "D룬", "num").c_str());
	INIDATA->addData("E룬", "num", INIDATA->loadDataString("PlayerData", "E룬", "num").c_str());
	INIDATA->addData("F룬", "num", INIDATA->loadDataString("PlayerData", "F룬", "num").c_str());
	INIDATA->addData("요정의 물약", "num", INIDATA->loadDataString("PlayerData", "요정의 물약", "num").c_str());
	INIDATA->addData("아이스 프리즌의 서", "num", INIDATA->loadDataString("PlayerData", "아이스 프리즌의 서", "num").c_str());
	INIDATA->addData("프로텍션의 서", "num", INIDATA->loadDataString("PlayerData", "프로텍션의 서", "num").c_str());
	INIDATA->addData("그래비티의 서", "num", INIDATA->loadDataString("PlayerData", "그래비티의 서", "num").c_str());
	INIDATA->addData("썬더 클라우드의 서", "num", INIDATA->loadDataString("PlayerData", "썬더 클라우드의 서", "num").c_str());
	INIDATA->addData("록 프레스의 서", "num", INIDATA->loadDataString("PlayerData", "록 프레스의 서", "num").c_str());
	INIDATA->addData("블리자드의 서", "num", INIDATA->loadDataString("PlayerData", "블리자드의 서", "num").c_str());
	INIDATA->addData("크리에이트 푸드의 서", "num", INIDATA->loadDataString("PlayerData", "크리에이트 푸드의 서", "num").c_str());
	INIDATA->addData("커스의 서", "num", INIDATA->loadDataString("PlayerData", "커스의 서", "num").c_str());
	INIDATA->addData("페트리피케이션의 서", "num", INIDATA->loadDataString("PlayerData", "페트리피케이션의 서", "num").c_str());

	//가방	-- 던전에서 사용할 아이템을 등록
	INIDATA->addData("Bag", "bag1", INIDATA->loadDataString("PlayerData","Bag","bag1").c_str());
	INIDATA->addData("Bag", "bag2", INIDATA->loadDataString("PlayerData","Bag","bag2").c_str());
	INIDATA->addData("Bag", "bag3", INIDATA->loadDataString("PlayerData","Bag","bag3").c_str());
	INIDATA->addData("Bag", "bag4", INIDATA->loadDataString("PlayerData","Bag","bag4").c_str());
	INIDATA->addData("Bag", "bag5", INIDATA->loadDataString("PlayerData","Bag","bag5").c_str());
	INIDATA->addData("Bag", "bag6", INIDATA->loadDataString("PlayerData","Bag","bag6").c_str());
	INIDATA->addData("Bag", "bag7", INIDATA->loadDataString("PlayerData","Bag","bag7").c_str());
	INIDATA->addData("Bag", "bag8", INIDATA->loadDataString("PlayerData","Bag","bag8").c_str());

	//스킬
	sprintf(str1, "%d", _player->getSkillPoint());
	INIDATA->addData("Skill", "SKILLPOINT",str1);
	INIDATA->addData("Skill", "mental_absorb", INIDATA->loadDataString("PlayerData", "Skill", "mental_absorb").c_str());
	INIDATA->addData("Skill", "extract", INIDATA->loadDataString("PlayerData", "Skill", "extract").c_str());
	INIDATA->addData("Skill", "concentrate", INIDATA->loadDataString("PlayerData","Skill","concentrate").c_str());
	INIDATA->addData("Skill", "magic_point_up", INIDATA->loadDataString("PlayerData","Skill","magic_point_up").c_str());
	INIDATA->addData("Skill", "ice_prision", INIDATA->loadDataString("PlayerData", "Skill", "ice_prision").c_str());
	INIDATA->addData("Skill", "protection", INIDATA->loadDataString("PlayerData", "Skill", "protection").c_str());
	INIDATA->addData("Skill", "gravity", INIDATA->loadDataString("PlayerData", "Skill", "gravity").c_str());
	INIDATA->addData("Skill", "thunder_cloud", INIDATA->loadDataString("PlayerData", "Skill", "thunder_cloud").c_str());
	INIDATA->addData("Skill", "rock_press", INIDATA->loadDataString("PlayerData", "Skill", "rock_press").c_str());
	INIDATA->addData("Skill", "blizzard", INIDATA->loadDataString("PlayerData", "Skill", "blizzard").c_str());
	INIDATA->addData("Skill", "animate_skelton", INIDATA->loadDataString("PlayerData", "Skill", "animate_skelton").c_str());
	INIDATA->addData("Skill", "ravitation", INIDATA->loadDataString("PlayerData", "Skill", "ravitation").c_str());
	INIDATA->addData("Skill", "create_food", INIDATA->loadDataString("PlayerData", "Skill", "create_food").c_str());
	INIDATA->addData("Skill", "curse", INIDATA->loadDataString("PlayerData", "Skill", "curse").c_str());
	INIDATA->addData("Skill", "petrification", INIDATA->loadDataString("PlayerData", "Skill", "petrification").c_str());
	INIDATA->addData("Skill", "sliding", INIDATA->loadDataString("PlayerData", "Skill", "sliding").c_str());
	INIDATA->addData("Skill", "gold_healing", INIDATA->loadDataString("PlayerData","Skill","gold_healing").c_str());
	INIDATA->addData("Skill", "gold_scoring", INIDATA->loadDataString("PlayerData","Skill","gold_scoring").c_str());
	INIDATA->addData("Skill", "hit_point_up", INIDATA->loadDataString("PlayerData","Skill","hit_point_up").c_str());
	INIDATA->addData("Skill", "food_psytology", INIDATA->loadDataString("PlayerData", "Skill", "food_psytology").c_str());
	INIDATA->addData("Skill", "maintenance", INIDATA->loadDataString("PlayerData", "Skill", "maintenance").c_str());
	INIDATA->addData("Skill", "item_user", INIDATA->loadDataString("PlayerData", "Skill", "item_user").c_str());
	INIDATA->addData("Skill", "evade", INIDATA->loadDataString("PlayerData", "Skill", "evade").c_str());
	INIDATA->addData("Skill", "extra_pocket", INIDATA->loadDataString("PlayerData", "Skill", "extra_pocket").c_str());

	//좌표
	sprintf(str1, "%d", 100);
	INIDATA->addData("Position", "X", str1);
	sprintf(str1, "%d", 300);
	INIDATA->addData("Position", "Y", str1);
	sprintf(str1, "%d", 115);
	INIDATA->addData("Position", "그림자X", str1);
	sprintf(str1, "%d", 740);
	INIDATA->addData("Position", "그림자Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "절대좌표X", str1);
	sprintf(str1, "%d", -600);
	INIDATA->addData("Position", "절대좌표Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "성X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "성Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을1X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을1Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을2X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을2Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을3X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을3Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을4X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을4Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을5X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을5Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "루카인X", str1);

	//탈리즈만
	sprintf(str1, "%d", _talizman[0]);
	INIDATA->addData("Talizman", "red", str1);
	sprintf(str1, "%d", _talizman[1]);
	INIDATA->addData("Talizman", "orange", str1);
	sprintf(str1, "%d", _talizman[2]);
	INIDATA->addData("Talizman", "yellow", str1);
	sprintf(str1, "%d", _talizman[3]);
	INIDATA->addData("Talizman", "green", str1);
	sprintf(str1, "%d", _talizman[4]);
	INIDATA->addData("Talizman", "skyblue", str1);
	sprintf(str1, "%d", _talizman[5]);
	INIDATA->addData("Talizman", "blue", str1);
	sprintf(str1, "%d", _talizman[6]);
	INIDATA->addData("Talizman", "pupple", str1);
	sprintf(str1, "%d", _talizman[7]);
	INIDATA->addData("Talizman", "white", str1);
	sprintf(str1, "%d", _talizman[8]);
	INIDATA->addData("Talizman", "black", str1);
	INIDATA->iniSave("PlayerData");
}
