#pragma once
#include <string>
#include <vector>
#include "gameNode.h"
#include "image.h"

enum ITEM_TYPE { WEAPON, ARMOR, POTION, SKILL_BOOK, RUNE };

struct tagItemAbility{

	//능력치용
	int HP;
	int STR;
	int INT;
	int CON;
	int MGR;
	int DEX;
	int LUC;

	int ATK;
	int DEF;

	int HEAL;
};

struct tagItem{
	ITEM_TYPE type;
	char rank[3];
	string name;
	string info;
	int LVCondition;
	tagItemAbility ability;
	int useCount;
	bool seal;
	int price;
	int currentCon;
	int maxCon;
	int frameX;
	int frameY;
};

class item 
{
	

private:
	tagItem _item;
	
	typedef vector<tagItem> vItem;
	typedef vector<tagItem>::iterator viItem;
	vItem _vItem;
	viItem _viItem;

public:
	item();
	~item();

	void itemSetting();
	vItem getVItem(){ return _vItem; }
	viItem getViItem(){ return _viItem; }
	
};

