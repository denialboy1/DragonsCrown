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
	
	int _currentSelect;			//���� ���õ� ��ġ
	int _currentAlpha;			//���� ���õ� ��ġ ���İ�
	int _currentReverse;		//���İ� ������

	inven* _inven;				//�κ��丮�� ��ȣ����

	tagBag _bagArr[8];
public:
	bag();
	~bag();

	HRESULT init();
	void update();
	void render();
	void release();

	void addressLinkInven(inven* inven){ _inven = inven; }

	//���濡 ����ϱ�
	void equipItem();

	//�����ϱ�
	void bagSave();
};

