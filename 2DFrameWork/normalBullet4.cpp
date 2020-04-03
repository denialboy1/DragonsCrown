#include "stdafx.h"
#include "normalBullet4.h"


normalBullet4::normalBullet4()
{
}


normalBullet4::~normalBullet4()
{
}

HRESULT normalBullet4::init(){
	//IMAGEMANAGER->addFrameImage("normalBullet4", "이미지/소서리스/fireball4.bmp", 2400, 800, 6, 2, true, RGB(255, 0, 255));
	bulletPF::init("normalBullet4", 1, 2000);
	_isAttack = false;
	return S_OK;
}
void normalBullet4::update(){
	bulletPF::update();

	for (int i = 0; i < _vBullet.size(); i++){
		if (_vBullet[i].shadowY < _vBullet[i].y+30){
			removeBullet(i);
		}
	}

	for (int i = 0; i<_vBullet.size(); i++){
		_vBullet[i].rc = RectMakeCenter(_vBullet[i].x, _vBullet[i].y, 100, 80);
		_vBullet[i].rcShadow = RectMake(_vBullet[i].shadowX, _vBullet[i].shadowY, 30, 35);
		setRect(_vBullet[i].rcShadow);
	}
}
void normalBullet4::render(){
	//bulletPF::render();

	int frame;
	float angle;

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left-150, _viBullet->rc.top-180, _viBullet->frameX, _viBullet->frameY);
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _viBullet->x-100, _viBullet->shadowY, 200, 20, 0, 0, 235, 16);
		

		if (_debug){
			Rectangle(getMemDC(), _viBullet->rc.left, _viBullet->rc.top, _viBullet->rc.right, _viBullet->rc.bottom);
			Rectangle(getMemDC(), _viBullet->rcShadow.left, _viBullet->rcShadow.top, _viBullet->rcShadow.right, _viBullet->rcShadow.bottom);
		}
	}

}
void normalBullet4::release(){}

void normalBullet4::fire(float x, float y, float shadowX, float shadowY, float angle, float speed, int frameX, int frameY){
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.radius = bullet.bulletImage->getWidth() / 2;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y, 0, 0);
	bullet.frameX = 0;
	bullet.frameY = frameY;
	bullet.frameTime = 0;
	bullet.shadowX = shadowX;
	bullet.shadowY = shadowY;
	bullet.isAttack = false;
	_vBullet.push_back(bullet);
}