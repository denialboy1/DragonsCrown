#pragma once
#include "gameNode.h"
#include "player.h"
#include "icePrision.h"
#include "motherEnemy.h"

class objectCollision : public gameNode
{
private:
	player* _player;
	icePrision* _icePrision;
	motherEnemy* _motherEnemy;
public:
	objectCollision();
	~objectCollision();
	

	HRESULT init(player* pl,icePrision* ice);

	void collision();
	void collision(motherEnemy* _enemy);
};

