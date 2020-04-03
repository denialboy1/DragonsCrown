#include "stdafx.h"
#include "imageManager.h"


imageManager::imageManager()
{
}


imageManager::~imageManager()
{
}

HRESULT imageManager::init()
{
	return S_OK;
}

void imageManager::release()
{
	deleteAll();
}

image* imageManager::addImage(string strKey, int width, int height)
{
	//������ �̹��� �ִ��� ã�´�
	image* img = findImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new image;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addImage(string strKey, const DWORD resID,
	int width, int height, bool trans, COLORREF transColor)
{
	//������ �̹��� �ִ��� ã�´�
	image* img = findImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new image;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(resID, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addImage(string strKey, const char* fileName,
	int width, int height, bool trans, COLORREF transColor)
{
	//������ �̹��� �ִ��� ã�´�
	image* img = findImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new image;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;

}

image* imageManager::addImage(string strKey, const char* fileName,
	float x, float y, int width, int height, bool trans, COLORREF transColor, bool multi)
{
	//������ �̹��� �ִ��� ã�´�
	image* img = findImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (!multi) {
		if (img) return img;
	}

	//�̹��� ����
	img = new image;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}



//������ �̹���
image* imageManager::addFrameImage(string strKey, const char* fileName, float x, float y,
	int width, int height, int frameX, int frameY, bool trans, COLORREF transColor)
{
	//������ �̹��� �ִ��� ã�´�
	image* img = findImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new image;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addFrameImage(string strKey, const char* fileName, int width, int height,
	int frameX, int frameY, bool trans, COLORREF transColor)
{
	//������ �̹��� �ִ��� ã�´�
	image* img = findImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new image;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* imageManager::addFrameImage(string strKey, const char* fileName, int width, int height,
	int frameX, int frameY, bool trans, COLORREF transColor,bool multi)
{

	//������ �̹��� �ִ��� ã�´�
	image* img = findImage(strKey);

	if (!multi){
		//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
		if (img) return img;
	}

	//�̹��� ����
	img = new image;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}


alphaImage* imageManager::addAlphaImage(string strKey, int width, int height){
	//������ �̹��� �ִ��� ã�´�
	alphaImage* img = findAlphaImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new alphaImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mAlphaImageList.insert(make_pair(strKey, img));

	return img;
}

alphaImage* imageManager::addAlphaImage(string strKey, const DWORD resID,
	int width, int height, bool trans, COLORREF transColor){
	//������ �̹��� �ִ��� ã�´�
	alphaImage* img = findAlphaImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new alphaImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(resID, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mAlphaImageList.insert(make_pair(strKey, img));

	return img;
}

alphaImage* imageManager::addAlphaImage(string strKey, const char* fileName,
	int width, int height, bool trans, COLORREF transColor){
	//������ �̹��� �ִ��� ã�´�
	alphaImage* img = findAlphaImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new alphaImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mAlphaImageList.insert(make_pair(strKey, img));

	return img;
}

alphaImage* imageManager::addAlphaImage(string strKey, const char* fileName,
	float x, float y, int width, int height, bool trans, COLORREF transColor, bool multi){

	//������ �̹��� �ִ��� ã�´�
	alphaImage* img = findAlphaImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (!multi) {
		if (img) return img;
	}

	//�̹��� ����
	img = new alphaImage;


	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mAlphaImageList.insert(make_pair(strKey, img));

	return img;
}

//������ �̹���
alphaImage* imageManager::addAlphaFrameImage(string strKey, const char* fileName, float x, float y,
	int width, int height, int frameX, int frameY, bool trans, COLORREF transColor){
	//������ �̹��� �ִ��� ã�´�
	alphaImage* img = findAlphaImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new alphaImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mAlphaImageList.insert(make_pair(strKey, img));

	return img;
}

alphaImage* imageManager::addAlphaFrameImage(string strKey, const char* fileName, int width, int height,
	int frameX, int frameY, bool trans, COLORREF transColor){
	//������ �̹��� �ִ��� ã�´�
	alphaImage* img = findAlphaImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new alphaImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, width, height, frameX, frameY, trans, transColor)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mAlphaImageList.insert(make_pair(strKey, img));

	return img;
}

pngImage* imageManager::addPngImage(string strKey, const WCHAR* fileName, int width, int height){
	//������ �̹��� �ִ��� ã�´�
	pngImage* img = findPngImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new pngImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName,width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mPngImageList.insert(make_pair(strKey, img));

	return img;
}

pngImage* imageManager::addPngImage(string strKey, const WCHAR* fileName, float x, float y, int width, int height, bool multi){
	//������ �̹��� �ִ��� ã�´�
	pngImage* img = findPngImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (!multi) {
		if (img) return img;
	}

	//�̹��� ����
	img = new pngImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, x, y, width, height)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mPngImageList.insert(make_pair(strKey, img));

	return img;

}

//������ �̹���
pngImage* imageManager::addPngFrameImage(string strKey, const WCHAR* fileName, float x, float y, int width, int height, int frameX, int frameY){
	//������ �̹��� �ִ��� ã�´�
	pngImage* img = findPngImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new pngImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, x, y, width, height, frameX, frameY)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mPngImageList.insert(make_pair(strKey, img));

	return img;
}

pngImage* imageManager::addPngFrameImage(string strKey, const WCHAR* fileName, int width, int height, int frameX, int frameY){
	//������ �̹��� �ִ��� ã�´�
	pngImage* img = findPngImage(strKey);

	//Ű���� ���� �̹����� �̹� �ִٸ� �߰����� �ʴ´� �׸��� ������ �̹����� ��ȯ�Ѵ�
	if (img) return img;

	//�̹��� ����
	img = new pngImage;

	//�̹����� ����� �ʱ�ȭ �Ǿ����� �ʴٸ�
	if (FAILED(img->init(fileName, width, height, frameX, frameY)))
	{
		SAFE_DELETE(img);
		return NULL;
	}

	_mPngImageList.insert(make_pair(strKey, img));

	return img;
}



//�̹��� ã�� �Լ�
image* imageManager::findImage(string strKey)
{
	//�ش�Ű�� �ִ��� ���θ� �˻��Ѵ�
	mapImageIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		return key->second;
	}


	return NULL;
}

//���� �̹��� ã�� �Լ�
alphaImage* imageManager::findAlphaImage(string strKey)
{
	//�ش�Ű�� �ִ��� ���θ� �˻��Ѵ�
	mapAlphaImageIter key = _mAlphaImageList.find(strKey);

	if (key != _mAlphaImageList.end())
	{
		return key->second;
	}

	return NULL;
}

//png �̹��� ã�� �Լ�
pngImage* imageManager::findPngImage(string strKey){
	//�ش�Ű�� �ִ��� ���θ� �˻��Ѵ�
	mapPngImageIter key = _mPngImageList.find(strKey);

	if (key != _mPngImageList.end())
	{
		return key->second;
	}

	return NULL;
}

//�̹��� �����
BOOL imageManager::deleteImage(string strKey)
{
	//�ش� Ű�� �ִ��� �˻��Ѵ�
	mapImageIter key = _mImageList.find(strKey);

	if (key != _mImageList.end())
	{
		key->second->release();

		SAFE_DELETE(key->second);

		_mImageList.erase(key);

		return true;
	}

	return false;
}

BOOL imageManager::deleteAlphaImage(string strKey)
{
	//�ش� Ű�� �ִ��� �˻��Ѵ�
	mapAlphaImageIter key = _mAlphaImageList.find(strKey);

	if (key != _mAlphaImageList.end())
	{
		key->second->release();

		SAFE_DELETE(key->second);

		_mAlphaImageList.erase(key);

		return true;
	}

	return false;
}

BOOL imageManager::deletePngImage(string strKey)
{
	//�ش� Ű�� �ִ��� �˻��Ѵ�
	mapPngImageIter key = _mPngImageList.find(strKey);

	if (key != _mPngImageList.end())
	{
		key->second->release();

		SAFE_DELETE(key->second);

		_mPngImageList.erase(key);

		return true;
	}

	return false;
}

BOOL imageManager::deleteAll(void)
{
	//�̹��� ����Ʈ Ŭ����
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else
		{
			++iter;
		}
	}

	_mImageList.clear();

	return TRUE;
}

BOOL imageManager::deleteAlphaAll(void)
{
	//���� �̹��� ����Ʈ Ŭ����
	mapAlphaImageIter iter2 = _mAlphaImageList.begin();

	for (; iter2 != _mAlphaImageList.end();)
	{
		if (iter2->second != NULL)
		{
			SAFE_DELETE(iter2->second);
			iter2 = _mAlphaImageList.erase(iter2);
		}
		else
		{
			++iter2;
		}
	}

	_mAlphaImageList.clear();


	return TRUE;
}

BOOL imageManager::deletePngAll(void)
{
	//���� �̹��� ����Ʈ Ŭ����
	mapPngImageIter iter2 = _mPngImageList.begin();

	for (; iter2 != _mPngImageList.end();)
	{
		if (iter2->second != NULL)
		{
			SAFE_DELETE(iter2->second);
			iter2 = _mPngImageList.erase(iter2);
		}
		else
		{
			++iter2;
		}
	}

	_mPngImageList.clear();


	return TRUE;
}


//�����Լ�
void imageManager::render(string strKey, HDC hdc)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY)
{
	image* img = findImage(strKey);
	if (img) img->render(hdc, destX, destY);
}

void imageManager::render(string strKey, HDC hdc, int destX, int destY,
	int sourX, int sourY, int sourWidth, int sourHeight)
{
	image* img = findImage(strKey);

	if (img) img->render(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight);
}

void  imageManager::frameRender(string strKey, HDC hdc, int destX, int destY)
{
	image* img = findImage(strKey);

	if (img) img->frameRender(hdc, destX, destY);
}

void  imageManager::frameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY)
{
	image* img = findImage(strKey);

	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}

void imageManager::loopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY)
{
	image* img = findImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offsetX, offsetY);
}

void imageManager::alphaLoopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY, BYTE alpha)
{
	alphaImage* img = findAlphaImage(strKey);
	if (img) img->alphaLoopRender(hdc, drawArea, offsetX, offsetY,alpha);
}

void imageManager::alphaRender(string strKey, HDC hdc, BYTE alpha)
{
	alphaImage* img = (alphaImage*)findImage(strKey);
	if (img) img->alphaRender(hdc, alpha);
}

void imageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, BYTE alpha)
{
	alphaImage* img = (alphaImage*)findImage(strKey);
	if (img) img->alphaRender(hdc, destX, destY, alpha);
}

void imageManager::alphaRender(string strKey, HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight, BYTE alpha)
{
	alphaImage* img = (alphaImage*)findImage(strKey);
	if (img) img->alphaRender(hdc, destX, destY, sourX, sourY, sourWidth, sourHeight, alpha);
}

void imageManager::pngRender(string strKey, HDC hdc){
	pngImage* img = findPngImage(strKey);
	if (img) img->render(hdc);
}
void imageManager::pngRender(string strKey, HDC hdc, int destX, int destY){
	pngImage* img = findPngImage(strKey);
	if (img) img->render(hdc,destX,destY);
}
void imageManager::pngRender(string strKey, HDC hdc, int destX, int destY,
	int sourX, int sourY, int sourWidth, int sourHeight){
	pngImage* img = findPngImage(strKey);
	if (img) img->render(hdc,destX,destY,sourX,sourY,sourWidth,sourHeight);
}

void imageManager::pngRender(string strKey, HDC hdc, int destX, int destY,int width,int height,
	int sourX, int sourY, int sourWidth, int sourHeight){
	pngImage* img = findPngImage(strKey);
	if (img) img->render(hdc, destX, destY,width,height, sourX, sourY, sourWidth, sourHeight);
}

void imageManager::pngFrameRender(string strKey, HDC hdc, int destX, int destY){
	pngImage* img = findPngImage(strKey);
	if (img) img->frameRender(hdc, destX, destY);
}
void imageManager::pngFrameRender(string strKey, HDC hdc, int destX, int destY, int currentFrameX, int currentFrameY){
	pngImage* img = findPngImage(strKey);
	if (img) img->frameRender(hdc, destX, destY, currentFrameX, currentFrameY);
}
void imageManager::pngLoopRender(string strKey, HDC hdc, const LPRECT drawArea, int offsetX, int offsetY){
	pngImage* img = findPngImage(strKey);
	if (img) img->loopRender(hdc, drawArea, offsetX, offsetY);
}