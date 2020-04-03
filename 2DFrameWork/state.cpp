#include "stdafx.h"
#include "state.h"


state::state()
{
}


state::~state()
{
}

HRESULT state::init(){
	IMAGEMANAGER->addAlphaImage("stateTop", "이미지/menu/스테이터스/스테이터스_top.bmp", 1600, 146, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("stateBottom", "이미지/menu/스테이터스/스테이터스_bottom.bmp", 1600, 200, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("양피지1", "이미지/menu/스테이터스/스테이터스_양피지1.bmp", 840, 570, true, RGB(255, 0, 255));


	_expBar = new progressBar;
	_expBar->init("이미지/menu/스테이터스/expBarFull", "이미지/menu/스테이터스/expBar", WINSIZEX/2, 700, 1600, 200);
	_expBar->setGauge(50, 100);

	_player = new player;
	_player->init();
	return S_OK;
}
void state::render(){
	IMAGEMANAGER->findAlphaImage("stateTop")->render(getMemDC(), 0, 0);
	IMAGEMANAGER->findAlphaImage("stateBottom")->alphaRender(getMemDC(), 0, 700,200);
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
	TextOut(getMemDC(), 400, 280, str,strlen(str));
	sprintf(str, "%d", _player->getExp());
	TextOut(getMemDC(), 400, 320, str,strlen(str));
	sprintf(str, "%d", _player->getLevelExp()[_player->getLv()]);
	TextOut(getMemDC(), 400, 360, str,strlen(str));
	sprintf(str, "%d", _player->getHp());
	TextOut(getMemDC(), 330, 420, str,strlen(str));
	sprintf(str, "%d", _player->getStr());
	TextOut(getMemDC(), 330, 460, str,strlen(str));
	sprintf(str, "%d", _player->getCon());
	TextOut(getMemDC(), 330, 500, str,strlen(str));
	sprintf(str, "%d", _player->getDex());
	TextOut(getMemDC(), 330, 540, str,strlen(str));
	sprintf(str, "%d", _player->getInt());
	TextOut(getMemDC(), 630, 460, str,strlen(str));
	sprintf(str, "%d", _player->getMgr());
	TextOut(getMemDC(), 630, 500, str,strlen(str));
	sprintf(str, "%d", _player->getLuc());
	TextOut(getMemDC(), 630, 540, str,strlen(str));
	sprintf(str, "%d", _player->getSkillPoint());
	TextOut(getMemDC(), 500, 600, str,strlen(str));;
	SelectObject(getMemDC(), oldFont);
	DeleteObject(hFont);
}
void state::update(){
	//경험치
	_expBar->update();
	//_expBar->setGauge(INIDATA->loadDataInterger("PlayerData", "State", "EXP"), 300);
}
void state::release(){}
