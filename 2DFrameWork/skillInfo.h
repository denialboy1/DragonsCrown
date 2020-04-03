#pragma once
#include "gameNode.h"
#include "skill.h"
class skillInfo : public gameNode
{
private:
	skill* _skill;

	int _currentWhich;		//현재 아이템 위치
	int _currentAlpha;		//현재 위치 알파값
	int _currentReverse;	//아아템 알파값 리버스
	int _botFrameCursor;	//아래 프레임 커서
	int _botFrameMoveY;		//아래 프레임 움직임 위치	
public:
	skillInfo();
	~skillInfo();

	HRESULT init();
	void update();
	void render();
	void release();
};

