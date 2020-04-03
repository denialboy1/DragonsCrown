#include "stdafx.h"
#include "gameOverScene.h"


gameOverScene::gameOverScene()
{
}


gameOverScene::~gameOverScene()
{
}

HRESULT gameOverScene::init(){
	IMAGEMANAGER->addAlphaImage("����", "�̹���/����.bmp", 648, 151, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("����", "�̹���/����.bmp", 583, 473, false, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("���ӿ���", "����/���ӿ���.mp3", true, false);
	SOUNDMANAGER->play("���ӿ���", 0.1f);
	_alpha1 = 0;
	_alpha2 = 0;

	return S_OK;
}
void gameOverScene::update(){

	_alpha1++;
	if (_alpha1 > 250){
		_alpha1 = 254;
	}

	if (_alpha1 > 250){
		if (KEYMANAGER->isOnceKeyDown('A')){
			SOUNDMANAGER->allRemove();
			SCENEMANAGER->changeScene("�����׾�");
		}
	}
}
void gameOverScene::render(){
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	IMAGEMANAGER->findAlphaImage("����")->alphaRender(getMemDC(), 500, 300, _alpha1);
	IMAGEMANAGER->findAlphaImage("����")->alphaRender(getMemDC(), 500, 100, 255);
	
}
void gameOverScene::release(){}