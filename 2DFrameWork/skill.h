#pragma once
#include "gameNode.h"

//스킬 구조체
struct tagSkill{
	string name;						//스킬 이름
	int LVCondition[10];				//레벨조건
	int sKillPointCondition[10];		//필요스킬포인트개수
	int skillLV;						//현재 스킬레벨
	int skillLVMax;						//맥스 스킬레벨
	string skillInfo;					//스킬정보
};

class skill : public gameNode
{
private:
	//소서리스 스킬 목록
	tagSkill _sorceressSkill[17];

	//소서리스 스킬 초기화
	void sorceressSkillInit();

public:
	skill();
	~skill();

	HRESULT init();
public:
	tagSkill* getSorceressSkill(){ return _sorceressSkill; }
};

