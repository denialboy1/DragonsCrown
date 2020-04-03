#include "stdafx.h"
#include "bag.h"
#include "inven.h"

bag::bag()
{
}


bag::~bag()
{
}

HRESULT bag::init(){
	IMAGEMANAGER->addAlphaImage("장비소지품배경", "이미지/menu/장비소지품/장비_소지품.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("장비현재선택위치", "이미지/마을/상점/현재선택위치.bmp",0,0, 600, 73, true, RGB(255, 0, 255),true);
	SOUNDMANAGER->addSound("장착", "사운드/소서리스/장착.wav", false, false);
	SOUNDMANAGER->addSound("장착해제", "사운드/소서리스/장착해제.wav", false, false);
	_currentSelect = 0;
	_currentAlpha = 0;
	_currentReverse = 1;

	

	for (int i = 0; i < 8; i++){
		char str1[10];
		sprintf(str1, "bag%d", i + 1);
		_bagArr[i].name = INIDATA->loadDataString("PlayerData", "Bag", str1);
		_bagArr[i].index = -1;
	}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < _inven->getVInven().size(); j++){
			if (strcmp(_bagArr[i].name.c_str(), _inven->getVInven()[j].name.c_str()) == 0){
				_bagArr[i].index = j;
			}
		}
	}
	return S_OK;
}
void bag::update(){
	if (KEYMANAGER->isOnceKeyDown(VK_UP)){
		_currentSelect -= 1;
		if (_currentSelect < 0){ _currentSelect = 7; }
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
		_currentSelect += 1;
		if (_currentSelect > 7){ _currentSelect = 0; }
	}


	//현재 선택된 위치 깜빡이게 하기
	_currentAlpha += 20 * _currentReverse;
	if (_currentAlpha == 240){ _currentReverse = -1; }
	if (_currentAlpha == 0){ _currentReverse = 1; }


	
}
void bag::render(){
	IMAGEMANAGER->findAlphaImage("장비소지품배경")->alphaRender(getMemDC(), 0, 0, 200);

	SetBkMode(getMemDC(), TRANSPARENT);
	HFONT hFont,oldFont;
	char str[100];
	hFont = CreateFont(40, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont = (HFONT)SelectObject(getMemDC(), hFont);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	IMAGEMANAGER->findAlphaImage("장비현재선택위치")->alphaRender(getMemDC(), 358, 183 + 70 * _currentSelect, _currentAlpha);
	

	//중간 프레임
	for (int i = 0; i < 8; i++){
		sprintf(str, "bag%d", i + 1);
		if (strcmp(_bagArr[i].name.c_str(), "empty") == 0){
			sprintf(str, "없음");
			TextOut(getMemDC(), 600, 200+i*70, str, strlen(str));
		}
		else{
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), 400, 185 + i * 70, _inven->getVInven()[_bagArr[i].index].frameX, _inven->getVInven()[_bagArr[i].index].frameY);
			TextOut(getMemDC(), 500, 200 + i * 70, _bagArr[i].name.c_str(), _bagArr[i].name.size());

		}
	}

	SelectObject(getMemDC(), oldFont);
	DeleteObject(hFont);

	//오른쪽 프레임
	if (strcmp(_bagArr[_currentSelect].name.c_str(), "empty") != 0){
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 1000, 200, _inven->getVInven()[_bagArr[_currentSelect].index].frameX, _inven->getVInven()[_bagArr[_currentSelect].index].frameY);

		HFONT font;
		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//아이템 이름
		if (!_inven->getVInven()[_bagArr[_currentSelect].index].seal){
			strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].name.c_str());
			TextOut(getMemDC(), 1100, 230, str, strlen(str));
		}
		else{
			strcpy(str, "?????????????");
			TextOut(getMemDC(), 1100, 230, str, strlen(str));
		}

		if (_inven->getVInven()[_bagArr[_currentSelect].index].type == WEAPON){
			if (!_inven->getVInven()[_bagArr[_currentSelect].index].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 1000, 350, str, strlen(str));
				strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].rank);
				TextOut(getMemDC(), 1400, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "공격력");
				TextOut(getMemDC(), 1000, 450, str, strlen(str));
				sprintf(str, "%d - %d", _inven->getVInven()[_bagArr[_currentSelect].index].ability.ATK, _inven->getVInven()[_bagArr[_currentSelect].index].ability.ATK + _inven->getVInven()[_bagArr[_currentSelect].index].ability.ATK / 10);
				TextOut(getMemDC(), 1400, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 1000, 550, str, strlen(str));
				sprintf(str, "%d / %d", _inven->getVInven()[_bagArr[_currentSelect].index].currentCon, _inven->getVInven()[_bagArr[_currentSelect].index].maxCon);
				TextOut(getMemDC(), 1400, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 1000, 650, str, strlen(str));
				strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].info.c_str());
				TextOut(getMemDC(), 1000, 750, str, strlen(str));
			}
			else{
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 1000, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1400, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "공격력");
				TextOut(getMemDC(), 1000, 450, str, strlen(str));
				sprintf(str, "??? - ???");
				TextOut(getMemDC(), 1400, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 1000, 550, str, strlen(str));
				sprintf(str, "??? / ???", _inven->getVInven()[_bagArr[_currentSelect].index].currentCon, _inven->getVInven()[_bagArr[_currentSelect].index].maxCon);
				TextOut(getMemDC(), 1400, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 1000, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 1000, 750, str, strlen(str));
			}
		}

		if (_inven->getVInven()[_bagArr[_currentSelect].index].type == ARMOR){
			if (!_inven->getVInven()[_bagArr[_currentSelect].index].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 1000, 350, str, strlen(str));
				strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].rank);
				TextOut(getMemDC(), 1400, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "방어력");
				TextOut(getMemDC(), 1000, 450, str, strlen(str));
				sprintf(str, "%d", _inven->getVInven()[_bagArr[_currentSelect].index].ability.DEF);
				TextOut(getMemDC(), 1400, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 1000, 550, str, strlen(str));
				sprintf(str, "%d / %d", _inven->getVInven()[_bagArr[_currentSelect].index].currentCon, _inven->getVInven()[_bagArr[_currentSelect].index].maxCon);
				TextOut(getMemDC(), 1400, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 1000, 650, str, strlen(str));
				strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].info.c_str());
				TextOut(getMemDC(), 1000, 750, str, strlen(str));
			}
			else{
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 1000, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1400, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "방어력");
				TextOut(getMemDC(), 1000, 450, str, strlen(str));
				sprintf(str, "???");
				TextOut(getMemDC(), 1400, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 1000, 550, str, strlen(str));
				sprintf(str, "??? / ???", _inven->getVInven()[_bagArr[_currentSelect].index].currentCon, _inven->getVInven()[_bagArr[_currentSelect].index].maxCon);
				TextOut(getMemDC(), 1400, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 1000, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 1000, 750, str, strlen(str));
			}
		}

		if (_inven->getVInven()[_bagArr[_currentSelect].index].type == RUNE){
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 1000, 450, str, strlen(str));
			strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].info.c_str());
			TextOut(getMemDC(), 1000, 550, str, strlen(str));
		}

		if (_inven->getVInven()[_bagArr[_currentSelect].index].type == POTION){
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 1000, 450, str, strlen(str));
			strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].info.c_str());
			TextOut(getMemDC(), 1000, 550, str, strlen(str));
		}


		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);
	}
}
void bag::release(){}


void bag::equipItem(){
	for (int i = 0; i < 8; i++){
		char str1[10];
		sprintf(str1, "bag%d", i + 1);
		if (_currentSelect == i){
			for (int j = 0; j < 8; j++){
				if (_bagArr[j].index > -1){
					if (strcmp(_bagArr[j].name.c_str(), _inven->getVInven()[_inven->getItemIndex()].name.c_str()) == 0){
						_bagArr[j].name = "empty";
						_bagArr[j].index = -1;
						SOUNDMANAGER->play("장착해제", 0.3F);
					}
				}
			}
			_bagArr[i].name = _inven->getVInven()[_inven->getItemIndex()].name.c_str();
			_bagArr[i].index = _inven->getItemIndex();
		}
	}
}

void bag::bagSave(){
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

	//인벤토리	-- 모든 아이템이들어있음
	str = INIDATA->loadDataString("PlayerData", "마카로프의 스태프", "num").c_str();
	INIDATA->addData("마카로프의 스태프", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "문라이트 스태프", "num").c_str();
	INIDATA->addData("문라이트 스태프", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "이그니 스태프", "num").c_str();
	INIDATA->addData("이그니 스태프", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "크라운 스태프", "num").c_str();
	INIDATA->addData("크라운 스태프", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "붉은 망토", "num").c_str();
	INIDATA->addData("붉은 망토", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "마법사 망토", "num").c_str();
	INIDATA->addData("마법사 망토", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "대마법사 망토", "num").c_str();
	INIDATA->addData("대마법사 망토", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "가죽 장갑", "num").c_str();
	INIDATA->addData("가죽 장갑", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "요정 장갑", "num").c_str();
	INIDATA->addData("요정 장갑", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "가죽 신발", "num").c_str();
	INIDATA->addData("가죽 신발", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "마법사 신발", "num").c_str();
	INIDATA->addData("마법사 신발", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "에메랄드 귀거리", "num").c_str();
	INIDATA->addData("에메랄드 귀거리", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "요정눈물 귀거리", "num").c_str();
	INIDATA->addData("요정눈물 귀거리", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "A룬", "num").c_str();
	INIDATA->addData("A룬", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "B룬", "num").c_str();
	INIDATA->addData("B룬", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "C룬", "num").c_str();
	INIDATA->addData("C룬", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "D룬", "num").c_str();
	INIDATA->addData("D룬", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "E룬", "num").c_str();
	INIDATA->addData("E룬", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "F룬", "num").c_str();
	INIDATA->addData("F룬", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "요정의 물약", "num").c_str();
	INIDATA->addData("요정의 물약", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "아이스 프리즌의 서", "num").c_str();
	INIDATA->addData("아이스 프리즌의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "프로텍션의 서", "num").c_str();
	INIDATA->addData("프로텍션의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "그래비티의 서", "num").c_str();
	INIDATA->addData("그래비티의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "썬더 클라우드의 서", "num").c_str();
	INIDATA->addData("썬더 클라우드의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "록 프레스의 서", "num").c_str();
	INIDATA->addData("록 프레스의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "블리자드의 서", "num").c_str();
	INIDATA->addData("블리자드의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "크리에이트 푸드의 서", "num").c_str();
	INIDATA->addData("크리에이트 푸드의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "커스의 서", "num").c_str();
	INIDATA->addData("커스의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "페트리피케이션의 서", "num").c_str();
	INIDATA->addData("페트리피케이션의 서", "num", str.c_str());


	//세이브
	for (int i = 0; i < 8; i++){
		char str1[10];
		sprintf(str1, "bag%d", i + 1);
		INIDATA->addData("Bag", str1, _bagArr[i].name.c_str());
	}

	//스킬
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

	INIDATA->iniSave("PlayerData");
}