#include "stdafx.h"
#include "deathAttack.h"


deathAttack::deathAttack()
{
}


deathAttack::~deathAttack()
{
}

HRESULT deathAttack::init(){
	IMAGEMANAGER->addAlphaFrameImage("killerrabbit_effect", "�̹���/����/ų������/killerrabbit_effect.bmp", 2856, 1000, 8, 2, true, RGB(255, 0, 255));

	return S_OK;
}
void deathAttack::update(){

}
void deathAttack::render(){}
void deathAttack::release(){}