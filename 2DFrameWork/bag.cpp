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
	IMAGEMANAGER->addAlphaImage("������ǰ���", "�̹���/menu/������ǰ/���_����ǰ.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("������缱����ġ", "�̹���/����/����/���缱����ġ.bmp",0,0, 600, 73, true, RGB(255, 0, 255),true);
	SOUNDMANAGER->addSound("����", "����/�Ҽ�����/����.wav", false, false);
	SOUNDMANAGER->addSound("��������", "����/�Ҽ�����/��������.wav", false, false);
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


	//���� ���õ� ��ġ �����̰� �ϱ�
	_currentAlpha += 20 * _currentReverse;
	if (_currentAlpha == 240){ _currentReverse = -1; }
	if (_currentAlpha == 0){ _currentReverse = 1; }


	
}
void bag::render(){
	IMAGEMANAGER->findAlphaImage("������ǰ���")->alphaRender(getMemDC(), 0, 0, 200);

	SetBkMode(getMemDC(), TRANSPARENT);
	HFONT hFont,oldFont;
	char str[100];
	hFont = CreateFont(40, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
	oldFont = (HFONT)SelectObject(getMemDC(), hFont);
	SetTextColor(getMemDC(), RGB(255, 255, 255));

	IMAGEMANAGER->findAlphaImage("������缱����ġ")->alphaRender(getMemDC(), 358, 183 + 70 * _currentSelect, _currentAlpha);
	

	//�߰� ������
	for (int i = 0; i < 8; i++){
		sprintf(str, "bag%d", i + 1);
		if (strcmp(_bagArr[i].name.c_str(), "empty") == 0){
			sprintf(str, "����");
			TextOut(getMemDC(), 600, 200+i*70, str, strlen(str));
		}
		else{
			IMAGEMANAGER->findImage("������1")->frameRender(getMemDC(), 400, 185 + i * 70, _inven->getVInven()[_bagArr[i].index].frameX, _inven->getVInven()[_bagArr[i].index].frameY);
			TextOut(getMemDC(), 500, 200 + i * 70, _bagArr[i].name.c_str(), _bagArr[i].name.size());

		}
	}

	SelectObject(getMemDC(), oldFont);
	DeleteObject(hFont);

	//������ ������
	if (strcmp(_bagArr[_currentSelect].name.c_str(), "empty") != 0){
		IMAGEMANAGER->findImage("������")->frameRender(getMemDC(), 1000, 200, _inven->getVInven()[_bagArr[_currentSelect].index].frameX, _inven->getVInven()[_bagArr[_currentSelect].index].frameY);

		HFONT font;
		font = CreateFont(30, 20, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		//������ �̸�
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
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 1000, 350, str, strlen(str));
				strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].rank);
				TextOut(getMemDC(), 1400, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 1000, 450, str, strlen(str));
				sprintf(str, "%d - %d", _inven->getVInven()[_bagArr[_currentSelect].index].ability.ATK, _inven->getVInven()[_bagArr[_currentSelect].index].ability.ATK + _inven->getVInven()[_bagArr[_currentSelect].index].ability.ATK / 10);
				TextOut(getMemDC(), 1400, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 1000, 550, str, strlen(str));
				sprintf(str, "%d / %d", _inven->getVInven()[_bagArr[_currentSelect].index].currentCon, _inven->getVInven()[_bagArr[_currentSelect].index].maxCon);
				TextOut(getMemDC(), 1400, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 1000, 650, str, strlen(str));
				strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].info.c_str());
				TextOut(getMemDC(), 1000, 750, str, strlen(str));
			}
			else{
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 1000, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1400, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "���ݷ�");
				TextOut(getMemDC(), 1000, 450, str, strlen(str));
				sprintf(str, "??? - ???");
				TextOut(getMemDC(), 1400, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 1000, 550, str, strlen(str));
				sprintf(str, "??? / ???", _inven->getVInven()[_bagArr[_currentSelect].index].currentCon, _inven->getVInven()[_bagArr[_currentSelect].index].maxCon);
				TextOut(getMemDC(), 1400, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 1000, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 1000, 750, str, strlen(str));
			}
		}

		if (_inven->getVInven()[_bagArr[_currentSelect].index].type == ARMOR){
			if (!_inven->getVInven()[_bagArr[_currentSelect].index].seal){
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 1000, 350, str, strlen(str));
				strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].rank);
				TextOut(getMemDC(), 1400, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 1000, 450, str, strlen(str));
				sprintf(str, "%d", _inven->getVInven()[_bagArr[_currentSelect].index].ability.DEF);
				TextOut(getMemDC(), 1400, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 1000, 550, str, strlen(str));
				sprintf(str, "%d / %d", _inven->getVInven()[_bagArr[_currentSelect].index].currentCon, _inven->getVInven()[_bagArr[_currentSelect].index].maxCon);
				TextOut(getMemDC(), 1400, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 1000, 650, str, strlen(str));
				strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].info.c_str());
				TextOut(getMemDC(), 1000, 750, str, strlen(str));
			}
			else{
				//������ ��ũ
				sprintf(str, "��ũ");
				TextOut(getMemDC(), 1000, 350, str, strlen(str));
				strcpy(str, "???");
				TextOut(getMemDC(), 1400, 350, str, strlen(str));
				//������ ���ݷ�
				sprintf(str, "����");
				TextOut(getMemDC(), 1000, 450, str, strlen(str));
				sprintf(str, "???");
				TextOut(getMemDC(), 1400, 450, str, strlen(str));
				//������ ������
				sprintf(str, "������");
				TextOut(getMemDC(), 1000, 550, str, strlen(str));
				sprintf(str, "??? / ???", _inven->getVInven()[_bagArr[_currentSelect].index].currentCon, _inven->getVInven()[_bagArr[_currentSelect].index].maxCon);
				TextOut(getMemDC(), 1400, 550, str, strlen(str));
				//������ ����
				sprintf(str, "ȿ��");
				TextOut(getMemDC(), 1000, 650, str, strlen(str));
				sprintf(str, "������ ������ �ʿ��մϴ�");
				TextOut(getMemDC(), 1000, 750, str, strlen(str));
			}
		}

		if (_inven->getVInven()[_bagArr[_currentSelect].index].type == RUNE){
			//������ ����
			sprintf(str, "ȿ��");
			TextOut(getMemDC(), 1000, 450, str, strlen(str));
			strcpy(str, _inven->getVInven()[_bagArr[_currentSelect].index].info.c_str());
			TextOut(getMemDC(), 1000, 550, str, strlen(str));
		}

		if (_inven->getVInven()[_bagArr[_currentSelect].index].type == POTION){
			//������ ����
			sprintf(str, "ȿ��");
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
						SOUNDMANAGER->play("��������", 0.3F);
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

	//�κ��丮	-- ��� �������̵������
	str = INIDATA->loadDataString("PlayerData", "��ī������ ������", "num").c_str();
	INIDATA->addData("��ī������ ������", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "������Ʈ ������", "num").c_str();
	INIDATA->addData("������Ʈ ������", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�̱״� ������", "num").c_str();
	INIDATA->addData("�̱״� ������", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "ũ��� ������", "num").c_str();
	INIDATA->addData("ũ��� ������", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���� ����", "num").c_str();
	INIDATA->addData("���� ����", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "������ ����", "num").c_str();
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�븶���� ����", "num").c_str();
	INIDATA->addData("�븶���� ����", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���� �尩", "num").c_str();
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���� �尩", "num").c_str();
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���� �Ź�", "num").c_str();
	INIDATA->addData("���� �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "������ �Ź�", "num").c_str();
	INIDATA->addData("������ �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���޶��� �ͰŸ�", "num").c_str();
	INIDATA->addData("���޶��� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�������� �ͰŸ�", "num").c_str();
	INIDATA->addData("�������� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "A��", "num").c_str();
	INIDATA->addData("A��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "B��", "num").c_str();
	INIDATA->addData("B��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "C��", "num").c_str();
	INIDATA->addData("C��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "D��", "num").c_str();
	INIDATA->addData("D��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "E��", "num").c_str();
	INIDATA->addData("E��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "F��", "num").c_str();
	INIDATA->addData("F��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "������ ����", "num").c_str();
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���̽� �������� ��", "num").c_str();
	INIDATA->addData("���̽� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�����ؼ��� ��", "num").c_str();
	INIDATA->addData("�����ؼ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�׷���Ƽ�� ��", "num").c_str();
	INIDATA->addData("�׷���Ƽ�� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "��� Ŭ������ ��", "num").c_str();
	INIDATA->addData("��� Ŭ������ ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "�� �������� ��", "num").c_str();
	INIDATA->addData("�� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "���ڵ��� ��", "num").c_str();
	INIDATA->addData("���ڵ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "ũ������Ʈ Ǫ���� ��", "num").c_str();
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Ŀ���� ��", "num").c_str();
	INIDATA->addData("Ŀ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "��Ʈ�������̼��� ��", "num").c_str();
	INIDATA->addData("��Ʈ�������̼��� ��", "num", str.c_str());


	//���̺�
	for (int i = 0; i < 8; i++){
		char str1[10];
		sprintf(str1, "bag%d", i + 1);
		INIDATA->addData("Bag", str1, _bagArr[i].name.c_str());
	}

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

	INIDATA->iniSave("PlayerData");
}