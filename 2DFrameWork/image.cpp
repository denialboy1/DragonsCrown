#include "stdafx.h"
#include "image.h"

#pragma comment (lib, "msimg32.lib")

//��� �̴ϼ� ������� �ʱ�ȭ
image::image() : _imageInfo(NULL), _fileName(NULL), _trans(false), _transColor(RGB(0, 0, 0))
{
}


image::~image()
{
}

//�� ��Ʈ�� �̹��� �����
HRESULT image::init(int width, int height)
{
	//�ʱ�ȭ�� �ٽ� �Ǵ°��� ����
	if (_imageInfo != NULL) release();

	//DC���´�
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = 0;
	_imageInfo->y = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = 0;
	_imageInfo->maxFrameY = 0;
	_imageInfo->frameWidth = width;
	_imageInfo->frameHeight = height;

	_fileName = NULL;

	//���� �÷� ����
	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	return S_OK;
}


//���ҽ��κ��� �о��
HRESULT image::init(const DWORD resID, int width, int height,BOOL trans, COLORREF transColor)
{
	//�ʱ�ȭ�� �ٽ� �Ǵ°��� ����
	if (_imageInfo != NULL) release();

	//DC���´�
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_RESOURCE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = 0;
	_imageInfo->y = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = 0;
	_imageInfo->maxFrameY = 0;
	_imageInfo->frameWidth = width;
	_imageInfo->frameHeight = height;

	_fileName = NULL;

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���� �÷� ����
	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	return S_OK;
}


//�̹��� ����(���Ϸκ��� �о��)
HRESULT image::init(const char* fileName, int width, int height,BOOL trans, COLORREF transColor)
{
	//���� ��ΰ� �߸� �Ǿ�����....
	if (fileName == NULL) return E_FAIL;

	//�ʱ�ȭ�� �ٽ� �Ǵ°��� ����
	if (_imageInfo != NULL) release();

	//DC���´�
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = 0;
	_imageInfo->y = 0;
	_imageInfo->frameWidth = width;
	_imageInfo->frameHeight = height;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;

	//���� ��� �̸� ����
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	return S_OK;
}



HRESULT image::init(const char* fileName, float x, float y, int width, int height,BOOL trans, COLORREF transColor)
{
	//���� ��ΰ� �߸� �Ǿ�����....
	if (fileName == NULL) return E_FAIL;

	//�ʱ�ȭ�� �ٽ� �Ǵ°��� ����
	if (_imageInfo != NULL) release();

	//DC���´�
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x - (width / 2);
	_imageInfo->y = y - (height / 2);
	_imageInfo->frameWidth = width;
	_imageInfo->frameHeight = height;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->maxFrameX = 0;
	_imageInfo->maxFrameY = 0;

	//���� ��� �̸� ����
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	
	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	return S_OK;
}



//�̹��� + ������ ���� �ʱ�ȭ
HRESULT image::init(const char* fileName, float x, float y, int width, int height,int frameX, int frameY, BOOL trans, COLORREF transColor)
{
	//���� ��ΰ� �߸� �Ǿ�������
	if (fileName == NULL) return E_FAIL;

	//�ʱ�ȭ �ٽõǴ°��� ����
	if (_imageInfo != NULL) release();

	//DC��´�
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x - (width / 2);
	_imageInfo->y = y - (height / 2);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	//���� ��� �̸� ����
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}


	return S_OK;
}



HRESULT image::init(const char* fileName, int width, int height, int frameX, int frameY,BOOL trans, COLORREF transColor)
{
	//���� ��ΰ� �߸� �Ǿ�������
	if (fileName == NULL) return E_FAIL;

	//�ʱ�ȭ �ٽõǴ°��� ����
	if (_imageInfo != NULL) release();

	//DC��´�
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = 0;
	_imageInfo->y = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	//���� ��� �̸� ����
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);


	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}


	return S_OK;
}


//����
void image::release(void)
{
	if (_imageInfo)
	{
		//�̹��� ����
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		//������ ����
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);

		//���� �÷� �ʱ�ȭ
		_trans = false;
		_transColor = RGB(0, 0, 0);
	}
}


//���� Ű��(RGB��) ���� == Ư�������� ���ؼ� ������
void image::setTransColor(BOOL trans, COLORREF transColor)
{
	_trans = trans;
	_transColor = transColor;
}

//����
void image::render(HDC hdc)
{
	if (_trans)
	{
		//TransparentBlt�� �ִ�
		//
		GdiTransparentBlt(hdc,	//������ ����� DC
			(int)_imageInfo->x,	//����� ��ǥ ������ X
			(int)_imageInfo->y,	//����� ��ǥ ������ Y
			_imageInfo->width,	//����� ũ�� width
			_imageInfo->height,	//����� ũ�� height
			_imageInfo->hMemDC,	//������ DC,
			0, 0,				//���� ��������
			_imageInfo->width,	//����� �������� width
			_imageInfo->height,	//����� �������� height
			_transColor);		//���翡�� ������ ���� ����
	}
	else
	{
		//BitBlt �� DC���� �������� ���� ��Ӻ��縦 ���ִ� �Լ��̴�.
		BitBlt(hdc, (int)_imageInfo->x, (int)_imageInfo->y,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}



//����
void image::render(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		GdiTransparentBlt(hdc,
			destX,
			destY,
			_imageInfo->width,
			_imageInfo->height,
			_imageInfo->hMemDC,
			0, 0,
			_imageInfo->width,
			_imageInfo->height,
			_transColor);
	}
	else
	{
		//BitBlt == DC���� �������� ���� ��Ӻ��� ���ִ� �Լ�
		BitBlt(hdc, destX, destY,
			_imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, SRCCOPY);
	}
}

//destX destY ��ġ�� sourX, sourY��ǥ�� �׸��� sourWidth, sourHeight ũ�⸦ �ѷ���
void image::render(HDC hdc, int destX, int destY, int sourX, int sourY,
	int sourWidth, int sourHeight)
{
	if (_trans)
	{
		GdiTransparentBlt(hdc,
			destX,
			destY,
			sourWidth,
			sourHeight,
			_imageInfo->hMemDC,
			sourX, sourY,
			sourWidth,
			sourHeight,
			_transColor);
	}
	else
	{
		//BitBlt == DC���� �������� ���� ��Ӻ��� ���ִ� �Լ�
		BitBlt(hdc, destX, destY,
			sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, SRCCOPY);
	}
}

//������ ����
void image::frameRender(HDC hdc, int destX, int destY)
{
	if (_trans)
	{
		GdiTransparentBlt(hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		//BitBlt == DC���� �������� ���� ��Ӻ��� ���ִ� �Լ�
		BitBlt(hdc, destX, destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			_imageInfo->currentFrameX * _imageInfo->frameWidth,
			_imageInfo->currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}
void image::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		GdiTransparentBlt(hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			currentFrameX * _imageInfo->frameWidth,
			currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_transColor);
	}
	else
	{
		//BitBlt == DC���� �������� ���� ��Ӻ��� ���ִ� �Լ�
		BitBlt(hdc,
			destX,
			destY,
			_imageInfo->frameWidth,
			_imageInfo->frameHeight,
			_imageInfo->hMemDC,
			currentFrameX * _imageInfo->frameWidth,
			currentFrameY * _imageInfo->frameHeight,
			SRCCOPY);
	}
}

void image::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	//offset ���� ������ ��쿡 �����Ѵ�
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	//�׷����� �ҽ��� ����(�̹���) ������ ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//�׷����� ������ DC
	RECT rcDest;

	//�׷����� ��ü ����
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//�̹��� �ҽ�(sour) ������ ���� ���
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		//�ҽ��� ������ ��ο� ��Ʈ ������ ������(���������� �̹����� ������)
		if (y + sourHeight > drawAreaH)
		{
			//�Ѿ �׸��� ����ŭ ���� ���� �÷���
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//���� ��
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			//�ҽ��� ���� ���� ���
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW)
			{
				//�Ѿ �縸ŭ right���� �ٽ� ��������
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			//�׷����� ����
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			//�׷��ش�
			render(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top);
		}
	}
}

void image::aniRender(HDC hdc, int destX, int destY, animation* ani)
{
	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}

alphaImage::alphaImage(){}
alphaImage::~alphaImage(){}

HRESULT alphaImage::init(int width, int height){
	//�ʱ�ȭ�� �ٽ� �Ǵ°��� ����
	if (_imageInfo != NULL) release();

	//DC���´�
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_EMPTY;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = 0;
	_imageInfo->y = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = 0;
	_imageInfo->maxFrameY = 0;
	_imageInfo->frameWidth = width;
	_imageInfo->frameHeight = height;

	_fileName = NULL;

	//���� �÷� ����
	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	//���ĺ��� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	return S_OK;
}

HRESULT alphaImage::init(const DWORD resID, int width, int height, BOOL trans, COLORREF transColor){
	//�ʱ�ȭ�� �ٽ� �Ǵ°��� ����
	if (_imageInfo != NULL) release();

	//DC���´�
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_RESOURCE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, width, height);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = 0;
	_imageInfo->y = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->maxFrameX = 0;
	_imageInfo->maxFrameY = 0;
	_imageInfo->frameWidth = width;
	_imageInfo->frameHeight = height;

	_fileName = NULL;

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���� �÷� ����
	_trans = FALSE;
	_transColor = RGB(0, 0, 0);

	//���ĺ��� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	return S_OK;
}

HRESULT alphaImage::init(const char* fileName, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor){
	//���� ��ΰ� �߸� �Ǿ�������
	if (fileName == NULL) return E_FAIL;

	//�ʱ�ȭ �ٽõǴ°��� ����
	if (_imageInfo != NULL) release();

	//DC��´�
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = 0;
	_imageInfo->y = 0;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	//���� ��� �̸� ����
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);


	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	//���ĺ��� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}


	return S_OK;
}

HRESULT alphaImage::init(const char* fileName, float x, float y, int width, int height, BOOL trans, COLORREF transColor){
	//���� ��ΰ� �߸� �Ǿ�����....
	if (fileName == NULL) return E_FAIL;

	//�ʱ�ȭ�� �ٽ� �Ǵ°��� ����
	if (_imageInfo != NULL) release();

	//DC���´�
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x - (width / 2);
	_imageInfo->y = y - (height / 2);
	_imageInfo->frameWidth = width;
	_imageInfo->frameHeight = height;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->maxFrameX = 0;
	_imageInfo->maxFrameY = 0;

	//���� ��� �̸� ����
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	//���ĺ��� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	return S_OK;
}

HRESULT alphaImage::init(const char* fileName, int width, int height, BOOL trans, COLORREF transColor){
	//���� ��ΰ� �߸� �Ǿ�����....
	if (fileName == NULL) return E_FAIL;

	//�ʱ�ȭ�� �ٽ� �Ǵ°��� ����
	if (_imageInfo != NULL) release();

	//DC���´�
	HDC hdc = GetDC(_hWnd);

	//CreateCompatibleDC
	//��Ʈ���� ����ϱ� ���ؼ� �޸� DC�� ����� �ִ� ��

	//CreateCompatibleBitMap
	//���� DC�� ȣȯ�Ǵ� ��Ʈ�� ����

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = 0;
	_imageInfo->y = 0;
	_imageInfo->frameWidth = width;
	_imageInfo->frameHeight = height;
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;

	//���� ��� �̸� ����
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	//���ĺ��� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}

	return S_OK;
}

HRESULT alphaImage::init(const char* fileName, float x, float y, int width, int height, int frameX, int frameY, BOOL trans, COLORREF transColor){
	//���� ��ΰ� �߸� �Ǿ�������
	if (fileName == NULL) return E_FAIL;

	//�ʱ�ȭ �ٽõǴ°��� ����
	if (_imageInfo != NULL) release();

	//DC��´�
	HDC hdc = GetDC(_hWnd);

	//�̹��� ���� ����
	_imageInfo = new IMAGE_INFO;
	_imageInfo->loadType = LOAD_FILE;
	_imageInfo->resID = 0;
	_imageInfo->hMemDC = CreateCompatibleDC(hdc);
	_imageInfo->hBit = (HBITMAP)LoadImage(_hInstance, fileName, IMAGE_BITMAP, width, height, LR_LOADFROMFILE);
	_imageInfo->hOBit = (HBITMAP)SelectObject(_imageInfo->hMemDC, _imageInfo->hBit);
	_imageInfo->x = x - (width / 2);
	_imageInfo->y = y - (height / 2);
	_imageInfo->width = width;
	_imageInfo->height = height;
	_imageInfo->currentFrameX = 0;
	_imageInfo->currentFrameY = 0;
	_imageInfo->frameWidth = width / frameX;
	_imageInfo->frameHeight = height / frameY;
	_imageInfo->maxFrameX = frameX - 1;
	_imageInfo->maxFrameY = frameY - 1;

	//���� ��� �̸� ����
	int len = strlen(fileName);
	_fileName = new CHAR[len + 1];
	strcpy_s(_fileName, len + 1, fileName);

	//���� �÷� ����
	_trans = trans;
	_transColor = transColor;

	//���ĺ��� �ɼ�
	_blendFunc.BlendFlags = 0;
	_blendFunc.AlphaFormat = 0;
	_blendFunc.BlendOp = AC_SRC_OVER;

	//���� ���� ����� ���� �̹��� ����
	_blendImage = new IMAGE_INFO;
	_blendImage->loadType = LOAD_EMPTY;
	_blendImage->resID = 0;
	_blendImage->hMemDC = CreateCompatibleDC(hdc);
	_blendImage->hBit = (HBITMAP)CreateCompatibleBitmap(hdc, WINSIZEX, WINSIZEY);
	_blendImage->hOBit = (HBITMAP)SelectObject(_blendImage->hMemDC, _blendImage->hBit);
	_blendImage->width = WINSIZEX;
	_blendImage->height = WINSIZEY;

	//���� DC ����
	ReleaseDC(_hWnd, hdc);

	//���ҽ� ������ ���н� ó��
	if (_imageInfo->hBit == 0)
	{
		release();

		return E_FAIL;
	}


	return S_OK;
}

void alphaImage::release(void){
	if (_imageInfo)
	{
		//�̹��� ����
		SelectObject(_imageInfo->hMemDC, _imageInfo->hOBit);
		DeleteObject(_imageInfo->hBit);
		DeleteDC(_imageInfo->hMemDC);

		//���ĺ��� ��� �̹��� ����
		SelectObject(_blendImage->hMemDC, _blendImage->hOBit);
		DeleteObject(_blendImage->hBit);
		DeleteDC(_blendImage->hMemDC);

		//������ ����
		SAFE_DELETE(_imageInfo);
		SAFE_DELETE(_fileName);
		SAFE_DELETE(_blendImage);

		//���� �÷� �ʱ�ȭ
		_trans = false;
		_transColor = RGB(0, 0, 0);
	}
}

void alphaImage::alphaRender(HDC hdc, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		//����ؾߵ� DC�� �׷����ִ� ������ blend�� �׸���
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, (int)_imageInfo->x, (int)_imageInfo->y, SRCCOPY);

		//����ؾߵ� �̹����� Blend�� �ű��
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, (int)_imageInfo->x, (int)_imageInfo->y, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, (int)_imageInfo->x, (int)_imageInfo->y, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}

}

void alphaImage::alphaRender(HDC hdc, int destX, int destY, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		//����ؾߵ� DC�� �׷����ִ� ������ blend�� �׸���
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		//����ؾߵ� �̹����� Blend�� �ű��
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _transColor);

		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
	else
	{
		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, destX, destY, _imageInfo->width, _imageInfo->height,
			_imageInfo->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height, _blendFunc);
	}
}

void alphaImage::alphaRender(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		//����ؾߵ� DC�� �׷����ִ� ������ blend�� �׸���
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->width, _imageInfo->height,
			hdc, destX, destY, SRCCOPY);

		//����ؾߵ� �̹����� Blend�� �ű��
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _transColor);

		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
			_blendImage->hMemDC, 0, 0, sourWidth, sourHeight, _blendFunc);
	}
	else
	{
		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, destX, destY, sourWidth, sourHeight,
			_imageInfo->hMemDC, sourX, sourY, sourWidth, sourHeight, _blendFunc);
	}
}

void alphaImage::alphaLoopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
	//offset ���� ������ ��쿡 �����Ѵ�
	if (offsetX < 0) offsetX = _imageInfo->width + (offsetX % _imageInfo->width);
	if (offsetY < 0) offsetY = _imageInfo->height + (offsetY % _imageInfo->height);

	//�׷����� �ҽ��� ����(�̹���) ������ ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//�׷����� ������ DC
	RECT rcDest;

	//�׷����� ��ü ����
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//�̹��� �ҽ�(sour) ������ ���� ���
		rcSour.top = (y + offsetY) % _imageInfo->height;
		rcSour.bottom = _imageInfo->height;
		sourHeight = rcSour.bottom - rcSour.top;

		//�ҽ��� ������ ��ο� ��Ʈ ������ ������(���������� �̹����� ������)
		if (y + sourHeight > drawAreaH)
		{
			//�Ѿ �׸��� ����ŭ ���� ���� �÷���
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//���� ��
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			//�ҽ��� ���� ���� ���
			rcSour.left = (x + offsetX) % _imageInfo->width;
			rcSour.right = _imageInfo->width;
			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW)
			{
				//�Ѿ �縸ŭ right���� �ٽ� ��������
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			//�׷����� ����
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			//�׷��ش�
			alphaRender(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top,alpha);
		}
	}
}


void alphaImage::alphaFrameRender(HDC hdc, int destX, int destY, BYTE alpha){
	_blendFunc.SourceConstantAlpha = alpha;

	if (_trans)
	{
		//����ؾߵ� DC�� �׷����ִ� ������ blend�� �׸���
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->frameWidth, _imageInfo->frameHeight,
			hdc, destX, destY, SRCCOPY);

		//����ؾߵ� �̹����� Blend�� �ű��
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, _imageInfo->currentFrameX * _imageInfo->frameWidth, _imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _transColor);

		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_blendImage->hMemDC, 0, 0, _imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
	}
	else
	{
		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, _imageInfo->currentFrameX * _imageInfo->frameWidth, _imageInfo->currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
	}
}
void alphaImage::alphaFrameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY, BYTE alpha){
	_blendFunc.SourceConstantAlpha = alpha;
	_imageInfo->currentFrameX = currentFrameX;
	_imageInfo->currentFrameY = currentFrameY;

	if (_trans)
	{
		//����ؾߵ� DC�� �׷����ִ� ������ blend�� �׸���
		BitBlt(_blendImage->hMemDC, 0, 0, _imageInfo->frameWidth, _imageInfo->frameHeight,
			hdc, destX, destY, SRCCOPY);

		//����ؾߵ� �̹����� Blend�� �ű��
		GdiTransparentBlt(_blendImage->hMemDC, 0, 0, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, currentFrameX * _imageInfo->frameWidth, currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _transColor);

		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_blendImage->hMemDC, 0, 0, _imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
	}
	else
	{
		//BlendDC�� ����ؾߵ� ��� �׸���
		AlphaBlend(hdc, destX, destY, _imageInfo->frameWidth, _imageInfo->frameHeight,
			_imageInfo->hMemDC, currentFrameX * _imageInfo->frameWidth, currentFrameY * _imageInfo->frameHeight,
			_imageInfo->frameWidth, _imageInfo->frameHeight, _blendFunc);
	}
}
void alphaImage::alphaAniRender(HDC hdc, int destX, int destY, animation* ani, BYTE alpha)
{
	alphaRender(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight(), alpha);
}



HRESULT pngImage::init(int width, int height){

	_width = width;
	_height = height;
	_x = 0;
	_y = 0;
	_frameX = 0;
	_frameY = 0;
	_frameWidth = width;
	_frameHeight = height;
	_maxFrameX = 0;
	_maxFrameY = 0;
	_rcDest = { _x, _y, _width, _height };
	//���� ��� �̸� ����
	_fileName = NULL;

	return S_OK;
}

//�̹��� ����(���Ϸκ��� �о��)
HRESULT pngImage::init(const WCHAR* fileName, int width, int height)
{
	//���� ��ΰ� �߸� �Ǿ�����....
	if (fileName == NULL) return E_FAIL;

	_width = width;
	_height = height;
	_x = 0;
	_y = 0;
	_frameX = 0;
	_frameY = 0;
	_frameWidth = width;
	_frameHeight = height;
	_maxFrameX = 0;
	_maxFrameY = 0;
	_rcDest = { _x, _y, _width, _height };
	//���� ��� �̸� ����
	int len = lstrlenW(fileName);
	_fileName = new WCHAR[len + 1];
	lstrcpyW(_fileName, fileName);

	return S_OK;
}



HRESULT pngImage::init(const WCHAR* fileName, float x, float y, int width, int height)
{
	//���� ��ΰ� �߸� �Ǿ�����....
	if (fileName == NULL) return E_FAIL;

	_width = width;
	_height = height;
	_x = x;
	_y = y;
	_frameX = 0;
	_frameY = 0;
	_frameWidth = width;
	_frameHeight = height;
	_maxFrameX = 0;
	_maxFrameY = 0;
	_rcDest = { _x, _y, _width, _height };
	//���� ��� �̸� ����
	int len = lstrlenW(fileName);
	_fileName = new WCHAR[len + 1];
	lstrcpyW(_fileName, fileName);

	return S_OK;
}



//�̹��� + ������ ���� �ʱ�ȭ
HRESULT pngImage::init(const WCHAR* fileName, float x, float y, int width, int height, int frameX, int frameY)
{
	//���� ��ΰ� �߸� �Ǿ�����....
	if (fileName == NULL) return E_FAIL;

	_width = width;
	_height = height;
	_x = x;
	_y = y;
	_frameX = frameX;
	_frameY = frameY;
	_frameWidth = width/_frameX;
	_frameHeight = height/_frameY;
	_maxFrameX = _frameWidth-1;
	_maxFrameY = _frameHeight - 1;
	_rcDest = { _x, _y, _width, _height };
	//���� ��� �̸� ����
	int len = lstrlenW(fileName);
	_fileName = new WCHAR[len + 1];
	lstrcpyW(_fileName, fileName);

	return S_OK;
}



HRESULT pngImage::init(const WCHAR* fileName, int width, int height, int frameX, int frameY)
{
	//���� ��ΰ� �߸� �Ǿ�����....
	if (fileName == NULL) return E_FAIL;

	_width = width;
	_height = height;
	_x = 0;
	_y = 0;
	_frameX = frameX;
	_frameY = frameY;
	_frameWidth = width / _frameX;
	_frameHeight = height / _frameY;
	_maxFrameX = _frameWidth - 1;
	_maxFrameY = _frameHeight - 1;
	//���� ��� �̸� ����
	int len = lstrlenW(fileName);
	_fileName = new WCHAR[len + 1];
	lstrcpyW(_fileName, fileName);


	Image image(_fileName);
	_img = image.Clone();
	return S_OK;
}

//����
void pngImage::render(HDC hdc){
	
	Image _image(_fileName);
	Graphics graphics(hdc);
	graphics.DrawImage(&_image, _x, _y, _width, _height);
}
void pngImage::render(HDC hdc, int destX, int destY){
	Image _image(_fileName);
	Graphics graphics(hdc);
	graphics.DrawImage(&_image, destX, destY, _width, _height);
}
void pngImage::render(HDC hdc, int destX, int destY, int sourX, int sourY,	int sourWidth, int sourHeight){
	Image _image(_fileName);
	Graphics graphics(hdc);
	Gdiplus::Rect _rc = { destX, destY, _width,_height };
	graphics.DrawImage(&_image, _rc,sourX,sourY,sourWidth,sourHeight,UnitPixel);
}

void pngImage::render(HDC hdc, int destX, int destY,int width,int height, int sourX, int sourY, int sourWidth, int sourHeight){
	Image _image(_fileName);
	Graphics graphics(hdc);
	Gdiplus::Rect _rc = { destX, destY, width, height };
	graphics.DrawImage(&_image, _rc, sourX, sourY, sourWidth, sourHeight, UnitPixel);
}

//������ ����
void pngImage::frameRender(HDC hdc, int destX, int destY){
	Image _image(_fileName);
	Graphics graphics(hdc);
	graphics.DrawImage(&_image, destX, destY, _frameWidth * _currentFrameX, _frameHeight*_currentFrameY, _frameWidth, _frameHeight, UnitPixel);
}
void pngImage::frameRender(HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY){
	//Image _image(_fileName);
	Graphics graphics(hdc);
	graphics.DrawImage(_img, destX, destY, _frameWidth * currentFrameX, _frameHeight * currentFrameY, _frameWidth, _frameHeight, UnitPixel);
}

void pngImage::loopRender(HDC hdc, const LPRECT drawArea, int offsetX, int offsetY){
	//offset ���� ������ ��쿡 �����Ѵ�
	if (offsetX < 0) offsetX = _width + (offsetX % _width);
	if (offsetY < 0) offsetY = _height + (offsetY % _height);

	//�׷����� �ҽ��� ����(�̹���) ������ ����
	RECT rcSour;
	int sourWidth;
	int sourHeight;

	//�׷����� ������ DC
	RECT rcDest;

	//�׷����� ��ü ����
	int drawAreaX = drawArea->left;
	int drawAreaY = drawArea->top;
	int drawAreaW = drawArea->right - drawArea->left;
	int drawAreaH = drawArea->bottom - drawArea->top;

	//���� ���� ����
	for (int y = 0; y < drawAreaH; y += sourHeight)
	{
		//�̹��� �ҽ�(sour) ������ ���� ���
		rcSour.top = (y + offsetY) % _height;
		rcSour.bottom = _height;
		sourHeight = rcSour.bottom - rcSour.top;

		//�ҽ��� ������ ��ο� ��Ʈ ������ ������(���������� �̹����� ������)
		if (y + sourHeight > drawAreaH)
		{
			//�Ѿ �׸��� ����ŭ ���� ���� �÷���
			rcSour.bottom -= (y + sourHeight) - drawAreaH;
			sourHeight = rcSour.bottom - rcSour.top;
		}

		rcDest.top = y + drawAreaY;
		rcDest.bottom = rcDest.top + sourHeight;

		//���� ��
		for (int x = 0; x < drawAreaW; x += sourWidth)
		{
			//�ҽ��� ���� ���� ���
			rcSour.left = (x + offsetX) % _width;
			rcSour.right = _width;
			sourWidth = rcSour.right - rcSour.left;

			if (x + sourWidth > drawAreaW)
			{
				//�Ѿ �縸ŭ right���� �ٽ� ��������
				rcSour.right -= (x + sourWidth) - drawAreaW;
				sourWidth = rcSour.right - rcSour.left;
			}

			//�׷����� ����
			rcDest.left = x + drawAreaX;
			rcDest.right = rcDest.left + sourWidth;

			//�׷��ش�
			render(hdc, rcDest.left, rcDest.top,
				rcSour.left, rcSour.top,
				rcSour.right - rcSour.left,
				rcSour.bottom - rcSour.top);
		}
	}

}

void pngImage::aniRender(HDC hdc, int destX, int destY, animation* ani){
	render(hdc, destX, destY, ani->getFramePos().x, ani->getFramePos().y, ani->getFrameWidth(), ani->getFrameHeight());
}

void pngImage::release(){
	if (_fileName){
		SAFE_DELETE(_fileName);
	}
}