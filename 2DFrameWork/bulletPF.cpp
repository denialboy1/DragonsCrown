#include "stdafx.h"
#include "bulletPF.h"

bulletPF::bulletPF()
{}

bulletPF::~bulletPF()
{}

HRESULT bulletPF::init(const char* imageName, int bulletMax, float range)
{
	_imageName = imageName;
	_range = range;
	_bulletMax = bulletMax;
	_frameTime = 0;
	return S_OK;
}


void bulletPF::release()
{
	_vBullet.clear();
}

void bulletPF::update()
{
	move();

	//ÀÌ¹ÌÁö ÇÁ·¹ÀÓ
	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();_viBullet++)
	{
		(*_viBullet).frameTime++;
		if ((*_viBullet).frameTime > 5){
			(*_viBullet).frameX++;
			(*_viBullet).frameTime = 0;
		}
		if ((*_viBullet).bulletImage->getMaxFrameX() == (*_viBullet).frameX){
			(*_viBullet).frameX = 0;
		}
	}

}

void bulletPF::render()
{
	draw();
}

void bulletPF::fire(float x, float y, float angle, float speed,int frameX,int frameY)
{
	if (_bulletMax < _vBullet.size()) return;

	tagBullet bullet;
	ZeroMemory(&bullet, sizeof(tagBullet));
	bullet.bulletImage = IMAGEMANAGER->findImage(_imageName);
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.radius = bullet.bulletImage->getWidth() / 2;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());
	bullet.frameX = 0;
	bullet.frameY = frameY;
	bullet.frameTime = 0;
	_vBullet.push_back(bullet);

}

void bulletPF::move()
{
	float elapsedTime = TIMEMANAGER->getElapsedTime();

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed * elapsedTime;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed * elapsedTime;


		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;

	}
}

void bulletPF::draw()
{
	int frame;
	float angle;

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		angle = _viBullet->angle + PI16;
		if (angle >= PI2) angle -= PI2;

		frame = int(angle / PI8);

		_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top, frame, 0);
	}
}

void bulletPF::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}

/////alphaÃÑ¾Ë
bulletPFAlpha::bulletPFAlpha()
{}

bulletPFAlpha::~bulletPFAlpha()
{}

HRESULT bulletPFAlpha::init(const char* imageName, int bulletMax, float range)
{
	_imageName = imageName;
	_range = range;
	_bulletMax = bulletMax;


	return S_OK;
}


void bulletPFAlpha::release()
{
	_vBullet.clear();
}

void bulletPFAlpha::update()
{
	move();
}

void bulletPFAlpha::render()
{
	draw();
}

void bulletPFAlpha::fire(float x, float y, float angle, float speed)
{
	if (_bulletMax < _vBullet.size()) return;

	tagAlphaBullet bullet;
	ZeroMemory(&bullet, sizeof(tagAlphaBullet));
	bullet.bulletImage = IMAGEMANAGER->findAlphaImage(_imageName);
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.radius = bullet.bulletImage->getWidth() / 2;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());

	_vBullet.push_back(bullet);

}

void bulletPFAlpha::move()
{
	float elapsedTime = TIMEMANAGER->getElapsedTime();

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed * elapsedTime;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed * elapsedTime;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());

		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;

	}
}

void bulletPFAlpha::draw()
{
	int frame;
	float angle;

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		angle = _viBullet->angle + PI16;
		if (angle >= PI2) angle -= PI2;

		frame = int(angle / PI8);

		_viBullet->bulletImage->alphaFrameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top, frame, 0,255);
	}
}

void bulletPFAlpha::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}


//pngÃÑ¾Ë
bulletPFPng::bulletPFPng()
{}

bulletPFPng::~bulletPFPng()
{}

HRESULT bulletPFPng::init(const char* imageName, int bulletMax, float range)
{
	_imageName = imageName;
	_range = range;
	_bulletMax = bulletMax;


	return S_OK;
}


void bulletPFPng::release()
{
	_vBullet.clear();
}

void bulletPFPng::update()
{
	move();
}

void bulletPFPng::render()
{
	draw();
}

void bulletPFPng::fire(float x, float y, float angle, float speed)
{
	if (_bulletMax < _vBullet.size()) return;

	tagPngBullet bullet;
	ZeroMemory(&bullet, sizeof(tagPngBullet));
	bullet.bulletImage = IMAGEMANAGER->findPngImage(_imageName);
	bullet.speed = speed;
	bullet.angle = angle;
	bullet.radius = bullet.bulletImage->getWidth() / 2;
	bullet.x = bullet.fireX = x;
	bullet.y = bullet.fireY = y;
	bullet.rc = RectMakeCenter(bullet.x, bullet.y,
		bullet.bulletImage->getFrameWidth(),
		bullet.bulletImage->getFrameHeight());

	_vBullet.push_back(bullet);

}

void bulletPFPng::move()
{
	float elapsedTime = TIMEMANAGER->getElapsedTime();

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end();)
	{
		_viBullet->x += cosf(_viBullet->angle) * _viBullet->speed * elapsedTime;
		_viBullet->y += -sinf(_viBullet->angle) * _viBullet->speed * elapsedTime;

		_viBullet->rc = RectMakeCenter(_viBullet->x, _viBullet->y,
			_viBullet->bulletImage->getFrameWidth(),
			_viBullet->bulletImage->getFrameHeight());

		if (_range < getDistance(_viBullet->fireX, _viBullet->fireY, _viBullet->x, _viBullet->y))
		{
			_viBullet = _vBullet.erase(_viBullet);
		}
		else ++_viBullet;

	}
}

void bulletPFPng::draw()
{
	int frame;
	float angle;

	for (_viBullet = _vBullet.begin(); _viBullet != _vBullet.end(); ++_viBullet)
	{
		angle = _viBullet->angle + PI16;
		if (angle >= PI2) angle -= PI2;

		frame = int(angle / PI8);

		_viBullet->bulletImage->frameRender(getMemDC(), _viBullet->rc.left, _viBullet->rc.top, frame, 0);
	}
}

void bulletPFPng::removeBullet(int arrNum)
{
	_vBullet.erase(_vBullet.begin() + arrNum);
}

