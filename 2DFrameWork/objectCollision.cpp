#include "stdafx.h"
#include "objectCollision.h"


objectCollision::objectCollision()
{
}


objectCollision::~objectCollision()
{
}


HRESULT objectCollision::init(player* pl, icePrision* ice){
	_player = pl;
	_icePrision = ice;

	return S_OK;
}

void objectCollision::collision(){
	RECT temp;
	int width;

	if (IntersectRect(&temp, &_player->getRcShadow(), &_icePrision->getRcDeffence()[2])){
		if (_player->getRcShadow().right > _icePrision->getRcDeffence()[2].left &&_player->getRcShadow().right < _icePrision->getRcDeffence()[2].left + 10){
			_player->setShadowX(_icePrision->getRcDeffence()[2].left - 190);
		}
	}

	if (IntersectRect(&temp, &_player->getRcShadow(), &_icePrision->getRcDeffence()[1])){
		if (_player->getRcShadow().right > _icePrision->getRcDeffence()[1].left &&_player->getRcShadow().right < _icePrision->getRcDeffence()[1].left + 40){
			_player->setShadowX(_icePrision->getRcDeffence()[1].left - 190);
		}
	}

	if (IntersectRect(&temp, &_player->getRcShadow(), &_icePrision->getRcDeffence()[0])){
		if (_player->getRcShadow().right > _icePrision->getRcDeffence()[0].left &&_player->getRcShadow().right < _icePrision->getRcDeffence()[0].left +60){
			_player->setShadowX(_icePrision->getRcDeffence()[0].left - 190);
		}
	}

	if (IntersectRect(&temp, &_player->getRcShadow(), &_icePrision->getRcDeffence()[0])){
		if (_player->getRcShadow().left < _icePrision->getRcDeffence()[0].right &&_player->getRcShadow().left > _icePrision->getRcDeffence()[0].right - 10){
			_player->setShadowX(_icePrision->getRcDeffence()[0].right - 90);
		}
	}


	if (IntersectRect(&temp, &_player->getRcShadow(), &_icePrision->getRcDeffence()[1])){
		if (_player->getRcShadow().left < _icePrision->getRcDeffence()[1].right &&_player->getRcShadow().left > _icePrision->getRcDeffence()[1].right - 40){
			_player->setShadowX(_icePrision->getRcDeffence()[1].right - 90);
		}
	}

	if (IntersectRect(&temp, &_player->getRcShadow(), &_icePrision->getRcDeffence()[2])){
		if (_player->getRcShadow().left < _icePrision->getRcDeffence()[2].right &&_player->getRcShadow().left > _icePrision->getRcDeffence()[2].right - 40){
			_player->setShadowX(_icePrision->getRcDeffence()[2].right-90);
		}
	}
	
}

void objectCollision::collision(motherEnemy* _enemy){
	RECT temp;
	int width;

	if (IntersectRect(&temp, &_enemy->getRcShadow(), &_icePrision->getRcDeffence()[2])){
		if (_enemy->getRcShadow().right > _icePrision->getRcDeffence()[2].left &&_enemy->getRcShadow().right < _icePrision->getRcDeffence()[2].left + 10){
			_enemy->setEnemyX(_icePrision->getRcDeffence()[2].left - 290);
		}
	}

	if (IntersectRect(&temp, &_enemy->getRcShadow(), &_icePrision->getRcDeffence()[1])){
		if (_enemy->getRcShadow().right > _icePrision->getRcDeffence()[1].left &&_enemy->getRcShadow().right < _icePrision->getRcDeffence()[1].left + 40){
			_enemy->setEnemyX(_icePrision->getRcDeffence()[1].left - 290);
		}
	}

	if (IntersectRect(&temp, &_enemy->getRcShadow(), &_icePrision->getRcDeffence()[0])){
		if (_enemy->getRcShadow().right > _icePrision->getRcDeffence()[0].left &&_enemy->getRcShadow().right < _icePrision->getRcDeffence()[0].left + 60){
			_enemy->setEnemyX(_icePrision->getRcDeffence()[0].left - 290);
		}
	}

	if (IntersectRect(&temp, &_enemy->getRcShadow(), &_icePrision->getRcDeffence()[0])){
		if (_enemy->getRcShadow().left < _icePrision->getRcDeffence()[0].right &&_enemy->getRcShadow().left > _icePrision->getRcDeffence()[0].right - 10){
			_enemy->setEnemyX(_icePrision->getRcDeffence()[0].right - 130);
		}
	}


	if (IntersectRect(&temp, &_enemy->getRcShadow(), &_icePrision->getRcDeffence()[1])){
		if (_enemy->getRcShadow().left < _icePrision->getRcDeffence()[1].right &&_enemy->getRcShadow().left > _icePrision->getRcDeffence()[1].right - 40){
			_enemy->setEnemyX(_icePrision->getRcDeffence()[1].right - 130);
		}
	}

	if (IntersectRect(&temp, &_enemy->getRcShadow(), &_icePrision->getRcDeffence()[2])){
		if (_enemy->getRcShadow().left < _icePrision->getRcDeffence()[2].right &&_enemy->getRcShadow().left > _icePrision->getRcDeffence()[2].right - 40){
			_enemy->setEnemyX(_icePrision->getRcDeffence()[2].right - 130);
		}
	}

}