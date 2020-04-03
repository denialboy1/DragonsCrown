#pragma once
#include "gameNode.h"
#include "loading.h"

class graveStageLoadingScene : public gameNode
{
private:
	loading* _loading;

public:
	graveStageLoadingScene();
	~graveStageLoadingScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

