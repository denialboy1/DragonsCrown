#pragma once
#include "gameNode.h"
#include "animation.h"

#define SKILLMOVEX 10


//스킬 열고 닫는 애니메이션 끝난후 콜백처리용
static bool _bSkillListMoveOpen;
static bool _bSkillListMoveClose;

static int _sorceressSkillChoice;
static int _skillMoveX;
static int _skillMoveXMax;
static int _commonSkillChoice;

//길드 화면, 스킬 선택화면, 소서리스 스킬, 공용 스킬,소서리스 스킬 확인창, 공용 스킬 확인창,
// 소서리스 스킬 포인트 에러 창, 소서리스 레벨 에러창, 소서리스 스킬 마스터 에러창
// 공용 스킬 포인트 에러창, 공용 레벨 에러창, 공용 스킬 마스터 에러창
enum GUILD_STATE{ GUILD, SKILL_CHOICE, SORCERESS_SKILL, COMMON_SKILL, SORCERESS_CONFIRM, COMMON_CONFIRM ,
	SORCERESS_SKILL_POINT_ERROR, SORCERESS_LV_ERROR, SORCERESS_SKILL_MASTER_ERROR,
	COMMON_SKILL_POINT_ERROR, COMMON_LV_ERROR, COMMON_SKILL_MASTER_ERROR
};
static GUILD_STATE _guildState;

class guildScene : public gameNode
{
	//어떤종류의 스킬을 선택할지
	//1.소서리스 스킬
	//2.일반 스킬
	enum SKILL_CHOICE_STATE{ SORCERESS, COMMON };

	//소서리스 스킬 목록
	enum SORCERESS_SKILL_LIST{
		MENTAL_ABSORB,	//멘탈 앱소브 : 적을 쓰려트렸을때 MP가 회복
		EXTRACT,		//엑스트랙트  : 매직 샷의 MP 회복량이 증가
		CONCENTRATE,	//콘센트레이트 : MP 차지 속도가 상승
		MAGIC_POINT_UP, //매직 포인트 업 : MP 최대치가 증가
		ICE_PRISION,	//아이스 프리즌 : 적을 가두는 얼음을 발생
		PROTECTION,		//프로텍션 : 아군에게 마법의 방패를 부여
		GRAVITY,		//그래비티 : 적을 빨아들이는 중력장을 발생
		THUNDER_CLOUD,	//썬더 클라우드 : 벼락을 떨어트리는 뇌운을 발생
		ROCK_PRESS,		//록 프레스 : 스턴 효과가 있는 암석을 떨어트림
		BLIZZARD,		//블리자드 : 적을 얼리는 눈보라를 불러일으킴
		ANIMATE_SKELTON, //애니메이트 스켈톤 : 스켈톤을 생성
		RAVITATION,		//레비테이션 : 마녀비행을 할수있음
		CREATE_FOOD,	//크리에이트 푸드 : 주위에 음식을 만든다.
		CURSE,			//커스 : 적을 개구리 상태로 만듬
		PETRIFICATION,  //페트리피케이션 : 적을 석화상태로 만듬
	};

	
	//공용스킬목록
	enum COMMAN_SKILL_LIST{
		SLIDING,		// 슬라이딩 : 슬라이딩 강화
		GOLD_HEALING,	// 골드 힐링 : 코인 획득 시에 HP회복
		GOLD_SCORING,	// 골드 스코어링 : 코인 획득 시에 스코어 획득
		HIT_POINT_UP,	// 히트 포인트 업 : HP 최대치가 증가
		FOOD_PSYTOLOGY, //푸드 사이톨로지 : 음식 회복량 증가
		MAINTENANCE,	//메인테넌스 : 무기 사용 횟수가 잘 감소하지 않음
		ITEM_USER,		//아이템 유저 : 아이템 재사용시간 단축
		EVADE,			//이베이드 : 연속으로 회피
		EXTRA_POCKET,	//가방의 아이템 슬롯을 확장
	};

	//현재 선택한 메뉴
	enum MENUSTATE{ SKILL, GUILDEXIT };

	//스킬 구조체
	struct tagSkill{
		string name;						//스킬 이름
		int LVCondition[10];				//레벨조건
		int sKillPointCondition[10];		//필요스킬포인트개수
		int skillLV;						//현재 스킬레벨
		int skillLVMax;						//맥스 스킬레벨
		string skillInfo;					//스킬정보
	};

private:

	
	

	//길드메뉴선택
	int _menuChoice;
	MENUSTATE _menuState;

	//소서리스 또는 공용스킬 선택
	int _skillListChoice;
	SKILL_CHOICE_STATE _skillChioceState;

	//소서리스 스킬 선택
	SORCERESS_SKILL_LIST _sorceressSkillList;

	//공용 스킬 선택
	COMMAN_SKILL_LIST _commonSkillList;

	//소서리스 스킬 목록
	tagSkill _sorceressSkill[13];
	//공용 스킬목록
	tagSkill _commonSkill[4];

	//스킬리스트움직임조절
	//소서리스
	int _skillListX1;
	int _skillListX2;

	//공용
	int _commonSkillListX1;
	int _commonSkillListX2;
	static void skillMoveOpen(void* obj);
	static void skillMoveClose(void* obj);

	//스킬움직임 조절
	bool _bSkillLeftMove;
	bool _bSkillRightMove;
	
	
	//스킬포인트가 부족하다는 오류 불값
	bool _pointError;
	//레벨이 부족하다는 오류 불값
	bool _lvError;
	//스킬 다찍으면 발생하는 오류 불값
	bool _masterError;
	//스킬 배울지 말지
	bool _skillLearn;
	bool _skillLearnConfirm;

	int _skillPoint;
	int _lv;
public:
	guildScene();
	~guildScene();

	HRESULT init();
	void update();
	void render();
	void release();

	//현재창이 길드
	void guild();
	//현재창이 스킬트리선택
	void skillChoice();
	//현재창이 소서리스 스킬트리
	void sorceressSkill();
	//현재창이 공용 스킬트리
	void commonSkill();
	//소서리스 스킬 초기화
	void sorceressSkillInit();
	//공용 스킬 초기화
	void commonSkillInit();
	//스킬 배우기 함수
	void confirm();
	//에러 창
	void error();
	
	void guildRender();
	void skillChooseRender();
	void sorceressSkillRender();
	void commonSkillRender();
	void confirmRender();
	void errorRender();

public :
	tagSkill* getSorceressSkill(){ return _sorceressSkill; }
	tagSkill* getCommonSkill(){ return _commonSkill; }

	void dataSave();
};

