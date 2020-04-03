#include "stdafx.h"
#include "lastBossLoadingScene.h"


lastBossLoadingScene::lastBossLoadingScene()
{
}


lastBossLoadingScene::~lastBossLoadingScene()
{
}


HRESULT lastBossLoadingScene::init(void)
{
	_loading = new loading;
	_loading->init();

	char image[256];

	//로딩을 한번 해봅시다
	memset(image, 0, sizeof(image));
	//_loading->loadImage(image, "selectCh.bmp", 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255), false);
	//_loading->loadSound("over", "OVER.mp3", true, true);
	_loading->loadImage("고대드래곤배경", "이미지/고대드래곤/고대드래곤배경.bmp", 1600, 900, false, RGB(255, 0, 255));
	_loading->loadImage("지형1", "이미지/고대드래곤/지형1.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadImage("지형1픽셀", "이미지/고대드래곤/지형1픽셀.bmp", 1600, 900, false, RGB(255, 0, 255));

	//고대드래곤
	_loading->loadFrameImage("고대드래곤등장", "이미지/고대드래곤/고대드래곤등장.bmp", 28800, 1800, 18, 2, true, RGB(255, 0, 255));
	_loading->loadFrameImage("고대드래곤스탠드1", "이미지/고대드래곤/고대드래곤스탠드1.bmp", 17600, 1200, 11, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("고대드래곤불공격1", "이미지/고대드래곤/고대드래곤불공격1.bmp", 17600, 900, 11, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("고대드래곤전체불공격", "이미지/고대드래곤/고대드래곤전체불공격.bmp", 28800, 2700, 18, 3, true, RGB(255, 0, 255));
	_loading->loadImage("빨강", "damageBuffer1.bmp", 1600, 900, false, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("공격모션2", "이미지/고대드래곤/공격모션2.bmp", 3936, 501, 8,1,true,RGB(255,0,255));
	_loading->loadAlphaFrameImage("공격모션3", "이미지/고대드래곤/공격모션3.bmp", 3936, 501, 8, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("firefloor", "이미지/고대드래곤/firefloor.bmp", 3072, 3072, 4, 4, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("불이펙트", "이미지/고대드래곤/불이펙트.bmp", 960, 124, 16, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("firefloor_shadow", "이미지/소서리스/shadow.bmp", 60, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("fireRain", "이미지/고대드래곤/firerain.bmp", 476, 276, 4, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("불이펙트2", "이미지/고대드래곤/불이펙트2.bmp", 1600, 150, 8, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("fireRain_shadow", "이미지/소서리스/shadow.bmp", 150, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("전체불공격이펙트", "이미지/고대드래곤/전체불공격이펙트.bmp", 24000, 1800, 15, 2, true, RGB(255, 0, 255));
	_loading->loadImage("이미지/고대드래곤/dragonHPTop", "이미지/고대드래곤/dragonHPTop.bmp", 800, 800, 1340, 58, true, RGB(255, 0, 255),false);
	_loading->loadImage("이미지/고대드래곤/dragonHPBottom", "이미지/고대드래곤/dragonHPBottom.bmp", 800, 800, 1340, 58, true, RGB(255, 0, 255), false);
	_loading->loadAlphaFrameImage("보스죽음", "이미지/고대드래곤/보스죽음.bmp", 6400, 900, 4, 1, false, RGB(0, 0, 0));
	_loading->loadImage("고대드래곤", "이미지/고대드래곤/고대드래곤.bmp", 508, 84, true, RGB(255, 0, 255));
	_loading->loadSound("드래곤등장", "사운드/몬스터/드래곤등장.wav", false, false);
	_loading->loadSound("드래곤피어", "사운드/몬스터/드래곤피어.wav", false, false);
	_loading->loadSound("드래곤죽음", "사운드/몬스터/드래곤죽음.wav", false, false);
	_loading->loadSound("드래곤브레스", "사운드/몬스터/드래곤브레스.wav", false, false);
	_loading->loadSound("드래곤공격1", "사운드/몬스터/드래곤공격1.wav", false, false);
	_loading->loadSound("burn", "사운드/몬스터/burn.wav", false, false);
	_loading->loadSound("드래곤공격2", "사운드/몬스터/드래곤공격2.wav", false, false);
	//플레이어
	_loading->loadAlphaFrameImage("sorceress_stand", "이미지/소서리스/sorceress_stand.bmp", 2233, 912, 7, 2, true, RGB(255, 0, 255));						
	_loading->loadAlphaFrameImage("sorceress_walk", "이미지/소서리스/sorceress_walk.bmp", 4080, 950, 12, 2, true, RGB(255, 0, 255));							
	_loading->loadAlphaFrameImage("sorceress_run", "이미지/소서리스/sorceress_run.bmp", 3740, 950, 11, 2, true, RGB(255, 0, 255));							
	_loading->loadAlphaFrameImage("sorceress_turn", "이미지/소서리스/sorceress_turn.bmp", 680, 950, 2, 2, true, RGB(255, 0, 255));							
	_loading->loadAlphaFrameImage("sorceress_jump", "이미지/소서리스/sorceress_jump.bmp", 3700, 950, 10, 2, true, RGB(255, 0, 255));							
	_loading->loadAlphaFrameImage("sorceress_ravitation", "이미지/소서리스/sorceress_ravitation.bmp", 2800, 950, 7, 2, true, RGB(255, 0, 255));				
	_loading->loadAlphaFrameImage("sorceress_attack1", "이미지/소서리스/sorceress_attack1.bmp", 3500, 1100, 7, 2, true, RGB(255, 0, 255));					
	_loading->loadAlphaFrameImage("sorceress_attack2", "이미지/소서리스/sorceress_attack2.bmp", 3000, 1100, 6, 2, true, RGB(255, 0, 255));					
	_loading->loadAlphaFrameImage("sorceress_attack3", "이미지/소서리스/sorceress_attack3.bmp", 5500, 1100, 11, 2, true, RGB(255, 0, 255));					
	_loading->loadAlphaFrameImage("sorceress_attack4", "이미지/소서리스/sorceress_attack4.bmp", 3500, 1100, 7, 2, true, RGB(255, 0, 255));					
	_loading->loadAlphaFrameImage("sorceress_jump_attack1", "이미지/소서리스/sorceress_jump_down_attack.bmp", 2900, 1100, 6, 2, true, RGB(255, 0, 255));		
	_loading->loadAlphaFrameImage("sorceress_jump_attack2", "이미지/소서리스/sorceress_jump_up_attack.bmp", 3000, 1000, 6, 2, true, RGB(255, 0, 255));		
	_loading->loadAlphaFrameImage("sorceress_damage", "이미지/소서리스/sorceress_damage.bmp", 2500, 1100, 5, 2, true, RGB(255, 0, 255));						
	_loading->loadAlphaFrameImage("sorceress_down", "이미지/소서리스/sorceress_down.bmp", 10000, 1232, 20, 2, true, RGB(255, 0, 255));						
	_loading->loadAlphaFrameImage("sorceress_gauge", "이미지/소서리스/sorceress_gauge.bmp", 7500, 950, 15, 2, true, RGB(255, 0, 255));						
	_loading->loadAlphaFrameImage("sorceress_ability", "이미지/소서리스/sorceress_ability.bmp", 3000, 1000, 6, 2, true, RGB(255, 0, 255));					
	_loading->loadAlphaFrameImage("sorceress_potion", "이미지/소서리스/sorceress_potion.bmp", 6000, 1120, 12, 2, true, RGB(255, 0, 255));					
	_loading->loadAlphaFrameImage("sorceress_skill", "이미지/소서리스/sorceress_skill.bmp", 4000, 1200, 8, 2, true, RGB(255, 0, 255));						
	_loading->loadAlphaFrameImage("sorceress_food_eat", "이미지/소서리스/사과먹기.bmp", 6500, 1100, 13, 2, true, RGB(255, 0, 255));							
	_loading->loadPngImage("shadow", L"이미지/소서리스/shadow.png", 300, 32);
	_loading->loadAlphaImage("shadow1", "이미지/소서리스/shadow.bmp", 300, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow2", "이미지/소서리스/shadow.bmp", 320, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow3", "이미지/소서리스/shadow.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow6", "이미지/소서리스/shadow.bmp", 300, 130, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("마나모으기", "이미지/소서리스/마나모으기.bmp", 400, 100, 100, 100, true, RGB(255, 0, 255));
	_loading->loadFrameImage("manaball", "이미지/소서리스/manaball.bmp", 1542, 200, 6, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("fireball1", "이미지/소서리스/fireball1.bmp", 6120, 400, 17, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("fireball2", "이미지/소서리스/fireball2.bmp", 6750, 450, 15, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("normalBullet3", "이미지/소서리스/fireball3.bmp", 1285, 314, 5, 2, true, RGB(255, 0, 255));
	_loading->loadFrameImage("normalBullet4", "이미지/소서리스/fireball4.bmp", 2400, 800, 6, 2, true, RGB(255, 0, 255));
	_loading->loadFrameImage("normalBullet5", "이미지/소서리스/fireball4.bmp", 1200, 400, 6, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("블리자드", "이미지/소서리스/스킬/블리자드.bmp", 1600, 900, false, RGB(255, 0, 255));
	_loading->loadAlphaImage("apple", "이미지/음식/apple.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("pear", "이미지/음식/pear.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("pormegranate", "이미지/음식/pormegranate.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow4", "이미지/소서리스/shadow.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("cuss", "이미지/소서리스/스킬/커즈.bmp", 3600, 1000, 12, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow5", "이미지/소서리스/shadow.bmp", 200, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("gravity", "이미지/소서리스/스킬/그래비티.bmp", 10500, 500, 21, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("gravity_arrage", "이미지/소서리스/스킬/그래비티범위.bmp", 1000, 700, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision1", "이미지/소서리스/스킬/아이스프리즌1.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision2", "이미지/소서리스/스킬/아이스프리즌2.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision3", "이미지/소서리스/스킬/아이스프리즌3.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision4", "이미지/소서리스/스킬/아이스프리즌4.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision5", "이미지/소서리스/스킬/아이스프리즌5.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("석화", "이미지/소서리스/스킬/페트리픽케이션.bmp", 1500, 300, 5, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("석화효과", "이미지/소서리스/스킬/석화효과.bmp", 1600, 900, false, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("프로텍션", "이미지/소서리스/스킬/프로텍션.bmp", 5400, 900, 6, 1, true, RGB(255, 0, 255));
	_loading->loadPngFrameImage("rockPress", L"이미지/소서리스/스킬/스톤.png", 900, 600, 3, 1);
	_loading->loadAlphaImage("rockPress2", "이미지/소서리스/스킬/스톤3.bmp", 400, 500, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("구름", "이미지/소서리스/스킬/구름.bmp", 1200, 150, 4, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("번개", "이미지/소서리스/스킬/번개.bmp", 600, 800, 6, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("피격흑백", "이미지/소서리스/흑백.bmp", 300, 300, false, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("피격이펙트", "이미지/소서리스/피격이펙트.bmp", 900, 900, 3, 3, true, RGB(255, 0, 255));
	_loading->loadSound("공격1", "사운드/소서리스/공격.mp3", false, false);
	_loading->loadSound("빗자루타기", "사운드/소서리스/공격2.mp3", false, false);
	_loading->loadSound("공격3", "사운드/소서리스/공격3.mp3", false, false);
	_loading->loadSound("공격4", "사운드/소서리스/공격4.mp3", false, false);
	_loading->loadSound("기모으기", "사운드/소서리스/기모으기.mp3", false, false);
	_loading->loadSound("데미지입음", "사운드/소서리스/데미지입음.mp3", false, false);
	_loading->loadSound("데미지입음2", "사운드/소서리스/데미지입음2.mp3", false, false);
	_loading->loadSound("데미지입음3", "사운드/소서리스/데미지입음3.mp3", false, false);
	_loading->loadSound("점프", "사운드/소서리스/점프.mp3", false, false);
	_loading->loadSound("죽음1", "사운드/소서리스/죽음1.mp3", false, false);
	_loading->loadSound("죽음2", "사운드/소서리스/죽음2.mp3", false, false);
	_loading->loadSound("레벨업", "사운드/소서리스/레벨업.wav", false, false);
	_loading->loadSound("스킬", "사운드/소서리스/스킬.wav", false, true);
	_loading->loadSound("포션마시기", "사운드/소서리스/포션마시기.wav", false, false);
	_loading->loadSound("파이어2", "사운드/소서리스/파이어2.wav", false, false);
	_loading->loadSound("폭발", "사운드/소서리스/폭발.wav", false, false);
	_loading->loadSound("중력", "사운드/소서리스/gravity.wav", false, false);
	_loading->loadSound("음식먹기", "사운드/소서리스/음식먹기.wav", false, false);
	_loading->loadSound("블리자드", "사운드/소서리스/블리자드.wav", false, false);
	_loading->loadSound("createFood", "사운드/소서리스/createFood.wav", false, false);
	_loading->loadSound("커즈", "사운드/소서리스/cuss.wav", false, false);
	_loading->loadSound("gravity", "사운드/소서리스/gravity.wav", false, false);
	_loading->loadSound("아이스프리즌", "사운드/소서리스/아이스프리즌.wav", false, false);
	_loading->loadSound("페트리", "사운드/소서리스/petri.wav", false, false);
	_loading->loadSound("쉴드시작", "사운드/소서리스/쉴드시작.wav", false, false);
	_loading->loadSound("쉴드해제", "사운드/소서리스/쉴드해제.wav", false, false);
	_loading->loadSound("stone", "사운드/소서리스/stone.wav", false, false);
	_loading->loadSound("thunder", "사운드/소서리스/thunderstorm.wav", false, false);
	_loading->loadSound("파이어볼", "사운드/소서리스/파이어볼.wav", false, false);
	return S_OK;
}

void lastBossLoadingScene::release(void)
{
	SAFE_DELETE(_loading);
}

void lastBossLoadingScene::update(void)
{
	_loading->update();

	if (!_loading->loadNext())
	{
		SCENEMANAGER->changeScene("라스트보스씬");
	}
	else {

	}
}

void lastBossLoadingScene::render(void)
{
	_loading->render();
}