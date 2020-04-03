#pragma once
#include "item.h"
#include "gameNode.h"


class inven : public gameNode
{
private:
	tagItem _invenItem;
	item* _item;

	typedef vector<tagItem> VINVEN;
	typedef vector<tagItem>::iterator VIINVEN;

	VINVEN _vInven;
	VIINVEN _viInven;

	int _currentWhich;		//현재 아이템 위치
	int _currentAlpha;		//현재 위치 알파값
	int _currentReverse;	//아아템 알파값 리버스
	int _itemIndex;
	int _itemNum;			//가방속에 가지고 있는 아이템 개수
	int _leftFrameCursor;	//왼쪽 프레임 커서
	int _leftFrameMoveY;	//왼쪽 프레임 움직임 위치	

	bool _isItemSelect;		//가방에 등록
	int _bagIndex;			//가방번호
public:
	inven();
	~inven();
	HRESULT init();
	void update();
	void render();
	void release();

	//인벤에 아이템 추가하기
	void addInvenItem(char* name);

	//인벤 로딩
	void invenLoading();
	//인벤 세이브
	void invenSaving();
	//아이템 구입
	void itemBuy(char* name);
	//아이템 판매
	void itemSell(char* name);
public:
	//inven vector getter
	VINVEN getVInven(){ return _vInven; }
	VIINVEN getVIInven(){ return _viInven; }

	//현재 가지고 있는 아이템 인덱스
	int getItemIndex(){ return _itemIndex; }
	void setItemIndex(int itemIndex){ _itemIndex = itemIndex; }

	//가방에 등록할지말지
	void setItemSelect(bool isItemSelect){ _isItemSelect = isItemSelect; }
	bool getItemSelect(){ return _isItemSelect; }


	int getBagIndex(){ return _bagIndex; }
	void setBagIndex(int bagIndex){ _bagIndex = bagIndex; }
};

