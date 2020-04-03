#pragma once
#include "animation.h"
#include <ObjIdl.h>
#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib,"Gdiplus.lib")
//====================================================
// 2015.05.08 ## image Class ## - Thursday Of Blood -
//====================================================

class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE = 0,	//���ҽ��κ��� ����
		LOAD_FILE,			//���Ϸκ��� ����
		LOAD_EMPTY,			//�� ����
		LOAD_END
	};

	typedef struct tagImageInfo
	{
		DWORD resID;
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		int x;
		int y;
		int width;
		int height;

		int currentFrameX;		//���� ������X
		int currentFrameY;		//���� ������Y
		int maxFrameX;			//�ִ� ������X
		int maxFrameY;			//�ִ� ������Y
		int frameWidth;			//������ ����ũ��
		int frameHeight;		//������ ����ũ��

		BYTE loadType;
		RECT boundingBox;		//�̹����� �ٷ� ��Ʈ������� ����

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			currentFrameX = 0;
			currentFrameY = 0;
			maxFrameX = 0;
			maxFrameY = 0;
			frameWidth = 0;
			frameHeight = 0;
			loadType = LOAD_RESOURCE;
			boundingBox = RectMake(0, 0, 0, 0);
		}

	}IMAGE_INFO, *LPIMAGE_INFO;

public:
	//������ ���ÿ� ����̴ϼ� ������� �ٷ� �ʱ�ȭ ���ִ� ����
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;
	BOOL			_trans;
	COLORREF		_transColor;



public:
	image();
	~image();

	//�� ��Ʈ�� �̹��� �����
	HRESULT init(int width, int height);

	//���ҽ��κ��� �о��
	HRESULT init(const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	//�̹��� ����(���Ϸκ��� �о��)
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	//�̹��� + ������ ���� �ʱ�ȭ
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY,
		BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));


	//����
	void release(void);

	//���� Ű��(RGB��) ���� == Ư�������� ���ؼ� ������
	void setTransColor(BOOL trans, COLORREF transColor);

	//����
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int sourX, int sourY,
		int sourWidth, int sourHeight);

	//������ ����
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	//������
	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	//�ִϷ���
	void aniRender(HDC hdc, int destX, int destY, animation* ani);


	//DC ���´�
	inline HDC getMemDC(void) { return _imageInfo->hMemDC; }

	//��ǥ X
	inline void setX(float x) { _imageInfo->x = x; }
	inline float getX(void) { return _imageInfo->x; }

	//��ǥ Y
	inline void setY(float y) { _imageInfo->y = y; }
	inline float getY(void) { return _imageInfo->y; }

	//��ǥ x y
	inline void setCenter(float x, float y)
	{
		_imageInfo->x = x - (_imageInfo->width / 2);
		_imageInfo->y = y - (_imageInfo->height / 2);
	}

	//���� x
	inline float getCenterX(void)
	{
		return _imageInfo->maxFrameX <= 0 ? _imageInfo->x + (_imageInfo->width / 2) :
			_imageInfo->x + (_imageInfo->frameWidth / 2);
	}

	//���� y
	inline float getCenterY(void)
	{
		return _imageInfo->maxFrameY <= 0 ? _imageInfo->y + (_imageInfo->height / 2) :
			_imageInfo->y + (_imageInfo->frameHeight / 2);
	}

	//���� �ػ�
	inline int getWidth(void) { return _imageInfo->width; }

	//���� �ػ�
	inline int getHeight(void) { return _imageInfo->height; }

	//�ٿ�� �ڽ�
	inline RECT boundingBox(void)
	{
		RECT rc = { int(_imageInfo->x - (_imageInfo->width / 2)),
			int(_imageInfo->y - (_imageInfo->height / 2)),
			int(_imageInfo->x + (_imageInfo->frameWidth / 2)),
			int(_imageInfo->y + (_imageInfo->frameHeight / 2)) };

		return rc;
	}



	//������
	inline void setFrameX(int frameX)
	{
		_imageInfo->currentFrameX = frameX;
		if (frameX > _imageInfo->maxFrameX) _imageInfo->currentFrameX = _imageInfo->maxFrameX;
	}

	inline void setFrameY(int frameY)
	{
		_imageInfo->currentFrameY = frameY;
		if (frameY > _imageInfo->maxFrameY) _imageInfo->currentFrameY = _imageInfo->maxFrameY;
	}

	inline int getMaxFrameX(void) { return _imageInfo->maxFrameX; }
	inline int getMaxFrameY(void) { return _imageInfo->maxFrameY; }

	inline int getFrameX(void) { return _imageInfo->currentFrameX; }
	inline int getFrameY(void) { return _imageInfo->currentFrameY; }

	inline int getFrameWidth(void) { return _imageInfo->frameWidth; }
	inline int getFrameHeight(void) { return _imageInfo->frameHeight; }

};

class alphaImage : public image
{
private:
	image* image;
	BLENDFUNCTION	_blendFunc;		//���ĺ��带 ���� ����
	LPIMAGE_INFO	_blendImage;	//���ĺ��带 ����ϱ� ���� �̹��� ����

public :
	alphaImage();
	~alphaImage();

	//�ʱ�ȭ
	HRESULT init(int width, int height);

	//���ҽ��κ��� �о��
	HRESULT init(const DWORD resID, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	//�̹��� ����(���Ϸκ��� �о��)
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	HRESULT init(const char* fileName, float x, float y, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	//�̹��� + ������ ���� �ʱ�ȭ
	HRESULT init(const char* fileName, float x, float y, int width, int height,
		int frameX, int frameY, BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	HRESULT init(const char* fileName, int width, int height, int frameX, int frameY,
		BOOL trans = FALSE, COLORREF transColor = RGB(255, 0, 255));

	//����
	void release(void);

	//���ķ���
	void alphaRender(HDC hdc, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha);

	//������
	void alphaLoopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY,BYTE alpha);

	void alphaFrameRender(HDC hdc, int destX, int destY, BYTE alpha);
	void alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha);

	void alphaAniRender(HDC hdc, int destX, int destY, animation* ani, BYTE alpha);
};

class pngImage{
private:
	WCHAR*		_fileName;
	int			_width;
	int			_height;
	int			_x, _y;
	int			_currentFrameX, _currentFrameY;
	int			_frameX, _frameY;
	int			_frameWidth, _frameHeight;
	int			_maxFrameX, _maxFrameY;
	Gdiplus::Rect _rcDest;
	Image* _img;
	Graphics* _graphics;
public:
	//�� ��Ʈ�� �̹��� �����
	HRESULT init(int width, int height);

	//�̹��� �ʱ�ȭ
	HRESULT init(const WCHAR* fileName, int width, int height);

	HRESULT init(const WCHAR* fileName, float x, float y, int width, int height);

	//�̹��� + ������ ���� �ʱ�ȭ
	HRESULT init(const WCHAR* fileName, float x, float y, int width, int height, int frameX, int frameY);

	HRESULT init(const WCHAR* fileName, int width, int height, int frameX, int frameY);

	//����
	void render(HDC hdc);
	void render(HDC hdc, int destX, int destY);
	void render(HDC hdc, int destX, int destY, int sourX, int sourY,int sourWidth, int sourHeight);
	void render(HDC hdc, int destX, int destY, int width,int height,int sourX, int sourY, int sourWidth, int sourHeight);

	//������ ����
	void frameRender(HDC hdc, int destX, int destY);
	void frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY);

	void loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY);

	//�ִϷ���
	void aniRender(HDC hdc, int destX, int destY, animation* ani);
	//����
	void release(void);

	//��ǥ X
	inline void setX(float x) { _x = x; }
	inline float getX(void) { return _x; }

	//��ǥ Y
	inline void setY(float y) { _y = y; }
	inline float getY(void) { return _y; }

	//��ǥ x y
	inline void setCenter(float x, float y)
	{
		_x = x - (_width / 2);
		_y = y - (_height / 2);
	}

	//���� x
	inline float getCenterX(void)
	{
		return _maxFrameX <= 0 ? _x + (_width / 2) :
			_x + (_frameWidth / 2);
	}

	//���� y
	inline float getCenterY(void)
	{
		return _maxFrameY <= 0 ? _y + (_height / 2) :
			_y + (_frameHeight / 2);
	}

	//���� �ػ�
	inline int getWidth(void) { return _width; }

	//���� �ػ�
	inline int getHeight(void) { return _height; }

	//�ٿ�� �ڽ�
	inline RECT boundingBox(void)
	{
		RECT rc = { int(_x - (_width / 2)),
			int(_y - (_height / 2)),
			int(_x + (_frameWidth / 2)),
			int(_y + (_frameHeight / 2)) };

		return rc;
	}



	//������
	inline void setFrameX(int frameX)
	{
		_currentFrameX = frameX;
		if (frameX > _maxFrameX) _currentFrameX = _maxFrameX;
	}

	inline void setFrameY(int frameY)
	{
		_currentFrameY = frameY;
		if (frameY > _maxFrameY) _currentFrameY = _maxFrameY;
	}

	inline int getMaxFrameX(void) { return _maxFrameX; }
	inline int getMaxFrameY(void) { return _maxFrameY; }

	inline int getFrameX(void) { return _currentFrameX; }
	inline int getFrameY(void) { return _currentFrameY; }

	inline int getFrameWidth(void) { return _frameWidth; }
	inline int getFrameHeight(void) { return _frameHeight; }
};