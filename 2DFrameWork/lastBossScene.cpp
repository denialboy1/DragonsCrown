#include "stdafx.h"
#include "lastBossScene.h"


lastBossScene::lastBossScene()
{
}


lastBossScene::~lastBossScene()
{
}


HRESULT lastBossScene::init(){
	//°´Ã¼ »ý¼º
	_dragon = new ancientDragon;
	_dragon->init();
	_fireRain = new fireRain;
	_fireRain->init();
	_fireWorld = new fireWorld;
	_fireWorld->init();
	_fireFloor = new fireFloor;
	_fireFloor->init();

	//º¸½º Ã¼·Â
	_hpBar = new progressBar;
	_hpBar->init("ÀÌ¹ÌÁö/°í´ëµå·¡°ï/dragonHPTop", "ÀÌ¹ÌÁö/°í´ëµå·¡°ï/dragonHPBottom", 800, 800, 1340, 58);


	SOUNDMANAGER->addSound("¸¶Áö¸·º¸½º", "»ç¿îµå/¸¶Áö¸·º¸½º.mp3", true, true);
	SOUNDMANAGER->play("¸¶Áö¸·º¸½º", 0.1f);
	//¹è°æ
	//IMAGEMANAGER->addImage("°í´ëµå·¡°ï¹è°æ", "ÀÌ¹ÌÁö/°í´ëµå·¡°ï/°í´ëµå·¡°ï¹è°æ.bmp", 1600, 900, false, RGB(255, 0, 255));
	_offX = 0;

	//±¸Á¶¹°
	//IMAGEMANAGER->addImage("ÁöÇü1", "ÀÌ¹ÌÁö/°í´ëµå·¡°ï/ÁöÇü1.bmp", 1600, 900, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("ÁöÇü1ÇÈ¼¿", "ÀÌ¹ÌÁö/°í´ëµå·¡°ï/ÁöÇü1ÇÈ¼¿.bmp", 1600, 900, false, RGB(255, 0, 255));
	
	//IMAGEMANAGER->addAlphaFrameImage("º¸½ºÁ×À½", "ÀÌ¹ÌÁö/°í´ëµå·¡°ï/º¸½ºÁ×À½.bmp", 6400, 900, 4, 1, false, RGB(0, 0, 0));
	//IMAGEMANAGER->addImage("°í´ëµå·¡°ï", "ÀÌ¹ÌÁö/°í´ëµå·¡°ï/°í´ëµå·¡°ï.bmp", 508, 84, true, RGB(255, 0, 255));
	///////////////////////////////////////ÇÃ·¹ÀÌ¾î//////////////////////////////
	_player = new player;
	_player->init();
	_player->setPlayerX(0);
	_player->setPlayerY(400);
	_player->setShadowX(0);
	_player->setShadowY(400);

	_zOrder.clear();

	//½ºÅ³
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

	//Ã¥ ½ºÅ³
	_zOrder.push_back(_skillManager->getRockPress());
	_zOrder.push_back(_skillManager->getIcePrision());
	_zOrder.push_back(_skillManager->getThunderCloud());
	_zOrder.push_back(_skillManager->getBlizzard());
	_zOrder.push_back(_skillManager->getCreateFood());
	_zOrder.push_back(_skillManager->getProtection());
	_zOrder.push_back(_skillManager->getGravity());
	_zOrder.push_back(_skillManager->getCuss());
	_zOrder.push_back(_skillManager->getPetrification());


	//¾ÆÀÌ½ºÇÁ¸®Áð°ú Ãæµ¹
	_objectCollision = new objectCollision;
	_objectCollision->init(_player, _skillManager->getIcePrision());
	////////////////////////////////////////////////////////////////////////////////

	_battle = new battle;
	_battle->init();
	_battle->linkEnemyAddress(_dragon);
	_battle->linkFireFloorAddress(_fireFloor);
	_battle->linkFireWorldAddress(_fireWorld);
	_battle->linkPlayerAddress(_player);
	_battle->linkManaballAddress(_manaball1);
	_battle->linkNormalBullet1Address(_normalBullet1[0]);
	_battle->linkNormalBullet2Address(_normalBullet3);
	_battle->linkNormalBullet3Address(_normalBullet4);
	_battle->linkNormalBullet4Address(_normalBullet5);
	_battle->linkNormalBullet5Address(_normalBullet6);
	_battle->linkSkillManagerAddress(_skillManager);

	//º¸½ºÁ×À½
	_deadFrameX = 0;
	_deadEffectEnd = false;
	_deadEffectTimer = 0;
	_deadEffectAlpha = 255;

	
	
	
	return S_OK;
}
void lastBossScene::update(){
	

	//¹è°æ
	_offX++;
	if (_offX > 1600) _offX = 0;

	_dragon->update();

	fireRainAttack();
	fireWorldAttack();
	fireFloorAttack();


	////////////////ÇÃ·¹ÀÌ¾î/////////////////

	//Ä³¸¯ÅÍ°¡ È­¸é¹ÛÀ¸·Î ¸ø³ª°¡°Ô ÇÏ±â
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


	//¾ÆÀÌ½ºÇÁ¸®Áð°ú Ãæµ¹
	_objectCollision->collision();
	///////////////////////////////////////


	//zOrder¼ø¼­ Á¤ÇÏ±â
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

	
	////////////////////////////ÀüÅõ/////////////////////////////
	//ÇÃ·¹ÀÌ¾î
	_battle->linkManaballAddress(_manaball1);
	_battle->manaball();
	_battle->linkManaballAddress(_manaball2);
	_battle->manaball();
	_battle->linkManaballAddress(_manaball1);
	_battle->floorVSmanaball();
	_battle->linkManaballAddress(_manaball2);
	_battle->floorVSmanaball();
	for (int i = 0; i < 8; i++){
		_battle->linkNormalBullet1Address(_normalBullet1[i]);
		_battle->normalBullet1();
	}

	for (int i = 0; i <5; i++){
		_battle->linkNormalBullet1Address(_normalBullet2[i]);
		_battle->normalBullet1();
	}
	for (int i = 0; i < 8; i++){
		_battle->linkNormalBullet1Address(_normalBullet1[i]);
		_battle->floorVSnormalBullet1();
	}

	for (int i = 0; i <5; i++){
		_battle->linkNormalBullet1Address(_normalBullet2[i]);
		_battle->floorVSnormalBullet1();
	}
	_battle->playerAttack();
	//°í´ëµå·¡°ï
	for (int i = 0; i < _vFireRain.size(); i++){
		_battle->linkFireRainAddress(&(_vFireRain[i]));
		_battle->fireRain();
	}
	_battle->dragonSkillAttack();
	_battle->playerVSDragonSkillAttack();
	_battle->update();

	//ºÒ²É
	//////////////////////////////////////////////////////////////
	KEYANIMANAGER->update();
	//EFFECTMANAGER->update();

	_hpBar->setGauge(_dragon->getHp(), _dragon->getMaxHp());

	////////////////////////¿£µù///////////////////////////////
	if (_dragon->getHp() <= 0){
		_deadFrameX+=0.1;
		_deadEffectTimer++;
		_deadEffectAlpha += 100;
		if (_deadFrameX > 3){
			_deadFrameX = 0;
			if (_deadEffectTimer>DEAD_EFFECT_SHOW)
			_deadEffectEnd = true;
		}
		//SOUNDMANAGER->allRemove();
		//SCENEMANAGER->changeScene("¿£µù¾À");
	}
}
void lastBossScene::render(){
	RECT _rc=RectMake(0,0,1600,900);
	IMAGEMANAGER->findImage("°í´ëµå·¡°ï¹è°æ")->loopRender(getMemDC(), &_rc, _offX, 0);
	
	_dragon->render();
	IMAGEMANAGER->findImage("ÁöÇü1")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findImage("ÁöÇü1ÇÈ¼¿")->render(getPixelMemDC(), 0,0);
	for (int i = 0; i < _zOrder.size(); i++){
		_zOrder[i]->render();
	}

	//ÇÃ·¹ÀÌ¾î
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

	_battle->render();
	_hpBar->render();
	IMAGEMANAGER->findImage("°í´ëµå·¡°ï")->render(getMemDC(), 100, 730);
	
	if (_dragon->getHp() < 0){
		if (!_deadEffectEnd)
		IMAGEMANAGER->findAlphaImage("º¸½ºÁ×À½")->alphaFrameRender(getMemDC(), 0, 0, _deadFrameX, 0, _deadEffectAlpha);
	}

	_ui->render();

	

	
	//////////


	//HFONT oldFont;
	//HFONT font1;
	//SetBkMode(getMemDC(), TRANSPARENT);
	//
	//char str[100];
	//¼¼ÀÌºê1 µ¥ÀÌÅÍ°¡ ÀÖÀ¸¸é

	//¾øÀ¸¸é
	//font1 = CreateFont(50, 30, 0, 0, 300, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("Pyunji R"));
	//oldFont = (HFONT)SelectObject(getMemDC(), font1);
	//SetTextColor(getMemDC(), RGB(0, 0, 0));
	//sprintf(str, "1234567890");
	//TextOut(getMemDC(), 403, 188, str, strlen(str));
	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	//sprintf(str, "1234567890");
	//TextOut(getMemDC(), 400, 185, str, strlen(str));
	//SelectObject(getMemDC(), oldFont);
	//DeleteObject(font1);
}
void lastBossScene::release(){}

void lastBossScene::fireRainAttack(){
	if (_dragon->getIsFireRain()){
		fireRain temp;
		temp.start(600, 0, 600, 800, 30);
		_vFireRain.push_back(temp);

		temp.start(400, 0, 400, 840, 40);
		_vFireRain.push_back(temp);

		temp.start(800, 0, 800, 860, 50);
		_vFireRain.push_back(temp);

		temp.start(1000, 0, 1000, 820, 60);
		_vFireRain.push_back(temp);

		temp.start(200, 0, 200, 800, 70);
		_vFireRain.push_back(temp);

		temp.start(1200, 0, 1200, 820, 60);
		_vFireRain.push_back(temp);

		temp.start(1400, 0, 1400, 840, 40);
		_vFireRain.push_back(temp);

		temp.start(0, 0, 0, 840, 50);
		_vFireRain.push_back(temp);
		for (int i = 0; i < _vFireRain.size(); i++){
			_zOrder.push_back(&_vFireRain[i]);
		}

		_dragon->setIsFireRain(false);
	}

	for (int i = 0; i < _vFireRain.size(); i++){
		_vFireRain[i].update();
	}

	//for (vector<gameNode*>::iterator _viZOrder = _zOrder.begin(); _viZOrder != _zOrder.end();){
	//	if (!static_cast<fireRain*>((*_viZOrder))->getStart()){
	//		_zOrder.erase(_viZOrder);
	//		break;
	//	}
	//	else{
	//		_viZOrder++;
	//	}
	//}
	//
	for (_viFireRain = _vFireRain.begin(); _viFireRain != _vFireRain.end();){
		if (!(*_viFireRain).getStart()){
			_vFireRain.erase(_viFireRain);
			break;
		}
		else{
			_viFireRain++;
		}
	}
}

void lastBossScene::fireWorldAttack(){
	
	if (_dragon->getIsFireWorld()){
		if (!_fireWorld->getStart()){
			_zOrder.push_back(_fireWorld);
			_fireWorld->start(0, 0, 0, 2000, 230);
		}
		
	}
	_fireWorld->update();
	if (!_fireWorld->getStart()) _dragon->setIsFireWorld(false);
}

void lastBossScene::fireFloorAttack(){
	if (_dragon->getIsFireFloor()){
		if (!_fireFloor->getStart()){
			_zOrder.push_back(_fireFloor);
			int rand = RND->getFromIntTo(100, 1500);
			int rand2 = RND->getFromIntTo(720, 850);
			//_fireFloor->start(rand, 0, rand, rand2);
			_fireFloor->start(100, 0, 100, 760);
		}
	}
	_fireFloor->update();
	if (!_fireFloor->getStart())_dragon->setIsFireFloor(false);
}


void lastBossScene::skill(){
	//½ºÅ³ 
	for (int i = 0; i < 8; i++){
		_normalBullet1[i]->update();
	}

	if (_player->getIsRight()){
		if (_player->getIsFireball1()){
			_player->setIsFireball1(false);
			_normalBullet1[0]->start(_player->getPlayerX() + 100, _player->getPlayerY());
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[0]->getFrameX() == 2){
			_normalBullet1[1]->start(_normalBullet1[0]->getX() - 70, _normalBullet1[0]->getY() - 20);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[1]->getFrameX() == 2){
			_normalBullet1[2]->start(_normalBullet1[1]->getX() - 70, _normalBullet1[1]->getY() - 20);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[2]->getFrameX() == 2){
			_normalBullet1[3]->start(_normalBullet1[2]->getX() - 70, _normalBullet1[2]->getY() - 100);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[3]->getFrameX() == 2){
			_normalBullet1[4]->start(_normalBullet1[3]->getX() - 70, _normalBullet1[3]->getY() - 100);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[4]->getFrameX() == 2){
			_normalBullet1[5]->start(_normalBullet1[4]->getX() + 70, _normalBullet1[4]->getY() - 100);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
			//_normalBullet1[5]->setRect(RectMake(_normalBullet1[5]->getRc().left + 300,
			//	_normalBullet1[5]->getRc().top,
			//	_normalBullet1[5]->getRc().right,
			//	_normalBullet1[5]->getRc().bottom));
		}

		if (_normalBullet1[5]->getFrameX() == 2){
			_normalBullet1[6]->start(_normalBullet1[5]->getX() + 70, _normalBullet1[5]->getY() - 100);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
			//_normalBullet1[6]->setRect(RectMake(_normalBullet1[6]->getRc().left + 300,
			//	_normalBullet1[6]->getRc().top,
			//	_normalBullet1[6]->getRc().right,
			//	_normalBullet1[6]->getRc().bottom));
		}

		if (_normalBullet1[6]->getFrameX() == 2){
			_normalBullet1[7]->start(_normalBullet1[6]->getX() + 70, _normalBullet1[6]->getY() - 20);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball1()){
			_player->setIsFireball1(false);
			_normalBullet1[0]->start(_player->getPlayerX() - 160, _player->getPlayerY() - 20);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[0]->getFrameX() == 2){
			_normalBullet1[1]->start(_normalBullet1[0]->getX() + 70, _normalBullet1[0]->getY() - 20);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[1]->getFrameX() == 2){
			_normalBullet1[2]->start(_normalBullet1[1]->getX() + 70, _normalBullet1[1]->getY() - 20);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[2]->getFrameX() == 2){
			_normalBullet1[3]->start(_normalBullet1[2]->getX() + 70, _normalBullet1[2]->getY() - 100);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[3]->getFrameX() == 2){
			_normalBullet1[4]->start(_normalBullet1[3]->getX() + 70, _normalBullet1[3]->getY() - 100);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[4]->getFrameX() == 2){
			_normalBullet1[5]->start(_normalBullet1[4]->getX() - 70, _normalBullet1[4]->getY() - 100);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
		}

		if (_normalBullet1[5]->getFrameX() == 2){
			_normalBullet1[6]->start(_normalBullet1[5]->getX() - 70, _normalBullet1[5]->getY() - 100);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
			//_normalBullet1[6]->setRect(RectMake(_normalBullet1[6]->getRc().left + 300,
			//	_normalBullet1[6]->getRc().top,
			//	_normalBullet1[6]->getRc().right,
			//	_normalBullet1[6]->getRc().bottom));
		}

		if (_normalBullet1[6]->getFrameX() == 2){
			_normalBullet1[7]->start(_normalBullet1[6]->getX() - 70, _normalBullet1[6]->getY() - 20);
			SOUNDMANAGER->stop("Æø¹ß");
			SOUNDMANAGER->play("Æø¹ß", 0.15F);
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
		}

		if (_normalBullet2[0]->getFrameX() == 2){
			_normalBullet2[1]->start(_normalBullet2[0]->getX() + 200, _normalBullet2[0]->getY() - 60);
		}

		if (_normalBullet2[1]->getFrameX() == 2){
			_normalBullet2[2]->start(_normalBullet2[1]->getX() + 200, _normalBullet2[1]->getY() - 60);
		}

		if (_normalBullet2[2]->getFrameX() == 2){
			_normalBullet2[3]->start(_normalBullet2[2]->getX() + 200, _normalBullet2[2]->getY() - 60);
		}

		if (_normalBullet2[3]->getFrameX() == 2){
			_normalBullet2[4]->start(_normalBullet2[3]->getX() + 200, _normalBullet2[3]->getY() - 60);
		}

	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball2()){
			_player->setIsFireball2(false);
			_normalBullet2[0]->start(_player->getPlayerX() - 200, _player->getPlayerY());
		}

		if (_normalBullet2[0]->getFrameX() == 2){
			_normalBullet2[1]->start(_normalBullet2[0]->getX() - 200, _normalBullet2[0]->getY() - 60);
		}

		if (_normalBullet2[1]->getFrameX() == 2){
			_normalBullet2[2]->start(_normalBullet2[1]->getX() - 200, _normalBullet2[1]->getY() - 60);
		}

		if (_normalBullet2[2]->getFrameX() == 2){
			_normalBullet2[3]->start(_normalBullet2[2]->getX() - 200, _normalBullet2[2]->getY() - 60);
		}

		if (_normalBullet2[3]->getFrameX() == 2){
			_normalBullet2[4]->start(_normalBullet2[3]->getX() - 200, _normalBullet2[3]->getY() - 60);
		}
	}


	//normalBullet3;
	_normalBullet3->update();

	if (_player->getIsRight()){
		if (_player->getIsFireball3()){
			_player->setIsFireball3(false);
			_normalBullet3->start(_player->getPlayerX() + 100, _player->getPlayerY() - 10);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsFireball3()){
			_player->setIsFireball3(false);
			_normalBullet3->start(_player->getPlayerX() - 300, _player->getPlayerY() - 10);

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
			_normalBullet5->fire(_player->getPlayerX() - 100, _player->getPlayerY() + 350, _player->getShadowX(), _player->getShadowY(), PI + PI / 4, 600, 0, 1);
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
			_manaball1->start(_player->getPlayerX() + 250, _player->getPlayerY() - 10, _player->getShadowX(), _player->getShadowY());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsManaball1()){
			_player->setIsManaball1(false);
			_manaball1->start(_player->getPlayerX() - 200, _player->getPlayerY() - 10, _player->getShadowX(), _player->getShadowY());
		}
	}

	//manaball2
	_manaball2->update();

	if (_player->getIsRight()){
		if (_player->getIsManaball2()){
			_player->setIsManaball2(false);
			_manaball2->start(_player->getPlayerX() + 320, _player->getPlayerY() + 150, _player->getShadowX(), _player->getShadowY());
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
			_skillManager->getRockPress()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 300, _player->getShadowX() + 320, _player->getShadowY());
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
			_skillManager->getIcePrision()->start(_player->getPlayerX() + 320, _player->getPlayerY() - 100
				, _player->getShadowX() + 320, _player->getShadowY());
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsIcePrision()){
			_player->setIsIcePrision(false);
			_skillManager->getIcePrision()->start(_player->getPlayerX() - 400, _player->getPlayerY(), _player->getShadowX(), _player->getShadowY());
		}
	}

	if ((_player->getRcPlayer().right + _player->getRcPlayer().left) / 2 < _skillManager->getIcePrision()->getRcDeffence()[2].left){
		_skillManager->getIcePrision()->setRect(RectMake(_skillManager->getIcePrision()->getRect().left, _skillManager->getIcePrision()->getRect().top, 300, -500));
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
				_player->getShadowX() - 300, _player->getShadowY());
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
			_skillManager->getCreateFood()->start(_player->getPlayerX() + 320, _player->getPlayerY() + 380
				, _player->getShadowX() + 320, _player->getShadowY() - 35, 0);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsCreateFood()){
			_player->setIsCreateFood(false);
			_skillManager->getCreateFood()->start(_player->getPlayerX() - 170, _player->getPlayerY() + 380,
				_player->getShadowX() - 170, _player->getShadowY() - 35, 0);
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
				, _player->getShadowX() + 260, _player->getShadowY() + 10);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsGravity()){
			_player->setIsGravity(false);
			_skillManager->getGravity()->start(_player->getPlayerX() - 350, _player->getPlayerY(),
				_player->getShadowX() - 280, _player->getShadowY() + 10);
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
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsCuss()){
			_player->setIsCuss(false);
			_skillManager->getCuss()->start(_player->getPlayerX() - 170, _player->getPlayerY() + 30,
				_player->getShadowX() - 140, _player->getShadowY() - 45, 1);
		}
	}

	//petrification
	_skillManager->getPetrification()->update();

	if (_player->getIsRight()){
		if (_player->getIsPtetrification()){
			_player->setIsPtetrification(false);
			_skillManager->getPetrification()->start(_player->getPlayerX() + 120, _player->getPlayerY() - 230
				, _player->getShadowX() + 290, _player->getShadowY() - 45);
		}
	}
	else if (_player->getIsLeft()){
		if (_player->getIsPtetrification()){
			_player->setIsPtetrification(false);
			_skillManager->getPetrification()->start(_player->getPlayerX() - 120, _player->getPlayerY() - 230,
				_player->getShadowX() - 140, _player->getShadowY() - 45);
		}
	}
}