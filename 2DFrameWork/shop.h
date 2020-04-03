#pragma once
#include "gameNode.h"
#include "item.h"

class shop : public gameNode
{
	//�� ���� �����ְ� �ִ� ȭ��(Ű���� ������ ����)
	enum SHOP_WINDOW{ SHOP, BUY, SELL, REPAIR, ANALYZE, BUY_CONFIRM, SELL_CONFIRM, REPAIR_CONFIRM, ANALYZE_CONFIRM };
	enum SHOP_ACTION{ ITEM_BUY, ITEM_SELL, ITEM_REPAIR, ITEM_ANALYZE, SHOP_EXIT };
private:
	animation* _npcMove;
	SHOP_WINDOW _shopWindow;

	int _shopActionNumber;
	SHOP_ACTION _shopAction;

	//���� ��ġ�� ������ �ε���
	int _itemIndex;
	int _playerIndex;

	//�������� �Ǹ��ϴ� ����
	int _itemBuyNum;

	//������ ������ ����
	int _repairNum;

	//������ ������ ����
	int _analyzeNum;


	//���� ������ Ŀ��
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

	//�� ó�� ���� ȭ��
	void shopInit();
	void shopUpdate();
	void shopRender();

	//������ ���
	void buyInit();
	void buyUpdate();
	void buyRender();

	//������ �ȱ�
	void sellInit();
	void sellUpdate();
	void sellRender();

	//������ ����
	void repairInit();
	void repairUpdate();
	void repairRender();

	//������ ����
	void analyzeInit();
	void analyzeUpdate();
	void analyzeRender();

	//�ൿ�� �Ұ��� Ȯ���ϴ� ȭ��
	void confirmInit();
	void confirmUpdate();
	void confirmRender();

	void dataSave();
};

