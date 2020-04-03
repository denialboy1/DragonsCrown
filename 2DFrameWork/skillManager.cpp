#include "stdafx.h"
#include "skillManager.h"
#include "player.h"


skillManager::skillManager()
{
}


skillManager::~skillManager()
{
}


HRESULT skillManager::init(){
	_rockPress = new rockPress;
	_rockPress->init();

	_icePrision = new icePrision;
	_icePrision->init();

	_thunderCloud = new ThunderCloud;
	_thunderCloud->init();

	_blizzard = new blizzard;
	_blizzard->init();

	_createFood = new createFood;
	_createFood->init();

	_protection = new protection;
	_protection->init();

	_gravity = new gravity;
	_gravity->init();

	_cuss = new cuss;
	_cuss->init();

	_petrification = new petrification;
	_petrification->init();
	return S_OK;
}
void skillManager::render(){}
void skillManager::update(){}
void skillManager::release(){}

