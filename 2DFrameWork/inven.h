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

	int _currentWhich;		//���� ������ ��ġ
	int _currentAlpha;		//���� ��ġ ���İ�
	int _currentReverse;	//�ƾ��� ���İ� ������
	int _itemIndex;
	int _itemNum;			//����ӿ� ������ �ִ� ������ ����
	int _leftFrameCursor;	//���� ������ Ŀ��
	int _leftFrameMoveY;	//���� ������ ������ ��ġ	

	bool _isItemSelect;		//���濡 ���
	int _bagIndex;			//�����ȣ
public:
	inven();
	~inven();
	HRESULT init();
	void update();
	void render();
	void release();

	//�κ��� ������ �߰��ϱ�
	void addInvenItem(char* name);

	//�κ� �ε�
	void invenLoading();
	//�κ� ���̺�
	void invenSaving();
	//������ ����
	void itemBuy(char* name);
	//������ �Ǹ�
	void itemSell(char* name);
public:
	//inven vector getter
	VINVEN getVInven(){ return _vInven; }
	VIINVEN getVIInven(){ return _viInven; }

	//���� ������ �ִ� ������ �ε���
	int getItemIndex(){ return _itemIndex; }
	void setItemIndex(int itemIndex){ _itemIndex = itemIndex; }

	//���濡 �����������
	void setItemSelect(bool isItemSelect){ _isItemSelect = isItemSelect; }
	bool getItemSelect(){ return _isItemSelect; }


	int getBagIndex(){ return _bagIndex; }
	void setBagIndex(int bagIndex){ _bagIndex = bagIndex; }
};

