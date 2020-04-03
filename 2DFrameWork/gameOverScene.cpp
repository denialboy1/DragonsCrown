#include "stdafx.h"
#include "gameOverScene.h"


gameOverScene::gameOverScene()
{
}


gameOverScene::~gameOverScene()
{
}

HRESULT gameOverScene::init(){
	IMAGEMANAGER->addAlphaImage("Á×À½", "ÀÌ¹ÌÁö/Á×À½.bmp", 648, 151, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaImage("¹¦Áö", "ÀÌ¹ÌÁö/¹¦Áö.bmp", 583, 473, false, RGB(255, 0, 255));

	SOUNDMANAGER->addSound("°ÔÀÓ¿À¹ö", "»ç¿îµå/°ÔÀÓ¿À¹ö.mp3", true, false);
	SOUNDMANAGER->play("°ÔÀÓ¿À¹ö", 0.1f);
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
			SCENEMANAGER->changeScene("¿ÀÇÁ´×¾À");
		}
	}
}
void gameOverScene::render(){
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	IMAGEMANAGER->findAlphaImage("¹¦Áö")->alphaRender(getMemDC(), 500, 300, _alpha1);
	IMAGEMANAGER->findAlphaImage("Á×À½")->alphaRender(getMemDC(), 500, 100, 255);
	
}
void gameOverScene::release(){}