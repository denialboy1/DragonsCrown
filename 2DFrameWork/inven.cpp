#include "stdafx.h"
#include "inven.h"


inven::inven()
{
}


inven::~inven()
{
}

HRESULT inven::init(){
	IMAGEMANAGER->addAlphaImage("bgItemBox", "�̹���/menu/�����۹ڽ�/�����۹ڽ�.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("���������缱����ġ", "�̹���/����/����/���缱����ġ.bmp", 0, 0, 900, 100, true, RGB(255, 0, 255), true);

	_item = new item;
	_item->itemSetting();
	
	invenLoading();

	//�������� �Ĵ� ������ ����
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
		if (strcmp(_vInven[i].name.c_str(), "ũ��� ������") == 0){
			_vInven[i].seal = INIDATA->loadDataInterger("PlayerData", "ũ��� ������", "seal");
		}
		if (strcmp(_vInven[i].name.c_str(), "�븶���� ����") == 0){
			_vInven[i].seal = INIDATA->loadDataInterger("PlayerData", "�븶���� ����", "seal");
		}
		if (strcmp(_vInven[i].name.c_str(), "��ī������ ������") == 0){
			_vInven[i].currentCon = INIDATA->loadDataInterger("PlayerData", "��ī������ ������", "currentCon");
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



	//���� ���õ� ��ġ �����̰� �ϱ�
	_currentAlpha += 20 * _currentReverse;
	if (_currentAlpha == 240){ _currentReverse = -1; }
	if (_currentAlpha == 0){ _currentReverse = 1; }

}
void inven::render(){
	IMAGEMANAGER->findAlphaImage("bgItemBox")->alphaRender(getMemDC(),0,0,200);
	
	//���� ������
	IMAGEMANAGER->findAlphaImage("���������缱����ġ")->alphaRender(getMemDC(), -30, 170 + _leftFrameCursor, _currentAlpha);

	SetBkMode(getMemDC(), TRANSPARENT);
	HFONT hFont, oldFont;
	char str[100];
	hFont = CreateFont(40, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont = (HFONT)SelectObject(getMemDC(), hFont);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	for (int i = 0; i < _vInven.size(); i++){
		int temp = 250 + 100 * i - _leftFrameMoveY;
		if (temp > 150){
			IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 5, 175 + 100 * i-_leftFrameMoveY, _vInven[i].frameX, _vInven[i].frameY);
			TextOut(getMemDC(), 100, 200 + 100 * i - _leftFrameMoveY, _vInven[i].name.c_str(), _vInven[i].name.size());
		}
	}

	SelectObject(getMemDC(), oldFont);
	DeleteObject(hFont);

	if (_vInven.size() != 0){
		//������ ������
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 900, 200, _vInven[_itemIndex].frameX, _vInven[_itemIndex].frameY);

		//������ ������
		HFONT font;
		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//������ �̸�
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
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _vInven[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d - %d", _vInven[_itemIndex].ability.ATK, _vInven[_itemIndex].ability.ATK + _vInven[_itemIndex].ability.ATK / 10);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _vInven[_itemIndex].currentCon, _vInven[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _vInven[_itemIndex].info.c_str());
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
				sprintf(str, "??? / ???", _vInven[_itemIndex].currentCon, _vInven[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_vInven[_itemIndex].type == ARMOR){
			if (!_vInven[_itemIndex].seal){
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 900, 350, str, strlen(str));
				strcpy(str, _vInven[_itemIndex].rank);
				TextOut(getMemDC(), 1300, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 900, 450, str, strlen(str));
				sprintf(str, "%d", _vInven[_itemIndex].ability.DEF);
				TextOut(getMemDC(), 1300, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 900, 550, str, strlen(str));
				sprintf(str, "%d / %d", _vInven[_itemIndex].currentCon, _vInven[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				strcpy(str, _vInven[_itemIndex].info.c_str());
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
				sprintf(str, "??? / ???", _vInven[_itemIndex].currentCon, _vInven[_itemIndex].maxCon);
				TextOut(getMemDC(), 1300, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 900, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 900, 750, str, strlen(str));
			}
		}

		if (_vInven[_itemIndex].type == RUNE){
			//������ ����
			sprintf(str, "ȿ��");
			TextOut(getMemDC(), 900, 450, str, strlen(str));
			strcpy(str, _vInven[_itemIndex].info.c_str());
			TextOut(getMemDC(), 900, 550, str, strlen(str));
		}

		if (_vInven[_itemIndex].type == POTION){
			//������ ����
			sprintf(str, "ȿ��");
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
			if (strcmp(name, "������ ����") == 0){
				_invenItem.useCount = INIDATA->loadDataInterger("PlayerData", "������ ����", "num");
			}
			else{
				_invenItem.useCount = _item->getVItem()[i].useCount;
			}

			_vInven.push_back(_invenItem);
		}
	}
}
void inven::invenLoading(){
	if (INIDATA->loadDataInterger("PlayerData", "��ī������ ������", "num") > 0){
		addInvenItem("��ī������ ������");
	}
	if (INIDATA->loadDataInterger("PlayerData", "������Ʈ ������", "num") > 0){
		addInvenItem("������Ʈ ������");
	}
	if (INIDATA->loadDataInterger("PlayerData", "�̱״� ������", "num") > 0){
		addInvenItem("�̱״� ������");
	}
	if (INIDATA->loadDataInterger("PlayerData", "ũ��� ������", "num") > 0){
		addInvenItem("ũ��� ������");
	}
	if (INIDATA->loadDataInterger("PlayerData", "���� ����", "num") > 0){
		addInvenItem("���� ����");
	}
	if (INIDATA->loadDataInterger("PlayerData", "������ ����", "num") > 0){
		addInvenItem("������ ����");
	}
	if (INIDATA->loadDataInterger("PlayerData", "�븶���� ����", "num") > 0){
		addInvenItem("�븶���� ����");
	}
	if (INIDATA->loadDataInterger("PlayerData", "���� �尩", "num") > 0){
		addInvenItem("���� �尩");
	}
	if (INIDATA->loadDataInterger("PlayerData", "���� �尩", "num") > 0){
		addInvenItem("���� �尩");
	}
	if (INIDATA->loadDataInterger("PlayerData", "���� �Ź�", "num") > 0){
		addInvenItem("���� �Ź�");
	}
	if (INIDATA->loadDataInterger("PlayerData", "������ �Ź�", "num") > 0){
		addInvenItem("������ �Ź�");
	}
	if (INIDATA->loadDataInterger("PlayerData", "���޶��� �ͰŸ�", "num") > 0){
		addInvenItem("���޶��� �ͰŸ�");
	}
	if (INIDATA->loadDataInterger("PlayerData", "�������� �ͰŸ�", "num") > 0){
		addInvenItem("�������� �ͰŸ�");
	}
	if (INIDATA->loadDataInterger("PlayerData", "A��", "num") > 0){
		addInvenItem("A��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "B��", "num") > 0){
		addInvenItem("B��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "C��", "num") > 0){
		addInvenItem("C��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "D��", "num") > 0){
		addInvenItem("D��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "E��", "num") > 0){
		addInvenItem("E��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "F��", "num") > 0){
		addInvenItem("F��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "������ ����", "num") > 0){
		addInvenItem("������ ����");
	}
	if (INIDATA->loadDataInterger("PlayerData", "���̽� �������� ��", "num") > 0){
		addInvenItem("���̽� �������� ��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "�����ؼ��� ��", "num") > 0){
		addInvenItem("�����ؼ��� ��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "�׷���Ƽ�� ��", "num") > 0){
		addInvenItem("�׷���Ƽ�� ��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "��� Ŭ������ ��", "num") > 0){
		addInvenItem("��� Ŭ������ ��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "�� �������� ��", "num") > 0){
		addInvenItem("�� �������� ��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "���ڵ��� ��", "num") > 0){
		addInvenItem("���ڵ��� ��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "ũ������Ʈ Ǫ���� ��", "num") > 0){
		addInvenItem("ũ������Ʈ Ǫ���� ��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "Ŀ���� ��", "num") > 0){
		addInvenItem("Ŀ���� ��");
	}
	if (INIDATA->loadDataInterger("PlayerData", "��Ʈ�������̼��� ��", "num") > 0){
		addInvenItem("��Ʈ�������̼��� ��");
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

	//�κ��丮	-- ��� �������̵������
	for (int i = 0; i < _vInven.size(); i++){
		sprintf(str1, "%d", _vInven[i].useCount);
		INIDATA->addData(_vInven[i].name.c_str(), "num", str1);
	}

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

	str = INIDATA->loadDataString("PlayerData", "Position", "X").c_str();
	INIDATA->addData("Position", "X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "Y").c_str();
	INIDATA->addData("Position", "Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "������ǥX").c_str();
	INIDATA->addData("Position", "������ǥX", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "������ǥY").c_str();
	INIDATA->addData("Position", "������ǥY", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "�׸���X").c_str();
	INIDATA->addData("Position", "�׸���X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "�׸���Y").c_str();
	INIDATA->addData("Position", "�׸���Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "��X").c_str();
	INIDATA->addData("Position", "��X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "��Y").c_str();
	INIDATA->addData("Position", "��Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����1X").c_str();
	INIDATA->addData("Position", "����1X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����1Y").c_str();
	INIDATA->addData("Position", "����1Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����2X").c_str();
	INIDATA->addData("Position", "����2X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����2Y").c_str();
	INIDATA->addData("Position", "����2Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����3X").c_str();
	INIDATA->addData("Position", "����3X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����3Y").c_str();
	INIDATA->addData("Position", "����3Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����4X").c_str();
	INIDATA->addData("Position", "����4X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����4Y").c_str();
	INIDATA->addData("Position", "����4Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����5X").c_str();
	INIDATA->addData("Position", "����5X", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "����5Y").c_str();
	INIDATA->addData("Position", "����5Y", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Position", "��ī��X").c_str();
	INIDATA->addData("Position", "��ī��X", str.c_str());

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