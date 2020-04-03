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

	_sorceressSkill[0].name = "멘탈 앱소브";
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
	_sorceressSkill[0].skillInfo = "적을 쓰러트렸을 때 MP가 회복된다";

	_sorceressSkill[1].name = "엑스트랙트";
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
	_sorceressSkill[1].skillInfo = "매직 샷의 MP 회복량이 증가한다";

	_sorceressSkill[2].name = "콘센트레이트";
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
	_sorceressSkill[2].skillInfo = "MP 차지 속도가 상승한다";

	_sorceressSkill[3].name = "매직 포인트 업";
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
	_sorceressSkill[3].skillInfo = "MP 최대치가 증가한다";

	_sorceressSkill[4].name = "아이스 프리즌";
	_sorceressSkill[4].LVCondition[0] = 1;
	_sorceressSkill[4].LVCondition[1] = 30;
	_sorceressSkill[4].LVCondition[2] = 60;
	_sorceressSkill[4].sKillPointCondition[0] = 1;
	_sorceressSkill[4].sKillPointCondition[1] = 3;
	_sorceressSkill[4].sKillPointCondition[2] = 5;
	_sorceressSkill[4].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "ice_prision");
	_sorceressSkill[4].skillLVMax = 3;
	_sorceressSkill[4].skillInfo = "적을 가두는 얼음을 발생시킨다";

	_sorceressSkill[5].name = "프로텍션";
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
	_sorceressSkill[5].skillInfo = "아군에게 마법의 방패를 부여한다";

	_sorceressSkill[6].name = "그래비티";
	_sorceressSkill[6].LVCondition[0] = 1;
	_sorceressSkill[6].LVCondition[1] = 20;
	_sorceressSkill[6].LVCondition[2] = 40;
	_sorceressSkill[6].sKillPointCondition[0] = 1;
	_sorceressSkill[6].sKillPointCondition[1] = 1;
	_sorceressSkill[6].sKillPointCondition[2] = 2;
	_sorceressSkill[6].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "gravity");
	_sorceressSkill[6].skillLVMax = 3;
	_sorceressSkill[6].skillInfo = "중력장을 발생시킨다";

	_sorceressSkill[7].name = "썬더 클라우드";
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
	_sorceressSkill[7].skillInfo = "벼락을 떨어트리는 뇌운을 발생시킨다";

	_sorceressSkill[8].name = "록 프레스";
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
	_sorceressSkill[8].skillInfo = "암석을 떨어트린다";

	_sorceressSkill[9].name = "블리자드";
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
	_sorceressSkill[9].skillInfo = "적을 얼리는 눈보라를 불러일으킨다";

	_sorceressSkill[10].name = "레비테이션";
	_sorceressSkill[10].LVCondition[0] = 1;
	_sorceressSkill[10].LVCondition[1] = 31;
	_sorceressSkill[10].LVCondition[2] = 61;
	_sorceressSkill[10].sKillPointCondition[0] = 1;
	_sorceressSkill[10].sKillPointCondition[1] = 3;
	_sorceressSkill[10].sKillPointCondition[2] = 5;
	_sorceressSkill[10].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "ravitation");
	_sorceressSkill[10].skillLVMax = 3;
	_sorceressSkill[10].skillInfo = "마녀 비행을 할 수 있다";

	_sorceressSkill[11].name = "크리에이트 푸드";
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
	_sorceressSkill[11].skillInfo = "주위에 음식을 만든다";

	_sorceressSkill[12].name = "페트리피케이션";
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
	_sorceressSkill[12].skillInfo = "적을 석화 상태로 만든다";

	_sorceressSkill[13].name = "히트 포인트 업";
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
	_sorceressSkill[13].skillInfo = "HP 최대치가 증가한다";

	_sorceressSkill[14].name = "푸드 사으톨로지";
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
	_sorceressSkill[14].skillInfo = "음식의 회복량이 증가한다";

	_sorceressSkill[15].name = "메인테넌스";
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
	_sorceressSkill[15].skillInfo = "아이템 사용횟수가 증가한다";

	_sorceressSkill[16].name = "아이템 유저";
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
	_sorceressSkill[16].skillInfo = "아이템 사용후 체력이 회복된다";

}

