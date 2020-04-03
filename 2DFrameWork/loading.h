#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include <vector>

//�ε� ������ ����
enum LOADING_KIND
{
	LOADING_KIND_IMAGE_00,
	LOADING_KIND_IMAGE_01,
	LOADING_KIND_IMAGE_02,
	LOADING_KIND_IMAGE_03,
	LOADING_KIND_IMAGE_04,
	LOADING_KIND_IMAGE_05,
	LOADING_KIND_FRAMEIMAGE_00,
	LOADING_KIND_FRAMEIMAGE_01,
	LOADING_KIND_FRAMEIMAGE_02,
	LOADING_KIND_FRAMEIMAGE_03,
	LOADING_KIND_FRAMEIMAGE_04,
	LOADING_KIND_SOUND_00,
	LOADING_KIND_END
};

//���ҽ� ����ü
struct tagResource
{
	string keyName;
	const char* fileName;

	const WCHAR* wFileName;
	//�̹��� ���ҽ�
	int x, y;
	int width, height;
	int frameX, frameY;
	bool trans;
	COLORREF transColor;
	bool multi;

	//���� ���ҽ�
	bool bgm;
	bool loop;
};


class loadItem
{
private:
	LOADING_KIND _kind;
	tagResource _resource;

public:
	//�̹���
	HRESULT initForImage(string keyName, int width, int height);
	HRESULT initForImage(string keyName, const char* fileName, int x, int y, int width, int height, bool trans, COLORREF transColor);
	HRESULT initForImage(string keyName, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	HRESULT initForFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	HRESULT initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	HRESULT initForFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor,bool multi);
	HRESULT initForAlphaImage(string keyName, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	HRESULT initForAlphaImage(string keyName, const char* fileName, int x, int y,int width, int height, bool trans, COLORREF transColor,bool multi);
	HRESULT initForAlphaFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	HRESULT initForPngImage(string keyName, const WCHAR* wFileName, int width, int height);
	HRESULT initForPngFrameImage(string keyName, const WCHAR* wFileName, int width, int height, int frameX, int frameY);

	//����
	HRESULT initForSound(string keyName, const char* fileName, bool bgm, bool loop);


	LOADING_KIND getLoadingKind() { return _kind; }
	tagResource getResource() { return _resource; }

	loadItem();
	~loadItem();
};


#define FAIRY_FRAME_TIMER 3
#define LOADING_FRAME_TIMER 10

class loading : public gameNode
{
private:
	typedef vector<loadItem*> arrLoadItem;
	typedef vector<loadItem*>::iterator arrLoadItemIter;

private:
	arrLoadItem _vLoadItem;

	image* _background;
	image* _run;
	image* _circle;
	progressBar* _loadingBar;
	progressBar* _loadingBar2;

	int _current;
	int _fairyFrameX;
	int _fairyFrameY;
	int _fairyFrameTimer;
	int _loadingFrameX;
	int _loadingFrameTimer;
public:
	HRESULT init();
	void release();
	void update();
	void render();

	//�̹���
	void loadImage(string keyName, int width, int height);
	void loadImage(string keyName, const char* fileName, int x, int y, int width, int height, bool trans, COLORREF transColor, bool multi);
	void loadImage(string keyName, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	void loadAlphaImage(string keyName, const char* fileName, int width, int height, bool trans, COLORREF transColor);
	void loadAlphaImage(string keyName, const char* fileName, int x, int y, int width, int height, bool trans, COLORREF transColor, bool multi);
	void loadPngImage(string keyName, const WCHAR* wFileName, int width, int height);
	void loadFrameImage(string keyName, const char* fileName, int x, int y, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	void loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	void loadFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor,bool multi);
	void loadAlphaFrameImage(string keyName, const char* fileName, int width, int height, int frameX, int frameY, bool trans, COLORREF transColor);
	void loadPngFrameImage(string keyName, const WCHAR* wFileName, int width, int height, int frameX, int frameY);

	//����
	void loadSound(string keyName, const char* fileName, bool bgm, bool loop);
	//�ε��� �Ǵ� ���̸� true, �ٵǸ� false
	BOOL loadNext();

	vector<loadItem*> getLoadItem(void) { return _vLoadItem; }

	loading();
	~loading();
};

