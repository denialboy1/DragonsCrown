#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init(){
	playerInit();
	_rcPlayer = RectMake(0, 0, 0, 0);
	setRect(_rcShadow);
	setShow(true);
	return S_OK;
}
void player::update(){
	playerUpdate();

	//zOrder용
	//setRect(_rcPlayer);
	levelUp();
	setRect(_rcShadow);
}
void player::render(){
	playerRender();

}
void player::release(){
	playerRelease();
}

void player::playerInit(){
	
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_stand", "이미지/소서리스/sorceress_stand.bmp", 2233, 912, 7, 2, true, RGB(255, 0, 255));							//서있는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_walk", "이미지/소서리스/sorceress_walk.bmp", 4080, 950, 12, 2, true, RGB(255, 0, 255));							//걷는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_run", "이미지/소서리스/sorceress_run.bmp", 3740, 950, 11, 2, true, RGB(255, 0, 255));								//달리는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_turn", "이미지/소서리스/sorceress_turn.bmp", 680, 950, 2, 2, true, RGB(255, 0, 255));								//턴하는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_jump", "이미지/소서리스/sorceress_jump.bmp", 3700, 950, 10, 2, true, RGB(255, 0, 255));							//서있는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_ravitation", "이미지/소서리스/sorceress_ravitation.bmp", 2800, 950, 7, 2, true, RGB(255, 0, 255));					//비행하는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_attack1", "이미지/소서리스/sorceress_attack1.bmp", 3500, 1100, 7, 2, true, RGB(255, 0, 255));						//공격하는 이미지1
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_attack2", "이미지/소서리스/sorceress_attack2.bmp", 3000, 1100, 6, 2, true, RGB(255, 0, 255));						//공격하는 이미지2
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_attack3", "이미지/소서리스/sorceress_attack3.bmp", 5500, 1100, 11, 2, true, RGB(255, 0, 255));						//공격하는 이미지3
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_attack4", "이미지/소서리스/sorceress_attack4.bmp", 3500, 1100, 7, 2, true, RGB(255, 0, 255));						//공격하는 이미지4
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_jump_attack1", "이미지/소서리스/sorceress_jump_down_attack.bmp", 2900, 1100, 6, 2, true, RGB(255, 0, 255));		//점프 공격하는 이미지1
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_jump_attack2", "이미지/소서리스/sorceress_jump_up_attack.bmp", 3000, 1000, 6, 2, true, RGB(255, 0, 255));			//점프 공격하는 이미지1
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_damage", "이미지/소서리스/sorceress_damage.bmp", 2500, 1100, 5, 2, true, RGB(255, 0, 255));						//공격받는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_down", "이미지/소서리스/sorceress_down.bmp", 8500, 1100, 17, 2, true, RGB(255, 0, 255));							//쓰러지는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_gauge", "이미지/소서리스/sorceress_gauge.bmp", 7500, 950, 15, 2, true, RGB(255, 0, 255));						//기모으는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_ability", "이미지/소서리스/sorceress_ability.bmp", 3000, 1000, 6, 2, true, RGB(255, 0, 255));						//회피하는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_potion", "이미지/소서리스/sorceress_potion.bmp", 6000, 1120, 12, 2, true, RGB(255, 0, 255));						//포션먹는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_skill", "이미지/소서리스/sorceress_skill.bmp", 4000, 1200, 8, 2, true, RGB(255, 0, 255));							//스킬쓰는 이미지
	//IMAGEMANAGER->addAlphaFrameImage("sorceress_food_eat", "이미지/소서리스/사과먹기.bmp", 6500, 1100, 13, 2, true, RGB(255, 0, 255));							//사과먹는 이미지
	//IMAGEMANAGER->addPngImage("shadow", L"이미지/소서리스/shadow.png", 300, 32);
	//IMAGEMANAGER->addAlphaImage("shadow1", "이미지/소서리스/shadow.bmp", 300, 100,true,RGB(255,0,255));
	//IMAGEMANAGER->addAlphaImage("shadow2", "이미지/소서리스/shadow.bmp", 320, 100, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("shadow3", "이미지/소서리스/shadow.bmp", 100, 100, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("마나모으기", "이미지/소서리스/마나모으기.bmp", 400, 100,true,RGB(255,0,255));
	EFFECTMANAGER->addEffect("마나모으기", "이미지/소서리스/마나모으기.bmp", 400, 100, 100, 100, 2,0.1, 1,100);

	int arr1[] = { 0, 1, 2, 3, 4, 5 };																								//RIGHT_STAND ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("이미지/소서리스/sorceress_stand_right", "이미지/소서리스/sorceress_stand", arr1, sizeof(arr1) / sizeof(int), 7, true);
	int arr2[] = {7,8,9,10,11,12};																									//LEFT_STAND ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("이미지/소서리스/sorceress_stand_left", "이미지/소서리스/sorceress_stand", arr2, sizeof(arr2) / sizeof(int), 7, true);
	int arr3[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };																				//RIGHT_WALK ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("이미지/소서리스/sorceress_walk_right", "이미지/소서리스/sorceress_walk", arr3, sizeof(arr3) / sizeof(int), 10, true);
	int arr4[] = { 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };																	//LEFT_WALK ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_walk_left", "sorceress_walk", arr4, sizeof(arr4) / sizeof(int), 10, true);
	int arr5[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };																			//RIGHT_RUN ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_run_right", "sorceress_run", arr5, sizeof(arr5) / sizeof(int), 15, true);
	int arr6[] = { 11, 13, 14, 15, 16, 17, 18, 19, 20, 21 };																	//LEFT_RUN ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_run_left", "sorceress_run", arr6, sizeof(arr6) / sizeof(int), 15, true);
	int arr7[] = {0,1  };																												//RIGHT_TURN ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_turn_right", "sorceress_turn", arr7, sizeof(arr7) / sizeof(int), 20, false, cbStand);
	int arr8[] = { 2,3 };																												//LEFT_TURN ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_turn_left", "sorceress_turn", arr8, sizeof(arr8) / sizeof(int), 20, false, cbStand);
	int arr9[] = { 0, 1,2,3 };																										//RIGHT_JUMP_UP ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_jump_up_right", "sorceress_jump", arr9, sizeof(arr9) / sizeof(int), 10, false);
	int arr10[] = { 10,11,12,13 };																								//LEFT_JUMP_UP ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_jump_up_left", "sorceress_jump", arr10, sizeof(arr10) / sizeof(int), 10, false);
	int arr11[] = { 4,5,6,7,8,9 };																											//RIGHT_JUMP_DOWN ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_jump_down_right", "sorceress_jump", arr11, sizeof(arr11) / sizeof(int), 10, true);
	int arr12[] = { 14,15,16,17,18,19 };																										//LEFT_JUMP_DOWN ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_jump_down_left", "sorceress_jump", arr12, sizeof(arr12) / sizeof(int), 10, true);
	int arr13[] = { 0, 1, 2, 3, 4, 5 };																									//RIGHT_RAVITATION ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_ravitation_right", "sorceress_ravitation", arr13, sizeof(arr13) / sizeof(int), 10, true);
	int arr14[] = { 7,8,9,10,11,12 };																							//LEFT_RAVITATION ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_ravitation_left", "sorceress_ravitation", arr14, sizeof(arr14) / sizeof(int), 10, true);
	int arr43[] = { 6 };																									//RIGHT_RAVITATION ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_ravitation_down_right", "sorceress_ravitation", arr43, sizeof(arr43) / sizeof(int), 10, true);
	int arr44[] = {13 };																							//LEFT_RAVITATION ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_ravitation_down_left", "sorceress_ravitation", arr44, sizeof(arr44) / sizeof(int), 10, true);
	int arr15[] = { 0, 1, 2, 3, 4, 5 ,6};																								//RIGHT_ATTACK1 ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_attack1_right", "sorceress_attack1", arr15, sizeof(arr15) / sizeof(int), 20, false, cbStand);
	int arr16[] = { 7,8,9,10,11,12,13 };																								//LEFT_ATTACK1 ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_attack1_left", "sorceress_attack1", arr16, sizeof(arr16) / sizeof(int), 20, false, cbStand);
	int arr17[] = { 0, 1, 2, 3, 4, 5 };																									//RIGHT_ATTACK2 ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_attack2_right", "sorceress_attack2", arr17, sizeof(arr17) / sizeof(int), 10, false, cbStand);
	int arr18[] = { 6,7,8,9,10,11};																										//LEFT_ATTACK2 ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_attack2_left", "sorceress_attack2", arr18, sizeof(arr18) / sizeof(int), 10, false, cbStand);
	int arr19[] = { 0, 1, 2, 3, 4, 5, 6,7,8,9,10 };																						//RIGHT_ATTACK3 ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_attack3_right", "sorceress_attack3", arr19, sizeof(arr19) / sizeof(int), 15, false, cbStand);
	int arr20[] = { 11,12,13,14,15,16,17,18,19,20 };																					//LEFT_ATTACK3 ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_attack3_left", "sorceress_attack3", arr20, sizeof(arr20) / sizeof(int), 15, false, cbStand);
	int arr21[] = { 0, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 4, 5,6 };																								//RIGHT_ATTACK4 ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_attack4_right", "sorceress_attack4", arr21, sizeof(arr21) / sizeof(int), 10, false, cbStand);
	int arr22[] = { 7, 8, 9, 10, 11, 12, 8, 9, 10, 11, 12, 8, 9, 10, 11, 12, 8, 9, 10, 11, 12,13 };																							//LEFT_ATTACK4 ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_attack4_left", "sorceress_attack4", arr22, sizeof(arr22) / sizeof(int), 10, false, cbStand);
	int arr23[] = { 0, 1, 2, 3, 4, 5 };																									//JUMP_ATTACK1_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_jump_attack1_right", "sorceress_jump_attack1", arr23, sizeof(arr23) / sizeof(int), 10, false);
	int arr24[] = { 6,7, 8, 9, 10, 11, };																								//JUMP_ATTACK1_LEFT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_jump_attack1_left", "sorceress_jump_attack1", arr24, sizeof(arr24) / sizeof(int), 10, false);
	int arr25[] = { 0, 1, 2, 3, 4, 5 };																									//JUMP_ATTACK2_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_jump_attack2_right", "sorceress_jump_attack2", arr25, sizeof(arr25) / sizeof(int), 10, false);
	int arr26[] = { 6, 7, 8, 9, 10, 11, };																								//JUMP_ATTACK2_LEFT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_jump_attack2_left", "sorceress_jump_attack2", arr26, sizeof(arr26) / sizeof(int), 10, false);
	int arr27[] = { 0, 1, 2, 3, 4};																										//DAMAGE_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_damage_right", "sorceress_damage", arr27, sizeof(arr27) / sizeof(int), 10, false, cbStand);
	int arr28[] = { 5,6, 7, 8, 9,};																										//DAMAGE_LEFT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_damage_left", "sorceress_damage", arr28, sizeof(arr28) / sizeof(int), 10, false,cbStand);
	int arr29[] = { 0, 1, 2, 3, 4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,19,19,19,19,19,19 };																		//DOWN_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_down_right", "sorceress_down", arr29, sizeof(arr29) / sizeof(int), 10, false,cbDead);
	int arr30[] = {20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,39,39,39,39,39,39,39 };																//DOWN_LEFT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_down_left", "sorceress_down", arr30, sizeof(arr30) / sizeof(int), 10, false, cbDead);
	int arr31[] = { 0, 1, 2, 3, 4};																									//CHARGE_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_charge_right", "sorceress_gauge", arr31, sizeof(arr31) / sizeof(int), 15, false, cbCharge);
	int arr32[] = { 5, 6, 7, 8, 9, 10, 11, 12 };																					//CHARGING_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_charging_right", "sorceress_gauge", arr32, sizeof(arr32) / sizeof(int), 10, true, cbCharging);
	int arr33[] = { 13, 14 };																							//CHARGED_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_charged_right", "sorceress_gauge", arr33, sizeof(arr33) / sizeof(int), 10, false, cbStand);
	int arr34[] = { 15, 16, 17, 18,19 };																								//CHARGE_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_charge_left", "sorceress_gauge", arr34, sizeof(arr34) / sizeof(int), 15, false, cbCharge);
	int arr35[] = { 20, 21, 22, 23, 24, 26, 27 };																							//CHARGING_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_charging_left", "sorceress_gauge", arr35, sizeof(arr35) / sizeof(int), 10, true, cbCharging);
	int arr36[] = { 28, 29 };																						//CHARGED_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_charged_left", "sorceress_gauge", arr36, sizeof(arr36) / sizeof(int), 10, false, cbStand);
	int arr37[] = { 0, 1, 2, 3, 4 };																									//ABILITY_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_ability_right", "sorceress_ability", arr37, sizeof(arr37) / sizeof(int), 20, false);
	int arr38[] = { 6,7,8,9,10 };																									//ABILITY_LEFT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_ability_left", "sorceress_ability", arr38, sizeof(arr38) / sizeof(int), 20, false);
	int arr39[] = { 0, 1, 2, 3, 4, 5,6,7,8,9,10,11 };																					//POTION_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_potion_right", "sorceress_potion", arr39, sizeof(arr39) / sizeof(int), 10, false, cbStand);
	int arr40[] = { 12,13,14,15,16,17,18,19,20,21,22,23 };																				//POTION_LEFT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_potion_left", "sorceress_potion", arr40, sizeof(arr40) / sizeof(int), 10, false, cbStand);
	int arr41[] = { 0, 1, 2, 3, 4, 5, 6, 4,5,6,7 };																					//POTION_RIGHT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_skill_right", "sorceress_skill", arr41, sizeof(arr41) / sizeof(int), 10, false, cbStand);
	int arr42[] = { 8, 9, 10, 11, 12, 13, 14, 12, 13, 14, 15 };																				//POTION_LEFT ANI
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_skill_left", "sorceress_skill", arr42, sizeof(arr42) / sizeof(int), 10, false, cbStand);
	int arr47[] = { 0, 1, 2 };
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_teleport_right_start", "sorceress_ability", arr47, sizeof(arr47) / sizeof(int), 10, false, cbTeleportStart);
	int arr48[] = { 3,4,5};
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_teleport_right_end", "sorceress_ability", arr48, sizeof(arr48) / sizeof(int), 10, false, cbTeleportEnd);
	int arr45[] = {6,7,8 };
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_teleport_left_start", "sorceress_ability", arr45, sizeof(arr45) / sizeof(int), 10, false, cbTeleportStart);
	int arr46[] = { 9,10,11 };
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_teleport_left_end", "sorceress_ability", arr46, sizeof(arr46) / sizeof(int), 10, false, cbTeleportEnd);
	int arr49[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_food_eat_right", "sorceress_food_eat", arr49, sizeof(arr49) / sizeof(int), 10, false, cbStand);
	int arr50[] = { 13,14,15,16,17,18,19,20,21,22,23 };
	KEYANIMANAGER->addArrayAlphaFrameAnimation("sorceress_food_eat_left", "sorceress_food_eat", arr50, sizeof(arr50) / sizeof(int), 10, false, cbStand);

	
	KEYANIMANAGER->findAnimation("sorceress_stand_right")->start();
	KEYANIMANAGER->findAnimation("sorceress_stand_right")->isPlay();
	_state = PLAYER_STAND;
	_direction = RIGHT_DIRECTION;

	_playerX = 100;
	_playerY = 300;
	_shadowX = 115;
	_shadowY = 740;
	_input = NONE;
	_chargeTimeA = 0;
	_chargeTimeS = 0;
	_isChargeA = false;
	_isChargeS = false;
	_isKeyUpA = false;
	_isKeyUpS = false;
	_shadowWidth = 300;
	_shadowHeight = 32;
	_shadowOffX = 0;
	_jump = new jump;
	_jump->init();
	_ravitationTime = 0;
	_isRavitation = false;
	_jumpAttackTime = 0;
	_isJumpAttack = false;
	_abilityTime = 0;
	_isAbility = false;
	_isInvincible = false;
	_invincibleTime = 0;
	_jump->setStartY(_playerY);
	_teleport = false;
	_damageAlpha = 0;
	_teleportAlpha = 255;
	_leftButton = false;;
	_rightButton=false;
	_speedRate = 0;
	_foodCount = 0;
	_playerFoodEat = false;
	_damageAlpha = 255;
	//스킬 관련
	_abilityMaxCount = 1;					//회피기
	_abilityCount = _abilityMaxCount;				
	_isSoundPlay = false;

	//플레이어 스텟 초기화
	_lv = INIDATA->loadDataInterger("PlayerData", "State", "LEVEL");
	_exp = INIDATA->loadDataInterger("PlayerData", "State", "EXP");
	_hpMax = _hp = INIDATA->loadDataInterger("PlayerData", "State", "HP") + INIDATA->loadDataInterger("PlayerData","Skill","hit_point_up")*100;
	_mpMax = _mp = INIDATA->loadDataInterger("PlayerData", "State", "MP") + INIDATA->loadDataInterger("PlayerData", "Skill", "magic_point_up") * 50;
	_str = INIDATA->loadDataInterger("PlayerData", "State", "STR");
	_int = INIDATA->loadDataInterger("PlayerData", "State", "INT");
	_con = INIDATA->loadDataInterger("PlayerData", "State", "CON");
	_mgr = INIDATA->loadDataInterger("PlayerData", "State", "MGR");
	_dex = INIDATA->loadDataInterger("PlayerData", "State", "DEX");
	_luc = INIDATA->loadDataInterger("PlayerData", "State", "LUC");
	_skillPoint = INIDATA->loadDataInterger("PlayerData", "Skill", "SKILLPOINT");
	_atk = _str*0.5 + _int * 2;
	if (strcmp(INIDATA->loadDataString("PlayerData", "Bag", "bag1").c_str(), "크라운 스태프") == 0 ||
		strcmp(INIDATA->loadDataString("PlayerData", "Bag", "bag2").c_str(), "크라운 스태프") == 0 || 
		strcmp(INIDATA->loadDataString("PlayerData", "Bag", "bag3").c_str(), "크라운 스태프") == 0 || 
		strcmp(INIDATA->loadDataString("PlayerData", "Bag", "bag4").c_str(), "크라운 스태프") == 0 || 
		strcmp(INIDATA->loadDataString("PlayerData", "Bag", "bag5").c_str(), "크라운 스태프") == 0 ||
		strcmp(INIDATA->loadDataString("PlayerData", "Bag", "bag6").c_str(), "크라운 스태프") == 0 ||
		strcmp(INIDATA->loadDataString("PlayerData", "Bag", "bag7").c_str(), "크라운 스태프") == 0 ||
		strcmp(INIDATA->loadDataString("PlayerData", "Bag", "bag8").c_str(), "크라운 스태프") == 0){
		_atk = 600 + _str*0.5 + _int * 2;
	}
	_def = _con*0.5 + _mgr * 1;
	//플레이어 경험치
	for (int i = 0; i < 100; i++){
		_playerExp[i] = i * 100;
	}

	bagInit();
	_emptyBag.name = "empty";
	_emptyBag.currentCon = 0;
	_emptyBag.frameX = 30;
	_emptyBag.frameY = 0;
	_emptyBag.info = "";
	_emptyBag.LVCondition = 0;
	_emptyBag.maxCon = 0;
	_emptyBag.price = 0;
	strcpy(_emptyBag.rank,"");
	_emptyBag.seal = 0;
	_emptyBag.type = WEAPON;
	_emptyBag.useCount = 0;


	//스킬
	_isFireball1 = false;
	_isFireball2 = false;
	_isFireball3 = false;
	_isFireball4 = false;
	_isFireball5 = false;
	_isFireball6 = false;
	_isManaball1 = false;
	_isManaball2 = false;
	_isRockPress = false;
	_isIcePrision = false;
	_isProtection = false;
	_isGravity = false;
	_isThunderCloud = false;
	_isBlizzard = false;
	_isCreateFood = false;
	_isCuss = false;
	_isPetrification = false;

	_evadeCount = 1;
}

void player::playerUpdate(){
	keyInput();
	inputAction();
	_jump->update();

	//무적
	if (_isInvincible){
		if (_invincibleTime > INVINCIBLE_TIME){
			_isInvincible = false;
		}
		_invincibleTime++;
		_damageAlpha += 60;
	}
	else{
		_damageAlpha = 255;
	}

	if (_state == PLAYER_DEAD){
		_isInvincible = true;
		if (_direction == RIGHT_DIRECTION){
			if (KEYANIMANAGER->findAnimation("sorceress_down_right")->getFramePos().x<5000)
			_shadowX-=10;
		}
		if (_direction == LEFT_DIRECTION){
			if (KEYANIMANAGER->findAnimation("sorceress_down_left")->getFramePos().x<5000)
			_shadowX+=10;
		}
	}
	
	//그림자 rect
	_rcShadow = RectMakeCenter(_shadowX+138, _shadowY+10, 100, 20);

	if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_LEFT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP ||
		_state == PLAYER_NORMAL_JUMP_ATTACK || _state == PLAYER_NORMAL_JUMP_CHARGE_ATTACK || _state == PLAYER_SPECIAL_JUMP_ATTACK || _state == PLAYER_SPECIAL_JUMP_CHARGE_ATTACK ||
		_state == PLAYER_RAVITATION){
		if (_direction == RIGHT_DIRECTION){
			_rcPlayer = RectMake(_playerX + 150, _playerY + 50, 100, 400);
		}
		else{
			_rcPlayer = RectMake(_playerX + 100, _playerY + 50, 100, 400);
		}
	}
	else if (_state == PLAYER_RUN){
		if (_direction == RIGHT_DIRECTION){
			_rcPlayer = RectMake(_playerX + 150, _playerY + 50, 100, 400);
		}
		else{
			_rcPlayer = RectMake(_playerX + 100, _playerY + 50, 100, 400);
		}
	}
	else{
		_rcPlayer = RectMake(_playerX + 100, _playerY + 50, 100, 400);
	}
	

	//마나 채우기
	if (_state == PLAYER_NORMAL_CHARGING){
		if (_mp < _mpMax){
			_mp += 1 * (INIDATA->loadDataInterger("PlayerData","Skill","concentrate")+1);
		}
		if (_direction == RIGHT_DIRECTION){
			EFFECTMANAGER->playAlpha("마나모으기", _playerX+250, _playerY+10);
		}
		else{
			EFFECTMANAGER->playAlpha("마나모으기", _playerX + 70, _playerY + 10);
		}
	}
}
void player::playerRender(){
	switch (_state){
	case PLAYER_STAND:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_stand_right")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_stand_right")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_stand")->alphaAniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_stand_right"), _damageAlpha);
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_stand_left")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_stand_left")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_stand")->alphaAniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_stand_left"), _damageAlpha);
			break;
		}
		
		break;
	case PLAYER_WALK:
		_playerRun = false;
		_playerRavitation = false;
		_playerWalk = true;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_walk_right")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_walk_right")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_walk")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_walk_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_walk_left")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_walk_left")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_walk")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_walk_left"));
			break;
		}
		break;
	case PLAYER_RUN:
		_playerRun = true;
		_playerWalk = false;
		_playerRavitation = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_run_right")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_run_right")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_run")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_run_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_run_left")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_run_left")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_run")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_run_left"));
			break;
		}
		break;
	case PLAYER_TURN:
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_turn_right")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_turn_right")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_turn")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_turn_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_turn_left")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_turn_left")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_turn")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_turn_left"));
			break;
		}
		break;
	case PLAYER_JUMP:
	case PLAYER_JUMP_RIGHT:
	case PLAYER_JUMP_LEFT:
	case PLAYER_JUMP_UP:
	case PLAYER_JUMP_DOWN:
	case PLAYER_JUMP_RIGHT_UP:
	case PLAYER_JUMP_RIGHT_DOWN:
	case PLAYER_JUMP_LEFT_UP:
	case PLAYER_JUMP_LEFT_DOWN:
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX+_shadowOffX/2, _shadowY,_shadowWidth-_shadowOffX,_shadowHeight,0,0,235,16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if(!KEYANIMANAGER->findAnimation("sorceress_jump_up_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_jump_up_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_up_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_jump_up_left"));
			break;
		}
		break;
	case PLAYER_RAVITATION:
		_playerRavitation = true;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_ravitation_right")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_ravitation_right")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_ravitation")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_ravitation_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_ravitation_left")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_ravitation_left")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_ravitation")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_ravitation_left"));
			break;
		}
		break;

	case PLAYER_RAVITATION_DOWN:
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_ravitation_down_right")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_ravitation_down_right")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_ravitation")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_ravitation_down_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_ravitation_down_left")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_ravitation_down_left")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_ravitation")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_ravitation_down_left"));
			break;
		}
		break;
	case PLAYER_SLIDING:
		switch (_direction){
		case RIGHT_DIRECTION:
			break;
		case LEFT_DIRECTION:
			break;
		}
		break;
	case PLAYER_NORMAL_ATTACK:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack1_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack1")->aniRender(getMemDC(), _playerX-112, _playerY-69, KEYANIMANAGER->findAnimation("sorceress_attack1_right"));
			break;
			
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack1_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack1")->aniRender(getMemDC(), _playerX-69, _playerY-69, KEYANIMANAGER->findAnimation("sorceress_attack1_left"));
			break;
		}


		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		HFONT hFont, oldFont;
		char str3[100];
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);

		break;
	case PLAYER_NORMAL_JUMP_CHARGE_ATTACK:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump_attack1")->aniRender(getMemDC(), _playerX , _playerY , KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right"));
			break;

		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump_attack1")->aniRender(getMemDC(), _playerX-100 , _playerY-10 , KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left"));
			break;
		}


		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);
		break;

	case PLAYER_NORMAL_JUMP_ATTACK:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump_attack1")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right"));
			break;

		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump_attack1")->aniRender(getMemDC(), _playerX - 100, _playerY - 10, KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left"));
			break;
		}


		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);

		break;
	case PLAYER_NORMAL_CHARGE:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_charge_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_gauge")->aniRender(getMemDC(), _playerX-99 , _playerY-8 , KEYANIMANAGER->findAnimation("sorceress_charge_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_charge_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_gauge")->aniRender(getMemDC(), _playerX - 82, _playerY - 8, KEYANIMANAGER->findAnimation("sorceress_charge_left"));
			break;
		}
		break;
	case PLAYER_NORMAL_CHARGING:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_charging_right")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_charging_right")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_gauge")->aniRender(getMemDC(), _playerX - 99, _playerY-8, KEYANIMANAGER->findAnimation("sorceress_charging_right"));
			
			
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_charging_left")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_charging_left")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_gauge")->aniRender(getMemDC(), _playerX - 82, _playerY - 8, KEYANIMANAGER->findAnimation("sorceress_charging_left"));
			
			break;
		}
		EFFECTMANAGER->render();
		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);


		break;
	case PLAYER_NORMAL_CHARGED:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_charged_right")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_charged_right")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_gauge")->aniRender(getMemDC(), _playerX - 99, _playerY - 8, KEYANIMANAGER->findAnimation("sorceress_charged_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_charged_left")->isPlay()){
				sorceressAllStop();
				KEYANIMANAGER->findAnimation("sorceress_charged_left")->start();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_gauge")->aniRender(getMemDC(), _playerX - 82, _playerY - 8, KEYANIMANAGER->findAnimation("sorceress_charged_left"));
			break;
		}
		break;
	case PLAYER_SPECIAL_ATTACK:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findAlphaImage("shadow4")->alphaRender(getMemDC(), _shadowX - 10, _shadowY - 45, 125);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack1_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack1")->aniRender(getMemDC(), _playerX - 112, _playerY - 69, KEYANIMANAGER->findAnimation("sorceress_attack1_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack1_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack1")->aniRender(getMemDC(), _playerX - 69, _playerY - 69, KEYANIMANAGER->findAnimation("sorceress_attack1_left"));
			break;
		}


		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);

		break;

	case PLAYER_SPECIAL_ATTACK2:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findAlphaImage("shadow6")->alphaRender(getMemDC(), _shadowX - 10, _shadowY - 45, 125);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack2_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack2")->aniRender(getMemDC(), _playerX - 112, _playerY - 90, KEYANIMANAGER->findAnimation("sorceress_attack2_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack2_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack2")->aniRender(getMemDC(), _playerX - 69, _playerY - 90, KEYANIMANAGER->findAnimation("sorceress_attack2_left"));
			break;
		}


		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);

		break;

	case PLAYER_SPECIAL_ATTACK3:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findAlphaImage("shadow6")->alphaRender(getMemDC(), _shadowX - 10, _shadowY - 45, 125);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack4_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack4")->aniRender(getMemDC(), _playerX - 100, _playerY - 38, KEYANIMANAGER->findAnimation("sorceress_attack4_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack4_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack4")->aniRender(getMemDC(), _playerX - 80, _playerY - 38, KEYANIMANAGER->findAnimation("sorceress_attack4_left"));
			break;
		}


		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);

		break;
	case PLAYER_SPECIAL_CHARGE_ATTACK:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		//IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX, _shadowY);
		IMAGEMANAGER->findAlphaImage("shadow6")->alphaRender(getMemDC(), _shadowX-10, _shadowY-45,125);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack3_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack3")->aniRender(getMemDC(), _playerX - 97, _playerY - 45, KEYANIMANAGER->findAnimation("sorceress_attack3_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_attack3_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_attack3")->aniRender(getMemDC(), _playerX - 90, _playerY - 47, KEYANIMANAGER->findAnimation("sorceress_attack3_left"));
			break;
		}

		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);

		break;
	case PLAYER_SPECIAL_JUMP_CHARGE_ATTACK:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump_attack1")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right"));
			break;

		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump_attack1")->aniRender(getMemDC(), _playerX - 100, _playerY - 10, KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left"));
			break;
		}

		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);

		break;
	case PLAYER_SPECIAL_JUMP_ATTACK:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump_attack1")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right"));
			break;

		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_jump_attack1")->aniRender(getMemDC(), _playerX - 100, _playerY - 10, KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left"));
			break;
		}

		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(), _playerX + 80, _playerY - 100, 200);

		SetBkMode(getMemDC(), TRANSPARENT);
		hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), hFont);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str3, "%d/", _mp);
		TextOut(getMemDC(), _playerX + 100, _playerY - 90, str3, strlen(str3));
		sprintf(str3, "%d", _mpMax);
		TextOut(getMemDC(), _playerX + 110, _playerY - 60, str3, strlen(str3));
		SelectObject(getMemDC(), oldFont);
		DeleteObject(hFont);

		break;
	case PLAYER_ABILITY:
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_ability_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_ability")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_ability_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_ability_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_ability")->aniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_ability_left"));
			break;
		}
		break;
	case PLAYER_TELEPORT_START:
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_teleport_right_start")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_ability")->alphaAniRender(getMemDC(), _playerX - 50, _playerY, KEYANIMANAGER->findAnimation("sorceress_teleport_right_start"),_teleportAlpha);
			_teleportAlpha -= 15;
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_teleport_left_start")->isPlay()){
				sorceressAllStop();
			}
			_teleportAlpha -= 15;
			IMAGEMANAGER->findAlphaImage("sorceress_ability")->alphaAniRender(getMemDC(), _playerX - 100, _playerY, KEYANIMANAGER->findAnimation("sorceress_teleport_left_start"), _teleportAlpha);
			break;
		}
		break;
	case PLAYER_TELEPORT_END:
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_teleport_right_end")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_ability")->alphaAniRender(getMemDC(), _playerX, _playerY, KEYANIMANAGER->findAnimation("sorceress_teleport_right_end"), _teleportAlpha);
			_teleportAlpha += 15;
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_teleport_left_end")->isPlay()){
				sorceressAllStop();
			}
			_teleportAlpha += 15;
			IMAGEMANAGER->findAlphaImage("sorceress_ability")->alphaAniRender(getMemDC(), _playerX - 100, _playerY, KEYANIMANAGER->findAnimation("sorceress_teleport_left_end"), _teleportAlpha);
			break;
		}
		break;

	case PLAYER_BAG_USE:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_skill_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_skill")->aniRender(getMemDC(), _playerX-90, _playerY-97, KEYANIMANAGER->findAnimation("sorceress_skill_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_skill_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_skill")->aniRender(getMemDC(), _playerX-90, _playerY-97, KEYANIMANAGER->findAnimation("sorceress_skill_left"));
			break;
		}
		break;
	case PLAYER_POTION:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_potion_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_potion")->aniRender(getMemDC(), _playerX - 90, _playerY-40 , KEYANIMANAGER->findAnimation("sorceress_potion_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_potion_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_potion")->aniRender(getMemDC(), _playerX - 90, _playerY -40, KEYANIMANAGER->findAnimation("sorceress_potion_left"));
			break;
		}
		break;
	case PLAYER_DAMAGE:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_damage_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_damage")->alphaAniRender(getMemDC(), _playerX-50 , _playerY , KEYANIMANAGER->findAnimation("sorceress_damage_right"),_damageAlpha);
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_damage_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_damage")->alphaAniRender(getMemDC(), _playerX - 50, _playerY, KEYANIMANAGER->findAnimation("sorceress_damage_left"), _damageAlpha);
			break;
		}
		break;

	case PLAYER_DEAD:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_down_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_down")->alphaAniRender(getMemDC(), _playerX - 100, _playerY-100, KEYANIMANAGER->findAnimation("sorceress_down_right"), 255);
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_down_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_down")->alphaAniRender(getMemDC(), _playerX - 100, _playerY-100, KEYANIMANAGER->findAnimation("sorceress_down_left"), 255);
			break;
		}
		break;

	case PLAYER_FOOD_EAT:
		_playerRavitation = false;
		_playerWalk = false;
		_playerRun = false;
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _shadowX + _shadowOffX / 2, _shadowY, _shadowWidth - _shadowOffX, _shadowHeight, 0, 0, 235, 16);
		switch (_direction){
		case RIGHT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_food_eat_right")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_food_eat")->aniRender(getMemDC(), _playerX - 70, _playerY-90, KEYANIMANAGER->findAnimation("sorceress_food_eat_right"));
			break;
		case LEFT_DIRECTION:
			if (!KEYANIMANAGER->findAnimation("sorceress_food_eat_left")->isPlay()){
				sorceressAllStop();
			}
			IMAGEMANAGER->findAlphaImage("sorceress_food_eat")->aniRender(getMemDC(), _playerX - 100, _playerY-90, KEYANIMANAGER->findAnimation("sorceress_food_eat_left"));
			break;
		}
		break;
	}


	if (_debug){
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
		Rectangle(getMemDC(), _rcPlayer.left, _rcPlayer.top, _rcPlayer.right, _rcPlayer.bottom);
	}

	if (_bagTimer < BAG_SHOW){
		IMAGEMANAGER->findAlphaImage("bag_equip")->alphaRender(getMemDC(),_playerX+80,_playerY-100, 200);	
		HFONT hFont, oldFont;
		char str3[100];
		RECT _rcDialog = { _playerX, _playerY, _playerX + 300, _playerY + 30 };
		SetBkMode(getMemDC(), TRANSPARENT);
		switch (_currentEquip){
		case 0:
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), _playerX + 110, _playerY - 90, _bag[0].frameX, _bag[0].frameY);
			if (strcmp(_bag[0].name.c_str(), "empty") != 0){
				hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), hFont);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf(str3, "%d", _bag[0].useCount);
				TextOut(getMemDC(), _playerX + 150, _playerY - 60, str3, strlen(str3));
				DrawText(getMemDC(), _bag[0].name.c_str(), _bag[0].name.size(), &_rcDialog, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				SelectObject(getMemDC(), oldFont);
				DeleteObject(hFont);
			}
			break;
		case 1:
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), _playerX + 110, _playerY - 90, _bag[1].frameX, _bag[1].frameY);
			if (strcmp(_bag[1].name.c_str(), "empty") != 0){
				hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), hFont);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf(str3, "%d", _bag[1].useCount);
				TextOut(getMemDC(), _playerX + 150, _playerY - 60, str3, strlen(str3));
				DrawText(getMemDC(), _bag[1].name.c_str(), _bag[1].name.size(), &_rcDialog, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				SelectObject(getMemDC(), oldFont);
				DeleteObject(hFont);
			}
			break;						   
		case 2:							   
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), _playerX + 110, _playerY - 90, _bag[2].frameX, _bag[2].frameY);
			if (strcmp(_bag[2].name.c_str(), "empty") != 0){
				hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), hFont);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf(str3, "%d", _bag[2].useCount);
				TextOut(getMemDC(), _playerX + 150, _playerY - 60, str3, strlen(str3));
				DrawText(getMemDC(), _bag[2].name.c_str(), _bag[2].name.size(), &_rcDialog, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				SelectObject(getMemDC(), oldFont);
				DeleteObject(hFont);
			}
			break;						   
		case 3:							   
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), _playerX + 110, _playerY - 90, _bag[3].frameX, _bag[3].frameY);
			if (strcmp(_bag[3].name.c_str(), "empty") != 0){
				hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), hFont);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf(str3, "%d", _bag[3].useCount);
				TextOut(getMemDC(), _playerX + 150, _playerY - 60, str3, strlen(str3));
				DrawText(getMemDC(), _bag[3].name.c_str(), _bag[3].name.size(), &_rcDialog, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				SelectObject(getMemDC(), oldFont);
				DeleteObject(hFont);
			}
			break;						   
		case 4:							   
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), _playerX + 110, _playerY - 90, _bag[4].frameX, _bag[4].frameY);
			if (strcmp(_bag[4].name.c_str(), "empty") != 0){
				hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), hFont);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf(str3, "%d", _bag[4].useCount);
				TextOut(getMemDC(), _playerX + 150, _playerY - 60, str3, strlen(str3));
				DrawText(getMemDC(), _bag[4].name.c_str(), _bag[4].name.size(), &_rcDialog, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				SelectObject(getMemDC(), oldFont);
				DeleteObject(hFont);
			}
			break;						   
		case 5:							   
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), _playerX + 110, _playerY - 90, _bag[5].frameX, _bag[5].frameY);
			if (strcmp(_bag[5].name.c_str(), "empty") != 0){
				hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), hFont);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf(str3, "%d", _bag[5].useCount);
				TextOut(getMemDC(), _playerX + 150, _playerY - 60, str3, strlen(str3));
				DrawText(getMemDC(), _bag[5].name.c_str(), _bag[5].name.size(), &_rcDialog, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				SelectObject(getMemDC(), oldFont);
				DeleteObject(hFont);
			}
			break;						   
		case 6:							   
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), _playerX + 110, _playerY - 90, _bag[6].frameX, _bag[6].frameY);
			if (strcmp(_bag[6].name.c_str(), "empty") != 0){
				hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), hFont);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf(str3, "%d", _bag[6].useCount);
				TextOut(getMemDC(), _playerX + 150, _playerY - 60, str3, strlen(str3));
				DrawText(getMemDC(), _bag[6].name.c_str(), _bag[6].name.size(), &_rcDialog, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				SelectObject(getMemDC(), oldFont);
				DeleteObject(hFont);
			}
			break;						   
		case 7:							   
			IMAGEMANAGER->findImage("아이템1")->frameRender(getMemDC(), _playerX + 110, _playerY - 90, _bag[7].frameX, _bag[7].frameY);
			if (strcmp(_bag[7].name.c_str(), "empty") != 0){
				hFont = CreateFont(30, 15, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
				oldFont = (HFONT)SelectObject(getMemDC(), hFont);
				SetTextColor(getMemDC(), RGB(255, 255, 255));
				sprintf(str3, "%d", _bag[7].useCount);
				TextOut(getMemDC(), _playerX + 150, _playerY - 60, str3, strlen(str3));
				DrawText(getMemDC(), _bag[7].name.c_str(), _bag[7].name.size(), &_rcDialog, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
				SelectObject(getMemDC(), oldFont);
				DeleteObject(hFont);
			}
			break;
		}
		
		
	}
}
void player::playerRelease(){ }

/*
void player::stateInit(){
	_hpMax = _hp = _hpCurrent = INIDATA->loadDataInterger("PlayerData", "State", "HP");
	_mpMax = _mp = INIDATA->loadDataInterger("PlayerData", "State", "MP");
	_lv = INIDATA->loadDataInterger("PlayerData", "State", "LEVEL");
	_exp = INIDATA->loadDataInterger("PlayerData", "State", "EXP");
	_str = INIDATA->loadDataInterger("PlayerData", "State", "STR");
	_int = INIDATA->loadDataInterger("PlayerData", "State", "INT");
	_con = INIDATA->loadDataInterger("PlayerData", "State", "CON");
	_mgr = INIDATA->loadDataInterger("PlayerData", "State", "MGR");
	_dex = INIDATA->loadDataInterger("PlayerData", "State", "DEX");
	_luc = INIDATA->loadDataInterger("PlayerData", "State", "LUC");

	//공격
	_atk = _str/2 + _int * 10 + _dex / 2;
	//크리티컬
	_critical = _luc;
	//방어력
	_def = _con / 5 + _mgr;

}
*/
void player::keyInput(){
	_input = NONE;

	if (KEYMANAGER->isStayKeyDown(VK_LEFT)){
			_input |= LEFT;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT)){
		_chargeTimeA = 0;
		_isChargeA = false;
		_leftButton = false;
	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)){
			_input |= RIGHT;
			_rightButton = true;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)){
		_chargeTimeA = 0;
		_isChargeA = false;
		_rightButton = false;
	}

	if (KEYMANAGER->isStayKeyDown(VK_UP)){
		_input |= UP;
		
	}

	if (KEYMANAGER->isOnceKeyUp(VK_UP)){
		_upButton = false;
	}

	if (KEYMANAGER->isStayKeyDown(VK_DOWN)){
		_input |= DOWN;
	}

	if (KEYMANAGER->isOnceKeyUp(VK_DOWN)){
		_downButton = false;
	}

	if (KEYMANAGER->isStayKeyDown('A')){
		_isChargeA = true;
	}
	
	if (KEYMANAGER->isOnceKeyUp('A')){
		if ((!_isRunningJump || _state == PLAYER_STAND || _state == PLAYER_WALK) && _state != PLAYER_NORMAL_CHARGE){
			_input |= COMMAND_NORMAL_A;
		}
		_chargeTimeA = 0;
		_isChargeA = false;

		if (_state == PLAYER_NORMAL_CHARGING || _state == PLAYER_NORMAL_CHARGE){
			_state = PLAYER_NORMAL_CHARGED;
		}
	}
	if (KEYMANAGER->isStayKeyDown('S')){
		_isChargeS = true;
	}

	if (KEYMANAGER->isOnceKeyUp('S')){
		if (_state != PLAYER_SPECIAL_CHARGE_ATTACK){
			if (_chargeTimeS < CHARGE_TIME){
				_input |= COMMAND_NORMAL_S;
			}
			else {
				_input |= COMMAND_CHARGE_S;
			}
		}
		_isChargeS = false;
		_chargeTimeS = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('Z')){
		_input |= COMMAND_Z;
	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		_isRunningJump = false;
		if (_input &LEFT &&_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN){
			_direction = LEFT_DIRECTION;
		}
		if (_input&RIGHT && _state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN){
			_direction = RIGHT_DIRECTION;
		}

		if (!_jump->getIsTwo()){
			_input |= COMMAND_X;
		}
		else if (_state != PLAYER_RAVITATION  && _state != PLAYER_RAVITATION_DOWN){
			SOUNDMANAGER->play("빗자루타기", 1.0f);
			_state = PLAYER_RAVITATION;
			_ravitationTime = 0;
		}
		_isChargeA = false;
		_chargeTimeA = 0;
	}

	if (_state != PLAYER_BAG_USE&&
		_state != PLAYER_DAMAGE){
		if (KEYMANAGER->isOnceKeyDown('Q')){
			_input |= COMMAND_Q;
			if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN || _state == PLAYER_RAVITATION ||
				_state == PLAYER_NORMAL_JUMP_ATTACK || _state == PLAYER_NORMAL_JUMP_CHARGE_ATTACK || _state == PLAYER_SPECIAL_JUMP_ATTACK || _state == PLAYER_SPECIAL_JUMP_CHARGE_ATTACK || _state == PLAYER_ABILITY_START || _state == PLAYER_ABILITY){
				if (_abilityCount > 0){
					_state = PLAYER_ABILITY_START;
					_abilityCount--;
				}
			}
			else{
				if (_state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END){
					_state = PLAYER_TELEPORT_START;
					_teleportAlpha = 255;
				}
			}
		}
	}
	
	if (_state != PLAYER_DAMAGE){
		if (KEYMANAGER->isOnceKeyDown('W')){
			_input |= COMMAND_W;
			_state == PLAYER_BAG_USE;
		}
	}

	
	//차지 입력
	if (_isChargeA){
		_chargeTimeA++;
	}

	if (_isChargeS){
		_chargeTimeS++;
	}

	if (_chargeTimeA > CHARGE_TIME){

		//상태에따라 다르게 (점프상태일경우 초기화)
		_input |= COMMAND_CHARGE_A;
		if (_state == PLAYER_JUMP){
			_chargeTimeA = 0;
			_isChargeA = false;
		}
		
	}

	if (_chargeTimeS > CHARGE_TIME){
		_input |= COMMAND_CHARGE_S;
		
		_chargeTimeS = 0;
		_isChargeS = false;
	}

	
	if (KEYMANAGER->isOnceKeyDown('E')){
		if (_bagShow)	_currentEquip++;
		_bagTimer = 0;
		_bagShow = true;
		if (_currentEquip > 7){
			_currentEquip = 0;
		}
		
	}
	_bagTimer++;
	if (_bagTimer >= BAG_SHOW){ 
		_bagTimer = BAG_SHOW;
		_bagShow = false;
	}

}

void player::inputAction(){
	//플레이어 음식먹기
	if (_playerFoodEat){
		_playerFoodEat = false;
		_state = PLAYER_FOOD_EAT;
		if (_direction == RIGHT_DIRECTION)
			KEYANIMANAGER->findAnimation("sorceress_food_eat_right")->start();
		else
			KEYANIMANAGER->findAnimation("sorceress_food_eat_left")->start();
		_hp += 100 + INIDATA->loadDataInterger("PlayerData", "Skill", "create_food") * (10 * INIDATA->loadDataInterger("PlayerData", "Skill", "food_psytology")+1);
		SOUNDMANAGER->play("음식먹기", 0.3F);
	}


	if (_input == NONE){
		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION && _state != PLAYER_RAVITATION_DOWN&&
			_state != PLAYER_NORMAL_ATTACK&&
			_state != PLAYER_NORMAL_CHARGE&&_state != PLAYER_NORMAL_CHARGING && _state != PLAYER_NORMAL_CHARGED &&
			_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK&&
			_state != PLAYER_NORMAL_JUMP_ATTACK &&
			_state != PLAYER_SPECIAL_CHARGE_ATTACK&&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 &&
			_state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK && _state != PLAYER_SPECIAL_JUMP_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE && _state != PLAYER_POTION &&
			_state != PLAYER_DAMAGE && _state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT ){
			_state = PLAYER_STAND;
			_isSoundPlay = false;
		}
		
	}

	if (_input & LEFT){

		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN&&
			_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK&&
			_state != PLAYER_NORMAL_ATTACK&&
			_state != PLAYER_NORMAL_JUMP_ATTACK &&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 && _state != PLAYER_SPECIAL_JUMP_ATTACK&&
			_state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&_state != PLAYER_SPECIAL_CHARGE_ATTACK&&
			_state != PLAYER_ABILITY && _state != PLAYER_ABILITY_START&& _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			if (_direction == RIGHT_DIRECTION){
				_state = PLAYER_TURN;
				_direction = LEFT_DIRECTION;
			}
			if (_state != PLAYER_TURN){
				_state = PLAYER_WALK;
				//_playerX -= PLAYER_SPEEDX - _speedRate;
				_shadowX -= PLAYER_SPEEDX - _speedRate;
				_playerX = _shadowX;
				_playerY = _shadowY - 440;
			}
			_leftButton = true;
			_rightButton = false;
		}
	}

	if (_input & RIGHT){
		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN&&
			_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_NORMAL_ATTACK&&
			_state != PLAYER_NORMAL_JUMP_ATTACK &&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 &&_state != PLAYER_SPECIAL_JUMP_ATTACK&&
			_state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK && _state != PLAYER_SPECIAL_CHARGE_ATTACK&&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			if (_direction == LEFT_DIRECTION){
				_state = PLAYER_TURN;
				_direction = RIGHT_DIRECTION;
			}
			if (_state != PLAYER_TURN){
				_state = PLAYER_WALK;

				//_playerX += PLAYER_SPEEDX + _speedRate;
				_shadowX += PLAYER_SPEEDX + _speedRate;
				_playerX = _shadowX;
				_playerY = _shadowY - 440;
			}
			_leftButton = false;
			_rightButton = true;
		}
	}
	
	if (_input & UP){
		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&

			_state != PLAYER_NORMAL_CHARGE && _state != PLAYER_NORMAL_CHARGED && _state != PLAYER_NORMAL_CHARGING &&
			_state != PLAYER_NORMAL_ATTACK&& _state != PLAYER_NORMAL_JUMP_ATTACK && _state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&_state != PLAYER_SPECIAL_JUMP_ATTACK && _state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_WALK;
			//_playerY -= PLAYER_SPEEDY;
			_shadowY -= PLAYER_SPEEDY;
			_playerY = _shadowY-440;

			_upButton = true;
		}
	}

	if (_input & DOWN){
		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN&&
			_state != PLAYER_NORMAL_CHARGE && _state != PLAYER_NORMAL_CHARGED && _state != PLAYER_NORMAL_CHARGING &&
			_state != PLAYER_NORMAL_ATTACK&& _state != PLAYER_NORMAL_JUMP_ATTACK && _state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 && _state != PLAYER_SPECIAL_JUMP_ATTACK && _state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_WALK;
			//_playerY += PLAYER_SPEEDY;
			_shadowY += PLAYER_SPEEDY;
			_playerY = _shadowY-440;
			_downButton = true;
		}
	}

	//플레이어 달리기
	if (_input == (COMMAND_CHARGE_A | RIGHT)){
		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&
			_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK && _state != PLAYER_NORMAL_JUMP_ATTACK &&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 && _state != PLAYER_SPECIAL_CHARGE_ATTACK && _state != PLAYER_SPECIAL_JUMP_ATTACK && _state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_RUN;
			_direction = RIGHT_DIRECTION;
			//_playerX += PLAYER_RUNSPEEDX + _speedRate;
			_shadowX += PLAYER_RUNSPEEDX + _speedRate;
			_playerX = _shadowX;
			if (!_isSoundPlay){
				SOUNDMANAGER->play("공격1", 1.0f);
				_isSoundPlay = true;
			}
		}

		//if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN){
		//	KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->start();
		//	_state = PLAYER_NORMAL_JUMP_CHARGE_ATTACK;
		//}
	}
	
	if (_input == (COMMAND_CHARGE_A | LEFT)){
		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&
			_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&_state != PLAYER_NORMAL_JUMP_ATTACK &&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 && _state != PLAYER_SPECIAL_CHARGE_ATTACK && _state != PLAYER_SPECIAL_JUMP_ATTACK && _state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_RUN;
			_direction = LEFT_DIRECTION;
			//_playerX -= PLAYER_RUNSPEEDX - _speedRate;
			_shadowX -= PLAYER_RUNSPEEDX - _speedRate;
			_playerX = _shadowX;
			if (!_isSoundPlay){
				SOUNDMANAGER->play("공격1", 1.0f);
				_isSoundPlay = true;
			}
		}

		//if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN){
		//	KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->start();
		//	_state = PLAYER_NORMAL_JUMP_CHARGE_ATTACK;
		//}
	}

	//플레이어 공격
	
	if (_input == COMMAND_NORMAL_A || _input == (RIGHT | COMMAND_NORMAL_A) || _input == (LEFT | COMMAND_NORMAL_A) || _input == (UP | COMMAND_NORMAL_A) || _input == (DOWN | COMMAND_NORMAL_A)){
		if (_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&
			_state != PLAYER_NORMAL_ATTACK &&
			_state != PLAYER_NORMAL_JUMP_ATTACK &&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 && _state != PLAYER_SPECIAL_CHARGE_ATTACK && _state != PLAYER_SPECIAL_JUMP_ATTACK && _state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			
			if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN){
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->start();
				}
				if (_direction == LEFT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->start();
				}
				_state = PLAYER_NORMAL_JUMP_ATTACK;
				if (_mp - 5 > 0){
					
					_isManaball2 = true;
					_mp -= 5;
				}
				SOUNDMANAGER->play("공격1", 1.0f);
			}
			else{
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_attack1_right")->start();
				}
				if (_direction == LEFT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_attack1_left")->start();
				}
				_state = PLAYER_NORMAL_ATTACK;
				if (_mp - 5 > 0){
					
					_isManaball1 = true;
					_mp -= 5;
				}
				SOUNDMANAGER->play("공격1", 1.0f);
			}
		}
	}

	if (_input == COMMAND_CHARGE_A || _input == (RIGHT | COMMAND_CHARGE_A) || _input == (LEFT | COMMAND_CHARGE_A) || _input == (UP | COMMAND_CHARGE_A) || _input == (DOWN | COMMAND_CHARGE_A)){
		if (_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN 
			&& _state !=PLAYER_NORMAL_CHARGE && _state != PLAYER_NORMAL_CHARGING & _state != PLAYER_NORMAL_CHARGED &&
			_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_NORMAL_JUMP_ATTACK &&
			_state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK && _state != PLAYER_SPECIAL_JUMP_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_SPECIAL_ATTACK && _state != PLAYER_SPECIAL_ATTACK2 && _state != PLAYER_SPECIAL_ATTACK3 && _state != PLAYER_SPECIAL_CHARGE_ATTACK && _state != PLAYER_SPECIAL_JUMP_ATTACK && _state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_RUN &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN){
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->start();
				}
				if (_direction == LEFT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->start();
				}

				_state = PLAYER_NORMAL_JUMP_CHARGE_ATTACK;
				if (_mp - 20>0){
					
					_isJumpAttack = true;
					_isManaball2 = true;
					_mp -= 20;
				}
				SOUNDMANAGER->play("공격1", 1.0f);
			}
			else{
				_state = PLAYER_NORMAL_CHARGE;
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_charge_right")->start();
				}
				if (_direction == LEFT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_charge_left")->start();
				}				
				SOUNDMANAGER->play("기모으기", 1.0f);
			}
		}
	}

	if (_input == COMMAND_NORMAL_S){
		if (_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&
			_state != PLAYER_SPECIAL_ATTACK &&
			_state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK && _state != PLAYER_SPECIAL_CHARGE_ATTACK &&
			_state != PLAYER_SPECIAL_JUMP_ATTACK&&
			_state != PLAYER_NORMAL_ATTACK &&_state != PLAYER_NORMAL_JUMP_ATTACK &&	_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END&&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT
			){
			if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN){
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->start();
				}
				if (_direction == LEFT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->start();
				}
				_state = PLAYER_SPECIAL_JUMP_ATTACK;
				if (_mp - 7 > 0){
					
					_isFireball6 = true;
					_mp -= 7;
				}
			}
			else{
				
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_attack1_right")->start();
				}
				if (_direction == LEFT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_attack1_left")->start();
				}
				_state = PLAYER_SPECIAL_ATTACK;
				if (_mp - 7 > 0){
					
					_isFireball4 = true;
					_mp -= 7;
				}
			}
			SOUNDMANAGER->play("공격1", 1.0f);

		}

	}

	if (_input == (RIGHT | COMMAND_NORMAL_S)){
		if (_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&
			_state != PLAYER_SPECIAL_ATTACK &&
			_state != PLAYER_SPECIAL_JUMP_ATTACK&&
			_state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_NORMAL_ATTACK &&_state != PLAYER_NORMAL_JUMP_ATTACK &&	_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END&&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			
			if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN){
				KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->start();
				_state = PLAYER_SPECIAL_JUMP_ATTACK;
				if (_mp - 7 > 0){
					
					_isFireball6 = true;
					_mp -= 7;
				}
			}
			else{
				KEYANIMANAGER->findAnimation("sorceress_attack1_right")->start();
				_state = PLAYER_SPECIAL_ATTACK;
				if (_mp - 7 > 0){
					_mp -= 7;
					
					_isFireball4 = true;
				}
			}
			SOUNDMANAGER->play("공격1", 1.0f);
		}
	}

	if (_input == (LEFT | COMMAND_NORMAL_S)){
		if (_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&
			_state != PLAYER_SPECIAL_ATTACK &&
			_state != PLAYER_SPECIAL_JUMP_ATTACK&&
			_state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK&&
			_state != PLAYER_NORMAL_ATTACK &&_state != PLAYER_NORMAL_JUMP_ATTACK &&	_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_NORMAL_ATTACK &&_state != PLAYER_NORMAL_JUMP_ATTACK &&	_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END&&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN){
				KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->start();
				_state = PLAYER_SPECIAL_JUMP_ATTACK;
				if (_mp - 7 > 0){
					_mp -= 7;
					
					_isFireball6 = true;
				}
			}
			else{
				
				KEYANIMANAGER->findAnimation("sorceress_attack1_left")->start();
				_state = PLAYER_SPECIAL_ATTACK;
				if (_mp - 7 > 0){
					
					_mp -= 7;
					_isFireball4 = true;
				}
			}
			SOUNDMANAGER->play("공격1", 1.0f);
		}
	}

	if (_input == (UP | COMMAND_NORMAL_S)){
		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&
			_state != PLAYER_NORMAL_ATTACK &&_state != PLAYER_NORMAL_JUMP_ATTACK &&	_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_SPECIAL_ATTACK2 &&
			_state != PLAYER_ABILITY && _state != PLAYER_ABILITY_START&& _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			
			if (_direction == RIGHT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_attack2_right")->start();
			}
			if (_direction == LEFT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_attack2_left")->start();
			}
			_state = PLAYER_SPECIAL_ATTACK2;
			if (_mp - 15 > 0){

				_isFireball3 = true;
				_mp -= 15;
			}
			SOUNDMANAGER->play("공격3", 1.0f);
			SOUNDMANAGER->play("파이어2", 0.3F);
		}

	}

	if (_input == (DOWN | COMMAND_NORMAL_S)){
		if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN&&
			_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN &&
			_state != PLAYER_SPECIAL_ATTACK3 &&
			_state != PLAYER_ABILITY && _state != PLAYER_ABILITY_START&& _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END&&
			_state != PLAYER_NORMAL_ATTACK &&_state != PLAYER_NORMAL_JUMP_ATTACK &&	_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_SPECIAL_ATTACK3;
			if (_direction == RIGHT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_attack4_right")->start();
			}
			if (_direction == LEFT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_attack4_left")->start();
			}
			if (_mp - 30 > 0){
				_isFireball1 = true;
				_mp -= 30;
			}
			SOUNDMANAGER->play("공격3", 1.0f);
		}

	}
	
	if (_input == COMMAND_CHARGE_S || _input == (RIGHT | COMMAND_CHARGE_S) || _input == (LEFT | COMMAND_CHARGE_S)){
		if (_state != PLAYER_RAVITATION&& _state != PLAYER_RAVITATION_DOWN
			&& _state != PLAYER_NORMAL_CHARGE && _state != PLAYER_NORMAL_CHARGING & _state != PLAYER_NORMAL_CHARGED &&
			_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_SPECIAL_CHARGE_ATTACK &&_state != PLAYER_SPECIAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_NORMAL_ATTACK &&_state != PLAYER_NORMAL_JUMP_ATTACK &&	_state != PLAYER_NORMAL_JUMP_CHARGE_ATTACK &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&_state != PLAYER_SPECIAL_JUMP_ATTACK&&
			_state != PLAYER_FOOD_EAT){
			if (_state == PLAYER_JUMP || _state == PLAYER_JUMP_RIGHT || _state == PLAYER_JUMP_LEFT || _state == PLAYER_JUMP_UP || _state == PLAYER_JUMP_DOWN || _state == PLAYER_JUMP_RIGHT_UP || _state == PLAYER_JUMP_RIGHT_DOWN || _state == PLAYER_JUMP_LEFT_UP || _state == PLAYER_JUMP_LEFT_DOWN){
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_jump_attack1_right")->start();
				}
				if (_direction == LEFT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_jump_attack1_left")->start();
				}
				_state = PLAYER_SPECIAL_JUMP_CHARGE_ATTACK;
				if (_mp - 20>0){
					_isJumpAttack = true;
					_isFireball5 = true;
					_mp -= 20;
				}
			}
			else{
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_attack3_right")->start();
				}
				if (_direction == LEFT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_attack3_left")->start();
				}
				_state = PLAYER_SPECIAL_CHARGE_ATTACK;
				if (_mp - 20>0){
					_isFireball2 = true;
					_mp -= 20;
				}
			}
			SOUNDMANAGER->play("공격3", 1.0f);
		}
	}

	//플레이어 점프
	if (_input == (COMMAND_X)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_JUMP;

			if (_direction == RIGHT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_jump_up_right")->start();
				_leftButton = false;
				_rightButton = true;
			}
			else{
				KEYANIMANAGER->findAnimation("sorceress_jump_up_left")->start();
				_leftButton = true;
				_rightButton = false;
			}
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			SOUNDMANAGER->play("점프", 1.0f);
		}
		
	}

	if (_input == (COMMAND_X | RIGHT) || _input == (COMMAND_X | RIGHT | COMMAND_CHARGE_A)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			if (_state == PLAYER_WALK) { 
				_isRunningJump = true; }
			_state = PLAYER_JUMP_RIGHT;
			KEYANIMANAGER->findAnimation("sorceress_jump_up_right")->start();
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			_leftButton = false;
			_rightButton = true;
			SOUNDMANAGER->play("점프", 1.0f);
		}
	}

	if (_input == (COMMAND_X | LEFT) || _input == (COMMAND_X | LEFT | COMMAND_CHARGE_A)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			if (_state == PLAYER_WALK) { _isRunningJump = true; }
			_state = PLAYER_JUMP_LEFT;
			KEYANIMANAGER->findAnimation("sorceress_jump_up_left")->start();
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			_leftButton = true;
			_rightButton = false;
			SOUNDMANAGER->play("점프", 1.0f);
		}
	}

	if (_input == (COMMAND_X | UP)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_JUMP_UP;
			if (_direction == RIGHT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_jump_up_right")->start();
			}
			else{
				KEYANIMANAGER->findAnimation("sorceress_jump_up_left")->start();
			}
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			_jumpStartY = _jump->getIsStartY();
			SOUNDMANAGER->play("점프", 1.0f);
		}
	}

	if (_input == (COMMAND_X | DOWN)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_JUMP_DOWN;
			if (_direction == RIGHT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_jump_up_right")->start();
			}
			else{
				KEYANIMANAGER->findAnimation("sorceress_jump_up_left")->start();
			}
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			_jumpStartY = _jump->getIsStartY();
			SOUNDMANAGER->play("점프", 1.0f);
		}
	}

	if (_input == (COMMAND_X | UP | RIGHT)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_JUMP_RIGHT_UP;
			KEYANIMANAGER->findAnimation("sorceress_jump_up_right")->start();
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			_jumpStartY = _jump->getIsStartY();
			SOUNDMANAGER->play("점프", 1.0f);
		}
	}

	if (_input == (COMMAND_X | UP | LEFT)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_JUMP_LEFT_UP;
			KEYANIMANAGER->findAnimation("sorceress_jump_up_left")->start();
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			_jumpStartY = _jump->getIsStartY();
			SOUNDMANAGER->play("점프", 1.0f);
		}
	}

	if (_input == (COMMAND_X | DOWN | RIGHT)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_JUMP_RIGHT_DOWN;
			KEYANIMANAGER->findAnimation("sorceress_jump_up_right")->start();
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			_jumpStartY = _jump->getIsStartY();
			SOUNDMANAGER->play("점프", 1.0f);
		}
	}

	if (_input == (COMMAND_X | DOWN | LEFT)){
		if (_state != PLAYER_ABILITY&& _state != PLAYER_ABILITY_START && _state != PLAYER_TELEPORT_START && _state != PLAYER_TELEPORT_END &&
			_state != PLAYER_BAG_USE&&
			_state != PLAYER_DAMAGE&&
			_state != PLAYER_DEAD &&
			_state != PLAYER_FOOD_EAT){
			_state = PLAYER_JUMP_LEFT_DOWN;
			KEYANIMANAGER->findAnimation("sorceress_jump_up_left")->start();
			_jump->doubleJumping(&_playerX, &_playerY, JUMPPOWER, JUMPGRAVITY);
			_jumpStartY = _jump->getIsStartY();
			SOUNDMANAGER->play("점프", 1.0f);
		}
	}


	switch (_state){
	case PLAYER_JUMP:
		break;
	case PLAYER_JUMP_RIGHT:
		//_playerX += PLAYER_SPEEDX + _speedRate;
		_shadowX += PLAYER_SPEEDX + _speedRate;
		_playerX = _shadowX;
		break;
	case PLAYER_JUMP_LEFT:
		//_playerX -= (PLAYER_SPEEDX - _speedRate);
		_shadowX -= (PLAYER_SPEEDX - _speedRate);
		_playerX = _shadowX;
		break;
	case PLAYER_JUMP_UP:
		if (!_pixelCollision){
			_playerY -= PLAYER_SPEEDY;
			_shadowY -= PLAYER_SPEEDY;
			_jumpStartY -= PLAYER_SPEEDY;
			_jump->setStartY(_jumpStartY);
		}
		break;
	case PLAYER_JUMP_DOWN:
		if (!_pixelCollision){
			_playerY += PLAYER_SPEEDY;
			_shadowY += PLAYER_SPEEDY;
			_jumpStartY += PLAYER_SPEEDY;
			_jump->setStartY(_jumpStartY);
		}
		break;
	case PLAYER_JUMP_RIGHT_UP:
		//_playerX += PLAYER_SPEEDX + _speedRate;
		_shadowX += PLAYER_SPEEDX + _speedRate;
		_playerX = _shadowX;
		if (!_pixelCollision){
			_playerY -= PLAYER_SPEEDY;
			_shadowY -= PLAYER_SPEEDY;
			_jumpStartY -= PLAYER_SPEEDY;
			_jump->setStartY(_jumpStartY);
		}
		break;
	case PLAYER_JUMP_RIGHT_DOWN:
		//_playerX += PLAYER_SPEEDX + _speedRate;
		_shadowX += PLAYER_SPEEDX + _speedRate;
		_playerX = _shadowX;
		if (!_pixelCollision){
			_playerY += PLAYER_SPEEDY;
			_shadowY += PLAYER_SPEEDY;
			_jumpStartY += PLAYER_SPEEDY;
			_jump->setStartY(_jumpStartY);
		}
		break;
	case PLAYER_JUMP_LEFT_UP:
		//_playerX -= (PLAYER_SPEEDX - _speedRate);
		_shadowX -= (PLAYER_SPEEDX - _speedRate);
		_playerX = _shadowX;
		if (!_pixelCollision){
			_playerY -= PLAYER_SPEEDY;
			_shadowY -= PLAYER_SPEEDY;
			_jumpStartY -= PLAYER_SPEEDY;
			_jump->setStartY(_jumpStartY);
		}
		break;
	case PLAYER_JUMP_LEFT_DOWN:
		//_playerX -= (PLAYER_SPEEDX - _speedRate);
		_shadowX -= (PLAYER_SPEEDX - _speedRate);
		_playerX = _shadowX;
		_playerY += PLAYER_SPEEDY;
		_shadowY += PLAYER_SPEEDY;
		_jumpStartY += PLAYER_SPEEDY;
		_jump->setStartY(_jumpStartY);
		break;
	}

	if (_jump->getJumpPower() > 0){
		_shadowOffX += SHADOW_OFFX;
	}
	else{
		if (_jump->getIsDoubleJumping())
			_shadowOffX -= SHADOW_OFFX;
	}
	if (!_jump->getIsDoubleJumping()){
		switch (_state){
		case PLAYER_JUMP:
		case PLAYER_JUMP_RIGHT:
		case PLAYER_JUMP_LEFT:
		case PLAYER_JUMP_UP:
		case PLAYER_JUMP_DOWN:
		case PLAYER_JUMP_RIGHT_UP:
		case PLAYER_JUMP_RIGHT_DOWN:
		case PLAYER_JUMP_LEFT_UP:
		case PLAYER_JUMP_LEFT_DOWN:
			_state = PLAYER_STAND;
		}
		_shadowY = _playerY+440;
		_shadowOffX = 0;
	}
	
	//빗자루타기
	if (_state == PLAYER_RAVITATION){
		_isRavitation = true;
		if (_isRavitation){
			_jump->setJumpPower(0);
		}
		if (_direction == RIGHT_DIRECTION){
			_rightButton = true;
			_leftButton = false;
			//_playerX += PLAYER_RAVITATIONX + _speedRate;
			_shadowX += PLAYER_RAVITATIONX + _speedRate;
			_playerX = _shadowX;

		}
		else{
			_leftButton = true;
			_rightButton = false;
			//_playerX -= (PLAYER_RAVITATIONX - _speedRate);
			_shadowX -= (PLAYER_RAVITATIONX - _speedRate);
			_playerX = _shadowX;
		}
		_ravitationTime++;
	}

	if (_ravitationTime > INIDATA->loadDataInterger("PlayerData","Skill","ravitation")*30){
		_isRavitation = false;
		_ravitationTime = 0;
		_state = PLAYER_RAVITATION_DOWN;
	}

	if (_state == PLAYER_RAVITATION_DOWN){
		if (_direction == RIGHT_DIRECTION){
			//_playerX += PLAYER_RUNSPEEDX + _speedRate;
			_shadowX += PLAYER_RUNSPEEDX + _speedRate;
			_playerX = _shadowX;

		}
		else{
			//_playerX -= (PLAYER_RUNSPEEDX - _speedRate);
			_shadowX -= (PLAYER_RUNSPEEDX - _speedRate);
			_playerX = _shadowX;
		}

		if (_playerY == _jump->getIsStartY())
			_state = PLAYER_STAND;
	}

	//점프공격
	if (_state == PLAYER_NORMAL_JUMP_CHARGE_ATTACK || _state == PLAYER_SPECIAL_JUMP_ATTACK || _state == PLAYER_SPECIAL_JUMP_CHARGE_ATTACK ||_state == PLAYER_NORMAL_JUMP_ATTACK){
		if (_playerY == _jump->getIsStartY())
			_state = PLAYER_STAND;

		if (_isJumpAttack){
			_jump->setJumpPower(0);
		}
		_jumpAttackTime++;
	}

	if (_jumpAttackTime > JUMP_ATTACK_LIMIT){
		_isJumpAttack = false;
		_jumpAttackTime = 0;
	}

	//플레이어 회피 및 텔레포트
	if (_input & COMMAND_Q ){
		if (_state != PLAYER_ABILITY  && _state != PLAYER_TELEPORT_END &&_state != PLAYER_DEAD && _state != PLAYER_BAG_USE ){
			if (_state == PLAYER_ABILITY_START){
				_state = PLAYER_ABILITY;
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_ability_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_ability_left")->start();
				}
				_isAbility = true;
				_isInvincible = true;
				_jumpStartY = _jump->getIsStartY();
				_jump->jumping(&_playerX, &_playerY, 10, 0.5);
				_jump->setStartY(_jumpStartY);
			}
			else{
				if (_direction == RIGHT_DIRECTION){
					if (!KEYANIMANAGER->findAnimation("sorceress_teleport_right_start")->isPlay())
					KEYANIMANAGER->findAnimation("sorceress_teleport_right_start")->start();
				}
				else{
					if (!KEYANIMANAGER->findAnimation("sorceress_teleport_left_start")->isPlay())
					KEYANIMANAGER->findAnimation("sorceress_teleport_left_start")->start();
				}
			}
		}
	}
	
	if (_state ==PLAYER_ABILITY){
		if (_playerY == _jump->getIsStartY()){
			_state = PLAYER_STAND;
			_abilityCount = _abilityMaxCount;
		}

		_abilityTime++;
		if (_direction == RIGHT_DIRECTION){
			//_playerX -= (PLAYER_RUNSPEEDX + _speedRate);
			_shadowX -= (PLAYER_RUNSPEEDX + _speedRate);
			_playerX = _shadowX;
			
		}
		else{
			//_playerX += PLAYER_RUNSPEEDX + _speedRate;
			_shadowX += PLAYER_RUNSPEEDX + _speedRate;
			_playerX = _shadowX;
		}
	}

	if (_abilityTime > ABILITY_TIME){
		_isInvincible = false;
		_isAbility = false;
		_abilityTime = 0;
	}

	if (_teleport){
		if (_direction == RIGHT_DIRECTION){
			_shadowX -= (PLAYER_TELEPORTX + _speedRate);
			//_playerX -= (PLAYER_TELEPORTX + _speedRate);
			_playerX = _shadowX;
		}
		else{
			_shadowX += PLAYER_TELEPORTX + _speedRate;
			//_playerX += PLAYER_TELEPORTX + _speedRate;
			_playerX = _shadowX;
		}
		_teleport = false;
	}

	if (_state == PLAYER_TELEPORT_START || _state == PLAYER_TELEPORT_END){
		_isTeleport1 = true;
	}
	else{
		_isTeleport1 = false;
	}
	//스킬쓰기
	if (_input & COMMAND_W){
		if (_state == PLAYER_STAND || _state == PLAYER_WALK){
			//요정의 물약 실행
			if (strcmp(_bag[_currentEquip].name.c_str(),"요정의 물약")==0){
				_state = PLAYER_POTION;
				_bag[_currentEquip].useCount--;
				if (_hp < _hpMax){
					_hp += 100;
					if (_hp >= _hpMax){  _hp = _hpMax; }

				}
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_potion_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_potion_left")->start();
				}
				SOUNDMANAGER->play("포션마시기", 0.3f);
			}
			
			if (strcmp(_bag[_currentEquip].name.c_str(), "아이스 프리즌의 서") == 0){
				_isIcePrision = true;
				_state = PLAYER_BAG_USE;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
					SOUNDMANAGER->play("스킬", 0.3f);
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
					SOUNDMANAGER->play("스킬", 0.3f);
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}

			if (strcmp(_bag[_currentEquip].name.c_str(), "프로텍션의 서") == 0){
				_isProtection = true;
				_state = PLAYER_BAG_USE;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				SOUNDMANAGER->play("스킬", 0.3f);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}

			if (strcmp(_bag[_currentEquip].name.c_str(), "그래비티의 서") == 0){
				_isGravity = true;
				_state = PLAYER_BAG_USE;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				SOUNDMANAGER->play("스킬", 0.3f);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}

			if (strcmp(_bag[_currentEquip].name.c_str(), "썬더 클라우드의 서") == 0){
				_isThunderCloud = true;
				_state = PLAYER_BAG_USE;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				SOUNDMANAGER->play("스킬", 0.3f);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}

			if (strcmp(_bag[_currentEquip].name.c_str(), "록 프레스의 서") == 0){
				_isRockPress = true;
				_state = PLAYER_BAG_USE;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				SOUNDMANAGER->play("스킬", 0.3f);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}

			if (strcmp(_bag[_currentEquip].name.c_str(), "블리자드의 서") == 0){
				_state = PLAYER_BAG_USE;
				_isBlizzard = true;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				SOUNDMANAGER->play("스킬", 0.3f);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}

			if (strcmp(_bag[_currentEquip].name.c_str(), "크리에이트 푸드의 서") == 0){
				_state = PLAYER_BAG_USE;
				_isCreateFood = true;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				SOUNDMANAGER->play("스킬", 0.3f);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}

			if (strcmp(_bag[_currentEquip].name.c_str(), "커스의 서") == 0){
				_state = PLAYER_BAG_USE;
				_isCuss = true;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				SOUNDMANAGER->play("스킬", 0.3f);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}

			if (strcmp(_bag[_currentEquip].name.c_str(), "페트리피케이션의 서") == 0){
				_isPetrification = true;
				_state = PLAYER_BAG_USE;
				_bag[_currentEquip].useCount--;
				if (_bag[_currentEquip].useCount == 0){
					_bag[_currentEquip] = _emptyBag;
				}
				if (_direction == RIGHT_DIRECTION){
					KEYANIMANAGER->findAnimation("sorceress_skill_right")->start();
				}
				else{
					KEYANIMANAGER->findAnimation("sorceress_skill_left")->start();
				}
				SOUNDMANAGER->play("공격4", 1.0F);
				SOUNDMANAGER->play("스킬", 0.3f);
				int hp = _hp + INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance") * 30;
				if (hp > _hpMax) _hp = _hp;
				else{
					_hp = hp;
				}
			}
		}
	}

	
	_playerX = _shadowX;
}

void player::sorceressAllStop(){
	KEYANIMANAGER->findAnimation("sorceress_stand_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_stand_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_walk_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_walk_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_run_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_run_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_turn_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_turn_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_jump_up_right")->pause();
	KEYANIMANAGER->findAnimation("sorceress_jump_up_left")->pause();
	KEYANIMANAGER->findAnimation("sorceress_ravitation_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_ravitation_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_ravitation_down_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_ravitation_down_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_attack1_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_attack1_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_attack2_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_attack2_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_attack3_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_attack3_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_attack4_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_attack4_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_charge_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_charged_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_charging_right")->stop();
	KEYANIMANAGER->findAnimation("sorceress_charge_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_charged_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_charging_left")->stop();
	KEYANIMANAGER->findAnimation("sorceress_teleport_right_start")->pause();
	KEYANIMANAGER->findAnimation("sorceress_teleport_left_start")->pause();
	KEYANIMANAGER->findAnimation("sorceress_teleport_right_end")->stop();
	KEYANIMANAGER->findAnimation("sorceress_teleport_left_end")->stop();

	//SOUNDMANAGER->stop("스킬");
}

void player::cbStand(){
	if (_state != PLAYER_JUMP && _state != PLAYER_JUMP_RIGHT && _state != PLAYER_JUMP_LEFT && _state != PLAYER_JUMP_UP && _state != PLAYER_JUMP_DOWN && _state != PLAYER_JUMP_RIGHT_UP && _state != PLAYER_JUMP_RIGHT_DOWN && _state != PLAYER_JUMP_LEFT_UP && _state != PLAYER_JUMP_LEFT_DOWN){
		_state = PLAYER_STAND;
	}
}

void player::cbCharge(){
	if (_state != PLAYER_NORMAL_CHARGED && _state != PLAYER_STAND)
	_state = PLAYER_NORMAL_CHARGING;
	
}

void player::cbCharging(){
	if (_state != PLAYER_NORMAL_CHARGED&& _state != PLAYER_STAND)
	_state = PLAYER_NORMAL_CHARGED;
}

void player::cbTeleportStart(){
	if (_direction == RIGHT_DIRECTION){
		KEYANIMANAGER->findAnimation("sorceress_teleport_right_end")->start();
	}
	else{
		KEYANIMANAGER->findAnimation("sorceress_teleport_left_end")->start();
	}
	_state = PLAYER_TELEPORT_END;
	_teleport = true;
}

void player::cbTeleportEnd(){
	_state = PLAYER_STAND;
}

bool player::getIsRight(){
	if (_direction == RIGHT_DIRECTION) return true;
	return false;
}

bool player::getIsLeft(){
	if (_direction == LEFT_DIRECTION) return true;
	return false;
}

void player::bagInit(){
	IMAGEMANAGER->addAlphaImage("bag_equip", "이미지/소서리스/equip.bmp", 119, 98, true, RGB(255, 0, 255));

	_item = new item;
	_item->itemSetting();
	_currentEquip = 0;
	_bagShow = false;
	_bagTimer = 100;
	char str[50];
	for (int i = 0; i < 8; i++){
		sprintf(str, "bag%d", i + 1);
		for (int j = 0; j < _item->getVItem().size(); j++){
			if (strcmp(INIDATA->loadDataString("PlayerData", "Bag", str).c_str(), _item->getVItem()[j].name.c_str()) == 0){
				_bag[i] = _item->getVItem()[j];
				_bag[i].useCount = INIDATA->loadDataInterger("PlayerData", _bag[i].name.c_str(), "num") + INIDATA->loadDataInterger("PlayerData","Skill","item_user");
				break;
			}
			else{
				_bag[i].name = "empty";
				_bag[i].frameX = 20;
				
			}
		}
	}
}

void player::damaged(int damage)
{
	//데미지 입음
	if (!_isInvincible){
		//죽음
		if (_hp-damage <= 0){
			_state = PLAYER_DEAD;
			_hp -= damage;
			_hp = 0;
			if (_direction == RIGHT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_down_right")->start();
			}
			else{
				KEYANIMANAGER->findAnimation("sorceress_down_left")->start();
			}
			_isInvincible = true;
			SOUNDMANAGER->play("죽음2", 1.0F);
		}
		else{
			_state = PLAYER_DAMAGE;
			_hp -= damage;
			_isInvincible = true;
			_invincibleTime = 0;
			_damageAlpha = 255;
			if (_direction == RIGHT_DIRECTION){
				KEYANIMANAGER->findAnimation("sorceress_damage_right")->start();
			}
			else{
				KEYANIMANAGER->findAnimation("sorceress_damage_left")->start();
			}
			int rnd = RND->getInt(3);
			switch (rnd){
			case 0:
				SOUNDMANAGER->play("데미지입음", 1.0f);
				break;
			case 1:
				SOUNDMANAGER->play("데미지입음2", 1.0f);
				break;
			case 2:
				SOUNDMANAGER->play("데미지입음3", 1.0f);
				break;
			}
		}
	}

	
	

}

void player::cbDead(){
	SOUNDMANAGER->allRemove();
	SCENEMANAGER->changeScene("게임오버씬");
}

void player::levelUp(){
	if (_exp >= _playerExp[_lv]){
		_lv++;
		_exp -= _playerExp[_lv - 1]; 
		_hpMax += 100;
		_str += 2;
		_int += 5;
		_con += 3;
		_mgr += 2;
		_dex += 4;
		_luc += 3;
		_atk += 10;
		_def += 3;
		_skillPoint += 1;
		SOUNDMANAGER->play("레벨업", 0.5F);
	}
}