#include "stdafx.h"
#include "menu.h"


menu::menu()
{
}


menu::~menu()
{
}

HRESULT menu::init(){
	IMAGEMANAGER->addAlphaImage("state_bag_choice1", "이미지/menu/state_bag_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("state_bag_choice2", "이미지/menu/state_bag_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("state_inven_choice1", "이미지/menu/state_inven_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("state_inven_choice2", "이미지/menu/state_inven_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("state_skill_choice1", "이미지/menu/state_skill_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("state_skill_choice2", "이미지/menu/state_skill_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("state_state_choice1", "이미지/menu/state_state_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("state_state_choice2", "이미지/menu/state_state_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman_empty", "이미지/menu/talizman_empty.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman1", "이미지/menu/talizman1.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman2", "이미지/menu/talizman2.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman3", "이미지/menu/talizman3.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman4", "이미지/menu/talizman4.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman5", "이미지/menu/talizman5.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman6", "이미지/menu/talizman6.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman7", "이미지/menu/talizman7.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman8", "이미지/menu/talizman8.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("talizman9", "이미지/menu/talizman9.bmp", 45, 55, true, RGB(255, 0, 255));
	IMAGEMANAGER->addPngImage("bg_sorceress", L"이미지/menu/bg_sorceressout.png", 900, 900);
	IMAGEMANAGER->addAlphaImage("state_money", "이미지/menu/state_money.bmp", 581, 84, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("bgGray", "이미지/menu/bgGray.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("menu_talizman", "이미지/menu/menu_talizman.bmp", 581, 100, true, RGB(255, 0, 255));

	_bag = new bag;
	_inven = new inven;
	_state = new state;
	_skillInfo = new skillInfo;

	_bag->addressLinkInven(_inven);
	_inven->init();
	_bag->init();
	_state->init();
	_skillInfo->init();
	


	_window = MENU;
	_windowChoice = 0;

	return S_OK;
}
void menu::update(){
	switch (_window){
	case MENU:
		keyInput();
		break;
	case INVEN:
		_inven->update();
		if (_inven->getItemSelect()){
			if (!_inven->getVInven()[_inven->getItemIndex()].seal){
				if (KEYMANAGER->isOnceKeyDown('A')){
					_window = BAG;
					_inven->setItemSelect(false);
					_bag->equipItem();
					SOUNDMANAGER->play("장착", 0.3f);
				}
			}
		}
		break;
	case BAG:
		_bag->update();
		if (KEYMANAGER->isOnceKeyDown('A')){
			_window = INVEN;
			_inven->setItemSelect(true);
		}
		break;
	case STATE:
		_state->update();
		break;
	case SKILL:
		_skillInfo->update();
		break;
	}
	
	if (KEYMANAGER->isOnceKeyDown('X')){
		if (_window == BAG){ 
			_bag->bagSave(); 
		}
		_window = MENU;
	}

	
	

}
void menu::render(){
	IMAGEMANAGER->findAlphaImage("bgGray")->alphaRender(getMemDC(), 0, 0, 200);
	IMAGEMANAGER->findPngImage("bg_sorceress")->render(getMemDC(), 730, 150);


	HFONT oldFont;
	HFONT font1;
	SetBkMode(getMemDC(), TRANSPARENT);
	char str[100];
	switch (_window){
	case MENU:
		
		IMAGEMANAGER->findAlphaImage("state_money")->render(getMemDC(), 60, 700);

		font1 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font1);
		SetTextColor(getMemDC(), RGB(255,255,0));
		sprintf(str, "%d", INIDATA->loadDataInterger("PlayerData","State","Money"));
		TextOut(getMemDC(), 250, 720, str, strlen(str));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font1);


		IMAGEMANAGER->findImage("menu_talizman")->render(getMemDC(), 60, 550);

		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 130, 580);
		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 180, 580);
		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 230, 580);
		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 280, 580);
		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 330, 580);
		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 380, 580);
		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 430, 580);
		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 480, 580);
		IMAGEMANAGER->findImage("talizman_empty")->render(getMemDC(), 530, 580);

		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "red") != 0)
		IMAGEMANAGER->findImage("talizman6")->render(getMemDC(), 130, 580);
		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "orange") != 0)
		IMAGEMANAGER->findImage("talizman8")->render(getMemDC(), 180, 580);
		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "yellow") != 0)
		IMAGEMANAGER->findImage("talizman2")->render(getMemDC(), 230, 580);
		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "green") != 0)
		IMAGEMANAGER->findImage("talizman9")->render(getMemDC(), 280, 580);
		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "skyblue") != 0)
		IMAGEMANAGER->findImage("talizman3")->render(getMemDC(), 330, 580);
		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "blue") != 0)
		IMAGEMANAGER->findImage("talizman4")->render(getMemDC(), 380, 580);
		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "pupple") != 0)
		IMAGEMANAGER->findImage("talizman5")->render(getMemDC(), 430, 580);
		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "white") != 0)
		IMAGEMANAGER->findImage("talizman1")->render(getMemDC(), 480, 580);
		if (INIDATA->loadDataInterger("PlayerData", "Talizman", "black") != 0)
		IMAGEMANAGER->findImage("talizman7")->render(getMemDC(), 530, 580);


		switch (_windowChoice){
		case 0:
			IMAGEMANAGER->findAlphaImage("state_bag_choice2")->alphaRender(getMemDC(), 100, 100, 255);
			IMAGEMANAGER->findAlphaImage("state_inven_choice1")->alphaRender(getMemDC(), 100, 200, 255);
			IMAGEMANAGER->findAlphaImage("state_skill_choice1")->alphaRender(getMemDC(), 100, 300, 255);
			IMAGEMANAGER->findAlphaImage("state_state_choice1")->alphaRender(getMemDC(), 100, 400, 255);
			break;
		case 1:
			IMAGEMANAGER->findAlphaImage("state_bag_choice1")->alphaRender(getMemDC(), 100, 100, 255);
			IMAGEMANAGER->findAlphaImage("state_inven_choice2")->alphaRender(getMemDC(), 100, 200, 255);
			IMAGEMANAGER->findAlphaImage("state_skill_choice1")->alphaRender(getMemDC(), 100, 300, 255);
			IMAGEMANAGER->findAlphaImage("state_state_choice1")->alphaRender(getMemDC(), 100, 400, 255);
			break;
		case 2:
			IMAGEMANAGER->findAlphaImage("state_bag_choice1")->alphaRender(getMemDC(), 100, 100, 255);
			IMAGEMANAGER->findAlphaImage("state_inven_choice1")->alphaRender(getMemDC(), 100, 200, 255);
			IMAGEMANAGER->findAlphaImage("state_skill_choice2")->alphaRender(getMemDC(), 100, 300, 255);
			IMAGEMANAGER->findAlphaImage("state_state_choice1")->alphaRender(getMemDC(), 100, 400, 255);
			break;
		case 3:
			IMAGEMANAGER->findAlphaImage("state_bag_choice1")->alphaRender(getMemDC(), 100, 100, 255);
			IMAGEMANAGER->findAlphaImage("state_inven_choice1")->alphaRender(getMemDC(), 100, 200, 255);
			IMAGEMANAGER->findAlphaImage("state_skill_choice1")->alphaRender(getMemDC(), 100, 300, 255);
			IMAGEMANAGER->findAlphaImage("state_state_choice2")->alphaRender(getMemDC(), 100, 400, 255);
			break;
		}
		break;
	case INVEN:
		_inven->render();
		break;
	case BAG:
		_bag->render();
		break;
	case STATE:
		_state->render();
		break;
	case SKILL:
		_skillInfo->render();
		break;
	}
}
void menu::release(){}

void menu::keyInput(){
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
		_windowChoice += 1;
		if (_windowChoice == 4){ _windowChoice = 0; }
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP)){
		_windowChoice -= 1;
		if (_windowChoice == -1){ _windowChoice = 3; }
	}

	if (KEYMANAGER->isOnceKeyDown('A')){
		switch (_windowChoice){
		case 0:
			_window = BAG;
			break;
		case 1:
			_window = INVEN;
			break;
		case 2:
			_window = SKILL;
			break;
		case 3:
			_window = STATE;
			break;
		}
	}

	
}