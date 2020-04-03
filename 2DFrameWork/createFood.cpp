#include "stdafx.h"
#include "createFood.h"


createFood::createFood()
{
}


createFood::~createFood()
{
}

HRESULT createFood::init(){
	//IMAGEMANAGER->addAlphaImage("apple", "이미지/음식/apple.bmp", 100, 100, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("pear", "이미지/음식/pear.bmp", 100, 100, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("pormegranate", "이미지/음식/pormegranate.bmp", 100, 100, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addAlphaImage("shadow4", "이미지/소서리스/shadow.bmp", 100, 100, true, RGB(255, 0, 255));
	
	attackSkill::init();
	_foodTime = 0;
	_skillLV = 0;

	return S_OK;
}
void createFood::render(){
	if (!_start) return; 

	IMAGEMANAGER->findAlphaImage("shadow4")->alphaRender(getMemDC(), _shadowX, _shadowY, _shadowAlpha);
	switch (_skillLV){
	case 0:
		IMAGEMANAGER->findAlphaImage("apple")->alphaRender(getMemDC(), _x, _y, _alpha);
		break;
	case 1:
		IMAGEMANAGER->findAlphaImage("pear")->alphaRender(getMemDC(), _x, _y, _alpha);
		break;
	default:
		IMAGEMANAGER->findAlphaImage("pormegranate")->alphaRender(getMemDC(), _x, _y, _alpha);
		break;
	}
	

	if (_debug){
		Rectangle(getMemDC(), _rcObject.left, _rcObject.top, _rcObject.right, _rcObject.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void createFood::update(){
	
	if (!_start){
		_rcObject = RectMake(0, 0, 0, 0);
		return;
	}

	_alpha--;
	if (_alpha < 160){
		_shadowAlpha--;
		if (_shadowAlpha < 10){ _shadowAlpha = 0; }
	}
	if (_alpha < 4){ _alpha = 0; _start = false; 
	_rcObject = RectMake(0, 0, 0, 0);
	}
}
void createFood::release(){}

void createFood::start(float x, float y, float shadowX, float shadowY, int skillLV){
	attackSkill::start(x,y,shadowX,shadowY);
	_skillLV = skillLV;
	_alpha = 255;
	_shadowX = shadowX;
	_shadowY = shadowY;
	_rcShadow = RectMake(_shadowX, _shadowY+35, 100, 20);
	_rcObject = RectMake(_shadowX+30, _shadowY, 50, 50);
	_shadowAlpha = 125;
	SOUNDMANAGER->play("createFood", 0.3f);
}