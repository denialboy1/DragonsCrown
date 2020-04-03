#pragma once
#include "gameNode.h"
#include "shop.h"
class shopScene : public gameNode
{
private:
	shop* _shop;
public:
	
	shopScene();
	~shopScene();

	HRESULT init();
	void update();
	void render();
	void release();
	
};

