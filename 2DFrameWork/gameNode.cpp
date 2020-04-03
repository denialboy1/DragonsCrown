#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

//�ʱ�ȭ ���ִ� �Լ�
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

//�޸� ���� ���ִ� �Լ�
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

	//DC������
	ReleaseDC(_hWnd, _hdc);

}

//���� ��� �Լ�
void gameNode::update(void)
{
}

//�׷��ִ� �Լ�
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
		//�ʱ�ȭ�� ���⿡!
	case WM_CREATE:
		hNormalCursor = LoadCursorFromFile("�̹���/���콺�븻.cur");
		hClickCursor = LoadCursorFromFile("�̹���/���콺Ŭ��.cur");
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
		//���콺 ���ֱ�
	case WM_SETCURSOR:
		SetCursor(hNowCursor);
		return 0;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}