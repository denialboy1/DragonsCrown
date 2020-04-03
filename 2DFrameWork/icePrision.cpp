#include "stdafx.h"
#include "icePrision.h"


icePrision::icePrision()
{

}


icePrision::~icePrision()
{
}

HRESULT icePrision::init(){
	//IMAGEMANAGER->addAlphaImage("icePrision1", "이미지/소서리스/스킬/아이스프리즌1.bmp", 200, 600,true,RGB(255,0,255));
	//IMAGEMANAGER->addAlphaImage("icePrision2", "이미지/소서리스/스킬/아이스프리즌2.bmp", 200, 600, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("icePrision3", "이미지/소서리스/스킬/아이스프리즌3.bmp", 200, 600, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("icePrision4", "이미지/소서리스/스킬/아이스프리즌4.bmp", 200, 600, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("icePrision5", "이미지/소서리스/스킬/아이스프리즌5.bmp", 200, 600, true, RGB(255, 0, 255));
	
	attackSkill::init();
	return S_OK;
}
void icePrision::update(){
	if (!_start) return;
	if (_alpha == 255){ SOUNDMANAGER->play("아이스프리즌", 0.3f); }
	_rcDeffence[0] = RectMake(_x+50, WINSIZEY - 600 , 90, 500);
	_rcDeffence[1] = RectMake(_x + 90, WINSIZEY - 600 + 20 + 400, 60, 120);
	_rcDeffence[2] = RectMake(_x + 120, WINSIZEY - 600 + 100 + 400, 50, 300);

	setRect(_rcDeffence[2]);

	_alpha-= (3 -  INIDATA->loadDataInterger("PlayerData","Skill","ice_prision"));
	if (_alpha < 4){
		_alpha = 0;
	}

	if (_alpha == 0){
		_start = false;
		_rcDeffence[0] = RectMake(0, 0, 0, 0);
		_rcDeffence[1] = RectMake(0, 0, 0, 0);
		_rcDeffence[2] = RectMake(0, 0, 0, 0);
	}
}
void icePrision::render(){
	if (!_start) return;

	//IMAGEMANAGER->findAlphaImage("icePrision1")->alphaRender(getMemDC(), _x - 50, WINSIZEY - 600 - 100, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision2")->alphaRender(getMemDC(), _x - 45, WINSIZEY - 600 - 90, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision3")->alphaRender(getMemDC(), _x - 40, WINSIZEY - 600 - 80, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision4")->alphaRender(getMemDC(), _x - 35, WINSIZEY - 600 - 70, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision5")->alphaRender(getMemDC(), _x - 30, WINSIZEY - 600 - 60, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision1")->alphaRender(getMemDC(), _x - 25, WINSIZEY - 600 - 50, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision2")->alphaRender(getMemDC(), _x - 20, WINSIZEY - 600 - 40, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision3")->alphaRender(getMemDC(), _x - 15, WINSIZEY - 600 - 30, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision4")->alphaRender(getMemDC(), _x - 10, WINSIZEY - 600 - 20, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision5")->alphaRender(getMemDC(), _x - 5, WINSIZEY - 600 - 10, 255);
	//IMAGEMANAGER->findAlphaImage("icePrision1")->alphaRender(getMemDC(), _x, WINSIZEY - 600, 255);
	IMAGEMANAGER->findAlphaImage("icePrision2")->alphaRender(getMemDC(), _x + 5, WINSIZEY - 600 + 10, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision3")->alphaRender(getMemDC(), _x+10, WINSIZEY-600+20, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision4")->alphaRender(getMemDC(), _x+15, WINSIZEY-600+30, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision5")->alphaRender(getMemDC(), _x+20, WINSIZEY-600+40, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision1")->alphaRender(getMemDC(), _x + 25, WINSIZEY - 600 + 50, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision2")->alphaRender(getMemDC(), _x + 30, WINSIZEY-600 + 60, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision3")->alphaRender(getMemDC(), _x + 35, WINSIZEY-600 + 70, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision4")->alphaRender(getMemDC(), _x + 40, WINSIZEY-600 + 80, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision5")->alphaRender(getMemDC(), _x + 45, WINSIZEY-600 + 90, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision1")->alphaRender(getMemDC(), _x + 50, WINSIZEY-600 + 100, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision2")->alphaRender(getMemDC(), _x + 55, WINSIZEY-600 + 110, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision3")->alphaRender(getMemDC(), _x + 60, WINSIZEY-600 + 120, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision4")->alphaRender(getMemDC(), _x + 65, WINSIZEY-600 + 130, _alpha);
	IMAGEMANAGER->findAlphaImage("icePrision5")->alphaRender(getMemDC(), _x + 70, WINSIZEY-600 + 140, _alpha);


	if (_debug){
		for (int i = 0; i < 3; i++){
			Rectangle(getMemDC(), _rcDeffence[i].left, _rcDeffence[i].top, _rcDeffence[i].right, _rcDeffence[i].bottom);
		}
	}
}
void icePrision::release(){}
