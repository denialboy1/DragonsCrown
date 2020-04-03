#include "stdafx.h"
#include "skillInfo.h"


skillInfo::skillInfo()
{
}


skillInfo::~skillInfo()
{
}


HRESULT skillInfo::init(){
	IMAGEMANAGER->addAlphaImage("bgSkillInfo", "�̹���/menu/��ų/��ųȮ��.bmp", 1600, 900, true, RGB(255, 0, 255));

	//�Ҽ�������ų
	IMAGEMANAGER->addAlphaImage("��Ż�ۼҺ�1", "�̹���/����/���/��Ż�ۼҺ�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("����Ʈ��Ʈ1", "�̹���/����/���/����Ʈ��Ʈ.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("�ܼ�Ʈ����Ʈ1", "�̹���/����/���/�ܼ�Ʈ����Ʈ.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("��������Ʈ��1", "�̹���/����/���/��������Ʈ��.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("���̽�������1", "�̹���/����/���/���̽�������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("�����ؼ�1", "�̹���/����/���/�����ؼ�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("�׷���Ƽ1", "�̹���/����/���/�׷���Ƽ.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("���Ŭ����1", "�̹���/����/���/���Ŭ����.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("��������1", "�̹���/����/���/��������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("���ڵ�1", "�̹���/����/���/���ڵ�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("�������̼�1", "�̹���/����/���/�������̼�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("ũ������ƮǪ��1", "�̹���/����/���/ũ������ƮǪ��.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("��Ʈ�������̼�1", "�̹���/����/���/��Ʈ�������̼�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);

	//���� ��ų
	IMAGEMANAGER->addAlphaImage("��Ʈ����Ʈ��1", "�̹���/����/���/��Ʈ����Ʈ��.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("Ǫ����������1", "�̹���/����/���/Ǫ����������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("�����׳ͽ�1", "�̹���/����/���/�����׳ͽ�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("����������1", "�̹���/����/���/����������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);

	//��ų���� ������
	IMAGEMANAGER->addAlphaImage("��ų����������1", "�̹���/menu/��ų/��ų����������1.bmp", 1400, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("��ų����������2", "�̹���/menu/��ų/��ų����������2.bmp", 1400, 90, true, RGB(255, 0, 255));


	_skill = new skill;
	_skill->init();

	_currentWhich = 0;
	_currentAlpha = 255;
	_currentReverse = 1;
	_botFrameCursor = 0;
	_botFrameMoveY = 0;
	return S_OK;
}
void skillInfo::update(){
	if (KEYMANAGER->isOnceKeyDown(VK_UP)){
		_currentWhich -= 1;
		if (_currentWhich < -1) { _currentWhich = -1; }
		if (150 + _botFrameCursor * 60 > 150){ _botFrameCursor--; }
		else{
			if (_currentWhich > -1)
				_botFrameMoveY -= 60;
		}
		if (_currentWhich == -1) _currentWhich = 0;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){

		_currentWhich += 1;
		if (_currentWhich >= 17) { _currentWhich = 17; }
		if (_botFrameCursor == 4){
			if (_currentWhich < 17){ _botFrameMoveY += 60;  }
		}
		if (150 + _botFrameCursor * 60 < 150 + 4 * 60){ _botFrameCursor++; }
		if (_currentWhich == 17) _currentWhich = 16;
	}
}
void skillInfo::render(){
	IMAGEMANAGER->findAlphaImage("bgSkillInfo")->alphaRender(getMemDC(), 200);

	//������ ���
	for (int i = 0; i < 19; i++){
		if ((150 <= 150 + i * 60 - _botFrameMoveY) && (150 + i * 60 - _botFrameMoveY < 450)){
			IMAGEMANAGER->findAlphaImage("��ų����������1")->alphaRender(getMemDC(), 100, 150 + i * 60 - _botFrameMoveY, 255);
		}
	}


	IMAGEMANAGER->findAlphaImage("��ų����������2")->alphaRender(getMemDC(), 100, 150 + _botFrameCursor * 60, 255);

	HFONT hFont, oldFont;
	char str[100];
	//������ ����
	for (int i = 0; i < 20; i++){
		if ((150 <= 150 + i * 60 - _botFrameMoveY) && (150 + i * 60 - _botFrameMoveY < 450)){
			SetBkMode(getMemDC(), TRANSPARENT);
			hFont = CreateFont(40, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), hFont);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			//��ų �̸�
			TextOut(getMemDC(), 400, 175 + i * 60 - _botFrameMoveY, _skill->getSorceressSkill()[i].name.c_str(), _skill->getSorceressSkill()[i].name.size());
			//��ų ����
			sprintf(str, "LV %d", _skill->getSorceressSkill()[i].skillLV);
			TextOut(getMemDC(), 1200, 175 + i * 60 - _botFrameMoveY, str, strlen(str));

		}
	}

	//�Ʒ� ������
	switch (_currentWhich){
	case 0:
		IMAGEMANAGER->findAlphaImage("��Ż�ۼҺ�1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[0].name.c_str(), _skill->getSorceressSkill()[0].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[0].skillInfo.c_str(), _skill->getSorceressSkill()[0].skillInfo.size());
		break;
	case 1:
		IMAGEMANAGER->findAlphaImage("����Ʈ��Ʈ1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[1].name.c_str(), _skill->getSorceressSkill()[1].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[1].skillInfo.c_str(), _skill->getSorceressSkill()[1].skillInfo.size());
		break;
	case 2:
		IMAGEMANAGER->findAlphaImage("�ܼ�Ʈ����Ʈ1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[2].name.c_str(), _skill->getSorceressSkill()[2].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[2].skillInfo.c_str(), _skill->getSorceressSkill()[2].skillInfo.size());
		break;
	case 3:
		IMAGEMANAGER->findAlphaImage("��������Ʈ��1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[3].name.c_str(), _skill->getSorceressSkill()[3].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[3].skillInfo.c_str(), _skill->getSorceressSkill()[3].skillInfo.size());
		break;
	case 4:
		IMAGEMANAGER->findAlphaImage("���̽�������1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[4].name.c_str(), _skill->getSorceressSkill()[4].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[4].skillInfo.c_str(), _skill->getSorceressSkill()[4].skillInfo.size());
		break;
	case 5:
		IMAGEMANAGER->findAlphaImage("�����ؼ�1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[5].name.c_str(), _skill->getSorceressSkill()[5].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[5].skillInfo.c_str(), _skill->getSorceressSkill()[5].skillInfo.size());
		break;
	case 6:
		IMAGEMANAGER->findAlphaImage("�׷���Ƽ1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[6].name.c_str(), _skill->getSorceressSkill()[6].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[6].skillInfo.c_str(), _skill->getSorceressSkill()[6].skillInfo.size());
		break;
	case 7:
		IMAGEMANAGER->findAlphaImage("���Ŭ����1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[7].name.c_str(), _skill->getSorceressSkill()[7].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[7].skillInfo.c_str(), _skill->getSorceressSkill()[7].skillInfo.size());
		break;
	case 8:
		IMAGEMANAGER->findAlphaImage("��������1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[8].name.c_str(), _skill->getSorceressSkill()[8].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[8].skillInfo.c_str(), _skill->getSorceressSkill()[8].skillInfo.size());
		break;
	case 9:
		IMAGEMANAGER->findAlphaImage("���ڵ�1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[9].name.c_str(), _skill->getSorceressSkill()[9].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[9].skillInfo.c_str(), _skill->getSorceressSkill()[9].skillInfo.size());
		break;
	case 10:
		IMAGEMANAGER->findAlphaImage("�������̼�1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[10].name.c_str(), _skill->getSorceressSkill()[10].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[10].skillInfo.c_str(), _skill->getSorceressSkill()[10].skillInfo.size());
		break;
	case 11:
		IMAGEMANAGER->findAlphaImage("ũ������ƮǪ��1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[11].name.c_str(), _skill->getSorceressSkill()[11].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[11].skillInfo.c_str(), _skill->getSorceressSkill()[11].skillInfo.size());
		break;
	case 12:
		IMAGEMANAGER->findAlphaImage("��Ʈ�������̼�1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[12].name.c_str(), _skill->getSorceressSkill()[12].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[12].skillInfo.c_str(), _skill->getSorceressSkill()[12].skillInfo.size());
		break;
	case 13:
		IMAGEMANAGER->findAlphaImage("��Ʈ����Ʈ��1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[13].name.c_str(), _skill->getSorceressSkill()[13].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[13].skillInfo.c_str(), _skill->getSorceressSkill()[13].skillInfo.size());
		break;
	case 14:
		IMAGEMANAGER->findAlphaImage("Ǫ����������1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[14].name.c_str(), _skill->getSorceressSkill()[14].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[14].skillInfo.c_str(), _skill->getSorceressSkill()[14].skillInfo.size());
		break;
	case 15:
		IMAGEMANAGER->findAlphaImage("�����׳ͽ�1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[15].name.c_str(), _skill->getSorceressSkill()[15].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[15].skillInfo.c_str(), _skill->getSorceressSkill()[15].skillInfo.size());
		break;
	case 16:
		IMAGEMANAGER->findAlphaImage("����������1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[16].name.c_str(), _skill->getSorceressSkill()[16].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[16].skillInfo.c_str(), _skill->getSorceressSkill()[16].skillInfo.size());
		break;
	}

	SelectObject(getMemDC(), oldFont);
	DeleteObject(hFont);
}
void skillInfo::release(){}