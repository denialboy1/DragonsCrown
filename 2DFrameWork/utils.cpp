#include "stdafx.h"
#include "utils.h"


namespace DENIALBOY_UTIL	//원하는대로
{
	//거리 가져오는 공식
	float getDistance(float startX, float startY, float endX, float endY)
	{
		float x = endX - startX;
		float y = endY - startY;

		return sqrtf(x * x + y * y);
	}

	//각도 가져오는 공식
	float getAngle(float x1, float y1, float x2, float y2)
	{
		float x = x2 - x1;
		float y = y2 - y1;

		float distance = sqrtf(x * x + y * y);
		float angle = acosf(x / distance);

		if (y > 0) angle = PI2 - angle;

		return angle;
	}

	//미니맵 만들기
	void minimapRender(HDC hdc, int rate, int bgWidth, int bgHeight)
	{
		StretchBlt(hdc, bgWidth - bgWidth / rate, 0, bgWidth / rate, bgHeight / rate, hdc, 0, 0, bgWidth, bgHeight, SRCCOPY);
		LineMake(hdc, bgWidth - bgWidth / rate, 0, bgWidth - bgWidth / rate, bgHeight / rate);
		LineMake(hdc, bgWidth - bgWidth / rate, bgHeight / rate, bgWidth, bgHeight / rate);
	}

	void MakeBlackAndWhite(HDC hdc, int startX, int startY, int endX, int endY) {

		LPVOID m_pBits;
		int m_nBytePerLine;
		BITMAPINFO* m_pbmi;

		HDC hdcTemp;
		hdcTemp = CreateCompatibleDC(hdc);
		BITMAPINFO bitmap;
		BYTE* bitPointer;
		bitmap.bmiHeader.biSize = sizeof(bitmap.bmiHeader);
		bitmap.bmiHeader.biWidth = WINSIZEX;
		bitmap.bmiHeader.biHeight = WINSIZEY;
		bitmap.bmiHeader.biPlanes = 1;
		bitmap.bmiHeader.biBitCount = 32;
		bitmap.bmiHeader.biCompression = BI_RGB;
		bitmap.bmiHeader.biSizeImage = WINSIZEX * 4 * WINSIZEY;
		bitmap.bmiHeader.biClrUsed = 0;
		bitmap.bmiHeader.biClrImportant = 0;
		HBITMAP hBitmap = CreateDIBSection(hdcTemp, &bitmap, DIB_RGB_COLORS, (void**)(&bitPointer), NULL, NULL);
		HBITMAP hOldBitmap;
		hOldBitmap = (HBITMAP)SelectObject(hdcTemp, hBitmap);
		BitBlt(hdcTemp, 0, 0, WINSIZEX, WINSIZEY, hdc, 0, 0, SRCCOPY);

		BITMAPINFO bmi;
		ZeroMemory(&bmi, sizeof(bmi));
		bmi.bmiHeader.biSize = sizeof(bmi.bmiHeader);	//버전확인용
		GetDIBits(hdcTemp, hBitmap, 0, 0, NULL, &bmi, DIB_RGB_COLORS);

		m_pbmi = (BITMAPINFO*)new BYTE[sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)];
		memcpy(m_pbmi, &bmi, sizeof(bmi.bmiHeader));
		m_nBytePerLine = bmi.bmiHeader.biBitCount / 8 * bmi.bmiHeader.biWidth;
		m_nBytePerLine = (m_nBytePerLine + 3) & ~3;
		m_pBits = new char[m_nBytePerLine * abs(bmi.bmiHeader.biHeight)];
		m_pbmi->bmiHeader.biHeight = abs(bmi.bmiHeader.biHeight) * -1;
		GetDIBits(hdcTemp, hBitmap, 0, abs(bmi.bmiHeader.biHeight), m_pBits, m_pbmi, DIB_RGB_COLORS);

		for (int x = startX; x < endX; x = x + 1) {
			for (int y = startY; y < endY; y = y + 1) {
				DWORD dw = ((DWORD*)m_pBits)[x + (y * (m_nBytePerLine / sizeof(DWORD)))];
				COLORREF color = ((dw & 0x000000FF) << 24) + (dw & 0x0000FF00) + ((dw & 0x00FF0000) >> 24);
				int red;
				int green;
				int blue;

				red = GetRValue(color);
				green = GetGValue(color);
				blue = GetBValue(color);

				int blackAndWhite = (red + green + blue) / 3;

				color = RGB(blackAndWhite, blackAndWhite, blackAndWhite);
				((DWORD*)m_pBits)[x + (y * (m_nBytePerLine / sizeof(DWORD)))] = color;

			}
		}
		SetDIBits(hdcTemp, hBitmap, 0, abs(bmi.bmiHeader.biHeight), m_pBits, m_pbmi, DIB_RGB_COLORS);
		BitBlt(hdc, 0, 0, WINSIZEX, WINSIZEY, hdcTemp, 0, 0, SRCCOPY);

		SelectObject(hdcTemp, hOldBitmap);
		DeleteObject(hBitmap);

		delete m_pBits;

	}

	bool pixelCollision(HDC hdc, int axis, int x, int y, int scale1, int scale2, COLORREF color0, int* coordinate_of_pixel)
	{

		int r0 = GetRValue(color0);
		int g0 = GetGValue(color0);
		int b0 = GetBValue(color0);

		//이미지의 픽셀값 읽어온다
		if (axis == Y_AXIS)
		{
			for (int i = y - scale1; i < y + scale2; ++i)
			{
				COLORREF color = GetPixel(hdc, x, i);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == r0 && g == g0 && b == b0)
				{
					*coordinate_of_pixel = i;
					return true;
				}
			}
		}

		if (axis == X_AXIS)
		{
			for (int i = x - scale1; i < x + scale2; ++i)
			{
				COLORREF color = GetPixel(hdc, i, y);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == r0 && g == g0 && b == b0)
				{
					*coordinate_of_pixel = i;
					return true;
				}
			}
		}

		return false;
	}

	bool pixelCollision(char* imgKey, int axis, int x, int y, int scale1, int scale2, COLORREF color0, int* coordinate_of_pixel)
	{
		if (IMAGEMANAGER->findImage(imgKey) == NULL) return NULL;

		int r0 = GetRValue(color0);
		int g0 = GetGValue(color0);
		int b0 = GetBValue(color0);

		//이미지의 픽셀값 읽어온다
		if (axis == Y_AXIS)
		{
			for (int i = y - scale1; i < y + scale2; ++i)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(imgKey)->getMemDC(), x, i);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == r0 && g == g0 && b == b0)
				{
					*coordinate_of_pixel = i;
					return true;
				}
			}
		}

		if (axis == X_AXIS)
		{
			for (int i = x - scale1; i < x + scale2; ++i)
			{
				COLORREF color = GetPixel(IMAGEMANAGER->findImage(imgKey)->getMemDC(), i, y);

				int r = GetRValue(color);
				int g = GetGValue(color);
				int b = GetBValue(color);

				if (r == r0 && g == g0 && b == b0)
				{
					*coordinate_of_pixel = i;
					return true;
				}
			}
		}

		return false;
	}

}