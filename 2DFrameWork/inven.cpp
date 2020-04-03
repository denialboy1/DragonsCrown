#include "stdafx.h"
#include "inven.h"


inven::inven()
{
}


inven::~inven()
{
}

HRESULT inven::init(){
	IMAGEMANAGER->addAlphaImage("bgItemBox", "이미지/menu/아이템박스/아이템박스.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("아이템현재선택위치", "이미지/마을/상점/현재선택위치.bmp", 0, 0, 900, 100, true, RGB(255, 0, 255), true);

	_item = new item;
	_item->itemSetting();
	
	invenLoading();

	//상점에서 파는 아이템 개수
	_itemNum = 0;
	for (int i = 0; i < _vInven.size(); i++){
		switch (_vInven[i].type){
		case WEAPON:
		case ARMOR:
		case POTION:
		case RUNE:
		case SKILL_BOOK:
			_itemNum++;
		}
	}

	_leftFrameCursor = 0;
	_leftFrameMoveY = 0;
	_itemIndex = 0;

	_currentAlpha = 0;
	_currentReverse = 1;
	_currentWhich = 0;

	for (int i = 0; i < _vInven.size(); i++){
		if (strcmp(_vInven[i].name.c_str(), "크라운 스태프") == 0){
			_vInven[i].seal = INIDATA->loadDataInterger("PlayerData", "크라운 스태프", "seal");
		}
		if (strcmp(_vInven[i].name.c_str(), "대마법사 망토") == 0){
			_vInven[i].seal = INIDATA->loadDataInterger("PlayerData", "대마법사 망토", "seal");
		}
		if (strcmp(_vInven[i].name.c_str(), "마카로프의 스태프") == 0){
			_vInven[i].currentCon = INIDATA->loadDataInterger("PlayerData", "마카로프의 스태프", "currentCon");
		}
	}
	return S_OK;
}

void inven::update(){
	if (KEYMANAGER->isOnceKeyDown(VK_UP)){
		_itemIndex -= 1;
		_leftFrameCursor -= 100;
		
		if (_leftFrameCursor <= -100){
			_leftFrameCursor = 0;
			_leftFrameMoveY -= 100;
			if (_leftFrameMoveY <= -100){
				if (_itemNum < 6){
					_leftFrameCursor = (_itemNum - 1) * 100;
					_leftFrameMoveY = 0;
				}else{
					_leftFrameMoveY = (_itemNum - 7) * 100;
					_leftFrameCursor = (_itemNum - (_itemNum-6)) * 100;
				}
			}
		}
		if (_itemIndex < 0)_itemIndex = _itemNum - 1;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
		_itemIndex += 1;
		_leftFrameCursor += 100;
		if (_leftFrameCursor >= 700){
			_leftFrameCursor = 600;
			_leftFrameMoveY += 100;
			if (_leftFrameMoveY >(_itemNum-7) * 100){
				_leftFrameMoveY = 0;
				_leftFrameCursor = 0;
			}
		}

		if (_itemNum < 6){
			if (_leftFrameCursor >(_itemNum-1) * 100){
				_leftFrameMoveY = 0;
				_leftFrameCursor = 0;
			}
		}

		if (_itemIndex > _itemNum - 1)_itemIndex = 0;
	}



	//현재 선택된 위치 깜빡이게 하기
	_currentAlpha += 20 * _currentReverse;
	if (_currentAlpha == 240){ _currentReverse = -1; }
	if (_currentAlpha == 0){ _currentReverse = 1; }

}
void inven::render(){
	IMAGEMANAGER->findAlphaImage("bgItemBox")->alphaRender(getMemDC(),0,0,200);
	
	//왼쪽 프레임
	IMAGEMANAGER->findAlphaImage("아이템현재선택위치")->alphaRender(getMemDC(), -30, 170 + _leftFrameCursor, _currentAlpha);

	SetBkMode(getMemDC(), TRANSPARENT);
	HFONT hFont, oldFont;
	char str[100];
	hFont = CreateFont(40, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont = (HFONT)SelectObject(getMemDC(), hFont);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	for (int i = 0; i < _vInven.size(); i++){
		int temp = 250 + 100 * i - _leftFrameMoveY;
		if (temp > 150){
			IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 5, 175 + 100 * i-_leftFrameMoveY, _vInven[i].frameX, _vInven[i].frameY);
			TextOut(getMemDC(), 100, 200 + 100 * i - _leftFrameMoveY, _vInven[i].name.c_str(), _vInven[i].name.size());
		}
	}

	SelectObject(getMemDC(), oldFont);
	DeleteObject(hFont);

	if (_vInven.size() != 0){
		//오른쪽 프레임
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 900, 200, _vInven[_itemIndex].frameX, _vInven[_itemIndex].frameY);

		//오른쪽 프레임
		HFONT font;
		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//아이템 이름
		if (!_vInven[_itemIndex].seal){
			strcpy(str, _vInven[_itemIndex].name.c_str());
			TextOut(getMemDC(), 1000, 230, str, strlen(str));
		}
		else{
			strcpy(str, "?????????????");
			TextOut(getMemDC(), 1000, 230, str, strlen(str));
		}

		if (_vInven[_itemIndex].type == WEAPON){
			if (!_vInven[_itemIndex].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _vInven[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "공격력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d - %d", _vInven[_itemIndex].ability.ATK, _vInven[_itemIndex].ability.ATK + _vInven[_itemIndex].ability.ATK / 10);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _vInven[_itemIndex].currentCon, _vInven[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _vInven[_itemIndex].info.c_str());
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
			else{
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "공격력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "??? - ???");
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "??? / ???", _vInven[_itemIndex].currentCon, _vInven[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_vInven[_itemIndex].type == ARMOR){
			if (!_vInven[_itemIndex].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _vInven[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "방어력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d", _vInven[_itemIndex].ability.DEF);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _vInven[_itemIndex].currentCon, _vInven[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _vInven[_itemIndex].info.c_str());
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
			else{
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "방어력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "???");
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "??? / ???", _vInven[_itemIndex].currentCon, _vInven[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_vInven[_itemIndex].type == RUNE){
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			strcpy(str, _vInven[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 550, str, strlen(str));
		}

		if (_vInven[_itemIndex].type == POTION){
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			strcpy(str, _vInven[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 550, str, strlen(str));
		}
		SelectObject(getMemDC(), oldFont);

		DeleteObject(font);
	}

}
void inven::release(){
}

void inven::addInvenItem(char* name){
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), name) == 0){
			_invenItem.ability = _item->getVItem()[i].ability;
			_invenItem.currentCon = _item->getVItem()[i].currentCon;
			_invenItem.frameX = _item->getVItem()[i].frameX;
			_invenItem.frameY = _item->getVItem()[i].frameY;
			_invenItem.info = _item->getVItem()[i].info;
			_invenItem.LVCondition = _item->getVItem()[i].LVCondition;
			_invenItem.maxCon = _item->getVItem()[i].maxCon;
			_invenItem.name = _item->getVItem()[i].name;
			_invenItem.price = _item->getVItem()[i].price;
			strcpy(_invenItem.rank, _item->getVItem()[i].rank);
			_invenItem.seal = _item->getVItem()[i].seal;
			_invenItem.type = _item->getVItem()[i].type;
			if (strcmp(name, "요정의 물약") == 0){
				_invenItem.useCount = INIDATA->loadDataInterger("PlayerData", "요정의 물약", "num");
			}
			else{
				_invenItem.useCount = _item->getVItem()[i].useCount;
			}

			_vInven.push_back(_invenItem);
		}
	}
}
void inven::invenLoading(){
	if (INIDATA->loadDataInterger("PlayerData", "마카로프의 스태프", "num") > 0){
		addInvenItem("마카로프의 스태프");
	}
	if (INIDATA->loadDataInterger("PlayerData", "문라이트 스태프", "num") > 0){
		addInvenItem("문라이트 스태프");
	}
	if (INIDATA->loadDataInterger("PlayerData", "이그니 스태프", "num") > 0){
		addInvenItem("이그니 스태프");
	}
	if (INIDATA->loadDataInterger("PlayerData", "크라운 스태프", "num") > 0){
		addInvenItem("크라운 스태프");
	}
	if (INIDATA->loadDataInterger("PlayerData", "붉은 망토", "num") > 0){
		addInvenItem("붉은 망토");
	}
	if (INIDATA->loadDataInterger("PlayerData", "마법사 망토", "num") > 0){
		addInvenItem("마법사 망토");
	}
	if (INIDATA->loadDataInterger("PlayerData", "대마법사 망토", "num") > 0){
		addInvenItem("대마법사 망토");
	}
	if (INIDATA->loadDataInterger("PlayerData", "가죽 장갑", "num") > 0){
		addInvenItem("가죽 장갑");
	}
	if (INIDATA->loadDataInterger("PlayerData", "요정 장갑", "num") > 0){
		addInvenItem("요정 장갑");
	}
	if (INIDATA->loadDataInterger("PlayerData", "가죽 신발", "num") > 0){
		addInvenItem("가죽 신발");
	}
	if (INIDATA->loadDataInterger("PlayerData", "마법사 신발", "num") > 0){
		addInvenItem("마법사 신발");
	}
	if (INIDATA->loadDataInterger("PlayerData", "에메랄드 귀거리", "num") > 0){
		addInvenItem("에메랄드 귀거리");
	}
	if (INIDATA->loadDataInterger("PlayerData", "요정눈물 귀거리", "num") > 0){
		addInvenItem("요정눈물 귀거리");
	}
	if (INIDATA->loadDataInterger("PlayerData", "A룬", "num") > 0){
		addInvenItem("A룬");
	}
	if (INIDATA->loadDataInterger("PlayerData", "B룬", "num") > 0){
		addInvenItem("B룬");
	}
	if (INIDATA->loadDataInterger("PlayerData", "C룬", "num") > 0){
		addInvenItem("C룬");
	}
	if (INIDATA->loadDataInterger("PlayerData", "D룬", "num") > 0){
		addInvenItem("D룬");
	}
	if (INIDATA->loadDataInterger("PlayerData", "E룬", "num") > 0){
		addInvenItem("E룬");
	}
	if (INIDATA->loadDataInterger("PlayerData", "F룬", "num") > 0){
		addInvenItem("F룬");
	}
	if (INIDATA->loadDataInterger("PlayerData", "요정의 물약", "num") > 0){
		addInvenItem("요정의 물약");
	}
	if (INIDATA->loadDataInterger("PlayerData", "아이스 프리즌의 서", "num") > 0){
		addInvenItem("아이스 프리즌의 서");
	}
	if (INIDATA->loadDataInterger("PlayerData", "프로텍션의 서", "num") > 0){
		addInvenItem("프로텍션의 서");
	}
	if (INIDATA->loadDataInterger("PlayerData", "그래비티의 서", "num") > 0){
		addInvenItem("그래비티의 서");
	}
	if (INIDATA->loadDataInterger("PlayerData", "썬더 클라우드의 서", "num") > 0){
		addInvenItem("썬더 클라우드의 서");
	}
	if (INIDATA->loadDataInterger("PlayerData", "록 프레스의 서", "num") > 0){
		addInvenItem("록 프레스의 서");
	}
	if (INIDATA->loadDataInterger("PlayerData", "블리자드의 서", "num") > 0){
		addInvenItem("블리자드의 서");
	}
	if (INIDATA->loadDataInterger("PlayerData", "크리에이트 푸드의 서", "num") > 0){
		addInvenItem("크리에이트 푸드의 서");
	}
	if (INIDATA->loadDataInterger("PlayerData", "커스의 서", "num") > 0){
		addInvenItem("커스의 서");
	}
	if (INIDATA->loadDataInterger("PlayerData", "페트리피케이션의 서", "num") > 0){
		addInvenItem("페트리피케이션의 서");
	}
}
void inven::invenSaving(){
	char str1[10];

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
	for (int i = 0; i < _vInven.size(); i++){
		sprintf(str1, "%d", _vInven[i].useCount);
		INIDATA->addData(_vInven[i].name.c_str(), "num", str1);
	}

	//가방	-- 던전에서 사용할 아이템을 등록
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

	str = INIDATA->loadDataString("PlayerData", "Position", "X").c_str();
	INIDATA->addData("Position", "X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "Y").c_str();
	INIDATA->addData("Position", "Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "절대좌표X").c_str();
	INIDATA->addData("Position", "절대좌표X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "절대좌표Y").c_str();
	INIDATA->addData("Position", "절대좌표Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "그림자X").c_str();
	INIDATA->addData("Position", "그림자X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "그림자Y").c_str();
	INIDATA->addData("Position", "그림자Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "성X").c_str();
	INIDATA->addData("Position", "성X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "성Y").c_str();
	INIDATA->addData("Position", "성Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을1X").c_str();
	INIDATA->addData("Position", "마을1X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을1Y").c_str();
	INIDATA->addData("Position", "마을1Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을2X").c_str();
	INIDATA->addData("Position", "마을2X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을2Y").c_str();
	INIDATA->addData("Position", "마을2Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을3X").c_str();
	INIDATA->addData("Position", "마을3X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을3Y").c_str();
	INIDATA->addData("Position", "마을3Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을4X").c_str();
	INIDATA->addData("Position", "마을4X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을4Y").c_str();
	INIDATA->addData("Position", "마을4Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을5X").c_str();
	INIDATA->addData("Position", "마을5X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "마을5Y").c_str();
	INIDATA->addData("Position", "마을5Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "루카인X").c_str();
	INIDATA->addData("Position", "루카인X", str.c_str());

	INIDATA->iniSave("PlayerData");

}
void inven::itemBuy(char* name){
	for (int i = 0; i < _vInven.size(); i++){
		if (strcmp(_vInven[i].name.c_str(), name) == 0){
			_vInven[i].useCount = _vInven[i].useCount + 1;
		}
	}
}
void inven::itemSell(char* name){
	for (int i = 0; i < _vInven.size(); i++){
		if (strcmp(_vInven[i].name.c_str(), name) == 0){
			_vInven[i].useCount = _vInven[i].useCount - 1;
		}
	}

	for (VIINVEN viInven; viInven != _vInven.end();){
		if ((*viInven).useCount < 0){
			_vInven.erase(viInven);
		}
		else{
			_viInven++;
		}
	}
}