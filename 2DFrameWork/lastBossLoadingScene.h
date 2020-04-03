#pragma once
#include "gameNode.h"
#include "loading.h"

class lastBossLoadingScene : public gameNode
{
private:
	loading* _loading;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);


	lastBossLoadingScene();
	~lastBossLoadingScene();
};

