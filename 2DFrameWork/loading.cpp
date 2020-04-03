#include "stdafx.h"
#include "loading.h"

loadItem::loadItem(){}
loadItem::~loadItem(){}

HRESULT loadItem::initForImage(string keyName, int width, int height)
{
	_kind = LOADING_KIND_IMAGE_00;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.width = width;
	_resource.height = height;

	return S_OK;
}

HRESULT loadItem::initForImage(string keyName, const char* fileName, int x, int y, int width, int height, bool trans, COLORREF transColor)
{
	_kind = LOADING_KIND_IMAGE_01;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.x = x;
	_resource.y = y;
	_resource.width = width;
	_resource.height = height;
	_resource.trans = trans;
	_resource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForImage(string keyName, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	_kind = LOADING_KIND_IMAGE_02;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.width = width;
	_resource.height = height;
	_resource.trans = trans;
	_resource.transColor = transColor;

	return S_OK;
}
HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	_kind = LOADING_KIND_FRAMEIMAGE_00;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.x = x;
	_resource.y = y;
	_resource.width = width;
	_resource.height = height;
	_resource.frameX = frameX;
	_resource.frameY = frameY;
	_resource.trans = trans;
	_resource.transColor = transColor;
	return S_OK;
}
HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{

	_kind = LOADING_KIND_FRAMEIMAGE_01;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.width = width;
	_resource.height = height;
	_resource.frameX = frameX;
	_resource.frameY = frameY;
	_resource.trans = trans;
	_resource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor,bool multi)
{

	_kind = LOADING_KIND_FRAMEIMAGE_04;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.width = width;
	_resource.height = height;
	_resource.frameX = frameX;
	_resource.frameY = frameY;
	_resource.trans = trans;
	_resource.transColor = transColor;
	_resource.multi = multi;

	return S_OK;
}

HRESULT loadItem::initForAlphaImage(string keyName, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	_kind = LOADING_KIND_IMAGE_03;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.width = width;
	_resource.height = height;
	_resource.trans = trans;
	_resource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForAlphaImage(string keyName, const char* fileName, int x, int y,int width, int height, bool trans, COLORREF transColor, bool multi)
{
	_kind = LOADING_KIND_IMAGE_05;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.x = x;
	_resource.y = y;
	_resource.width = width;
	_resource.height = height;
	_resource.trans = trans;
	_resource.transColor = transColor;
	_resource.multi = multi;
	return S_OK;
}


HRESULT loadItem::initForPngImage(string keyName, const WCHAR* wFileName, int width, int height)
{
	_kind = LOADING_KIND_IMAGE_04;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.wFileName = wFileName;
	_resource.width = width;
	_resource.height = height;

	return S_OK;
}

HRESULT loadItem::initForAlphaFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{

	_kind = LOADING_KIND_FRAMEIMAGE_02;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.width = width;
	_resource.height = height;
	_resource.frameX = frameX;
	_resource.frameY = frameY;
	_resource.trans = trans;
	_resource.transColor = transColor;

	return S_OK;
}

HRESULT loadItem::initForPngFrameImage(string keyName, const WCHAR* wFileName, int width, int height, int frameX, int frameY)
{

	_kind = LOADING_KIND_FRAMEIMAGE_03;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.wFileName = wFileName;
	_resource.width = width;
	_resource.height = height;
	_resource.frameX = frameX;
	_resource.frameY = frameY;

	return S_OK;
}

HRESULT loadItem::initForSound(string keyName, const char* fileName, bool bgm, bool loop) {
	_kind = LOADING_KIND_SOUND_00;

	memset(&_resource, 0, sizeof(tagResource));

	_resource.keyName = keyName;
	_resource.fileName = fileName;
	_resource.bgm = bgm;
	_resource.loop = loop;

	return S_OK;
}


loading::loading()
{
}


loading::~loading()
{
}

HRESULT loading::init()
{
	//백그라운드 이미지
	IMAGEMANAGER->addFrameImage("요정로딩", "이미지/요정3.bmp", 5664, 195, 32, 1, false, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("NowLoading", "이미지/NowLoading.bmp", 2960, 69, 4, 1, false, RGB(255, 0, 255));
	
	_current = 0;
	_fairyFrameX = 0;
	_fairyFrameY = 0;
	_fairyFrameTimer = 0;
	_loadingFrameX = 0;
	_loadingFrameTimer = 0;
	return S_OK;
}


void loading::loadImage(string keyName, int width, int height)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, width, height);
	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char* fileName, int x, int y, int width, int height, bool trans, COLORREF transColor, bool multi)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, x, y, width, height, trans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadImage(string keyName, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForImage(keyName, fileName, width, height, trans, transColor);
	_vLoadItem.push_back(item);
}
void loading::loadAlphaImage(string keyName, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForAlphaImage(keyName, fileName, width, height, trans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadAlphaImage(string keyName, const char* fileName, int x, int y,int width, int height, bool trans, COLORREF transColor, bool multi)
{
	loadItem* item = new loadItem;
	item->initForAlphaImage(keyName, fileName,x,y, width, height, trans, transColor,multi);
	_vLoadItem.push_back(item);
}

void loading::loadPngImage(string keyName, const WCHAR* wFileName, int width, int height)
{
	loadItem* item = new loadItem;
	item->initForPngImage(keyName, wFileName, width, height);
	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, x, y, width, height, frameX, frameY, trans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, width, height, frameX, frameY, trans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor, bool multi){
	loadItem* item = new loadItem;
	item->initForFrameImage(keyName, fileName, width, height, frameX, frameY, trans, transColor,multi);
	_vLoadItem.push_back(item);
}

void loading::loadAlphaFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	loadItem* item = new loadItem;
	item->initForAlphaFrameImage(keyName, fileName, width, height, frameX, frameY, trans, transColor);
	_vLoadItem.push_back(item);
}

void loading::loadPngFrameImage(string keyName, const WCHAR* wFileName, int width, int height, int frameX, int frameY)
{
	loadItem* item = new loadItem;
	item->initForPngFrameImage(keyName, wFileName, width, height, frameX, frameY);
	_vLoadItem.push_back(item);
}

void loading::loadSound(string keyName, const char* fileName, bool bgm, bool loop) {
	loadItem* item = new loadItem;
	item->initForSound(keyName, fileName, bgm, loop);
	_vLoadItem.push_back(item);
}

void loading::release()
{

}

void loading::update()
{
	_fairyFrameTimer++;
	if (_fairyFrameTimer > FAIRY_FRAME_TIMER){
		_fairyFrameX++;
		_fairyFrameTimer = 0;
		if (_fairyFrameX == 32){
			_fairyFrameX = 0;
		}
	}

	_loadingFrameTimer++;
	if (_loadingFrameTimer > LOADING_FRAME_TIMER){
		_loadingFrameX++;
		_loadingFrameTimer = 0;
		if (_loadingFrameX == 4){
			_loadingFrameX = 0;
		}
	}
}

void loading::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	IMAGEMANAGER->findImage("요정로딩")->frameRender(getMemDC(), 600, 700, _fairyFrameX, 0);
	IMAGEMANAGER->findImage("NowLoading")->frameRender(getMemDC(), 800, 800, _loadingFrameX, 0);
}



//로딩이 되는 중이면 true, 다되면 false
BOOL loading::loadNext()
{
	//현재 아이템 갯수가 벡터 사이즈 이상 넘어가면 -> 로딩이 끝났다
	if (_current >= _vLoadItem.size() - 1)
	{
		return false;
	}

	//로딩중
	loadItem* item = _vLoadItem[_current];

	switch (item->getLoadingKind())
	{
	case LOADING_KIND_IMAGE_00:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addImage(imageResource.keyName, imageResource.width, imageResource.height);
	}
	break;
	case LOADING_KIND_IMAGE_01:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addImage(imageResource.keyName, imageResource.fileName,
			imageResource.x, imageResource.y,
			imageResource.width, imageResource.height,
			imageResource.trans, imageResource.transColor, imageResource.multi);
	}
	break;
	case LOADING_KIND_IMAGE_02:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addImage(imageResource.keyName, imageResource.fileName,
			imageResource.width, imageResource.height,
			imageResource.trans, imageResource.transColor);
	}
	break;
	case LOADING_KIND_IMAGE_03:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addAlphaImage(imageResource.keyName, imageResource.fileName,
			imageResource.width, imageResource.height,
			imageResource.trans, imageResource.transColor);
	}
	break;

	case LOADING_KIND_IMAGE_04:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addPngImage(imageResource.keyName, imageResource.wFileName,
			imageResource.width, imageResource.height);
	}
	break;

	case LOADING_KIND_IMAGE_05:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addAlphaImage(imageResource.keyName, imageResource.fileName,
			imageResource.x, imageResource.y,
			imageResource.width, imageResource.height,
			imageResource.trans, imageResource.transColor,imageResource.multi);
	}
	break;

	case LOADING_KIND_FRAMEIMAGE_00:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addFrameImage(imageResource.keyName, imageResource.fileName,
			imageResource.x, imageResource.y,
			imageResource.width, imageResource.height,
			imageResource.frameX, imageResource.frameY,
			imageResource.trans, imageResource.transColor);
	}
	break;
	case LOADING_KIND_FRAMEIMAGE_01:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addFrameImage(imageResource.keyName, imageResource.fileName,
			imageResource.width, imageResource.height,
			imageResource.frameX, imageResource.frameY,
			imageResource.trans, imageResource.transColor);
	}
	break;

	case LOADING_KIND_FRAMEIMAGE_02:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addAlphaFrameImage(imageResource.keyName, imageResource.fileName,
			imageResource.width, imageResource.height,
			imageResource.frameX, imageResource.frameY,
			imageResource.trans, imageResource.transColor);
	}
	break;

	case LOADING_KIND_FRAMEIMAGE_03:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addPngFrameImage(imageResource.keyName, imageResource.wFileName,
			imageResource.width, imageResource.height,
			imageResource.frameX, imageResource.frameY);
	}
	break;
	case LOADING_KIND_FRAMEIMAGE_04:
	{
		tagResource imageResource = item->getResource();
		IMAGEMANAGER->addFrameImage(imageResource.keyName, imageResource.fileName,
			imageResource.width, imageResource.height,
			imageResource.frameX, imageResource.frameY,
			imageResource.trans, imageResource.transColor,imageResource.multi);
	}
	break;

	case LOADING_KIND_SOUND_00:
	{
		tagResource soundResource = item->getResource();
		SOUNDMANAGER->addSound(soundResource.keyName, soundResource.fileName, soundResource.bgm, soundResource.loop);
	}
	break;
	}


	//카운트 == 로딩률
	_current++;

	return true;
}
