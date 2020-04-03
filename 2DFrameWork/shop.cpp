#include "stdafx.h"
#include "shop.h"


shop::shop()
{
}


shop::~shop()
{
}

HRESULT shop::init(){
	_shopWindow = SHOP;
	_item = new item;
	_item->itemSetting();
	_itemCount[0].count = INIDATA->loadDataInterger("PlayerData", "마카로프의 스태프", "num");
	_itemCount[0].seal = 0;
	_itemCount[0].currentCon = INIDATA->loadDataInterger("PlayerData", "마카로프의 스태프", "currentCon");
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "마카로프의 스태프") == 0){
			_itemCount[0].maxCon = _item->getVItem()[i].maxCon;
		}
	}
	//_itemCount[0].maxCon = 
	_itemCount[1].count = INIDATA->loadDataInterger("PlayerData", "문라이트 스태프", "num");
	_itemCount[1].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "문라이트 스태프") == 0) _itemCount[1].maxCon = _itemCount[1].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[2].count = INIDATA->loadDataInterger("PlayerData", "이그니 스태프", "num");
	_itemCount[2].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "이그니 스태프") == 0) _itemCount[2].maxCon = _itemCount[2].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[3].count = INIDATA->loadDataInterger("PlayerData", "크라운 스태프", "num");
	_itemCount[3].seal = INIDATA->loadDataInterger("PlayerData", "크라운 스태프", "seal");
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "크라운 스태프") == 0) _itemCount[3].maxCon = _itemCount[3].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[4].count = INIDATA->loadDataInterger("PlayerData", "붉은 망토", "num");
	_itemCount[4].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "붉은 망토") == 0) _itemCount[4].maxCon = _itemCount[4].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[5].count = INIDATA->loadDataInterger("PlayerData", "마법사 망토", "num");
	_itemCount[5].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "마법사 망토") == 0) _itemCount[5].maxCon = _itemCount[5].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[6].count = INIDATA->loadDataInterger("PlayerData", "대마법사 망토", "num");
	_itemCount[6].seal = INIDATA->loadDataInterger("PlayerData", "대마법사 망토", "seal");
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "대마법사 망토") == 0) _itemCount[6].maxCon = _itemCount[6].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[7].count = INIDATA->loadDataInterger("PlayerData", "가죽 장갑", "num");
	_itemCount[7].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "가죽 장갑") == 0) _itemCount[7].maxCon = _itemCount[7].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[8].count = INIDATA->loadDataInterger("PlayerData", "요정 장갑", "num");
	_itemCount[8].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "요정 장갑") == 0) _itemCount[8].maxCon = _itemCount[8].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[9].count = INIDATA->loadDataInterger("PlayerData", "가죽 신발", "num");
	_itemCount[9].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "가죽 신발") == 0) _itemCount[9].maxCon = _itemCount[9].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[10].count= INIDATA->loadDataInterger("PlayerData", "마법사 신발", "num");
	_itemCount[10].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "마법사 신발") == 0) _itemCount[10].maxCon = _itemCount[10].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[11].count= INIDATA->loadDataInterger("PlayerData", "에메랄드 귀거리", "num");
	_itemCount[11].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "에메랄드 귀거리") == 0) _itemCount[11].maxCon = _itemCount[11].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[12].count= INIDATA->loadDataInterger("PlayerData", "요정눈물 귀거리", "num");
	_itemCount[12].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "요정눈물 귀거리") == 0) _itemCount[12].maxCon = _itemCount[12].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[13].count= INIDATA->loadDataInterger("PlayerData", "A룬", "num");
	_itemCount[13].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "A룬") == 0) _itemCount[13].maxCon = _itemCount[13].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[14].count= INIDATA->loadDataInterger("PlayerData", "B룬", "num");
	_itemCount[14].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "B룬") == 0) _itemCount[14].maxCon = _itemCount[14].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[15].count= INIDATA->loadDataInterger("PlayerData", "C룬", "num");
	_itemCount[15].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "C룬") == 0) _itemCount[15].maxCon = _itemCount[15].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[16].count= INIDATA->loadDataInterger("PlayerData", "D룬", "num");
	_itemCount[16].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "D룬") == 0) _itemCount[16].maxCon = _itemCount[16].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[17].count= INIDATA->loadDataInterger("PlayerData", "E룬", "num");
	_itemCount[17].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "E룬") == 0) _itemCount[17].maxCon = _itemCount[17].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[18].count= INIDATA->loadDataInterger("PlayerData", "F룬", "num");
	_itemCount[18].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "F룬") == 0) _itemCount[18].maxCon = _itemCount[18].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[19].count=INIDATA->loadDataInterger("PlayerData", "요정의 물약", "num");
	_itemCount[19].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "요정의 물약") == 0) _itemCount[19].maxCon = _itemCount[19].currentCon = _item->getVItem()[i].maxCon;
	}
	_money = INIDATA->loadDataInterger("PlayerData", "State", "Money");
	_moneyError = false;
	IMAGEMANAGER->addAlphaImage("금액부족", "이미지/마을/상점/금액부족.bmp", 1600, 113, false, RGB(0, 0, 0));
	IMAGEMANAGER->addAlphaImage("감정템부족", "이미지/마을/상점/감정템부족.bmp", 1600, 113, false, RGB(0, 0, 0));
	shopInit();
	buyInit();
	sellInit();
	repairInit();
	analyzeInit();
	confirmInit();
	return S_OK;
}
void shop::update(){
	shopUpdate();
	buyUpdate();
	sellUpdate();
	repairUpdate();
	analyzeUpdate();
	confirmUpdate();
}
void shop::render(){
	shopRender();

	switch (_shopWindow){
	case BUY:
	case BUY_CONFIRM:
		buyRender();
		break;
	case SELL:
	case SELL_CONFIRM:
		sellRender();
		break;
	case REPAIR:
	case REPAIR_CONFIRM:
		repairRender();
		break;
	case ANALYZE:
	case ANALYZE_CONFIRM:
		analyzeRender();
		break;
	}


	confirmRender();


}
void shop::release(){
	
}

void shop::shopInit(){
	

	//IMAGEMANAGER->addFrameImage("상점엔피씨", "이미지/마을/상점/상점엔피씨.bmp", 16000, 4500, 10, 5, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("상점마크", "이미지/마을/상점/마법상점마크.bmp", 293, 215, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("구입선택지1", "이미지/마을/상점/구입선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("구입선택지2", "이미지/마을/상점/구입선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("매각선택지1", "이미지/마을/상점/매각선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("매각선택지2", "이미지/마을/상점/매각선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("수리선택지1", "이미지/마을/상점/수리선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("수리선택지2", "이미지/마을/상점/수리선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("감정선택지1", "이미지/마을/상점/감정선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("감정선택지2", "이미지/마을/상점/감정선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("나가기선택지1", "이미지/마을/나가기선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("나가기선택지2", "이미지/마을/나가기선택지2.bmp", 467, 80, true, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("상점", "사운드/상점.mp3", true, true);
	SOUNDMANAGER->play("상점", 0.1f);
	SOUNDMANAGER->addSound("구입", "사운드/상점/구입.wav", false, false);
	SOUNDMANAGER->addSound("팔기", "사운드/상점/팔기.wav", false, false);
	SOUNDMANAGER->addSound("감정", "사운드/상점/감정.wav", false, false);
	SOUNDMANAGER->addSound("수리", "사운드/상점/수리.wav", false, false);

	KEYANIMANAGER->addDefaultFrameAnimation("상점엔피씨", "상점엔피씨", 30, true, true);
	_npcMove = KEYANIMANAGER->findAnimation("상점엔피씨");
	_npcMove->start();
	_analyzeError = false;
	_shopAction = ITEM_BUY;
	_shopActionNumber = 0;
}
void shop::shopUpdate(){
	if (_shopWindow == SHOP){
		if (KEYMANAGER->isOnceKeyDown(VK_UP)){
			_shopActionNumber -= 1;
			if (_shopActionNumber == -1){ _shopActionNumber = 4; }
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
			_shopActionNumber += 1;
			if (_shopActionNumber == 5){ _shopActionNumber = 0; }
		}

		if (KEYMANAGER->isOnceKeyDown('A')){
			switch (_shopAction){
			case ITEM_BUY:
				_shopWindow = BUY;
				break;
			case ITEM_SELL:
				_shopWindow = SELL;
				break;
			case ITEM_REPAIR:
				_shopWindow = REPAIR;
				break;
			case ITEM_ANALYZE:
				_shopWindow = ANALYZE;
				break;
			case SHOP_EXIT:
				_npcMove->stop();
				dataSave();
				SOUNDMANAGER->allRemove();
				SCENEMANAGER->changeScene("마을씬");
				break;
			}
		}

		if (KEYMANAGER->isOnceKeyDown('X')){
			_shopActionNumber = 4;
		}

		switch (_shopActionNumber){
		case 0:
			_shopAction = ITEM_BUY;
			break;
		case 1:
			_shopAction = ITEM_SELL;
			break;
		case 2:
			_shopAction = ITEM_REPAIR;
			break;
		case 3:
			_shopAction = ITEM_ANALYZE;
			break;
		case 4:
			_shopAction = SHOP_EXIT;
			break;
		}
	}
}
void shop::shopRender(){
	IMAGEMANAGER->findImage("상점엔피씨")->aniRender(getMemDC(), 0, 0, _npcMove);
	IMAGEMANAGER->findImage("상점마크")->render(getMemDC(), 80, 55);

	switch (_shopAction){
	case ITEM_BUY:
		IMAGEMANAGER->findImage("구입선택지2")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("매각선택지1")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("수리선택지1")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("감정선택지1")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("나가기선택지1")->render(getMemDC(), -10, 650);
		break;
	case ITEM_SELL:
		IMAGEMANAGER->findImage("구입선택지1")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("매각선택지2")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("수리선택지1")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("감정선택지1")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("나가기선택지1")->render(getMemDC(), -10, 650);
		break;
	case ITEM_REPAIR:
		IMAGEMANAGER->findImage("구입선택지1")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("매각선택지1")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("수리선택지2")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("감정선택지1")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("나가기선택지1")->render(getMemDC(), -10, 650);
		break;
	case ITEM_ANALYZE:
		IMAGEMANAGER->findImage("구입선택지1")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("매각선택지1")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("수리선택지1")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("감정선택지2")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("나가기선택지1")->render(getMemDC(), -10, 650);
		break;
	case SHOP_EXIT:
		IMAGEMANAGER->findImage("구입선택지1")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("매각선택지1")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("수리선택지1")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("감정선택지1")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("나가기선택지2")->render(getMemDC(), -10, 650);
		break;
	}
}

void shop::confirmInit(){
	IMAGEMANAGER->addAlphaImage("흑백처리2", "이미지/마을/길드/흑백처리.bmp", 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("대화상자", "이미지/talkBar.bmp", 1600, 118, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("no", "이미지/no.bmp", 184, 185, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yes", "이미지/yes.bmp", 185, 185, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("no_check", "이미지/no_check.bmp", 236, 234, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yes_check", "이미지/yes_check.bmp", 234, 235, true, RGB(255, 0, 255));

	_bConfirm = true;

}
void shop::confirmUpdate(){
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
		_bConfirm = !_bConfirm;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
		_bConfirm = !_bConfirm;
	}

	if (KEYMANAGER->isOnceKeyDown('A')){
		switch (_shopAction){
		case ITEM_BUY:
			if (_bConfirm){
				_money -= _item->getVItem()[_itemIndex].price;
				_itemCount[_itemIndex].count++;
				if (strcmp(_item->getVItem()[_itemIndex].name.c_str(), "크라운 스태프") == 0 ||
					strcmp(_item->getVItem()[_itemIndex].name.c_str(), "대마법사 망토") == 0){
					_itemCount[_itemIndex].seal = 1;
				}
				else{
					_itemCount[_itemIndex].seal = 0;
				}
				dataSave();
				_shopWindow = BUY;
				SOUNDMANAGER->play("구입", 0.3F);
			}
			else{
				//구입 취소
				_bConfirm = true;
				_shopWindow = BUY;
			}
			
			break;
		case ITEM_SELL:
			if (_bConfirm){
				//아이템 팔기
				for (int i = 0; i < 20; i++){
					if (strcmp(_sellItem[_itemIndex].name.c_str(), _item->getVItem()[i].name.c_str())==0){
						_money += _item->getVItem()[i].price*0.8;
						_itemCount[i].count--;
					}
				}
				dataSave();
				_playerIndex--;
				_shopWindow = SELL;
				SOUNDMANAGER->play("팔기", 0.3F);
			}
			else{
				//팔기 취소
				_bConfirm = true;
				_shopWindow = SELL;
			}
			
			break;
		case ITEM_REPAIR:
			if (_bConfirm){
				//아이템 수리
				_repairItem[_playerIndex].currentCon = _repairItem[_playerIndex].maxCon;
				if (strcmp(_repairItem[_playerIndex].name.c_str(), "마카로프의 스태프") == 0){
					_itemCount[0].currentCon = _itemCount[0].maxCon;
				}


				_money -= _repairItem[_playerIndex].price*0.2f;
				dataSave();
				_playerIndex--;
				_shopWindow = REPAIR;
				SOUNDMANAGER->play("수리", 0.3F);
			}
			else{
				//수리 취소
				_bConfirm = true;
			}
			_shopWindow = REPAIR;
			break;
		case ITEM_ANALYZE:
			if (_bConfirm){
				//아이템 감정
				_analyzeItem[_itemIndex].seal = false;
				_money -= _analyzeItem[_itemIndex].price*0.1f;
				dataSave();
				_playerIndex--;
				_shopWindow = SELL;
				SOUNDMANAGER->play("감정", 0.3F);
			}
			else{
				//감정 취소
				_bConfirm = true;
			}
			_shopWindow = ANALYZE;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		_bConfirm = false;
	}
}
void shop::confirmRender(){
	HFONT oldFont;
	HFONT font;
	SetBkMode(getMemDC(), TRANSPARENT);

	char str1[100];
	char str2[100];
	RECT rcText = { 0, 340, 1600, 390 };

	switch (_shopWindow){
	case BUY_CONFIRM:
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		
			IMAGEMANAGER->findAlphaImage("대화상자")->render(getMemDC(), 0, 300);
			if (_bConfirm){
				IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
				IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
			}
			else{
				IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
				IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
			}
			font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
			oldFont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			strcpy(str1, _item->getVItem()[_itemIndex].name.c_str());
			sprintf(str2, " 아이템을 %d에 사시겠습니까?", _item->getVItem()[_itemIndex].price);
			strcat(str1, str2);
			DrawText(getMemDC(), str1, strlen(str1), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font);
		

		
		break;

	case SELL_CONFIRM:
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("대화상자")->render(getMemDC(), 0, 300);
		if (_bConfirm){
			IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
			IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
		}
		else{
			IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
			IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
		}

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		for (int i = 0; i < 20; i++){
			if (strcmp(_sellItem[_itemIndex].name.c_str(), _item->getVItem()[i].name.c_str()) == 0){
				strcpy(str1, _sellItem[_itemIndex].name.c_str());
				sprintf(str2, " 아이템을 %d에 파시겠습니까?", _sellItem[_itemIndex].price / 10 * 8);
				strcat(str1, str2);
			}
		}
		
		DrawText(getMemDC(), str1, strlen(str1), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;

	case REPAIR_CONFIRM:
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("대화상자")->render(getMemDC(), 0, 300);
		if (_bConfirm){
			IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
			IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
		}
		else{
			IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
			IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
		}

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		strcpy(str1, _repairItem[_playerIndex].name.c_str());
		
		sprintf(str2, " 아이템을 %d에 수리하시겠습니까?", (int)((float)_repairItem[_playerIndex].price * 0.2f));
		strcat(str1, str2);
		DrawText(getMemDC(), str1, strlen(str1), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	case ANALYZE_CONFIRM:
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("대화상자")->render(getMemDC(), 0, 300);
		if (_bConfirm){
			IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
			IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
		}
		else{
			IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
			IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
		}



		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		int price1 = (float)_analyzeItem[_itemIndex].price*0.1f;
		sprintf(str1, " %d에 감정하시겠습니까?", price1);
		

		DrawText(getMemDC(), str1, strlen(str1), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	}
}
void shop::buyInit(){
	IMAGEMANAGER->addAlphaImage("구입", "이미지/마을/상점/구입.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("코인", "이미지/마을/상점/코인.bmp", 34, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("현재선택위치", "이미지/마을/상점/현재선택위치.bmp", 750, 110, true, RGB(255, 0, 255));
	_itemIndex = 0;

	//상점에서 파는 아이템 개수
	_itemBuyNum = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		switch (_item->getVItem()[i].type){
		case WEAPON:
		case ARMOR:
		case POTION:
		case RUNE:
			_itemBuyNum++;
		}
	}

	_leftFrameCursor = 0;
	_leftFrameMoveY = 0;
}
void shop::buyUpdate(){
	if (_shopWindow == BUY){
		if (KEYMANAGER->isOnceKeyDown(VK_UP)){
			_itemIndex -= 1;
			_leftFrameCursor -= 100;
			if (_leftFrameCursor <= -100){
				_leftFrameCursor = 0;
				_leftFrameMoveY -= 100;
				if (_leftFrameMoveY <= -100){
					_leftFrameMoveY = (_itemBuyNum - 6) * 100;
					_leftFrameCursor = 500;
				}
			}
			if (_itemIndex < 0)_itemIndex = _itemBuyNum - 1;
			_moneyError = false;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
			_itemIndex += 1;
			_leftFrameCursor += 100;
			if (_leftFrameCursor >= 600){
				_leftFrameCursor = 500;
				_leftFrameMoveY += 100;
				if (_leftFrameMoveY >(_itemBuyNum - 6) * 100){
					_leftFrameMoveY = 0;
					_leftFrameCursor = 0;
				}
			}
			if (_itemIndex > _itemBuyNum - 1)_itemIndex = 0;
			_moneyError = false;
		}
		if (KEYMANAGER->isOnceKeyDown('A')){
			if (_money - _item->getVItem()[_itemIndex].price<0){
				_moneyError = true;
			}
			else{
				_shopWindow = BUY_CONFIRM;
				_moneyError = false;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X')){
			_shopWindow = SHOP;
			_itemIndex = 0;
			_leftFrameCursor = 0;
			_leftFrameMoveY = 0;
		}
	}
}
void shop::buyRender(){
	IMAGEMANAGER->findAlphaImage("구입")->alphaRender(getMemDC(), 0, 0, 240);

	//왼쪽 프레임
	IMAGEMANAGER->findAlphaImage("현재선택위치")->alphaRender(getMemDC(), 50, 240 + _leftFrameCursor, 200);
	HFONT oldFont2;
	HFONT font2;
	char str1[30];
	SetBkMode(getMemDC(), TRANSPARENT);
	font2 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont2 = (HFONT)SelectObject(getMemDC(), font2);
	SetTextColor(getMemDC(), RGB(255, 255, 0));
	sprintf(str1, "%d", _money);
	TextOut(getMemDC(), 400, 165, str1, strlen(str1));
	SelectObject(getMemDC(), oldFont2);
	DeleteObject(font2);

	HFONT oldFont;
	HFONT font;
	SetBkMode(getMemDC(), TRANSPARENT);
	char str[100];
	for (int i = 0, j = 0; i < _item->getVItem().size(); i++){

		switch (_item->getVItem()[i].type){
		case WEAPON:
		case ARMOR:
		case POTION:
		case RUNE:
			int temp = 250 + 100 * j - _leftFrameMoveY;
			if (temp > 150){
				IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 100, 250 + 100 * j - _leftFrameMoveY, _item->getVItem()[i].frameX, _item->getVItem()[i].frameY);

				//코인 이미지
				IMAGEMANAGER->findImage("코인")->render(getMemDC(), 580, 275 + 100 * j - _leftFrameMoveY);
				//금액

				font = CreateFont(30, 20, 0, 0, 100, 0, 0
					, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				//아이템이름
				if (!_item->getVItem()[i].seal){
					strcpy(str, _item->getVItem()[i].name.c_str());
					TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
				}
				else{
					strcpy(str, "?????????????");
					TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
				}
				//아이템가격
				sprintf(str, "%d", _item->getVItem()[i].price);
				TextOut(getMemDC(), 620, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
				SelectObject(getMemDC(), oldFont);
				DeleteObject(font);
			}
		}
		switch (_item->getVItem()[i].type){
		case WEAPON:
		case ARMOR:
		case POTION:
		case RUNE:
			j++;
		}
	}

	//오른쪽 프레임
	IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 900, 200, _item->getVItem()[_itemIndex].frameX, _item->getVItem()[_itemIndex].frameY);

	font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont = (HFONT)SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	//아이템 이름
	if (!_item->getVItem()[_itemIndex].seal){
		strcpy(str, _item->getVItem()[_itemIndex].name.c_str());
		TextOut(getMemDC(), 1000, 230, str, strlen(str));
	}
	else{
		strcpy(str, "?????????????");
		TextOut(getMemDC(), 1000, 230, str, strlen(str));
	}

	if (_item->getVItem()[_itemIndex].type == WEAPON){
		if (!_item->getVItem()[_itemIndex].seal){
			//아이템 랭크
			sprintf(str, "랭크");
			TextOut(getMemDC(), 900, 350, str, strlen(str));
			strcpy(str, _item->getVItem()[_itemIndex].rank);
			TextOut(getMemDC(), 1300, 350, str, strlen(str));
			//아이템 공격력
			sprintf(str, "공격력");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			sprintf(str, "%d - %d", _item->getVItem()[_itemIndex].ability.ATK, _item->getVItem()[_itemIndex].ability.ATK + _item->getVItem()[_itemIndex].ability.ATK / 10);
			TextOut(getMemDC(), 1300, 450, str, strlen(str));
			//아이템 내구도
			sprintf(str, "내구도");
			TextOut(getMemDC(), 900, 550, str, strlen(str));
			sprintf(str, "%d / %d", _item->getVItem()[_itemIndex].currentCon, _item->getVItem()[_itemIndex].maxCon);
			TextOut(getMemDC(), 1300, 550, str, strlen(str));
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 900, 650, str, strlen(str));
			strcpy(str, _item->getVItem()[_itemIndex].info.c_str());
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
			sprintf(str, "??? / ???", _item->getVItem()[_itemIndex].currentCon, _item->getVItem()[_itemIndex].maxCon);
			TextOut(getMemDC(), 1300, 550, str, strlen(str));
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 900, 650, str, strlen(str));
			sprintf(str, "아이템 감정이 필요합니다");
			TextOut(getMemDC(), 900, 750, str, strlen(str));
		}
	}

	if (_item->getVItem()[_itemIndex].type == ARMOR){
		if (!_item->getVItem()[_itemIndex].seal){
			//아이템 랭크
			sprintf(str, "랭크");
			TextOut(getMemDC(), 900, 350, str, strlen(str));
			strcpy(str, _item->getVItem()[_itemIndex].rank);
			TextOut(getMemDC(), 1300, 350, str, strlen(str));
			//아이템 공격력
			sprintf(str, "방어력");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			sprintf(str, "%d", _item->getVItem()[_itemIndex].ability.DEF);
			TextOut(getMemDC(), 1300, 450, str, strlen(str));
			//아이템 내구도
			sprintf(str, "내구도");
			TextOut(getMemDC(), 900, 550, str, strlen(str));
			sprintf(str, "%d / %d", _item->getVItem()[_itemIndex].currentCon, _item->getVItem()[_itemIndex].maxCon);
			TextOut(getMemDC(), 1300, 550, str, strlen(str));
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 900, 650, str, strlen(str));
			strcpy(str, _item->getVItem()[_itemIndex].info.c_str());
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
			sprintf(str, "??? / ???", _item->getVItem()[_itemIndex].currentCon, _item->getVItem()[_itemIndex].maxCon);
			TextOut(getMemDC(), 1300, 550, str, strlen(str));
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 900, 650, str, strlen(str));
			sprintf(str, "아이템 감정이 필요합니다");
			TextOut(getMemDC(), 900, 750, str, strlen(str));
		}
	}

	if (_item->getVItem()[_itemIndex].type == RUNE){
		//아이템 설명
		sprintf(str, "효과");
		TextOut(getMemDC(), 900, 450, str, strlen(str));
		strcpy(str, _item->getVItem()[_itemIndex].info.c_str());
		TextOut(getMemDC(), 900, 550, str, strlen(str));
	}

	if (_item->getVItem()[_itemIndex].type == POTION){
		//아이템 설명
		sprintf(str, "효과");
		TextOut(getMemDC(), 900, 450, str, strlen(str));
		strcpy(str, _item->getVItem()[_itemIndex].info.c_str());
		TextOut(getMemDC(), 900, 550, str, strlen(str));
	}
	SelectObject(getMemDC(), oldFont);

	DeleteObject(font);

	if (_moneyError){
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("금액부족")->render(getMemDC(), 0, 600);
	}
}

void shop::sellInit(){
	IMAGEMANAGER->addAlphaImage("매각", "이미지/마을/상점/매각.bmp", 1600, 900, true, RGB(255, 0, 255));

	_playerIndex = -1;
}

void shop::sellUpdate(){
	//플레이어가 아이템을 가지고있는지 확인
	
	if (_shopWindow == SELL){
		_playerIndex = -1;
		_sellItem.clear();
		for (int i = 0; i < 20; i++){
			if (_itemCount[i].count > 0){
				_playerIndex++;
				tagItem temp;
				temp = _item->getVItem()[i];
				_sellItem.push_back(temp);
			}

		}
		if (_playerIndex > -1){
			if (KEYMANAGER->isOnceKeyDown(VK_UP)){
				_itemIndex -= 1;
				_leftFrameCursor -= 100;
				if (_leftFrameCursor <= -100){
					_leftFrameCursor = 0;
					_leftFrameMoveY -= 100;
					if (_leftFrameMoveY <= -100){
						_leftFrameMoveY = (_itemBuyNum - 6) * 100;
						_leftFrameCursor = 500;
					}
				}
				if (_itemIndex < 0)_itemIndex = _itemBuyNum - 1;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
				_itemIndex += 1;
				_leftFrameCursor += 100;
				if (_leftFrameCursor >= 600){
					_leftFrameCursor = 500;
					_leftFrameMoveY += 100;
					if (_leftFrameMoveY >(_itemBuyNum - 6) * 100){
						_leftFrameMoveY = 0;
						_leftFrameCursor = 0;
					}
				}
				if (_itemIndex > _itemBuyNum - 1)_itemIndex = 0;
			}
			if (KEYMANAGER->isOnceKeyDown('A')){
				_shopWindow = SELL_CONFIRM;
				//아이템 번호 추가
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X')){
			_shopWindow = SHOP;
			_leftFrameCursor = 0;
		}
	}
}

void shop::sellRender(){
	IMAGEMANAGER->findAlphaImage("매각")->alphaRender(getMemDC(), 0, 0, 240);

	HFONT oldFont;
	HFONT font;
	SetBkMode(getMemDC(), TRANSPARENT);

	char str1[100];
	HFONT oldFont2;
	HFONT font2;
	char str3[30];
	SetBkMode(getMemDC(), TRANSPARENT);
	font2 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont2 = (HFONT)SelectObject(getMemDC(), font2);
	SetTextColor(getMemDC(), RGB(255, 255, 0));
	sprintf(str3, "%d", _money);
	TextOut(getMemDC(), 400, 165, str3, strlen(str3));
	SelectObject(getMemDC(), oldFont2);
	DeleteObject(font2);
	if (_playerIndex <= -1){
		font = CreateFont(30, 20, 0, 0, 100, 0, 0
			, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str1, "아이템을 가지고 있지 않습니다.");
		TextOut(getMemDC(), 130, 250, str1, strlen(str1));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
	else{
		//왼쪽 프레임
		IMAGEMANAGER->findAlphaImage("현재선택위치")->alphaRender(getMemDC(), 50, 240 + _leftFrameCursor, 200);
		

		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);
		char str[100];
		for (int i = 0, j = 0; i < _sellItem.size(); i++){

			switch (_sellItem[i].type){
			case WEAPON:
			case ARMOR:
			case POTION:
			case RUNE:
				int temp = 250 + 100 * j - _leftFrameMoveY;
				if (temp > 150){
					IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 100, 250 + 100 * j - _leftFrameMoveY, _sellItem[i].frameX, _sellItem[i].frameY);

					//코인 이미지
					IMAGEMANAGER->findImage("코인")->render(getMemDC(), 580, 275 + 100 * j - _leftFrameMoveY);
					//금액

					font = CreateFont(30, 20, 0, 0, 100, 0, 0
						, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
					oldFont = (HFONT)SelectObject(getMemDC(), font);
					SetTextColor(getMemDC(), RGB(255, 255, 255));
					//아이템이름
					if (!_sellItem[i].seal){
						strcpy(str, _sellItem[i].name.c_str());
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					else{
						strcpy(str, "?????????????");
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					//아이템가격
					sprintf(str, "%d", _sellItem[i].price);
					TextOut(getMemDC(), 620, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					SelectObject(getMemDC(), oldFont);
					DeleteObject(font);
				}
			}
			switch (_sellItem[i].type){
			case WEAPON:
			case ARMOR:
			case POTION:
			case RUNE:
				j++;
			}
		}

		//오른쪽 프레임
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 900, 200, _sellItem[_itemIndex].frameX, _sellItem[_itemIndex].frameY);

		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//아이템 이름
		if (!_sellItem[_itemIndex].seal){
			strcpy(str, _sellItem[_itemIndex].name.c_str());
			TextOut(getMemDC(), 1000, 230, str, strlen(str));
		}
		else{
			strcpy(str, "?????????????");
			TextOut(getMemDC(), 1000, 230, str, strlen(str));
		}

		if (_sellItem[_itemIndex].type == WEAPON){
			if (!_sellItem[_itemIndex].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _sellItem[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "공격력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d - %d", _sellItem[_itemIndex].ability.ATK, _sellItem[_itemIndex].ability.ATK + _sellItem[_itemIndex].ability.ATK / 10);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _sellItem[_itemIndex].currentCon, _sellItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _sellItem[_itemIndex].info.c_str());
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
				sprintf(str, "??? / ???", _sellItem[_itemIndex].currentCon, _sellItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_sellItem[_itemIndex].type == ARMOR){
			if (!_sellItem[_itemIndex].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _sellItem[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "방어력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d", _sellItem[_itemIndex].ability.DEF);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _sellItem[_itemIndex].currentCon, _sellItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _sellItem[_itemIndex].info.c_str());
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
				sprintf(str, "??? / ???", _sellItem[_itemIndex].currentCon, _sellItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_sellItem[_itemIndex].type == RUNE){
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			strcpy(str, _sellItem[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 550, str, strlen(str));
		}

		if (_sellItem[_itemIndex].type == POTION){
			//아이템 설명
			sprintf(str, "효과");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			strcpy(str, _sellItem[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 550, str, strlen(str));
		}
	}
}

void shop::repairInit(){
	IMAGEMANAGER->addAlphaImage("수리", "이미지/마을/상점/수리.bmp", 1600, 900, true, RGB(255, 0, 255));
	_repairNum = 0;
}
void shop::repairUpdate(){
	if (_shopWindow == REPAIR){
		//플레이어가 아이템을 가지고있는지 확인
		_playerIndex = -1;
		_repairItem.clear();
		for (int i = 0; i < 20; i++){
			if (_itemCount[i].currentCon < _itemCount[i].maxCon){
				_playerIndex++;
				tagItem temp;
				temp = _item->getVItem()[i];
				temp.currentCon = _itemCount[i].currentCon;
				_repairItem.push_back(temp);
			}
		}
		if (_playerIndex >= 0){
			if (KEYMANAGER->isOnceKeyDown(VK_UP)){
				_itemIndex -= 1;
				_leftFrameCursor -= 100;
				if (_leftFrameCursor <= -100){
					_leftFrameCursor = 0;
					_leftFrameMoveY -= 100;
					if (_leftFrameMoveY <= -100){
						_leftFrameMoveY = (_itemBuyNum - 6) * 100;
						_leftFrameCursor = 500;
					}
				}
				if (_itemIndex < 0)_itemIndex = _itemBuyNum - 1;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
				_itemIndex += 1;
				_leftFrameCursor += 100;
				if (_leftFrameCursor >= 600){
					_leftFrameCursor = 500;
					_leftFrameMoveY += 100;
					if (_leftFrameMoveY >(_itemBuyNum - 6) * 100){
						_leftFrameMoveY = 0;
						_leftFrameCursor = 0;
					}
				}
				if (_itemIndex > _itemBuyNum - 1)_itemIndex = 0;
			}
			if (KEYMANAGER->isOnceKeyDown('A')){
				_shopWindow = REPAIR_CONFIRM;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X')){
			_shopWindow = SHOP;
			_leftFrameCursor = 0;
		}
	}
}
void shop::repairRender(){
	IMAGEMANAGER->findAlphaImage("수리")->alphaRender(getMemDC(), 0, 0, 240);

	HFONT oldFont;
	HFONT font;
	SetBkMode(getMemDC(), TRANSPARENT);

	char str1[100];
	HFONT oldFont2;
	HFONT font2;
	char str3[30];
	SetBkMode(getMemDC(), TRANSPARENT);
	font2 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont2 = (HFONT)SelectObject(getMemDC(), font2);
	SetTextColor(getMemDC(), RGB(255, 255, 0));
	sprintf(str3, "%d", _money);
	TextOut(getMemDC(), 400, 165, str3, strlen(str3));
	SelectObject(getMemDC(), oldFont2);
	DeleteObject(font2);
	if (_playerIndex<0){
		font = CreateFont(30, 20, 0, 0, 100, 0, 0
			, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str1, "수리할 아이템이 없습니다.");
		TextOut(getMemDC(), 130, 250, str1, strlen(str1));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
	else{
		//왼쪽 프레임
		//왼쪽 프레임
		IMAGEMANAGER->findAlphaImage("현재선택위치")->alphaRender(getMemDC(), 50, 240 + _leftFrameCursor, 200);

		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);
		char str[100];
		for (int i = 0, j = 0; i < _repairItem.size(); i++){

			switch (_repairItem[i].type){
			case WEAPON:
			case ARMOR:
			case POTION:
			case RUNE:
				int temp = 250 + 100 * j - _leftFrameMoveY;
				if (temp > 150){
					IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 100, 250 + 100 * j - _leftFrameMoveY, _repairItem[i].frameX, _repairItem[i].frameY);

					//코인 이미지
					IMAGEMANAGER->findImage("코인")->render(getMemDC(), 580, 275 + 100 * j - _leftFrameMoveY);
					//금액

					font = CreateFont(30, 20, 0, 0, 100, 0, 0
						, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
					oldFont = (HFONT)SelectObject(getMemDC(), font);
					SetTextColor(getMemDC(), RGB(255, 255, 255));
					//아이템이름
					if (!_repairItem[i].seal){
						strcpy(str, _repairItem[i].name.c_str());
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					else{
						strcpy(str, "?????????????");
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					//아이템가격
					sprintf(str, "%d", (int)((float)_repairItem[_playerIndex].price * 0.2f));
					TextOut(getMemDC(), 620, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					SelectObject(getMemDC(), oldFont);
					DeleteObject(font);
				}
			}
			switch (_repairItem[i].type){
			case WEAPON:
			case ARMOR:
			case POTION:
			case RUNE:
				j++;
			}
		}

		//오른쪽 프레임
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 900, 200, _repairItem[_playerIndex].frameX, _repairItem[_playerIndex].frameY);

		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//아이템 이름
		if (!_repairItem[_playerIndex].seal){
			strcpy(str, _repairItem[_playerIndex].name.c_str());
			TextOut(getMemDC(), 1000, 230, str, strlen(str));
		}
		else{
			strcpy(str, "?????????????");
			TextOut(getMemDC(), 1000, 230, str, strlen(str));
		}

		if (_repairItem[_playerIndex].type == WEAPON){
			if (!_repairItem[_playerIndex].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _repairItem[_playerIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "공격력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d - %d", _repairItem[_playerIndex].ability.ATK, _repairItem[_playerIndex].ability.ATK + _repairItem[_playerIndex].ability.ATK / 10);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _repairItem[_playerIndex].currentCon, _repairItem[_playerIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _repairItem[_playerIndex].info.c_str());
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
				sprintf(str, "??? / ???", _repairItem[_playerIndex].currentCon, _repairItem[_playerIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_repairItem[_playerIndex].type == ARMOR){
			if (!_repairItem[_playerIndex].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _repairItem[_playerIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "방어력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d", _repairItem[_playerIndex].ability.DEF);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _repairItem[_playerIndex].currentCon, _repairItem[_playerIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _repairItem[_playerIndex].info.c_str());
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
				sprintf(str, "??? / ???", _repairItem[_playerIndex].currentCon, _repairItem[_playerIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

	}
}

void shop::analyzeInit(){
	IMAGEMANAGER->addAlphaImage("감정", "이미지/마을/상점/감정.bmp", 1600, 900, true, RGB(255, 0, 255));
	_analyzeNum = 0;
}
void shop::analyzeUpdate(){
	if (_shopWindow == ANALYZE){
		if (_analyzeItem.size() == 0){
			_analyzeItem.clear();
			//감정할 아이템 개수 구하기*
			_playerIndex = -1;
			for (int i = 0; i < 20; i++){
				if (i == 3 || i == 6){
					if (_itemCount[i].count > 0){
						_playerIndex++;
						tagItem temp;
						temp = _item->getVItem()[i];
						_analyzeItem.push_back(temp);
					}
				}
			}
		}
		if (_playerIndex >= 0){
			if (KEYMANAGER->isOnceKeyDown(VK_UP)){
				_analyzeError = false;
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
				_analyzeError = false;
			}
			if (KEYMANAGER->isOnceKeyDown('A')){
				for (int i = 0; i < 20; i++){
					if (strcmp(_analyzeItem[_itemIndex].name.c_str(), _item->getVItem()[i].name.c_str()) == 0){
						if (_itemCount[i].seal == 0){
							_analyzeError = true;
						}
					}
				}
				if (!_analyzeError )
				_shopWindow = ANALYZE_CONFIRM;
				//아이템 번호 추가
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X')){
			_shopWindow = SHOP;
			_leftFrameCursor = 0;
			_analyzeError = false;
		}
		for (int i = 0; i < _analyzeItem.size(); i++){
			if (strcmp(_analyzeItem[i].name.c_str(), "크라운 스태프") == 0){
				if (!_analyzeItem[i].seal)
					_itemCount[3].seal = 0;
			}
			if (strcmp(_analyzeItem[i].name.c_str(), "대마법사 망토") == 0){
				if (!_analyzeItem[i].seal)
					_itemCount[6].seal = 0;
			}
		}
	}
}
void shop::analyzeRender(){
	IMAGEMANAGER->findAlphaImage("감정")->alphaRender(getMemDC(), 0, 0, 240);
	HFONT oldFont2;
	HFONT font2;
	char str3[30];
	SetBkMode(getMemDC(), TRANSPARENT);
	font2 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont2 = (HFONT)SelectObject(getMemDC(), font2);
	SetTextColor(getMemDC(), RGB(255, 255, 0));
	sprintf(str3, "%d", _money);
	TextOut(getMemDC(), 400, 165, str3, strlen(str3));
	SelectObject(getMemDC(), oldFont2);
	DeleteObject(font2);
	HFONT oldFont;
	HFONT font;
	SetBkMode(getMemDC(), TRANSPARENT);

	char str1[100];

	if (_playerIndex < 0){
		font = CreateFont(30, 20, 0, 0, 100, 0, 0
			, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str1, "감정할 아이템이 없습니다.");
		TextOut(getMemDC(), 130, 250, str1, strlen(str1));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
	else{
		IMAGEMANAGER->findAlphaImage("현재선택위치")->alphaRender(getMemDC(), 50, 240 + _leftFrameCursor, 200);

		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);
		char str[100];
		for (int i = 0, j = 0; i < _analyzeItem.size(); i++){

			switch (_analyzeItem[i].type){
			case WEAPON:
			case ARMOR:
				int temp = 250 + 100 * j - _leftFrameMoveY;
				if (temp > 150){
					IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 100, 250 + 100 * j - _leftFrameMoveY, _analyzeItem[i].frameX, _analyzeItem[i].frameY);

					//코인 이미지
					IMAGEMANAGER->findImage("코인")->render(getMemDC(), 580, 275 + 100 * j - _leftFrameMoveY);
					//금액

					font = CreateFont(30, 20, 0, 0, 100, 0, 0
						, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
					oldFont = (HFONT)SelectObject(getMemDC(), font);
					SetTextColor(getMemDC(), RGB(255, 255, 255));
					//아이템이름
					if (!_analyzeItem[i].seal){
						strcpy(str, _analyzeItem[i].name.c_str());
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					else{
						strcpy(str, "?????????????");
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					//아이템가격
					float price = (float)_analyzeItem[i].price*0.1;
					sprintf(str, "%d", (int)price);
					TextOut(getMemDC(), 620, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					SelectObject(getMemDC(), oldFont);
					DeleteObject(font);
				}
			}
			switch (_analyzeItem[i].type){
			case WEAPON:
			case ARMOR:
			case POTION:
			case RUNE:
				j++;
			}
		}

		//오른쪽 프레임
		IMAGEMANAGER->findImage("아이템")->frameRender(getMemDC(), 900, 200, _analyzeItem[_itemIndex].frameX, _analyzeItem[_itemIndex].frameY);

		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//아이템 이름
		if (!_analyzeItem[_itemIndex].seal){
			strcpy(str, _analyzeItem[_itemIndex].name.c_str());
			TextOut(getMemDC(), 1000, 230, str, strlen(str));
		}
		else{
			strcpy(str, "?????????????");
			TextOut(getMemDC(), 1000, 230, str, strlen(str));
		}

		if (_analyzeItem[_itemIndex].type == WEAPON){
			if (!_analyzeItem[_itemIndex].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _analyzeItem[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "공격력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d - %d", _analyzeItem[_itemIndex].ability.ATK, _analyzeItem[_itemIndex].ability.ATK + _analyzeItem[_itemIndex].ability.ATK / 10);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _analyzeItem[_itemIndex].currentCon, _analyzeItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _analyzeItem[_itemIndex].info.c_str());
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
				sprintf(str, "??? / ???", _analyzeItem[_itemIndex].currentCon, _analyzeItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_analyzeItem[_itemIndex].type == ARMOR){
			if (!_analyzeItem[_itemIndex].seal){
				//아이템 랭크
				sprintf(str, "랭크");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _analyzeItem[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//아이템 공격력
				sprintf(str, "방어력");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d", _analyzeItem[_itemIndex].ability.DEF);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//아이템 내구도
				sprintf(str, "내구도");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _analyzeItem[_itemIndex].currentCon, _analyzeItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _analyzeItem[_itemIndex].info.c_str());
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
				sprintf(str, "??? / ???", _analyzeItem[_itemIndex].currentCon, _analyzeItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//아이템 설명
				sprintf(str, "효과");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "아이템 감정이 필요합니다");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}
	}

	if (_moneyError){
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("금액부족")->render(getMemDC(), 0, 600);
	}

	if (_analyzeError){
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("감정템부족")->render(getMemDC(), 0, 600);
	}
}

void shop::dataSave(){
	char str1[50];
	INIDATA->addData("Position", "X", INIDATA->loadDataString("PlayerData","Position","X").c_str());
	INIDATA->addData("Position", "Y", INIDATA->loadDataString("PlayerData", "Position", "Y").c_str());
	INIDATA->addData("Position", "그림자X", INIDATA->loadDataString("PlayerData", "Position", "그림자X").c_str());
	INIDATA->addData("Position", "그림자Y", INIDATA->loadDataString("PlayerData", "Position", "그림자Y").c_str());
	INIDATA->addData("Position", "절대좌표X", INIDATA->loadDataString("PlayerData", "Position", "절대좌표X").c_str());
	INIDATA->addData("Position", "절대좌표Y", INIDATA->loadDataString("PlayerData", "Position", "절대좌표Y").c_str());
	INIDATA->addData("Position", "성X", INIDATA->loadDataString("PlayerData", "Position", "성X").c_str());
	INIDATA->addData("Position", "성Y", INIDATA->loadDataString("PlayerData", "Position", "성Y").c_str());
	INIDATA->addData("Position", "마을1X", INIDATA->loadDataString("PlayerData", "Position", "마을1X").c_str());
	INIDATA->addData("Position", "마을1Y", INIDATA->loadDataString("PlayerData", "Position", "마을1Y").c_str());
	INIDATA->addData("Position", "마을2X", INIDATA->loadDataString("PlayerData", "Position", "마을2X").c_str());
	INIDATA->addData("Position", "마을2Y", INIDATA->loadDataString("PlayerData", "Position", "마을2Y").c_str());
	INIDATA->addData("Position", "마을3X", INIDATA->loadDataString("PlayerData", "Position", "마을3X").c_str());
	INIDATA->addData("Position", "마을3Y", INIDATA->loadDataString("PlayerData", "Position", "마을3Y").c_str());
	INIDATA->addData("Position", "마을4X", INIDATA->loadDataString("PlayerData", "Position", "마을4X").c_str());
	INIDATA->addData("Position", "마을4Y", INIDATA->loadDataString("PlayerData", "Position", "마을4Y").c_str());
	INIDATA->addData("Position", "마을5X", INIDATA->loadDataString("PlayerData", "Position", "마을5X").c_str());
	INIDATA->addData("Position", "마을5Y", INIDATA->loadDataString("PlayerData", "Position", "마을5Y").c_str());
	INIDATA->addData("Position", "루카인X", INIDATA->loadDataString("PlayerData", "Position", "루카인X").c_str());

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
	char str3[30];
	sprintf(str3, "%d", _money);
	INIDATA->addData("State", "Money", str3);

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


	char str2[30];
	sprintf(str2, "%d", _itemCount[0].count);
	INIDATA->addData("마카로프의 스태프", "num", str2);
	sprintf(str2, "%d", _itemCount[0].currentCon);
	INIDATA->addData("마카로프의 스태프", "currentCon", str2);
	sprintf(str2, "%d", _itemCount[1].count);
	INIDATA->addData("문라이트 스태프", "num", str2);
	sprintf(str2, "%d", _itemCount[2].count);
	INIDATA->addData("이그니 스태프", "num", str2);
	sprintf(str2, "%d", _itemCount[3].count);
	INIDATA->addData("크라운 스태프", "num", str2);
	sprintf(str2, "%d", _itemCount[3].seal);
	INIDATA->addData("크라운 스태프", "seal", str2);
	sprintf(str2, "%d", _itemCount[4].count);
	INIDATA->addData("붉은 망토", "num", str2);
	sprintf(str2, "%d", _itemCount[5].count);
	INIDATA->addData("마법사 망토", "num", str2);
	sprintf(str2, "%d", _itemCount[6].count);
	INIDATA->addData("대마법사 망토", "num", str2);
	sprintf(str2, "%d", _itemCount[6].seal);
	INIDATA->addData("대마법사 망토", "seal", str2);
	sprintf(str2, "%d", _itemCount[7].count);
	INIDATA->addData("가죽 장갑", "num", str2);
	sprintf(str2, "%d", _itemCount[8].count);
	INIDATA->addData("요정 장갑", "num", str2);
	sprintf(str2, "%d", _itemCount[9].count);
	INIDATA->addData("가죽 신발", "num", str2);
	sprintf(str2, "%d", _itemCount[10].count);
	INIDATA->addData("마법사 신발", "num", str2);
	sprintf(str2, "%d", _itemCount[11].count);
	INIDATA->addData("에메랄드 귀거리", "num", str2);
	sprintf(str2, "%d", _itemCount[12].count);
	INIDATA->addData("요정눈물 귀거리", "num", str2);
	sprintf(str2, "%d", _itemCount[13].count);
	INIDATA->addData("A룬", "num", str2);
	sprintf(str2, "%d", _itemCount[14].count);
	INIDATA->addData("B룬", "num", str2);
	sprintf(str2, "%d", _itemCount[15].count);
	INIDATA->addData("C룬", "num", str2);
	sprintf(str2, "%d", _itemCount[16].count);
	INIDATA->addData("D룬", "num", str2);
	sprintf(str2, "%d", _itemCount[17].count);
	INIDATA->addData("E룬", "num", str2);
	sprintf(str2, "%d", _itemCount[18].count);
	INIDATA->addData("F룬", "num", str2);
	sprintf(str2, "%d", _itemCount[19].count);
	INIDATA->addData("요정의 물약", "num", str2);

	str = INIDATA->loadDataString("PlayerData", "아이스 프리즌의 서", "num");
	INIDATA->addData("아이스 프리즌의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "프로텍션의 서", "num");
	INIDATA->addData("프로텍션의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "그래비티의 서", "num");
	INIDATA->addData("그래비티의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "썬더 클라우드의 서", "num");
	INIDATA->addData("썬더 클라우드의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "록 프레스의 서", "num");
	INIDATA->addData("록 프레스의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "블리자드의 서", "num");
	INIDATA->addData("블리자드의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "크리에이트 푸드의 서", "num");
	INIDATA->addData("크리에이트 푸드의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "커스의 서", "num");
	INIDATA->addData("커스의 서", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "페트리피케이션의 서", "num");
	INIDATA->addData("페트리피케이션의 서", "num", str.c_str());

	//탈리즈만
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
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "white").c_str();
	INIDATA->addData("Talizman", "white", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "black").c_str();
	INIDATA->addData("Talizman", "black", str.c_str());

	INIDATA->iniSave("PlayerData");
}