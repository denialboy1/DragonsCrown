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
	IMAGEMANAGER->addFrameImage("아이템", "이미지/마을/item.bmp", 950, 760, 10, 8, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("아이템1", "이미지/마을/item.bmp", 600, 500, 10, 8, true, RGB(255, 0, 255),true);
	IMAGEMANAGER->addFrameImage("아이템2", "이미지/마을/item.bmp", 400, 300, 10, 8, true, RGB(255, 0, 255), true);


	memset(&_item, 0, sizeof(tagItem));

	_item.type = WEAPON;
	strcpy(_item.rank, "C");
	_item.name = "마카로프의 스태프";
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
	_item.name = "문라이트 스태프";
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
	_item.name = "이그니 스태프";
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
	_item.name = "크라운 스태프";
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
	_item.name = "붉은 망토";
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
	_item.name = "마법사 망토";
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
	_item.name = "대마법사 망토";
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
	_item.name = "가죽 장갑";
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
	_item.name = "요정 장갑";
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
	_item.name = "가죽 신발";
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
	_item.name = "마법사 신발";
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
	_item.name = "에메랄드 귀거리";
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
	_item.name = "요정눈물 귀거리";
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
	_item.name = "A룬";
	_item.info = "룬을 조합하여 마법을 사용 할수 있다.";
	_item.price = 7000;
	_item.frameX = 0;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "B룬";
	_item.info = "룬을 조합하여 마법을 사용 할수 있다.";
	_item.price = 7000;
	_item.frameX = 1;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "C룬";
	_item.info = "룬을 조합하여 마법을 사용 할수 있다.";
	_item.price = 7000;
	_item.frameX = 2;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "D룬";
	_item.info = "룬을 조합하여 마법을 사용 할수 있다.";
	_item.price = 7000;
	_item.frameX = 3;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "E룬";
	_item.info = "룬을 조합하여 마법을 사용 할수 있다.";
	_item.price = 7000;
	_item.frameX = 4;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = RUNE;
	_item.name = "F룬";
	_item.info = "룬을 조합하여 마법을 사용 할수 있다.";
	_item.price = 7000;
	_item.frameX = 5;
	_item.frameY = 5;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = POTION;
	_item.name = "요정의 물약";
	_item.info = "체력을 100 회복한다.";
	_item.price = 1000;
	_item.frameX = 0;
	_item.frameY = 6;
	_item.ability.HEAL = 100;
	_vItem.push_back(_item);


	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "아이스 프리즌의 서";
	_item.info = "적을 가두는 얼음을 생성한다.";
	_item.useCount = 3;
	_item.frameX = 7;
	_item.frameY = 7;
	_vItem.push_back(_item);
	
	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "프로텍션의 서";
	_item.info = "마법의 방패를 생성한다";
	_item.useCount = 3;
	_item.frameX = 8;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "그래비티의 서";
	_item.info = "적을 빨아들이는 중력장을 발생시킨다";
	_item.useCount = 3;
	_item.frameX = 9;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "썬더 클라우드의 서";
	_item.info = "벼락을 떨어트리는 뇌운을 발생시킨다";
	_item.useCount = 3;
	_item.frameX = 3;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "록 프레스의 서";
	_item.info = "스턴 효과가 있는 암석을 떨어트린다";
	_item.useCount = 3;
	_item.frameX = 6;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "블리자드의 서";
	_item.info = "적을 얼리는 눈보라를 불러일으킨다";
	_item.useCount = 3;
	_item.frameX = 4;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "크리에이트 푸드의 서";
	_item.info = "주위에 음식을 만든다";
	_item.useCount = 3;
	_item.frameX = 2;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "커스의 서";
	_item.info = "적을 개구리 상태로 만든다";
	_item.useCount = 3;
	_item.frameX = 1;
	_item.frameY = 7;
	_vItem.push_back(_item);

	memset(&_item, 0, sizeof(tagItem));
	_item.type = SKILL_BOOK;
	_item.name = "페트리피케이션의 서";
	_item.info = "적을 석화 상태로 만든다";
	_item.useCount = 3;
	_item.frameX = 0;
	_item.frameY = 7;
	_vItem.push_back(_item);

	/*
	INIDATA->addData("마카로프의 스태프", "Type", "WEAPON");
	INIDATA->addData("마카로프의 스태프", "Rank", "C");
	INIDATA->addData("마카로프의 스태프", "Name", "마카로프의 스태프");
	INIDATA->addData("마카로프의 스태프", "Info", "HP +30     INT +3");
	INIDATA->addData("마카로프의 스태프", "LVCondition", "1");
	INIDATA->addData("마카로프의 스태프", "Atk", "10");
	INIDATA->addData("마카로프의 스태프", "Hp", "30");
	INIDATA->addData("마카로프의 스태프", "Int", "3");
	INIDATA->addData("마카로프의 스태프", "Seal", "false");
	INIDATA->addData("마카로프의 스태프", "Price", "1000");
	INIDATA->addData("마카로프의 스태프", "FrameX", "0");
	INIDATA->addData("마카로프의 스태프", "FrameY", "0");
	INIDATA->addData("마카로프의 스태프", "MaxCon", "1000");
	INIDATA->addData("마카로프의 스태프", "CurrentCon", "1000");


	INIDATA->addData("문라이트 스태프", "Type", "WEAPON");
	INIDATA->addData("문라이트 스태프", "Rank", "B");
	INIDATA->addData("문라이트 스태프", "Name", "문라이트 스태프");
	INIDATA->addData("문라이트 스태프", "Info", "INT +10     DEX +5");
	INIDATA->addData("문라이트 스태프", "LVCondition", "4");
	INIDATA->addData("문라이트 스태프", "Atk", "20");
	INIDATA->addData("문라이트 스태프", "Dex", "5");
	INIDATA->addData("문라이트 스태프", "Int", "10");
	INIDATA->addData("문라이트 스태프", "Seal", "false");
	INIDATA->addData("문라이트 스태프", "Price", "2000");
	INIDATA->addData("문라이트 스태프", "FrameX", "1");
	INIDATA->addData("문라이트 스태프", "FrameY", "0");
	INIDATA->addData("문라이트 스태프", "MaxCon", "1500");
	INIDATA->addData("문라이트 스태프", "CurrentCon", "1500");


	INIDATA->addData("이그니 스태프", "Type", "WEAPON");
	INIDATA->addData("이그니 스태프", "Rank", "A");
	INIDATA->addData("이그니 스태프", "Name", "이그니 스태프");
	INIDATA->addData("이그니 스태프", "Info", "INT +40     DEX +10     HP +50");
	INIDATA->addData("이그니 스태프", "LVCondition", "9");
	INIDATA->addData("이그니 스태프", "Atk", "50");
	INIDATA->addData("이그니 스태프", "Hp", "50");
	INIDATA->addData("이그니 스태프", "Int", "40");
	INIDATA->addData("이그니 스태프", "Dex", "10");
	INIDATA->addData("이그니 스태프", "Seal", "false");
	INIDATA->addData("이그니 스태프", "Price", "8000");
	INIDATA->addData("이그니 스태프", "FrameX", "2");
	INIDATA->addData("이그니 스태프", "FrameY", "0");
	INIDATA->addData("이그니 스태프", "MaxCon", "2000");
	INIDATA->addData("이그니 스태프", "CurrentCon", "2000");


	INIDATA->addData("크라운 스태프", "Type", "WEAPON");
	INIDATA->addData("크라운 스태프", "Rank", "S");
	INIDATA->addData("크라운 스태프", "Name", "크라운 스태프");
	INIDATA->addData("크라운 스태프", "Info", "INT +300     DEX +50     HP +100");
	INIDATA->addData("크라운 스태프", "LVCondition", "9");
	INIDATA->addData("크라운 스태프", "Atk", "300");
	INIDATA->addData("크라운 스태프", "Hp", "100");
	INIDATA->addData("크라운 스태프", "Int", "300");
	INIDATA->addData("크라운 스태프", "Dex", "50");
	INIDATA->addData("크라운 스태프", "Seal", "true");
	INIDATA->addData("크라운 스태프", "Price", "30000");
	INIDATA->addData("크라운 스태프", "FrameX", "3");
	INIDATA->addData("크라운 스태프", "FrameY", "0");
	INIDATA->addData("크라운 스태프", "MaxCon", "2500");
	INIDATA->addData("크라운 스태프", "CurrentCon", "2500");

	INIDATA->addData("붉은 망토", "Type", "ARMOR");
	INIDATA->addData("붉은 망토", "Rank", "B");
	INIDATA->addData("붉은 망토", "Name", "붉은 망토");
	INIDATA->addData("붉은 망토", "Info", "CON + 10     HP +100");
	INIDATA->addData("붉은 망토", "LVCondition", "1");
	INIDATA->addData("붉은 망토", "Con", "10");
	INIDATA->addData("붉은 망토", "Hp", "100");
	INIDATA->addData("붉은 망토", "Def", "100");
	INIDATA->addData("붉은 망토", "Seal", "false");
	INIDATA->addData("붉은 망토", "Price", "1000");
	INIDATA->addData("붉은 망토", "FrameX", "0");
	INIDATA->addData("붉은 망토", "FrameY", "1");
	INIDATA->addData("붉은 망토", "MaxCon", "1500");
	INIDATA->addData("붉은 망토", "CurrentCon", "1500");

	INIDATA->addData("마법사 망토", "Type", "ARMOR");
	INIDATA->addData("마법사 망토", "Rank", "A");
	INIDATA->addData("마법사 망토", "Name", "마법사 망토");
	INIDATA->addData("마법사 망토", "Info", "CON + 50     HP +200");
	INIDATA->addData("마법사 망토", "LVCondition", "5");
	INIDATA->addData("마법사 망토", "Con", "50");
	INIDATA->addData("마법사 망토", "Hp", "200");
	INIDATA->addData("마법사 망토", "Def", "500");
	INIDATA->addData("마법사 망토", "Seal", "false");
	INIDATA->addData("마법사 망토", "Price", "5000");
	INIDATA->addData("마법사 망토", "FrameX", "1");
	INIDATA->addData("마법사 망토", "FrameY", "1");
	INIDATA->addData("마법사 망토", "MaxCon", "2000");
	INIDATA->addData("마법사 망토", "CurrentCon", "2000");


	INIDATA->addData("대마법사 망토", "Type", "ARMOR");
	INIDATA->addData("대마법사 망토", "Rank", "S");
	INIDATA->addData("대마법사 망토", "Name", "대마법사 망토");
	INIDATA->addData("대마법사 망토", "Info", "CON + 100     HP +300");
	INIDATA->addData("대마법사 망토", "LVCondition", "9");
	INIDATA->addData("대마법사 망토", "Con", "100");
	INIDATA->addData("대마법사 망토", "Hp", "300");
	INIDATA->addData("대마법사 망토", "Def", "1000");
	INIDATA->addData("대마법사 망토", "Seal", "true");
	INIDATA->addData("대마법사 망토", "Price", "30000");
	INIDATA->addData("대마법사 망토", "FrameX", "2");
	INIDATA->addData("대마법사 망토", "FrameY", "1");
	INIDATA->addData("대마법사 망토", "MaxCon", "2500");
	INIDATA->addData("대마법사 망토", "CurrentCon", "2500");

	INIDATA->addData("가죽 장갑", "Type", "ARMOR");
	INIDATA->addData("가죽 장갑", "Rank", "B");
	INIDATA->addData("가죽 장갑", "Name", "가죽 장갑");
	INIDATA->addData("가죽 장갑", "Info", "CON + 10     DEX + 10");
	INIDATA->addData("가죽 장갑", "LVCondition", "3");
	INIDATA->addData("가죽 장갑", "Con", "10");
	INIDATA->addData("가죽 장갑", "Dex", "10");
	INIDATA->addData("가죽 장갑", "Def", "10");
	INIDATA->addData("가죽 장갑", "Seal", "false");
	INIDATA->addData("가죽 장갑", "Price", "3000");
	INIDATA->addData("가죽 장갑", "FrameX", "0");
	INIDATA->addData("가죽 장갑", "FrameY", "2");
	INIDATA->addData("가죽 장갑", "MaxCon", "2500");
	INIDATA->addData("가죽 장갑", "CurrentCon", "2500");

	INIDATA->addData("요정 장갑", "Type", "ARMOR");
	INIDATA->addData("요정 장갑", "Rank", "A");
	INIDATA->addData("요정 장갑", "Name", "요정 장갑");
	INIDATA->addData("요정 장갑", "Info", "CON + 20     DEX + 40");
	INIDATA->addData("요정 장갑", "LVCondition", "7");
	INIDATA->addData("요정 장갑", "Con", "20");
	INIDATA->addData("요정 장갑", "Dex", "40");
	INIDATA->addData("요정 장갑", "Def", "20");
	INIDATA->addData("요정 장갑", "Seal", "false");
	INIDATA->addData("요정 장갑", "Price", "10000");
	INIDATA->addData("요정 장갑", "FrameX", "1");
	INIDATA->addData("요정 장갑", "FrameY", "2");
	INIDATA->addData("요정 장갑", "MaxCon", "2500");
	INIDATA->addData("요정 장갑", "CurrentCon", "2500");

	INIDATA->addData("가죽 신발", "Type", "ARMOR");
	INIDATA->addData("가죽 신발", "Rank", "B");
	INIDATA->addData("가죽 신발", "Name", "가죽 신발");
	INIDATA->addData("가죽 신발", "Info", "LUC + 10     DEX + 10");
	INIDATA->addData("가죽 신발", "LVCondition", "3");
	INIDATA->addData("가죽 신발", "Dex", "10");
	INIDATA->addData("가죽 신발", "Luc", "10");
	INIDATA->addData("가죽 신발", "Def", "20");
	INIDATA->addData("가죽 신발", "Seal", "false");
	INIDATA->addData("가죽 신발", "Price", "3000");
	INIDATA->addData("가죽 신발", "FrameX", "0");
	INIDATA->addData("가죽 신발", "FrameY", "3");
	INIDATA->addData("가죽 신발", "MaxCon", "2500");
	INIDATA->addData("가죽 신발", "CurrentCon", "2500");

	INIDATA->addData("마법사 신발", "Type", "ARMOR");
	INIDATA->addData("마법사 신발", "Rank", "A");
	INIDATA->addData("마법사 신발", "Name", "마법사 신발");
	INIDATA->addData("마법사 신발", "Info", "LUC + 30     DEX + 30");
	INIDATA->addData("마법사 신발", "LVCondition", "5");
	INIDATA->addData("마법사 신발", "Dex", "30");
	INIDATA->addData("마법사 신발", "Luc", "30");
	INIDATA->addData("마법사 신발", "Def", "25");
	INIDATA->addData("마법사 신발", "Seal", "false");
	INIDATA->addData("마법사 신발", "Price", "5000");
	INIDATA->addData("마법사 신발", "FrameX", "1");
	INIDATA->addData("마법사 신발", "FrameY", "3");
	INIDATA->addData("마법사 신발", "MaxCon", "2500");
	INIDATA->addData("마법사 신발", "CurrentCon", "2500");

	INIDATA->addData("에메랄드 귀거리", "Type", "ARMOR");
	INIDATA->addData("에메랄드 귀거리", "Rank", "B");
	INIDATA->addData("에메랄드 귀거리", "Name", "에메랄드 귀거리");
	INIDATA->addData("에메랄드 귀거리", "Info", "LUC + 40");
	INIDATA->addData("에메랄드 귀거리", "LVCondition", "3");
	INIDATA->addData("에메랄드 귀거리", "Luc", "40");
	INIDATA->addData("에메랄드 귀거리", "Def", "10");
	INIDATA->addData("에메랄드 귀거리", "Seal", "false");
	INIDATA->addData("에메랄드 귀거리", "Price", "3000");
	INIDATA->addData("에메랄드 귀거리", "FrameX", "0");
	INIDATA->addData("에메랄드 귀거리", "FrameY", "4");
	INIDATA->addData("에메랄드 귀거리", "MaxCon", "2500");
	INIDATA->addData("에메랄드 귀거리", "CurrentCon", "2500");

	INIDATA->addData("요정눈물 귀거리", "Type", "ARMOR");
	INIDATA->addData("요정눈물 귀거리", "Rank", "A");
	INIDATA->addData("요정눈물 귀거리", "Name", "요정눈물 귀거리");
	INIDATA->addData("요정눈물 귀거리", "Info", "LUC + 80");
	INIDATA->addData("요정눈물 귀거리", "LVCondition", "7");
	INIDATA->addData("요정눈물 귀거리", "Luc", "8");
	INIDATA->addData("요정눈물 귀거리", "Def", "15");
	INIDATA->addData("요정눈물 귀거리", "Seal", "false");
	INIDATA->addData("요정눈물 귀거리", "Price", "7000");
	INIDATA->addData("요정눈물 귀거리", "FrameX", "1");
	INIDATA->addData("요정눈물 귀거리", "FrameY", "4");
	INIDATA->addData("요정눈물 귀거리", "MaxCon", "2500");
	INIDATA->addData("요정눈물 귀거리", "CurrentCon", "2500");

	INIDATA->addData("A룬", "Type", "RUNE");
	INIDATA->addData("A룬", "Name", "A룬");
	INIDATA->addData("A룬", "Info", "룬을 조합하여 마법을 사용 할수 있다.");
	INIDATA->addData("A룬", "Price", "7000");
	INIDATA->addData("A룬", "FrameX", "0");
	INIDATA->addData("A룬", "FrameY", "5");

	INIDATA->addData("B룬", "Type", "RUNE");
	INIDATA->addData("B룬", "Name", "B룬");
	INIDATA->addData("B룬", "Info", "룬을 조합하여 마법을 사용 할수 있다.");
	INIDATA->addData("B룬", "Price", "7000");
	INIDATA->addData("B룬", "FrameX", "1");
	INIDATA->addData("B룬", "FrameY", "5");

	INIDATA->addData("C룬", "Type", "RUNE");
	INIDATA->addData("C룬", "Name", "C룬");
	INIDATA->addData("C룬", "Info", "룬을 조합하여 마법을 사용 할수 있다.");
	INIDATA->addData("C룬", "Price", "7000");
	INIDATA->addData("C룬", "FrameX", "2");
	INIDATA->addData("C룬", "FrameY", "5");

	INIDATA->addData("D룬", "Type", "RUNE");
	INIDATA->addData("D룬", "Name", "D룬");
	INIDATA->addData("D룬", "Info", "룬을 조합하여 마법을 사용 할수 있다.");
	INIDATA->addData("D룬", "Price", "7000");
	INIDATA->addData("D룬", "FrameX", "3");
	INIDATA->addData("D룬", "FrameY", "5");

	INIDATA->addData("E룬", "Type", "RUNE");
	INIDATA->addData("E룬", "Name", "E룬");
	INIDATA->addData("E룬", "Info", "룬을 조합하여 마법을 사용 할수 있다.");
	INIDATA->addData("E룬", "Price", "7000");
	INIDATA->addData("E룬", "FrameX", "4");
	INIDATA->addData("E룬", "FrameY", "5");

	INIDATA->addData("F룬", "Type", "RUNE");
	INIDATA->addData("F룬", "Name", "F룬");
	INIDATA->addData("F룬", "Info", "룬을 조합하여 마법을 사용 할수 있다.");
	INIDATA->addData("F룬", "Price", "7000");
	INIDATA->addData("F룬", "FrameX", "5");
	INIDATA->addData("F룬", "FrameY", "5");

	INIDATA->addData("요정의 물약", "Type", "POTION");
	INIDATA->addData("요정의 물약", "Name", "요정의 물약");
	INIDATA->addData("요정의 물약", "Info", "체력을 100 회복한다.");
	INIDATA->addData("요정의 물약", "Price", "1000");
	INIDATA->addData("요정의 물약", "FrameX", "0");
	INIDATA->addData("요정의 물약", "FrameY", "6");
	INIDATA->addData("요정의 물약", "Heal", "100");


	INIDATA->addData("아이스 프리즌의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("아이스 프리즌의 서", "Name", "아이스 프리즌의 서");
	INIDATA->addData("아이스 프리즌의 서", "Info", "적을 가두는 얼음을 생성한다.");
	INIDATA->addData("아이스 프리즌의 서", "UseCount", "3");
	INIDATA->addData("아이스 프리즌의 서", "FrameX", "7");
	INIDATA->addData("아이스 프리즌의 서", "FrameY", "7");

	INIDATA->addData("프로텍션의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("프로텍션의 서", "Name", "프로텍션의 서");
	INIDATA->addData("프로텍션의 서", "Info", "마법의 방패를 생성한다");
	INIDATA->addData("프로텍션의 서", "UseCount", "3");
	INIDATA->addData("프로텍션의 서", "FrameX", "8");
	INIDATA->addData("프로텍션의 서", "FrameY", "7");

	INIDATA->addData("그래비티의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("그래비티의 서", "Name", "그래비티의 서");
	INIDATA->addData("그래비티의 서", "Info", "적을 빨아들이는 중력장을 발생시킨다");
	INIDATA->addData("그래비티의 서", "UseCount", "3");
	INIDATA->addData("그래비티의 서", "FrameX", "9");
	INIDATA->addData("그래비티의 서", "FrameY", "7");


	INIDATA->addData("썬더 클라우드의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("썬더 클라우드의 서", "Name", "썬더 클라우드의 서");
	INIDATA->addData("썬더 클라우드의 서", "Info", "벼락을 떨어트리는 뇌운을 발생시킨다");
	INIDATA->addData("썬더 클라우드의 서", "UseCount", "3");
	INIDATA->addData("썬더 클라우드의 서", "FrameX", "3");
	INIDATA->addData("썬더 클라우드의 서", "FrameY", "7");

	INIDATA->addData("록 프레스의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("록 프레스의 서", "Name", "록 프레스의 서");
	INIDATA->addData("록 프레스의 서", "Info", "스턴 효과가 있는 암석을 떨어트린다");
	INIDATA->addData("록 프레스의 서", "UseCount", "3");
	INIDATA->addData("록 프레스의 서", "FrameX", "6");
	INIDATA->addData("록 프레스의 서", "FrameY", "7");

	INIDATA->addData("블리자드의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("블리자드의 서", "Name", "블리자드의 서");
	INIDATA->addData("블리자드의 서", "Info", "적을 얼리는 눈보라를 불러일으킨다");
	INIDATA->addData("블리자드의 서", "UseCount", "3");
	INIDATA->addData("블리자드의 서", "FrameX", "4");
	INIDATA->addData("블리자드의 서", "FrameY", "7");

	INIDATA->addData("크리에이트 푸드의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("크리에이트 푸드의 서", "Name", "크리에이트 푸드의 서");
	INIDATA->addData("크리에이트 푸드의 서", "Info", "주위에 음식을 만든다");
	INIDATA->addData("크리에이트 푸드의 서", "UseCount", "3");
	INIDATA->addData("크리에이트 푸드의 서", "FrameX", "2");
	INIDATA->addData("크리에이트 푸드의 서", "FrameY", "7");

	INIDATA->addData("커스의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("커스의 서", "Name", "커스의 서");
	INIDATA->addData("커스의 서", "Info", "적을 개구리 상태로 만든다");
	INIDATA->addData("커스의 서", "UseCount", "3");
	INIDATA->addData("커스의 서", "FrameX", "1");
	INIDATA->addData("커스의 서", "FrameY", "7");

	INIDATA->addData("페트리피케이션의 서", "Type", "SKILL_BOOK");
	INIDATA->addData("페트리피케이션의 서", "Name", "페트리피케이션의 서");
	INIDATA->addData("페트리피케이션의 서", "Info", "적을 석화 상태로 만든다");
	INIDATA->addData("페트리피케이션의 서", "UseCount", "3");
	INIDATA->addData("페트리피케이션의 서", "FrameX", "0");
	INIDATA->addData("페트리피케이션의 서", "FrameY", "7");*/

}