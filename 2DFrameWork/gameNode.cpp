#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

//초기화 해주는 함수
HRESULT gameNode::init(void)
{
	_hdc = GetDC(_hWnd);
	_managerInit = false;
	_show = false;
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	_hdc = GetDC(_hWnd);
	_managerInit = managerInit;
	_show = false;
	if (_managerInit)
	{
		SetTimer(_hWnd, 1, 10, NULL);

		KEYMANAGER->init();
		IMAGEMANAGER->init();
		TIMEMANAGER->init();
		EFFECTMANAGER->init();
		SOUNDMANAGER->init();
		SCENEMANAGER->init();
		KEYANIMANAGER->init();
		TXTDATA->init();
		DATABASE->init();
		INIDATA->init();
	}

	return S_OK;
}

//메모리 해제 해주는 함수
void gameNode::release(void)
{

	if (_managerInit)
	{
		KillTimer(_hWnd, 1);

		KEYMANAGER->releaseSingleton();
		IMAGEMANAGER->releaseSingleton();
		TIMEMANAGER->releaseSingleton();
		EFFECTMANAGER->releaseSingleton();
		SCENEMANAGER->releaseSingleton();
		SOUNDMANAGER->releaseSingleton();
		KEYANIMANAGER->releaseSingleton();
		TXTDATA->releaseSingleton();
		DATABASE->releaseSingleton();
		INIDATA->release();
	}

	//DC릴리즈
	ReleaseDC(_hWnd, _hdc);

}

//연산 담당 함수
void gameNode::update(void)
{
}

//그려주는 함수
void gameNode::render()
{

}
HCURSOR hNormalCursor, hClickCursor, hNowCursor;
LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	_hWnd = hWnd;
	
	switch (iMessage)
	{
		//초기화는 여기에!
	case WM_CREATE:
		hNormalCursor = LoadCursorFromFile("이미지/마우스노말.cur");
		hClickCursor = LoadCursorFromFile("이미지/마우스클릭.cur");
		hNowCursor = hNormalCursor;
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		for (int i = 0; i < _vZOrder.size(); i++){
			_vZOrder[i]->render();
		}
		//this->render();

		EndPaint(hWnd, &ps);
	}
	break;
	case WM_MOUSEMOVE:
		_ptMouse.x = static_cast<float>(LOWORD(lParam));
		_ptMouse.y = static_cast<float>(HIWORD(lParam));
		break;
	case WM_LBUTTONDOWN:
		hNowCursor = hClickCursor;
		SetCursor(hNowCursor);
		return 0;
	case WM_LBUTTONUP:
		hNowCursor = hNormalCursor;
		SetCursor(hNowCursor);
		return 0;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		case VK_F2:
			_debug ? _debug = false : _debug = true;
			break;
		}
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
		//마우스 없애기
	case WM_SETCURSOR:
		SetCursor(hNowCursor);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}