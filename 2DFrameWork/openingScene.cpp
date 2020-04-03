#include "stdafx.h"
#include "openingScene.h"



openingScene::openingScene()
{
}


openingScene::~openingScene()
{
}

HRESULT openingScene::init(){
	//동영상 초기화
	if (getHVideo()){
		MCIWndClose(getHVideo());
		MCIWndDestroy(getHVideo());
		setHVideo(0);
	}
	setHVideo(MCIWndCreateA(_hWnd, _hInstance, MCIWNDF_NOMENU | MCIWNDF_NOOPEN | MCIWNDF_NOPLAYBAR | MCIWNDF_NOTIFYALL, "동영상/오프닝.wmv"));
	SetWindowPos(getHVideo(), NULL, 0, 0, WINSIZEX, WINSIZEY, NULL);
	if (getHVideo()){
		MCIWndPlay(getHVideo());
	}

	//사운드 초기화
	SOUNDMANAGER->addSound("오프닝", "사운드/opening.mp3", true, true);
	SOUNDMANAGER->addSound("saveload", "사운드/저장.mp3", true, true);
	SOUNDMANAGER->play("오프닝",0.1f);

	//모험의 기록 이미지 불러오기 
	IMAGEMANAGER->addImage("세이브책1", "이미지/마을/주점/세이브/세이브1.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addImage("세이브책2", "이미지/마을/주점/세이브/세이브2.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addImage("세이브책3", "이미지/마을/주점/세이브/세이브3.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addImage("큰세이브책1", "이미지/마을/주점/세이브/세이브1.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addImage("큰세이브책2", "이미지/마을/주점/세이브/세이브2.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addImage("큰세이브책3", "이미지/마을/주점/세이브/세이브3.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	IMAGEMANAGER->addAlphaImage("세이브", "이미지/마을/주점/세이브/세이브.bmp", 1600, 900, true, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("세이브위치선택", "이미지/마을/주점/세이브/세이브위치선택1.bmp", 1505, 206, true, RGB(255, 0, 255));

	_saveChoice = 0;
	_saveState = SAVE1;

	_windowState = OPENING;
	return S_OK;
}
void openingScene::update(){
	if (_windowState == OPENING){
		//스킵 기능
		if (KEYMANAGER->isOnceKeyDown('A')){
			_windowState = SAVELOAD;
			////동영상 스킵
			MCIWndClose(getHVideo());
			MCIWndDestroy(getHVideo());
			setHVideo(0);
			SOUNDMANAGER->stop("오프닝");
			SOUNDMANAGER->play("saveload", 0.1f);
		}
	}

	if (_windowState == SAVELOAD){
		if (KEYMANAGER->isOnceKeyDown(VK_UP)){
			_saveChoice -= 1;
			if (_saveChoice == -1){ _saveChoice = 2; }
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN)){
			_saveChoice += 1;
			if (_saveChoice == 3){ _saveChoice = 0; }
		}

		switch (_saveChoice){
		case 0:
			_saveState = SAVE1;
			break;
		case 1:
			_saveState = SAVE2;
			break;
		case 2:
			_saveState = SAVE3;
			break;
		}

		if (KEYMANAGER->isOnceKeyDown('A')){
			string str;
			int a = 0;
			switch (_saveState){
			case SAVE1:
				if (INIDATA->loadDataInterger("save1", "State", "LEVEL") < 1){
					createData("save1");
				}
				else{
					loadData("save1");
				}
				break;
			case SAVE2:
				if (INIDATA->loadDataInterger("save2", "State", "LEVEL") < 1){
					createData("save2");
				}
				else{
					loadData("save2");
				}
				break;
			case SAVE3:
				if (INIDATA->loadDataInterger("save3", "State", "LEVEL") < 1){
					createData("save3");
				}
				else{
					loadData("save3");
				}
				break;
			}
			////사운드
			SOUNDMANAGER->stop("saveload");
			SOUNDMANAGER->allRemove();
			SCENEMANAGER->changeScene("마을로딩씬");
		}
	}
}
void openingScene::render(){
	gameNode::render();
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	IMAGEMANAGER->findAlphaImage("세이브")->alphaRender(getMemDC(), 0, 0, 200);
	if (_windowState == SAVELOAD){
		
		switch (_saveState){
		case SAVE1:
			IMAGEMANAGER->findAlphaImage("세이브위치선택")->alphaRender(getMemDC(), 46, 135, 80);
			IMAGEMANAGER->findImage("큰세이브책1")->render(getMemDC(), 70, 140);
			IMAGEMANAGER->findImage("세이브책2")->render(getMemDC(), 70, 365);
			IMAGEMANAGER->findImage("세이브책3")->render(getMemDC(), 70, 570);

			break;
		case SAVE2:
			IMAGEMANAGER->findAlphaImage("세이브위치선택")->alphaRender(getMemDC(), 46, 340, 80);
			IMAGEMANAGER->findImage("세이브책1")->render(getMemDC(), 70, 160);
			IMAGEMANAGER->findImage("큰세이브책2")->render(getMemDC(), 70, 345);
			IMAGEMANAGER->findImage("세이브책3")->render(getMemDC(), 70, 570);

			break;
		case SAVE3:
			IMAGEMANAGER->findAlphaImage("세이브위치선택")->alphaRender(getMemDC(), 46, 547, 80);
			IMAGEMANAGER->findImage("세이브책1")->render(getMemDC(), 70, 160);
			IMAGEMANAGER->findImage("세이브책2")->render(getMemDC(), 70, 365);
			IMAGEMANAGER->findImage("큰세이브책3")->render(getMemDC(), 70, 550);

			break;
		}

		HFONT oldFont;
		HFONT font1;
		SetBkMode(getMemDC(), TRANSPARENT);

		char str[100];
		if (INIDATA->loadDataInterger("save1", "State", "LEVEL") < 1){
			//없으면
			font1 = CreateFont(100, 60, 0, 0, 500, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 405, 190, str, strlen(str));
			if (_saveState == SAVE1){
				SetTextColor(getMemDC(), RGB(255, 255, 255));
			}
			else{
				SetTextColor(getMemDC(), RGB(125, 125, 125));
			}
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 400, 185, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
		}
		else{
			//세이브1 데이터가 있으면
			font1 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			sprintf(str, "LV : %d", INIDATA->loadDataInterger("save1", "State", "LEVEL"));
			TextOut(getMemDC(), 280, 180, str, strlen(str));
			sprintf(str, "STR : %d", INIDATA->loadDataInterger("save1", "State", "STR"));
			TextOut(getMemDC(), 680, 180, str, strlen(str));
			sprintf(str, "INT : %d", INIDATA->loadDataInterger("save1", "State", "INT"));
			TextOut(getMemDC(), 980, 180, str, strlen(str));
			sprintf(str, "CON : %d", INIDATA->loadDataInterger("save1", "State", "CON"));
			TextOut(getMemDC(), 1280, 180, str, strlen(str));
			sprintf(str, "MGR : %d", INIDATA->loadDataInterger("save1", "State", "MGR"));
			TextOut(getMemDC(), 680, 250, str, strlen(str));
			sprintf(str, "DEX : %d", INIDATA->loadDataInterger("save1", "State", "DEX"));
			TextOut(getMemDC(), 980, 250, str, strlen(str));
			sprintf(str, "LUC : %d", INIDATA->loadDataInterger("save1", "State", "LUC"));
			TextOut(getMemDC(), 1280, 250, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);


		}

		if (INIDATA->loadDataInterger("save2", "State", "LEVEL") < 1){
			//없으면
			font1 = CreateFont(100, 60, 0, 0, 500, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 405, 400, str, strlen(str));
			if (_saveState == SAVE2){
				SetTextColor(getMemDC(), RGB(255, 255, 255));
			}
			else{
				SetTextColor(getMemDC(), RGB(125, 125, 125));
			}
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 400, 395, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
		}
		else{
			//세이브2 데이터가 있으면
			font1 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			sprintf(str, "LV : %d", INIDATA->loadDataInterger("save2", "State", "LEVEL"));
			TextOut(getMemDC(), 280, 380, str, strlen(str));
			sprintf(str, "STR : %d", INIDATA->loadDataInterger("save2", "State", "STR"));
			TextOut(getMemDC(), 680, 380, str, strlen(str));
			sprintf(str, "INT : %d", INIDATA->loadDataInterger("save2", "State", "INT"));
			TextOut(getMemDC(), 980, 380, str, strlen(str));
			sprintf(str, "CON : %d", INIDATA->loadDataInterger("save2", "State", "CON"));
			TextOut(getMemDC(), 1280, 380, str, strlen(str));
			sprintf(str, "MGR : %d", INIDATA->loadDataInterger("save2", "State", "MGR"));
			TextOut(getMemDC(), 680, 450, str, strlen(str));
			sprintf(str, "DEX : %d", INIDATA->loadDataInterger("save2", "State", "DEX"));
			TextOut(getMemDC(), 980, 450, str, strlen(str));
			sprintf(str, "LUC : %d", INIDATA->loadDataInterger("save2", "State", "LUC"));
			TextOut(getMemDC(), 1280, 450, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
		}
		

		if (INIDATA->loadDataInterger("save3", "State", "LEVEL") < 1){
			//없으면
			font1 = CreateFont(100, 60, 0, 0, 500, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 405, 600, str, strlen(str));
			if (_saveState == SAVE3){
				SetTextColor(getMemDC(), RGB(255, 255, 255));
			}
			else{
				SetTextColor(getMemDC(), RGB(125, 125, 125));
			}
			sprintf(str, "NO DATA");
			TextOut(getMemDC(), 400, 595, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
		}
		else{
			//세이브3 데이터가 있으면
			font1 = CreateFont(50, 30, 0, 0, 100, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("HYcysM"));
			oldFont = (HFONT)SelectObject(getMemDC(), font1);
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			sprintf(str, "LV : %d", INIDATA->loadDataInterger("save3", "State", "LEVEL"));
			TextOut(getMemDC(), 280, 580, str, strlen(str));
			sprintf(str, "STR : %d", INIDATA->loadDataInterger("save3", "State", "STR"));
			TextOut(getMemDC(), 680, 580, str, strlen(str));
			sprintf(str, "INT : %d", INIDATA->loadDataInterger("save3", "State", "INT"));
			TextOut(getMemDC(), 980, 580, str, strlen(str));
			sprintf(str, "CON : %d", INIDATA->loadDataInterger("save3", "State", "CON"));
			TextOut(getMemDC(), 1280, 580, str, strlen(str));
			sprintf(str, "MGR : %d", INIDATA->loadDataInterger("save3", "State", "MGR"));
			TextOut(getMemDC(), 680, 650, str, strlen(str));
			sprintf(str, "DEX : %d", INIDATA->loadDataInterger("save3", "State", "DEX"));
			TextOut(getMemDC(), 980, 650, str, strlen(str));
			sprintf(str, "LUC : %d", INIDATA->loadDataInterger("save3", "State", "LUC"));
			TextOut(getMemDC(), 1280, 650, str, strlen(str));
			SelectObject(getMemDC(), oldFont);
			DeleteObject(font1);
			
		}
	}
}
void openingScene::release(){
}

void openingScene::createData(char* fileName){
	//캐릭터 스테이터스
	INIDATA->addData("State", "LEVEL", "1");
	INIDATA->addData("State", "EXP", "0");
	INIDATA->addData("State", "HP", "100");
	INIDATA->addData("State", "MP", "300");
	INIDATA->addData("State", "STR", "1");
	INIDATA->addData("State", "INT", "10");
	INIDATA->addData("State", "CON", "4");
	INIDATA->addData("State", "MGR", "9");
	INIDATA->addData("State", "DEX", "5");
	INIDATA->addData("State", "LUC", "5");
	INIDATA->addData("State", "Money", "1000");

	//인벤토리	-- 모든 아이템이들어있음
	//num = -1이면 봉인된 아이템
	INIDATA->addData("마카로프의 스태프", "num", "1");
	INIDATA->addData("마카로프의 스태프", "currentCon", "0");
	INIDATA->addData("문라이트 스태프", "num", "0");
	INIDATA->addData("이그니 스태프", "num", "0");
	INIDATA->addData("크라운 스태프", "num", "0");
	INIDATA->addData("크라운 스태프", "seal", "1");
	INIDATA->addData("붉은 망토", "num", "0");
	INIDATA->addData("마법사 망토", "num", "0");
	INIDATA->addData("대마법사 망토", "num", "0");
	INIDATA->addData("대마법사 망토", "seal", "1");
	INIDATA->addData("가죽 장갑", "num", "0");
	INIDATA->addData("요정 장갑", "num", "0");
	INIDATA->addData("가죽 신발", "num", "0");
	INIDATA->addData("마법사 신발", "num", "0");
	INIDATA->addData("에메랄드 귀거리", "num", "0");
	INIDATA->addData("요정눈물 귀거리", "num", "0");
	INIDATA->addData("A룬", "num", "0");
	INIDATA->addData("B룬", "num", "0");
	INIDATA->addData("C룬", "num", "0");
	INIDATA->addData("D룬", "num", "0");
	INIDATA->addData("E룬", "num", "0");
	INIDATA->addData("F룬", "num", "0");
	INIDATA->addData("요정의 물약", "num", "3");
	INIDATA->addData("아이스 프리즌의 서", "num", "0");
	INIDATA->addData("프로텍션의 서", "num", "0");
	INIDATA->addData("그래비티의 서", "num", "0");
	INIDATA->addData("썬더 클라우드의 서", "num", "0");
	INIDATA->addData("록 프레스의 서", "num", "0");
	INIDATA->addData("블리자드의 서", "num", "0");
	INIDATA->addData("크리에이트 푸드의 서", "num", "0");
	INIDATA->addData("커스의 서", "num", "0");
	INIDATA->addData("페트리피케이션의 서", "num", "0");

	//가방	-- 던전에서 사용할 아이템을 등록
	INIDATA->addData("Bag", "bag1", "empty");
	INIDATA->addData("Bag", "bag2", "empty");
	INIDATA->addData("Bag", "bag3", "empty");
	INIDATA->addData("Bag", "bag4", "empty");
	INIDATA->addData("Bag", "bag5", "empty");
	INIDATA->addData("Bag", "bag6", "empty");
	INIDATA->addData("Bag", "bag7", "empty");
	INIDATA->addData("Bag", "bag8", "empty");

	//스킬
	INIDATA->addData("Skill", "SKILLPOINT", "1");
	INIDATA->addData("Skill", "mental_absorb","0");
	INIDATA->addData("Skill", "extract", "0");
	INIDATA->addData("Skill", "concentrate", "0");
	INIDATA->addData("Skill", "magic_point_up", "0");
	INIDATA->addData("Skill", "ice_prision", "0");
	INIDATA->addData("Skill", "protection", "0");
	INIDATA->addData("Skill", "gravity", "0");
	INIDATA->addData("Skill", "thunder_cloud", "0");
	INIDATA->addData("Skill", "rock_press", "0");
	INIDATA->addData("Skill", "blizzard", "0");
	INIDATA->addData("Skill", "animate_skelton", "0");
	INIDATA->addData("Skill", "ravitation", "0");
	INIDATA->addData("Skill", "create_food", "0");
	INIDATA->addData("Skill", "curse", "0");
	INIDATA->addData("Skill", "petrification", "0");
	INIDATA->addData("Skill", "sliding", "0");
	INIDATA->addData("Skill", "gold_healing", "0");
	INIDATA->addData("Skill", "gold_scoring", "0");
	INIDATA->addData("Skill", "hit_point_up", "0");
	INIDATA->addData("Skill", "food_psytology", "0");
	INIDATA->addData("Skill", "maintenance", "0");
	INIDATA->addData("Skill", "item_user", "0");
	INIDATA->addData("Skill", "evade", "0");
	INIDATA->addData("Skill", "extra_pocket", "0");

	//좌표
	char str1[50];
	sprintf(str1, "%d", 100);
	INIDATA->addData("Position", "X", str1);
	sprintf(str1, "%d", 300);
	INIDATA->addData("Position", "Y", str1);
	sprintf(str1, "%d", 115);
	INIDATA->addData("Position", "그림자X", str1);
	sprintf(str1, "%d", 740);
	INIDATA->addData("Position", "그림자Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "절대좌표X", str1);
	sprintf(str1, "%d", -600);
	INIDATA->addData("Position", "절대좌표Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "성X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "성Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을1X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을1Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을2X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을2Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을3X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을3Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을4X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을4Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을5X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을5Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "루카인X", str1);

	//탈리즈만
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "red", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "orange", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "yellow", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "green", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "skyblue", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "blue", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "pupple", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "white", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Talizman", "black", str1);
	INIDATA->iniSave(fileName);
	loadData(fileName);


}

void openingScene::loadData(char* fileName){
	//좌표
	char str1[50];
	sprintf(str1, "%d", 100);
	INIDATA->addData("Position", "X", str1);
	sprintf(str1, "%d", 300);
	INIDATA->addData("Position", "Y", str1);
	sprintf(str1, "%d", 115);
	INIDATA->addData("Position", "그림자X", str1);
	sprintf(str1, "%d", 740);
	INIDATA->addData("Position", "그림자Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "절대좌표X", str1);
	sprintf(str1, "%d", -600);
	INIDATA->addData("Position", "절대좌표Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "성X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "성Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을1X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을1Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을2X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을2Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을3X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을3Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을4X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을4Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을5X", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "마을5Y", str1);
	sprintf(str1, "%d", 0);
	INIDATA->addData("Position", "루카인X", str1);


	string str = INIDATA->loadDataString(fileName, "State", "LEVEL").c_str();
	INIDATA->addData("State", "LEVEL", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "EXP").c_str();
	INIDATA->addData("State", "EXP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "HP").c_str();
	INIDATA->addData("State", "HP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "MP").c_str();
	INIDATA->addData("State", "MP", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "STR").c_str();
	INIDATA->addData("State", "STR", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "INT").c_str();
	INIDATA->addData("State", "INT", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "CON").c_str();
	INIDATA->addData("State", "CON", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "MGR").c_str();
	INIDATA->addData("State", "MGR", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "DEX").c_str();
	INIDATA->addData("State", "DEX", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "LUC").c_str();
	INIDATA->addData("State", "LUC", str.c_str());
	str = INIDATA->loadDataString(fileName, "State", "Money").c_str();
	INIDATA->addData("State", "Money", str.c_str());
	//인벤토리	-- 모든 아이템이들어있음
	str = INIDATA->loadDataString(fileName, "마카로프의 스태프", "num").c_str();
	INIDATA->addData("마카로프의 스태프", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "마카로프의 스태프", "currentCon").c_str();
	INIDATA->addData("마카로프의 스태프", "currentCon", str.c_str());
	str = INIDATA->loadDataString(fileName, "문라이트 스태프", "num").c_str();
	INIDATA->addData("문라이트 스태프", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "이그니 스태프", "num").c_str();
	INIDATA->addData("이그니 스태프", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "크라운 스태프", "num").c_str();
	INIDATA->addData("크라운 스태프", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "크라운 스태프", "seal").c_str();
	INIDATA->addData("크라운 스태프", "seal", str.c_str());
	str = INIDATA->loadDataString(fileName, "붉은 망토", "num").c_str();
	INIDATA->addData("붉은 망토", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "마법사 망토", "num").c_str();
	INIDATA->addData("마법사 망토", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "대마법사 망토", "num").c_str();
	INIDATA->addData("대마법사 망토", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "대마법사 망토", "seal").c_str();
	INIDATA->addData("대마법사 망토", "seal", str.c_str());
	str = INIDATA->loadDataString(fileName, "가죽 장갑", "num").c_str();
	INIDATA->addData("가죽 장갑", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "요정 장갑", "num").c_str();
	INIDATA->addData("요정 장갑", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "가죽 신발", "num").c_str();
	INIDATA->addData("가죽 신발", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "마법사 신발", "num").c_str();
	INIDATA->addData("마법사 신발", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "에메랄드 귀거리", "num").c_str();
	INIDATA->addData("에메랄드 귀거리", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "요정눈물 귀거리", "num").c_str();
	INIDATA->addData("요정눈물 귀거리", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "A룬", "num").c_str();
	INIDATA->addData("A룬", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "B룬", "num").c_str();
	INIDATA->addData("B룬", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "C룬", "num").c_str();
	INIDATA->addData("C룬", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "D룬", "num").c_str();
	INIDATA->addData("D룬", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "E룬", "num").c_str();
	INIDATA->addData("E룬", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "F룬", "num").c_str();
	INIDATA->addData("F룬", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "요정의 물약", "num").c_str();
	INIDATA->addData("요정의 물약", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "아이스 프리즌의 서", "num").c_str();
	INIDATA->addData("아이스 프리즌의 서", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "프로텍션의 서", "num").c_str();
	INIDATA->addData("프로텍션의 서", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "그래비티의 서", "num").c_str();
	INIDATA->addData("그래비티의 서", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "썬더 클라우드의 서", "num").c_str();
	INIDATA->addData("썬더 클라우드의 서", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "록 프레스의 서", "num").c_str();
	INIDATA->addData("록 프레스의 서", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "블리자드의 서", "num").c_str();
	INIDATA->addData("블리자드의 서", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "크리에이트 푸드의 서", "num").c_str();
	INIDATA->addData("크리에이트 푸드의 서", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "커스의 서", "num").c_str();
	INIDATA->addData("커스의 서", "num", str.c_str());
	str = INIDATA->loadDataString(fileName, "페트리피케이션의 서", "num").c_str();
	INIDATA->addData("페트리피케이션의 서", "num", str.c_str());

	//가방	-- 던전에서 사용할 아이템을 등록
	str = INIDATA->loadDataString(fileName, "Bag", "bag1").c_str();
	INIDATA->addData("Bag", "bag1", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag2").c_str();
	INIDATA->addData("Bag", "bag2", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag3").c_str();
	INIDATA->addData("Bag", "bag3", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag4").c_str();
	INIDATA->addData("Bag", "bag4", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag5").c_str();
	INIDATA->addData("Bag", "bag5", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag6").c_str();
	INIDATA->addData("Bag", "bag6", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag7").c_str();
	INIDATA->addData("Bag", "bag7", str.c_str());
	str = INIDATA->loadDataString(fileName, "Bag", "bag8").c_str();
	INIDATA->addData("Bag", "bag8", str.c_str());
	
	//스킬
	str = INIDATA->loadDataString(fileName, "Skill", "SKILLPOINT").c_str();
	INIDATA->addData("Skill", "SKILLPOINT", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "mental_absorb").c_str();
	INIDATA->addData("Skill", "mental_absorb", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "extract").c_str();
	INIDATA->addData("Skill", "extract", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "concentrate").c_str();
	INIDATA->addData("Skill", "concentrate", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "magic_point_up").c_str();
	INIDATA->addData("Skill", "magic_point_up", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "ice_prision").c_str();
	INIDATA->addData("Skill", "ice_prision", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "protection").c_str();
	INIDATA->addData("Skill", "protection", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gravity").c_str();
	INIDATA->addData("Skill", "gravity", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "thunder_cloud").c_str();
	INIDATA->addData("Skill", "thunder_cloud", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "rock_press").c_str();
	INIDATA->addData("Skill", "rock_press", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "blizzard").c_str();
	INIDATA->addData("Skill", "blizzard", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "animate_skelton").c_str();
	INIDATA->addData("Skill", "animate_skelton", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "ravitation").c_str();
	INIDATA->addData("Skill", "ravitation", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "create_food").c_str();
	INIDATA->addData("Skill", "create_food", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "curse").c_str();
	INIDATA->addData("Skill", "curse", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "petrification").c_str();
	INIDATA->addData("Skill", "petrification", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "sliding").c_str();
	INIDATA->addData("Skill", "sliding", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gold_healing").c_str();
	INIDATA->addData("Skill", "gold_healing", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "gold_scoring").c_str();
	INIDATA->addData("Skill", "gold_scoring", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "hit_point_up").c_str();
	INIDATA->addData("Skill", "hit_point_up", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "food_psytology").c_str();
	INIDATA->addData("Skill", "food_psytology", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "maintenance").c_str();
	INIDATA->addData("Skill", "maintenance", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "item_user").c_str();
	INIDATA->addData("Skill", "item_user", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "evade").c_str();
	INIDATA->addData("Skill", "evade", str.c_str());
	str = INIDATA->loadDataString(fileName, "Skill", "extra_pocket").c_str();
	INIDATA->addData("Skill", "extra_pocket", str.c_str());
	
	//탈리즈만
	str = INIDATA->loadDataString(fileName, "Talizman", "red").c_str();
	INIDATA->addData("Talizman", "red", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "orange").c_str();
	INIDATA->addData("Talizman", "orange", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "yellow").c_str();
	INIDATA->addData("Talizman", "yellow", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "green").c_str();
	INIDATA->addData("Talizman", "green", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "skyblue").c_str();
	INIDATA->addData("Talizman", "skyblue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "blue").c_str();
	INIDATA->addData("Talizman", "blue", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "pupple").c_str();
	INIDATA->addData("Talizman", "pupple", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "white").c_str();
	INIDATA->addData("Talizman", "white", str.c_str());
	str = INIDATA->loadDataString(fileName, "Talizman", "black").c_str();
	INIDATA->addData("Talizman", "black", str.c_str());

	INIDATA->iniSave("PlayerData");
}