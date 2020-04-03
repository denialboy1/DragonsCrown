#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}



//초기화는 여기!
HRESULT mainGame::init(void)
{
	gameNode::init(true);
	SCENEMANAGER->init();
	
	SCENEMANAGER->addScene("오프닝씬", new openingScene);
	SCENEMANAGER->addScene("마을씬", new townScene);
	SCENEMANAGER->addScene("마을로딩씬", new townLoadingScene);
	SCENEMANAGER->addScene("주점씬", new barScene);
	SCENEMANAGER->addScene("길드씬", new guildScene);
	SCENEMANAGER->addScene("상점씬", new shopScene);
	SCENEMANAGER->addScene("라스트보스씬", new lastBossScene);
	SCENEMANAGER->addScene("라스트보스로딩씬", new lastBossLoadingScene);
	SCENEMANAGER->addScene("게임오버씬", new gameOverScene);
	SCENEMANAGER->addScene("엔딩씬", new endingScene);
	SCENEMANAGER->addScene("무덤스테이지씬", new graveScene);
	SCENEMANAGER->addScene("무덤로딩씬", new graveStageLoadingScene);
	SCENEMANAGER->changeScene("오프닝씬");
	
	return S_OK;
}

//메모리 해제 여기!
void mainGame::release(void)
{
	gameNode::release();
	SCENEMANAGER->release();
}

//연산 여기!
void mainGame::update(void)
{
	gameNode::update();
	SCENEMANAGER->update();
	SOUNDMANAGER->update();
	EFFECTMANAGER->update();
	
}

// 그려주는 것도 여기!
void mainGame::render(void)
{
	if (!getHVideo()){
		PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
		SCENEMANAGER->render();
		
		//백버퍼 내용을 화면에 그려준다 ## 지우지 말 것 ##
		this->getBackBuffer()->render(getHDC(), 0, 0);
	}
}
