#include "stdafx.h"
#include "guildScene.h"


guildScene::guildScene()
{
}


guildScene::~guildScene()
{
}

HRESULT guildScene::init(){
	///////////////////////�̹��� �ҷ�����//////////////////////
	//��� ���� �̹���
	//IMAGEMANAGER->addFrameImage("��������", "�̹���/����/���/��������.bmp", 16000, 7200, 10, 8, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("��尣��", "�̹���/����/���/��尣��.bmp", 627, 92, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("��帶ũ", "�̹���/����/���/��帶ũ.bmp", 208, 227, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("��ų������1", "�̹���/����/���/��ų������1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("��ų������2", "�̹���/����/���/��ų������2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("�����⼱����1", "�̹���/����/�����⼱����1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("�����⼱����2", "�̹���/����/�����⼱����2.bmp", 467, 80, true, RGB(255, 0, 255));
	//
	////�Ҽ�������ų,���뽺ų������ �̹���
	//IMAGEMANAGER->addImage("��ųâ���", "�̹���/����/���/��ųâ���.bmp", 1600, 146, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("��ųâ�ϴ�", "�̹���/����/���/��ųâ�ϴ�.bmp", 1600, 123, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("�Ҽ�������ų����Ʈ������", "�̹���/����/���/�Ҽ�������ų����Ʈ������.bmp", 4140, 1200,12,2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("���뽺ų������", "�̹���/����/���/���뽺ų������.bmp", 4212, 1248, 12, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("�Ҽ�������ų����Ʈ", "�̹���/����/���/�Ҽ�������ų����Ʈ.bmp", 400, 600, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("���뽺ų����Ʈ", "�̹���/����/���/���뽺ų����Ʈ.bmp", 400, 590, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("���ó��", "�̹���/����/���/���ó��.bmp", 0,0,250, 400, true, RGB(255, 0, 255),true);
	//IMAGEMANAGER->addAlphaImage("���ó��2", "�̹���/����/���/���ó��.bmp", 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("��ųâ�ߴ�", "�̹���/����/���/��ųâ�߰�.bmp", 1600, 631, true, RGB(255, 0, 255));
	//
	////�Ҽ�������ų
	//IMAGEMANAGER->addAlphaImage("��Ż�ۼҺ�", "�̹���/����/���/��Ż�ۼҺ�.bmp", 0,0,250, 400, true, RGB(255, 0, 255),true);
	//IMAGEMANAGER->addAlphaImage("����Ʈ��Ʈ", "�̹���/����/���/����Ʈ��Ʈ.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("�ܼ�Ʈ����Ʈ", "�̹���/����/���/�ܼ�Ʈ����Ʈ.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("��������Ʈ��", "�̹���/����/���/��������Ʈ��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("���̽�������", "�̹���/����/���/���̽�������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("�����ؼ�", "�̹���/����/���/�����ؼ�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("�׷���Ƽ", "�̹���/����/���/�׷���Ƽ.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("���Ŭ����", "�̹���/����/���/���Ŭ����.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("��������", "�̹���/����/���/��������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("���ڵ�", "�̹���/����/���/���ڵ�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("�ִϸ���Ʈ������", "�̹���/����/���/�ִϸ���Ʈ������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("�������̼�", "�̹���/����/���/�������̼�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("ũ������ƮǪ��", "�̹���/����/���/ũ������ƮǪ��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("Ŀ��", "�̹���/����/���/Ŀ��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("��Ʈ�������̼�", "�̹���/����/���/��Ʈ�������̼�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//
	////���� ��ų
	//IMAGEMANAGER->addAlphaImage("�����̵�", "�̹���/����/���/�����̵�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("�������", "�̹���/����/���/�������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("��彺�ھ", "�̹���/����/���/��彺�ھ.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("��Ʈ����Ʈ��", "�̹���/����/���/��Ʈ����Ʈ��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("Ǫ����������", "�̹���/����/���/Ǫ����������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("�����׳ͽ�", "�̹���/����/���/�����׳ͽ�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("����������", "�̹���/����/���/����������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("�̺��̵�", "�̹���/����/���/�̺��̵�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("����Ʈ������", "�̹���/����/���/����Ʈ������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//
	////��ȭ �̹���
	//IMAGEMANAGER->addAlphaImage("��ȭ����", "�̹���/talkBar.bmp", 1600, 118, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("no", "�̹���/no.bmp", 184, 185, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("yes", "�̹���/yes.bmp", 185, 185, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("no_check", "�̹���/no_check.bmp", 236, 234, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("yes_check", "�̹���/yes_check.bmp", 234, 235, true, RGB(255, 0, 255));

	IMAGEMANAGER->addAlphaImage("��ų������", "�̹���/����/���/��ų������.bmp", 1600, 113, false, RGB(0, 0, 0));
	IMAGEMANAGER->addAlphaImage("��������", "�̹���/����/���/��������.bmp", 1600, 113, false, RGB(0, 0, 0));
	IMAGEMANAGER->addAlphaImage("��ų����Ʈ����", "�̹���/����/���/��ų����Ʈ����.bmp", 1600, 113, false, RGB(0, 0, 0));


	//���������̱�
	KEYANIMANAGER->addDefaultFrameAnimation("��������", "��������", 15, true, true);
	KEYANIMANAGER->findAnimation("��������")->start();

	int arr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	KEYANIMANAGER->addArrayFrameAnimation("�Ҽ�������ų����Ʈ������", "�Ҽ�������ų����Ʈ������",arr1,12, 10, false,skillMoveOpen);
	int arr2[] = { 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	KEYANIMANAGER->addArrayFrameAnimation("�Ҽ�������ų����Ʈ�����Ӵݱ�", "�Ҽ�������ų����Ʈ������", arr2,12, 10, false, skillMoveClose);
	KEYANIMANAGER->addArrayFrameAnimation("���뽺ų������", "���뽺ų������", arr1, 12, 10, false, skillMoveOpen);
	KEYANIMANAGER->addArrayFrameAnimation("���뽺ų�����Ӵݱ�", "���뽺ų������", arr2, 12, 10, false, skillMoveClose);
	
	SOUNDMANAGER->addSound("���", "����/���.mp3", true, true);
	SOUNDMANAGER->addSound("��ų���", "����/��ų/��ų���.wav", false, false);
	SOUNDMANAGER->play("���",0.1f);

	sorceressSkillInit();
	commonSkillInit();
	
	_menuChoice = 0;
	_guildState = GUILD;
	_menuState = SKILL;
	_skillChioceState = SORCERESS;
	_skillListChoice = 0;
	_skillListX1 = 0;
	_skillListX2 = 0;
	_commonSkillListX1 = 0;
	_commonSkillListX2 = 0;
	_skillMoveX = 0;
	_skillMoveXMax = 0;

	_sorceressSkillChoice = 0;
	_sorceressSkillList = MENTAL_ABSORB;

	_bSkillLeftMove = false;
	_bSkillRightMove = false;
	_bSkillListMoveOpen = true;
	_bSkillListMoveClose = false;

	_pointError = false;
	_lvError = false;
	_masterError = false;
	_skillLearn = true;

	_skillPoint = INIDATA->loadDataInterger("PlayerData", "Skill", "SKILLPOINT");
	_lv = INIDATA->loadDataInterger("PlayerData", "State", "LEVEL");
	return S_OK;
}
void guildScene::update(){
	KEYANIMANAGER->update();
	switch (_guildState){
	case GUILD:
		guild();
		break;
	case SKILL_CHOICE:
		skillChoice();
		break;
	case SORCERESS_SKILL:
		sorceressSkill();
		break;
	case COMMON_SKILL:
		commonSkill();
		break;
	case SORCERESS_CONFIRM:
	case COMMON_CONFIRM:
		confirm();
		break;
	}

	//��ų����Ʈ ������ ����
	switch (_skillChioceState){
	case SORCERESS:
		if (!_bSkillListMoveOpen){
			if (_skillChioceState == SORCERESS || _skillChioceState == COMMON){
				_skillListX1 -= 4;
				_skillListX2 += 15;
				if (_skillListX2 > 1200) _skillListX2 = 1200;
				if (_skillListX1 < 50) _skillListX1 = 50;
			}
			else if (_skillChioceState == SKILL_CHOICE){
				_skillListX2 -= 15;
				if (_skillListX2 < 300) _skillListX2 = 300;
			}
		}

		if (_bSkillListMoveClose){
			if (_skillChioceState == SORCERESS || _skillChioceState == COMMON){
				_skillListX1 += 4;
				_skillListX2 -= 15;
				if (_skillListX2 < 300) _skillListX2 = 300;
				if (_skillListX1 > 300) _skillListX1 = 300;
			}
			else if (_skillChioceState == SKILL_CHOICE){
				_skillListX2 += 15;
				if (_skillListX2 < 300) _skillListX2 = 300;
			}
		}
		break;
	case COMMON:
		if (!_bSkillListMoveOpen){
			if (_skillChioceState == SORCERESS || _skillChioceState == COMMON){
				_skillListX1 -= 10;
				_skillListX2 += 4;
				if (_skillListX2 > 1200) _skillListX2 = 1200;
				if (_skillListX1 < 50) _skillListX1 = 50;
			}
			else if (_skillChioceState == SKILL_CHOICE){
				_skillListX2 -= 15;
				if (_skillListX2 < 300) _skillListX2 = 300;
			}
		}

		if (_bSkillListMoveClose){
			if (_skillChioceState == SORCERESS || _skillChioceState == COMMON){
				_skillListX1 += 10;
				_skillListX2 -= 4;
				if (_skillListX2 < 900) _skillListX2 = 900;
				if (_skillListX1 > 900) _skillListX1 = 900;
			}
			else if (_skillChioceState == SKILL_CHOICE){
				_skillListX2 += 15;
				if (_skillListX2 < 900) _skillListX2 = 900;
			}
		}
		break;
	}
	
}
void guildScene::render(){
	
	guildRender();
	skillChooseRender();
	confirmRender();

	
	
}
void guildScene::release(){
	
}

void guildScene::skillMoveOpen(void* obj){
	_bSkillListMoveOpen = true;
}

void guildScene::skillMoveClose(void* obj){
	_bSkillListMoveClose = false;
	_guildState = SKILL_CHOICE;

	_sorceressSkillChoice = 0;
	_skillMoveXMax = 0;
	_skillMoveX = 0;
}

void guildScene::guild(){
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
		case SKILL:
			_guildState = SKILL_CHOICE;
			break;
		case GUILDEXIT:
			KEYANIMANAGER->findAnimation("��������")->stop();
			SOUNDMANAGER->allRemove();
			dataSave();
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
		_menuState = SKILL;
		break;
	case 1:
		_menuState = GUILDEXIT;
	}

}
void guildScene::skillChoice(){
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
		_skillListChoice -= 1;
		if (_skillListChoice == -1) _skillListChoice = 1;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
		_skillListChoice += 1;
		if (_skillListChoice == 2) _skillListChoice = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('A')){
		
		switch (_skillChioceState){
		case SORCERESS:
			_skillListX1 = 300;
			_skillListX2 = 300;
			_guildState = SORCERESS_SKILL;
			_bSkillListMoveOpen = false;
			KEYANIMANAGER->findAnimation("�Ҽ�������ų����Ʈ������")->start();
			break;
		case COMMON:
			_skillListX1 = 900;
			_skillListX2 = 900;
			_guildState = COMMON_SKILL;
			_bSkillListMoveOpen = false;
			KEYANIMANAGER->findAnimation("���뽺ų������")->start();
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('S')){

	}

	if (KEYMANAGER->isOnceKeyDown('Z')){

	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		_menuChoice = 0;
		_guildState = GUILD;
	}

	//�������� ���� ���
	switch (_skillListChoice){
	case 0:
		_skillChioceState = SORCERESS;
		break;
	case 1:
		_skillChioceState = COMMON;
		break;
	}
}
void guildScene::sorceressSkill(){
	if (!(_bSkillLeftMove || _bSkillRightMove) && _bSkillListMoveOpen &&!_bSkillListMoveClose){
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
			_pointError = false;
			_lvError = false;
			_masterError = false;
			_sorceressSkillChoice -= 1;
			_bSkillLeftMove = true;
			_skillMoveXMax += 280;
			if (_skillMoveXMax > 0) _skillMoveXMax = 0;
			if (_sorceressSkillChoice == -1) _sorceressSkillChoice =0;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
			_pointError = false;
			_lvError = false;
			_masterError = false;
			_sorceressSkillChoice += 1;
			_bSkillRightMove = true;
			_skillMoveXMax -= 280;
			if (_skillMoveXMax < -3360) _skillMoveXMax = -3360;
			if (_sorceressSkillChoice == 13) _sorceressSkillChoice = 12;
		}
		//if (){
			if (KEYMANAGER->isOnceKeyDown('A')){
				if (_pointError || _lvError || _masterError){
					_pointError = false;
					_lvError = false;
					_masterError = false;
				}
				//��ų ����Ʈ�� ���ڸ��� �ߴ� ����
				if (_skillPoint-_sorceressSkill[_sorceressSkillChoice].sKillPointCondition[_sorceressSkill[_sorceressSkillChoice].skillLV]<0){
					_pointError = true;
				}
				////������ �����ϸ� �ߴ� ����
				else if (_lv - _sorceressSkill[_sorceressSkillChoice].LVCondition[_sorceressSkill[_sorceressSkillChoice].skillLV] < 0){
					_lvError = true;
				}
				////��ų �������� �ߴ� ����
				else if (_sorceressSkill[_sorceressSkillChoice].skillLV == _sorceressSkill[_sorceressSkillChoice].skillLVMax){
					_masterError = true;
				}
				else{
				_guildState = SORCERESS_CONFIRM;
				}

			}
		//}
		if (KEYMANAGER->isOnceKeyDown('S')){
			_pointError = false;
			_lvError = false;
			_masterError = false;
		}

		if (KEYMANAGER->isOnceKeyDown('Z')){
			_pointError = false;
			_lvError = false;
			_masterError = false;
		}
		if (_bSkillListMoveOpen){
			if (KEYMANAGER->isOnceKeyDown('X')){
				_pointError = false;
				_lvError = false;
				_masterError = false;
				_bSkillListMoveClose = true;
				if (!KEYANIMANAGER->findAnimation("�Ҽ�������ų����Ʈ�����Ӵݱ�")->isPlay())
					KEYANIMANAGER->findAnimation("�Ҽ�������ų����Ʈ�����Ӵݱ�")->start();
				
			}
		}

		if (_skillLearnConfirm){
			switch (_sorceressSkillList){
			case MENTAL_ABSORB:
				break;
			case EXTRACT:
				break;
			case CONCENTRATE:
				break;
			case MAGIC_POINT_UP:
				break;
			case ICE_PRISION:
				break;
			case PROTECTION:
				break;
			case GRAVITY:
				break;
			case THUNDER_CLOUD:
				break;
			case ROCK_PRESS:
				break;
			case BLIZZARD:
				break;
			case ANIMATE_SKELTON:
				break;
			case RAVITATION:
				break;
			case CREATE_FOOD:
				break;
			case CURSE:
				break;
			case PETRIFICATION:
				break;
			}
			_skillLearnConfirm = false;
		}
	}
	//�������� ���� ���
	switch (_sorceressSkillChoice){
	case 0:
		_sorceressSkillList = MENTAL_ABSORB;
		break;
	case 1:
		_sorceressSkillList = EXTRACT;
		break;
	case 2:
		_sorceressSkillList = CONCENTRATE;
		break;
	case 3:
		_sorceressSkillList = MAGIC_POINT_UP;
		break;
	case 4:
		_sorceressSkillList = ICE_PRISION;
		break;
	case 5:
		_sorceressSkillList = PROTECTION;
		break;
	case 6:
		_sorceressSkillList = GRAVITY;
		break;
	case 7:
		_sorceressSkillList = THUNDER_CLOUD;
		break;
	case 8:
		_sorceressSkillList = ROCK_PRESS;
		break;
	case 9:
		_sorceressSkillList = BLIZZARD;
		break;
	case 10:
		_sorceressSkillList = RAVITATION;
		break;
	case 11:
		_sorceressSkillList = CREATE_FOOD;
		break;
	case 12:
		_sorceressSkillList = PETRIFICATION;
		break;
	}

	if (_bSkillLeftMove){
		_skillMoveX += SKILLMOVEX;
		if (_skillMoveX > _skillMoveXMax){
			_skillMoveX = _skillMoveXMax;
			_bSkillLeftMove = false;
		}
	}

	if (_bSkillRightMove){
		_skillMoveX -= SKILLMOVEX;
		if (_skillMoveX < _skillMoveXMax){
			_skillMoveX = _skillMoveXMax;
			_bSkillRightMove = false;
		}
	}
}
void guildScene::commonSkill(){
	if (!(_bSkillLeftMove || _bSkillRightMove) && _bSkillListMoveOpen &&!_bSkillListMoveClose){
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
			_pointError = false;
			_lvError = false;
			_masterError = false;
			_commonSkillChoice -= 1;
			_bSkillLeftMove = true;
			_skillMoveXMax += 280;
			if (_skillMoveXMax > 0) _skillMoveXMax = 0;
			if (_commonSkillChoice == -1) _commonSkillChoice = 0;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
			_pointError = false;
			_lvError = false;
			_masterError = false;
			_commonSkillChoice += 1;
			_bSkillRightMove = true;
			_skillMoveXMax -= 280;
			if (_skillMoveXMax < -280*3) _skillMoveXMax = -280*3;
			if (_commonSkillChoice == 4) _commonSkillChoice = 3;
		}
		//if (){
		if (KEYMANAGER->isOnceKeyDown('A')){
			if (_pointError || _lvError || _masterError){
				_pointError = false;
				_lvError = false;
				_masterError = false;
			}
			//��ų ����Ʈ�� ���ڸ��� �ߴ� ����
			if (_skillPoint - _commonSkill[_commonSkillChoice].sKillPointCondition[_commonSkill[_commonSkillChoice].skillLV]<0){
				_pointError = true;
			}
			////������ �����ϸ� �ߴ� ����
			else if (_lv - _commonSkill[_commonSkillChoice].LVCondition[_commonSkill[_commonSkillChoice].skillLV] < 0){
				_lvError = true;
			}
			////��ų �������� �ߴ� ����
			else if (_commonSkill[_commonSkillChoice].skillLV == _commonSkill[_commonSkillChoice].skillLVMax){
				_masterError = true;
			}
			else{
				_guildState = COMMON_CONFIRM;
			}

		}
		//}
		if (KEYMANAGER->isOnceKeyDown('S')){
			_pointError = false;
			_lvError = false;
			_masterError = false;
		}

		if (KEYMANAGER->isOnceKeyDown('Z')){
			_pointError = false;
			_lvError = false;
			_masterError = false;
		}
		if (_bSkillListMoveOpen){
			if (KEYMANAGER->isOnceKeyDown('X')){
				_pointError = false;
				_lvError = false;
				_masterError = false;
				_bSkillListMoveClose = true;
				if (!KEYANIMANAGER->findAnimation("���뽺ų�����Ӵݱ�")->isPlay())
					KEYANIMANAGER->findAnimation("���뽺ų�����Ӵݱ�")->start();

			}
		}

		if (_skillLearnConfirm){
			switch (_sorceressSkillList){
			case MENTAL_ABSORB:
				break;
			case EXTRACT:
				break;
			case CONCENTRATE:
				break;
			case MAGIC_POINT_UP:
				break;
			case ICE_PRISION:
				break;
			case PROTECTION:
				break;
			case GRAVITY:
				break;
			case THUNDER_CLOUD:
				break;
			case ROCK_PRESS:
				break;
			case BLIZZARD:
				break;
			case ANIMATE_SKELTON:
				break;
			case RAVITATION:
				break;
			case CREATE_FOOD:
				break;
			case CURSE:
				break;
			case PETRIFICATION:
				break;
			}
			_skillLearnConfirm = false;
		}
	}
	//�������� ���� ���
	switch (_sorceressSkillList){
	case 0:
		_sorceressSkillList = MENTAL_ABSORB;
		break;
	case 1:
		_sorceressSkillList = EXTRACT;
		break;
	case 2:
		_sorceressSkillList = CONCENTRATE;
		break;
	case 3:
		_sorceressSkillList = MAGIC_POINT_UP;
		break;
	case 4:
		_sorceressSkillList = ICE_PRISION;
		break;
	case 5:
		_sorceressSkillList = PROTECTION;
		break;
	case 6:
		_sorceressSkillList = GRAVITY;
		break;
	case 7:
		_sorceressSkillList = THUNDER_CLOUD;
		break;
	case 8:
		_sorceressSkillList = ROCK_PRESS;
		break;
	case 9:
		_sorceressSkillList = BLIZZARD;
		break;
	case 10:
		_sorceressSkillList = ANIMATE_SKELTON;
		break;
	case 11:
		_sorceressSkillList = RAVITATION;
		break;
	case 12:
		_sorceressSkillList = CREATE_FOOD;
		break;
	case 13:
		_sorceressSkillList = CURSE;
		break;
	case 14:
		_sorceressSkillList = PETRIFICATION;
		break;
	}

	if (_bSkillLeftMove){
		_skillMoveX += SKILLMOVEX;
		if (_skillMoveX > _skillMoveXMax){
			_skillMoveX = _skillMoveXMax;
			_bSkillLeftMove = false;
		}
	}

	if (_bSkillRightMove){
		_skillMoveX -= SKILLMOVEX;
		if (_skillMoveX < _skillMoveXMax){
			_skillMoveX = _skillMoveXMax;
			_bSkillRightMove = false;
		}
	}
}

void guildScene::sorceressSkillInit(){
	memset(_sorceressSkill, 0, sizeof(_sorceressSkill));

	_sorceressSkill[0].name = "��Ż �ۼҺ�";
	_sorceressSkill[0].LVCondition[0] = 1;
	_sorceressSkill[0].LVCondition[1] = 9;
	_sorceressSkill[0].LVCondition[2] = 18;
	_sorceressSkill[0].LVCondition[3] = 27;
	_sorceressSkill[0].LVCondition[4] = 36;
	_sorceressSkill[0].LVCondition[5] = 45;
	_sorceressSkill[0].LVCondition[6] = 54;
	_sorceressSkill[0].LVCondition[7] = 63;
	_sorceressSkill[0].LVCondition[8] = 72;
	_sorceressSkill[0].LVCondition[9] = 81;
	_sorceressSkill[0].sKillPointCondition[0] = 1;
	_sorceressSkill[0].sKillPointCondition[1] = 1;
	_sorceressSkill[0].sKillPointCondition[2] = 1;
	_sorceressSkill[0].sKillPointCondition[3] = 2;
	_sorceressSkill[0].sKillPointCondition[4] = 2;
	_sorceressSkill[0].sKillPointCondition[5] = 3;
	_sorceressSkill[0].sKillPointCondition[6] = 3;
	_sorceressSkill[0].sKillPointCondition[7] = 4;
	_sorceressSkill[0].sKillPointCondition[8] = 4;
	_sorceressSkill[0].sKillPointCondition[9] = 5;
	_sorceressSkill[0].skillLV = INIDATA->loadDataInterger("PlayerData","Skill","mental_absorb");
	_sorceressSkill[0].skillLVMax = 10;
	_sorceressSkill[0].skillInfo = "���� ����Ʈ���� �� MP�� ȸ���ȴ�";

	_sorceressSkill[1].name = "����Ʈ��Ʈ";
	_sorceressSkill[1].LVCondition[0] = 1;
	_sorceressSkill[1].LVCondition[1] = 12;
	_sorceressSkill[1].LVCondition[2] = 24;
	_sorceressSkill[1].LVCondition[3] = 36;
	_sorceressSkill[1].LVCondition[4] = 48;
	_sorceressSkill[1].LVCondition[5] = 50;
	_sorceressSkill[1].LVCondition[6] = 62;
	_sorceressSkill[1].sKillPointCondition[0] = 1;
	_sorceressSkill[1].sKillPointCondition[1] = 1;
	_sorceressSkill[1].sKillPointCondition[2] = 2;
	_sorceressSkill[1].sKillPointCondition[3] = 2;
	_sorceressSkill[1].sKillPointCondition[4] = 3;
	_sorceressSkill[1].sKillPointCondition[5] = 3;
	_sorceressSkill[1].sKillPointCondition[6] = 5;
	_sorceressSkill[1].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "extract");
	_sorceressSkill[1].skillLVMax = 7;
	_sorceressSkill[1].skillInfo = "���� ���� MP ȸ������ �����Ѵ�";

	_sorceressSkill[2].name = "�ܼ�Ʈ����Ʈ";
	_sorceressSkill[2].LVCondition[0] = 1;
	_sorceressSkill[2].LVCondition[1] = 20;
	_sorceressSkill[2].LVCondition[2] = 40;
	_sorceressSkill[2].LVCondition[3] = 60;
	_sorceressSkill[2].LVCondition[4] = 80;
	_sorceressSkill[2].sKillPointCondition[0] = 1;
	_sorceressSkill[2].sKillPointCondition[1] = 1;
	_sorceressSkill[2].sKillPointCondition[2] = 2;
	_sorceressSkill[2].sKillPointCondition[3] = 3;
	_sorceressSkill[2].sKillPointCondition[4] = 5;
	_sorceressSkill[2].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "concentrate");
	_sorceressSkill[2].skillLVMax = 5;
	_sorceressSkill[2].skillInfo = "MP ���� �ӵ��� ����Ѵ�";

	_sorceressSkill[3].name = "���� ����Ʈ ��";
	_sorceressSkill[3].LVCondition[0] = 1;
	_sorceressSkill[3].LVCondition[1] = 10;
	_sorceressSkill[3].LVCondition[2] = 20;
	_sorceressSkill[3].LVCondition[3] = 30;
	_sorceressSkill[3].LVCondition[4] = 40;
	_sorceressSkill[3].sKillPointCondition[0] = 1;
	_sorceressSkill[3].sKillPointCondition[1] = 1;
	_sorceressSkill[3].sKillPointCondition[2] = 2;
	_sorceressSkill[3].sKillPointCondition[3] = 3;
	_sorceressSkill[3].sKillPointCondition[4] = 5;
	_sorceressSkill[3].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "magic_point_up");
	_sorceressSkill[3].skillLVMax = 5;
	_sorceressSkill[3].skillInfo = "MP �ִ�ġ�� �����Ѵ�";

	_sorceressSkill[4].name = "���̽� ������";
	_sorceressSkill[4].LVCondition[0] = 1;
	_sorceressSkill[4].LVCondition[1] = 30;
	_sorceressSkill[4].LVCondition[2] = 60;
	_sorceressSkill[4].sKillPointCondition[0] = 1;
	_sorceressSkill[4].sKillPointCondition[1] = 3;
	_sorceressSkill[4].sKillPointCondition[2] = 5;
	_sorceressSkill[4].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "ice_prision");
	_sorceressSkill[4].skillLVMax = 3;
	_sorceressSkill[4].skillInfo = "���� ���δ� ������ �߻���Ų��";

	_sorceressSkill[5].name = "�����ؼ�";
	_sorceressSkill[5].LVCondition[0] = 1;
	_sorceressSkill[5].LVCondition[1] = 7;
	_sorceressSkill[5].LVCondition[2] = 15;
	_sorceressSkill[5].LVCondition[3] = 25;
	_sorceressSkill[5].LVCondition[4] = 35;
	_sorceressSkill[5].sKillPointCondition[0] = 1;
	_sorceressSkill[5].sKillPointCondition[1] = 1;
	_sorceressSkill[5].sKillPointCondition[2] = 2;
	_sorceressSkill[5].sKillPointCondition[3] = 3;
	_sorceressSkill[5].sKillPointCondition[4] = 5;
	_sorceressSkill[5].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "protection");
	_sorceressSkill[5].skillLVMax = 5;
	_sorceressSkill[5].skillInfo = "�Ʊ����� ������ ���и� �ο��Ѵ�";

	_sorceressSkill[6].name = "�׷���Ƽ";
	_sorceressSkill[6].LVCondition[0] = 1;
	_sorceressSkill[6].LVCondition[1] = 20;
	_sorceressSkill[6].LVCondition[2] = 40;
	_sorceressSkill[6].sKillPointCondition[0] = 1;
	_sorceressSkill[6].sKillPointCondition[1] = 1;
	_sorceressSkill[6].sKillPointCondition[2] = 2;
	_sorceressSkill[6].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "gravity");
	_sorceressSkill[6].skillLVMax = 3;
	_sorceressSkill[6].skillInfo = "�߷����� �߻���Ų��";

	_sorceressSkill[7].name = "��� Ŭ����";
	_sorceressSkill[7].LVCondition[0] = 1;
	_sorceressSkill[7].LVCondition[1] = 8;
	_sorceressSkill[7].LVCondition[2] = 16;
	_sorceressSkill[7].LVCondition[3] = 24;
	_sorceressSkill[7].LVCondition[4] = 32;
	_sorceressSkill[7].LVCondition[5] = 40;
	_sorceressSkill[7].LVCondition[6] = 48;
	_sorceressSkill[7].sKillPointCondition[0] = 1;
	_sorceressSkill[7].sKillPointCondition[1] = 1;
	_sorceressSkill[7].sKillPointCondition[2] = 2;
	_sorceressSkill[7].sKillPointCondition[3] = 2;
	_sorceressSkill[7].sKillPointCondition[4] = 3;
	_sorceressSkill[7].sKillPointCondition[5] = 3;
	_sorceressSkill[7].sKillPointCondition[6] = 5;
	_sorceressSkill[7].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "thunder_cloud");
	_sorceressSkill[7].skillLVMax = 7;
	_sorceressSkill[7].skillInfo = "������ ����Ʈ���� ������ �߻���Ų��";

	_sorceressSkill[8].name = "�� ������";
	_sorceressSkill[8].LVCondition[0] = 1;
	_sorceressSkill[8].LVCondition[1] = 6;
	_sorceressSkill[8].LVCondition[2] = 12;
	_sorceressSkill[8].LVCondition[3] = 22;
	_sorceressSkill[8].LVCondition[4] = 38;
	_sorceressSkill[8].LVCondition[5] = 42;
	_sorceressSkill[8].LVCondition[6] = 52;
	_sorceressSkill[8].sKillPointCondition[0] = 1;
	_sorceressSkill[8].sKillPointCondition[1] = 1;
	_sorceressSkill[8].sKillPointCondition[2] = 2;
	_sorceressSkill[8].sKillPointCondition[3] = 2;
	_sorceressSkill[8].sKillPointCondition[4] = 3;
	_sorceressSkill[8].sKillPointCondition[5] = 3;
	_sorceressSkill[8].sKillPointCondition[6] = 5;
	_sorceressSkill[8].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "rock_press");
	_sorceressSkill[8].skillLVMax = 7;
	_sorceressSkill[8].skillInfo = "�ϼ��� ����Ʈ����";

	_sorceressSkill[9].name = "���ڵ�";
	_sorceressSkill[9].LVCondition[0] = 1;
	_sorceressSkill[9].LVCondition[1] = 20;
	_sorceressSkill[9].LVCondition[2] = 40;
	_sorceressSkill[9].LVCondition[3] = 60;
	_sorceressSkill[9].LVCondition[4] = 80;
	_sorceressSkill[9].sKillPointCondition[0] = 1;
	_sorceressSkill[9].sKillPointCondition[1] = 1;
	_sorceressSkill[9].sKillPointCondition[2] = 2;
	_sorceressSkill[9].sKillPointCondition[3] = 3;
	_sorceressSkill[9].sKillPointCondition[4] = 5;
	_sorceressSkill[9].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "blizzard");
	_sorceressSkill[9].skillLVMax = 5;
	_sorceressSkill[9].skillInfo = "���� �󸮴� ������ �ҷ�����Ų��";

	_sorceressSkill[10].name = "�������̼�";
	_sorceressSkill[10].LVCondition[0] = 1;
	_sorceressSkill[10].LVCondition[1] = 31;
	_sorceressSkill[10].LVCondition[2] = 61;
	_sorceressSkill[10].sKillPointCondition[0] = 1;
	_sorceressSkill[10].sKillPointCondition[1] = 3;
	_sorceressSkill[10].sKillPointCondition[2] = 5;
	_sorceressSkill[10].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "ravitation");
	_sorceressSkill[10].skillLVMax = 3;
	_sorceressSkill[10].skillInfo = "���� ������ �� �� �ִ�";

	_sorceressSkill[11].name = "ũ������Ʈ Ǫ��";
	_sorceressSkill[11].LVCondition[0] = 1;
	_sorceressSkill[11].LVCondition[1] = 21;
	_sorceressSkill[11].LVCondition[2] = 41;
	_sorceressSkill[11].LVCondition[3] = 61;
	_sorceressSkill[11].LVCondition[4] = 81;
	_sorceressSkill[11].sKillPointCondition[0] = 1;
	_sorceressSkill[11].sKillPointCondition[1] = 1;
	_sorceressSkill[11].sKillPointCondition[2] = 2;
	_sorceressSkill[11].sKillPointCondition[3] = 2;
	_sorceressSkill[11].sKillPointCondition[4] = 4;
	_sorceressSkill[11].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "create_food");
	_sorceressSkill[11].skillLVMax = 5;
	_sorceressSkill[11].skillInfo = "������ ������ �����";

	_sorceressSkill[12].name = "��Ʈ�������̼�";
	_sorceressSkill[12].LVCondition[0] = 1;
	_sorceressSkill[12].LVCondition[1] = 11;
	_sorceressSkill[12].LVCondition[2] = 21;
	_sorceressSkill[12].LVCondition[3] = 31;
	_sorceressSkill[12].LVCondition[4] = 41;
	_sorceressSkill[12].LVCondition[5] = 51;
	_sorceressSkill[12].LVCondition[6] = 61;
	_sorceressSkill[12].sKillPointCondition[0] = 1;
	_sorceressSkill[12].sKillPointCondition[1] = 1;
	_sorceressSkill[12].sKillPointCondition[2] = 2;
	_sorceressSkill[12].sKillPointCondition[3] = 2;
	_sorceressSkill[12].sKillPointCondition[4] = 3;
	_sorceressSkill[12].sKillPointCondition[5] = 3;
	_sorceressSkill[12].sKillPointCondition[6] = 5;
	_sorceressSkill[12].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "petrification");
	_sorceressSkill[12].skillLVMax = 7;
	_sorceressSkill[12].skillInfo = "���� ��ȭ ���·� �����";

}
void guildScene::commonSkillInit(){
	memset(_commonSkill, 0, sizeof(_commonSkill));

	_commonSkill[0].name = "��Ʈ ����Ʈ ��";
	_commonSkill[0].LVCondition[0] = 1;
	_commonSkill[0].LVCondition[1] = 7;
	_commonSkill[0].LVCondition[2] = 13;
	_commonSkill[0].LVCondition[3] = 19;
	_commonSkill[0].LVCondition[4] = 25;
	_commonSkill[0].LVCondition[5] = 31;
	_commonSkill[0].LVCondition[6] = 38;
	_commonSkill[0].LVCondition[7] = 45;
	_commonSkill[0].LVCondition[8] = 52;
	_commonSkill[0].LVCondition[9] = 59;
	_commonSkill[0].sKillPointCondition[0] = 1;
	_commonSkill[0].sKillPointCondition[1] = 1;
	_commonSkill[0].sKillPointCondition[2] = 1;
	_commonSkill[0].sKillPointCondition[3] = 2;
	_commonSkill[0].sKillPointCondition[4] = 2;
	_commonSkill[0].sKillPointCondition[5] = 3;
	_commonSkill[0].sKillPointCondition[6] = 3;
	_commonSkill[0].sKillPointCondition[7] = 4;
	_commonSkill[0].sKillPointCondition[8] = 4;
	_commonSkill[0].sKillPointCondition[9] = 6;
	_commonSkill[0].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "hit_point_up");
	_commonSkill[0].skillLVMax = 10;
	_commonSkill[0].skillInfo = "HP �ִ�ġ�� �����Ѵ�";

	_commonSkill[1].name = "Ǫ�� ���������";
	_commonSkill[1].LVCondition[0] = 1;
	_commonSkill[1].LVCondition[1] = 11;
	_commonSkill[1].LVCondition[2] = 24;
	_commonSkill[1].LVCondition[3] = 37;
	_commonSkill[1].LVCondition[4] = 51;
	_commonSkill[1].sKillPointCondition[0] = 1;
	_commonSkill[1].sKillPointCondition[1] = 1;
	_commonSkill[1].sKillPointCondition[2] = 2;
	_commonSkill[1].sKillPointCondition[3] = 3;
	_commonSkill[1].sKillPointCondition[4] = 4;
	_commonSkill[1].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "food_psytology");;
	_commonSkill[1].skillLVMax = 5;
	_commonSkill[1].skillInfo = "������ ȸ������ �����Ѵ�";

	_commonSkill[2].name = "�����׳ͽ�";
	_commonSkill[2].LVCondition[0] = 1;
	_commonSkill[2].LVCondition[1] = 6;
	_commonSkill[2].LVCondition[2] = 13;
	_commonSkill[2].LVCondition[3] = 23;
	_commonSkill[2].LVCondition[4] = 34;
	_commonSkill[2].sKillPointCondition[0] = 1;
	_commonSkill[2].sKillPointCondition[1] = 1;
	_commonSkill[2].sKillPointCondition[2] = 2;
	_commonSkill[2].sKillPointCondition[3] = 3;
	_commonSkill[2].sKillPointCondition[4] = 4;
	_commonSkill[2].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance");;
	_commonSkill[2].skillLVMax = 5;
	_commonSkill[2].skillInfo = "�����۵��� �� ��� �� �� �ִ�";

	_commonSkill[3].name = "������ ����";
	_commonSkill[3].LVCondition[0] = 1;
	_commonSkill[3].LVCondition[1] = 9;
	_commonSkill[3].LVCondition[2] = 16;
	_commonSkill[3].LVCondition[3] = 22;
	_commonSkill[3].LVCondition[4] = 29;
	_commonSkill[3].LVCondition[5] = 36;
	_commonSkill[3].LVCondition[6] = 44;
	_commonSkill[3].sKillPointCondition[0] = 1;
	_commonSkill[3].sKillPointCondition[1] = 1;
	_commonSkill[3].sKillPointCondition[2] = 2;
	_commonSkill[3].sKillPointCondition[3] = 2;
	_commonSkill[3].sKillPointCondition[4] = 3;
	_commonSkill[3].sKillPointCondition[5] = 3;
	_commonSkill[3].sKillPointCondition[6] = 5;
	_commonSkill[3].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "item_user");
	_commonSkill[3].skillLVMax = 7;
	_commonSkill[3].skillInfo = "������ ��� �� ü���� ȸ���Ѵ�";


}

void guildScene::guildRender(){
	///////////////��ų����� ������ �����ִ� â/////////////////
	IMAGEMANAGER->findImage("��������")->aniRender(getMemDC(), 0, 0, KEYANIMANAGER->findAnimation("��������"));

	IMAGEMANAGER->findImage("��尣��")->render(getMemDC(), 0, -11);
	IMAGEMANAGER->findImage("��帶ũ")->render(getMemDC(), 210, 50);

	switch (_menuState){
	case SKILL:
		IMAGEMANAGER->findAlphaImage("��ų������2")->alphaRender(getMemDC(), 80, 280, 200);
		IMAGEMANAGER->findAlphaImage("�����⼱����1")->alphaRender(getMemDC(), 80, 350, 125);
		break;
	case GUILDEXIT:
		IMAGEMANAGER->findAlphaImage("��ų������1")->alphaRender(getMemDC(), 80, 280, 125);
		IMAGEMANAGER->findAlphaImage("�����⼱����2")->alphaRender(getMemDC(), 80, 350, 200);
		break;
	}
}
void guildScene::skillChooseRender(){
	//////////////////////////��ųâ///////////////////////////
	if (_guildState != GUILD){
		IMAGEMANAGER->findImage("��ųâ���")->render(getMemDC(), 0, 0);
		IMAGEMANAGER->findAlphaImage("��ųâ�ߴ�")->alphaRender(getMemDC(), 0, 147, 125);
		IMAGEMANAGER->findImage("��ųâ�ϴ�")->render(getMemDC(), 0, 777);
	}


	switch (_guildState){
	case SKILL_CHOICE:	//�Ҽ����� ��ų�� ����� ���� ��ų�� ����� �����ִ� â
		switch (_skillChioceState){
		case SORCERESS:
			IMAGEMANAGER->findAlphaImage("�Ҽ�������ų����Ʈ")->alphaRender(getMemDC(), 300, 165, 255);
			IMAGEMANAGER->findAlphaImage("���뽺ų����Ʈ")->alphaRender(getMemDC(), 900, 165, 125);
			break;
		case COMMON:
			IMAGEMANAGER->findAlphaImage("�Ҽ�������ų����Ʈ")->alphaRender(getMemDC(), 300, 165, 125);
			IMAGEMANAGER->findAlphaImage("���뽺ų����Ʈ")->alphaRender(getMemDC(), 900, 165, 255);
			break;
		}
		break;

	case SORCERESS_SKILL:	//�Ҽ����� ��ųâ
	case SORCERESS_CONFIRM:
		sorceressSkillRender();
		break;
	case COMMON_SKILL:		//���� ��ųâ
	case COMMON_CONFIRM:
		commonSkillRender();
		break;
	}

	



}
void guildScene::sorceressSkillRender(){
	
	if (_bSkillListMoveOpen){
		//��ų ���� ����
		for (int i = _sorceressSkill[0].skillLV; i > 1; i--){
			int x = 670 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("��Ż�ۼҺ�")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[1].skillLV; i > 1; i--){
			int x = 950 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("����Ʈ��Ʈ")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[2].skillLV; i > 1; i--){
			int x = 1230 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("�ܼ�Ʈ����Ʈ")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[3].skillLV; i > 1; i--){
			int x = 1510 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("��������Ʈ��")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[4].skillLV; i > 1; i--){
			int x = 1790 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("���̽�������")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[5].skillLV; i > 1; i--){
			int x = 2070 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("�����ؼ�4")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[6].skillLV; i > 1; i--){
			int x = 2350 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("�׷���Ƽ")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[7].skillLV; i > 1; i--){
			int x = 2630 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("���Ŭ����")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[8].skillLV; i > 1; i--){
			int x = 2910 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("��������")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[9].skillLV; i > 1; i--){
			int x = 3190 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("���ڵ�4")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[10].skillLV; i > 1; i--){
			int x = 3470 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
				IMAGEMANAGER->findAlphaImage("�������̼�")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[11].skillLV; i > 1; i--){
			int x = 3750 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
				IMAGEMANAGER->findAlphaImage("ũ������ƮǪ��")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[12].skillLV; i > 1; i--){
			int x = 4030 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
				IMAGEMANAGER->findAlphaImage("��Ʈ�������̼�")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}


		int x;

		x = 670 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[0].skillLV==0)
				IMAGEMANAGER->findAlphaImage("��Ż�ۼҺ�")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("��Ż�ۼҺ�")->alphaRender(getMemDC(), x, 300, 170);
		}
		
		x = 950 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[1].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("����Ʈ��Ʈ")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("����Ʈ��Ʈ")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 1230 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[2].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("�ܼ�Ʈ����Ʈ")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("�ܼ�Ʈ����Ʈ")->alphaRender(getMemDC(), x, 300, 170);
		}
		
		x = 1510 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[3].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("��������Ʈ��")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("��������Ʈ��")->alphaRender(getMemDC(), x, 300, 170);
		}
		
		x = 1790 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[4].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("���̽�������")->alphaRender(getMemDC(),x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("���̽�������")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 2070 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[5].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("�����ؼ�4")->alphaRender(getMemDC(),x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("�����ؼ�4")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 2350 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[6].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("�׷���Ƽ")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("�׷���Ƽ")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 2630 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[7].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("���Ŭ����")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("���Ŭ����")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 2910 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[8].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("��������")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("��������")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 3190 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[9].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("���ڵ�4")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("���ڵ�4")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 3470 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[10].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("�������̼�")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("�������̼�")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 3750 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[11].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("ũ������ƮǪ��")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("ũ������ƮǪ��")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 4030 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[12].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("��Ʈ�������̼�")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("��Ʈ�������̼�")->alphaRender(getMemDC(), x, 300, 170);
		}

		switch (_sorceressSkillList){
		case MENTAL_ABSORB:
			IMAGEMANAGER->findAlphaImage("��Ż�ۼҺ�")->alphaRender(getMemDC(), 670 + _skillMoveX, 300, 255);
			break;
		case EXTRACT:	
			IMAGEMANAGER->findAlphaImage("����Ʈ��Ʈ")->alphaRender(getMemDC(), 950 + _skillMoveX, 300, 255);
			break;
		case CONCENTRATE:
			IMAGEMANAGER->findAlphaImage("�ܼ�Ʈ����Ʈ")->alphaRender(getMemDC(), 1230 + _skillMoveX, 300, 255);
			break;
		case MAGIC_POINT_UP:
			IMAGEMANAGER->findAlphaImage("��������Ʈ��")->alphaRender(getMemDC(), 1510 + _skillMoveX, 300, 255);
			break;
		case ICE_PRISION:
			IMAGEMANAGER->findAlphaImage("���̽�������")->alphaRender(getMemDC(), 1790 + _skillMoveX, 300, 255);
			break;
		case PROTECTION:
			IMAGEMANAGER->findAlphaImage("�����ؼ�4")->alphaRender(getMemDC(), 2070 + _skillMoveX, 300, 255);
			break;
		case GRAVITY:
			IMAGEMANAGER->findAlphaImage("�׷���Ƽ")->alphaRender(getMemDC(), 2350 + _skillMoveX, 300, 255);
			break;
		case THUNDER_CLOUD:
			IMAGEMANAGER->findAlphaImage("���Ŭ����")->alphaRender(getMemDC(), 2630 + _skillMoveX, 300, 255);
			break;
		case ROCK_PRESS:
			IMAGEMANAGER->findAlphaImage("��������")->alphaRender(getMemDC(), 2910 + _skillMoveX, 300, 255);
			break;
		case BLIZZARD:
			IMAGEMANAGER->findAlphaImage("���ڵ�4")->alphaRender(getMemDC(), 3190 + _skillMoveX, 300, 255);
			break;
		case RAVITATION:
			IMAGEMANAGER->findAlphaImage("�������̼�")->alphaRender(getMemDC(), 3470 + _skillMoveX, 300, 255);
			break;
		case CREATE_FOOD:
			IMAGEMANAGER->findAlphaImage("ũ������ƮǪ��")->alphaRender(getMemDC(), 3750 + _skillMoveX, 300, 255);
			break;
		case PETRIFICATION:
			IMAGEMANAGER->findAlphaImage("��Ʈ�������̼�")->alphaRender(getMemDC(), 4030 + _skillMoveX, 300, 255);
			break;
		}
	}
	if (!_bSkillListMoveClose){
		IMAGEMANAGER->findAlphaImage("�Ҽ�������ų����Ʈ")->alphaRender(getMemDC(), _skillListX1, 165, 255);
		IMAGEMANAGER->findImage("�Ҽ�������ų����Ʈ������")->aniRender(getMemDC(), _skillListX2, 165, KEYANIMANAGER->findAnimation("�Ҽ�������ų����Ʈ������"));
	}
	else{
		IMAGEMANAGER->findAlphaImage("�Ҽ�������ų����Ʈ")->alphaRender(getMemDC(), _skillListX1, 165, 255);
		IMAGEMANAGER->findImage("�Ҽ�������ų����Ʈ������")->aniRender(getMemDC(), _skillListX2, 165, KEYANIMANAGER->findAnimation("�Ҽ�������ų����Ʈ�����Ӵݱ�"));
	}

	if (_bSkillListMoveOpen && !_bSkillListMoveClose){
		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);

		char str[100];

		///////////////////////////��������//////////////////////////////
		font = CreateFont(50, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "���� ����");
		TextOut(getMemDC(), 1240, 250, str, strlen(str));
		
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 129, 129));
		sprintf(str, "�Һ� ��ų ����Ʈ");
		TextOut(getMemDC(), 1240, 320, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "%d ����Ʈ", _sorceressSkill[_sorceressSkillChoice].sKillPointCondition[_sorceressSkill[_sorceressSkillChoice].skillLV]);
		TextOut(getMemDC(), 1240, 350, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 0, 0));
		sprintf(str, "(����: %d����Ʈ)", _skillPoint);
		TextOut(getMemDC(), 1240, 380, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 129, 129));
		sprintf(str, "�÷��̾� LV");
		TextOut(getMemDC(), 1240, 450, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "LV%d �̻�", _sorceressSkill[_sorceressSkillChoice].LVCondition[_sorceressSkill[_sorceressSkillChoice].skillLV]);
		TextOut(getMemDC(), 1240, 480, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 0, 0));
		sprintf(str, "(����: LV%d)", _lv);
		TextOut(getMemDC(), 1240, 510, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		//////////////////////////////////////////////////////////////////////

		///////////////////��ų �̸� �� ����/////////////////////////////

		RECT rcText = { 0, 750, 1600, 850 };

		font = CreateFont(60,0,0,0,FW_NORMAL,false,false,false,DEFAULT_CHARSET,OUT_STROKE_PRECIS,CLIP_MASK,DRAFT_QUALITY,DEFAULT_PITCH | FF_SWISS,TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		DrawText(getMemDC(), _sorceressSkill[_sorceressSkillChoice].name.c_str(), _sorceressSkill[_sorceressSkillChoice].name.size(), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		rcText = { 0, 850, 1600, 900 };

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		DrawText(getMemDC(), _sorceressSkill[_sorceressSkillChoice].skillInfo.c_str(), _sorceressSkill[_sorceressSkillChoice].skillInfo.size(), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		if (_pointError){
			IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
			IMAGEMANAGER->findAlphaImage("��ų����Ʈ����")->render(getMemDC(), 0, 600);
		}
		else if (_lvError){
			IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
			IMAGEMANAGER->findAlphaImage("��������")->render(getMemDC(), 0, 600);
		}
		else if (_masterError){
			IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
			IMAGEMANAGER->findAlphaImage("��ų������")->render(getMemDC(), 0, 600);
		}
	}
}
void guildScene::commonSkillRender(){
	if (_bSkillListMoveOpen){
		//��ų ���� ����
		for (int i = _commonSkill[0].skillLV; i > 1; i--){
			IMAGEMANAGER->findAlphaImage("��Ʈ����Ʈ��")->alphaRender(getMemDC(), 670 + _skillMoveX - (i - 1) * 20, 300 - (i - 1) * 20, 255);
		}

		for (int i = _commonSkill[1].skillLV; i > 1; i--){
			IMAGEMANAGER->findAlphaImage("Ǫ����������")->alphaRender(getMemDC(), 950 + _skillMoveX - (i - 1) * 20, 300 - (i - 1) * 20, 255);
		}

		for (int i = _commonSkill[2].skillLV; i > 1; i--){
			IMAGEMANAGER->findAlphaImage("�����׳ͽ�")->alphaRender(getMemDC(), 1230 + _skillMoveX - (i - 1) * 20, 300 - (i - 1) * 20, 255);
		}

		for (int i = _commonSkill[3].skillLV; i > 1; i--){
			IMAGEMANAGER->findAlphaImage("����������")->alphaRender(getMemDC(), 1510 + _skillMoveX - (i - 1) * 20, 300 - (i - 1) * 20, 255);
		}

		
		int x;

		x = 670 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_commonSkill[0].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("��Ʈ����Ʈ��")->alphaRender(getMemDC(), x, 300, 20);
			else
			IMAGEMANAGER->findAlphaImage("��Ʈ����Ʈ��")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 950 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_commonSkill[1].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("Ǫ����������")->alphaRender(getMemDC(), x, 300, 20);
			else
			IMAGEMANAGER->findAlphaImage("Ǫ����������")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 1230 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_commonSkill[2].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("�����׳ͽ�")->alphaRender(getMemDC(), x, 300, 20);
			else
			IMAGEMANAGER->findAlphaImage("�����׳ͽ�")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 1510 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("���ó��")->alphaRender(getMemDC(), x, 300, 255);
			if (_commonSkill[3].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("����������")->alphaRender(getMemDC(), x, 300, 20);
			else
			IMAGEMANAGER->findAlphaImage("����������")->alphaRender(getMemDC(), x, 300, 170);
		}


		switch (_commonSkillChoice){
		case 0:
			IMAGEMANAGER->findAlphaImage("��Ʈ����Ʈ��")->alphaRender(getMemDC(), 670 + _skillMoveX, 300, 255);
			break;
		case 1:
			IMAGEMANAGER->findAlphaImage("Ǫ����������")->alphaRender(getMemDC(), 950 + _skillMoveX, 300, 255);
			break;
		case 2:
			IMAGEMANAGER->findAlphaImage("�����׳ͽ�")->alphaRender(getMemDC(), 1230 + _skillMoveX, 300, 255);
			break;
		case 3:
			IMAGEMANAGER->findAlphaImage("����������")->alphaRender(getMemDC(), 1510 + _skillMoveX, 300, 255);
			break;
		}
	}
	
	if (!_bSkillListMoveClose){
		IMAGEMANAGER->findAlphaImage("���뽺ų����Ʈ")->alphaRender(getMemDC(), _skillListX1, 165, 255);
		IMAGEMANAGER->findImage("���뽺ų������")->aniRender(getMemDC(), _skillListX2, 165, KEYANIMANAGER->findAnimation("���뽺ų������"));
	}
	else{
		IMAGEMANAGER->findAlphaImage("���뽺ų����Ʈ")->alphaRender(getMemDC(), _skillListX1, 165, 255);
		IMAGEMANAGER->findImage("���뽺ų������")->aniRender(getMemDC(), _skillListX2, 165, KEYANIMANAGER->findAnimation("���뽺ų�����Ӵݱ�"));
	}

	if (_bSkillListMoveOpen && !_bSkillListMoveClose){
		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);

		char str[100];

		///////////////////////////��������//////////////////////////////
		font = CreateFont(50, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "���� ����");
		TextOut(getMemDC(), 1240, 250, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 129, 129));
		sprintf(str, "�Һ� ��ų ����Ʈ");
		TextOut(getMemDC(), 1240, 320, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "%d ����Ʈ", _commonSkill[_commonSkillChoice].sKillPointCondition[_commonSkill[_commonSkillChoice].skillLV]);
		TextOut(getMemDC(), 1240, 350, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 0, 0));
		sprintf(str, "(����: %d����Ʈ)", _skillPoint);
		TextOut(getMemDC(), 1240, 380, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 129, 129));
		sprintf(str, "�÷��̾� LV");
		TextOut(getMemDC(), 1240, 450, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "LV%d �̻�", _commonSkill[_commonSkillChoice].LVCondition[_commonSkill[_commonSkillChoice].skillLV]);
		TextOut(getMemDC(), 1240, 480, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 0, 0));
		sprintf(str, "(����: LV%d)", _lv);
		TextOut(getMemDC(), 1240, 510, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		//////////////////////////////////////////////////////////////////////

		///////////////////��ų �̸� �� ����/////////////////////////////

		RECT rcText = { 0, 750, 1600, 850 };

		font = CreateFont(60, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		DrawText(getMemDC(), _commonSkill[_commonSkillChoice].name.c_str(), _commonSkill[_commonSkillChoice].name.size(), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		rcText = { 0, 850, 1600, 900 };

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		DrawText(getMemDC(), _commonSkill[_commonSkillChoice].skillInfo.c_str(), _commonSkill[_commonSkillChoice].skillInfo.size(), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}

	if (_pointError){
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("��ų����Ʈ����")->render(getMemDC(), 0, 600);
	}
	else if (_lvError){
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("��������")->render(getMemDC(), 0, 600);
	}
	else if (_masterError){
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("��ų������")->render(getMemDC(), 0, 600);
	}
}

void guildScene::confirmRender(){
	

	//�Ҽ����� ��ų�� ����� Ȯ���ϴ� ����
	switch (_guildState){
	case SORCERESS_CONFIRM:
	case COMMON_CONFIRM:
		IMAGEMANAGER->findAlphaImage("���ó��2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("��ȭ����")->render(getMemDC(), 0, 300);
		if (_skillLearn){
			IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
			IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
		}
		else{
			IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
			IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
		}

		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);

		char str[100];

		RECT rcText = { 0, 340, 1600, 390 };

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "��ų�� ���ðڽ��ϱ�?");
		DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}

	
}

void guildScene::confirm(){
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
		if (_skillLearn)_skillLearn = false;
		else _skillLearn = true;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
		if (_skillLearn)_skillLearn = false;
		else _skillLearn = true;
	}

	if (KEYMANAGER->isOnceKeyDown('A')){
		if (_skillLearn){
			_skillLearnConfirm = true;
			switch (_skillChioceState){
			case SORCERESS:
				_guildState = SORCERESS_SKILL;
				_skillPoint -= _sorceressSkill[_sorceressSkillChoice].sKillPointCondition[_sorceressSkill[_sorceressSkillChoice].skillLV];
				_sorceressSkill[_sorceressSkillChoice].skillLV++;
				SOUNDMANAGER->play("��ų���", 0.1f);
				break;
			case COMMON:
				_guildState = COMMON_SKILL;
				_skillPoint -= _commonSkill[_commonSkillChoice].sKillPointCondition[_commonSkill[_commonSkillChoice].skillLV];
				_commonSkill[_commonSkillChoice].skillLV++;
				SOUNDMANAGER->play("��ų���", 0.1f);
				break;
			}
		}
		switch (_skillChioceState){
		case SORCERESS:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON:
			_guildState = COMMON_SKILL;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		_skillLearn = false;
	}
}


void guildScene::error(){
	if (KEYMANAGER->isOnceKeyDown('A')){
		switch (_guildState){
		case SORCERESS_SKILL_POINT_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_LV_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_SKILL_MASTER_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON_SKILL_POINT_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_LV_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_SKILL_MASTER_ERROR:
			_guildState = COMMON_SKILL;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('S')){
		switch (_guildState){
		case SORCERESS_SKILL_POINT_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_LV_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_SKILL_MASTER_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON_SKILL_POINT_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_LV_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_SKILL_MASTER_ERROR:
			_guildState = COMMON_SKILL;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('Z')){
		switch (_guildState){
		case SORCERESS_SKILL_POINT_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_LV_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_SKILL_MASTER_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON_SKILL_POINT_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_LV_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_SKILL_MASTER_ERROR:
			_guildState = COMMON_SKILL;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		switch (_guildState){
		case SORCERESS_SKILL_POINT_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_LV_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_SKILL_MASTER_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON_SKILL_POINT_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_LV_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_SKILL_MASTER_ERROR:
			_guildState = COMMON_SKILL;
			break;
		}
	}
}

void guildScene::errorRender(){
	RECT rcText = { 0, 340, 1600, 390 };
	HFONT oldFont;
	HFONT font;
	SetBkMode(getMemDC(), TRANSPARENT);

	char str[100];

	IMAGEMANAGER->findAlphaImage("��ȭ����")->render(getMemDC(), 0, 300);

	switch (_guildState){
	case SORCERESS_SKILL_POINT_ERROR :
	case COMMON_SKILL_POINT_ERROR:
		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "��ų ����Ʈ�� �����մϴ�.");
		DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	case SORCERESS_LV_ERROR:
	case COMMON_LV_ERROR:
		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "������ �����ϴ�.");
		DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	case SORCERESS_SKILL_MASTER_ERROR:
	case COMMON_SKILL_MASTER_ERROR:
		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("�޸ձ���"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "���̻� ��ų�� ���� �����ϴ�.");
		DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	
	}
	
}

void guildScene::dataSave(){
	char str1[50];
	INIDATA->addData("Position", "X", INIDATA->loadDataString("PlayerData", "Position", "X").c_str());
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
	INIDATA->addData("State", "Money", INIDATA->loadDataString("PlayerData","State","Money").c_str());

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
	char str3[50];
	sprintf(str3, "%d", _skillPoint);
	INIDATA->addData("Skill", "SKILLPOINT", str3);
	sprintf(str3,"%d",_sorceressSkill[0].skillLV);
	INIDATA->addData("Skill", "mental_absorb", str3);
	sprintf(str3, "%d", _sorceressSkill[1].skillLV);
	INIDATA->addData("Skill", "extract", str3);
	sprintf(str3, "%d", _sorceressSkill[2].skillLV);
	INIDATA->addData("Skill", "concentrate", str3);
	sprintf(str3, "%d", _sorceressSkill[3].skillLV);
	INIDATA->addData("Skill", "magic_point_up", str3);
	sprintf(str3, "%d", _sorceressSkill[4].skillLV);
	INIDATA->addData("Skill", "ice_prision", str3);
	sprintf(str3, "%d", _sorceressSkill[5].skillLV);
	INIDATA->addData("Skill", "protection", str3);
	sprintf(str3, "%d", _sorceressSkill[6].skillLV);
	INIDATA->addData("Skill", "gravity", str3);
	sprintf(str3, "%d", _sorceressSkill[7].skillLV);
	INIDATA->addData("Skill", "thunder_cloud", str3);
	sprintf(str3, "%d", _sorceressSkill[8].skillLV);
	INIDATA->addData("Skill", "rock_press", str3);
	sprintf(str3, "%d", _sorceressSkill[9].skillLV);
	INIDATA->addData("Skill", "blizzard", str3);
	sprintf(str3, "%d", _sorceressSkill[10].skillLV);
	INIDATA->addData("Skill", "ravitation", str3);
	sprintf(str3, "%d", _sorceressSkill[11].skillLV);
	INIDATA->addData("Skill", "create_food", str3);
	sprintf(str3, "%d", _sorceressSkill[12].skillLV);
	INIDATA->addData("Skill", "petrification", str3);
	sprintf(str3, "%d", _commonSkill[0].skillLV);
	INIDATA->addData("Skill", "hit_point_up", str3);
	sprintf(str3, "%d", _commonSkill[1].skillLV);
	INIDATA->addData("Skill", "food_psytology", str3);
	sprintf(str3, "%d", _commonSkill[2].skillLV);
	INIDATA->addData("Skill", "maintenance", str3);
	sprintf(str3, "%d", _commonSkill[3].skillLV);
	INIDATA->addData("Skill", "item_user", str3);


	char str2[30];
	INIDATA->addData("��ī������ ������", "num", INIDATA->loadDataString("PlayerData","��ī������ ������","num").c_str());
	INIDATA->addData("��ī������ ������", "currentCon", INIDATA->loadDataString("PlayerData", "��ī������ ������", "currentCon").c_str());
	INIDATA->addData("������Ʈ ������", "num", INIDATA->loadDataString("PlayerData","������Ʈ ������","num").c_str());
	INIDATA->addData("�̱״� ������", "num", INIDATA->loadDataString("PlayerData","�̱״� ������","num").c_str());
	INIDATA->addData("ũ��� ������", "num", INIDATA->loadDataString("PlayerData","ũ��� ������","num").c_str());
	INIDATA->addData("ũ��� ������", "seal", INIDATA->loadDataString("PlayerData","ũ��� ������","seal").c_str());
	INIDATA->addData("���� ����", "num", INIDATA->loadDataString("PlayerData","���� ����","num").c_str());
	INIDATA->addData("������ ����", "num", INIDATA->loadDataString("PlayerData","������ ����","num").c_str());
	INIDATA->addData("�븶���� ����", "num", INIDATA->loadDataString("PlayerData","�븶���� ����","num").c_str());
	INIDATA->addData("�븶���� ����", "seal", INIDATA->loadDataString("PlayerData","�븶���� ����","seal").c_str());
	INIDATA->addData("���� �尩", "num", INIDATA->loadDataString("PlayerData", "���� �尩", "num").c_str());
	INIDATA->addData("���� �尩", "num", INIDATA->loadDataString("PlayerData", "���� �尩", "num").c_str());
	INIDATA->addData("���� �Ź�", "num", INIDATA->loadDataString("PlayerData", "���� �Ź�", "num").c_str());
	INIDATA->addData("������ �Ź�", "num", INIDATA->loadDataString("PlayerData","������ �Ź�","num").c_str());
	INIDATA->addData("���޶��� �ͰŸ�", "num", INIDATA->loadDataString("PlayerData", "���޶��� �ͰŸ�", "num").c_str());
	INIDATA->addData("�������� �ͰŸ�", "num", INIDATA->loadDataString("PlayerData", "�������� �ͰŸ�", "num").c_str());
	INIDATA->addData("A��", "num", INIDATA->loadDataString("PlayerData", "A��", "num").c_str());
	INIDATA->addData("B��", "num", INIDATA->loadDataString("PlayerData", "B��", "num").c_str());
	INIDATA->addData("C��", "num", INIDATA->loadDataString("PlayerData", "C��", "num").c_str());
	INIDATA->addData("D��", "num", INIDATA->loadDataString("PlayerData", "D��", "num").c_str());
	INIDATA->addData("E��", "num", INIDATA->loadDataString("PlayerData", "E��", "num").c_str());
	INIDATA->addData("F��", "num", INIDATA->loadDataString("PlayerData", "F��", "num").c_str());
	INIDATA->addData("������ ����", "num", INIDATA->loadDataString("PlayerData","������ ����","num").c_str());


	if (_sorceressSkill[4].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("���̽� �������� ��", "num", str3);
	}
	if (_sorceressSkill[5].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("�����ؼ��� ��", "num", str3);
	}
	if (_sorceressSkill[6].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("�׷���Ƽ�� ��", "num", str3);
	}
	if (_sorceressSkill[7].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("��� Ŭ������ ��", "num", str3);
	}
	if (_sorceressSkill[8].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("�� �������� ��", "num", str3);
	}
	if (_sorceressSkill[9].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("���ڵ��� ��", "num", str3);
	}
	if (_sorceressSkill[11].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("ũ������Ʈ Ǫ���� ��", "num", str3);
	}
	if (_sorceressSkill[12].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("��Ʈ�������̼��� ��", "num", str3);
	}

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