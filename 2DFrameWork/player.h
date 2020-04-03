#pragma once
#include "gameNode.h"
#include "directionMove.h"
#include "jump.h"
#include "item.h"


#define PLAYER_SPEEDX 7
#define PLAYER_SPEEDY 3
#define PLAYER_RUNSPEEDX 10
#define PLAYER_RAVITATIONX 25
#define PLAYER_TELEPORTX 500

//Ŀ�ǵ� ����Ű
#define NONE					0
#define LEFT					1		// ����
#define RIGHT					2		// ������
#define UP						4		// ����
#define DOWN					8		// �Ʒ���
#define COMMAND_NORMAL_A		16		// A��ư
#define COMMAND_CHARGE_A		32		// CHARGE A��ư
#define COMMAND_NORMAL_S		64		// S��ư
#define COMMAND_CHARGE_S		128		// CHARGE S��ư
#define COMMAND_Z				256		// Z��ư
#define COMMAND_X				512		// X��ư
#define COMMAND_Q				1024	// Q��ư
#define COMMAND_W				2048	// W��ư
#define COMMAND_SHIFT			4096	// shift��ư
#define COMMAND_E				8192	// E��ư


//Ŀ�ǵ� �Է� ����
#define NUM_HISTORY 50
#define NUM_COMMAND 20

//������ �����Ë� ����Ǵ� �ִϸ��̼� Y��ǥ ����
#define DOWN_ANIMATION		285

#define CHARGE_TIME			10		//������� �ð�
#define JUMPPOWER			25		//�����Ŀ�
#define JUMPGRAVITY			1		//�߷�
#define RAVITATION_LIMIT	30		//���߿� ���� �ð� ����Ʈ
#define SHADOW_OFFX			4		//�׸��� ������
#define JUMP_ATTACK_LIMIT	20		//���� ���� �ð� ����Ʈ
#define ABILITY_TIME		25		//ȸ�� ����Ʈ
#define INVINCIBLE_TIME		70		//�����ð�
#define BAG_SHOW			100		//���� ���� �������� �����ߴ��� �����ִ� �ð�
//�÷��̾� ����
enum PLAYER_STATE{
	PLAYER_STAND,							//�÷��̾� ���ֱ�
	PLAYER_WALK,							//�÷��̾� �ȱ�
	PLAYER_TURN,							//�÷��̾� ����
	PLAYER_RUN,								//�÷��̾� �޸���
	PLAYER_JUMP,							//�÷��̾� ���ڸ� ����
	PLAYER_JUMP_RIGHT,						//�÷��̾� ������ ����
	PLAYER_JUMP_LEFT,						//�÷��̾� ���� ����
	PLAYER_JUMP_UP,							//�÷��̾� ���� ����
	PLAYER_JUMP_DOWN,						//�÷��̾� �Ʒ��� ����
	PLAYER_JUMP_RIGHT_UP,					//�÷��̾� �������� ����
	PLAYER_JUMP_LEFT_UP,					//�÷��̾� ������ ����
	PLAYER_JUMP_RIGHT_DOWN,					//�÷��̾� �����ʾƷ� ����
	PLAYER_JUMP_LEFT_DOWN,					//�÷��̾� ���ʾƷ� ����
	PLAYER_RAVITATION,						//�÷��̾� ����
	PLAYER_RAVITATION_DOWN,					//�÷��̾� ��������
	PLAYER_SLIDING, 						//�÷��̾� �����̵�
	PLAYER_NORMAL_ATTACK,					//�÷��̾� �Ϲݰ���
	PLAYER_NORMAL_JUMP_ATTACK,				//�÷��̾� ���� ����
	PLAYER_NORMAL_JUMP_CHARGE_ATTACK,		//�÷��̾� ���� ��������
	PLAYER_NORMAL_CHARGE,					//�÷��̾� �������
	PLAYER_NORMAL_CHARGING,					//�÷��̾� �������
	PLAYER_NORMAL_CHARGED,					//�÷��̾� �������
	PLAYER_SPECIAL_ATTACK,					//�÷��̾� Ư������1
	PLAYER_SPECIAL_ATTACK2,					//�÷��̾� Ư������2
	PLAYER_SPECIAL_ATTACK3,					//�÷��̾� Ư������3
	PLAYER_SPECIAL_CHARGE_ATTACK,			//�÷��̾� Ư����������
	PLAYER_SPECIAL_JUMP_ATTACK,
	PLAYER_SPECIAL_JUMP_CHARGE_ATTACK,		//�÷��̾� ���� ��������
	PLAYER_ABILITY_START,					//�÷��̾� ȸ�� ����ġ
	PLAYER_ABILITY,							//�÷��̾� ȸ��
	PLAYER_TELEPORT_START,					//�÷��̾� �ڷ���Ʈ
	PLAYER_TELEPORT_END,
	PLAYER_POTION,							//�÷��̾� ����
	PLAYER_BAG_USE,							//�÷��̾� ��ų
	PLAYER_DAMAGE,
	PLAYER_DEAD,							//�÷��̾� ����
	PLAYER_FOOD_EAT							//�÷��̾� ���ĸԱ�
};


//�÷��̾� ����
enum PLAYER_DIRECTION{
	LEFT_DIRECTION, RIGHT_DIRECTION
};

//�÷��̾� ����
static PLAYER_STATE _state;
static PLAYER_DIRECTION _direction;

//�ݹ��Լ� ���� ����
static bool _teleport;
class player : public gameNode
{
private:
private:
	float _playerX, _playerY;	//�÷��̾� ��ǥ
	float _shadowX, _shadowY;	//�׸��� ��ǥ
	float _shadowWidth, _shadowHeight;
	float _shadowOffX;
	RECT _rcPlayer;				//�÷��̾� ��Ʈ
	RECT _rcShadow;				//�׸��� ��Ʈ

	int _input;					//����Ű �Է�

	int _chargeTimeA;			//A��ư ������� �ð�
	int _chargeTimeS;			//S��ư ������� �ð�
	bool _isChargeA;			//A��ư ��������� Ȯ��
	bool _isChargeS;			//S��ư ��������� Ȯ��
	bool _isKeyUpA;				//A��ư Ű��
	bool _isKeyUpS;				//S��ư Ű��
	bool _isRunningJump;


	jump* _jump;				//����
	float _jumpStartY;			//���� ������

	int _ravitationTime;		//�ϴ� ���� �ð�
	bool _isRavitation;			//�ϴ��� �����ִ����� �Ұ�

	int _jumpAttackTime;		//���� �����ϴ� �ð�
	bool _isJumpAttack;			//���� �ð� Ÿ�̸� �Ұ�

	int _abilityTime;			//ȸ�� �ð�
	bool _isAbility;			//ȸ�� �ð� Ÿ�̸� �Ұ�
	int _abilityCount;			//�ѹ��� ȸ���Ҽ� �ִ� Ƚ��
	int _abilityMaxCount;		//���� �ѹ��� ȸ���Ҽ� �ִ� Ƚ��

	bool _isInvincible;			//�����ð�
	int _invincibleTime;

	int _damageAlpha;			//������ ���İ�
	int _teleportAlpha;			//�ڷ���Ʈ ���İ�

	//���� ������ Ű���� Ȯ�� �Ұ�
	bool _leftButton;
	bool _rightButton;
	bool _upButton;
	bool _downButton;

	float _speedRate;//�÷��̾� �ӵ� ����
	bool _playerWalk;		//�÷��̾� �ȱ�
	bool _playerRun;		//�÷��̾� �޸�
	bool _playerRavitation;	//�÷��̾� ���ڷ� Ÿ��
	bool _playerRightJump;
	bool _playerLeftJump;
	bool _playerFoodEat;
	bool _pixelCollision;
	
	bool _isSoundPlay;
	bool _isTeleport1;
private:
	//��ų �Ұ���
	bool _isFireball1;
	bool _isFireball2;
	bool _isFireball3;
	bool _isFireball4;
	bool _isFireball5;
	bool _isFireball6;
	bool _isManaball1;
	bool _isManaball2;
	bool _isRockPress;
	bool _isIcePrision;
	bool _isProtection;
	bool _isGravity;
	bool _isThunderCloud;
	bool _isBlizzard;
	bool _isCreateFood;
	bool _isCuss;
	bool _isPetrification;
private:
	int _hp;					//���� hp
	int _hpCurrent;				//hp�� �￩�� �������� �Ծ��ٴ°� �����ִ� ����
	int _hpMax;					//�ִ� hp
	int _mp;
	int _mpMax;
	int _lv;
	int _exp;
	int _str;
	int _int;
	int _con;
	int _mgr;
	int _dex;
	int _luc;
	int _atk;
	int _def;
	float _critical;
	int _skillPoint;

	int _foodCount;				//�������ִ� ���� ����
	int _playerExp[100];
	int _damage;

	int _evadeCount;
private:
	//���� ���õ� ���
	item* _item;
	tagItem _bag[8];
	tagItem _emptyBag;
	int _currentEquip;
	int _bagTimer;
	bool _bagShow;
public:
	player();
	~player();

	HRESULT init();
	void update();
	void render();
	void release();
	
	//�÷��̾�
	void playerInit();
	void playerUpdate();
	void playerRender();
	void playerRelease();

	void keyInput();
	void inputAction();

	//�Ҽ����� �ִϸ��̼� all_stop;
	void sorceressAllStop();

	static void cbStand();
	static void cbCharge();
	static void cbCharging();
	static void cbTeleportStart();
	static void cbTeleportEnd();
	static void cbDead();
	void bagInit();

	//������ ����
	void damaged(int damage);

	void levelUp();
public:
	//���ͼ��� ����

	//���� ����ġ
	void setExp(int exp){ _exp = exp; }
	int getExp(){ return _exp; }
	//�÷��̾� ������ ����ġ
	int* getLevelExp(){ return _playerExp; }
	//�÷��̾��
	int getLv(){ return _lv; }
	void setLv(int lv){ _lv = lv; }
	//�÷��̾�hp
	int getHp(){ return _hp; }
	void setHp(int hp){ _hp = hp; }
	//�÷��̾� ���� hp
	int getHpCurrent(){ return _hpCurrent; }
	void setHpCurrent(int hpCurrent){ _hpCurrent = hpCurrent; }
	//�÷��̾� �ִ� hp
	int getHpMax(){ return _hpMax; }
	void setHpMax(int hpMax){ _hpMax = hpMax; }
	//�÷��̾� mp
	int getMp(){ return _mp; }
	void setMp(int mp){ _mp = mp; }
	//�÷��̾� �ִ� mp
	int getMpMax(){ return _mpMax; }
	void setMpMax(int mpMax){ _mpMax = mpMax; }
	//�÷��̾� ����
	int getStr(){ return _str; }
	void setStr(int str){ _str = str; }
	int getCon(){ return _con; }
	void setCon(int con){ _con = con; }
	int getDex() { return _dex; }
	void setDex(int dex){ _dex = dex; }
	int getInt(){ return _int; }
	void setInt(int intelligent){ _int = intelligent; }
	int getMgr(){ return _mgr; }
	void setMgr(int mgr){ _mgr = mgr; }
	int getLuc(){ return _luc; }
	void setLuc(int luc){ _luc = luc; }
	int getAtk(){ return _atk; }
	void setAtk(int atk){ _atk = atk; }
	int getDef(){ return _def; }
	void setDef(int def){ _def = def; }
	int getSkillPoint(){ return _skillPoint; }
	void setSkillPoint(int skillPoint){ _skillPoint = skillPoint; }

	//�÷��̾� ��ǥ
	float getPlayerX(){ return _playerX; }
	void setPlayerX(float x){ _playerX = x; }
	float getPlayerY(){ return _playerY; }
	void setPlayerY(float y){ _playerY = y; }
	//�׸��� ��ǥ
	float getShadowX(){ return _shadowX; }
	void setShadowX(float x){ _shadowX = x; }
	float getShadowY(){ return _shadowY; }
	void setShadowY(float y){ _shadowY = y; }
	//�÷��̾� Rect
	RECT getRcPlayer(){ return _rcPlayer; }
	void setRcPlayer(RECT rc){ _rcPlayer = rc; }
	//�׸��� Rect
	RECT getRcShadow(){ return _rcShadow; }
	void setRcShadow(RECT rc){ _rcShadow = rc; }

	//�¿� ��ư Ȯ��
	bool getLeftButton(){ return _leftButton; }
	bool getRightButton(){ return _rightButton; }
	bool getUpButton(){ return _upButton; }
	bool getDownButton(){ return _downButton; }
	//�÷��̾�ӵ� ������
	float getSpeedRate(){ return _speedRate; }
	void setSpeedRate(float speedRate){ _speedRate = speedRate; }

	//�÷��̾� �޸����� ������
	bool getIsRun(){ return _playerRun; }
	bool getIsRavitation(){ return _playerRavitation; }
	bool getIsWalk(){ return _playerWalk; }

	bool getIsFoodEat(){ return _playerFoodEat; }
	void setIsFoddEat(bool playerFoodEat){ _playerFoodEat = playerFoodEat; }

	//Rect��
	RECT getShadowRect(){ return _rcShadow; }
	RECT getPlayerRecT(){ return _rcPlayer; }

	bool getPixelCollision(){ return _pixelCollision; }
	void setPixelCollision(bool pixelCollision){ _pixelCollision = pixelCollision; }

	bool getIsRight();
	bool getIsLeft();

	//��ų
	bool getIsFireball1(){ return _isFireball1; }
	void setIsFireball1(bool isFireball1){ _isFireball1 = isFireball1; }

	bool getIsFireball2(){ return _isFireball2; }
	void setIsFireball2(bool isFireball2){ _isFireball2 = isFireball2; }

	bool getIsFireball3(){ return _isFireball3; }
	void setIsFireball3(bool isFireball3){ _isFireball3 = isFireball3; }

	bool getIsFireball4(){ return _isFireball4; }
	void setIsFireball4(bool isFireball4){ _isFireball4 = isFireball4; }

	bool getIsFireball5(){ return _isFireball5; }
	void setIsFireball5(bool isFireball5){ _isFireball5 = isFireball5; }

	bool getIsFireball6(){ return _isFireball6; }
	void setIsFireball6(bool isFireball6){ _isFireball6 = isFireball6; }

	bool getIsManaball1(){ return _isManaball1; }
	void setIsManaball1(bool isManaball1){ _isManaball1 = isManaball1; }

	bool getIsManaball2(){ return _isManaball2; }
	void setIsManaball2(bool isManaball2){ _isManaball2 = isManaball2; }

	bool getIsRockPress(){ return _isRockPress; }
	void setIsRockPress(bool isRockPress){ _isRockPress = isRockPress; }

	bool getIsIcePrision(){ return _isIcePrision; }
	void setIsIcePrision(bool isIcePrision){ _isIcePrision = isIcePrision; }

	bool getIsGravity(){ return _isGravity; }
	void setIsGravity(bool isGravity){ _isGravity = isGravity; }

	bool getIsThunderCloud(){ return _isThunderCloud; }
	void setIsThunderCloud(bool isThunderCloud){ _isThunderCloud = isThunderCloud; }

	bool getIsBlizzard(){ return _isBlizzard; }
	void setIsBlizzard(bool isBlizzard){ _isBlizzard = isBlizzard; }

	bool getIsCreateFood(){ return _isCreateFood; }
	void setIsCreateFood(bool isCreateFood){ _isCreateFood = isCreateFood; }

	bool getIsCuss(){ return _isCuss; }
	void setIsCuss(bool isCuss){ _isCuss = isCuss; }

	bool getIsProtection(){ return _isProtection; }
	void setIsProtection(bool isProtection){ _isProtection = isProtection; }

	bool getIsPtetrification(){ return _isPetrification; }
	void setIsPtetrification(bool isPetrification){ _isPetrification = isPetrification; }
	//���İ���
	int getFoodCount(){ return _foodCount; }
	void setFoodCount(int foodCount){ _foodCount = foodCount; }

	bool getIsInvincible(){ return _isInvincible; }

	int getDamage(){ return _damage; }

	bool getIsTeleport(){ return _isTeleport1; }
};

