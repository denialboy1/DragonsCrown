#pragma once
#include "gameNode.h"
#include "item.h"

class shop : public gameNode
{
	//맨 위에 보여주고 있는 화면(키보드 조작을 위해)
	enum SHOP_WINDOW{ SHOP, BUY, SELL, REPAIR, ANALYZE, BUY_CONFIRM, SELL_CONFIRM, REPAIR_CONFIRM, ANALYZE_CONFIRM };
	enum SHOP_ACTION{ ITEM_BUY, ITEM_SELL, ITEM_REPAIR, ITEM_ANALYZE, SHOP_EXIT };
private:
	animation* _npcMove;
	SHOP_WINDOW _shopWindow;

	int _shopActionNumber;
	SHOP_ACTION _shopAction;

	//현재 위치한 아이템 인덱스
	int _itemIndex;
	int _playerIndex;

	//상점에서 판매하는 개수
	int _itemBuyNum;

	//수리할 아이템 개수
	int _repairNum;

	//감정할 아이템 개수
	int _analyzeNum;


	//왼쪽 프레임 커서
	int _leftFrameCursor;
	int _leftFrameMoveY;
	item* _item;


	vector<tagItem> _shopItem;

	vector<tagItem> _sellItem;

	vector<tagItem> _analyzeItem;

	vector<tagItem> _repairItem;
	bool _bConfirm;

	struct tagItem2{
		int count;
		int seal;
		int currentCon;
		int maxCon;
	};
	tagItem2 _itemCount[20];
	//int _staff[4];
	//int _armor[9];
	//int _rune[6];
	//int _potion;

	bool _moneyError;
	int _money;

	bool _analyzeError;
public:

	shop();
	~shop();

	HRESULT init();
	void update();
	void render();
	void release();

	//맨 처음 상점 화면
	void shopInit();
	void shopUpdate();
	void shopRender();

	//아이템 사기
	void buyInit();
	void buyUpdate();
	void buyRender();

	//아이템 팔기
	void sellInit();
	void sellUpdate();
	void sellRender();

	//아이템 수리
	void repairInit();
	void repairUpdate();
	void repairRender();

	//아이템 감정
	void analyzeInit();
	void analyzeUpdate();
	void analyzeRender();

	//행동을 할건지 확인하는 화면
	void confirmInit();
	void confirmUpdate();
	void confirmRender();

	void dataSave();
};

