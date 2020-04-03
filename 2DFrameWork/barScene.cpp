#include "stdafx.h"
#include "barScene.h"


barScene::barScene()
{
}


barScene::~barScene()
{
}

HRESULT barScene::init(){
	//���� �̹��� �ҷ�����
	IMAGEMANAGER->addImage("����", "�̹���/����/����/����.bmp", 1920, 957, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��������", "�̹���/����/����/��������.bmp", 14616, 998,24,2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "�̹���/����/����/��������.bmp", 651, 118, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������ũ", "�̹���/����/����/������ũ.bmp", 191, 171, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("�����⼱����1", "�̹���/����/�����⼱����1.bmp", 467, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("�����⼱����2", "�̹���/����/�����⼱����2.bmp", 467, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("���̺꼱����1", "�̹���/����/����/���̺꼱����1.bmp", 467, 80, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("���̺꼱����2", "�̹���/����/����/���̺꼱����2.bmp", 467, 80, true, RGB(255, 0, 255));

	//������ ��� �̹��� �ҷ����� 
	IMAGEMANAGER->addImage("���̺�å1", "�̹���/����/����/���̺�/���̺�1.bmp",0,0, 164, 165, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addImage("���̺�å2", "�̹���/����/����/���̺�/���̺�2.bmp", 0,0,164, 165, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addImage("���̺�å3", "�̹���/����/����/���̺�/���̺�3.bmp", 0,0,164, 165, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addImage("ū���̺�å1", "�̹���/����/����/���̺�/���̺�1.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addImage("ū���̺�å2", "�̹���/����/����/���̺�/���̺�2.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addImage("ū���̺�å3", "�̹���/����/����/���̺�/���̺�3.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("���̺�", "�̹���/����/����/���̺�/���̺�.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("���̺���ġ����", "�̹���/����/����/���̺�/���̺���ġ����1.bmp", 1505, 206, true, RGB(255, 0, 255));

	//���� �ִϸ��̼�
	KEYANIMANAGER->addDefaultFrameAnimation("��������", "��������", 10, false, true);
	KEYANIMANAGER->findAnimation("��������")->start();

	SOUNDMANAGER->addSound("����", "����/����.mp3", true, true);
	SOUNDMANAGER->play("����", 0.1F);
	
	_menuChoice = 0;
	_saveChoice = 0;
	_choiceState = BAR;
	_menuState = SAVE;
	_saveState = SAVE1;
	return S_OK;
}
void barScene::update(){
	KEYANIMANAGER->update();
	switch (_choiceState){
	case BAR:
		if (KEYMANAGER->isOnceKeyDown(VK_UP)){
			_menuChoice -= 1;
			if (_menuChoice == -1) _menuChoice = 1;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
			_menuChoice += 1;
			if (_menuChoice == 2) _menuChoice = 0;
		}

		if (KEYMANAGER->isOnceKeyDown('A')){
			switch (_menuState){
			case SAVE:
				_choiceState = GAMESAVE;
				break;
			case BAREXIT:
				KEYANIMANAGER->findAnimation("��������")->stop();
				SOUNDMANAGER->allRemove();
				SCENEMANAGER->changeScene("������");
				break;
			}
		}

		if (KEYMANAGER->isOnceKeyDown('S')){

		}

		if (KEYMANAGER->isOnceKeyDown('Z')){

		}

		if (KEYMANAGER->isOnceKeyDown('X')){
			//�ٷ� �����Ⱑ �ɼ��ְ� ����
			_menuChoice = 1;
		}

		//�������� ���� ���
		switch (_menuChoice){
		case 0:
			_menuState = SAVE;
			break;
		case 1:
			_menuState = BAREXIT;
		}

		break;
	case GAMESAVE:
		if (KEYMANAGER->isOnceKeyDown(VK_UP)){
			_saveChoice -= 1;
			if (_saveChoice == -1) _saveChoice = 2;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
			_saveChoice += 1;
			if (_saveChoice == 3) _saveChoice = 0;
		}

		if (KEYMANAGER->isOnceKeyDown('A')){
			switch (_saveState){
			case SAVE1:
				save1("PlayerData");
				break;
			case SAVE2:
				save2("PlayerData");
				break;
			case SAVE3:
				save3("PlayerData");
				break;
			}
		}

		if (KEYMANAGER->isOnceKeyDown('S')){

		}

		if (KEYMANAGER->isOnceKeyDown('Z')){

		}

		if (KEYMANAGER->isOnceKeyDown('X')){
			_choiceState = BAR;
		}

		//�������� ���� ���
		switch (_saveChoice){
		case 0:
			_saveState = SAVE1;
			break;
		case 1:
			_saveState = SAVE2;
			break;
		case 2:
			_saveState = SAVE3;
			break;
		}

		break;
	}
	
}
void barScene::render(){
	IMAGEMANAGER->findImage("����")->render(getMemDC(),-310,-50);
	IMAGEMANAGER->findImage("��������")->aniRender(getMemDC(), 991, 370, KEYANIMANAGER->findAnimation("��������"));
	IMAGEMANAGER->findImage("��������")->render(getMemDC(), 70, 20);
	IMAGEMANAGER->findImage("������ũ")->render(getMemDC(), 300, 120);
	
	switch (_menuState){
	case SAVE:
		IMAGEMANAGER->findAlphaImage("���̺꼱����2")->alphaRender(getMemDC(), 170, 280, 200);
		IMAGEMANAGER->findAlphaImage("�����⼱����1")->alphaRender(getMemDC(), 170, 350, 125);
		break;
	case BAREXIT:
		IMAGEMANAGER->findAlphaImage("���̺꼱����1")->alphaRender(getMemDC(), 170, 280, 125);
		IMAGEMANAGER->findAlphaImage("�����⼱����2")->alphaRender(getMemDC(), 170, 350, 200);
		break;
	}
	
	if (_choiceState == GAMESAVE){
		IMAGEMANAGER->findAlphaImage("���̺�")->alphaRender(getMemDC(), 0, 0, 200);
		switch (_saveState){
		case SAVE1:
			IMAGEMANAGER->findAlphaImage("���̺���ġ����")->alphaRender(getMemDC(), 46, 135, 80);
			IMAGEMANAGER->findImage("ū���̺�å1")->render(getMemDC(), 70, 140);
			IMAGEMANAGER->findImage("���̺�å2")->render(getMemDC(), 70, 365);
			IMAGEMANAGER->findImage("���̺�å3")->render(getMemDC(), 70, 570);

			break;
		case SAVE2:
			IMAGEMANAGER->findAlphaImage("���̺���ġ����")->alphaRender(getMemDC(), 46, 340, 80);
			IMAGEMANAGER->findImage("���̺�å1")->render(getMemDC(), 70, 160);
			IMAGEMANAGER->findImage("ū���̺�å2")->render(getMemDC(), 70, 345);
			IMAGEMANAGER->findImage("���̺�å3")->render(getMemDC(), 70, 570);

			break;
		case SAVE3:
			IMAGEMANAGER->findAlphaImage("���̺���ġ����")->alphaRender(getMemDC(), 46, 547, 80);
			IMAGEMANAGER->findImage("���̺�å1")->render(getMemDC(), 70, 160);
			IMAGEMANAGER->findImage("���̺�å2")->render(getMemDC(), 70, 365);
			IMAGEMANAGER->findImage("ū���̺�å3")->render(getMemDC(), 70, 550);

			break;
		}

		HFONT oldFont;
		HFONT font1;
		SetBkMode(getMemDC(), TRANSPARENT);

		char str[100];
		if (INIDATA->loadDataInterger("save1", "State", "LEVEL") < 1){
			//������
			font1 = CreateFont(100, 60, 0, 0, 500, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 405, 190, str, strlen(str));
			if (_saveState == SAVE1){
				SetTextColor(getMemDC(), RGB(255, 255, 255));
			}
			else{
				SetTextColor(getMemDC(), RGB(125, 125, 125));
			}
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 400, 185, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
		}
		else{
			//���̺�1 �����Ͱ� ������
			font1 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			sprintf(str, "LV : %d", INIDATA->loadDataInterger("save1", "State", "LEVEL"));
			TextOut(getMemDC(), 280, 180, str, strlen(str));
			sprintf(str, "STR : %d", INIDATA->loadDataInterger("save1", "State", "STR"));
			TextOut(getMemDC(), 680, 180, str, strlen(str));
			sprintf(str, "INT : %d", INIDATA->loadDataInterger("save1", "State", "INT"));
			TextOut(getMemDC(), 980, 180, str, strlen(str));
			sprintf(str, "CON : %d", INIDATA->loadDataInterger("save1", "State", "CON"));
			TextOut(getMemDC(), 1280, 180, str, strlen(str));
			sprintf(str, "MGR : %d", INIDATA->loadDataInterger("save1", "State", "MGR"));
			TextOut(getMemDC(), 680, 250, str, strlen(str));
			sprintf(str, "DEX : %d", INIDATA->loadDataInterger("save1", "State", "DEX"));
			TextOut(getMemDC(), 980, 250, str, strlen(str));
			sprintf(str, "LUC : %d", INIDATA->loadDataInterger("save1", "State", "LUC"));
			TextOut(getMemDC(), 1280, 250, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);


		}

		if (INIDATA->loadDataInterger("save2", "State", "LEVEL") < 1){
			//������
			font1 = CreateFont(100, 60, 0, 0, 500, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 405, 400, str, strlen(str));
			if (_saveState == SAVE2){
				SetTextColor(getMemDC(), RGB(255, 255, 255));
			}
			else{
				SetTextColor(getMemDC(), RGB(125, 125, 125));
			}
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 400, 395, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
		}
		else{
			//���̺�2 �����Ͱ� ������
			font1 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			sprintf(str, "LV : %d", INIDATA->loadDataInterger("save2", "State", "LEVEL"));
			TextOut(getMemDC(), 280, 380, str, strlen(str));
			sprintf(str, "STR : %d", INIDATA->loadDataInterger("save2", "State", "STR"));
			TextOut(getMemDC(), 680, 380, str, strlen(str));
			sprintf(str, "INT : %d", INIDATA->loadDataInterger("save2", "State", "INT"));
			TextOut(getMemDC(), 980, 380, str, strlen(str));
			sprintf(str, "CON : %d", INIDATA->loadDataInterger("save2", "State", "CON"));
			TextOut(getMemDC(), 1280, 380, str, strlen(str));
			sprintf(str, "MGR : %d", INIDATA->loadDataInterger("save2", "State", "MGR"));
			TextOut(getMemDC(), 680, 450, str, strlen(str));
			sprintf(str, "DEX : %d", INIDATA->loadDataInterger("save2", "State", "DEX"));
			TextOut(getMemDC(), 980, 450, str, strlen(str));
			sprintf(str, "LUC : %d", INIDATA->loadDataInterger("save2", "State", "LUC"));
			TextOut(getMemDC(), 1280, 450, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
		}


		if (INIDATA->loadDataInterger("save3", "State", "LEVEL") < 1){
			//������
			font1 = CreateFont(100, 60, 0, 0, 500, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 405, 600, str, strlen(str));
			if (_saveState == SAVE3){
				SetTextColor(getMemDC(), RGB(255, 255, 255));
			}
			else{
				SetTextColor(getMemDC(), RGB(125, 125, 125));
			}
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 400, 595, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
		}
		else{
			//���̺�3 �����Ͱ� ������
			font1 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			sprintf(str, "LV : %d", INIDATA->loadDataInterger("save3", "State", "LEVEL"));
			TextOut(getMemDC(), 280, 580, str, strlen(str));
			sprintf(str, "STR : %d", INIDATA->loadDataInterger("save3", "State", "STR"));
			TextOut(getMemDC(), 680, 580, str, strlen(str));
			sprintf(str, "INT : %d", INIDATA->loadDataInterger("save3", "State", "INT"));
			TextOut(getMemDC(), 980, 580, str, strlen(str));
			sprintf(str, "CON : %d", INIDATA->loadDataInterger("save3", "State", "CON"));
			TextOut(getMemDC(), 1280, 580, str, strlen(str));
			sprintf(str, "MGR : %d", INIDATA->loadDataInterger("save3", "State", "MGR"));
			TextOut(getMemDC(), 680, 650, str, strlen(str));
			sprintf(str, "DEX : %d", INIDATA->loadDataInterger("save3", "State", "DEX"));
			TextOut(getMemDC(), 980, 650, str, strlen(str));
			sprintf(str, "LUC : %d", INIDATA->loadDataInterger("save3", "State", "LUC"));
			TextOut(getMemDC(), 1280, 650, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);

		}
	}
}
void barScene::release(){
}


void barScene::save1(char* fileName){
	//��ǥ
	char str1[50];
	sprintf(str1, "%d", 100);
	INIDATA->addData("Position", "X", str1);
	sprintf(str1, "%d", 300);
	INIDATA->addData("Position", "Y", str1);
	sprintf(str1, "%d", 115);
	INIDATA->addData("Position", "�׸���X", str1);
	sprintf(str1, "%d", 740);
	INIDATA->addData("Position", "�׸���Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "������ǥX", str1);
	sprintf(str1, "%d", -600);
	INIDATA->addData("Position", "������ǥY", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����1X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����1Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����2X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����2Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����3X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����3Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����4X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����4Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����5X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����5Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��ī��X", str1);


	string str = INIDATA->loadDataString(fileName, "State", "LEVEL").c_str();
	INIDATA->addData("State", "LEVEL", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "EXP").c_str();
	INIDATA->addData("State", "EXP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "HP").c_str();
	INIDATA->addData("State", "HP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "MP").c_str();
	INIDATA->addData("State", "MP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "STR").c_str();
	INIDATA->addData("State", "STR", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "INT").c_str();
	INIDATA->addData("State", "INT", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "CON").c_str();
	INIDATA->addData("State", "CON", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "MGR").c_str();
	INIDATA->addData("State", "MGR", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "DEX").c_str();
	INIDATA->addData("State", "DEX", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "LUC").c_str();
	INIDATA->addData("State", "LUC", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "Money").c_str();
	INIDATA->addData("State", "Money", str.c_str());
	//�κ��丮	-- ��� �������̵������
	str = INIDATA->loadDataString(fileName, "��ī������ ������", "num").c_str();
	INIDATA->addData("��ī������ ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��ī������ ������", "currentCon").c_str();
	INIDATA->addData("��ī������ ������", "currentCon", str.c_str());
	str = INIDATA->loadDataString(fileName, "������Ʈ ������", "num").c_str();
	INIDATA->addData("������Ʈ ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�̱״� ������", "num").c_str();
	INIDATA->addData("�̱״� ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ��� ������", "num").c_str();
	INIDATA->addData("ũ��� ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ��� ������", "seal").c_str();
	INIDATA->addData("ũ��� ������", "seal", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� ����", "num").c_str();
	INIDATA->addData("���� ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ ����", "num").c_str();
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�븶���� ����", "num").c_str();
	INIDATA->addData("�븶���� ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�븶���� ����", "seal").c_str();
	INIDATA->addData("�븶���� ����", "seal", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �尩", "num").c_str();
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �尩", "num").c_str();
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �Ź�", "num").c_str();
	INIDATA->addData("���� �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ �Ź�", "num").c_str();
	INIDATA->addData("������ �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���޶��� �ͰŸ�", "num").c_str();
	INIDATA->addData("���޶��� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�������� �ͰŸ�", "num").c_str();
	INIDATA->addData("�������� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "A��", "num").c_str();
	INIDATA->addData("A��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "B��", "num").c_str();
	INIDATA->addData("B��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "C��", "num").c_str();
	INIDATA->addData("C��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "D��", "num").c_str();
	INIDATA->addData("D��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "E��", "num").c_str();
	INIDATA->addData("E��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "F��", "num").c_str();
	INIDATA->addData("F��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ ����", "num").c_str();
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���̽� �������� ��", "num").c_str();
	INIDATA->addData("���̽� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�����ؼ��� ��", "num").c_str();
	INIDATA->addData("�����ؼ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�׷���Ƽ�� ��", "num").c_str();
	INIDATA->addData("�׷���Ƽ�� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��� Ŭ������ ��", "num").c_str();
	INIDATA->addData("��� Ŭ������ ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�� �������� ��", "num").c_str();
	INIDATA->addData("�� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���ڵ��� ��", "num").c_str();
	INIDATA->addData("���ڵ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ������Ʈ Ǫ���� ��", "num").c_str();
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "Ŀ���� ��", "num").c_str();
	INIDATA->addData("Ŀ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��Ʈ�������̼��� ��", "num").c_str();
	INIDATA->addData("��Ʈ�������̼��� ��", "num", str.c_str());

	//����	-- �������� ����� �������� ���
	str = INIDATA->loadDataString(fileName, "Bag", "bag1").c_str();
	INIDATA->addData("Bag", "bag1", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag2").c_str();
	INIDATA->addData("Bag", "bag2", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag3").c_str();
	INIDATA->addData("Bag", "bag3", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag4").c_str();
	INIDATA->addData("Bag", "bag4", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag5").c_str();
	INIDATA->addData("Bag", "bag5", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag6").c_str();
	INIDATA->addData("Bag", "bag6", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag7").c_str();
	INIDATA->addData("Bag", "bag7", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag8").c_str();
	INIDATA->addData("Bag", "bag8", str.c_str());

	//��ų
	str = INIDATA->loadDataString(fileName, "Skill", "SKILLPOINT").c_str();
	INIDATA->addData("Skill", "SKILLPOINT", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "mental_absorb").c_str();
	INIDATA->addData("Skill", "mental_absorb", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "extract").c_str();
	INIDATA->addData("Skill", "extract", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "concentrate").c_str();
	INIDATA->addData("Skill", "concentrate", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "magic_point_up").c_str();
	INIDATA->addData("Skill", "magic_point_up", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "ice_prision").c_str();
	INIDATA->addData("Skill", "ice_prision", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "protection").c_str();
	INIDATA->addData("Skill", "protection", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gravity").c_str();
	INIDATA->addData("Skill", "gravity", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "thunder_cloud").c_str();
	INIDATA->addData("Skill", "thunder_cloud", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "rock_press").c_str();
	INIDATA->addData("Skill", "rock_press", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "blizzard").c_str();
	INIDATA->addData("Skill", "blizzard", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "animate_skelton").c_str();
	INIDATA->addData("Skill", "animate_skelton", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "ravitation").c_str();
	INIDATA->addData("Skill", "ravitation", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "create_food").c_str();
	INIDATA->addData("Skill", "create_food", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "curse").c_str();
	INIDATA->addData("Skill", "curse", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "petrification").c_str();
	INIDATA->addData("Skill", "petrification", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "sliding").c_str();
	INIDATA->addData("Skill", "sliding", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gold_healing").c_str();
	INIDATA->addData("Skill", "gold_healing", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gold_scoring").c_str();
	INIDATA->addData("Skill", "gold_scoring", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "hit_point_up").c_str();
	INIDATA->addData("Skill", "hit_point_up", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "food_psytology").c_str();
	INIDATA->addData("Skill", "food_psytology", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "maintenance").c_str();
	INIDATA->addData("Skill", "maintenance", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "item_user").c_str();
	INIDATA->addData("Skill", "item_user", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "evade").c_str();
	INIDATA->addData("Skill", "evade", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "extra_pocket").c_str();
	INIDATA->addData("Skill", "extra_pocket", str.c_str());

	//Ż���
	str = INIDATA->loadDataString(fileName, "Talizman", "red").c_str();
	INIDATA->addData("Talizman", "red", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "orange").c_str();
	INIDATA->addData("Talizman", "orange", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "yellow").c_str();
	INIDATA->addData("Talizman", "yellow", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "green").c_str();
	INIDATA->addData("Talizman", "green", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "skyblue").c_str();
	INIDATA->addData("Talizman", "skyblue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "blue").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "pupple").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "white").c_str();
	INIDATA->addData("Talizman", "white", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "black").c_str();
	INIDATA->addData("Talizman", "black", str.c_str());

	INIDATA->iniSave("save1");
}
void barScene::save2(char* fileName){//��ǥ
	char str1[50];
	sprintf(str1, "%d", 100);
	INIDATA->addData("Position", "X", str1);
	sprintf(str1, "%d", 300);
	INIDATA->addData("Position", "Y", str1);
	sprintf(str1, "%d", 115);
	INIDATA->addData("Position", "�׸���X", str1);
	sprintf(str1, "%d", 740);
	INIDATA->addData("Position", "�׸���Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "������ǥX", str1);
	sprintf(str1, "%d", -600);
	INIDATA->addData("Position", "������ǥY", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����1X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����1Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����2X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����2Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����3X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����3Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����4X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����4Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����5X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����5Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��ī��X", str1);


	string str = INIDATA->loadDataString(fileName, "State", "LEVEL").c_str();
	INIDATA->addData("State", "LEVEL", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "EXP").c_str();
	INIDATA->addData("State", "EXP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "HP").c_str();
	INIDATA->addData("State", "HP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "MP").c_str();
	INIDATA->addData("State", "MP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "STR").c_str();
	INIDATA->addData("State", "STR", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "INT").c_str();
	INIDATA->addData("State", "INT", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "CON").c_str();
	INIDATA->addData("State", "CON", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "MGR").c_str();
	INIDATA->addData("State", "MGR", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "DEX").c_str();
	INIDATA->addData("State", "DEX", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "LUC").c_str();
	INIDATA->addData("State", "LUC", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "Money").c_str();
	INIDATA->addData("State", "Money", str.c_str());
	//�κ��丮	-- ��� �������̵������
	str = INIDATA->loadDataString(fileName, "��ī������ ������", "num").c_str();
	INIDATA->addData("��ī������ ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��ī������ ������", "currentCon").c_str();
	INIDATA->addData("��ī������ ������", "currentCon", str.c_str());
	str = INIDATA->loadDataString(fileName, "������Ʈ ������", "num").c_str();
	INIDATA->addData("������Ʈ ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�̱״� ������", "num").c_str();
	INIDATA->addData("�̱״� ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ��� ������", "num").c_str();
	INIDATA->addData("ũ��� ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ��� ������", "seal").c_str();
	INIDATA->addData("ũ��� ������", "seal", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� ����", "num").c_str();
	INIDATA->addData("���� ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ ����", "num").c_str();
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�븶���� ����", "num").c_str();
	INIDATA->addData("�븶���� ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�븶���� ����", "seal").c_str();
	INIDATA->addData("�븶���� ����", "seal", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �尩", "num").c_str();
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �尩", "num").c_str();
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �Ź�", "num").c_str();
	INIDATA->addData("���� �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ �Ź�", "num").c_str();
	INIDATA->addData("������ �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���޶��� �ͰŸ�", "num").c_str();
	INIDATA->addData("���޶��� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�������� �ͰŸ�", "num").c_str();
	INIDATA->addData("�������� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "A��", "num").c_str();
	INIDATA->addData("A��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "B��", "num").c_str();
	INIDATA->addData("B��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "C��", "num").c_str();
	INIDATA->addData("C��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "D��", "num").c_str();
	INIDATA->addData("D��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "E��", "num").c_str();
	INIDATA->addData("E��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "F��", "num").c_str();
	INIDATA->addData("F��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ ����", "num").c_str();
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���̽� �������� ��", "num").c_str();
	INIDATA->addData("���̽� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�����ؼ��� ��", "num").c_str();
	INIDATA->addData("�����ؼ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�׷���Ƽ�� ��", "num").c_str();
	INIDATA->addData("�׷���Ƽ�� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��� Ŭ������ ��", "num").c_str();
	INIDATA->addData("��� Ŭ������ ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�� �������� ��", "num").c_str();
	INIDATA->addData("�� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���ڵ��� ��", "num").c_str();
	INIDATA->addData("���ڵ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ������Ʈ Ǫ���� ��", "num").c_str();
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "Ŀ���� ��", "num").c_str();
	INIDATA->addData("Ŀ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��Ʈ�������̼��� ��", "num").c_str();
	INIDATA->addData("��Ʈ�������̼��� ��", "num", str.c_str());

	//����	-- �������� ����� �������� ���
	str = INIDATA->loadDataString(fileName, "Bag", "bag1").c_str();
	INIDATA->addData("Bag", "bag1", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag2").c_str();
	INIDATA->addData("Bag", "bag2", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag3").c_str();
	INIDATA->addData("Bag", "bag3", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag4").c_str();
	INIDATA->addData("Bag", "bag4", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag5").c_str();
	INIDATA->addData("Bag", "bag5", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag6").c_str();
	INIDATA->addData("Bag", "bag6", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag7").c_str();
	INIDATA->addData("Bag", "bag7", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag8").c_str();
	INIDATA->addData("Bag", "bag8", str.c_str());

	//��ų
	str = INIDATA->loadDataString(fileName, "Skill", "SKILLPOINT").c_str();
	INIDATA->addData("Skill", "SKILLPOINT", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "mental_absorb").c_str();
	INIDATA->addData("Skill", "mental_absorb", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "extract").c_str();
	INIDATA->addData("Skill", "extract", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "concentrate").c_str();
	INIDATA->addData("Skill", "concentrate", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "magic_point_up").c_str();
	INIDATA->addData("Skill", "magic_point_up", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "ice_prision").c_str();
	INIDATA->addData("Skill", "ice_prision", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "protection").c_str();
	INIDATA->addData("Skill", "protection", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gravity").c_str();
	INIDATA->addData("Skill", "gravity", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "thunder_cloud").c_str();
	INIDATA->addData("Skill", "thunder_cloud", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "rock_press").c_str();
	INIDATA->addData("Skill", "rock_press", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "blizzard").c_str();
	INIDATA->addData("Skill", "blizzard", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "animate_skelton").c_str();
	INIDATA->addData("Skill", "animate_skelton", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "ravitation").c_str();
	INIDATA->addData("Skill", "ravitation", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "create_food").c_str();
	INIDATA->addData("Skill", "create_food", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "curse").c_str();
	INIDATA->addData("Skill", "curse", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "petrification").c_str();
	INIDATA->addData("Skill", "petrification", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "sliding").c_str();
	INIDATA->addData("Skill", "sliding", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gold_healing").c_str();
	INIDATA->addData("Skill", "gold_healing", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gold_scoring").c_str();
	INIDATA->addData("Skill", "gold_scoring", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "hit_point_up").c_str();
	INIDATA->addData("Skill", "hit_point_up", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "food_psytology").c_str();
	INIDATA->addData("Skill", "food_psytology", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "maintenance").c_str();
	INIDATA->addData("Skill", "maintenance", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "item_user").c_str();
	INIDATA->addData("Skill", "item_user", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "evade").c_str();
	INIDATA->addData("Skill", "evade", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "extra_pocket").c_str();
	INIDATA->addData("Skill", "extra_pocket", str.c_str());

	//Ż���
	str = INIDATA->loadDataString(fileName, "Talizman", "red").c_str();
	INIDATA->addData("Talizman", "red", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "orange").c_str();
	INIDATA->addData("Talizman", "orange", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "yellow").c_str();
	INIDATA->addData("Talizman", "yellow", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "green").c_str();
	INIDATA->addData("Talizman", "green", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "skyblue").c_str();
	INIDATA->addData("Talizman", "skyblue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "blue").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "pupple").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "white").c_str();
	INIDATA->addData("Talizman", "white", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "black").c_str();
	INIDATA->addData("Talizman", "black", str.c_str());

	INIDATA->iniSave("save2");
}
void barScene::save3(char* fileName){
	//��ǥ
	char str1[50];
	sprintf(str1, "%d", 100);
	INIDATA->addData("Position", "X", str1);
	sprintf(str1, "%d", 300);
	INIDATA->addData("Position", "Y", str1);
	sprintf(str1, "%d", 115);
	INIDATA->addData("Position", "�׸���X", str1);
	sprintf(str1, "%d", 740);
	INIDATA->addData("Position", "�׸���Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "������ǥX", str1);
	sprintf(str1, "%d", -600);
	INIDATA->addData("Position", "������ǥY", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����1X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����1Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����2X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����2Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����3X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����3Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����4X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����4Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����5X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "����5Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "��ī��X", str1);


	string str = INIDATA->loadDataString(fileName, "State", "LEVEL").c_str();
	INIDATA->addData("State", "LEVEL", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "EXP").c_str();
	INIDATA->addData("State", "EXP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "HP").c_str();
	INIDATA->addData("State", "HP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "MP").c_str();
	INIDATA->addData("State", "MP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "STR").c_str();
	INIDATA->addData("State", "STR", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "INT").c_str();
	INIDATA->addData("State", "INT", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "CON").c_str();
	INIDATA->addData("State", "CON", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "MGR").c_str();
	INIDATA->addData("State", "MGR", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "DEX").c_str();
	INIDATA->addData("State", "DEX", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "LUC").c_str();
	INIDATA->addData("State", "LUC", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "Money").c_str();
	INIDATA->addData("State", "Money", str.c_str());
	//�κ��丮	-- ��� �������̵������
	str = INIDATA->loadDataString(fileName, "��ī������ ������", "num").c_str();
	INIDATA->addData("��ī������ ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��ī������ ������", "currentCon").c_str();
	INIDATA->addData("��ī������ ������", "currentCon", str.c_str());
	str = INIDATA->loadDataString(fileName, "������Ʈ ������", "num").c_str();
	INIDATA->addData("������Ʈ ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�̱״� ������", "num").c_str();
	INIDATA->addData("�̱״� ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ��� ������", "num").c_str();
	INIDATA->addData("ũ��� ������", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ��� ������", "seal").c_str();
	INIDATA->addData("ũ��� ������", "seal", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� ����", "num").c_str();
	INIDATA->addData("���� ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ ����", "num").c_str();
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�븶���� ����", "num").c_str();
	INIDATA->addData("�븶���� ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�븶���� ����", "seal").c_str();
	INIDATA->addData("�븶���� ����", "seal", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �尩", "num").c_str();
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �尩", "num").c_str();
	INIDATA->addData("���� �尩", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���� �Ź�", "num").c_str();
	INIDATA->addData("���� �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ �Ź�", "num").c_str();
	INIDATA->addData("������ �Ź�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���޶��� �ͰŸ�", "num").c_str();
	INIDATA->addData("���޶��� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�������� �ͰŸ�", "num").c_str();
	INIDATA->addData("�������� �ͰŸ�", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "A��", "num").c_str();
	INIDATA->addData("A��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "B��", "num").c_str();
	INIDATA->addData("B��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "C��", "num").c_str();
	INIDATA->addData("C��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "D��", "num").c_str();
	INIDATA->addData("D��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "E��", "num").c_str();
	INIDATA->addData("E��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "F��", "num").c_str();
	INIDATA->addData("F��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "������ ����", "num").c_str();
	INIDATA->addData("������ ����", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���̽� �������� ��", "num").c_str();
	INIDATA->addData("���̽� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�����ؼ��� ��", "num").c_str();
	INIDATA->addData("�����ؼ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�׷���Ƽ�� ��", "num").c_str();
	INIDATA->addData("�׷���Ƽ�� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��� Ŭ������ ��", "num").c_str();
	INIDATA->addData("��� Ŭ������ ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "�� �������� ��", "num").c_str();
	INIDATA->addData("�� �������� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "���ڵ��� ��", "num").c_str();
	INIDATA->addData("���ڵ��� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "ũ������Ʈ Ǫ���� ��", "num").c_str();
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "Ŀ���� ��", "num").c_str();
	INIDATA->addData("Ŀ���� ��", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "��Ʈ�������̼��� ��", "num").c_str();
	INIDATA->addData("��Ʈ�������̼��� ��", "num", str.c_str());

	//����	-- �������� ����� �������� ���
	str = INIDATA->loadDataString(fileName, "Bag", "bag1").c_str();
	INIDATA->addData("Bag", "bag1", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag2").c_str();
	INIDATA->addData("Bag", "bag2", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag3").c_str();
	INIDATA->addData("Bag", "bag3", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag4").c_str();
	INIDATA->addData("Bag", "bag4", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag5").c_str();
	INIDATA->addData("Bag", "bag5", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag6").c_str();
	INIDATA->addData("Bag", "bag6", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag7").c_str();
	INIDATA->addData("Bag", "bag7", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag8").c_str();
	INIDATA->addData("Bag", "bag8", str.c_str());

	//��ų
	str = INIDATA->loadDataString(fileName, "Skill", "SKILLPOINT").c_str();
	INIDATA->addData("Skill", "SKILLPOINT", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "mental_absorb").c_str();
	INIDATA->addData("Skill", "mental_absorb", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "extract").c_str();
	INIDATA->addData("Skill", "extract", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "concentrate").c_str();
	INIDATA->addData("Skill", "concentrate", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "magic_point_up").c_str();
	INIDATA->addData("Skill", "magic_point_up", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "ice_prision").c_str();
	INIDATA->addData("Skill", "ice_prision", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "protection").c_str();
	INIDATA->addData("Skill", "protection", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gravity").c_str();
	INIDATA->addData("Skill", "gravity", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "thunder_cloud").c_str();
	INIDATA->addData("Skill", "thunder_cloud", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "rock_press").c_str();
	INIDATA->addData("Skill", "rock_press", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "blizzard").c_str();
	INIDATA->addData("Skill", "blizzard", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "animate_skelton").c_str();
	INIDATA->addData("Skill", "animate_skelton", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "ravitation").c_str();
	INIDATA->addData("Skill", "ravitation", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "create_food").c_str();
	INIDATA->addData("Skill", "create_food", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "curse").c_str();
	INIDATA->addData("Skill", "curse", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "petrification").c_str();
	INIDATA->addData("Skill", "petrification", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "sliding").c_str();
	INIDATA->addData("Skill", "sliding", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gold_healing").c_str();
	INIDATA->addData("Skill", "gold_healing", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gold_scoring").c_str();
	INIDATA->addData("Skill", "gold_scoring", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "hit_point_up").c_str();
	INIDATA->addData("Skill", "hit_point_up", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "food_psytology").c_str();
	INIDATA->addData("Skill", "food_psytology", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "maintenance").c_str();
	INIDATA->addData("Skill", "maintenance", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "item_user").c_str();
	INIDATA->addData("Skill", "item_user", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "evade").c_str();
	INIDATA->addData("Skill", "evade", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "extra_pocket").c_str();
	INIDATA->addData("Skill", "extra_pocket", str.c_str());

	//Ż���
	str = INIDATA->loadDataString(fileName, "Talizman", "red").c_str();
	INIDATA->addData("Talizman", "red", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "orange").c_str();
	INIDATA->addData("Talizman", "orange", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "yellow").c_str();
	INIDATA->addData("Talizman", "yellow", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "green").c_str();
	INIDATA->addData("Talizman", "green", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "skyblue").c_str();
	INIDATA->addData("Talizman", "skyblue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "blue").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "pupple").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "white").c_str();
	INIDATA->addData("Talizman", "white", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "black").c_str();
	INIDATA->addData("Talizman", "black", str.c_str());

	INIDATA->iniSave("save3");
}