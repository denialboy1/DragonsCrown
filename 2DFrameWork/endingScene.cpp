#include "stdafx.h"
#include "endingScene.h"


endingScene::endingScene()
{
}


endingScene::~endingScene()
{
}

HRESULT endingScene::init(){
	//������ �ʱ�ȭ
	if (getHVideo()){
		MCIWndClose(getHVideo());
		MCIWndDestroy(getHVideo());
		setHVideo(0);
	}
	setHVideo(MCIWndCreateA(_hWnd, _hInstance, MCIWNDF_NOMENU | MCIWNDF_NOOPEN | MCIWNDF_NOPLAYBAR | MCIWNDF_NOTIFYALL, "������/����.wmv"));
	SetWindowPos(getHVideo(), NULL, 0, 0, WINSIZEX, WINSIZEY, NULL);
	if (getHVideo()){
		MCIWndPlay(getHVideo());
	}

	return S_OK;
}
void endingScene::update(){}
void endingScene::render(){}
void endingScene::release(){}