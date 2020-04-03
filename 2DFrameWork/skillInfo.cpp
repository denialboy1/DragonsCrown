#include "stdafx.h"
#include "skillInfo.h"


skillInfo::skillInfo()
{
}


skillInfo::~skillInfo()
{
}


HRESULT skillInfo::init(){
	IMAGEMANAGER->addAlphaImage("bgSkillInfo", "이미지/menu/스킬/스킬확인.bmp", 1600, 900, true, RGB(255, 0, 255));

	//소서리스스킬
	IMAGEMANAGER->addAlphaImage("멘탈앱소브1", "이미지/마을/길드/멘탈앱소브.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("엑스트랙트1", "이미지/마을/길드/엑스트랙트.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("콘센트레이트1", "이미지/마을/길드/콘센트레이트.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("매직포인트업1", "이미지/마을/길드/매직포인트업.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("아이스프리즌1", "이미지/마을/길드/아이스프리즌.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("프로텍션1", "이미지/마을/길드/프로텍션.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("그래비티1", "이미지/마을/길드/그래비티.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("썬더클라우드1", "이미지/마을/길드/썬더클라우드.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("록프레스1", "이미지/마을/길드/록프레스.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("블리자드1", "이미지/마을/길드/블리자드.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("레비테이션1", "이미지/마을/길드/레비테이션.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("크리에이트푸드1", "이미지/마을/길드/크리에이트푸드.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("페트리피케이션1", "이미지/마을/길드/페트리피케이션.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);

	//공용 스킬
	IMAGEMANAGER->addAlphaImage("히트포인트업1", "이미지/마을/길드/히트포인트업.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("푸드사이톨로지1", "이미지/마을/길드/푸드사이톨로지.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("메인테넌스1", "이미지/마을/길드/메인테넌스.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("아이템유저1", "이미지/마을/길드/아이템유저.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);

	//스킬정보 선택지
	IMAGEMANAGER->addAlphaImage("스킬정보선택지1", "이미지/menu/스킬/스킬정보선택지1.bmp", 1400, 90, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("스킬정보선택지2", "이미지/menu/스킬/스킬정보선택지2.bmp", 1400, 90, true, RGB(255, 0, 255));


	_skill = new skill;
	_skill->init();

	_currentWhich = 0;
	_currentAlpha = 255;
	_currentReverse = 1;
	_botFrameCursor = 0;
	_botFrameMoveY = 0;
	return S_OK;
}
void skillInfo::update(){
	if (KEYMANAGER->isOnceKeyDown(VK_UP)){
		_currentWhich -= 1;
		if (_currentWhich < -1) { _currentWhich = -1; }
		if (150 + _botFrameCursor * 60 > 150){ _botFrameCursor--; }
		else{
			if (_currentWhich > -1)
				_botFrameMoveY -= 60;
		}
		if (_currentWhich == -1) _currentWhich = 0;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){

		_currentWhich += 1;
		if (_currentWhich >= 17) { _currentWhich = 17; }
		if (_botFrameCursor == 4){
			if (_currentWhich < 17){ _botFrameMoveY += 60;  }
		}
		if (150 + _botFrameCursor * 60 < 150 + 4 * 60){ _botFrameCursor++; }
		if (_currentWhich == 17) _currentWhich = 16;
	}
}
void skillInfo::render(){
	IMAGEMANAGER->findAlphaImage("bgSkillInfo")->alphaRender(getMemDC(), 200);

	//선택지 배경
	for (int i = 0; i < 19; i++){
		if ((150 <= 150 + i * 60 - _botFrameMoveY) && (150 + i * 60 - _botFrameMoveY < 450)){
			IMAGEMANAGER->findAlphaImage("스킬정보선택지1")->alphaRender(getMemDC(), 100, 150 + i * 60 - _botFrameMoveY, 255);
		}
	}


	IMAGEMANAGER->findAlphaImage("스킬정보선택지2")->alphaRender(getMemDC(), 100, 150 + _botFrameCursor * 60, 255);

	HFONT hFont, oldFont;
	char str[100];
	//선택지 글자
	for (int i = 0; i < 20; i++){
		if ((150 <= 150 + i * 60 - _botFrameMoveY) && (150 + i * 60 - _botFrameMoveY < 450)){
			SetBkMode(getMemDC(), TRANSPARENT);
			hFont = CreateFont(40, 20, 0, 0, 10, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), hFont);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			//스킬 이름
			TextOut(getMemDC(), 400, 175 + i * 60 - _botFrameMoveY, _skill->getSorceressSkill()[i].name.c_str(), _skill->getSorceressSkill()[i].name.size());
			//스킬 레벨
			sprintf(str, "LV %d", _skill->getSorceressSkill()[i].skillLV);
			TextOut(getMemDC(), 1200, 175 + i * 60 - _botFrameMoveY, str, strlen(str));

		}
	}

	//아래 프레임
	switch (_currentWhich){
	case 0:
		IMAGEMANAGER->findAlphaImage("멘탈앱소브1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[0].name.c_str(), _skill->getSorceressSkill()[0].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[0].skillInfo.c_str(), _skill->getSorceressSkill()[0].skillInfo.size());
		break;
	case 1:
		IMAGEMANAGER->findAlphaImage("엑스트랙트1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[1].name.c_str(), _skill->getSorceressSkill()[1].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[1].skillInfo.c_str(), _skill->getSorceressSkill()[1].skillInfo.size());
		break;
	case 2:
		IMAGEMANAGER->findAlphaImage("콘센트레이트1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[2].name.c_str(), _skill->getSorceressSkill()[2].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[2].skillInfo.c_str(), _skill->getSorceressSkill()[2].skillInfo.size());
		break;
	case 3:
		IMAGEMANAGER->findAlphaImage("매직포인트업1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[3].name.c_str(), _skill->getSorceressSkill()[3].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[3].skillInfo.c_str(), _skill->getSorceressSkill()[3].skillInfo.size());
		break;
	case 4:
		IMAGEMANAGER->findAlphaImage("아이스프리즌1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[4].name.c_str(), _skill->getSorceressSkill()[4].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[4].skillInfo.c_str(), _skill->getSorceressSkill()[4].skillInfo.size());
		break;
	case 5:
		IMAGEMANAGER->findAlphaImage("프로텍션1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[5].name.c_str(), _skill->getSorceressSkill()[5].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[5].skillInfo.c_str(), _skill->getSorceressSkill()[5].skillInfo.size());
		break;
	case 6:
		IMAGEMANAGER->findAlphaImage("그래비티1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[6].name.c_str(), _skill->getSorceressSkill()[6].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[6].skillInfo.c_str(), _skill->getSorceressSkill()[6].skillInfo.size());
		break;
	case 7:
		IMAGEMANAGER->findAlphaImage("썬더클라우드1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[7].name.c_str(), _skill->getSorceressSkill()[7].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[7].skillInfo.c_str(), _skill->getSorceressSkill()[7].skillInfo.size());
		break;
	case 8:
		IMAGEMANAGER->findAlphaImage("록프레스1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[8].name.c_str(), _skill->getSorceressSkill()[8].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[8].skillInfo.c_str(), _skill->getSorceressSkill()[8].skillInfo.size());
		break;
	case 9:
		IMAGEMANAGER->findAlphaImage("블리자드1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[9].name.c_str(), _skill->getSorceressSkill()[9].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[9].skillInfo.c_str(), _skill->getSorceressSkill()[9].skillInfo.size());
		break;
	case 10:
		IMAGEMANAGER->findAlphaImage("레비테이션1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[10].name.c_str(), _skill->getSorceressSkill()[10].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[10].skillInfo.c_str(), _skill->getSorceressSkill()[10].skillInfo.size());
		break;
	case 11:
		IMAGEMANAGER->findAlphaImage("크리에이트푸드1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[11].name.c_str(), _skill->getSorceressSkill()[11].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[11].skillInfo.c_str(), _skill->getSorceressSkill()[11].skillInfo.size());
		break;
	case 12:
		IMAGEMANAGER->findAlphaImage("페트리피케이션1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[12].name.c_str(), _skill->getSorceressSkill()[12].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[12].skillInfo.c_str(), _skill->getSorceressSkill()[12].skillInfo.size());
		break;
	case 13:
		IMAGEMANAGER->findAlphaImage("히트포인트업1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[13].name.c_str(), _skill->getSorceressSkill()[13].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[13].skillInfo.c_str(), _skill->getSorceressSkill()[13].skillInfo.size());
		break;
	case 14:
		IMAGEMANAGER->findAlphaImage("푸드사이톨로지1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[14].name.c_str(), _skill->getSorceressSkill()[14].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[14].skillInfo.c_str(), _skill->getSorceressSkill()[14].skillInfo.size());
		break;
	case 15:
		IMAGEMANAGER->findAlphaImage("메인테넌스1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[15].name.c_str(), _skill->getSorceressSkill()[15].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[15].skillInfo.c_str(), _skill->getSorceressSkill()[15].skillInfo.size());
		break;
	case 16:
		IMAGEMANAGER->findAlphaImage("아이템유저1")->render(getMemDC(), 100, 520);
		TextOut(getMemDC(), 400, 620, _skill->getSorceressSkill()[16].name.c_str(), _skill->getSorceressSkill()[16].name.size());
		TextOut(getMemDC(), 430, 720, _skill->getSorceressSkill()[16].skillInfo.c_str(), _skill->getSorceressSkill()[16].skillInfo.size());
		break;
	}

	SelectObject(getMemDC(), oldFont);
	DeleteObject(hFont);
}
void skillInfo::release(){}