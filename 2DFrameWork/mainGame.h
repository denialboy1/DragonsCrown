#pragma once
#include "gameNode.h"
#include "openingScene.h"
#include "townScene.h"
#include "barScene.h"
#include "guildScene.h"
#include "shopScene.h"
#include "lastBossScene.h"
#include "lastBossLoadingScene.h"
#include "townLoadingScene.h"
#include "gameOverScene.h"
#include "endingScene.h"
#include "graveScene.h"
#include "graveStageLoadingScene.h"
class mainGame : public gameNode
{
private:
	

public:
	virtual HRESULT init(void);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	

	mainGame();
	~mainGame();
};

