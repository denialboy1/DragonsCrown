#include "stdafx.h"
#include "item.h"


item::item()
{
}


item::~item()
{
}

void item::itemSetting(){

	if (_vItem.size() > 0){ return; }
	IMAGEMANAGER->addFrameImage("������", "�̹���/����/item.bmp", 950, 760, 10, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("������1", "�̹���/����/item.bmp", 600, 500, 10, 8, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addFrameImage("������2", "�̹���/����/item.bmp", 400, 300, 10, 8, true, RGB(255, 0, 255), true);


	memset(&_item, 0, sizeof(tagItem));

	_item.type = WEAPON;
	strcpy(_item.rank, "C");
	_item.name = "��ī������ ������";
	_item.info = "INT +3";
	_item.LVCondition = 1;
	_item.ability.ATK = 10;
	_item.ability.HP = 30;
	_item.ability.INT = 3;
	_item.seal = false;
	_item.price = 1000;
	_item.frameX = 0;
	_item.frameY = 0;
	_item.maxCon = 1000;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = WEAPON;
	strcpy(_item.rank, "B");
	_item.name = "������Ʈ ������";
	_item.info = "INT +10     DEX +5";
	_item.LVCondition = 4;
	_item.ability.ATK = 20;
	_item.ability.INT = 10;
	_item.ability.DEX = 5;
	_item.seal = false;
	_item.price = 2000;
	_item.frameX = 1;
	_item.frameY = 0;
	_item.maxCon = 1500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = WEAPON;
	strcpy(_item.rank, "A");
	_item.name = "�̱״� ������";
	_item.info = "INT +40     DEX +10";
	_item.LVCondition = 9;
	_item.ability.ATK = 50;
	_item.ability.INT = 40;
	_item.ability.DEX = 10;
	_item.ability.HP = 50;
	_item.seal = false;
	_item.price = 8000;
	_item.frameX = 2;
	_item.frameY = 0;
	_item.maxCon = 2000;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = WEAPON;
	strcpy(_item.rank, "S");
	_item.name = "ũ��� ������";
	_item.info = "INT +300     DEX +50";
	_item.LVCondition = 9;
	_item.ability.ATK = 300;
	_item.ability.INT = 300;
	_item.ability.DEX = 50;
	_item.ability.HP = 100;
	_item.seal = true;
	_item.price = 30000;
	_item.frameX = 3;
	_item.frameY = 0;
	_item.maxCon = 2500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "B");
	_item.name = "���� ����";
	_item.info = "CON + 10     HP +100";
	_item.LVCondition = 1;
	_item.ability.CON = 10;
	_item.ability.HP = 100;
	_item.ability.DEF = 100;
	_item.seal = false;
	_item.price = 1000;
	_item.frameX = 0;
	_item.frameY = 1;
	_item.maxCon = 1500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "A");
	_item.name = "������ ����";
	_item.info = "CON + 50     HP +200";
	_item.LVCondition = 5;
	_item.ability.CON = 50;
	_item.ability.HP = 200;
	_item.ability.DEF = 500;
	_item.seal = false;
	_item.price = 5000;
	_item.frameX = 1;
	_item.frameY = 1;
	_item.maxCon = 2000;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);


	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "S");
	_item.name = "�븶���� ����";
	_item.info = "CON + 100     HP +300";
	_item.LVCondition = 9;
	_item.ability.CON = 100;
	_item.ability.HP = 300;
	_item.ability.DEF = 1000;
	_item.seal = true;
	_item.price = 30000;
	_item.frameX = 2;
	_item.frameY = 1;
	_item.maxCon = 2500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "B");
	_item.name = "���� �尩";
	_item.info = "CON + 10     DEX + 10";
	_item.LVCondition = 3;
	_item.ability.CON = 10;
	_item.ability.DEX = 10;
	_item.ability.DEF = 10;
	_item.seal = false;
	_item.price = 3000;
	_item.frameX = 0;
	_item.frameY = 2;
	_item.maxCon = 2500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "A");
	_item.name = "���� �尩";
	_item.info = "CON + 20     DEX + 40";
	_item.LVCondition = 7;
	_item.ability.CON = 20;
	_item.ability.DEX = 40;
	_item.ability.DEF = 20;
	_item.seal = false;
	_item.price = 10000;
	_item.frameX = 1;
	_item.frameY = 2;
	_item.maxCon = 2500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "B");
	_item.name = "���� �Ź�";
	_item.info = "LUC + 10     DEX + 10";
	_item.LVCondition = 3;
	_item.ability.DEX = 10;
	_item.ability.LUC = 10;
	_item.ability.DEF = 20;
	_item.seal = false;
	_item.price = 3000;
	_item.frameX = 0;
	_item.frameY = 3;
	_item.maxCon = 2500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "A");
	_item.name = "������ �Ź�";
	_item.info = "LUC + 30     DEX + 30";
	_item.LVCondition = 5;
	_item.ability.DEX = 30;
	_item.ability.LUC = 30;
	_item.ability.DEF = 25;
	_item.seal = false;
	_item.price = 5000;
	_item.frameX = 1;
	_item.frameY = 3;
	_item.maxCon = 2500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "B");
	_item.name = "���޶��� �ͰŸ�";
	_item.info = "LUC + 40";
	_item.LVCondition = 3;
	_item.ability.LUC = 40;
	_item.ability.DEF = 10;
	_item.seal = false;
	_item.price = 3000;
	_item.frameX = 0;
	_item.frameY = 4;
	_item.maxCon = 2500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = ARMOR;
	strcpy(_item.rank, "A");
	_item.name = "�������� �ͰŸ�";
	_item.info = "LUC + 80";
	_item.LVCondition = 7;
	_item.ability.LUC = 8;
	_item.ability.DEF = 15;
	_item.seal = false;
	_item.price = 7000;
	_item.frameX = 1;
	_item.frameY = 4;
	_item.maxCon = 2500;
	_item.currentCon = _item.maxCon;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "A��";
	_item.info = "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.";
	_item.price = 7000;
	_item.frameX = 0;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "B��";
	_item.info = "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.";
	_item.price = 7000;
	_item.frameX = 1;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "C��";
	_item.info = "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.";
	_item.price = 7000;
	_item.frameX = 2;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "D��";
	_item.info = "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.";
	_item.price = 7000;
	_item.frameX = 3;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "E��";
	_item.info = "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.";
	_item.price = 7000;
	_item.frameX = 4;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "F��";
	_item.info = "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.";
	_item.price = 7000;
	_item.frameX = 5;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = POTION;
	_item.name = "������ ����";
	_item.info = "ü���� 100 ȸ���Ѵ�.";
	_item.price = 1000;
	_item.frameX = 0;
	_item.frameY = 6;
	_item.ability.HEAL = 100;
	_vItem.push_back(_item);


	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "���̽� �������� ��";
	_item.info = "���� ���δ� ������ �����Ѵ�.";
	_item.useCount = 3;
	_item.frameX = 7;
	_item.frameY = 7;
	_vItem.push_back(_item);
	
	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "�����ؼ��� ��";
	_item.info = "������ ���и� �����Ѵ�";
	_item.useCount = 3;
	_item.frameX = 8;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "�׷���Ƽ�� ��";
	_item.info = "���� ���Ƶ��̴� �߷����� �߻���Ų��";
	_item.useCount = 3;
	_item.frameX = 9;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "��� Ŭ������ ��";
	_item.info = "������ ����Ʈ���� ������ �߻���Ų��";
	_item.useCount = 3;
	_item.frameX = 3;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "�� �������� ��";
	_item.info = "���� ȿ���� �ִ� �ϼ��� ����Ʈ����";
	_item.useCount = 3;
	_item.frameX = 6;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "���ڵ��� ��";
	_item.info = "���� �󸮴� ������ �ҷ�����Ų��";
	_item.useCount = 3;
	_item.frameX = 4;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "ũ������Ʈ Ǫ���� ��";
	_item.info = "������ ������ �����";
	_item.useCount = 3;
	_item.frameX = 2;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "Ŀ���� ��";
	_item.info = "���� ������ ���·� �����";
	_item.useCount = 3;
	_item.frameX = 1;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "��Ʈ�������̼��� ��";
	_item.info = "���� ��ȭ ���·� �����";
	_item.useCount = 3;
	_item.frameX = 0;
	_item.frameY = 7;
	_vItem.push_back(_item);

	/*
	INIDATA->addData("��ī������ ������", "Type", "WEAPON");
	INIDATA->addData("��ī������ ������", "Rank", "C");
	INIDATA->addData("��ī������ ������", "Name", "��ī������ ������");
	INIDATA->addData("��ī������ ������", "Info", "HP +30     INT +3");
	INIDATA->addData("��ī������ ������", "LVCondition", "1");
	INIDATA->addData("��ī������ ������", "Atk", "10");
	INIDATA->addData("��ī������ ������", "Hp", "30");
	INIDATA->addData("��ī������ ������", "Int", "3");
	INIDATA->addData("��ī������ ������", "Seal", "false");
	INIDATA->addData("��ī������ ������", "Price", "1000");
	INIDATA->addData("��ī������ ������", "FrameX", "0");
	INIDATA->addData("��ī������ ������", "FrameY", "0");
	INIDATA->addData("��ī������ ������", "MaxCon", "1000");
	INIDATA->addData("��ī������ ������", "CurrentCon", "1000");


	INIDATA->addData("������Ʈ ������", "Type", "WEAPON");
	INIDATA->addData("������Ʈ ������", "Rank", "B");
	INIDATA->addData("������Ʈ ������", "Name", "������Ʈ ������");
	INIDATA->addData("������Ʈ ������", "Info", "INT +10     DEX +5");
	INIDATA->addData("������Ʈ ������", "LVCondition", "4");
	INIDATA->addData("������Ʈ ������", "Atk", "20");
	INIDATA->addData("������Ʈ ������", "Dex", "5");
	INIDATA->addData("������Ʈ ������", "Int", "10");
	INIDATA->addData("������Ʈ ������", "Seal", "false");
	INIDATA->addData("������Ʈ ������", "Price", "2000");
	INIDATA->addData("������Ʈ ������", "FrameX", "1");
	INIDATA->addData("������Ʈ ������", "FrameY", "0");
	INIDATA->addData("������Ʈ ������", "MaxCon", "1500");
	INIDATA->addData("������Ʈ ������", "CurrentCon", "1500");


	INIDATA->addData("�̱״� ������", "Type", "WEAPON");
	INIDATA->addData("�̱״� ������", "Rank", "A");
	INIDATA->addData("�̱״� ������", "Name", "�̱״� ������");
	INIDATA->addData("�̱״� ������", "Info", "INT +40     DEX +10     HP +50");
	INIDATA->addData("�̱״� ������", "LVCondition", "9");
	INIDATA->addData("�̱״� ������", "Atk", "50");
	INIDATA->addData("�̱״� ������", "Hp", "50");
	INIDATA->addData("�̱״� ������", "Int", "40");
	INIDATA->addData("�̱״� ������", "Dex", "10");
	INIDATA->addData("�̱״� ������", "Seal", "false");
	INIDATA->addData("�̱״� ������", "Price", "8000");
	INIDATA->addData("�̱״� ������", "FrameX", "2");
	INIDATA->addData("�̱״� ������", "FrameY", "0");
	INIDATA->addData("�̱״� ������", "MaxCon", "2000");
	INIDATA->addData("�̱״� ������", "CurrentCon", "2000");


	INIDATA->addData("ũ��� ������", "Type", "WEAPON");
	INIDATA->addData("ũ��� ������", "Rank", "S");
	INIDATA->addData("ũ��� ������", "Name", "ũ��� ������");
	INIDATA->addData("ũ��� ������", "Info", "INT +300     DEX +50     HP +100");
	INIDATA->addData("ũ��� ������", "LVCondition", "9");
	INIDATA->addData("ũ��� ������", "Atk", "300");
	INIDATA->addData("ũ��� ������", "Hp", "100");
	INIDATA->addData("ũ��� ������", "Int", "300");
	INIDATA->addData("ũ��� ������", "Dex", "50");
	INIDATA->addData("ũ��� ������", "Seal", "true");
	INIDATA->addData("ũ��� ������", "Price", "30000");
	INIDATA->addData("ũ��� ������", "FrameX", "3");
	INIDATA->addData("ũ��� ������", "FrameY", "0");
	INIDATA->addData("ũ��� ������", "MaxCon", "2500");
	INIDATA->addData("ũ��� ������", "CurrentCon", "2500");

	INIDATA->addData("���� ����", "Type", "ARMOR");
	INIDATA->addData("���� ����", "Rank", "B");
	INIDATA->addData("���� ����", "Name", "���� ����");
	INIDATA->addData("���� ����", "Info", "CON + 10     HP +100");
	INIDATA->addData("���� ����", "LVCondition", "1");
	INIDATA->addData("���� ����", "Con", "10");
	INIDATA->addData("���� ����", "Hp", "100");
	INIDATA->addData("���� ����", "Def", "100");
	INIDATA->addData("���� ����", "Seal", "false");
	INIDATA->addData("���� ����", "Price", "1000");
	INIDATA->addData("���� ����", "FrameX", "0");
	INIDATA->addData("���� ����", "FrameY", "1");
	INIDATA->addData("���� ����", "MaxCon", "1500");
	INIDATA->addData("���� ����", "CurrentCon", "1500");

	INIDATA->addData("������ ����", "Type", "ARMOR");
	INIDATA->addData("������ ����", "Rank", "A");
	INIDATA->addData("������ ����", "Name", "������ ����");
	INIDATA->addData("������ ����", "Info", "CON + 50     HP +200");
	INIDATA->addData("������ ����", "LVCondition", "5");
	INIDATA->addData("������ ����", "Con", "50");
	INIDATA->addData("������ ����", "Hp", "200");
	INIDATA->addData("������ ����", "Def", "500");
	INIDATA->addData("������ ����", "Seal", "false");
	INIDATA->addData("������ ����", "Price", "5000");
	INIDATA->addData("������ ����", "FrameX", "1");
	INIDATA->addData("������ ����", "FrameY", "1");
	INIDATA->addData("������ ����", "MaxCon", "2000");
	INIDATA->addData("������ ����", "CurrentCon", "2000");


	INIDATA->addData("�븶���� ����", "Type", "ARMOR");
	INIDATA->addData("�븶���� ����", "Rank", "S");
	INIDATA->addData("�븶���� ����", "Name", "�븶���� ����");
	INIDATA->addData("�븶���� ����", "Info", "CON + 100     HP +300");
	INIDATA->addData("�븶���� ����", "LVCondition", "9");
	INIDATA->addData("�븶���� ����", "Con", "100");
	INIDATA->addData("�븶���� ����", "Hp", "300");
	INIDATA->addData("�븶���� ����", "Def", "1000");
	INIDATA->addData("�븶���� ����", "Seal", "true");
	INIDATA->addData("�븶���� ����", "Price", "30000");
	INIDATA->addData("�븶���� ����", "FrameX", "2");
	INIDATA->addData("�븶���� ����", "FrameY", "1");
	INIDATA->addData("�븶���� ����", "MaxCon", "2500");
	INIDATA->addData("�븶���� ����", "CurrentCon", "2500");

	INIDATA->addData("���� �尩", "Type", "ARMOR");
	INIDATA->addData("���� �尩", "Rank", "B");
	INIDATA->addData("���� �尩", "Name", "���� �尩");
	INIDATA->addData("���� �尩", "Info", "CON + 10     DEX + 10");
	INIDATA->addData("���� �尩", "LVCondition", "3");
	INIDATA->addData("���� �尩", "Con", "10");
	INIDATA->addData("���� �尩", "Dex", "10");
	INIDATA->addData("���� �尩", "Def", "10");
	INIDATA->addData("���� �尩", "Seal", "false");
	INIDATA->addData("���� �尩", "Price", "3000");
	INIDATA->addData("���� �尩", "FrameX", "0");
	INIDATA->addData("���� �尩", "FrameY", "2");
	INIDATA->addData("���� �尩", "MaxCon", "2500");
	INIDATA->addData("���� �尩", "CurrentCon", "2500");

	INIDATA->addData("���� �尩", "Type", "ARMOR");
	INIDATA->addData("���� �尩", "Rank", "A");
	INIDATA->addData("���� �尩", "Name", "���� �尩");
	INIDATA->addData("���� �尩", "Info", "CON + 20     DEX + 40");
	INIDATA->addData("���� �尩", "LVCondition", "7");
	INIDATA->addData("���� �尩", "Con", "20");
	INIDATA->addData("���� �尩", "Dex", "40");
	INIDATA->addData("���� �尩", "Def", "20");
	INIDATA->addData("���� �尩", "Seal", "false");
	INIDATA->addData("���� �尩", "Price", "10000");
	INIDATA->addData("���� �尩", "FrameX", "1");
	INIDATA->addData("���� �尩", "FrameY", "2");
	INIDATA->addData("���� �尩", "MaxCon", "2500");
	INIDATA->addData("���� �尩", "CurrentCon", "2500");

	INIDATA->addData("���� �Ź�", "Type", "ARMOR");
	INIDATA->addData("���� �Ź�", "Rank", "B");
	INIDATA->addData("���� �Ź�", "Name", "���� �Ź�");
	INIDATA->addData("���� �Ź�", "Info", "LUC + 10     DEX + 10");
	INIDATA->addData("���� �Ź�", "LVCondition", "3");
	INIDATA->addData("���� �Ź�", "Dex", "10");
	INIDATA->addData("���� �Ź�", "Luc", "10");
	INIDATA->addData("���� �Ź�", "Def", "20");
	INIDATA->addData("���� �Ź�", "Seal", "false");
	INIDATA->addData("���� �Ź�", "Price", "3000");
	INIDATA->addData("���� �Ź�", "FrameX", "0");
	INIDATA->addData("���� �Ź�", "FrameY", "3");
	INIDATA->addData("���� �Ź�", "MaxCon", "2500");
	INIDATA->addData("���� �Ź�", "CurrentCon", "2500");

	INIDATA->addData("������ �Ź�", "Type", "ARMOR");
	INIDATA->addData("������ �Ź�", "Rank", "A");
	INIDATA->addData("������ �Ź�", "Name", "������ �Ź�");
	INIDATA->addData("������ �Ź�", "Info", "LUC + 30     DEX + 30");
	INIDATA->addData("������ �Ź�", "LVCondition", "5");
	INIDATA->addData("������ �Ź�", "Dex", "30");
	INIDATA->addData("������ �Ź�", "Luc", "30");
	INIDATA->addData("������ �Ź�", "Def", "25");
	INIDATA->addData("������ �Ź�", "Seal", "false");
	INIDATA->addData("������ �Ź�", "Price", "5000");
	INIDATA->addData("������ �Ź�", "FrameX", "1");
	INIDATA->addData("������ �Ź�", "FrameY", "3");
	INIDATA->addData("������ �Ź�", "MaxCon", "2500");
	INIDATA->addData("������ �Ź�", "CurrentCon", "2500");

	INIDATA->addData("���޶��� �ͰŸ�", "Type", "ARMOR");
	INIDATA->addData("���޶��� �ͰŸ�", "Rank", "B");
	INIDATA->addData("���޶��� �ͰŸ�", "Name", "���޶��� �ͰŸ�");
	INIDATA->addData("���޶��� �ͰŸ�", "Info", "LUC + 40");
	INIDATA->addData("���޶��� �ͰŸ�", "LVCondition", "3");
	INIDATA->addData("���޶��� �ͰŸ�", "Luc", "40");
	INIDATA->addData("���޶��� �ͰŸ�", "Def", "10");
	INIDATA->addData("���޶��� �ͰŸ�", "Seal", "false");
	INIDATA->addData("���޶��� �ͰŸ�", "Price", "3000");
	INIDATA->addData("���޶��� �ͰŸ�", "FrameX", "0");
	INIDATA->addData("���޶��� �ͰŸ�", "FrameY", "4");
	INIDATA->addData("���޶��� �ͰŸ�", "MaxCon", "2500");
	INIDATA->addData("���޶��� �ͰŸ�", "CurrentCon", "2500");

	INIDATA->addData("�������� �ͰŸ�", "Type", "ARMOR");
	INIDATA->addData("�������� �ͰŸ�", "Rank", "A");
	INIDATA->addData("�������� �ͰŸ�", "Name", "�������� �ͰŸ�");
	INIDATA->addData("�������� �ͰŸ�", "Info", "LUC + 80");
	INIDATA->addData("�������� �ͰŸ�", "LVCondition", "7");
	INIDATA->addData("�������� �ͰŸ�", "Luc", "8");
	INIDATA->addData("�������� �ͰŸ�", "Def", "15");
	INIDATA->addData("�������� �ͰŸ�", "Seal", "false");
	INIDATA->addData("�������� �ͰŸ�", "Price", "7000");
	INIDATA->addData("�������� �ͰŸ�", "FrameX", "1");
	INIDATA->addData("�������� �ͰŸ�", "FrameY", "4");
	INIDATA->addData("�������� �ͰŸ�", "MaxCon", "2500");
	INIDATA->addData("�������� �ͰŸ�", "CurrentCon", "2500");

	INIDATA->addData("A��", "Type", "RUNE");
	INIDATA->addData("A��", "Name", "A��");
	INIDATA->addData("A��", "Info", "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.");
	INIDATA->addData("A��", "Price", "7000");
	INIDATA->addData("A��", "FrameX", "0");
	INIDATA->addData("A��", "FrameY", "5");

	INIDATA->addData("B��", "Type", "RUNE");
	INIDATA->addData("B��", "Name", "B��");
	INIDATA->addData("B��", "Info", "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.");
	INIDATA->addData("B��", "Price", "7000");
	INIDATA->addData("B��", "FrameX", "1");
	INIDATA->addData("B��", "FrameY", "5");

	INIDATA->addData("C��", "Type", "RUNE");
	INIDATA->addData("C��", "Name", "C��");
	INIDATA->addData("C��", "Info", "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.");
	INIDATA->addData("C��", "Price", "7000");
	INIDATA->addData("C��", "FrameX", "2");
	INIDATA->addData("C��", "FrameY", "5");

	INIDATA->addData("D��", "Type", "RUNE");
	INIDATA->addData("D��", "Name", "D��");
	INIDATA->addData("D��", "Info", "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.");
	INIDATA->addData("D��", "Price", "7000");
	INIDATA->addData("D��", "FrameX", "3");
	INIDATA->addData("D��", "FrameY", "5");

	INIDATA->addData("E��", "Type", "RUNE");
	INIDATA->addData("E��", "Name", "E��");
	INIDATA->addData("E��", "Info", "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.");
	INIDATA->addData("E��", "Price", "7000");
	INIDATA->addData("E��", "FrameX", "4");
	INIDATA->addData("E��", "FrameY", "5");

	INIDATA->addData("F��", "Type", "RUNE");
	INIDATA->addData("F��", "Name", "F��");
	INIDATA->addData("F��", "Info", "���� �����Ͽ� ������ ��� �Ҽ� �ִ�.");
	INIDATA->addData("F��", "Price", "7000");
	INIDATA->addData("F��", "FrameX", "5");
	INIDATA->addData("F��", "FrameY", "5");

	INIDATA->addData("������ ����", "Type", "POTION");
	INIDATA->addData("������ ����", "Name", "������ ����");
	INIDATA->addData("������ ����", "Info", "ü���� 100 ȸ���Ѵ�.");
	INIDATA->addData("������ ����", "Price", "1000");
	INIDATA->addData("������ ����", "FrameX", "0");
	INIDATA->addData("������ ����", "FrameY", "6");
	INIDATA->addData("������ ����", "Heal", "100");


	INIDATA->addData("���̽� �������� ��", "Type", "SKILL_BOOK");
	INIDATA->addData("���̽� �������� ��", "Name", "���̽� �������� ��");
	INIDATA->addData("���̽� �������� ��", "Info", "���� ���δ� ������ �����Ѵ�.");
	INIDATA->addData("���̽� �������� ��", "UseCount", "3");
	INIDATA->addData("���̽� �������� ��", "FrameX", "7");
	INIDATA->addData("���̽� �������� ��", "FrameY", "7");

	INIDATA->addData("�����ؼ��� ��", "Type", "SKILL_BOOK");
	INIDATA->addData("�����ؼ��� ��", "Name", "�����ؼ��� ��");
	INIDATA->addData("�����ؼ��� ��", "Info", "������ ���и� �����Ѵ�");
	INIDATA->addData("�����ؼ��� ��", "UseCount", "3");
	INIDATA->addData("�����ؼ��� ��", "FrameX", "8");
	INIDATA->addData("�����ؼ��� ��", "FrameY", "7");

	INIDATA->addData("�׷���Ƽ�� ��", "Type", "SKILL_BOOK");
	INIDATA->addData("�׷���Ƽ�� ��", "Name", "�׷���Ƽ�� ��");
	INIDATA->addData("�׷���Ƽ�� ��", "Info", "���� ���Ƶ��̴� �߷����� �߻���Ų��");
	INIDATA->addData("�׷���Ƽ�� ��", "UseCount", "3");
	INIDATA->addData("�׷���Ƽ�� ��", "FrameX", "9");
	INIDATA->addData("�׷���Ƽ�� ��", "FrameY", "7");


	INIDATA->addData("��� Ŭ������ ��", "Type", "SKILL_BOOK");
	INIDATA->addData("��� Ŭ������ ��", "Name", "��� Ŭ������ ��");
	INIDATA->addData("��� Ŭ������ ��", "Info", "������ ����Ʈ���� ������ �߻���Ų��");
	INIDATA->addData("��� Ŭ������ ��", "UseCount", "3");
	INIDATA->addData("��� Ŭ������ ��", "FrameX", "3");
	INIDATA->addData("��� Ŭ������ ��", "FrameY", "7");

	INIDATA->addData("�� �������� ��", "Type", "SKILL_BOOK");
	INIDATA->addData("�� �������� ��", "Name", "�� �������� ��");
	INIDATA->addData("�� �������� ��", "Info", "���� ȿ���� �ִ� �ϼ��� ����Ʈ����");
	INIDATA->addData("�� �������� ��", "UseCount", "3");
	INIDATA->addData("�� �������� ��", "FrameX", "6");
	INIDATA->addData("�� �������� ��", "FrameY", "7");

	INIDATA->addData("���ڵ��� ��", "Type", "SKILL_BOOK");
	INIDATA->addData("���ڵ��� ��", "Name", "���ڵ��� ��");
	INIDATA->addData("���ڵ��� ��", "Info", "���� �󸮴� ������ �ҷ�����Ų��");
	INIDATA->addData("���ڵ��� ��", "UseCount", "3");
	INIDATA->addData("���ڵ��� ��", "FrameX", "4");
	INIDATA->addData("���ڵ��� ��", "FrameY", "7");

	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "Type", "SKILL_BOOK");
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "Name", "ũ������Ʈ Ǫ���� ��");
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "Info", "������ ������ �����");
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "UseCount", "3");
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "FrameX", "2");
	INIDATA->addData("ũ������Ʈ Ǫ���� ��", "FrameY", "7");

	INIDATA->addData("Ŀ���� ��", "Type", "SKILL_BOOK");
	INIDATA->addData("Ŀ���� ��", "Name", "Ŀ���� ��");
	INIDATA->addData("Ŀ���� ��", "Info", "���� ������ ���·� �����");
	INIDATA->addData("Ŀ���� ��", "UseCount", "3");
	INIDATA->addData("Ŀ���� ��", "FrameX", "1");
	INIDATA->addData("Ŀ���� ��", "FrameY", "7");

	INIDATA->addData("��Ʈ�������̼��� ��", "Type", "SKILL_BOOK");
	INIDATA->addData("��Ʈ�������̼��� ��", "Name", "��Ʈ�������̼��� ��");
	INIDATA->addData("��Ʈ�������̼��� ��", "Info", "���� ��ȭ ���·� �����");
	INIDATA->addData("��Ʈ�������̼��� ��", "UseCount", "3");
	INIDATA->addData("��Ʈ�������̼��� ��", "FrameX", "0");
	INIDATA->addData("��Ʈ�������̼��� ��", "FrameY", "7");*/

}