#include "stdafx.h"
#include "animation.h"


animation::animation()
	:_frameNum(0),
	_frameWidth(0),
	_frameHeight(0),
	_loop(FALSE),
	_frameUpdateSec(0),
	_elapsedSec(0),
	_nowPlayIdx(0),
	_play(FALSE)
{
}


animation::~animation()
{
}

HRESULT animation::init(int totalW, int totalH, int frameW, int frameH)
{
	//가로 프레임 수
	_frameWidth = frameW;
	int _frameNumWidth = totalW / _frameWidth;

	//세로 프레임 수
	_frameHeight = frameH;
	int _frameNumHeight = totalH / _frameHeight;

	//총 프레임 수 계산
	_frameNum = _frameNumWidth * _frameNumHeight;

	//프레임 위치 리스트 셋팅
	for (int i = 0; i < _frameNumHeight; i++)
	{
		for (int j = 0; j < _frameNumWidth; j++)
		{
			POINT framePos;
			framePos.x = j * _frameWidth;
			framePos.y = i * _frameHeight;

			//프레임 위치 리스트에 추가
			_frameList.push_back(framePos);
		}
	}

	//기본 프레임으로 셋팅해준다
	setDefPlayFrame();


	return S_OK;
}

void animation::release(void)
{

}

//그냥 일반 프레임 재생
void animation::setDefPlayFrame(BOOL reverse, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;

	//루프 여부
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	//정방향 ->
	//역방향 <-
	if (reverse)
	{
		//루프 여부
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < _frameNum; i++)
		{
			_playList.push_back(i);
		}
	}
}

void animation::setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	//루프 여부
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	//정방향 ->
	//역방향 <-
	if (reverse)
	{
		//루프 여부
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < _frameNum; i++)
		{
			_playList.push_back(i);
		}
	}
}

void animation::setDefPlayFrame(BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	//루프 여부
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	//정방향 ->
	//역방향 <-
	if (reverse)
	{
		//루프 여부
		if (_loop)
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
		else
		{
			for (int i = 0; i < _frameNum; i++)
			{
				_playList.push_back(i);
			}

			for (int i = _frameNum - 1; i > 0; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i < _frameNum; i++)
		{
			_playList.push_back(i);
		}
	}
}

//배열에 담아서 프레임 재생
void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;

	//루프 여부 묻고
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	//루프 여부 묻고
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

void animation::setPlayFrame(int* playArr, int arrLen, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	//루프 여부 묻고
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	for (int i = 0; i < arrLen; i++)
	{
		_playList.push_back(playArr[i]);
	}
}

//구간의 시작과 끝을 가지고 프레임 재생
void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop)
{
	_obj = NULL;
	_callbackFunction = NULL;
	_callbackFunctionParameter = NULL;

	//루프 여부
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	if (start == end)
	{
		//시작과 끝 프레임이 같으면
		_playList.clear();
		stop();
		return;
	}

	//시작 프레임이 종료 프레임보다 큰 경우
	if (start > end)
	{
		//리버스냐?
		if (reverse)
		{
			//루프냐?
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			for (int i = start; i >= end; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else //끝프레임이 크면
	{
		//리버스냐?
		if (reverse)
		{
			//루프냐?
			if (_loop)
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			for (int i = start; i <= end; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION cbFunction)
{
	_obj = NULL;
	_callbackFunction = cbFunction;
	_callbackFunctionParameter = NULL;

	//루프 여부
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	if (start == end)
	{
		//시작과 끝 프레임이 같으면
		_playList.clear();
		stop();
		return;
	}

	//시작 프레임이 종료 프레임보다 큰 경우
	if (start > end)
	{
		//리버스냐?
		if (reverse)
		{
			//루프냐?
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			for (int i = start; i >= end; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else //끝프레임이 크면
	{
		//리버스냐?
		if (reverse)
		{
			//루프냐?
			if (_loop)
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			for (int i = start; i <= end; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}

void animation::setPlayFrame(int start, int end, BOOL reverse, BOOL loop, CALLBACK_FUNCTION_PARAMETER cbFunction, void* obj)
{
	_obj = obj;
	_callbackFunction = NULL;
	_callbackFunctionParameter = cbFunction;

	//루프 여부
	_loop = loop;

	//플레이 리스트 클리어
	_playList.clear();

	if (start == end)
	{
		//시작과 끝 프레임이 같으면
		_playList.clear();
		stop();
		return;
	}

	//시작 프레임이 종료 프레임보다 큰 경우
	if (start > end)
	{
		//리버스냐?
		if (reverse)
		{
			//루프냐?
			if (_loop)
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i >= end; i--)
				{
					_playList.push_back(i);
				}

				for (int i = end + 1; i < start; i++)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			for (int i = start; i >= end; i--)
			{
				_playList.push_back(i);
			}
		}
	}
	else //끝프레임이 크면
	{
		//리버스냐?
		if (reverse)
		{
			//루프냐?
			if (_loop)
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
			else
			{
				for (int i = start; i <= end; i++)
				{
					_playList.push_back(i);
				}

				for (int i = end - 1; i > start; i--)
				{
					_playList.push_back(i);
				}
			}
		}
		else
		{
			for (int i = start; i <= end; i++)
			{
				_playList.push_back(i);
			}
		}
	}
}


void animation::setFPS(int framePerSec)
{
	_frameUpdateSec = 1.0f / framePerSec;
}

void animation::frameUpdate(float elapsedTime)
{
	if (_play)
	{
		_elapsedSec += elapsedTime;

		//프레임 업데이트 시간이 되었다면~
		if (_elapsedSec >= _frameUpdateSec)
		{
			_elapsedSec -= _frameUpdateSec;
			_nowPlayIdx++;

			if (_nowPlayIdx == _playList.size())
			{
				//루프 플레이
				if (_loop)
				{
					_nowPlayIdx = 0;
				}
				else
				{
					if (_obj == NULL)
					{
						if (_callbackFunction != NULL) _callbackFunction();
					}
					else
					{
						_callbackFunctionParameter(_obj);
					}
					_nowPlayIdx--;
					_play = FALSE;
				}
			}
		}
	}
}


void animation::start(void)
{
	_play = TRUE;
	_nowPlayIdx = 0;
}

void animation::stop(void)
{
	_play = FALSE;
	_nowPlayIdx = 0;
}

void animation::pause(void)
{
	_play = FALSE;
}

void animation::resume(void)
{
	_play = TRUE;
}
