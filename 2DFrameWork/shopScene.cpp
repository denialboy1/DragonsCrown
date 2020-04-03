#include "stdafx.h"
#include "shopScene.h"


shopScene::shopScene()
{
}


shopScene::~shopScene()
{
}

HRESULT shopScene::init(){
	_shop = new shop;
	_shop->init();
	return S_OK;
}
void shopScene::update(){
	_shop->update();
	KEYANIMANAGER->update();
}
void shopScene::render(){
	_shop->render();
}
void shopScene::release(){
	_shop->release();
}

