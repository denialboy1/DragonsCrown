#include "stdafx.h"
#include "menuScene.h"


menuScene::menuScene()
{
}


menuScene::~menuScene()
{
}


HRESULT menuScene::init(){
	_menu = new menu;
	_menu->init();
	return S_OK;
}
void menuScene::update(){
	_menu->update();
}
void menuScene::render(){
	_menu->render();
}
void menuScene::release(){}


