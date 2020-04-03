#include "stdafx.h"
#include "UI.h"
#include "player.h"

UI::UI()
{
}


UI::~UI()
{
}

HRESULT UI::init(){
	IMAGEMANAGER->addImage("face", "이미지/소서리스/face.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("apple", "이미지/음식/apple.bmp", 100, 100, true, RGB(255, 0, 255));

	_hpBar = new progressBar;
	_hpBar->init("이미지/소서리스/hpBottom", "이미지/소서리스/hpTop", 250, 50, 200, 30);
	_hpBar->setGauge(_player->getHp(), _player->getHpMax());

	_rc = { 0, 0, 10, WINSIZEY + 500 };

	return S_OK;
}
void UI::update(){
	int hp = _player->getHp();
	if (hp > _player->getHpMax()) hp = _player->getHpMax();
	_hpBar->setGauge(hp, _player->getHpMax());
}
void UI::render(){
	_hpBar->render();
	IMAGEMANAGER->findImage("face")->render(getMemDC(), 50, 30);

	SetBkMode(getMemDC(), TRANSPARENT);
	HFONT hFont, oldFont;
	char str3[100];
	hFont = CreateFont(25, 13, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont = (HFONT)SelectObject(getMemDC(), hFont);
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	sprintf(str3, "%d / %d", _player->getHp(), _player->getHpMax());
	TextOut(getMemDC(), 144, 83, str3, strlen(str3));
	SelectObject(getMemDC(), oldFont);
	DeleteObject(hFont);
}
void UI::release(){}
