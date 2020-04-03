#pragma once
#include "gameNode.h"
#include "animation.h"


class barScene : public gameNode
{
private:
	//�� ���� �ִ� ����â
	enum BARSTATE{ BAR, GAMESAVE };
	//���� � �޴��� �����ϰ��մ���
	enum MENUSTATE{ SAVE, BAREXIT };
	//���̺� ��ġ
	enum SAVESTATE{ SAVE1, SAVE2, SAVE3 };

private:
	animation* _fairy;
	BARSTATE _choiceState;
	MENUSTATE _menuState;
	SAVESTATE _saveState;
	int _menuChoice;
	int _saveChoice;
public:
	barScene();
	~barScene();

	HRESULT init();
	void update();
	void render();
	void release();


	void save1(char* fileName);
	void save2(char* fileName);
	void save3(char* fileName);
};

