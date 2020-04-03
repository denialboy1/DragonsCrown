#pragma once
#include "singletonBase.h"
#include "image.h"
#include <map>


class imageManager : public singletonBase<imageManager>
{
public:
	typedef map<string, image*> mapImageList;			//이미지 리스트 맵
	typedef map<string, image*>::iterator mapImageIter;	//이미지 리스트 이터레이터

	typedef map<string, alphaImage*> mapAlphaImageList;			//알파 이미지 리스트 맵
	typedef map<string, alphaImage*>::iterator mapAlphaImageIter;	//알파 이미지 리스트 이터레이터

	typedef map<string, pngImage*> mapPngImageList;			//PNG 이미지 리스트 맵
	typedef map<string, pngImage*>::iterator mapPngImageIter;	//PNG 이미지 리스트 이터레이터

private:
	mapImageList _mImageList;	//맵으로 구현된 이미지 리스트
	mapAlphaImageList _mAlphaImageList; //맵으로 구현된 알파 이미지 리스트
	mapPngImageList _mPngImageList; //맵으로 구현된 알파 이미지 리스트
public:
	HRESULT init();

	void release();

	image* addImage(string strKey, int width, int height);

	image* addImage(string strKey, const DWORD resID,
		int width, int height, bool trans, COLORREF transColor);

	image* addImage(string strKey, const char* fileName,
		int width, int height, bool trans, COLORREF transColor);

	image* addImage(string strKey, const char* fileName,
		float x, float y, int width, int height, bool trans, COLORREF transColor, bool multi);

	//프레임 이미지
	image* addFrameImage(string strKey, const char* fileName, float x, float y,
		int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);

	image* addFrameImage(string strKey, const char* fileName, int width, int height,
		int frameX, int frameY, bool trans, COLORREF transColor);

	image* addFrameImage(string strKey, const char* fileName, int width, int height,
		int frameX, int frameY, bool trans, COLORREF transColor,bool multi);

	//////////////////////////알파 이미지///////////////////
	alphaImage* addAlphaImage(string strKey, int width, int height);

	alphaImage* addAlphaImage(string strKey, const DWORD resID,
		int width, int height, bool trans, COLORREF transColor);

	alphaImage* addAlphaImage(string strKey, const char* fileName,
		int width, int height, bool trans, COLORREF transColor);

	alphaImage* addAlphaImage(string strKey, const char* fileName,
		float x, float y, int width, int height, bool trans, COLORREF transColor, bool multi);

	//프레임 이미지
	alphaImage* addAlphaFrameImage(string strKey, const char* fileName, float x, float y,
		int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);

	alphaImage* addAlphaFrameImage(string strKey, const char* fileName, int width, int height,
		int frameX, int frameY, bool trans, COLORREF transColor);

	///////////////////////png 이미지/////////////////////////
	pngImage* addPngImage(string strKey, const WCHAR* fileName, int width, int height);

	pngImage* addPngImage(string strKey, const WCHAR* fileName, float x, float y, int width, int height, bool multi);

	//프레임 이미지
	pngImage* addPngFrameImage(string strKey, const WCHAR* fileName, float x, float y, int width, int height, int frameX, int frameY);

	pngImage* addPngFrameImage(string strKey, const WCHAR* fileName, int width, int height, int frameX, int frameY);


	////////////////////////////////////////
	//이미지 찾는 함수
	image* findImage(string strKey);
	alphaImage* findAlphaImage(string strKey);
	pngImage* findPngImage(string strKey);
	//이미지 지운다
	BOOL deleteImage(string strKey);
	BOOL deleteAlphaImage(string strKey);
	BOOL deletePngImage(string strKey);

	BOOL deleteAll(void);
	BOOL deleteAlphaAll(void);
	BOOL deletePngAll(void);

	//렌더함수
	void render(string strKey, HDC hdc);
	void render(string strKey, HDC hdc, int destX, int destY);
	void render(string strKey, HDC hdc, int destX, int destY,
		int sourX, int sourY, int sourWidth, int sourHeight);

	void frameRender(string strKey, HDC hdc, int destX, int destY);
	void frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);


	void loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	void alphaLoopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY,BYTE alpha);

	void alphaRender(string strKey, HDC hdc, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);


	//png 렌더 함수
	void pngRender(string strKey, HDC hdc);
	void pngRender(string strKey, HDC hdc, int destX, int destY);
	void pngRender(string strKey, HDC hdc, int destX, int destY,
		int sourX, int sourY, int sourWidth, int sourHeight);
	void pngRender(string strKey, HDC hdc, int destX, int destY,int width,int height,int sourX, int sourY, int sourWidth, int sourHeight);

	void pngFrameRender(string strKey, HDC hdc, int destX, int destY);
	void pngFrameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);
	void pngLoopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	imageManager();
	~imageManager();
};

