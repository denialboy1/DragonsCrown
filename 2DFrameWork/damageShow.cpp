#include "stdafx.h"
#include "damageShow.h"


damageShow::damageShow()
{
}


damageShow::~damageShow()
{
}

HRESULT damageShow::init(){

	return S_OK;
}
void damageShow::update(){
	for (int i = 0; i < _vDamage.size(); i++){
		_vDamage[i].y--;
	}

	for (_viDamage = _vDamage.begin(); _viDamage != _vDamage.end();){
		if ((*_viDamage).y < (*_viDamage).limitY){
			_vDamage.erase(_viDamage);
			break;
		}
		else{
			_viDamage++;
		}
	}
}
void damageShow::render(){
	HFONT oldFont;
	HFONT font1;
	SetBkMode(getMemDC(), TRANSPARENT);
	char str[100];
	font1 = CreateFont(50, 30, 0, 0, 300, 0, 0, 0, HANGUL_CHARSET, 0, 0, 0, 0, TEXT("Pyunji R"));
	oldFont = (HFONT)SelectObject(getMemDC(), font1);
	
	for (int i = 0; i < _vDamage.size(); i++){
		if (_vDamage[i].enemy){
			sprintf(str, "%d", _vDamage[i].damage);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), _vDamage[i].x + 2, _vDamage[i].y + 2, str, strlen(str));
			SetTextColor(getMemDC(), RGB(255, 255, 255));
			TextOut(getMemDC(), _vDamage[i].x, _vDamage[i].y, str, strlen(str));
			
		}
		else{
			sprintf(str, "%d", _vDamage[i].damage);
			SetTextColor(getMemDC(), RGB(0, 0, 0));
			TextOut(getMemDC(), _vDamage[i].x + 2, _vDamage[i].y + 2, str, strlen(str));
			SetTextColor(getMemDC(), RGB(255, 144, 144));
			TextOut(getMemDC(), _vDamage[i].x, _vDamage[i].y, str, strlen(str));
			
		}
	}
	SelectObject(getMemDC(), oldFont);
	DeleteObject(font1);
}
void damageShow::release(){}
void damageShow::start(int x, int y, int damage,bool enemy){
	tagDamage temp;
	temp.x = x;
	temp.y = y;
	temp.limitY = temp.y - 100;
	temp.damage = damage;
	temp.enemy = enemy;
	_vDamage.push_back(temp);
}