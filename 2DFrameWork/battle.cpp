#include "stdafx.h"
#include "battle.h"

#include "player.h"
#include "mamaball.h"
#include "normalBullet1.h"
#include "normalBullet2.h"
#include "normalBullet3.h"
#include "normalBullet4.h"
#include "normalBullet5.h"
#include "skillManager.h"

#include "motherEnemy.h"
#include "fireFloor.h"
#include "fireRain.h"
#include "fireWorld.h"


battle::battle()
{
}


battle::~battle()
{
}

HRESULT battle::init(){
	_normal1Timer = 0;
	_normal2Timer = 0;
	_blizzardTimer = 0;
	_gravityTimer = 0;
	IMAGEMANAGER->addAlphaImage("피격흑백", "이미지/소서리스/흑백.bmp", 300, 300, false, RGB(255, 0, 255));
	IMAGEMANAGER->addAlphaFrameImage("피격이펙트", "이미지/소서리스/피격이펙트.bmp", 900, 900, 3, 3, true, RGB(255, 0, 255));

	
	

	_damageShow = new damageShow;
	_damageShow->init();
	return S_OK;
}

void battle::update(void){
	//playerAttack();
	
	for (int i = 0; i < _vTagDamageEffect.size(); i++){
		_vTagDamageEffect[i].frameTimer++;
		_vTagDamageEffect[i].alpha1-=10;
		if (_vTagDamageEffect[i].alpha1 < 30){ _vTagDamageEffect[i].alpha1 = 30; }
		if (DAMAGE_EFFECT_TIMER < _vTagDamageEffect[i].frameTimer){
			_vTagDamageEffect[i].frameX++;
			if (_vTagDamageEffect[i].frameX == 3){
				_vTagDamageEffect[i].isCollision = false;
			}
		}
	}

	//안쓰는거 삭제
	for (_viTagDamageEffect = _vTagDamageEffect.begin(); _viTagDamageEffect != _vTagDamageEffect.end();){
		if (!(*_viTagDamageEffect).isCollision){
			_vTagDamageEffect.erase(_viTagDamageEffect);
			break;
		}
		else{
			_viTagDamageEffect++;
		}
	}

	_damageShow->update();
}


void battle::render(){
	for (int i = 0; i < _vTagDamageEffect.size(); i++){
		IMAGEMANAGER->findAlphaImage("피격이펙트")->alphaFrameRender(getDamage2DC(), 0, 0, _vTagDamageEffect[i].frameX, _vTagDamageEffect[i].frameY, _vTagDamageEffect[i].alpha1);
		IMAGEMANAGER->findAlphaImage("피격흑백")->alphaRender(getDamage3DC(), _vTagDamageEffect[i].alpha2);
		BitBlt(getDamage2DC(), 0, 0, 300, 300,getDamage3DC(), 0, 0, SRCPAINT);
		TransparentBlt(getMemDC(), _vTagDamageEffect[i].rcCollision.left-100, _vTagDamageEffect[i].rcCollision.top-100,300,300,
			getDamage2DC(), 0, 0, 300,300, RGB(0, 0, 0));
		
		//BitBlt(getMemDC(), _vTagDamageEffect[i].rcCollision.left, _vTagDamageEffect[i].rcCollision.top, 150, 150, getDamage2DC(), 0, 0, SRCCOPY);
		//IMAGEMANAGER->findAlphaImage("피격이펙트")->alphaFrameRender(getMemDC(), _vTagDamageEffect[i].rcCollision.left, _vTagDamageEffect[i].rcCollision.top, _vTagDamageEffect[i].frameX, _vTagDamageEffect[i].frameY, _vTagDamageEffect[i].alpha1);
		PatBlt(getDamage2DC(), 0, 0, 300,300, BLACKNESS);
		PatBlt(getDamage3DC(), 0, 0, 300,300, BLACKNESS);
	}

	_damageShow->render();
}

void battle::playerAttack(){
	normalBullet2();
	normalBullet3();
	normalBullet4();
	normalBullet5();
	skillManager();
}
void battle::playerVSDragonSkillAttack(){
	//스킬공격
	floorVSnormalBullet2();
	floorVSnormalBullet3();
	floorVSnormalBullet4();
	floorVSnormalBullet5();
	floorVSskillManager();
}
void battle::enemyAttack(){
	tagDamageEffect _tagDamageEffect;
	if ((_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 > _enemy->getRcShadow().top &&
		(_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 < _enemy->getRcShadow().bottom){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_player->getRcPlayer(), &_enemy->getRcAttack())){
			if (!_player->getIsInvincible()){
				_damage = _enemy->getAttackDamage() + RND->getInt(15);
				if (_skillManager->getProtection()->getStart()){
					_damage = _damage - _damage* 0.5;
				}
				if (_damage >= 9999){ _damage = 9999; }
				_player->damaged(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, false);
				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}
}

void battle::dragonSkillAttack(){
	fireFloor();
	fireWorld();
}

void battle::fireFloor(){
	tagDamageEffect _tagDamageEffect;
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_player->getRcPlayer(), &_fireFloor->getRcAttack())){
		if (!_player->getIsInvincible()){
			_damage = 500 + RND->getInt(10);
			_player->damaged(_damage);
			_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top,	_damage, false);
			_tagDamageEffect.alpha1 = 255;
			_tagDamageEffect.alpha2 = 255;
			_tagDamageEffect.frameX = 0;
			_tagDamageEffect.frameY = RND->getInt(3);
			_tagDamageEffect.isCollision = true;
			_tagDamageEffect.frameTimer = 0;
			_vTagDamageEffect.push_back(_tagDamageEffect);
		}
	}
}

void battle::fireRain(){
	tagDamageEffect _tagDamageEffect;
	if ((_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 > _fireRain->getRcShadow().top &&
		(_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 < _fireRain->getRcShadow().bottom){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_player->getRcPlayer(), &_fireRain->getRcAttack())){
			if (!_player->getIsInvincible()){
				_damage = 2000 + RND->getInt(10);
				_player->damaged(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, false);
				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}
}

void battle::fireWorld(){
	if (_player->getRcPlayer().right < _fireWorld->getRcDeffence1().right ||
		_player->getRcPlayer().left > _fireWorld->getRcDeffence2().left){

	}
	else{
		if (!_player->getIsInvincible()){
			_damage = 9999;
			_player->damaged(_damage);
			_damageShow->start(_player->getPlayerX()+100, _player->getPlayerY(), _damage, false);
		}
	}
}

void battle::manaball(){
	tagDamageEffect _tagDamageEffect;
	if ((_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 > _enemy->getRcShadow().top &&
		(_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 < _enemy->getRcShadow().bottom){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_manaball->getRc(), &_enemy->getRcEnemy())){
			if (!_manaball->getIsAttack()){
				_damage = _player->getAtk() + RND->getInt(10);
				int mp = _player->getMp() + INIDATA->loadDataInterger("PlayerData", "Skill", "extract");
				if (mp > _player->getMpMax()) mp = _player->getMpMax();
				_player->setMp(mp);
				_enemy->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_manaball->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}
}

void battle::normalBullet1(){
	tagDamageEffect _tagDamageEffect;
	if ((_normalBullet1->getRcShadow().bottom + _normalBullet1->getRcShadow().top) / 2 > _enemy->getRcShadow().top &&
		(_normalBullet1->getRcShadow().bottom + _normalBullet1->getRcShadow().top) / 2 < _enemy->getRcShadow().bottom){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet1->getRc(), &_enemy->getRcEnemy())){
			if (!_normalBullet1->getIsAttack()){
				_damage = _player->getAtk() + RND->getInt(15);
				_enemy->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_normalBullet1->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
				
			}
		}
	}
	_normal1Timer++;
	if (_normal1Timer > NORMAL1_TIMER){
		_normal1Timer = 0;
		if (_normalBullet1->getIsAttack())
			_normalBullet1->setIsAttack(false);
	}
}

void battle::normalBullet2(){
	tagDamageEffect _tagDamageEffect;
	if ((_normalBullet2->getRcShadow().bottom + _normalBullet2->getRcShadow().top) / 2 > _enemy->getRcShadow().top &&
		(_normalBullet2->getRcShadow().bottom + _normalBullet2->getRcShadow().top) / 2 < _enemy->getRcShadow().bottom){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet2->getRc(), &_enemy->getRcEnemy())){
			if (!_normalBullet2->getIsAttack()){
				_damage = _player->getAtk() + RND->getInt(20);
				_enemy->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_normalBullet2->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}
	_normal2Timer++;
	if (_normal2Timer > NORMAL2_TIMER){
		_normal2Timer = 0;
		if (_normalBullet2->getIsAttack())
			_normalBullet2->setIsAttack(false);
	}
}

void battle::normalBullet3(){
	tagDamageEffect _tagDamageEffect;
	for (int i = 0; i<_normalBullet3->getVBullet().size(); i++){
		if ((_normalBullet3->getVBullet()[i].rcShadow.bottom + _normalBullet3->getVBullet()[i].rcShadow.top) / 2 > _enemy->getRcShadow().top &&
			(_normalBullet3->getVBullet()[i].rcShadow.bottom + _normalBullet3->getVBullet()[i].rcShadow.top) / 2 < _enemy->getRcShadow().bottom){
			if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet3->getVBullet()[i].rc, &_enemy->getRcEnemy())){
				if (!_normalBullet3->getVBullet()[i].isAttack){
					_damage = _player->getAtk() + RND->getInt(5);
					_enemy->damage(_damage);
					_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
					_normalBullet3->getVBullet()[i].isAttack = true;
					_normalBullet3->removeBullet(i);
					SOUNDMANAGER->play("파이어볼", 0.3f);
					_tagDamageEffect.alpha1 = 255;
					_tagDamageEffect.alpha2 = 255;
					_tagDamageEffect.frameX = 0;
					_tagDamageEffect.frameY = RND->getInt(3);
					_tagDamageEffect.isCollision = true;
					_tagDamageEffect.frameTimer = 0;
					_vTagDamageEffect.push_back(_tagDamageEffect);
				}
			}
		}
	}
}

void battle::normalBullet4(){
	tagDamageEffect _tagDamageEffect;
	for (int i = 0; i<_normalBullet4->getVBullet().size(); i++){
		if ((_normalBullet4->getVBullet()[i].rcShadow.bottom + _normalBullet4->getVBullet()[i].rcShadow.top) / 2 > _enemy->getRcShadow().top &&
			(_normalBullet4->getVBullet()[i].rcShadow.bottom + _normalBullet4->getVBullet()[i].rcShadow.top) / 2 < _enemy->getRcShadow().bottom){
			if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet4->getVBullet()[i].rc, &_enemy->getRcEnemy())){
				if (!_normalBullet4->getVBullet()[i].isAttack){
					_damage = _player->getAtk() + RND->getInt(5);
					_enemy->damage(_damage);
					_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
					_normalBullet4->getVBullet()[i].isAttack = true;
					_normalBullet4->removeBullet(i);
					SOUNDMANAGER->play("파이어볼", 0.3f);
					_tagDamageEffect.alpha1 = 255;
					_tagDamageEffect.alpha2 = 255;
					_tagDamageEffect.frameX = 0;
					_tagDamageEffect.frameY = RND->getInt(3);
					_tagDamageEffect.isCollision = true;
					_tagDamageEffect.frameTimer = 0;
					_vTagDamageEffect.push_back(_tagDamageEffect);
				}
			}
		}
	}
}

void battle::normalBullet5(){
	tagDamageEffect _tagDamageEffect;
	for (int i = 0; i<_normalBullet5->getVBullet().size(); i++){
		if ((_normalBullet5->getVBullet()[i].rcShadow.bottom + _normalBullet5->getVBullet()[i].rcShadow.top) / 2 > _enemy->getRcShadow().top &&
			(_normalBullet5->getVBullet()[i].rcShadow.bottom + _normalBullet5->getVBullet()[i].rcShadow.top) / 2 < _enemy->getRcShadow().bottom){
			if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet5->getVBullet()[i].rc, &_enemy->getRcEnemy())){
				if (!_normalBullet5->getVBullet()[i].isAttack){
					_damage = _player->getAtk() + RND->getInt(8);
					_enemy->damage(_damage);
					_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
					_normalBullet5->getVBullet()[i].isAttack = true;
					_normalBullet5->removeBullet(i);
					SOUNDMANAGER->play("파이어볼", 0.3f);
					_tagDamageEffect.alpha1 = 255;
					_tagDamageEffect.alpha2 = 255;
					_tagDamageEffect.frameX = 0;
					_tagDamageEffect.frameY = RND->getInt(3);
					_tagDamageEffect.isCollision = true;
					_tagDamageEffect.frameTimer = 0;
					_vTagDamageEffect.push_back(_tagDamageEffect);
				}
			}
		}
	}
}

void battle::skillManager(){
	tagDamageEffect _tagDamageEffect;
	//ROCK PRESS
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getRockPress()->getRcShadow(), &_enemy->getRcShadow())){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getRockPress()->getRcAttack(), &_enemy->getRcEnemy())){
			if (!_skillManager->getRockPress()->getIsAttack()){
				_damage = _player->getAtk() + RND->getInt(100) + INIDATA->loadDataInterger("PlayerData", "Skill", "thunder_cloud")*50;
				_enemy->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_skillManager->getRockPress()->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}


	//블리자드
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getBlizzard()->getRcAttack(), &_enemy->getRcEnemy())){
		if (!_skillManager->getBlizzard()->getIsAttack()){
			_damage = _player->getAtk() + RND->getInt(30) + INIDATA->loadDataInterger("PlayerData", "Skill", "blizzard")*3;
			_enemy->damage(_damage);
			_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
			_skillManager->getBlizzard()->setIsAttack(true);

			_tagDamageEffect.alpha1 = 255;
			_tagDamageEffect.alpha2 = 255;
			_tagDamageEffect.frameX = 0;
			_tagDamageEffect.frameY = RND->getInt(3);
			_tagDamageEffect.isCollision = true;
			_tagDamageEffect.frameTimer = 0;
			_vTagDamageEffect.push_back(_tagDamageEffect);
		}

		_blizzardTimer++;
		if (_blizzardTimer > NORMAL2_TIMER){
			_blizzardTimer = 0;
			if (_skillManager->getBlizzard()->getIsAttack())
				_skillManager->getBlizzard()->setIsAttack(false);
		}
	}

	//CUSS
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getCuss()->getRcShadow(), &_enemy->getRcShadow())){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getCuss()->getRcAttack(), &_enemy->getRcEnemy())){
			if (!_skillManager->getCuss()->getIsAttack()){
				_damage = _player->getAtk() + RND->getInt(6);
				_enemy->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_skillManager->getCuss()->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}

	//gravity
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getGravity()->getRcShadow(), &_enemy->getRcShadow())){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getGravity()->getRcAttack(), &_enemy->getRcEnemy())){
			if (!_skillManager->getGravity()->getIsAttack()){
				_damage = _player->getAtk() + RND->getInt(3);
				_enemy->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_skillManager->getGravity()->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}

		_gravityTimer++;
		if (_gravityTimer > GRAVITY_TIMER){
			_gravityTimer = 0;
			if (_skillManager->getGravity()->getIsAttack())
				_skillManager->getGravity()->setIsAttack(false);
		}
	}

	//petrification
	if (_skillManager->getPetrification()->getStart()){
		if (_enemy->getIsLeft()){
			if (_player->getPlayerX() < _enemy->getEnemyX()){
				//석화 발동
				RECT temp;
				if (IntersectRect(&temp, &_enemy->getRcEnemy(), &_skillManager->getPetrification()->getRcAttack())){
					_enemy->setIsPetri(true);
				}
			}
		}

		if (_enemy->getIsRight()){
			if (_player->getPlayerX() > _enemy->getEnemyX()){
				//석화 발동
				RECT temp;
				if (IntersectRect(&temp, &_enemy->getRcEnemy(), &_skillManager->getPetrification()->getRcAttack())){
					_enemy->setIsPetri(true);
				}
			}
		}
	}

	//ThunderCloud
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getThunderCloud()->getRcShadow(), &_enemy->getRcShadow())){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getThunderCloud()->getRcAttack(), &_enemy->getRcEnemy())){
			if (!_skillManager->getThunderCloud()->getIsAttack()){
				_damage = _player->getAtk() + RND->getInt(50) + INIDATA->loadDataInterger("PlayerData", "Skill", "thunder_cloud") * 10;
				_enemy->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_skillManager->getThunderCloud()->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}

	if (_skillManager->getThunderCloud()->getStart()){
		_gravityTimer++;
		if (_gravityTimer > THUNDERCLOUD_TIMER){
			_gravityTimer = 0;
			if (_skillManager->getThunderCloud()->getIsAttack())
				_skillManager->getThunderCloud()->setIsAttack(false);
		}
	}
}

void battle::floorVSmanaball(){
	tagDamageEffect _tagDamageEffect;
	if ((_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 > _fireFloor->getRcShadow().top &&
		(_player->getRcShadow().bottom + _player->getRcShadow().top) / 2 < _fireFloor->getRcShadow().bottom){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_manaball->getRc(), &_fireFloor->getRcFire())){
			if (!_manaball->getIsAttack()){
				_damage = _player->getAtk();
				_fireFloor->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_manaball->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}
}

void battle::floorVSnormalBullet1(){
	tagDamageEffect _tagDamageEffect;
	if ((_normalBullet1->getRcShadow().bottom + _normalBullet1->getRcShadow().top) / 2 > _fireFloor->getRcShadow().top &&
		(_normalBullet1->getRcShadow().bottom + _normalBullet1->getRcShadow().top) / 2 < _fireFloor->getRcShadow().bottom){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet1->getRc(), &_fireFloor->getRcFire())){
			if (!_normalBullet1->getIsAttack()){
				_damage = _player->getAtk();
				_fireFloor->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_normalBullet1->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}
}

void battle::floorVSnormalBullet2(){
	tagDamageEffect _tagDamageEffect;
	if ((_normalBullet2->getRcShadow().bottom + _normalBullet2->getRcShadow().top) / 2 > _fireFloor->getRcShadow().top &&
		(_normalBullet2->getRcShadow().bottom + _normalBullet2->getRcShadow().top) / 2 < _fireFloor->getRcShadow().bottom){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet2->getRc(), &_fireFloor->getRcFire())){
			if (!_normalBullet2->getIsAttack()){
				_damage = _player->getAtk();
				_fireFloor->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_normalBullet2->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}
	_normal2Timer++;
	if (_normal2Timer > NORMAL2_TIMER){
		_normal2Timer = 0;
		if (_normalBullet2->getIsAttack())
			_normalBullet2->setIsAttack(false);
	}
}

void battle::floorVSnormalBullet3(){
	tagDamageEffect _tagDamageEffect;
	for (int i = 0; i<_normalBullet3->getVBullet().size(); i++){
		if ((_normalBullet3->getVBullet()[i].rcShadow.bottom + _normalBullet3->getVBullet()[i].rcShadow.top) / 2 > _fireFloor->getRcShadow().top &&
			(_normalBullet3->getVBullet()[i].rcShadow.bottom + _normalBullet3->getVBullet()[i].rcShadow.top) / 2 < _fireFloor->getRcShadow().bottom){
			if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet3->getVBullet()[i].rc, &_fireFloor->getRcFire())){
				if (!_normalBullet3->getVBullet()[i].isAttack){
					_damage = _player->getAtk();
					_fireFloor->damage(_damage);
					_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
					_normalBullet3->getVBullet()[i].isAttack = true;
					_normalBullet3->removeBullet(i);

					_tagDamageEffect.alpha1 = 255;
					_tagDamageEffect.alpha2 = 255;
					_tagDamageEffect.frameX = 0;
					_tagDamageEffect.frameY = RND->getInt(3);
					_tagDamageEffect.isCollision = true;
					_tagDamageEffect.frameTimer = 0;
					_vTagDamageEffect.push_back(_tagDamageEffect);
				}
			}
		}
	}
}

void battle::floorVSnormalBullet4(){
	tagDamageEffect _tagDamageEffect;
	for (int i = 0; i<_normalBullet4->getVBullet().size(); i++){
		if ((_normalBullet4->getVBullet()[i].rcShadow.bottom + _normalBullet4->getVBullet()[i].rcShadow.top) / 2 > _fireFloor->getRcShadow().top &&
			(_normalBullet4->getVBullet()[i].rcShadow.bottom + _normalBullet4->getVBullet()[i].rcShadow.top) / 2 < _fireFloor->getRcShadow().bottom){
			if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet4->getVBullet()[i].rc, &_fireFloor->getRcFire())){
				if (!_normalBullet4->getVBullet()[i].isAttack){
					_damage = _player->getAtk();
					_fireFloor->damage(_damage);
					_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
					_normalBullet4->getVBullet()[i].isAttack = true;
					_normalBullet4->removeBullet(i);

					_tagDamageEffect.alpha1 = 255;
					_tagDamageEffect.alpha2 = 255;
					_tagDamageEffect.frameX = 0;
					_tagDamageEffect.frameY = RND->getInt(3);
					_tagDamageEffect.isCollision = true;
					_tagDamageEffect.frameTimer = 0;
					_vTagDamageEffect.push_back(_tagDamageEffect);
				}
			}
		}
	}
}

void battle::floorVSnormalBullet5(){
	tagDamageEffect _tagDamageEffect;
	for (int i = 0; i<_normalBullet5->getVBullet().size(); i++){
		if ((_normalBullet5->getVBullet()[i].rcShadow.bottom + _normalBullet5->getVBullet()[i].rcShadow.top) / 2 > _fireFloor->getRcShadow().top &&
			(_normalBullet5->getVBullet()[i].rcShadow.bottom + _normalBullet5->getVBullet()[i].rcShadow.top) / 2 < _fireFloor->getRcShadow().bottom){
			if (IntersectRect(&_tagDamageEffect.rcCollision, &_normalBullet5->getVBullet()[i].rc, &_fireFloor->getRcFire())){
				if (!_normalBullet5->getVBullet()[i].isAttack){
					_damage = _player->getAtk();
					_fireFloor->damage(_damage);
					_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
					_normalBullet5->getVBullet()[i].isAttack = true;
					_normalBullet5->removeBullet(i);

					_tagDamageEffect.alpha1 = 255;
					_tagDamageEffect.alpha2 = 255;
					_tagDamageEffect.frameX = 0;
					_tagDamageEffect.frameY = RND->getInt(3);
					_tagDamageEffect.isCollision = true;
					_tagDamageEffect.frameTimer = 0;
					_vTagDamageEffect.push_back(_tagDamageEffect);
				}
			}
		}
	}
}

void battle::floorVSskillManager(){
	tagDamageEffect _tagDamageEffect;
	//ROCK PRESS
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getRockPress()->getRcShadow(), &_fireFloor->getRcShadow())){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getRockPress()->getRcAttack(), &_fireFloor->getRcFire())){
			if (!_skillManager->getRockPress()->getIsAttack()){
				_damage = _player->getAtk();
				_fireFloor->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_skillManager->getRockPress()->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}


	//블리자드
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getBlizzard()->getRcAttack(), &_fireFloor->getRcFire())){
		if (!_skillManager->getBlizzard()->getIsAttack()){
			_damage = _player->getAtk();
			_fireFloor->damage(_damage);
			_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
			_skillManager->getBlizzard()->setIsAttack(true);

			_tagDamageEffect.alpha1 = 255;
			_tagDamageEffect.alpha2 = 255;
			_tagDamageEffect.frameX = 0;
			_tagDamageEffect.frameY = RND->getInt(3);
			_tagDamageEffect.isCollision = true;
			_tagDamageEffect.frameTimer = 0;
			_vTagDamageEffect.push_back(_tagDamageEffect);
		}

		_blizzardTimer++;
		if (_blizzardTimer > NORMAL2_TIMER){
			_blizzardTimer = 0;
			if (_skillManager->getBlizzard()->getIsAttack())
				_skillManager->getBlizzard()->setIsAttack(false);
		}
	}

	//CUSS
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getCuss()->getRcShadow(), &_fireFloor->getRcShadow())){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getCuss()->getRcAttack(), &_fireFloor->getRcFire())){
			if (!_skillManager->getCuss()->getIsAttack()){
				_damage = _player->getAtk();
				_fireFloor->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_skillManager->getCuss()->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}

	//gravity
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getGravity()->getRcShadow(), &_fireFloor->getRcShadow())){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getGravity()->getRcAttack(), &_fireFloor->getRcFire())){
			if (!_skillManager->getGravity()->getIsAttack()){
				_damage = _player->getAtk();
				_fireFloor->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_skillManager->getGravity()->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}

		_gravityTimer++;
		if (_gravityTimer > GRAVITY_TIMER){
			_gravityTimer = 0;
			if (_skillManager->getGravity()->getIsAttack())
				_skillManager->getGravity()->setIsAttack(false);
		}
	}


	//ThunderCloud
	if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getThunderCloud()->getRcShadow(), &_fireFloor->getRcShadow())){
		if (IntersectRect(&_tagDamageEffect.rcCollision, &_skillManager->getThunderCloud()->getRcAttack(), &_fireFloor->getRcFire())){
			if (!_skillManager->getThunderCloud()->getIsAttack()){
				_damage = _player->getAtk();
				_fireFloor->damage(_damage);
				_damageShow->start(_tagDamageEffect.rcCollision.left, _tagDamageEffect.rcCollision.top, _damage, true);
				_skillManager->getThunderCloud()->setIsAttack(true);

				_tagDamageEffect.alpha1 = 255;
				_tagDamageEffect.alpha2 = 255;
				_tagDamageEffect.frameX = 0;
				_tagDamageEffect.frameY = RND->getInt(3);
				_tagDamageEffect.isCollision = true;
				_tagDamageEffect.frameTimer = 0;
				_vTagDamageEffect.push_back(_tagDamageEffect);
			}
		}
	}

	if (_skillManager->getThunderCloud()->getStart()){
		_gravityTimer++;
		if (_gravityTimer > THUNDERCLOUD_TIMER){
			_gravityTimer = 0;
			if (_skillManager->getThunderCloud()->getIsAttack())
				_skillManager->getThunderCloud()->setIsAttack(false);
		}
	}
}

