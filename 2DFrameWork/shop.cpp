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
	_itemCount[0].count = INIDATA->loadDataInterger("PlayerData", "��ī������ ������", "num");
	_itemCount[0].seal = 0;
	_itemCount[0].currentCon = INIDATA->loadDataInterger("PlayerData", "��ī������ ������", "currentCon");
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "��ī������ ������") == 0){
			_itemCount[0].maxCon = _item->getVItem()[i].maxCon;
		}
	}
	//_itemCount[0].maxCon = 
	_itemCount[1].count = INIDATA->loadDataInterger("PlayerData", "������Ʈ ������", "num");
	_itemCount[1].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "������Ʈ ������") == 0) _itemCount[1].maxCon = _itemCount[1].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[2].count = INIDATA->loadDataInterger("PlayerData", "�̱״� ������", "num");
	_itemCount[2].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "�̱״� ������") == 0) _itemCount[2].maxCon = _itemCount[2].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[3].count = INIDATA->loadDataInterger("PlayerData", "ũ��� ������", "num");
	_itemCount[3].seal = INIDATA->loadDataInterger("PlayerData", "ũ��� ������", "seal");
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "ũ��� ������") == 0) _itemCount[3].maxCon = _itemCount[3].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[4].count = INIDATA->loadDataInterger("PlayerData", "���� ����", "num");
	_itemCount[4].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "���� ����") == 0) _itemCount[4].maxCon = _itemCount[4].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[5].count = INIDATA->loadDataInterger("PlayerData", "������ ����", "num");
	_itemCount[5].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "������ ����") == 0) _itemCount[5].maxCon = _itemCount[5].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[6].count = INIDATA->loadDataInterger("PlayerData", "�븶���� ����", "num");
	_itemCount[6].seal = INIDATA->loadDataInterger("PlayerData", "�븶���� ����", "seal");
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "�븶���� ����") == 0) _itemCount[6].maxCon = _itemCount[6].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[7].count = INIDATA->loadDataInterger("PlayerData", "���� �尩", "num");
	_itemCount[7].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "���� �尩") == 0) _itemCount[7].maxCon = _itemCount[7].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[8].count = INIDATA->loadDataInterger("PlayerData", "���� �尩", "num");
	_itemCount[8].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "���� �尩") == 0) _itemCount[8].maxCon = _itemCount[8].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[9].count = INIDATA->loadDataInterger("PlayerData", "���� �Ź�", "num");
	_itemCount[9].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "���� �Ź�") == 0) _itemCount[9].maxCon = _itemCount[9].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[10].count= INIDATA->loadDataInterger("PlayerData", "������ �Ź�", "num");
	_itemCount[10].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "������ �Ź�") == 0) _itemCount[10].maxCon = _itemCount[10].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[11].count= INIDATA->loadDataInterger("PlayerData", "���޶��� �ͰŸ�", "num");
	_itemCount[11].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "���޶��� �ͰŸ�") == 0) _itemCount[11].maxCon = _itemCount[11].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[12].count= INIDATA->loadDataInterger("PlayerData", "�������� �ͰŸ�", "num");
	_itemCount[12].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "�������� �ͰŸ�") == 0) _itemCount[12].maxCon = _itemCount[12].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[13].count= INIDATA->loadDataInterger("PlayerData", "A��", "num");
	_itemCount[13].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "A��") == 0) _itemCount[13].maxCon = _itemCount[13].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[14].count= INIDATA->loadDataInterger("PlayerData", "B��", "num");
	_itemCount[14].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "B��") == 0) _itemCount[14].maxCon = _itemCount[14].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[15].count= INIDATA->loadDataInterger("PlayerData", "C��", "num");
	_itemCount[15].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "C��") == 0) _itemCount[15].maxCon = _itemCount[15].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[16].count= INIDATA->loadDataInterger("PlayerData", "D��", "num");
	_itemCount[16].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "D��") == 0) _itemCount[16].maxCon = _itemCount[16].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[17].count= INIDATA->loadDataInterger("PlayerData", "E��", "num");
	_itemCount[17].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "E��") == 0) _itemCount[17].maxCon = _itemCount[17].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[18].count= INIDATA->loadDataInterger("PlayerData", "F��", "num");
	_itemCount[18].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "F��") == 0) _itemCount[18].maxCon = _itemCount[18].currentCon = _item->getVItem()[i].maxCon;
	}
	_itemCount[19].count=INIDATA->loadDataInterger("PlayerData", "������ ����", "num");
	_itemCount[19].seal = 0;
	for (int i = 0; i < _item->getVItem().size(); i++){
		if (strcmp(_item->getVItem()[i].name.c_str(), "������ ����") == 0) _itemCount[19].maxCon = _itemCount[19].currentCon = _item->getVItem()[i].maxCon;
	}
	_money = INIDATA->loadDataInterger("PlayerData", "State", "Money");
	_moneyError = false;
	IMAGEMANAGER->addAlphaImage("�ݾ׺���", "�̹���/����/����/�ݾ׺���.bmp", 1600, 113, false, RGB(0, 0, 0));
	IMAGEMANAGER->addAlphaImage("�����ۺ���", "�̹���/����/����/�����ۺ���.bmp", 1600, 113, false, RGB(0, 0, 0));
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
	

	//IMAGEMANAGER->addFrameImage("�������Ǿ�", "�̹���/����/����/�������Ǿ�.bmp", 16000, 4500, 10, 5, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("������ũ", "�̹���/����/����/����������ũ.bmp", 293, 215, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("���Լ�����1", "�̹���/����/����/���Լ�����1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("���Լ�����2", "�̹���/����/����/���Լ�����2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("�Ű�������1", "�̹���/����/����/�Ű�������1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("�Ű�������2", "�̹���/����/����/�Ű�������2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����������1", "�̹���/����/����/����������1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����������2", "�̹���/����/����/����������2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����������1", "�̹���/����/����/����������1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("����������2", "�̹���/����/����/����������2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("�����⼱����1", "�̹���/����/�����⼱����1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("�����⼱����2", "�̹���/����/�����⼱����2.bmp", 467, 80, true, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("����", "����/����.mp3", true, true);
	SOUNDMANAGER->play("����", 0.1f);
	SOUNDMANAGER->addSound("����", "����/����/����.wav", false, false);
	SOUNDMANAGER->addSound("�ȱ�", "����/����/�ȱ�.wav", false, false);
	SOUNDMANAGER->addSound("����", "����/����/����.wav", false, false);
	SOUNDMANAGER->addSound("����", "����/����/����.wav", false, false);

	KEYANIMANAGER->addDefaultFrameAnimation("�������Ǿ�", "�������Ǿ�", 30, true, true);
	_npcMove = KEYANIMANAGER->findAnimation("�������Ǿ�");
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
				SCENEMANAGER->changeScene("������");
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
	IMAGEMANAGER->findImage("�������Ǿ�")->aniRender(getMemDC(), 0, 0, _npcMove);
	IMAGEMANAGER->findImage("������ũ")->render(getMemDC(), 80, 55);

	switch (_shopAction){
	case ITEM_BUY:
		IMAGEMANAGER->findImage("���Լ�����2")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("�Ű�������1")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("����������1")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("����������1")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("�����⼱����1")->render(getMemDC(), -10, 650);
		break;
	case ITEM_SELL:
		IMAGEMANAGER->findImage("���Լ�����1")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("�Ű�������2")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("����������1")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("����������1")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("�����⼱����1")->render(getMemDC(), -10, 650);
		break;
	case ITEM_REPAIR:
		IMAGEMANAGER->findImage("���Լ�����1")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("�Ű�������1")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("����������2")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("����������1")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("�����⼱����1")->render(getMemDC(), -10, 650);
		break;
	case ITEM_ANALYZE:
		IMAGEMANAGER->findImage("���Լ�����1")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("�Ű�������1")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("����������1")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("����������2")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("�����⼱����1")->render(getMemDC(), -10, 650);
		break;
	case SHOP_EXIT:
		IMAGEMANAGER->findImage("���Լ�����1")->render(getMemDC(), -10, 250);
		IMAGEMANAGER->findImage("�Ű�������1")->render(getMemDC(), -10, 350);
		IMAGEMANAGER->findImage("����������1")->render(getMemDC(), -10, 450);
		IMAGEMANAGER->findImage("����������1")->render(getMemDC(), -10, 550);
		IMAGEMANAGER->findImage("�����⼱����2")->render(getMemDC(), -10, 650);
		break;
	}
}

void shop::confirmInit(){
	IMAGEMANAGER->addAlphaImage("���ó��2", "�̹���/����/���/���ó��.bmp", 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("��ȭ����", "�̹���/talkBar.bmp", 1600, 118, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("no", "�̹���/no.bmp", 184, 185, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yes", "�̹���/yes.bmp", 185, 185, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("no_check", "�̹���/no_check.bmp", 236, 234, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("yes_check", "�̹���/yes_check.bmp", 234, 235, true, RGB(255, 0, 255));

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
				if (strcmp(_item->getVItem()[_itemIndex].name.c_str(), "ũ��� ������") == 0 ||
					strcmp(_item->getVItem()[_itemIndex].name.c_str(), "�븶���� ����") == 0){
					_itemCount[_itemIndex].seal = 1;
				}
				else{
					_itemCount[_itemIndex].seal = 0;
				}
				dataSave();
				_shopWindow = BUY;
				SOUNDMANAGER->play("����", 0.3F);
			}
			else{
				//���� ���
				_bConfirm = true;
				_shopWindow = BUY;
			}
			
			break;
		case ITEM_SELL:
			if (_bConfirm){
				//������ �ȱ�
				for (int i = 0; i < 20; i++){
					if (strcmp(_sellItem[_itemIndex].name.c_str(), _item->getVItem()[i].name.c_str())==0){
						_money += _item->getVItem()[i].price*0.8;
						_itemCount[i].count--;
					}
				}
				dataSave();
				_playerIndex--;
				_shopWindow = SELL;
				SOUNDMANAGER->play("�ȱ�", 0.3F);
			}
			else{
				//�ȱ� ���
				_bConfirm = true;
				_shopWindow = SELL;
			}
			
			break;
		case ITEM_REPAIR:
			if (_bConfirm){
				//������ ����
				_repairItem[_playerIndex].currentCon = _repairItem[_playerIndex].maxCon;
				if (strcmp(_repairItem[_playerIndex].name.c_str(), "��ī������ ������") == 0){
					_itemCount[0].currentCon = _itemCount[0].maxCon;
				}


				_money -= _repairItem[_playerIndex].price*0.2f;
				dataSave();
				_playerIndex--;
				_shopWindow = REPAIR;
				SOUNDMANAGER->play("����", 0.3F);
			}
			else{
				//���� ���
				_bConfirm = true;
			}
			_shopWindow = REPAIR;
			break;
		case ITEM_ANALYZE:
			if (_bConfirm){
				//������ ����
				_analyzeItem[_itemIndex].seal = false;
				_money -= _analyzeItem[_itemIndex].price*0.1f;
				dataSave();
				_playerIndex--;
				_shopWindow = SELL;
				SOUNDMANAGER->play("����", 0.3F);
			}
			else{
				//���� ���
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
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		
			IMAGEMANAGER->findAlphaImage("��ȭ����")->render(getMemDC(), 0, 300);
			if (_bConfirm){
				IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
				IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
			}
			else{
				IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
				IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
			}
			font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
			oldFont = (HFONT)SelectObject(getMemDC(), font);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			strcpy(str1, _item->getVItem()[_itemIndex].name.c_str());
			sprintf(str2, " �������� %d�� ��ðڽ��ϱ�?", _item->getVItem()[_itemIndex].price);
			strcat(str1, str2);
			DrawText(getMemDC(), str1, strlen(str1), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font);
		

		
		break;

	case SELL_CONFIRM:
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("��ȭ����")->render(getMemDC(), 0, 300);
		if (_bConfirm){
			IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
			IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
		}
		else{
			IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
			IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
		}

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		for (int i = 0; i < 20; i++){
			if (strcmp(_sellItem[_itemIndex].name.c_str(), _item->getVItem()[i].name.c_str()) == 0){
				strcpy(str1, _sellItem[_itemIndex].name.c_str());
				sprintf(str2, " �������� %d�� �Ľðڽ��ϱ�?", _sellItem[_itemIndex].price / 10 * 8);
				strcat(str1, str2);
			}
		}
		
		DrawText(getMemDC(), str1, strlen(str1), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;

	case REPAIR_CONFIRM:
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("��ȭ����")->render(getMemDC(), 0, 300);
		if (_bConfirm){
			IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
			IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
		}
		else{
			IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
			IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
		}

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		strcpy(str1, _repairItem[_playerIndex].name.c_str());
		
		sprintf(str2, " �������� %d�� �����Ͻðڽ��ϱ�?", (int)((float)_repairItem[_playerIndex].price * 0.2f));
		strcat(str1, str2);
		DrawText(getMemDC(), str1, strlen(str1), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	case ANALYZE_CONFIRM:
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("��ȭ����")->render(getMemDC(), 0, 300);
		if (_bConfirm){
			IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
			IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
		}
		else{
			IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
			IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
		}



		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		int price1 = (float)_analyzeItem[_itemIndex].price*0.1f;
		sprintf(str1, " %d�� �����Ͻðڽ��ϱ�?", price1);
		

		DrawText(getMemDC(), str1, strlen(str1), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	}
}
void shop::buyInit(){
	IMAGEMANAGER->addAlphaImage("����", "�̹���/����/����/����.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("����", "�̹���/����/����/����.bmp", 34, 41, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("���缱����ġ", "�̹���/����/����/���缱����ġ.bmp", 750, 110, true, RGB(255, 0, 255));
	_itemIndex = 0;

	//�������� �Ĵ� ������ ����
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
	IMAGEMANAGER->findAlphaImage("����")->alphaRender(getMemDC(), 0, 0, 240);

	//���� ������
	IMAGEMANAGER->findAlphaImage("���缱����ġ")->alphaRender(getMemDC(), 50, 240 + _leftFrameCursor, 200);
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
				IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 100, 250 + 100 * j - _leftFrameMoveY, _item->getVItem()[i].frameX, _item->getVItem()[i].frameY);

				//���� �̹���
				IMAGEMANAGER->findImage("����")->render(getMemDC(), 580, 275 + 100 * j - _leftFrameMoveY);
				//�ݾ�

				font = CreateFont(30, 20, 0, 0, 100, 0, 0
					, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), font);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				//�������̸�
				if (!_item->getVItem()[i].seal){
					strcpy(str, _item->getVItem()[i].name.c_str());
					TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
				}
				else{
					strcpy(str, "?????????????");
					TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
				}
				//�����۰���
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

	//������ ������
	IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 900, 200, _item->getVItem()[_itemIndex].frameX, _item->getVItem()[_itemIndex].frameY);

	font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont = (HFONT)SelectObject(getMemDC(), font);
	SetTextColor(getMemDC(), RGB(255, 255, 255));
	//������ �̸�
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
			//������ ��ũ
			sprintf(str, "��ũ");
			TextOut(getMemDC(), 900, 350, str, strlen(str));
			strcpy(str, _item->getVItem()[_itemIndex].rank);
			TextOut(getMemDC(), 1300, 350, str, strlen(str));
			//������ ���ݷ�
			sprintf(str, "���ݷ�");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			sprintf(str, "%d - %d", _item->getVItem()[_itemIndex].ability.ATK, _item->getVItem()[_itemIndex].ability.ATK + _item->getVItem()[_itemIndex].ability.ATK / 10);
			TextOut(getMemDC(), 1300, 450, str, strlen(str));
			//������ ������
			sprintf(str, "������");
			TextOut(getMemDC(), 900, 550, str, strlen(str));
			sprintf(str, "%d / %d", _item->getVItem()[_itemIndex].currentCon, _item->getVItem()[_itemIndex].maxCon);
			TextOut(getMemDC(), 1300, 550, str, strlen(str));
			//������ ����
			sprintf(str, "ȿ��");
			TextOut(getMemDC(), 900, 650, str, strlen(str));
			strcpy(str, _item->getVItem()[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 750, str, strlen(str));
		}
		else{
			//������ ��ũ
			sprintf(str, "��ũ");
			TextOut(getMemDC(), 900, 350, str, strlen(str));
			strcpy(str, "???");
			TextOut(getMemDC(), 1300, 350, str, strlen(str));
			//������ ���ݷ�
			sprintf(str, "���ݷ�");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			sprintf(str, "??? - ???");
			TextOut(getMemDC(), 1300, 450, str, strlen(str));
			//������ ������
			sprintf(str, "������");
			TextOut(getMemDC(), 900, 550, str, strlen(str));
			sprintf(str, "??? / ???", _item->getVItem()[_itemIndex].currentCon, _item->getVItem()[_itemIndex].maxCon);
			TextOut(getMemDC(), 1300, 550, str, strlen(str));
			//������ ����
			sprintf(str, "ȿ��");
			TextOut(getMemDC(), 900, 650, str, strlen(str));
			sprintf(str, "������ ������ �ʿ��մϴ�");
			TextOut(getMemDC(), 900, 750, str, strlen(str));
		}
	}

	if (_item->getVItem()[_itemIndex].type == ARMOR){
		if (!_item->getVItem()[_itemIndex].seal){
			//������ ��ũ
			sprintf(str, "��ũ");
			TextOut(getMemDC(), 900, 350, str, strlen(str));
			strcpy(str, _item->getVItem()[_itemIndex].rank);
			TextOut(getMemDC(), 1300, 350, str, strlen(str));
			//������ ���ݷ�
			sprintf(str, "����");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			sprintf(str, "%d", _item->getVItem()[_itemIndex].ability.DEF);
			TextOut(getMemDC(), 1300, 450, str, strlen(str));
			//������ ������
			sprintf(str, "������");
			TextOut(getMemDC(), 900, 550, str, strlen(str));
			sprintf(str, "%d / %d", _item->getVItem()[_itemIndex].currentCon, _item->getVItem()[_itemIndex].maxCon);
			TextOut(getMemDC(), 1300, 550, str, strlen(str));
			//������ ����
			sprintf(str, "ȿ��");
			TextOut(getMemDC(), 900, 650, str, strlen(str));
			strcpy(str, _item->getVItem()[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 750, str, strlen(str));
		}
		else{
			//������ ��ũ
			sprintf(str, "��ũ");
			TextOut(getMemDC(), 900, 350, str, strlen(str));
			strcpy(str, "???");
			TextOut(getMemDC(), 1300, 350, str, strlen(str));
			//������ ���ݷ�
			sprintf(str, "����");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			sprintf(str, "???");
			TextOut(getMemDC(), 1300, 450, str, strlen(str));
			//������ ������
			sprintf(str, "������");
			TextOut(getMemDC(), 900, 550, str, strlen(str));
			sprintf(str, "??? / ???", _item->getVItem()[_itemIndex].currentCon, _item->getVItem()[_itemIndex].maxCon);
			TextOut(getMemDC(), 1300, 550, str, strlen(str));
			//������ ����
			sprintf(str, "ȿ��");
			TextOut(getMemDC(), 900, 650, str, strlen(str));
			sprintf(str, "������ ������ �ʿ��մϴ�");
			TextOut(getMemDC(), 900, 750, str, strlen(str));
		}
	}

	if (_item->getVItem()[_itemIndex].type == RUNE){
		//������ ����
		sprintf(str, "ȿ��");
		TextOut(getMemDC(), 900, 450, str, strlen(str));
		strcpy(str, _item->getVItem()[_itemIndex].info.c_str());
		TextOut(getMemDC(), 900, 550, str, strlen(str));
	}

	if (_item->getVItem()[_itemIndex].type == POTION){
		//������ ����
		sprintf(str, "ȿ��");
		TextOut(getMemDC(), 900, 450, str, strlen(str));
		strcpy(str, _item->getVItem()[_itemIndex].info.c_str());
		TextOut(getMemDC(), 900, 550, str, strlen(str));
	}
	SelectObject(getMemDC(), oldFont);

	DeleteObject(font);

	if (_moneyError){
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("�ݾ׺���")->render(getMemDC(), 0, 600);
	}
}

void shop::sellInit(){
	IMAGEMANAGER->addAlphaImage("�Ű�", "�̹���/����/����/�Ű�.bmp", 1600, 900, true, RGB(255, 0, 255));

	_playerIndex = -1;
}

void shop::sellUpdate(){
	//�÷��̾ �������� �������ִ��� Ȯ��
	
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
				//������ ��ȣ �߰�
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X')){
			_shopWindow = SHOP;
			_leftFrameCursor = 0;
		}
	}
}

void shop::sellRender(){
	IMAGEMANAGER->findAlphaImage("�Ű�")->alphaRender(getMemDC(), 0, 0, 240);

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
		sprintf(str1, "�������� ������ ���� �ʽ��ϴ�.");
		TextOut(getMemDC(), 130, 250, str1, strlen(str1));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
	else{
		//���� ������
		IMAGEMANAGER->findAlphaImage("���缱����ġ")->alphaRender(getMemDC(), 50, 240 + _leftFrameCursor, 200);
		

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
					IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 100, 250 + 100 * j - _leftFrameMoveY, _sellItem[i].frameX, _sellItem[i].frameY);

					//���� �̹���
					IMAGEMANAGER->findImage("����")->render(getMemDC(), 580, 275 + 100 * j - _leftFrameMoveY);
					//�ݾ�

					font = CreateFont(30, 20, 0, 0, 100, 0, 0
						, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
					oldFont = (HFONT)SelectObject(getMemDC(), font);
					SetTextColor(getMemDC(), RGB(255, 255, 255));
					//�������̸�
					if (!_sellItem[i].seal){
						strcpy(str, _sellItem[i].name.c_str());
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					else{
						strcpy(str, "?????????????");
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					//�����۰���
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

		//������ ������
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 900, 200, _sellItem[_itemIndex].frameX, _sellItem[_itemIndex].frameY);

		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//������ �̸�
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
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _sellItem[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d - %d", _sellItem[_itemIndex].ability.ATK, _sellItem[_itemIndex].ability.ATK + _sellItem[_itemIndex].ability.ATK / 10);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _sellItem[_itemIndex].currentCon, _sellItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _sellItem[_itemIndex].info.c_str());
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
			else{
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "??? - ???");
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "??? / ???", _sellItem[_itemIndex].currentCon, _sellItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_sellItem[_itemIndex].type == ARMOR){
			if (!_sellItem[_itemIndex].seal){
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _sellItem[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d", _sellItem[_itemIndex].ability.DEF);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _sellItem[_itemIndex].currentCon, _sellItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _sellItem[_itemIndex].info.c_str());
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
			else{
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "???");
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "??? / ???", _sellItem[_itemIndex].currentCon, _sellItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_sellItem[_itemIndex].type == RUNE){
			//������ ����
			sprintf(str, "ȿ��");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			strcpy(str, _sellItem[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 550, str, strlen(str));
		}

		if (_sellItem[_itemIndex].type == POTION){
			//������ ����
			sprintf(str, "ȿ��");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			strcpy(str, _sellItem[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 550, str, strlen(str));
		}
	}
}

void shop::repairInit(){
	IMAGEMANAGER->addAlphaImage("����", "�̹���/����/����/����.bmp", 1600, 900, true, RGB(255, 0, 255));
	_repairNum = 0;
}
void shop::repairUpdate(){
	if (_shopWindow == REPAIR){
		//�÷��̾ �������� �������ִ��� Ȯ��
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
	IMAGEMANAGER->findAlphaImage("����")->alphaRender(getMemDC(), 0, 0, 240);

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
		sprintf(str1, "������ �������� �����ϴ�.");
		TextOut(getMemDC(), 130, 250, str1, strlen(str1));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
	else{
		//���� ������
		//���� ������
		IMAGEMANAGER->findAlphaImage("���缱����ġ")->alphaRender(getMemDC(), 50, 240 + _leftFrameCursor, 200);

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
					IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 100, 250 + 100 * j - _leftFrameMoveY, _repairItem[i].frameX, _repairItem[i].frameY);

					//���� �̹���
					IMAGEMANAGER->findImage("����")->render(getMemDC(), 580, 275 + 100 * j - _leftFrameMoveY);
					//�ݾ�

					font = CreateFont(30, 20, 0, 0, 100, 0, 0
						, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
					oldFont = (HFONT)SelectObject(getMemDC(), font);
					SetTextColor(getMemDC(), RGB(255, 255, 255));
					//�������̸�
					if (!_repairItem[i].seal){
						strcpy(str, _repairItem[i].name.c_str());
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					else{
						strcpy(str, "?????????????");
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					//�����۰���
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

		//������ ������
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 900, 200, _repairItem[_playerIndex].frameX, _repairItem[_playerIndex].frameY);

		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//������ �̸�
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
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _repairItem[_playerIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d - %d", _repairItem[_playerIndex].ability.ATK, _repairItem[_playerIndex].ability.ATK + _repairItem[_playerIndex].ability.ATK / 10);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _repairItem[_playerIndex].currentCon, _repairItem[_playerIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _repairItem[_playerIndex].info.c_str());
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
			else{
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "??? - ???");
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "??? / ???", _repairItem[_playerIndex].currentCon, _repairItem[_playerIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_repairItem[_playerIndex].type == ARMOR){
			if (!_repairItem[_playerIndex].seal){
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _repairItem[_playerIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d", _repairItem[_playerIndex].ability.DEF);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _repairItem[_playerIndex].currentCon, _repairItem[_playerIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _repairItem[_playerIndex].info.c_str());
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
			else{
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "???");
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "??? / ???", _repairItem[_playerIndex].currentCon, _repairItem[_playerIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

	}
}

void shop::analyzeInit(){
	IMAGEMANAGER->addAlphaImage("����", "�̹���/����/����/����.bmp", 1600, 900, true, RGB(255, 0, 255));
	_analyzeNum = 0;
}
void shop::analyzeUpdate(){
	if (_shopWindow == ANALYZE){
		if (_analyzeItem.size() == 0){
			_analyzeItem.clear();
			//������ ������ ���� ���ϱ�*
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
				//������ ��ȣ �߰�
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X')){
			_shopWindow = SHOP;
			_leftFrameCursor = 0;
			_analyzeError = false;
		}
		for (int i = 0; i < _analyzeItem.size(); i++){
			if (strcmp(_analyzeItem[i].name.c_str(), "ũ��� ������") == 0){
				if (!_analyzeItem[i].seal)
					_itemCount[3].seal = 0;
			}
			if (strcmp(_analyzeItem[i].name.c_str(), "�븶���� ����") == 0){
				if (!_analyzeItem[i].seal)
					_itemCount[6].seal = 0;
			}
		}
	}
}
void shop::analyzeRender(){
	IMAGEMANAGER->findAlphaImage("����")->alphaRender(getMemDC(), 0, 0, 240);
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
		sprintf(str1, "������ �������� �����ϴ�.");
		TextOut(getMemDC(), 130, 250, str1, strlen(str1));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}
	else{
		IMAGEMANAGER->findAlphaImage("���缱����ġ")->alphaRender(getMemDC(), 50, 240 + _leftFrameCursor, 200);

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
					IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 100, 250 + 100 * j - _leftFrameMoveY, _analyzeItem[i].frameX, _analyzeItem[i].frameY);

					//���� �̹���
					IMAGEMANAGER->findImage("����")->render(getMemDC(), 580, 275 + 100 * j - _leftFrameMoveY);
					//�ݾ�

					font = CreateFont(30, 20, 0, 0, 100, 0, 0
						, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
					oldFont = (HFONT)SelectObject(getMemDC(), font);
					SetTextColor(getMemDC(), RGB(255, 255, 255));
					//�������̸�
					if (!_analyzeItem[i].seal){
						strcpy(str, _analyzeItem[i].name.c_str());
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					else{
						strcpy(str, "?????????????");
						TextOut(getMemDC(), 200, 280 + 100 * j - _leftFrameMoveY, str, strlen(str));
					}
					//�����۰���
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

		//������ ������
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 900, 200, _analyzeItem[_itemIndex].frameX, _analyzeItem[_itemIndex].frameY);

		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//������ �̸�
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
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _analyzeItem[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d - %d", _analyzeItem[_itemIndex].ability.ATK, _analyzeItem[_itemIndex].ability.ATK + _analyzeItem[_itemIndex].ability.ATK / 10);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _analyzeItem[_itemIndex].currentCon, _analyzeItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _analyzeItem[_itemIndex].info.c_str());
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
			else{
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "??? - ???");
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "??? / ???", _analyzeItem[_itemIndex].currentCon, _analyzeItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_analyzeItem[_itemIndex].type == ARMOR){
			if (!_analyzeItem[_itemIndex].seal){
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _analyzeItem[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d", _analyzeItem[_itemIndex].ability.DEF);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _analyzeItem[_itemIndex].currentCon, _analyzeItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _analyzeItem[_itemIndex].info.c_str());
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
			else{
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "???");
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "??? / ???", _analyzeItem[_itemIndex].currentCon, _analyzeItem[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}
	}

	if (_moneyError){
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("�ݾ׺���")->render(getMemDC(), 0, 600);
	}

	if (_analyzeError){
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("�����ۺ���")->render(getMemDC(), 0, 600);
	}
}

void shop::dataSave(){
	char str1[50];
	INIDATA->addData("Position", "X", INIDATA->loadDataString("PlayerData","Position","X").c_str());
	INIDATA->addData("Position", "Y", INIDATA->loadDataString("PlayerData", "Position", "Y").c_str());
	INIDATA->addData("Position", "�׸���X", INIDATA->loadDataString("PlayerData", "Position", "�׸���X").c_str());
	INIDATA->addData("Position", "�׸���Y", INIDATA->loadDataString("PlayerData", "Position", "�׸���Y").c_str());
	INIDATA->addData("Position", "������ǥX", INIDATA->loadDataString("PlayerData", "Position", "������ǥX").c_str());
	INIDATA->addData("Position", "������ǥY", INIDATA->loadDataString("PlayerData", "Position", "������ǥY").c_str());
	INIDATA->addData("Position", "��X", INIDATA->loadDataString("PlayerData", "Position", "��X").c_str());
	INIDATA->addData("Position", "��Y", INIDATA->loadDataString("PlayerData", "Position", "��Y").c_str());
	INIDATA->addData("Position", "����1X", INIDATA->loadDataString("PlayerData", "Position", "����1X").c_str());
	INIDATA->addData("Position", "����1Y", INIDATA->loadDataString("PlayerData", "Position", "����1Y").c_str());
	INIDATA->addData("Position", "����2X", INIDATA->loadDataString("PlayerData", "Position", "����2X").c_str());
	INIDATA->addData("Position", "����2Y", INIDATA->loadDataString("PlayerData", "Position", "����2Y").c_str());
	INIDATA->addData("Position", "����3X", INIDATA->loadDataString("PlayerData", "Position", "����3X").c_str());
	INIDATA->addData("Position", "����3Y", INIDATA->loadDataString("PlayerData", "Position", "����3Y").c_str());
	INIDATA->addData("Position", "����4X", INIDATA->loadDataString("PlayerData", "Position", "����4X").c_str());
	INIDATA->addData("Position", "����4Y", INIDATA->loadDataString("PlayerData", "Position", "����4Y").c_str());
	INIDATA->addData("Position", "����5X", INIDATA->loadDataString("PlayerData", "Position", "����5X").c_str());
	INIDATA->addData("Position", "����5Y", INIDATA->loadDataString("PlayerData", "Position", "����5Y").c_str());
	INIDATA->addData("Position", "��ī��X", INIDATA->loadDataString("PlayerData", "Position", "��ī��X").c_str());

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


	char str2[30];
	sprintf(str2, "%d", _itemCount[0].count);
	INIDATA->addData("��ī������ ������", "num", str2);
	sprintf(str2, "%d", _itemCount[0].currentCon);
	INIDATA->addData("��ī������ ������", "currentCon", str2);
	sprintf(str2, "%d", _itemCount[1].count);
	INIDATA->addData("������Ʈ ������", "num", str2);
	sprintf(str2, "%d", _itemCount[2].count);
	INIDATA->addData("�̱״� ������", "num", str2);
	sprintf(str2, "%d", _itemCount[3].count);
	INIDATA->addData("ũ��� ������", "num", str2);
	sprintf(str2, "%d", _itemCount[3].seal);
	INIDATA->addData("ũ��� ������", "seal", str2);
	sprintf(str2, "%d", _itemCount[4].count);
	INIDATA->addData("���� ����", "num", str2);
	sprintf(str2, "%d", _itemCount[5].count);
	INIDATA->addData("������ ����", "num", str2);
	sprintf(str2, "%d", _itemCount[6].count);
	INIDATA->addData("�븶���� ����", "num", str2);
	sprintf(str2, "%d", _itemCount[6].seal);
	INIDATA->addData("�븶���� ����", "seal", str2);
	sprintf(str2, "%d", _itemCount[7].count);
	INIDATA->addData("���� �尩", "num", str2);
	sprintf(str2, "%d", _itemCount[8].count);
	INIDATA->addData("���� �尩", "num", str2);
	sprintf(str2, "%d", _itemCount[9].count);
	INIDATA->addData("���� �Ź�", "num", str2);
	sprintf(str2, "%d", _itemCount[10].count);
	INIDATA->addData("������ �Ź�", "num", str2);
	sprintf(str2, "%d", _itemCount[11].count);
	INIDATA->addData("���޶��� �ͰŸ�", "num", str2);
	sprintf(str2, "%d", _itemCount[12].count);
	INIDATA->addData("�������� �ͰŸ�", "num", str2);
	sprintf(str2, "%d", _itemCount[13].count);
	INIDATA->addData("A��", "num", str2);
	sprintf(str2, "%d", _itemCount[14].count);
	INIDATA->addData("B��", "num", str2);
	sprintf(str2, "%d", _itemCount[15].count);
	INIDATA->addData("C��", "num", str2);
	sprintf(str2, "%d", _itemCount[16].count);
	INIDATA->addData("D��", "num", str2);
	sprintf(str2, "%d", _itemCount[17].count);
	INIDATA->addData("E��", "num", str2);
	sprintf(str2, "%d", _itemCount[18].count);
	INIDATA->addData("F��", "num", str2);
	sprintf(str2, "%d", _itemCount[19].count);
	INIDATA->addData("������ ����", "num", str2);

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
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "white").c_str();
	INIDATA->addData("Talizman", "white", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "black").c_str();
	INIDATA->addData("Talizman", "black", str.c_str());

	INIDATA->iniSave("PlayerData");
}