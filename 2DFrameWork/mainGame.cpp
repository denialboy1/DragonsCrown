#include "stdafx.h"
#include "mainGame.h"


mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}



//�ʱ�ȭ�� ����!
HRESULT mainGame::init(void)
{
	gameNode::init(true);
	SCENEMANAGER->init();
	
	SCENEMANAGER->addScene("�����׾�", new openingScene);
	SCENEMANAGER->addScene("������", new townScene);
	SCENEMANAGER->addScene("�����ε���", new townLoadingScene);
	SCENEMANAGER->addScene("������", new barScene);
	SCENEMANAGER->addScene("����", new guildScene);
	SCENEMANAGER->addScene("������", new shopScene);
	SCENEMANAGER->addScene("��Ʈ������", new lastBossScene);
	SCENEMANAGER->addScene("��Ʈ�����ε���", new lastBossLoadingScene);
	SCENEMANAGER->addScene("���ӿ�����", new gameOverScene);
	SCENEMANAGER->addScene("������", new endingScene);
	SCENEMANAGER->addScene("��������������", new graveScene);
	SCENEMANAGER->addScene("�����ε���", new graveStageLoadingScene);
	SCENEMANAGER->changeScene("�����׾�");
	
	return S_OK;
}

//�޸� ���� ����!
void mainGame::release(void)
{
	gameNode::release();
	SCENEMANAGER->release();
}

//���� ����!
void mainGame::update(void)
{
	gameNode::update();
	SCENEMANAGER->update();
	SOUNDMANAGER->update();
	EFFECTMANAGER->update();
	
}

// �׷��ִ� �͵� ����!
void mainGame::render(void)
{
	if (!getHVideo()){
		PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
		SCENEMANAGER->render();
		
		//����� ������ ȭ�鿡 �׷��ش� ## ������ �� �� ##
		this->getBackBuffer()->render(getHDC(), 0, 0);
	}
}
