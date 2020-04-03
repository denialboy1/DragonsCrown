#pragma once
#include "singletonBase.h"
#include "image.h"
#include <map>


class imageManager : public singletonBase<imageManager>
{
public:
	typedef map<string, image*> mapImageList;			//�̹��� ����Ʈ ��
	typedef map<string, image*>::iterator mapImageIter;	//�̹��� ����Ʈ ���ͷ�����

	typedef map<string, alphaImage*> mapAlphaImageList;			//���� �̹��� ����Ʈ ��
	typedef map<string, alphaImage*>::iterator mapAlphaImageIter;	//���� �̹��� ����Ʈ ���ͷ�����

	typedef map<string, pngImage*> mapPngImageList;			//PNG �̹��� ����Ʈ ��
	typedef map<string, pngImage*>::iterator mapPngImageIter;	//PNG �̹��� ����Ʈ ���ͷ�����

private:
	mapImageList _mImageList;	//������ ������ �̹��� ����Ʈ
	mapAlphaImageList _mAlphaImageList; //������ ������ ���� �̹��� ����Ʈ
	mapPngImageList _mPngImageList; //������ ������ ���� �̹��� ����Ʈ
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

	//������ �̹���
	image* addFrameImage(string strKey, const char* fileName, float x, float y,
		int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);

	image* addFrameImage(string strKey, const char* fileName, int width, int height,
		int frameX, int frameY, bool trans, COLORREF transColor);

	image* addFrameImage(string strKey, const char* fileName, int width, int height,
		int frameX, int frameY, bool trans, COLORREF transColor,bool multi);

	//////////////////////////���� �̹���///////////////////
	alphaImage* addAlphaImage(string strKey, int width, int height);

	alphaImage* addAlphaImage(string strKey, const DWORD resID,
		int width, int height, bool trans, COLORREF transColor);

	alphaImage* addAlphaImage(string strKey, const char* fileName,
		int width, int height, bool trans, COLORREF transColor);

	alphaImage* addAlphaImage(string strKey, const char* fileName,
		float x, float y, int width, int height, bool trans, COLORREF transColor, bool multi);

	//������ �̹���
	alphaImage* addAlphaFrameImage(string strKey, const char* fileName, float x, float y,
		int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);

	alphaImage* addAlphaFrameImage(string strKey, const char* fileName, int width, int height,
		int frameX, int frameY, bool trans, COLORREF transColor);

	///////////////////////png �̹���/////////////////////////
	pngImage* addPngImage(string strKey, const WCHAR* fileName, int width, int height);

	pngImage* addPngImage(string strKey, const WCHAR* fileName, float x, float y, int width, int height, bool multi);

	//������ �̹���
	pngImage* addPngFrameImage(string strKey, const WCHAR* fileName, float x, float y, int width, int height, int frameX, int frameY);

	pngImage* addPngFrameImage(string strKey, const WCHAR* fileName, int width, int height, int frameX, int frameY);


	////////////////////////////////////////
	//�̹��� ã�� �Լ�
	image* findImage(string strKey);
	alphaImage* findAlphaImage(string strKey);
	pngImage* findPngImage(string strKey);
	//�̹��� �����
	BOOL deleteImage(string strKey);
	BOOL deleteAlphaImage(string strKey);
	BOOL deletePngImage(string strKey);

	BOOL deleteAll(void);
	BOOL deleteAlphaAll(void);
	BOOL deletePngAll(void);

	//�����Լ�
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


	//png ���� �Լ�
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

