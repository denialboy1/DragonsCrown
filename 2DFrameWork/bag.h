#pragma once
#include "gameNode.h"

struct tagBag{
	int index;
	string name;
};

class inven;

class bag : public gameNode
{
private:
	
	int _currentSelect;			//현재 선택된 위치
	int _currentAlpha;			//현재 선택된 위치 알파값
	int _currentReverse;		//알파값 뒤집기

	inven* _inven;				//인벤토리와 상호참조

	tagBag _bagArr[8];
public:
	bag();
	~bag();

	HRESULT init();
	void update();
	void render();
	void release();

	void addressLinkInven(inven* inven){ _inven = inven; }

	//가방에 등록하기
	void equipItem();

	//저장하기
	void bagSave();
};

