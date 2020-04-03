#pragma once
#include "gameNode.h"
#include <vector>

struct tagBullet
{
	image* bulletImage;
	RECT rc;
	RECT rcShadow;
	int radius;
	float angle;
	float x, y;
	float fireX, fireY;
	float speed;
	bool fire;
	int count;

	int frameX;
	int frameY;
	int frameTime;

	float shadowX;
	float shadowY;

	bool isAttack;
};

//공용으로 사용할 미사일 Missile Public Frame
class bulletPF : public gameNode
{
protected:
	vector<tagBullet> _vBullet;
	vector<tagBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

	int _frameTime;
	
public:
	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed, int frameX, int frameY);
	void move();
	void draw();

	void removeBullet(int arrNum);

	vector<tagBullet> getVBullet(void) { return _vBullet; }
	vector<tagBullet>::iterator getVIBullet(void) { return _viBullet; }

	bulletPF();
	~bulletPF();
};

struct tagAlphaBullet
{
	alphaImage* bulletImage;
	RECT rc;
	int radius;
	float angle;
	float x, y;
	float fireX, fireY;
	float speed;
	bool fire;
	int count;
};

//공용으로 사용할 미사일 Missile Public Frame
class bulletPFAlpha : public gameNode
{
private:
	vector<tagAlphaBullet> _vBullet;
	vector<tagAlphaBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);
	void move();
	void draw();

	void removeBullet(int arrNum);

	vector<tagAlphaBullet> getVBullet(void) { return _vBullet; }
	vector<tagAlphaBullet>::iterator getVIBullet(void) { return _viBullet; }

	bulletPFAlpha();
	~bulletPFAlpha();
};

struct tagPngBullet
{
	pngImage* bulletImage;
	RECT rc;
	int radius;
	float angle;
	float x, y;
	float fireX, fireY;
	float speed;
	bool fire;
	int count;
};

//공용으로 사용할 미사일 Missile Public Frame
class bulletPFPng : public gameNode
{
private:
	vector<tagPngBullet> _vBullet;
	vector<tagPngBullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;

public:
	HRESULT init(const char* imageName, int bulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y, float angle, float speed);
	void move();
	void draw();

	void removeBullet(int arrNum);

	vector<tagPngBullet> getVBullet(void) { return _vBullet; }
	vector<tagPngBullet>::iterator getVIBullet(void) { return _viBullet; }

	bulletPFPng();
	~bulletPFPng();
};