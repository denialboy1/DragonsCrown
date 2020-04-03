#include "stdafx.h"
#include "townLoadingScene.h"


townLoadingScene::townLoadingScene()
{
}


townLoadingScene::~townLoadingScene()
{
}


HRESULT townLoadingScene::init(void)
{
	_loading = new loading;
	_loading->init();

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
	//마을
	_loading->loadImage("마을1", "이미지/마을/town1.bmp", 788, 120, true, RGB(255, 0, 255));
	_loading->loadImage("마을2", "이미지/마을/town2.bmp", 905, 143, true, RGB(255, 0, 255));
	_loading->loadImage("마을3", "이미지/마을/town3.bmp", 1501, 813, true, RGB(255, 0, 255));
	_loading->loadImage("마을4", "이미지/마을/town4.bmp", 1443, 300, true, RGB(255, 0, 255));
	_loading->loadImage("마을5", "이미지/마을/town5.bmp", 1700, 250, true, RGB(255, 0, 255));
	_loading->loadImage("마을6", "이미지/마을/town6.bmp", 1500, 300, true, RGB(255, 0, 255));
	_loading->loadImage("마을7", "이미지/마을/town7.bmp", 1449, 303, true, RGB(255, 0, 255));
	_loading->loadImage("마을8", "이미지/마을/town8.bmp", 800, WINSIZEY + 100, true, RGB(255, 0, 255));
	_loading->loadImage("마을9", "이미지/마을/town9.bmp", WINSIZEX, WINSIZEY + 300, true, RGB(255, 0, 255));
	_loading->loadImage("마을10", "이미지/마을/town10.bmp", 159, 297, true, RGB(255, 0, 255));
	_loading->loadImage("마을11", "이미지/마을/town11.bmp", 6083, 1500, true, RGB(255, 0, 255));
	_loading->loadImage("마을12", "이미지/마을/stone.bmp", 300, 1200, true, RGB(255, 0, 255));
	_loading->loadImage("마을13", "이미지/마을/town12.bmp", 105, 890, true, RGB(255, 0, 255));
	_loading->loadImage("마을충돌", "이미지/마을/collision.bmp", 6083, 1500, false, RGB(255, 0, 255));

	//상점
	_loading->loadFrameImage("상점엔피씨", "이미지/마을/상점/상점엔피씨.bmp", 16000, 4500, 10, 5, true, RGB(255, 0, 255));
	_loading->loadImage("상점마크", "이미지/마을/상점/마법상점마크.bmp", 293, 215, true, RGB(255, 0, 255));
	_loading->loadImage("상점간판", "이미지/마을/상점/마법상점간판.bmp", 400, 107, true, RGB(255, 0, 255));
	_loading->loadImage("구입선택지1", "이미지/마을/상점/구입선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("구입선택지2", "이미지/마을/상점/구입선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("매각선택지1", "이미지/마을/상점/매각선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("매각선택지2", "이미지/마을/상점/매각선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("수리선택지1", "이미지/마을/상점/수리선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("수리선택지2", "이미지/마을/상점/수리선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("감정선택지1", "이미지/마을/상점/감정선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("감정선택지2", "이미지/마을/상점/감정선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("나가기선택지1", "이미지/마을/나가기선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("나가기선택지2", "이미지/마을/나가기선택지2.bmp", 467, 80, true, RGB(255, 0, 255));

	//길드
	_loading->loadFrameImage("길드움직임", "이미지/마을/길드/길드움직임.bmp", 16000, 4500, 10, 5, true, RGB(255, 0, 255));
	_loading->loadImage("길드간판", "이미지/마을/길드/길드간판.bmp", 627, 92, true, RGB(255, 0, 255));
	_loading->loadImage("길드간판1", "이미지/마을/길드/길드간판.bmp", 400, 92, true, RGB(255, 0, 255));
	_loading->loadImage("길드마크", "이미지/마을/길드/길드마크.bmp", 208, 227, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("스킬선택지1", "이미지/마을/길드/스킬선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("스킬선택지2", "이미지/마을/길드/스킬선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("나가기선택지1", "이미지/마을/나가기선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("나가기선택지2", "이미지/마을/나가기선택지2.bmp", 467, 80, true, RGB(255, 0, 255));

	//소서리스스킬,공용스킬선택지 이미지
	_loading->loadImage("스킬창상단", "이미지/마을/길드/스킬창상단.bmp", 1600, 146, true, RGB(255, 0, 255));
	_loading->loadImage("스킬창하단", "이미지/마을/길드/스킬창하단.bmp", 1600, 123, true, RGB(255, 0, 255));
	_loading->loadFrameImage("소서리스스킬리스트움직임", "이미지/마을/길드/소서리스스킬리스트움직임.bmp", 4140, 1200, 12, 2, true, RGB(255, 0, 255));
	_loading->loadFrameImage("공용스킬움직임", "이미지/마을/길드/공용스킬움직임.bmp", 4212, 1248, 12, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("소서리스스킬리스트", "이미지/마을/길드/소서리스스킬리스트.bmp", 400, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("공통스킬리스트", "이미지/마을/길드/공통스킬리스트.bmp", 400, 590, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("흑백처리", "이미지/마을/길드/흑백처리.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("흑백처리2", "이미지/마을/길드/흑백처리.bmp", 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("스킬창중단", "이미지/마을/길드/스킬창중간.bmp", 1600, 631, true, RGB(255, 0, 255));

	//소서리스스킬
	_loading->loadAlphaImage("멘탈앱소브", "이미지/마을/길드/멘탈앱소브.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("엑스트랙트", "이미지/마을/길드/엑스트랙트.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("콘센트레이트", "이미지/마을/길드/콘센트레이트.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("매직포인트업", "이미지/마을/길드/매직포인트업.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("아이스프리즌", "이미지/마을/길드/아이스프리즌.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("프로텍션4", "이미지/마을/길드/프로텍션.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("그래비티", "이미지/마을/길드/그래비티.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("썬더클라우드", "이미지/마을/길드/썬더클라우드.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("록프레스", "이미지/마을/길드/록프레스.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("블리자드4", "이미지/마을/길드/블리자드.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("애니메이트스켈톤", "이미지/마을/길드/애니메이트스켈톤.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("레비테이션", "이미지/마을/길드/레비테이션.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("크리에이트푸드", "이미지/마을/길드/크리에이트푸드.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("커스", "이미지/마을/길드/커스.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("페트리피케이션", "이미지/마을/길드/페트리피케이션.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);

	//공용 스킬
	_loading->loadAlphaImage("슬라이딩", "이미지/마을/길드/슬라이딩.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("골드힐링", "이미지/마을/길드/골드힐링.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("골드스코어링", "이미지/마을/길드/골드스코어링.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("히트포인트업", "이미지/마을/길드/히트포인트업.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("푸드사이톨로지", "이미지/마을/길드/푸드사이톨로지.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("메인테넌스", "이미지/마을/길드/메인테넌스.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("아이템유저", "이미지/마을/길드/아이템유저.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("이베이드", "이미지/마을/길드/이베이드.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("엑스트라포켓", "이미지/마을/길드/엑스트라포켓.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);

	//대화 이미지
	_loading->loadAlphaImage("대화상자", "이미지/talkBar.bmp", 1600, 118, true, RGB(255, 0, 255));
	_loading->loadImage("no", "이미지/no.bmp", 184, 185, true, RGB(255, 0, 255));
	_loading->loadImage("yes", "이미지/yes.bmp", 185, 185, true, RGB(255, 0, 255));
	_loading->loadImage("no_check", "이미지/no_check.bmp", 236, 234, true, RGB(255, 0, 255));
	_loading->loadImage("yes_check", "이미지/yes_check.bmp", 234, 235, true, RGB(255, 0, 255));

	//주점
	_loading->loadImage("주점", "이미지/마을/주점/주점.bmp", 1920, 957, true, RGB(255, 0, 255));
	_loading->loadFrameImage("주점요정", "이미지/마을/주점/주점요정.bmp", 14616, 998, 24, 2, true, RGB(255, 0, 255));
	_loading->loadImage("주점간판", "이미지/마을/주점/주점간판.bmp", 651, 118, true, RGB(255, 0, 255));
	_loading->loadImage("주점간판1", "이미지/마을/주점/주점간판.bmp", 350, 118, true, RGB(255, 0, 255));
	_loading->loadImage("주점마크", "이미지/마을/주점/주점마크.bmp", 191, 171, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("나가기선택지1", "이미지/마을/나가기선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("나가기선택지2", "이미지/마을/나가기선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("세이브선택지1", "이미지/마을/주점/세이브선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("세이브선택지2", "이미지/마을/주점/세이브선택지2.bmp", 467, 80, true, RGB(255, 0, 255));

	//모험의 기록 이미지 불러오기 
	_loading->loadImage("세이브책1", "이미지/마을/주점/세이브/세이브1.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	_loading->loadImage("세이브책2", "이미지/마을/주점/세이브/세이브2.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	_loading->loadImage("세이브책3", "이미지/마을/주점/세이브/세이브3.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	_loading->loadImage("큰세이브책1", "이미지/마을/주점/세이브/세이브1.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	_loading->loadImage("큰세이브책2", "이미지/마을/주점/세이브/세이브2.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	_loading->loadImage("큰세이브책3", "이미지/마을/주점/세이브/세이브3.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("세이브", "이미지/마을/주점/세이브/세이브.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("세이브위치선택", "이미지/마을/주점/세이브/세이브위치선택1.bmp", 1505, 206, true, RGB(255, 0, 255));


	//플레이어 가방
	_loading->loadAlphaImage("장비소지품배경", "이미지/menu/장비소지품/장비_소지품.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("장비현재선택위치", "이미지/마을/상점/현재선택위치.bmp", 0, 0, 600, 73, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("bgItemBox", "이미지/menu/아이템박스/아이템박스.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("아이템현재선택위치", "이미지/마을/상점/현재선택위치.bmp", 0, 0, 900, 100, true, RGB(255, 0, 255), true);

	//매뉴
	_loading->loadAlphaImage("state_bag_choice1", "이미지/menu/state_bag_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_bag_choice2", "이미지/menu/state_bag_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_inven_choice1", "이미지/menu/state_inven_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_inven_choice2", "이미지/menu/state_inven_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_skill_choice1", "이미지/menu/state_skill_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_skill_choice2", "이미지/menu/state_skill_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_state_choice1", "이미지/menu/state_state_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_state_choice2", "이미지/menu/state_state_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadImage("talizman_empty", "이미지/menu/talizman_empty.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman1", "이미지/menu/talizman1.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman2", "이미지/menu/talizman2.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman3", "이미지/menu/talizman3.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman4", "이미지/menu/talizman4.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman5", "이미지/menu/talizman5.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman6", "이미지/menu/talizman6.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman7", "이미지/menu/talizman7.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman8", "이미지/menu/talizman8.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman9", "이미지/menu/talizman9.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadPngImage("bg_sorceress", L"이미지/menu/bg_sorceressout.png", 900, 900);
	_loading->loadAlphaImage("state_money", "이미지/menu/state_money.bmp", 581, 84, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("bgGray", "이미지/menu/bgGray.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadImage("menu_talizman", "이미지/menu/menu_talizman.bmp", 581, 100, true, RGB(255, 0, 255));

	//스킬정보
	_loading->loadAlphaImage("bgSkillInfo", "이미지/menu/스킬/스킬확인.bmp", 1600, 900, true, RGB(255, 0, 255));

	//소서리스스킬
	_loading->loadAlphaImage("멘탈앱소브1", "이미지/마을/길드/멘탈앱소브.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("엑스트랙트1", "이미지/마을/길드/엑스트랙트.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("콘센트레이트1", "이미지/마을/길드/콘센트레이트.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("매직포인트업1", "이미지/마을/길드/매직포인트업.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("아이스프리즌1", "이미지/마을/길드/아이스프리즌.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("프로텍션1", "이미지/마을/길드/프로텍션.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("그래비티1", "이미지/마을/길드/그래비티.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("썬더클라우드1", "이미지/마을/길드/썬더클라우드.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("록프레스1", "이미지/마을/길드/록프레스.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("블리자드1", "이미지/마을/길드/블리자드.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("애니메이트스켈톤1", "이미지/마을/길드/애니메이트스켈톤.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("레비테이션1", "이미지/마을/길드/레비테이션.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("크리에이트푸드1", "이미지/마을/길드/크리에이트푸드.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("커스1", "이미지/마을/길드/커스.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("페트리피케이션1", "이미지/마을/길드/페트리피케이션.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);

	//공용 스킬
	_loading->loadAlphaImage("슬라이딩1", "이미지/마을/길드/슬라이딩.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("골드힐링1", "이미지/마을/길드/골드힐링.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("골드스코어링1", "이미지/마을/길드/골드스코어링.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("히트포인트업1", "이미지/마을/길드/히트포인트업.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("푸드사이톨로지1", "이미지/마을/길드/푸드사이톨로지.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("메인테넌스1", "이미지/마을/길드/메인테넌스.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("아이템유저1", "이미지/마을/길드/아이템유저.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("이베이드1", "이미지/마을/길드/이베이드.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("엑스트라포켓1", "이미지/마을/길드/엑스트라포켓.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);

	//스킬정보 선택지
	_loading->loadAlphaImage("스킬정보선택지1", "이미지/menu/스킬/스킬정보선택지1.bmp", 1400, 90, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("스킬정보선택지2", "이미지/menu/스킬/스킬정보선택지2.bmp", 1400, 90, true, RGB(255, 0, 255));


	//상태창
	_loading->loadAlphaImage("stateTop", "이미지/menu/스테이터스/스테이터스_top.bmp", 1600, 146, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("stateBottom", "이미지/menu/스테이터스/스테이터스_bottom.bmp", 1600, 200, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("양피지1", "이미지/menu/스테이터스/스테이터스_양피지1.bmp", 840, 570, true, RGB(255, 0, 255));
	_loading->loadImage("이미지/menu/스테이터스/expBarFull", "이미지/menu/스테이터스/expBarFull.bmp", WINSIZEX / 2, 700, 1600, 200, true, RGB(255, 0, 255), true);
	_loading->loadImage("이미지/menu/스테이터스/expBar", "이미지/menu/스테이터스/expBar.bmp", WINSIZEX / 2, 700, 1600, 200, true, RGB(255, 0, 255), true);

	//아이템
	_loading->loadFrameImage("아이템", "이미지/마을/item.bmp", 950, 760, 10, 8, true, RGB(255, 0, 255));
	_loading->loadFrameImage("아이템1", "이미지/마을/item.bmp", 600, 500, 10, 8, true, RGB(255, 0, 255), true);
	_loading->loadFrameImage("아이템2", "이미지/마을/item.bmp", 400, 300, 10, 8, true, RGB(255, 0, 255), true);

	//죽음
	_loading->loadAlphaImage("죽음", "이미지/죽음.bmp", 648, 151, false, RGB(255, 0, 255));
	_loading->loadAlphaImage("묘지", "이미지/묘지.bmp", 583, 473, false, RGB(255, 0, 255));

	_loading->loadImage("던전마크", "이미지/마을/던전/던전마크.bmp", 218, 209, true, RGB(255, 0, 255));
	_loading->loadImage("던전간판", "이미지/마을/던전/던전간판.bmp", 400, 112, true, RGB(255, 0, 255));
	_loading->loadImage("던전간판", "이미지/마을/던전/던전간판.bmp", 658, 112, true, RGB(255, 0, 255));

	//룬
	_loading->loadImage("z", "이미지/룬/z.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("zClick", "이미지/룬/z클릭.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("z선택", "이미지/룬/z선택.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("t선택", "이미지/룬/t선택.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("s선택", "이미지/룬/s선택.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("d선택", "이미지/룬/d선택.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("e선택", "이미지/룬/e선택.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("r선택", "이미지/룬/r선택.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("m선택", "이미지/룬/m선택.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("z발동", "이미지/룬/z발동.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("t발동", "이미지/룬/t발동.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("s발동", "이미지/룬/s발동.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("d발동", "이미지/룬/d발동.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("e발동", "이미지/룬/e발동.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("r발동", "이미지/룬/r발동.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("m발동", "이미지/룬/m발동.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("rune_room", "이미지/룬/룬칸.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("rune_black", "이미지/룬/black.bmp", 1600, 900, false, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("light", "이미지/룬/light.bmp", 595 * 2, 595 * 2, 4, 4, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("rmz_info", "이미지/룬/rmz_info.bmp", 1600, 113, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("rmz_bg", "이미지/고대드래곤/고대드래곤배경.bmp", 1600, 900, false, RGB(255, 0, 255));
	return S_OK;
}

void townLoadingScene::release(void)
{
	SAFE_DELETE(_loading);
}

void townLoadingScene::update(void)
{
	_loading->update();

	if (!_loading->loadNext())
	{
		SCENEMANAGER->changeScene("마을씬");
	}
	else {

	}
}

void townLoadingScene::render(void)
{
	_loading->render();
}