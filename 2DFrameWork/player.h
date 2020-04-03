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

//커맨드 조작키
#define NONE					0
#define LEFT					1		// 왼쪽
#define RIGHT					2		// 오른쪽
#define UP						4		// 위쪽
#define DOWN					8		// 아래쪽
#define COMMAND_NORMAL_A		16		// A버튼
#define COMMAND_CHARGE_A		32		// CHARGE A버튼
#define COMMAND_NORMAL_S		64		// S버튼
#define COMMAND_CHARGE_S		128		// CHARGE S버튼
#define COMMAND_Z				256		// Z버튼
#define COMMAND_X				512		// X버튼
#define COMMAND_Q				1024	// Q버튼
#define COMMAND_W				2048	// W버튼
#define COMMAND_SHIFT			4096	// shift버튼
#define COMMAND_E				8192	// E버튼


//커맨드 입력 개수
#define NUM_HISTORY 50
#define NUM_COMMAND 20

//땅으로 내려올떄 실행되는 애니메이션 Y좌표 기준
#define DOWN_ANIMATION		285

#define CHARGE_TIME			10		//기모으는 시간
#define JUMPPOWER			25		//점프파워
#define JUMPGRAVITY			1		//중력
#define RAVITATION_LIMIT	30		//공중에 나는 시간 리미트
#define SHADOW_OFFX			4		//그림자 오프셋
#define JUMP_ATTACK_LIMIT	20		//점프 공격 시간 리미트
#define ABILITY_TIME		25		//회피 리미트
#define INVINCIBLE_TIME		70		//무적시간
#define BAG_SHOW			100		//현재 무슨 아이템을 장착했는지 보여주는 시간
//플레이어 상태
enum PLAYER_STATE{
	PLAYER_STAND,							//플레이어 서있기
	PLAYER_WALK,							//플레이어 걷기
	PLAYER_TURN,							//플레이어 돌기
	PLAYER_RUN,								//플레이어 달리기
	PLAYER_JUMP,							//플레이어 제자리 점프
	PLAYER_JUMP_RIGHT,						//플레이어 오른쪽 점프
	PLAYER_JUMP_LEFT,						//플레이어 왼쪽 점프
	PLAYER_JUMP_UP,							//플레이어 위로 점프
	PLAYER_JUMP_DOWN,						//플레이어 아래로 점프
	PLAYER_JUMP_RIGHT_UP,					//플레이어 오른쪽위 점프
	PLAYER_JUMP_LEFT_UP,					//플레이어 왼쪽위 점프
	PLAYER_JUMP_RIGHT_DOWN,					//플레이어 오른쪽아래 점프
	PLAYER_JUMP_LEFT_DOWN,					//플레이어 왼쪽아래 점프
	PLAYER_RAVITATION,						//플레이어 날기
	PLAYER_RAVITATION_DOWN,					//플레이어 내려가기
	PLAYER_SLIDING, 						//플레이어 슬라이딩
	PLAYER_NORMAL_ATTACK,					//플레이어 일반공격
	PLAYER_NORMAL_JUMP_ATTACK,				//플레이어 점프 어택
	PLAYER_NORMAL_JUMP_CHARGE_ATTACK,		//플레이어 점프 차지공격
	PLAYER_NORMAL_CHARGE,					//플레이어 기모으기
	PLAYER_NORMAL_CHARGING,					//플레이어 기모으기
	PLAYER_NORMAL_CHARGED,					//플레이어 기모으기
	PLAYER_SPECIAL_ATTACK,					//플레이어 특수공격1
	PLAYER_SPECIAL_ATTACK2,					//플레이어 특수공격2
	PLAYER_SPECIAL_ATTACK3,					//플레이어 특수공격3
	PLAYER_SPECIAL_CHARGE_ATTACK,			//플레이어 특수차지공격
	PLAYER_SPECIAL_JUMP_ATTACK,
	PLAYER_SPECIAL_JUMP_CHARGE_ATTACK,		//플레이어 점프 차지공격
	PLAYER_ABILITY_START,					//플레이어 회피 스위치
	PLAYER_ABILITY,							//플레이어 회피
	PLAYER_TELEPORT_START,					//플레이어 텔레포트
	PLAYER_TELEPORT_END,
	PLAYER_POTION,							//플레이어 포션
	PLAYER_BAG_USE,							//플레이어 스킬
	PLAYER_DAMAGE,
	PLAYER_DEAD,							//플레이어 죽음
	PLAYER_FOOD_EAT							//플레이어 음식먹기
};


//플레이어 방향
enum PLAYER_DIRECTION{
	LEFT_DIRECTION, RIGHT_DIRECTION
};

//플레이어 상태
static PLAYER_STATE _state;
static PLAYER_DIRECTION _direction;

//콜백함수 전용 변수
static bool _teleport;
class player : public gameNode
{
private:
private:
	float _playerX, _playerY;	//플레이어 좌표
	float _shadowX, _shadowY;	//그림자 좌표
	float _shadowWidth, _shadowHeight;
	float _shadowOffX;
	RECT _rcPlayer;				//플레이어 렉트
	RECT _rcShadow;				//그림자 렉트

	int _input;					//조작키 입력

	int _chargeTimeA;			//A버튼 기모으는 시간
	int _chargeTimeS;			//S버튼 기모으는 시간
	bool _isChargeA;			//A버튼 기모으는지 확인
	bool _isChargeS;			//S버튼 기모으는지 확인
	bool _isKeyUpA;				//A버튼 키업
	bool _isKeyUpS;				//S버튼 키업
	bool _isRunningJump;


	jump* _jump;				//점프
	float _jumpStartY;			//점프 시작점

	int _ravitationTime;		//하늘 나는 시간
	bool _isRavitation;			//하늘을 날고있는지의 불값

	int _jumpAttackTime;		//점프 공격하는 시간
	bool _isJumpAttack;			//공격 시간 타이머 불값

	int _abilityTime;			//회피 시간
	bool _isAbility;			//회피 시간 타이머 불값
	int _abilityCount;			//한번에 회피할수 있는 횟수
	int _abilityMaxCount;		//현재 한번에 회피할수 있는 횟수

	bool _isInvincible;			//무적시간
	int _invincibleTime;

	int _damageAlpha;			//데미지 알파값
	int _teleportAlpha;			//텔레포트 알파값

	//왼쪽 오른쪽 키보드 확인 불값
	bool _leftButton;
	bool _rightButton;
	bool _upButton;
	bool _downButton;

	float _speedRate;//플레이어 속도 조절
	bool _playerWalk;		//플레이어 걷기
	bool _playerRun;		//플레이어 달림
	bool _playerRavitation;	//플레이어 빗자루 타기
	bool _playerRightJump;
	bool _playerLeftJump;
	bool _playerFoodEat;
	bool _pixelCollision;
	
	bool _isSoundPlay;
	bool _isTeleport1;
private:
	//스킬 불값들
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
	int _hp;					//현재 hp
	int _hpCurrent;				//hp가 깍여서 데미지를 입었다는걸 보여주는 변수
	int _hpMax;					//최대 hp
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

	int _foodCount;				//가지고있는 음식 개수
	int _playerExp[100];
	int _damage;

	int _evadeCount;
private:
	//현재 선택된 장비
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
	
	//플레이어
	void playerInit();
	void playerUpdate();
	void playerRender();
	void playerRelease();

	void keyInput();
	void inputAction();

	//소서리스 애니메이션 all_stop;
	void sorceressAllStop();

	static void cbStand();
	static void cbCharge();
	static void cbCharging();
	static void cbTeleportStart();
	static void cbTeleportEnd();
	static void cbDead();
	void bagInit();

	//데미지 입음
	void damaged(int damage);

	void levelUp();
public:
	//게터세터 모음

	//현재 경험치
	void setExp(int exp){ _exp = exp; }
	int getExp(){ return _exp; }
	//플레이어 레벨업 경험치
	int* getLevelExp(){ return _playerExp; }
	//플레이어레벨
	int getLv(){ return _lv; }
	void setLv(int lv){ _lv = lv; }
	//플레이어hp
	int getHp(){ return _hp; }
	void setHp(int hp){ _hp = hp; }
	//플레이어 현재 hp
	int getHpCurrent(){ return _hpCurrent; }
	void setHpCurrent(int hpCurrent){ _hpCurrent = hpCurrent; }
	//플레이어 최대 hp
	int getHpMax(){ return _hpMax; }
	void setHpMax(int hpMax){ _hpMax = hpMax; }
	//플레이어 mp
	int getMp(){ return _mp; }
	void setMp(int mp){ _mp = mp; }
	//플레이어 최대 mp
	int getMpMax(){ return _mpMax; }
	void setMpMax(int mpMax){ _mpMax = mpMax; }
	//플레이어 스탯
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

	//플레이어 좌표
	float getPlayerX(){ return _playerX; }
	void setPlayerX(float x){ _playerX = x; }
	float getPlayerY(){ return _playerY; }
	void setPlayerY(float y){ _playerY = y; }
	//그림자 좌표
	float getShadowX(){ return _shadowX; }
	void setShadowX(float x){ _shadowX = x; }
	float getShadowY(){ return _shadowY; }
	void setShadowY(float y){ _shadowY = y; }
	//플레이어 Rect
	RECT getRcPlayer(){ return _rcPlayer; }
	void setRcPlayer(RECT rc){ _rcPlayer = rc; }
	//그림자 Rect
	RECT getRcShadow(){ return _rcShadow; }
	void setRcShadow(RECT rc){ _rcShadow = rc; }

	//좌우 버튼 확인
	bool getLeftButton(){ return _leftButton; }
	bool getRightButton(){ return _rightButton; }
	bool getUpButton(){ return _upButton; }
	bool getDownButton(){ return _downButton; }
	//플레이어속도 조절용
	float getSpeedRate(){ return _speedRate; }
	void setSpeedRate(float speedRate){ _speedRate = speedRate; }

	//플레이어 달리는지 나는지
	bool getIsRun(){ return _playerRun; }
	bool getIsRavitation(){ return _playerRavitation; }
	bool getIsWalk(){ return _playerWalk; }

	bool getIsFoodEat(){ return _playerFoodEat; }
	void setIsFoddEat(bool playerFoodEat){ _playerFoodEat = playerFoodEat; }

	//Rect값
	RECT getShadowRect(){ return _rcShadow; }
	RECT getPlayerRecT(){ return _rcPlayer; }

	bool getPixelCollision(){ return _pixelCollision; }
	void setPixelCollision(bool pixelCollision){ _pixelCollision = pixelCollision; }

	bool getIsRight();
	bool getIsLeft();

	//스킬
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
	//음식개수
	int getFoodCount(){ return _foodCount; }
	void setFoodCount(int foodCount){ _foodCount = foodCount; }

	bool getIsInvincible(){ return _isInvincible; }

	int getDamage(){ return _damage; }

	bool getIsTeleport(){ return _isTeleport1; }
};

