#pragma once
#include "image.h"
#include <Vfw.h>		//동영상


static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);
static image* _pixelColBuffer = IMAGEMANAGER->addImage("pixelColBuffer", WINSIZEX, WINSIZEY);
static image* _backBuffer2 = IMAGEMANAGER->addImage("backBuffer2", WINSIZEX, WINSIZEY);

static image* _damageBuffer = IMAGEMANAGER->addImage("damageBuffer", WINSIZEX, WINSIZEY);
static image* _damageBuffer1 = IMAGEMANAGER->addImage("damageBuffer1", WINSIZEX, WINSIZEY);
static image* _damageBuffer2 = IMAGEMANAGER->addImage("damageBuffer2", 300,300);
static image* _damageBuffer3 = IMAGEMANAGER->addImage("damageBuffer3", 300,300);
static vector<gameNode*> _vZOrder;
static HWND _hVideo = 0;	//동영상

class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;
	RECT _rc;
	bool _show;
public:
	virtual HRESULT init(void);
	virtual HRESULT init(bool managerInit);
	virtual void release(void);
	virtual void update(void);
	virtual void render();

	image* getBackBuffer(void) { return _backBuffer; }
	image* getBackBuffer2(void) { return _backBuffer2; }
	image* getPixelColBuffer(void) { return _pixelColBuffer; }
	image* getDamageBuffer(void) { return _damageBuffer; }
	image* getDamageBuffer1(void) { return _damageBuffer1; }
	image* getDamageBuffer2(void) { return _damageBuffer2; }
	image* getDamageBuffer3(void) { return _damageBuffer3; }
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getMemDC2(){ return _backBuffer2->getMemDC(); }
	HDC getPixelMemDC(){ return _pixelColBuffer->getMemDC(); }
	HDC getHDC() { return _hdc; }
	HDC getDamageDC(){ return _damageBuffer->getMemDC(); }
	HDC getDamage1DC(){ return _damageBuffer1->getMemDC(); }
	HDC getDamage2DC(){ return _damageBuffer2->getMemDC(); }
	HDC getDamage3DC(){ return _damageBuffer3->getMemDC(); }
	LRESULT MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
		
	HWND getHVideo(){ return _hVideo; }						//동영상
	void setHVideo(HWND hVideo){ _hVideo = hVideo; }		//동영상
	gameNode();
	virtual ~gameNode();

	RECT getRect(){ return _rc; }
	void setRect(RECT rc){ _rc = rc; }
	bool getShow(){ return _show; }
	void setShow(bool show){ _show = show; }
};

