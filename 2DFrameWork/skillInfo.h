#pragma once
#include "gameNode.h"
#include "skill.h"
class skillInfo : public gameNode
{
private:
	skill* _skill;

	int _currentWhich;		//���� ������ ��ġ
	int _currentAlpha;		//���� ��ġ ���İ�
	int _currentReverse;	//�ƾ��� ���İ� ������
	int _botFrameCursor;	//�Ʒ� ������ Ŀ��
	int _botFrameMoveY;		//�Ʒ� ������ ������ ��ġ	
public:
	skillInfo();
	~skillInfo();

	HRESULT init();
	void update();
	void render();
	void release();
};

