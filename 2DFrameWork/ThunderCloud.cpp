#include "stdafx.h"
#include "ThunderCloud.h"


ThunderCloud::ThunderCloud()
{
}


ThunderCloud::~ThunderCloud()
{
}

HRESULT ThunderCloud::init(){
	//IMAGEMANAGER->addAlphaFrameImage("구름", "이미지/소서리스/스킬/구름.bmp", 1200, 150, 4, 1, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("번개", "이미지/소서리스/스킬/번개.bmp", 600, 800, 6, 1, true, RGB(255, 0, 255));
	
	_thunderFrame = 0;
	_cloudX = 100;
	_cloudY = 100;
	_isAttack = false;
	_showTimer = 0;
	_moveTimer = 0;
	_frameTimer = 0;
	attackSkill::init();
	return S_OK;
}
void ThunderCloud::update(){
	if (!_start) return;
	//구름 움직임
	if (_frameTimer > FRAMETIMER){
		while (1){
			int temp = RND->getInt(4);
			if (temp == _frameX) continue;
			_frameX = temp;
			break;
		}
		_frameTimer = 0;
		
	}
	_frameTimer++;

	if (_thunderTimer > THUNDERTIMER && _thunderCount>0){
		_isAttack = true;
		_thunderTimer = 0;
		_thunderFrame = RND->getInt(6);
		_rcAttack = RectMake(_shadowX+120, _shadowY - 550, 50, 600);
		
	}
	if (_isAttack){
		_showTimer++;
		if (_showTimer > SHOWTIMER) {
			_isAttack = false;
			_rcAttack = RectMake(0, 0, 0, 0);
			_showTimer = 0;
			_thunderCount--;
			SOUNDMANAGER->play("thunder", 0.3f);
		}
	}
	_thunderTimer++;

	if (_thunderCount <= 0) {
		//_start = false;
		_isAttack = false;
		_alpha--;
	}
	
	if (_alpha == 0){ _start = false; }

	//구름 움직이기
	if (_moveTimer > CLOUD_MOVE_TIMER){
		_direction = RND->getInt(8);
		_moveTimer = 0;
	}
	_moveTimer++;
	switch (_direction){
	case 0:
		_shadowX -= CLOUDSPEEDX;
		break;
	case 1:
		_shadowX -= CLOUDSPEEDX;
		_shadowY -= CLOUDSPEEDY;
		break;
	case 2:
		_shadowY -= CLOUDSPEEDY;
		break;
	case 3:
		_shadowX += CLOUDSPEEDX;
		_shadowY -= CLOUDSPEEDY;
		break;
	case 4:
		_shadowX += CLOUDSPEEDX;
		break;
	case 5:
		_shadowX += CLOUDSPEEDX;
		_shadowY += CLOUDSPEEDY;
		break;
	case 6:
		_shadowY += CLOUDSPEEDY;
		break;
	case 7:
		_shadowX -= CLOUDSPEEDX;
		_shadowY += CLOUDSPEEDY;
		break;
	}

	if (_shadowX < 0) _shadowX = 0;
	if (_shadowX > WINSIZEX) _shadowX = WINSIZEX;
	if (_shadowY < 700) _shadowY = 700;
	if (_shadowY > WINSIZEY-30) _shadowY = WINSIZEY-30;

	_rcShadow = RectMake(_shadowX+100, _shadowY, 100, 20);
	setRect(_rcShadow);
}
void ThunderCloud::render(){

	if (!_start) return;

	if (_isAttack){
		IMAGEMANAGER->findImage("번개")->frameRender(getMemDC(), _shadowX + 100, _shadowY - 680, _thunderFrame, 0);
	}

	IMAGEMANAGER->findAlphaImage("구름")->alphaFrameRender(getMemDC(), _shadowX, _shadowY - 630, _frameX, 0,_alpha);
	IMAGEMANAGER->findAlphaImage("shadow3")->alphaRender(getMemDC(), _shadowX + 100, _shadowY - 30, 100);

	

	if (_debug){
		Rectangle(getMemDC(), _rcAttack.left, _rcAttack.top, _rcAttack.right, _rcAttack.bottom);
		Rectangle(getMemDC(), _rcShadow.left, _rcShadow.top, _rcShadow.right, _rcShadow.bottom);
	}
}
void ThunderCloud::release(){}

void ThunderCloud::start(float x, float y, float shadowX, float shadowY){
	attackSkill::start(x, y, shadowX, shadowY);
	_thunderCount = THUNDERCOUNT + INIDATA->loadDataInterger("PlayerData","Skill","thunder_cloud");
	_thunderTimer = 0;
	_showTimer = 0;
	_isAttack = false;
	_moveTimer = 0;
}