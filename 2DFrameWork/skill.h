#pragma once
#include "gameNode.h"

//��ų ����ü
struct tagSkill{
	string name;						//��ų �̸�
	int LVCondition[10];				//��������
	int sKillPointCondition[10];		//�ʿ佺ų����Ʈ����
	int skillLV;						//���� ��ų����
	int skillLVMax;						//�ƽ� ��ų����
	string skillInfo;					//��ų����
};

class skill : public gameNode
{
private:
	//�Ҽ����� ��ų ���
	tagSkill _sorceressSkill[17];

	//�Ҽ����� ��ų �ʱ�ȭ
	void sorceressSkillInit();

public:
	skill();
	~skill();

	HRESULT init();
public:
	tagSkill* getSorceressSkill(){ return _sorceressSkill; }
};

