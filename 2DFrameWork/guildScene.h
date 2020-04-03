#pragma once
#include "gameNode.h"
#include "animation.h"

#define SKILLMOVEX 10


//��ų ���� �ݴ� �ִϸ��̼� ������ �ݹ�ó����
static bool _bSkillListMoveOpen;
static bool _bSkillListMoveClose;

static int _sorceressSkillChoice;
static int _skillMoveX;
static int _skillMoveXMax;
static int _commonSkillChoice;

//��� ȭ��, ��ų ����ȭ��, �Ҽ����� ��ų, ���� ��ų,�Ҽ����� ��ų Ȯ��â, ���� ��ų Ȯ��â,
// �Ҽ����� ��ų ����Ʈ ���� â, �Ҽ����� ���� ����â, �Ҽ����� ��ų ������ ����â
// ���� ��ų ����Ʈ ����â, ���� ���� ����â, ���� ��ų ������ ����â
enum GUILD_STATE{ GUILD, SKILL_CHOICE, SORCERESS_SKILL, COMMON_SKILL, SORCERESS_CONFIRM, COMMON_CONFIRM ,
	SORCERESS_SKILL_POINT_ERROR, SORCERESS_LV_ERROR, SORCERESS_SKILL_MASTER_ERROR,
	COMMON_SKILL_POINT_ERROR, COMMON_LV_ERROR, COMMON_SKILL_MASTER_ERROR
};
static GUILD_STATE _guildState;

class guildScene : public gameNode
{
	//������� ��ų�� ��������
	//1.�Ҽ����� ��ų
	//2.�Ϲ� ��ų
	enum SKILL_CHOICE_STATE{ SORCERESS, COMMON };

	//�Ҽ����� ��ų ���
	enum SORCERESS_SKILL_LIST{
		MENTAL_ABSORB,	//��Ż �ۼҺ� : ���� ����Ʈ������ MP�� ȸ��
		EXTRACT,		//����Ʈ��Ʈ  : ���� ���� MP ȸ������ ����
		CONCENTRATE,	//�ܼ�Ʈ����Ʈ : MP ���� �ӵ��� ���
		MAGIC_POINT_UP, //���� ����Ʈ �� : MP �ִ�ġ�� ����
		ICE_PRISION,	//���̽� ������ : ���� ���δ� ������ �߻�
		PROTECTION,		//�����ؼ� : �Ʊ����� ������ ���и� �ο�
		GRAVITY,		//�׷���Ƽ : ���� ���Ƶ��̴� �߷����� �߻�
		THUNDER_CLOUD,	//��� Ŭ���� : ������ ����Ʈ���� ������ �߻�
		ROCK_PRESS,		//�� ������ : ���� ȿ���� �ִ� �ϼ��� ����Ʈ��
		BLIZZARD,		//���ڵ� : ���� �󸮴� ������ �ҷ�����Ŵ
		ANIMATE_SKELTON, //�ִϸ���Ʈ ������ : �������� ����
		RAVITATION,		//�������̼� : ��������� �Ҽ�����
		CREATE_FOOD,	//ũ������Ʈ Ǫ�� : ������ ������ �����.
		CURSE,			//Ŀ�� : ���� ������ ���·� ����
		PETRIFICATION,  //��Ʈ�������̼� : ���� ��ȭ���·� ����
	};

	
	//���뽺ų���
	enum COMMAN_SKILL_LIST{
		SLIDING,		// �����̵� : �����̵� ��ȭ
		GOLD_HEALING,	// ��� ���� : ���� ȹ�� �ÿ� HPȸ��
		GOLD_SCORING,	// ��� ���ھ : ���� ȹ�� �ÿ� ���ھ� ȹ��
		HIT_POINT_UP,	// ��Ʈ ����Ʈ �� : HP �ִ�ġ�� ����
		FOOD_PSYTOLOGY, //Ǫ�� ��������� : ���� ȸ���� ����
		MAINTENANCE,	//�����׳ͽ� : ���� ��� Ƚ���� �� �������� ����
		ITEM_USER,		//������ ���� : ������ ����ð� ����
		EVADE,			//�̺��̵� : �������� ȸ��
		EXTRA_POCKET,	//������ ������ ������ Ȯ��
	};

	//���� ������ �޴�
	enum MENUSTATE{ SKILL, GUILDEXIT };

	//��ų ����ü
	struct tagSkill{
		string name;						//��ų �̸�
		int LVCondition[10];				//��������
		int sKillPointCondition[10];		//�ʿ佺ų����Ʈ����
		int skillLV;						//���� ��ų����
		int skillLVMax;						//�ƽ� ��ų����
		string skillInfo;					//��ų����
	};

private:

	
	

	//���޴�����
	int _menuChoice;
	MENUSTATE _menuState;

	//�Ҽ����� �Ǵ� ���뽺ų ����
	int _skillListChoice;
	SKILL_CHOICE_STATE _skillChioceState;

	//�Ҽ����� ��ų ����
	SORCERESS_SKILL_LIST _sorceressSkillList;

	//���� ��ų ����
	COMMAN_SKILL_LIST _commonSkillList;

	//�Ҽ����� ��ų ���
	tagSkill _sorceressSkill[13];
	//���� ��ų���
	tagSkill _commonSkill[4];

	//��ų����Ʈ����������
	//�Ҽ�����
	int _skillListX1;
	int _skillListX2;

	//����
	int _commonSkillListX1;
	int _commonSkillListX2;
	static void skillMoveOpen(void* obj);
	static void skillMoveClose(void* obj);

	//��ų������ ����
	bool _bSkillLeftMove;
	bool _bSkillRightMove;
	
	
	//��ų����Ʈ�� �����ϴٴ� ���� �Ұ�
	bool _pointError;
	//������ �����ϴٴ� ���� �Ұ�
	bool _lvError;
	//��ų �������� �߻��ϴ� ���� �Ұ�
	bool _masterError;
	//��ų ����� ����
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

	//����â�� ���
	void guild();
	//����â�� ��ųƮ������
	void skillChoice();
	//����â�� �Ҽ����� ��ųƮ��
	void sorceressSkill();
	//����â�� ���� ��ųƮ��
	void commonSkill();
	//�Ҽ����� ��ų �ʱ�ȭ
	void sorceressSkillInit();
	//���� ��ų �ʱ�ȭ
	void commonSkillInit();
	//��ų ���� �Լ�
	void confirm();
	//���� â
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

