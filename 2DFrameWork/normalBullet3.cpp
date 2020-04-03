#include "stdafx.h"
#include "normalBullet3.h"


normalBullet3::normalBullet3()
{
}


normalBullet3::~normalBullet3()
{
}

HRESULT normalBullet3::init(){
	//IMAGEMANAGER->addFrameImage("normalBullet3", "이미지/소서리스/fireball3.bmp", 1285, 314, 5, 2, true, RGB(255, 0, 255));
	bulletPF::init("normalBullet3", 30, 2000);
	_isAttack = false;
	return S_OK;
}
void normalBullet3::update(){
	bulletPF::update();
	for (int i = 0; i<_vBullet.size(); i++){
		_vBullet[i].rc = RectMakeCenter(_vBullet[i].x, _vBullet[i].y, 100, 50);
		setRect(_vBullet[i].rcShadow);
		
	}
	
}
void normalBullet3::render(){
	//bulletPF::render();

	int frame;
	float angle;

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left-100, _viBullet->rc.top-50, _viBullet->frameX, _viBullet->frameY);
		//IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _viBullet->x - 30, _viBullet->shadowY , 100, 20, 0, 0, 235, 16);
		//Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
		IMAGEMANAGER->findAlphaImage("shadow3")->alphaRender(getMemDC(), _viBullet->x - 60, _viBullet->shadowY-30, 200);
		if (_debug){
			Rectangle(getMemDC(), _viBullet->rc.left, _viBullet->rc.top, _viBullet->rc.right, _viBullet->rc.bottom);
			Rectangle(getMemDC(), _viBullet->rcShadow.left, _viBullet->rcShadow.top, _viBullet->rcShadow.right, _viBullet->rcShadow.bottom);
		}
	}

}
void normalBullet3::release(){}

void normalBullet3::fire(float x, float y, float shadowX, float shadowY, float angle, float speed, int frameX, int frameY){
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.radius = bullet.bulletImage->getWidth() / 2;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,100,50);
	bullet.frameX = 0;
	bullet.frameY = frameY;
	bullet.frameTime = 0;
	bullet.shadowX = shadowX;
	bullet.shadowY = shadowY;
	bullet.rcShadow = RectMake(bullet.shadowX, bullet.shadowY, 30, 30);
	bullet.isAttack = false;
	_vBullet.push_back(bullet);
}