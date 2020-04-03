#pragma once
#include "attackSkill.h"

#define FRAMETIME 2

class rockPress : public attackSkill
{
	
public:

	rockPress();
	~rockPress();

	HRESULT init();
	void update();
	void render();
	void release();

	

};

