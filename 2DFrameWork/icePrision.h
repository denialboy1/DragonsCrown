#pragma once
#include "attackSkill.h"
class icePrision : public attackSkill
{
private:
	RECT _rcDeffence[3];

	
public:
	icePrision();
	~icePrision();

	HRESULT init();
	void update();
	void render();
	void release();
	

	RECT* getRcDeffence(){ return _rcDeffence; }
};

