#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include <vector>

//로딩 아이템 종류
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

//리소스 구조체
struct tagResource
{
	string keyName;
	const char* fileName;

	const WCHAR* wFileName;
	//이미지 리소스
	int x, y;
	int width, height;
	int frameX, frameY;
	bool trans;
	COLORREF transColor;
	bool multi;

	//사운드 리소스
	bool bgm;
	bool loop;
};


class loadItem
{
private:
	LOADING_KIND _kind;
	tagResource _resource;

public:
	//이미지
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

	//사운드
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

	//이미지
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

	//사운드
	void loadSound(string keyName, const char* fileName, bool bgm, bool loop);
	//로딩이 되는 중이면 true, 다되면 false
	BOOL loadNext();

	vector<loadItem*> getLoadItem(void) { return _vLoadItem; }

	loading();
	~loading();
};

