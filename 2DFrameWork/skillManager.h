#pragma once
#include "gameNode.h"
#include "rockPress.h"
#include "icePrision.h"
#include "ThunderCloud.h"
#include "blizzard.h"
#include "createFood.h"
#include "protection.h"
#include "gravity.h"
#include "cuss.h"
#include "petrification.h"

class player;

class skillManager : public gameNode
{
private:
	player* _player;
	rockPress* _rockPress;
	icePrision* _icePrision;
	ThunderCloud* _thunderCloud;
	blizzard* _blizzard;
	createFood* _createFood;
	protection* _protection;
	gravity* _gravity;
	cuss* _cuss;
	petrification* _petrification;
public:
	skillManager();
	~skillManager();

	HRESULT init();
	void render();
	void update();
	void release();

public:

	void addPlayerAddress(player* player){ _player = player; }
	rockPress* getRockPress(){ return _rockPress; }
	icePrision* getIcePrision(){ return _icePrision; }
	ThunderCloud* getThunderCloud(){ return _thunderCloud; }
	blizzard* getBlizzard(){ return _blizzard; }
	createFood* getCreateFood(){ return _createFood; }
	protection* getProtection(){ return _protection; }
	gravity* getGravity(){ return _gravity; }
	cuss* getCuss(){ return _cuss; }
	petrification* getPetrification(){ return _petrification; }
};

