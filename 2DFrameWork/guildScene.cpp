#include "stdafx.h"
#include "guildScene.h"


guildScene::guildScene()
{
}


guildScene::~guildScene()
{
}

HRESULT guildScene::init(){
	///////////////////////이미지 불러오기//////////////////////
	//길드 메인 이미지
	//IMAGEMANAGER->addFrameImage("길드움직임", "이미지/마을/길드/길드움직임.bmp", 16000, 7200, 10, 8, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("길드간판", "이미지/마을/길드/길드간판.bmp", 627, 92, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("길드마크", "이미지/마을/길드/길드마크.bmp", 208, 227, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("스킬선택지1", "이미지/마을/길드/스킬선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("스킬선택지2", "이미지/마을/길드/스킬선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("나가기선택지1", "이미지/마을/나가기선택지1.bmp", 467, 80, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("나가기선택지2", "이미지/마을/나가기선택지2.bmp", 467, 80, true, RGB(255, 0, 255));
	//
	////소서리스스킬,공용스킬선택지 이미지
	//IMAGEMANAGER->addImage("스킬창상단", "이미지/마을/길드/스킬창상단.bmp", 1600, 146, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("스킬창하단", "이미지/마을/길드/스킬창하단.bmp", 1600, 123, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("소서리스스킬리스트움직임", "이미지/마을/길드/소서리스스킬리스트움직임.bmp", 4140, 1200,12,2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("공용스킬움직임", "이미지/마을/길드/공용스킬움직임.bmp", 4212, 1248, 12, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("소서리스스킬리스트", "이미지/마을/길드/소서리스스킬리스트.bmp", 400, 600, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("공통스킬리스트", "이미지/마을/길드/공통스킬리스트.bmp", 400, 590, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("흑백처리", "이미지/마을/길드/흑백처리.bmp", 0,0,250, 400, true, RGB(255, 0, 255),true);
	//IMAGEMANAGER->addAlphaImage("흑백처리2", "이미지/마을/길드/흑백처리.bmp", 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("스킬창중단", "이미지/마을/길드/스킬창중간.bmp", 1600, 631, true, RGB(255, 0, 255));
	//
	////소서리스스킬
	//IMAGEMANAGER->addAlphaImage("멘탈앱소브", "이미지/마을/길드/멘탈앱소브.bmp", 0,0,250, 400, true, RGB(255, 0, 255),true);
	//IMAGEMANAGER->addAlphaImage("엑스트랙트", "이미지/마을/길드/엑스트랙트.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("콘센트레이트", "이미지/마을/길드/콘센트레이트.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("매직포인트업", "이미지/마을/길드/매직포인트업.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("아이스프리즌", "이미지/마을/길드/아이스프리즌.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("프로텍션", "이미지/마을/길드/프로텍션.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("그래비티", "이미지/마을/길드/그래비티.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("썬더클라우드", "이미지/마을/길드/썬더클라우드.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("록프레스", "이미지/마을/길드/록프레스.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("블리자드", "이미지/마을/길드/블리자드.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("애니메이트스켈톤", "이미지/마을/길드/애니메이트스켈톤.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("레비테이션", "이미지/마을/길드/레비테이션.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("크리에이트푸드", "이미지/마을/길드/크리에이트푸드.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("커스", "이미지/마을/길드/커스.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("페트리피케이션", "이미지/마을/길드/페트리피케이션.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//
	////공용 스킬
	//IMAGEMANAGER->addAlphaImage("슬라이딩", "이미지/마을/길드/슬라이딩.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("골드힐링", "이미지/마을/길드/골드힐링.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("골드스코어링", "이미지/마을/길드/골드스코어링.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("히트포인트업", "이미지/마을/길드/히트포인트업.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("푸드사이톨로지", "이미지/마을/길드/푸드사이톨로지.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("메인테넌스", "이미지/마을/길드/메인테넌스.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("아이템유저", "이미지/마을/길드/아이템유저.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("이베이드", "이미지/마을/길드/이베이드.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//IMAGEMANAGER->addAlphaImage("엑스트라포켓", "이미지/마을/길드/엑스트라포켓.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	//
	////대화 이미지
	//IMAGEMANAGER->addAlphaImage("대화상자", "이미지/talkBar.bmp", 1600, 118, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("no", "이미지/no.bmp", 184, 185, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("yes", "이미지/yes.bmp", 185, 185, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("no_check", "이미지/no_check.bmp", 236, 234, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("yes_check", "이미지/yes_check.bmp", 234, 235, true, RGB(255, 0, 255));

	IMAGEMANAGER->addAlphaImage("스킬마스터", "이미지/마을/길드/스킬마스터.bmp", 1600, 113, false, RGB(0, 0, 0));
	IMAGEMANAGER->addAlphaImage("레벨부족", "이미지/마을/길드/레벨부족.bmp", 1600, 113, false, RGB(0, 0, 0));
	IMAGEMANAGER->addAlphaImage("스킬포인트부족", "이미지/마을/길드/스킬포인트부족.bmp", 1600, 113, false, RGB(0, 0, 0));


	//길드장움직이기
	KEYANIMANAGER->addDefaultFrameAnimation("길드움직임", "길드움직임", 15, true, true);
	KEYANIMANAGER->findAnimation("길드움직임")->start();

	int arr1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
	KEYANIMANAGER->addArrayFrameAnimation("소서리스스킬리스트움직임", "소서리스스킬리스트움직임",arr1,12, 10, false,skillMoveOpen);
	int arr2[] = { 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 };
	KEYANIMANAGER->addArrayFrameAnimation("소서리스스킬리스트움직임닫기", "소서리스스킬리스트움직임", arr2,12, 10, false, skillMoveClose);
	KEYANIMANAGER->addArrayFrameAnimation("공용스킬움직임", "공용스킬움직임", arr1, 12, 10, false, skillMoveOpen);
	KEYANIMANAGER->addArrayFrameAnimation("공용스킬움직임닫기", "공용스킬움직임", arr2, 12, 10, false, skillMoveClose);
	
	SOUNDMANAGER->addSound("길드", "사운드/길드.mp3", true, true);
	SOUNDMANAGER->addSound("스킬찍기", "사운드/스킬/스킬찍기.wav", false, false);
	SOUNDMANAGER->play("길드",0.1f);

	sorceressSkillInit();
	commonSkillInit();
	
	_menuChoice = 0;
	_guildState = GUILD;
	_menuState = SKILL;
	_skillChioceState = SORCERESS;
	_skillListChoice = 0;
	_skillListX1 = 0;
	_skillListX2 = 0;
	_commonSkillListX1 = 0;
	_commonSkillListX2 = 0;
	_skillMoveX = 0;
	_skillMoveXMax = 0;

	_sorceressSkillChoice = 0;
	_sorceressSkillList = MENTAL_ABSORB;

	_bSkillLeftMove = false;
	_bSkillRightMove = false;
	_bSkillListMoveOpen = true;
	_bSkillListMoveClose = false;

	_pointError = false;
	_lvError = false;
	_masterError = false;
	_skillLearn = true;

	_skillPoint = INIDATA->loadDataInterger("PlayerData", "Skill", "SKILLPOINT");
	_lv = INIDATA->loadDataInterger("PlayerData", "State", "LEVEL");
	return S_OK;
}
void guildScene::update(){
	KEYANIMANAGER->update();
	switch (_guildState){
	case GUILD:
		guild();
		break;
	case SKILL_CHOICE:
		skillChoice();
		break;
	case SORCERESS_SKILL:
		sorceressSkill();
		break;
	case COMMON_SKILL:
		commonSkill();
		break;
	case SORCERESS_CONFIRM:
	case COMMON_CONFIRM:
		confirm();
		break;
	}

	//스킬리스트 움직임 조절
	switch (_skillChioceState){
	case SORCERESS:
		if (!_bSkillListMoveOpen){
			if (_skillChioceState == SORCERESS || _skillChioceState == COMMON){
				_skillListX1 -= 4;
				_skillListX2 += 15;
				if (_skillListX2 > 1200) _skillListX2 = 1200;
				if (_skillListX1 < 50) _skillListX1 = 50;
			}
			else if (_skillChioceState == SKILL_CHOICE){
				_skillListX2 -= 15;
				if (_skillListX2 < 300) _skillListX2 = 300;
			}
		}

		if (_bSkillListMoveClose){
			if (_skillChioceState == SORCERESS || _skillChioceState == COMMON){
				_skillListX1 += 4;
				_skillListX2 -= 15;
				if (_skillListX2 < 300) _skillListX2 = 300;
				if (_skillListX1 > 300) _skillListX1 = 300;
			}
			else if (_skillChioceState == SKILL_CHOICE){
				_skillListX2 += 15;
				if (_skillListX2 < 300) _skillListX2 = 300;
			}
		}
		break;
	case COMMON:
		if (!_bSkillListMoveOpen){
			if (_skillChioceState == SORCERESS || _skillChioceState == COMMON){
				_skillListX1 -= 10;
				_skillListX2 += 4;
				if (_skillListX2 > 1200) _skillListX2 = 1200;
				if (_skillListX1 < 50) _skillListX1 = 50;
			}
			else if (_skillChioceState == SKILL_CHOICE){
				_skillListX2 -= 15;
				if (_skillListX2 < 300) _skillListX2 = 300;
			}
		}

		if (_bSkillListMoveClose){
			if (_skillChioceState == SORCERESS || _skillChioceState == COMMON){
				_skillListX1 += 10;
				_skillListX2 -= 4;
				if (_skillListX2 < 900) _skillListX2 = 900;
				if (_skillListX1 > 900) _skillListX1 = 900;
			}
			else if (_skillChioceState == SKILL_CHOICE){
				_skillListX2 += 15;
				if (_skillListX2 < 900) _skillListX2 = 900;
			}
		}
		break;
	}
	
}
void guildScene::render(){
	
	guildRender();
	skillChooseRender();
	confirmRender();

	
	
}
void guildScene::release(){
	
}

void guildScene::skillMoveOpen(void* obj){
	_bSkillListMoveOpen = true;
}

void guildScene::skillMoveClose(void* obj){
	_bSkillListMoveClose = false;
	_guildState = SKILL_CHOICE;

	_sorceressSkillChoice = 0;
	_skillMoveXMax = 0;
	_skillMoveX = 0;
}

void guildScene::guild(){
	if (KEYMANAGER->isOnceKeyDown(VK_UP)){
		_menuChoice -= 1;
		if (_menuChoice == -1) _menuChoice = 1;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
		_menuChoice += 1;
		if (_menuChoice == 2) _menuChoice = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('A')){
		switch (_menuState){
		case SKILL:
			_guildState = SKILL_CHOICE;
			break;
		case GUILDEXIT:
			KEYANIMANAGER->findAnimation("길드움직임")->stop();
			SOUNDMANAGER->allRemove();
			dataSave();
			SCENEMANAGER->changeScene("마을씬");
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('S')){

	}

	if (KEYMANAGER->isOnceKeyDown('Z')){

	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		//바로 나가기가 될수있게 설정
		
		_menuChoice = 1;
	}

	//가독성을 위해 사용
	switch (_menuChoice){
	case 0:
		_menuState = SKILL;
		break;
	case 1:
		_menuState = GUILDEXIT;
	}

}
void guildScene::skillChoice(){
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
		_skillListChoice -= 1;
		if (_skillListChoice == -1) _skillListChoice = 1;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
		_skillListChoice += 1;
		if (_skillListChoice == 2) _skillListChoice = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('A')){
		
		switch (_skillChioceState){
		case SORCERESS:
			_skillListX1 = 300;
			_skillListX2 = 300;
			_guildState = SORCERESS_SKILL;
			_bSkillListMoveOpen = false;
			KEYANIMANAGER->findAnimation("소서리스스킬리스트움직임")->start();
			break;
		case COMMON:
			_skillListX1 = 900;
			_skillListX2 = 900;
			_guildState = COMMON_SKILL;
			_bSkillListMoveOpen = false;
			KEYANIMANAGER->findAnimation("공용스킬움직임")->start();
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('S')){

	}

	if (KEYMANAGER->isOnceKeyDown('Z')){

	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		_menuChoice = 0;
		_guildState = GUILD;
	}

	//가독성을 위해 사용
	switch (_skillListChoice){
	case 0:
		_skillChioceState = SORCERESS;
		break;
	case 1:
		_skillChioceState = COMMON;
		break;
	}
}
void guildScene::sorceressSkill(){
	if (!(_bSkillLeftMove || _bSkillRightMove) && _bSkillListMoveOpen &&!_bSkillListMoveClose){
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
			_pointError = false;
			_lvError = false;
			_masterError = false;
			_sorceressSkillChoice -= 1;
			_bSkillLeftMove = true;
			_skillMoveXMax += 280;
			if (_skillMoveXMax > 0) _skillMoveXMax = 0;
			if (_sorceressSkillChoice == -1) _sorceressSkillChoice =0;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
			_pointError = false;
			_lvError = false;
			_masterError = false;
			_sorceressSkillChoice += 1;
			_bSkillRightMove = true;
			_skillMoveXMax -= 280;
			if (_skillMoveXMax < -3360) _skillMoveXMax = -3360;
			if (_sorceressSkillChoice == 13) _sorceressSkillChoice = 12;
		}
		//if (){
			if (KEYMANAGER->isOnceKeyDown('A')){
				if (_pointError || _lvError || _masterError){
					_pointError = false;
					_lvError = false;
					_masterError = false;
				}
				//스킬 포인트가 모자르면 뜨는 오류
				if (_skillPoint-_sorceressSkill[_sorceressSkillChoice].sKillPointCondition[_sorceressSkill[_sorceressSkillChoice].skillLV]<0){
					_pointError = true;
				}
				////레벨이 부족하면 뜨는 오류
				else if (_lv - _sorceressSkill[_sorceressSkillChoice].LVCondition[_sorceressSkill[_sorceressSkillChoice].skillLV] < 0){
					_lvError = true;
				}
				////스킬 다찍으면 뜨는 오류
				else if (_sorceressSkill[_sorceressSkillChoice].skillLV == _sorceressSkill[_sorceressSkillChoice].skillLVMax){
					_masterError = true;
				}
				else{
				_guildState = SORCERESS_CONFIRM;
				}

			}
		//}
		if (KEYMANAGER->isOnceKeyDown('S')){
			_pointError = false;
			_lvError = false;
			_masterError = false;
		}

		if (KEYMANAGER->isOnceKeyDown('Z')){
			_pointError = false;
			_lvError = false;
			_masterError = false;
		}
		if (_bSkillListMoveOpen){
			if (KEYMANAGER->isOnceKeyDown('X')){
				_pointError = false;
				_lvError = false;
				_masterError = false;
				_bSkillListMoveClose = true;
				if (!KEYANIMANAGER->findAnimation("소서리스스킬리스트움직임닫기")->isPlay())
					KEYANIMANAGER->findAnimation("소서리스스킬리스트움직임닫기")->start();
				
			}
		}

		if (_skillLearnConfirm){
			switch (_sorceressSkillList){
			case MENTAL_ABSORB:
				break;
			case EXTRACT:
				break;
			case CONCENTRATE:
				break;
			case MAGIC_POINT_UP:
				break;
			case ICE_PRISION:
				break;
			case PROTECTION:
				break;
			case GRAVITY:
				break;
			case THUNDER_CLOUD:
				break;
			case ROCK_PRESS:
				break;
			case BLIZZARD:
				break;
			case ANIMATE_SKELTON:
				break;
			case RAVITATION:
				break;
			case CREATE_FOOD:
				break;
			case CURSE:
				break;
			case PETRIFICATION:
				break;
			}
			_skillLearnConfirm = false;
		}
	}
	//가독성을 위해 사용
	switch (_sorceressSkillChoice){
	case 0:
		_sorceressSkillList = MENTAL_ABSORB;
		break;
	case 1:
		_sorceressSkillList = EXTRACT;
		break;
	case 2:
		_sorceressSkillList = CONCENTRATE;
		break;
	case 3:
		_sorceressSkillList = MAGIC_POINT_UP;
		break;
	case 4:
		_sorceressSkillList = ICE_PRISION;
		break;
	case 5:
		_sorceressSkillList = PROTECTION;
		break;
	case 6:
		_sorceressSkillList = GRAVITY;
		break;
	case 7:
		_sorceressSkillList = THUNDER_CLOUD;
		break;
	case 8:
		_sorceressSkillList = ROCK_PRESS;
		break;
	case 9:
		_sorceressSkillList = BLIZZARD;
		break;
	case 10:
		_sorceressSkillList = RAVITATION;
		break;
	case 11:
		_sorceressSkillList = CREATE_FOOD;
		break;
	case 12:
		_sorceressSkillList = PETRIFICATION;
		break;
	}

	if (_bSkillLeftMove){
		_skillMoveX += SKILLMOVEX;
		if (_skillMoveX > _skillMoveXMax){
			_skillMoveX = _skillMoveXMax;
			_bSkillLeftMove = false;
		}
	}

	if (_bSkillRightMove){
		_skillMoveX -= SKILLMOVEX;
		if (_skillMoveX < _skillMoveXMax){
			_skillMoveX = _skillMoveXMax;
			_bSkillRightMove = false;
		}
	}
}
void guildScene::commonSkill(){
	if (!(_bSkillLeftMove || _bSkillRightMove) && _bSkillListMoveOpen &&!_bSkillListMoveClose){
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
			_pointError = false;
			_lvError = false;
			_masterError = false;
			_commonSkillChoice -= 1;
			_bSkillLeftMove = true;
			_skillMoveXMax += 280;
			if (_skillMoveXMax > 0) _skillMoveXMax = 0;
			if (_commonSkillChoice == -1) _commonSkillChoice = 0;
		}

		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
			_pointError = false;
			_lvError = false;
			_masterError = false;
			_commonSkillChoice += 1;
			_bSkillRightMove = true;
			_skillMoveXMax -= 280;
			if (_skillMoveXMax < -280*3) _skillMoveXMax = -280*3;
			if (_commonSkillChoice == 4) _commonSkillChoice = 3;
		}
		//if (){
		if (KEYMANAGER->isOnceKeyDown('A')){
			if (_pointError || _lvError || _masterError){
				_pointError = false;
				_lvError = false;
				_masterError = false;
			}
			//스킬 포인트가 모자르면 뜨는 오류
			if (_skillPoint - _commonSkill[_commonSkillChoice].sKillPointCondition[_commonSkill[_commonSkillChoice].skillLV]<0){
				_pointError = true;
			}
			////레벨이 부족하면 뜨는 오류
			else if (_lv - _commonSkill[_commonSkillChoice].LVCondition[_commonSkill[_commonSkillChoice].skillLV] < 0){
				_lvError = true;
			}
			////스킬 다찍으면 뜨는 오류
			else if (_commonSkill[_commonSkillChoice].skillLV == _commonSkill[_commonSkillChoice].skillLVMax){
				_masterError = true;
			}
			else{
				_guildState = COMMON_CONFIRM;
			}

		}
		//}
		if (KEYMANAGER->isOnceKeyDown('S')){
			_pointError = false;
			_lvError = false;
			_masterError = false;
		}

		if (KEYMANAGER->isOnceKeyDown('Z')){
			_pointError = false;
			_lvError = false;
			_masterError = false;
		}
		if (_bSkillListMoveOpen){
			if (KEYMANAGER->isOnceKeyDown('X')){
				_pointError = false;
				_lvError = false;
				_masterError = false;
				_bSkillListMoveClose = true;
				if (!KEYANIMANAGER->findAnimation("공용스킬움직임닫기")->isPlay())
					KEYANIMANAGER->findAnimation("공용스킬움직임닫기")->start();

			}
		}

		if (_skillLearnConfirm){
			switch (_sorceressSkillList){
			case MENTAL_ABSORB:
				break;
			case EXTRACT:
				break;
			case CONCENTRATE:
				break;
			case MAGIC_POINT_UP:
				break;
			case ICE_PRISION:
				break;
			case PROTECTION:
				break;
			case GRAVITY:
				break;
			case THUNDER_CLOUD:
				break;
			case ROCK_PRESS:
				break;
			case BLIZZARD:
				break;
			case ANIMATE_SKELTON:
				break;
			case RAVITATION:
				break;
			case CREATE_FOOD:
				break;
			case CURSE:
				break;
			case PETRIFICATION:
				break;
			}
			_skillLearnConfirm = false;
		}
	}
	//가독성을 위해 사용
	switch (_sorceressSkillList){
	case 0:
		_sorceressSkillList = MENTAL_ABSORB;
		break;
	case 1:
		_sorceressSkillList = EXTRACT;
		break;
	case 2:
		_sorceressSkillList = CONCENTRATE;
		break;
	case 3:
		_sorceressSkillList = MAGIC_POINT_UP;
		break;
	case 4:
		_sorceressSkillList = ICE_PRISION;
		break;
	case 5:
		_sorceressSkillList = PROTECTION;
		break;
	case 6:
		_sorceressSkillList = GRAVITY;
		break;
	case 7:
		_sorceressSkillList = THUNDER_CLOUD;
		break;
	case 8:
		_sorceressSkillList = ROCK_PRESS;
		break;
	case 9:
		_sorceressSkillList = BLIZZARD;
		break;
	case 10:
		_sorceressSkillList = ANIMATE_SKELTON;
		break;
	case 11:
		_sorceressSkillList = RAVITATION;
		break;
	case 12:
		_sorceressSkillList = CREATE_FOOD;
		break;
	case 13:
		_sorceressSkillList = CURSE;
		break;
	case 14:
		_sorceressSkillList = PETRIFICATION;
		break;
	}

	if (_bSkillLeftMove){
		_skillMoveX += SKILLMOVEX;
		if (_skillMoveX > _skillMoveXMax){
			_skillMoveX = _skillMoveXMax;
			_bSkillLeftMove = false;
		}
	}

	if (_bSkillRightMove){
		_skillMoveX -= SKILLMOVEX;
		if (_skillMoveX < _skillMoveXMax){
			_skillMoveX = _skillMoveXMax;
			_bSkillRightMove = false;
		}
	}
}

void guildScene::sorceressSkillInit(){
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

}
void guildScene::commonSkillInit(){
	memset(_commonSkill, 0, sizeof(_commonSkill));

	_commonSkill[0].name = "히트 포인트 업";
	_commonSkill[0].LVCondition[0] = 1;
	_commonSkill[0].LVCondition[1] = 7;
	_commonSkill[0].LVCondition[2] = 13;
	_commonSkill[0].LVCondition[3] = 19;
	_commonSkill[0].LVCondition[4] = 25;
	_commonSkill[0].LVCondition[5] = 31;
	_commonSkill[0].LVCondition[6] = 38;
	_commonSkill[0].LVCondition[7] = 45;
	_commonSkill[0].LVCondition[8] = 52;
	_commonSkill[0].LVCondition[9] = 59;
	_commonSkill[0].sKillPointCondition[0] = 1;
	_commonSkill[0].sKillPointCondition[1] = 1;
	_commonSkill[0].sKillPointCondition[2] = 1;
	_commonSkill[0].sKillPointCondition[3] = 2;
	_commonSkill[0].sKillPointCondition[4] = 2;
	_commonSkill[0].sKillPointCondition[5] = 3;
	_commonSkill[0].sKillPointCondition[6] = 3;
	_commonSkill[0].sKillPointCondition[7] = 4;
	_commonSkill[0].sKillPointCondition[8] = 4;
	_commonSkill[0].sKillPointCondition[9] = 6;
	_commonSkill[0].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "hit_point_up");
	_commonSkill[0].skillLVMax = 10;
	_commonSkill[0].skillInfo = "HP 최대치가 증가한다";

	_commonSkill[1].name = "푸드 사으톨로지";
	_commonSkill[1].LVCondition[0] = 1;
	_commonSkill[1].LVCondition[1] = 11;
	_commonSkill[1].LVCondition[2] = 24;
	_commonSkill[1].LVCondition[3] = 37;
	_commonSkill[1].LVCondition[4] = 51;
	_commonSkill[1].sKillPointCondition[0] = 1;
	_commonSkill[1].sKillPointCondition[1] = 1;
	_commonSkill[1].sKillPointCondition[2] = 2;
	_commonSkill[1].sKillPointCondition[3] = 3;
	_commonSkill[1].sKillPointCondition[4] = 4;
	_commonSkill[1].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "food_psytology");;
	_commonSkill[1].skillLVMax = 5;
	_commonSkill[1].skillInfo = "음식의 회복량이 증가한다";

	_commonSkill[2].name = "메인테넌스";
	_commonSkill[2].LVCondition[0] = 1;
	_commonSkill[2].LVCondition[1] = 6;
	_commonSkill[2].LVCondition[2] = 13;
	_commonSkill[2].LVCondition[3] = 23;
	_commonSkill[2].LVCondition[4] = 34;
	_commonSkill[2].sKillPointCondition[0] = 1;
	_commonSkill[2].sKillPointCondition[1] = 1;
	_commonSkill[2].sKillPointCondition[2] = 2;
	_commonSkill[2].sKillPointCondition[3] = 3;
	_commonSkill[2].sKillPointCondition[4] = 4;
	_commonSkill[2].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "maintenance");;
	_commonSkill[2].skillLVMax = 5;
	_commonSkill[2].skillInfo = "아이템들을 더 사용 할 수 있다";

	_commonSkill[3].name = "아이템 유저";
	_commonSkill[3].LVCondition[0] = 1;
	_commonSkill[3].LVCondition[1] = 9;
	_commonSkill[3].LVCondition[2] = 16;
	_commonSkill[3].LVCondition[3] = 22;
	_commonSkill[3].LVCondition[4] = 29;
	_commonSkill[3].LVCondition[5] = 36;
	_commonSkill[3].LVCondition[6] = 44;
	_commonSkill[3].sKillPointCondition[0] = 1;
	_commonSkill[3].sKillPointCondition[1] = 1;
	_commonSkill[3].sKillPointCondition[2] = 2;
	_commonSkill[3].sKillPointCondition[3] = 2;
	_commonSkill[3].sKillPointCondition[4] = 3;
	_commonSkill[3].sKillPointCondition[5] = 3;
	_commonSkill[3].sKillPointCondition[6] = 5;
	_commonSkill[3].skillLV = INIDATA->loadDataInterger("PlayerData", "Skill", "item_user");
	_commonSkill[3].skillLVMax = 7;
	_commonSkill[3].skillInfo = "아이템 사용 후 체력을 회복한다";


}

void guildScene::guildRender(){
	///////////////스킬배울지 나갈지 보여주는 창/////////////////
	IMAGEMANAGER->findImage("길드움직임")->aniRender(getMemDC(), 0, 0, KEYANIMANAGER->findAnimation("길드움직임"));

	IMAGEMANAGER->findImage("길드간판")->render(getMemDC(), 0, -11);
	IMAGEMANAGER->findImage("길드마크")->render(getMemDC(), 210, 50);

	switch (_menuState){
	case SKILL:
		IMAGEMANAGER->findAlphaImage("스킬선택지2")->alphaRender(getMemDC(), 80, 280, 200);
		IMAGEMANAGER->findAlphaImage("나가기선택지1")->alphaRender(getMemDC(), 80, 350, 125);
		break;
	case GUILDEXIT:
		IMAGEMANAGER->findAlphaImage("스킬선택지1")->alphaRender(getMemDC(), 80, 280, 125);
		IMAGEMANAGER->findAlphaImage("나가기선택지2")->alphaRender(getMemDC(), 80, 350, 200);
		break;
	}
}
void guildScene::skillChooseRender(){
	//////////////////////////스킬창///////////////////////////
	if (_guildState != GUILD){
		IMAGEMANAGER->findImage("스킬창상단")->render(getMemDC(), 0, 0);
		IMAGEMANAGER->findAlphaImage("스킬창중단")->alphaRender(getMemDC(), 0, 147, 125);
		IMAGEMANAGER->findImage("스킬창하단")->render(getMemDC(), 0, 777);
	}


	switch (_guildState){
	case SKILL_CHOICE:	//소서리스 스킬을 배울지 공용 스킬을 배울지 보여주는 창
		switch (_skillChioceState){
		case SORCERESS:
			IMAGEMANAGER->findAlphaImage("소서리스스킬리스트")->alphaRender(getMemDC(), 300, 165, 255);
			IMAGEMANAGER->findAlphaImage("공통스킬리스트")->alphaRender(getMemDC(), 900, 165, 125);
			break;
		case COMMON:
			IMAGEMANAGER->findAlphaImage("소서리스스킬리스트")->alphaRender(getMemDC(), 300, 165, 125);
			IMAGEMANAGER->findAlphaImage("공통스킬리스트")->alphaRender(getMemDC(), 900, 165, 255);
			break;
		}
		break;

	case SORCERESS_SKILL:	//소서리스 스킬창
	case SORCERESS_CONFIRM:
		sorceressSkillRender();
		break;
	case COMMON_SKILL:		//공용 스킬창
	case COMMON_CONFIRM:
		commonSkillRender();
		break;
	}

	



}
void guildScene::sorceressSkillRender(){
	
	if (_bSkillListMoveOpen){
		//스킬 찍은 개수
		for (int i = _sorceressSkill[0].skillLV; i > 1; i--){
			int x = 670 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("멘탈앱소브")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[1].skillLV; i > 1; i--){
			int x = 950 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("엑스트랙트")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[2].skillLV; i > 1; i--){
			int x = 1230 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("콘센트레이트")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[3].skillLV; i > 1; i--){
			int x = 1510 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("매직포인트업")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[4].skillLV; i > 1; i--){
			int x = 1790 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("아이스프리즌")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[5].skillLV; i > 1; i--){
			int x = 2070 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("프로텍션4")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[6].skillLV; i > 1; i--){
			int x = 2350 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("그래비티")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[7].skillLV; i > 1; i--){
			int x = 2630 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("썬더클라우드")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[8].skillLV; i > 1; i--){
			int x = 2910 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("록프레스")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[9].skillLV; i > 1; i--){
			int x = 3190 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
					IMAGEMANAGER->findAlphaImage("블리자드4")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[10].skillLV; i > 1; i--){
			int x = 3470 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
				IMAGEMANAGER->findAlphaImage("레비테이션")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[11].skillLV; i > 1; i--){
			int x = 3750 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
				IMAGEMANAGER->findAlphaImage("크리에이트푸드")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}

		for (int i = _sorceressSkill[12].skillLV; i > 1; i--){
			int x = 4030 + _skillMoveX - (i - 1) * 20;
			if (x + 300 > 0 && x < WINSIZEX){
				IMAGEMANAGER->findAlphaImage("페트리피케이션")->alphaRender(getMemDC(), x, 300 - (i - 1) * 20, 255);
			}
		}


		int x;

		x = 670 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[0].skillLV==0)
				IMAGEMANAGER->findAlphaImage("멘탈앱소브")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("멘탈앱소브")->alphaRender(getMemDC(), x, 300, 170);
		}
		
		x = 950 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[1].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("엑스트랙트")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("엑스트랙트")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 1230 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[2].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("콘센트레이트")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("콘센트레이트")->alphaRender(getMemDC(), x, 300, 170);
		}
		
		x = 1510 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[3].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("매직포인트업")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("매직포인트업")->alphaRender(getMemDC(), x, 300, 170);
		}
		
		x = 1790 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[4].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("아이스프리즌")->alphaRender(getMemDC(),x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("아이스프리즌")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 2070 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[5].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("프로텍션4")->alphaRender(getMemDC(),x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("프로텍션4")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 2350 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[6].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("그래비티")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("그래비티")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 2630 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[7].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("썬더클라우드")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("썬더클라우드")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 2910 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[8].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("록프레스")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("록프레스")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 3190 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[9].skillLV == 0)
			IMAGEMANAGER->findAlphaImage("블리자드4")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("블리자드4")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 3470 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[10].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("레비테이션")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("레비테이션")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 3750 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[11].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("크리에이트푸드")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("크리에이트푸드")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 4030 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_sorceressSkill[12].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("페트리피케이션")->alphaRender(getMemDC(), x, 300, 20);
			else
				IMAGEMANAGER->findAlphaImage("페트리피케이션")->alphaRender(getMemDC(), x, 300, 170);
		}

		switch (_sorceressSkillList){
		case MENTAL_ABSORB:
			IMAGEMANAGER->findAlphaImage("멘탈앱소브")->alphaRender(getMemDC(), 670 + _skillMoveX, 300, 255);
			break;
		case EXTRACT:	
			IMAGEMANAGER->findAlphaImage("엑스트랙트")->alphaRender(getMemDC(), 950 + _skillMoveX, 300, 255);
			break;
		case CONCENTRATE:
			IMAGEMANAGER->findAlphaImage("콘센트레이트")->alphaRender(getMemDC(), 1230 + _skillMoveX, 300, 255);
			break;
		case MAGIC_POINT_UP:
			IMAGEMANAGER->findAlphaImage("매직포인트업")->alphaRender(getMemDC(), 1510 + _skillMoveX, 300, 255);
			break;
		case ICE_PRISION:
			IMAGEMANAGER->findAlphaImage("아이스프리즌")->alphaRender(getMemDC(), 1790 + _skillMoveX, 300, 255);
			break;
		case PROTECTION:
			IMAGEMANAGER->findAlphaImage("프로텍션4")->alphaRender(getMemDC(), 2070 + _skillMoveX, 300, 255);
			break;
		case GRAVITY:
			IMAGEMANAGER->findAlphaImage("그래비티")->alphaRender(getMemDC(), 2350 + _skillMoveX, 300, 255);
			break;
		case THUNDER_CLOUD:
			IMAGEMANAGER->findAlphaImage("썬더클라우드")->alphaRender(getMemDC(), 2630 + _skillMoveX, 300, 255);
			break;
		case ROCK_PRESS:
			IMAGEMANAGER->findAlphaImage("록프레스")->alphaRender(getMemDC(), 2910 + _skillMoveX, 300, 255);
			break;
		case BLIZZARD:
			IMAGEMANAGER->findAlphaImage("블리자드4")->alphaRender(getMemDC(), 3190 + _skillMoveX, 300, 255);
			break;
		case RAVITATION:
			IMAGEMANAGER->findAlphaImage("레비테이션")->alphaRender(getMemDC(), 3470 + _skillMoveX, 300, 255);
			break;
		case CREATE_FOOD:
			IMAGEMANAGER->findAlphaImage("크리에이트푸드")->alphaRender(getMemDC(), 3750 + _skillMoveX, 300, 255);
			break;
		case PETRIFICATION:
			IMAGEMANAGER->findAlphaImage("페트리피케이션")->alphaRender(getMemDC(), 4030 + _skillMoveX, 300, 255);
			break;
		}
	}
	if (!_bSkillListMoveClose){
		IMAGEMANAGER->findAlphaImage("소서리스스킬리스트")->alphaRender(getMemDC(), _skillListX1, 165, 255);
		IMAGEMANAGER->findImage("소서리스스킬리스트움직임")->aniRender(getMemDC(), _skillListX2, 165, KEYANIMANAGER->findAnimation("소서리스스킬리스트움직임"));
	}
	else{
		IMAGEMANAGER->findAlphaImage("소서리스스킬리스트")->alphaRender(getMemDC(), _skillListX1, 165, 255);
		IMAGEMANAGER->findImage("소서리스스킬리스트움직임")->aniRender(getMemDC(), _skillListX2, 165, KEYANIMANAGER->findAnimation("소서리스스킬리스트움직임닫기"));
	}

	if (_bSkillListMoveOpen && !_bSkillListMoveClose){
		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);

		char str[100];

		///////////////////////////습득조건//////////////////////////////
		font = CreateFont(50, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "습득 조건");
		TextOut(getMemDC(), 1240, 250, str, strlen(str));
		
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 129, 129));
		sprintf(str, "소비 스킬 포인트");
		TextOut(getMemDC(), 1240, 320, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "%d 포인트", _sorceressSkill[_sorceressSkillChoice].sKillPointCondition[_sorceressSkill[_sorceressSkillChoice].skillLV]);
		TextOut(getMemDC(), 1240, 350, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 0, 0));
		sprintf(str, "(현재: %d포인트)", _skillPoint);
		TextOut(getMemDC(), 1240, 380, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 129, 129));
		sprintf(str, "플레이어 LV");
		TextOut(getMemDC(), 1240, 450, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "LV%d 이상", _sorceressSkill[_sorceressSkillChoice].LVCondition[_sorceressSkill[_sorceressSkillChoice].skillLV]);
		TextOut(getMemDC(), 1240, 480, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 0, 0));
		sprintf(str, "(현재: LV%d)", _lv);
		TextOut(getMemDC(), 1240, 510, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		//////////////////////////////////////////////////////////////////////

		///////////////////스킬 이름 및 설명/////////////////////////////

		RECT rcText = { 0, 750, 1600, 850 };

		font = CreateFont(60,0,0,0,FW_NORMAL,false,false,false,DEFAULT_CHARSET,OUT_STROKE_PRECIS,CLIP_MASK,DRAFT_QUALITY,DEFAULT_PITCH | FF_SWISS,TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		DrawText(getMemDC(), _sorceressSkill[_sorceressSkillChoice].name.c_str(), _sorceressSkill[_sorceressSkillChoice].name.size(), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		rcText = { 0, 850, 1600, 900 };

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		DrawText(getMemDC(), _sorceressSkill[_sorceressSkillChoice].skillInfo.c_str(), _sorceressSkill[_sorceressSkillChoice].skillInfo.size(), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		if (_pointError){
			IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
			IMAGEMANAGER->findAlphaImage("스킬포인트부족")->render(getMemDC(), 0, 600);
		}
		else if (_lvError){
			IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
			IMAGEMANAGER->findAlphaImage("레벨부족")->render(getMemDC(), 0, 600);
		}
		else if (_masterError){
			IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
			IMAGEMANAGER->findAlphaImage("스킬마스터")->render(getMemDC(), 0, 600);
		}
	}
}
void guildScene::commonSkillRender(){
	if (_bSkillListMoveOpen){
		//스킬 찍은 개수
		for (int i = _commonSkill[0].skillLV; i > 1; i--){
			IMAGEMANAGER->findAlphaImage("히트포인트업")->alphaRender(getMemDC(), 670 + _skillMoveX - (i - 1) * 20, 300 - (i - 1) * 20, 255);
		}

		for (int i = _commonSkill[1].skillLV; i > 1; i--){
			IMAGEMANAGER->findAlphaImage("푸드사이톨로지")->alphaRender(getMemDC(), 950 + _skillMoveX - (i - 1) * 20, 300 - (i - 1) * 20, 255);
		}

		for (int i = _commonSkill[2].skillLV; i > 1; i--){
			IMAGEMANAGER->findAlphaImage("메인테넌스")->alphaRender(getMemDC(), 1230 + _skillMoveX - (i - 1) * 20, 300 - (i - 1) * 20, 255);
		}

		for (int i = _commonSkill[3].skillLV; i > 1; i--){
			IMAGEMANAGER->findAlphaImage("아이템유저")->alphaRender(getMemDC(), 1510 + _skillMoveX - (i - 1) * 20, 300 - (i - 1) * 20, 255);
		}

		
		int x;

		x = 670 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_commonSkill[0].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("히트포인트업")->alphaRender(getMemDC(), x, 300, 20);
			else
			IMAGEMANAGER->findAlphaImage("히트포인트업")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 950 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_commonSkill[1].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("푸드사이톨로지")->alphaRender(getMemDC(), x, 300, 20);
			else
			IMAGEMANAGER->findAlphaImage("푸드사이톨로지")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 1230 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_commonSkill[2].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("메인테넌스")->alphaRender(getMemDC(), x, 300, 20);
			else
			IMAGEMANAGER->findAlphaImage("메인테넌스")->alphaRender(getMemDC(), x, 300, 170);
		}

		x = 1510 + _skillMoveX;
		if (x + 300 > 0 && x < WINSIZEX){
			IMAGEMANAGER->findAlphaImage("흑백처리")->alphaRender(getMemDC(), x, 300, 255);
			if (_commonSkill[3].skillLV == 0)
				IMAGEMANAGER->findAlphaImage("아이템유저")->alphaRender(getMemDC(), x, 300, 20);
			else
			IMAGEMANAGER->findAlphaImage("아이템유저")->alphaRender(getMemDC(), x, 300, 170);
		}


		switch (_commonSkillChoice){
		case 0:
			IMAGEMANAGER->findAlphaImage("히트포인트업")->alphaRender(getMemDC(), 670 + _skillMoveX, 300, 255);
			break;
		case 1:
			IMAGEMANAGER->findAlphaImage("푸드사이톨로지")->alphaRender(getMemDC(), 950 + _skillMoveX, 300, 255);
			break;
		case 2:
			IMAGEMANAGER->findAlphaImage("메인테넌스")->alphaRender(getMemDC(), 1230 + _skillMoveX, 300, 255);
			break;
		case 3:
			IMAGEMANAGER->findAlphaImage("아이템유저")->alphaRender(getMemDC(), 1510 + _skillMoveX, 300, 255);
			break;
		}
	}
	
	if (!_bSkillListMoveClose){
		IMAGEMANAGER->findAlphaImage("공통스킬리스트")->alphaRender(getMemDC(), _skillListX1, 165, 255);
		IMAGEMANAGER->findImage("공용스킬움직임")->aniRender(getMemDC(), _skillListX2, 165, KEYANIMANAGER->findAnimation("공용스킬움직임"));
	}
	else{
		IMAGEMANAGER->findAlphaImage("공통스킬리스트")->alphaRender(getMemDC(), _skillListX1, 165, 255);
		IMAGEMANAGER->findImage("공용스킬움직임")->aniRender(getMemDC(), _skillListX2, 165, KEYANIMANAGER->findAnimation("공용스킬움직임닫기"));
	}

	if (_bSkillListMoveOpen && !_bSkillListMoveClose){
		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);

		char str[100];

		///////////////////////////습득조건//////////////////////////////
		font = CreateFont(50, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "습득 조건");
		TextOut(getMemDC(), 1240, 250, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 129, 129));
		sprintf(str, "소비 스킬 포인트");
		TextOut(getMemDC(), 1240, 320, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "%d 포인트", _commonSkill[_commonSkillChoice].sKillPointCondition[_commonSkill[_commonSkillChoice].skillLV]);
		TextOut(getMemDC(), 1240, 350, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 0, 0));
		sprintf(str, "(현재: %d포인트)", _skillPoint);
		TextOut(getMemDC(), 1240, 380, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 129, 129));
		sprintf(str, "플레이어 LV");
		TextOut(getMemDC(), 1240, 450, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "LV%d 이상", _commonSkill[_commonSkillChoice].LVCondition[_commonSkill[_commonSkillChoice].skillLV]);
		TextOut(getMemDC(), 1240, 480, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		font = CreateFont(20, 12, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);

		SetTextColor(getMemDC(), RGB(255, 0, 0));
		sprintf(str, "(현재: LV%d)", _lv);
		TextOut(getMemDC(), 1240, 510, str, strlen(str));

		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		//////////////////////////////////////////////////////////////////////

		///////////////////스킬 이름 및 설명/////////////////////////////

		RECT rcText = { 0, 750, 1600, 850 };

		font = CreateFont(60, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		DrawText(getMemDC(), _commonSkill[_commonSkillChoice].name.c_str(), _commonSkill[_commonSkillChoice].name.size(), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);

		rcText = { 0, 850, 1600, 900 };

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		DrawText(getMemDC(), _commonSkill[_commonSkillChoice].skillInfo.c_str(), _commonSkill[_commonSkillChoice].skillInfo.size(), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}

	if (_pointError){
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("스킬포인트부족")->render(getMemDC(), 0, 600);
	}
	else if (_lvError){
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("레벨부족")->render(getMemDC(), 0, 600);
	}
	else if (_masterError){
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("스킬마스터")->render(getMemDC(), 0, 600);
	}
}

void guildScene::confirmRender(){
	

	//소서리스 스킬을 배울지 확인하는 렌더
	switch (_guildState){
	case SORCERESS_CONFIRM:
	case COMMON_CONFIRM:
		IMAGEMANAGER->findAlphaImage("흑백처리2")->alphaRender(getMemDC(), 0, 0, 200);
		IMAGEMANAGER->findAlphaImage("대화상자")->render(getMemDC(), 0, 300);
		if (_skillLearn){
			IMAGEMANAGER->findImage("yes_check")->render(getMemDC(), 500, 480);
			IMAGEMANAGER->findImage("no")->render(getMemDC(), 900, 500);
		}
		else{
			IMAGEMANAGER->findImage("yes")->render(getMemDC(), 500, 500);
			IMAGEMANAGER->findImage("no_check")->render(getMemDC(), 900, 480);
		}

		HFONT oldFont;
		HFONT font;
		SetBkMode(getMemDC(), TRANSPARENT);

		char str[100];

		RECT rcText = { 0, 340, 1600, 390 };

		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "스킬을 배우시겠습니까?");
		DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
	}

	
}

void guildScene::confirm(){
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT)){
		if (_skillLearn)_skillLearn = false;
		else _skillLearn = true;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)){
		if (_skillLearn)_skillLearn = false;
		else _skillLearn = true;
	}

	if (KEYMANAGER->isOnceKeyDown('A')){
		if (_skillLearn){
			_skillLearnConfirm = true;
			switch (_skillChioceState){
			case SORCERESS:
				_guildState = SORCERESS_SKILL;
				_skillPoint -= _sorceressSkill[_sorceressSkillChoice].sKillPointCondition[_sorceressSkill[_sorceressSkillChoice].skillLV];
				_sorceressSkill[_sorceressSkillChoice].skillLV++;
				SOUNDMANAGER->play("스킬찍기", 0.1f);
				break;
			case COMMON:
				_guildState = COMMON_SKILL;
				_skillPoint -= _commonSkill[_commonSkillChoice].sKillPointCondition[_commonSkill[_commonSkillChoice].skillLV];
				_commonSkill[_commonSkillChoice].skillLV++;
				SOUNDMANAGER->play("스킬찍기", 0.1f);
				break;
			}
		}
		switch (_skillChioceState){
		case SORCERESS:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON:
			_guildState = COMMON_SKILL;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		_skillLearn = false;
	}
}


void guildScene::error(){
	if (KEYMANAGER->isOnceKeyDown('A')){
		switch (_guildState){
		case SORCERESS_SKILL_POINT_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_LV_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_SKILL_MASTER_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON_SKILL_POINT_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_LV_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_SKILL_MASTER_ERROR:
			_guildState = COMMON_SKILL;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('S')){
		switch (_guildState){
		case SORCERESS_SKILL_POINT_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_LV_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_SKILL_MASTER_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON_SKILL_POINT_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_LV_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_SKILL_MASTER_ERROR:
			_guildState = COMMON_SKILL;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('Z')){
		switch (_guildState){
		case SORCERESS_SKILL_POINT_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_LV_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_SKILL_MASTER_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON_SKILL_POINT_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_LV_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_SKILL_MASTER_ERROR:
			_guildState = COMMON_SKILL;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('X')){
		switch (_guildState){
		case SORCERESS_SKILL_POINT_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_LV_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case SORCERESS_SKILL_MASTER_ERROR:
			_guildState = SORCERESS_SKILL;
			break;
		case COMMON_SKILL_POINT_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_LV_ERROR:
			_guildState = COMMON_SKILL;
			break;
		case COMMON_SKILL_MASTER_ERROR:
			_guildState = COMMON_SKILL;
			break;
		}
	}
}

void guildScene::errorRender(){
	RECT rcText = { 0, 340, 1600, 390 };
	HFONT oldFont;
	HFONT font;
	SetBkMode(getMemDC(), TRANSPARENT);

	char str[100];

	IMAGEMANAGER->findAlphaImage("대화상자")->render(getMemDC(), 0, 300);

	switch (_guildState){
	case SORCERESS_SKILL_POINT_ERROR :
	case COMMON_SKILL_POINT_ERROR:
		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "스킬 포인트가 부족합니다.");
		DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	case SORCERESS_LV_ERROR:
	case COMMON_LV_ERROR:
		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "레벨이 낮습니다.");
		DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	case SORCERESS_SKILL_MASTER_ERROR:
	case COMMON_SKILL_MASTER_ERROR:
		font = CreateFont(30, 0, 0, 0, FW_NORMAL, false, false, false, DEFAULT_CHARSET, OUT_STROKE_PRECIS, CLIP_MASK, DRAFT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("휴먼굴림"));
		oldFont = (HFONT)SelectObject(getMemDC(), font);
		SetTextColor(getMemDC(), RGB(255, 255, 255));
		sprintf(str, "더이상 스킬을 배울수 없습니다.");
		DrawText(getMemDC(), str, strlen(str), &rcText, DT_LEFT | DT_CENTER | DT_SINGLELINE);
		SelectObject(getMemDC(), oldFont);
		DeleteObject(font);
		break;
	
	}
	
}

void guildScene::dataSave(){
	char str1[50];
	INIDATA->addData("Position", "X", INIDATA->loadDataString("PlayerData", "Position", "X").c_str());
	INIDATA->addData("Position", "Y", INIDATA->loadDataString("PlayerData", "Position", "Y").c_str());
	INIDATA->addData("Position", "그림자X", INIDATA->loadDataString("PlayerData", "Position", "그림자X").c_str());
	INIDATA->addData("Position", "그림자Y", INIDATA->loadDataString("PlayerData", "Position", "그림자Y").c_str());
	INIDATA->addData("Position", "절대좌표X", INIDATA->loadDataString("PlayerData", "Position", "절대좌표X").c_str());
	INIDATA->addData("Position", "절대좌표Y", INIDATA->loadDataString("PlayerData", "Position", "절대좌표Y").c_str());
	INIDATA->addData("Position", "성X", INIDATA->loadDataString("PlayerData", "Position", "성X").c_str());
	INIDATA->addData("Position", "성Y", INIDATA->loadDataString("PlayerData", "Position", "성Y").c_str());
	INIDATA->addData("Position", "마을1X", INIDATA->loadDataString("PlayerData", "Position", "마을1X").c_str());
	INIDATA->addData("Position", "마을1Y", INIDATA->loadDataString("PlayerData", "Position", "마을1Y").c_str());
	INIDATA->addData("Position", "마을2X", INIDATA->loadDataString("PlayerData", "Position", "마을2X").c_str());
	INIDATA->addData("Position", "마을2Y", INIDATA->loadDataString("PlayerData", "Position", "마을2Y").c_str());
	INIDATA->addData("Position", "마을3X", INIDATA->loadDataString("PlayerData", "Position", "마을3X").c_str());
	INIDATA->addData("Position", "마을3Y", INIDATA->loadDataString("PlayerData", "Position", "마을3Y").c_str());
	INIDATA->addData("Position", "마을4X", INIDATA->loadDataString("PlayerData", "Position", "마을4X").c_str());
	INIDATA->addData("Position", "마을4Y", INIDATA->loadDataString("PlayerData", "Position", "마을4Y").c_str());
	INIDATA->addData("Position", "마을5X", INIDATA->loadDataString("PlayerData", "Position", "마을5X").c_str());
	INIDATA->addData("Position", "마을5Y", INIDATA->loadDataString("PlayerData", "Position", "마을5Y").c_str());
	INIDATA->addData("Position", "루카인X", INIDATA->loadDataString("PlayerData", "Position", "루카인X").c_str());

	string str = INIDATA->loadDataString("PlayerData", "State", "LEVEL").c_str();
	INIDATA->addData("State", "LEVEL", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "EXP").c_str();
	INIDATA->addData("State", "EXP", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "HP").c_str();
	INIDATA->addData("State", "HP", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "MP").c_str();
	INIDATA->addData("State", "MP", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "STR").c_str();
	INIDATA->addData("State", "STR", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "INT").c_str();
	INIDATA->addData("State", "INT", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "CON").c_str();
	INIDATA->addData("State", "CON", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "MGR").c_str();
	INIDATA->addData("State", "MGR", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "DEX").c_str();
	INIDATA->addData("State", "DEX", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "State", "LUC").c_str();
	INIDATA->addData("State", "LUC", str.c_str());
	INIDATA->addData("State", "Money", INIDATA->loadDataString("PlayerData","State","Money").c_str());

	//가방	-- 던전에서 사용할 아이템을 등록
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag1").c_str();
	INIDATA->addData("Bag", "bag1", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag2").c_str();
	INIDATA->addData("Bag", "bag2", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag3").c_str();
	INIDATA->addData("Bag", "bag3", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag4").c_str();
	INIDATA->addData("Bag", "bag4", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag5").c_str();
	INIDATA->addData("Bag", "bag5", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag6").c_str();
	INIDATA->addData("Bag", "bag6", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag7").c_str();
	INIDATA->addData("Bag", "bag7", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Bag", "bag8").c_str();
	INIDATA->addData("Bag", "bag8", str.c_str());

	//스킬
	char str3[50];
	sprintf(str3, "%d", _skillPoint);
	INIDATA->addData("Skill", "SKILLPOINT", str3);
	sprintf(str3,"%d",_sorceressSkill[0].skillLV);
	INIDATA->addData("Skill", "mental_absorb", str3);
	sprintf(str3, "%d", _sorceressSkill[1].skillLV);
	INIDATA->addData("Skill", "extract", str3);
	sprintf(str3, "%d", _sorceressSkill[2].skillLV);
	INIDATA->addData("Skill", "concentrate", str3);
	sprintf(str3, "%d", _sorceressSkill[3].skillLV);
	INIDATA->addData("Skill", "magic_point_up", str3);
	sprintf(str3, "%d", _sorceressSkill[4].skillLV);
	INIDATA->addData("Skill", "ice_prision", str3);
	sprintf(str3, "%d", _sorceressSkill[5].skillLV);
	INIDATA->addData("Skill", "protection", str3);
	sprintf(str3, "%d", _sorceressSkill[6].skillLV);
	INIDATA->addData("Skill", "gravity", str3);
	sprintf(str3, "%d", _sorceressSkill[7].skillLV);
	INIDATA->addData("Skill", "thunder_cloud", str3);
	sprintf(str3, "%d", _sorceressSkill[8].skillLV);
	INIDATA->addData("Skill", "rock_press", str3);
	sprintf(str3, "%d", _sorceressSkill[9].skillLV);
	INIDATA->addData("Skill", "blizzard", str3);
	sprintf(str3, "%d", _sorceressSkill[10].skillLV);
	INIDATA->addData("Skill", "ravitation", str3);
	sprintf(str3, "%d", _sorceressSkill[11].skillLV);
	INIDATA->addData("Skill", "create_food", str3);
	sprintf(str3, "%d", _sorceressSkill[12].skillLV);
	INIDATA->addData("Skill", "petrification", str3);
	sprintf(str3, "%d", _commonSkill[0].skillLV);
	INIDATA->addData("Skill", "hit_point_up", str3);
	sprintf(str3, "%d", _commonSkill[1].skillLV);
	INIDATA->addData("Skill", "food_psytology", str3);
	sprintf(str3, "%d", _commonSkill[2].skillLV);
	INIDATA->addData("Skill", "maintenance", str3);
	sprintf(str3, "%d", _commonSkill[3].skillLV);
	INIDATA->addData("Skill", "item_user", str3);


	char str2[30];
	INIDATA->addData("마카로프의 스태프", "num", INIDATA->loadDataString("PlayerData","마카로프의 스태프","num").c_str());
	INIDATA->addData("마카로프의 스태프", "currentCon", INIDATA->loadDataString("PlayerData", "마카로프의 스태프", "currentCon").c_str());
	INIDATA->addData("문라이트 스태프", "num", INIDATA->loadDataString("PlayerData","문라이트 스태프","num").c_str());
	INIDATA->addData("이그니 스태프", "num", INIDATA->loadDataString("PlayerData","이그니 스태프","num").c_str());
	INIDATA->addData("크라운 스태프", "num", INIDATA->loadDataString("PlayerData","크라운 스태프","num").c_str());
	INIDATA->addData("크라운 스태프", "seal", INIDATA->loadDataString("PlayerData","크라운 스태프","seal").c_str());
	INIDATA->addData("붉은 망토", "num", INIDATA->loadDataString("PlayerData","붉은 망토","num").c_str());
	INIDATA->addData("마법사 망토", "num", INIDATA->loadDataString("PlayerData","마법사 망토","num").c_str());
	INIDATA->addData("대마법사 망토", "num", INIDATA->loadDataString("PlayerData","대마법사 망토","num").c_str());
	INIDATA->addData("대마법사 망토", "seal", INIDATA->loadDataString("PlayerData","대마법사 망토","seal").c_str());
	INIDATA->addData("가죽 장갑", "num", INIDATA->loadDataString("PlayerData", "가죽 장갑", "num").c_str());
	INIDATA->addData("요정 장갑", "num", INIDATA->loadDataString("PlayerData", "요정 장갑", "num").c_str());
	INIDATA->addData("가죽 신발", "num", INIDATA->loadDataString("PlayerData", "가죽 신발", "num").c_str());
	INIDATA->addData("마법사 신발", "num", INIDATA->loadDataString("PlayerData","마법사 신발","num").c_str());
	INIDATA->addData("에메랄드 귀거리", "num", INIDATA->loadDataString("PlayerData", "에메랄드 귀거리", "num").c_str());
	INIDATA->addData("요정눈물 귀거리", "num", INIDATA->loadDataString("PlayerData", "요정눈물 귀거리", "num").c_str());
	INIDATA->addData("A룬", "num", INIDATA->loadDataString("PlayerData", "A룬", "num").c_str());
	INIDATA->addData("B룬", "num", INIDATA->loadDataString("PlayerData", "B룬", "num").c_str());
	INIDATA->addData("C룬", "num", INIDATA->loadDataString("PlayerData", "C룬", "num").c_str());
	INIDATA->addData("D룬", "num", INIDATA->loadDataString("PlayerData", "D룬", "num").c_str());
	INIDATA->addData("E룬", "num", INIDATA->loadDataString("PlayerData", "E룬", "num").c_str());
	INIDATA->addData("F룬", "num", INIDATA->loadDataString("PlayerData", "F룬", "num").c_str());
	INIDATA->addData("요정의 물약", "num", INIDATA->loadDataString("PlayerData","요정의 물약","num").c_str());


	if (_sorceressSkill[4].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("아이스 프리즌의 서", "num", str3);
	}
	if (_sorceressSkill[5].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("프로텍션의 서", "num", str3);
	}
	if (_sorceressSkill[6].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("그래비티의 서", "num", str3);
	}
	if (_sorceressSkill[7].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("썬더 클라우드의 서", "num", str3);
	}
	if (_sorceressSkill[8].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("록 프레스의 서", "num", str3);
	}
	if (_sorceressSkill[9].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("블리자드의 서", "num", str3);
	}
	if (_sorceressSkill[11].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("크리에이트 푸드의 서", "num", str3);
	}
	if (_sorceressSkill[12].skillLV > 0){
		sprintf(str3, "%d", 3);
		INIDATA->addData("페트리피케이션의 서", "num", str3);
	}

	//탈리즈만
	str = INIDATA->loadDataString("PlayerData", "Talizman", "red").c_str();
	INIDATA->addData("Talizman", "red", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "orange").c_str();
	INIDATA->addData("Talizman", "orange", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "yellow").c_str();
	INIDATA->addData("Talizman", "yellow", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "green").c_str();
	INIDATA->addData("Talizman", "green", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "skyblue").c_str();
	INIDATA->addData("Talizman", "skyblue", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "blue").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "pupple").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "white").c_str();
	INIDATA->addData("Talizman", "white", str.c_str());
	str = INIDATA->loadDataString("PlayerData", "Talizman", "black").c_str();
	INIDATA->addData("Talizman", "black", str.c_str());

	INIDATA->iniSave("PlayerData");
}