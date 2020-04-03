#include "stdafx.h"
#include "normalBullet5.h"


normalBullet5::normalBullet5()
{
}


normalBullet5::~normalBullet5()
{
}

HRESULT normalBullet5::init(){
	//IMAGEMANAGER->addFrameImage("normalBullet5", "이미지/소서리스/fireball4.bmp", 1200, 400, 6, 2, true, RGB(255, 0, 255));
	bulletPF::init("normalBullet5", 20, 2000);
	_isAttack = false;
	return S_OK;
}
void normalBullet5::update(){
	bulletPF::update();

	for (int i = 0; i < _vBullet.size(); i++){
		if (_vBullet[i].shadowY < _vBullet[i].y){
			removeBullet(i);
		}
	}

	for (int i = 0; i<_vBullet.size(); i++){
		_vBullet[i].rc = RectMakeCenter(_vBullet[i].x, _vBullet[i].y, 100, 80);
		_vBullet[i].rcShadow = RectMake(_vBullet[i].shadowX, _vBullet[i].shadowY, 30, 35);
		setRect(_vBullet[i].rcShadow);
	}
}
void normalBullet5::render(){
	//bulletPF::render();

	int frame;
	float angle;

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left-50, _viBullet->rc.top-50, _viBullet->frameX, _viBullet->frameY);
		IMAGEMANAGER->findPngImage("shadow")->render(getMemDC(), _viBullet->x - 30, _viBullet->shadowY + 25, 100, 20, 0, 0, 235, 16);

		if (_debug){
			Rectangle(getMemDC(), _viBullet->rc.left, _viBullet->rc.top, _viBullet->rc.right, _viBullet->rc.bottom);
			Rectangle(getMemDC(), _viBullet->rcShadow.left, _viBullet->rcShadow.top, _viBullet->rcShadow.right, _viBullet->rcShadow.bottom);
		}
	}

}
void normalBullet5::release(){}

void normalBullet5::fire(float x, float y, float shadowX, float shadowY, float angle, float speed, int frameX, int frameY){
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