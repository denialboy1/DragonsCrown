#include "stdafx.h"
#include "skill.h"


skill::skill()
{
}


skill::~skill()
{
}
HRESULT skill::init(){
	sorceressSkillInit();

	return S_OK;
}
void skill::sorceressSkillInit(){
	memset(_sorceressSkill, 0, sizeof(_sorceressSkill));

	_sorceressSkill[0].name = "��Ż �ۼҺ�";
	_sorceressSkill[0].LVCondition[0] = 1;
	_sorceressSkill[0].LVCondition[1] = 9;
	_sorceressSkill[0].LVCondition[2] = 18;
	_sorceressSkill[0].LVCondition[3] = 27;
	_sorceressSkill[0].LVCondition[4] = 36;
	_sorceressSkill[0].LVCondition[5] = 45;
	_sorceressSkill[0].LVCondition[6] = 54;
	_sorceressSkill[0].LVCondition[7] = 63;
	_sorceressSkill[0].LVCondition[8] = 72;
	_sorceressSkill[0].LVCondition[9] = 81;
	_sorceressSkill[0].sKillPointCondition[0] = 1;
	_sorceressSkill[0].sKillPointCondition[1] = 1;
	_sorceressSkill[0].sKillPointCondition[2] = 1;
	_sorceressSkill[0].sKillPointCondition[3] = 2;
	_sorceressSkill[0].sKillPointCondition[4] = 2;
	_sorceressSkill[0].sKillPointCondition[5] = 3;
	_sorceressSkill[0].sKillPointCondition[6] = 3;
	_sorceressSkill[0].sKillPointCondition[7] = 4;
	_sorceressSkill[0].sKillPointCondition[8] = 4;
	_sorceressSkill[0].sKillPointCondition[9] = 5;
	_sorceressSkill[0].skillLV = INIDATA->loadDataInterger("PlayerData","Skill","mental_absorb");
	_sorceressSkill[0].skillLVMax = 10;
	_sorceressSkill[0].skillInfo = "���� ����Ʈ���� �� MP�� ȸ���ȴ�";

	_sorceressSkill[1].name = "����Ʈ��Ʈ";
	_sorceressSkill[1].LVCondition[0] = 1;
	_sorceressSkill[1].LVCondition[1] = 12;
	_sorceressSkill[1].LVCondition[2] = 24;
	_sorceressSkill[1].LVCondition[3] = 36;
	_sorceressSkill[1].LVCondition[4] = 48;
	_sorceressSkill[1].LVCondition[5] = 50;
	_sorceressSkill[1].LVCondition[6] = 62;
	_sorceressSkill[1].sKillPointCondition[0] = 1;
	_sorceressSkill[1].sKillPointCondition[1] = 1;
	_sorceressSkill[1].sKillPointCondition[2] = 2;
	_sorceressSkill[1].sKillPointCondition[3] = 2;
	_sorceressSkill[1].sKillPointCondition[4] = 3;
	_sorceressSkill[1].sKillPointCondition[5] = 3;
	_sorceressSkill[1].sKillPointCondition[6] = 5;
	_sorceressSkill[1].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "extract");
	_sorceressSkill[1].skillLVMax = 7;
	_sorceressSkill[1].skillInfo = "���� ���� MP ȸ������ �����Ѵ�";

	_sorceressSkill[2].name = "�ܼ�Ʈ����Ʈ";
	_sorceressSkill[2].LVCondition[0] = 1;
	_sorceressSkill[2].LVCondition[1] = 20;
	_sorceressSkill[2].LVCondition[2] = 40;
	_sorceressSkill[2].LVCondition[3] = 60;
	_sorceressSkill[2].LVCondition[4] = 80;
	_sorceressSkill[2].sKillPointCondition[0] = 1;
	_sorceressSkill[2].sKillPointCondition[1] = 1;
	_sorceressSkill[2].sKillPointCondition[2] = 2;
	_sorceressSkill[2].sKillPointCondition[3] = 3;
	_sorceressSkill[2].sKillPointCondition[4] = 5;
	_sorceressSkill[2].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "concentrate");
	_sorceressSkill[2].skillLVMax = 5;
	_sorceressSkill[2].skillInfo = "MP ���� �ӵ��� ����Ѵ�";

	_sorceressSkill[3].name = "���� ����Ʈ ��";
	_sorceressSkill[3].LVCondition[0] = 1;
	_sorceressSkill[3].LVCondition[1] = 10;
	_sorceressSkill[3].LVCondition[2] = 20;
	_sorceressSkill[3].LVCondition[3] = 30;
	_sorceressSkill[3].LVCondition[4] = 40;
	_sorceressSkill[3].sKillPointCondition[0] = 1;
	_sorceressSkill[3].sKillPointCondition[1] = 1;
	_sorceressSkill[3].sKillPointCondition[2] = 2;
	_sorceressSkill[3].sKillPointCondition[3] = 3;
	_sorceressSkill[3].sKillPointCondition[4] = 5;
	_sorceressSkill[3].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "magic_point_up");
	_sorceressSkill[3].skillLVMax = 5;
	_sorceressSkill[3].skillInfo = "MP �ִ�ġ�� �����Ѵ�";

	_sorceressSkill[4].name = "���̽� ������";
	_sorceressSkill[4].LVCondition[0] = 1;
	_sorceressSkill[4].LVCondition[1] = 30;
	_sorceressSkill[4].LVCondition[2] = 60;
	_sorceressSkill[4].sKillPointCondition[0] = 1;
	_sorceressSkill[4].sKillPointCondition[1] = 3;
	_sorceressSkill[4].sKillPointCondition[2] = 5;
	_sorceressSkill[4].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "ice_prision");
	_sorceressSkill[4].skillLVMax = 3;
	_sorceressSkill[4].skillInfo = "���� ���δ� ������ �߻���Ų��";

	_sorceressSkill[5].name = "�����ؼ�";
	_sorceressSkill[5].LVCondition[0] = 1;
	_sorceressSkill[5].LVCondition[1] = 7;
	_sorceressSkill[5].LVCondition[2] = 15;
	_sorceressSkill[5].LVCondition[3] = 25;
	_sorceressSkill[5].LVCondition[4] = 35;
	_sorceressSkill[5].sKillPointCondition[0] = 1;
	_sorceressSkill[5].sKillPointCondition[1] = 1;
	_sorceressSkill[5].sKillPointCondition[2] = 2;
	_sorceressSkill[5].sKillPointCondition[3] = 3;
	_sorceressSkill[5].sKillPointCondition[4] = 5;
	_sorceressSkill[5].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "protection");
	_sorceressSkill[5].skillLVMax = 5;
	_sorceressSkill[5].skillInfo = "�Ʊ����� ������ ���и� �ο��Ѵ�";

	_sorceressSkill[6].name = "�׷���Ƽ";
	_sorceressSkill[6].LVCondition[0] = 1;
	_sorceressSkill[6].LVCondition[1] = 20;
	_sorceressSkill[6].LVCondition[2] = 40;
	_sorceressSkill[6].sKillPointCondition[0] = 1;
	_sorceressSkill[6].sKillPointCondition[1] = 1;
	_sorceressSkill[6].sKillPointCondition[2] = 2;
	_sorceressSkill[6].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "gravity");
	_sorceressSkill[6].skillLVMax = 3;
	_sorceressSkill[6].skillInfo = "�߷����� �߻���Ų��";

	_sorceressSkill[7].name = "��� Ŭ����";
	_sorceressSkill[7].LVCondition[0] = 1;
	_sorceressSkill[7].LVCondition[1] = 8;
	_sorceressSkill[7].LVCondition[2] = 16;
	_sorceressSkill[7].LVCondition[3] = 24;
	_sorceressSkill[7].LVCondition[4] = 32;
	_sorceressSkill[7].LVCondition[5] = 40;
	_sorceressSkill[7].LVCondition[6] = 48;
	_sorceressSkill[7].sKillPointCondition[0] = 1;
	_sorceressSkill[7].sKillPointCondition[1] = 1;
	_sorceressSkill[7].sKillPointCondition[2] = 2;
	_sorceressSkill[7].sKillPointCondition[3] = 2;
	_sorceressSkill[7].sKillPointCondition[4] = 3;
	_sorceressSkill[7].sKillPointCondition[5] = 3;
	_sorceressSkill[7].sKillPointCondition[6] = 5;
	_sorceressSkill[7].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "thunder_cloud");
	_sorceressSkill[7].skillLVMax = 7;
	_sorceressSkill[7].skillInfo = "������ ����Ʈ���� ������ �߻���Ų��";

	_sorceressSkill[8].name = "�� ������";
	_sorceressSkill[8].LVCondition[0] = 1;
	_sorceressSkill[8].LVCondition[1] = 6;
	_sorceressSkill[8].LVCondition[2] = 12;
	_sorceressSkill[8].LVCondition[3] = 22;
	_sorceressSkill[8].LVCondition[4] = 38;
	_sorceressSkill[8].LVCondition[5] = 42;
	_sorceressSkill[8].LVCondition[6] = 52;
	_sorceressSkill[8].sKillPointCondition[0] = 1;
	_sorceressSkill[8].sKillPointCondition[1] = 1;
	_sorceressSkill[8].sKillPointCondition[2] = 2;
	_sorceressSkill[8].sKillPointCondition[3] = 2;
	_sorceressSkill[8].sKillPointCondition[4] = 3;
	_sorceressSkill[8].sKillPointCondition[5] = 3;
	_sorceressSkill[8].sKillPointCondition[6] = 5;
	_sorceressSkill[8].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "rock_press");
	_sorceressSkill[8].skillLVMax = 7;
	_sorceressSkill[8].skillInfo = "�ϼ��� ����Ʈ����";

	_sorceressSkill[9].name = "���ڵ�";
	_sorceressSkill[9].LVCondition[0] = 1;
	_sorceressSkill[9].LVCondition[1] = 20;
	_sorceressSkill[9].LVCondition[2] = 40;
	_sorceressSkill[9].LVCondition[3] = 60;
	_sorceressSkill[9].LVCondition[4] = 80;
	_sorceressSkill[9].sKillPointCondition[0] = 1;
	_sorceressSkill[9].sKillPointCondition[1] = 1;
	_sorceressSkill[9].sKillPointCondition[2] = 2;
	_sorceressSkill[9].sKillPointCondition[3] = 3;
	_sorceressSkill[9].sKillPointCondition[4] = 5;
	_sorceressSkill[9].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "blizzard");
	_sorceressSkill[9].skillLVMax = 5;
	_sorceressSkill[9].skillInfo = "���� �󸮴� ������ �ҷ�����Ų��";

	_sorceressSkill[10].name = "�������̼�";
	_sorceressSkill[10].LVCondition[0] = 1;
	_sorceressSkill[10].LVCondition[1] = 31;
	_sorceressSkill[10].LVCondition[2] = 61;
	_sorceressSkill[10].sKillPointCondition[0] = 1;
	_sorceressSkill[10].sKillPointCondition[1] = 3;
	_sorceressSkill[10].sKillPointCondition[2] = 5;
	_sorceressSkill[10].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "ravitation");
	_sorceressSkill[10].skillLVMax = 3;
	_sorceressSkill[10].skillInfo = "���� ������ �� �� �ִ�";

	_sorceressSkill[11].name = "ũ������Ʈ Ǫ��";
	_sorceressSkill[11].LVCondition[0] = 1;
	_sorceressSkill[11].LVCondition[1] = 21;
	_sorceressSkill[11].LVCondition[2] = 41;
	_sorceressSkill[11].LVCondition[3] = 61;
	_sorceressSkill[11].LVCondition[4] = 81;
	_sorceressSkill[11].sKillPointCondition[0] = 1;
	_sorceressSkill[11].sKillPointCondition[1] = 1;
	_sorceressSkill[11].sKillPointCondition[2] = 2;
	_sorceressSkill[11].sKillPointCondition[3] = 2;
	_sorceressSkill[11].sKillPointCondition[4] = 4;
	_sorceressSkill[11].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "create_food");
	_sorceressSkill[11].skillLVMax = 5;
	_sorceressSkill[11].skillInfo = "������ ������ �����";

	_sorceressSkill[12].name = "��Ʈ�������̼�";
	_sorceressSkill[12].LVCondition[0] = 1;
	_sorceressSkill[12].LVCondition[1] = 11;
	_sorceressSkill[12].LVCondition[2] = 21;
	_sorceressSkill[12].LVCondition[3] = 31;
	_sorceressSkill[12].LVCondition[4] = 41;
	_sorceressSkill[12].LVCondition[5] = 51;
	_sorceressSkill[12].LVCondition[6] = 61;
	_sorceressSkill[12].sKillPointCondition[0] = 1;
	_sorceressSkill[12].sKillPointCondition[1] = 1;
	_sorceressSkill[12].sKillPointCondition[2] = 2;
	_sorceressSkill[12].sKillPointCondition[3] = 2;
	_sorceressSkill[12].sKillPointCondition[4] = 3;
	_sorceressSkill[12].sKillPointCondition[5] = 3;
	_sorceressSkill[12].sKillPointCondition[6] = 5;
	_sorceressSkill[12].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "petrification");
	_sorceressSkill[12].skillLVMax = 7;
	_sorceressSkill[12].skillInfo = "���� ��ȭ ���·� �����";

	_sorceressSkill[13].name = "��Ʈ ����Ʈ ��";
	_sorceressSkill[13].LVCondition[0] = 1;
	_sorceressSkill[13].LVCondition[1] = 7;
	_sorceressSkill[13].LVCondition[2] = 13;
	_sorceressSkill[13].LVCondition[3] = 19;
	_sorceressSkill[13].LVCondition[4] = 25;
	_sorceressSkill[13].LVCondition[5] = 31;
	_sorceressSkill[13].LVCondition[6] = 38;
	_sorceressSkill[13].LVCondition[7] = 45;
	_sorceressSkill[13].LVCondition[8] = 52;
	_sorceressSkill[13].LVCondition[9] = 59;
	_sorceressSkill[13].sKillPointCondition[0] = 1;
	_sorceressSkill[13].sKillPointCondition[1] = 1;
	_sorceressSkill[13].sKillPointCondition[2] = 1;
	_sorceressSkill[13].sKillPointCondition[3] = 2;
	_sorceressSkill[13].sKillPointCondition[4] = 2;
	_sorceressSkill[13].sKillPointCondition[5] = 3;
	_sorceressSkill[13].sKillPointCondition[6] = 3;
	_sorceressSkill[13].sKillPointCondition[7] = 4;
	_sorceressSkill[13].sKillPointCondition[8] = 4;
	_sorceressSkill[13].sKillPointCondition[9] = 6;
	_sorceressSkill[13].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "hit_point_up");
	_sorceressSkill[13].skillLVMax = 10;
	_sorceressSkill[13].skillInfo = "HP �ִ�ġ�� �����Ѵ�";

	_sorceressSkill[14].name = "Ǫ�� ���������";
	_sorceressSkill[14].LVCondition[0] = 1;
	_sorceressSkill[14].LVCondition[1] = 11;
	_sorceressSkill[14].LVCondition[2] = 24;
	_sorceressSkill[14].LVCondition[3] = 37;
	_sorceressSkill[14].LVCondition[4] = 51;
	_sorceressSkill[14].sKillPointCondition[0] = 1;
	_sorceressSkill[14].sKillPointCondition[1] = 1;
	_sorceressSkill[14].sKillPointCondition[2] = 2;
	_sorceressSkill[14].sKillPointCondition[3] = 3;
	_sorceressSkill[14].sKillPointCondition[4] = 4;
	_sorceressSkill[14].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "food_psytology");
	_sorceressSkill[14].skillLVMax = 5;
	_sorceressSkill[14].skillInfo = "������ ȸ������ �����Ѵ�";

	_sorceressSkill[15].name = "�����׳ͽ�";
	_sorceressSkill[15].LVCondition[0] = 1;
	_sorceressSkill[15].LVCondition[1] = 6;
	_sorceressSkill[15].LVCondition[2] = 13;
	_sorceressSkill[15].LVCondition[3] = 23;
	_sorceressSkill[15].LVCondition[4] = 34;
	_sorceressSkill[15].sKillPointCondition[0] = 1;
	_sorceressSkill[15].sKillPointCondition[1] = 1;
	_sorceressSkill[15].sKillPointCondition[2] = 2;
	_sorceressSkill[15].sKillPointCondition[3] = 3;
	_sorceressSkill[15].sKillPointCondition[4] = 4;
	_sorceressSkill[15].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance");
	_sorceressSkill[15].skillLVMax = 5;
	_sorceressSkill[15].skillInfo = "������ ���Ƚ���� �����Ѵ�";

	_sorceressSkill[16].name = "������ ����";
	_sorceressSkill[16].LVCondition[0] = 1;
	_sorceressSkill[16].LVCondition[1] = 9;
	_sorceressSkill[16].LVCondition[2] = 16;
	_sorceressSkill[16].LVCondition[3] = 22;
	_sorceressSkill[16].LVCondition[4] = 29;
	_sorceressSkill[16].LVCondition[5] = 36;
	_sorceressSkill[16].LVCondition[6] = 44;
	_sorceressSkill[16].sKillPointCondition[0] = 1;
	_sorceressSkill[16].sKillPointCondition[1] = 1;
	_sorceressSkill[16].sKillPointCondition[2] = 2;
	_sorceressSkill[16].sKillPointCondition[3] = 2;
	_sorceressSkill[16].sKillPointCondition[4] = 3;
	_sorceressSkill[16].sKillPointCondition[5] = 3;
	_sorceressSkill[16].sKillPointCondition[6] = 5;
	_sorceressSkill[16].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "item_user");
	_sorceressSkill[16].skillLVMax = 7;
	_sorceressSkill[16].skillInfo = "������ ����� ü���� ȸ���ȴ�";

}

