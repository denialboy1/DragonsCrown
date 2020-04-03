#include "stdafx.h"
#include "graveStageLoadingScene.h"


graveStageLoadingScene::graveStageLoadingScene()
{
}


graveStageLoadingScene::~graveStageLoadingScene()
{
}

HRESULT graveStageLoadingScene::init(void)
{
	_loading = new loading;
	_loading->init();

	char image[256];

	//�ε��� �ѹ� �غ��ô�
	memset(image, 0, sizeof(image));
	//��������
	_loading->loadImage("���Ͻ�������1", "�̹���/����/���Ͻ�������1.bmp", 5415, 900, true, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������1�ȼ�", "�̹���/����/���Ͻ�������1�ȼ�.bmp", 5415, 900, true, RGB(255, 0, 255));
	_loading->loadImage("���Ϲ��1", "�̹���/����/���Ϲ��.bmp", 1764, 569, true, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������2", "�̹���/����/���Ͻ�������2.bmp", 1600, 940, true, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������2_2", "�̹���/����/���Ͻ�������2_2.bmp", 1600, 940, true, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������2�ȼ�", "�̹���/����/���Ͻ�������2�ȼ�.bmp", 1600, 940, true, RGB(255, 0, 255));
	_loading->loadImage("���Ϲ��2", "�̹���/����/���Ϲ��.bmp", 1764, 569, true, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������3", "�̹���/����/���Ͻ�������3.bmp", 6000, 1000, true, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������3�ȼ�", "�̹���/����/���Ͻ�������3�ȼ�.bmp", 6000, 1000, true, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������3_2", "�̹���/����/���Ͻ�������3_2.bmp", 6000, 1000, true, RGB(255, 0, 255));
	_loading->loadImage("���Ϲ��3", "�̹���/����/���Ϲ��3.bmp", 1009 * 2, 821 * 2, true, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������4", "�̹���/����/���Ͻ�������4.bmp", 1600, 940, false, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������4�ȼ�", "�̹���/����/���Ͻ�������4�ȼ�.bmp", 1600, 940, false, RGB(255, 0, 255));
	_loading->loadImage("���Ͻ�������4_2", "�̹���/����/���Ͻ�������4_2.bmp", 1600, 940, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("grave_black", "�̹���/��/black.bmp", 1600, 900, false, RGB(255, 0, 255));

	//�÷��̾�
	_loading->loadAlphaFrameImage("sorceress_stand", "�̹���/�Ҽ�����/sorceress_stand.bmp", 2233, 912, 7, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_walk", "�̹���/�Ҽ�����/sorceress_walk.bmp", 4080, 950, 12, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_run", "�̹���/�Ҽ�����/sorceress_run.bmp", 3740, 950, 11, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_turn", "�̹���/�Ҽ�����/sorceress_turn.bmp", 680, 950, 2, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_jump", "�̹���/�Ҽ�����/sorceress_jump.bmp", 3700, 950, 10, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_ravitation", "�̹���/�Ҽ�����/sorceress_ravitation.bmp", 2800, 950, 7, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_attack1", "�̹���/�Ҽ�����/sorceress_attack1.bmp", 3500, 1100, 7, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_attack2", "�̹���/�Ҽ�����/sorceress_attack2.bmp", 3000, 1100, 6, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_attack3", "�̹���/�Ҽ�����/sorceress_attack3.bmp", 5500, 1100, 11, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_attack4", "�̹���/�Ҽ�����/sorceress_attack4.bmp", 3500, 1100, 7, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_jump_attack1", "�̹���/�Ҽ�����/sorceress_jump_down_attack.bmp", 2900, 1100, 6, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_jump_attack2", "�̹���/�Ҽ�����/sorceress_jump_up_attack.bmp", 3000, 1000, 6, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_damage", "�̹���/�Ҽ�����/sorceress_damage.bmp", 2500, 1100, 5, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_down", "�̹���/�Ҽ�����/sorceress_down.bmp", 10000, 1232, 20, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_gauge", "�̹���/�Ҽ�����/sorceress_gauge.bmp", 7500, 950, 15, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_ability", "�̹���/�Ҽ�����/sorceress_ability.bmp", 3000, 1000, 6, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_potion", "�̹���/�Ҽ�����/sorceress_potion.bmp", 6000, 1120, 12, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_skill", "�̹���/�Ҽ�����/sorceress_skill.bmp", 4000, 1200, 8, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("sorceress_food_eat", "�̹���/�Ҽ�����/����Ա�.bmp", 6500, 1100, 13, 2, true, RGB(255, 0, 255));
	_loading->loadPngImage("shadow", L"�̹���/�Ҽ�����/shadow.png", 300, 32);
	_loading->loadAlphaImage("shadow1", "�̹���/�Ҽ�����/shadow.bmp", 300, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow6", "�̹���/�Ҽ�����/shadow.bmp", 300, 130, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow2", "�̹���/�Ҽ�����/shadow.bmp", 320, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow3", "�̹���/�Ҽ�����/shadow.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("����������", "�̹���/�Ҽ�����/����������.bmp", 400, 100, 100, 100, true, RGB(255, 0, 255));
	_loading->loadFrameImage("manaball", "�̹���/�Ҽ�����/manaball.bmp", 1542, 200, 6, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("fireball1", "�̹���/�Ҽ�����/fireball1.bmp", 6120, 400, 17, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("fireball2", "�̹���/�Ҽ�����/fireball2.bmp", 6750, 450, 15, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("normalBullet3", "�̹���/�Ҽ�����/fireball3.bmp", 1285, 314, 5, 2, true, RGB(255, 0, 255));
	_loading->loadFrameImage("normalBullet4", "�̹���/�Ҽ�����/fireball4.bmp", 2400, 800, 6, 2, true, RGB(255, 0, 255));
	_loading->loadFrameImage("normalBullet5", "�̹���/�Ҽ�����/fireball4.bmp", 1200, 400, 6, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("���ڵ�", "�̹���/�Ҽ�����/��ų/���ڵ�.bmp", 1600, 900, false, RGB(255, 0, 255));
	_loading->loadAlphaImage("apple", "�̹���/����/apple.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("pear", "�̹���/����/pear.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("pormegranate", "�̹���/����/pormegranate.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow4", "�̹���/�Ҽ�����/shadow.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("cuss", "�̹���/�Ҽ�����/��ų/Ŀ��.bmp", 3600, 1000, 12, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow5", "�̹���/�Ҽ�����/shadow.bmp", 200, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("gravity", "�̹���/�Ҽ�����/��ų/�׷���Ƽ.bmp", 10500, 500, 21, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("gravity_arrage", "�̹���/�Ҽ�����/��ų/�׷���Ƽ����.bmp", 1000, 700, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision1", "�̹���/�Ҽ�����/��ų/���̽�������1.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision2", "�̹���/�Ҽ�����/��ų/���̽�������2.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision3", "�̹���/�Ҽ�����/��ų/���̽�������3.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision4", "�̹���/�Ҽ�����/��ų/���̽�������4.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("icePrision5", "�̹���/�Ҽ�����/��ų/���̽�������5.bmp", 200, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("��ȭ", "�̹���/�Ҽ�����/��ų/��Ʈ�������̼�.bmp", 1500, 300, 5, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("��ȭȿ��", "�̹���/�Ҽ�����/��ų/��ȭȿ��.bmp", 1600, 900, false, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("�����ؼ�", "�̹���/�Ҽ�����/��ų/�����ؼ�.bmp", 5400, 900, 6, 1, true, RGB(255, 0, 255));
	_loading->loadPngFrameImage("rockPress", L"�̹���/�Ҽ�����/��ų/����.png", 900, 600, 3, 1);
	_loading->loadAlphaImage("rockPress2", "�̹���/�Ҽ�����/��ų/����3.bmp", 400, 500, true, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("����", "�̹���/�Ҽ�����/��ų/����.bmp", 1200, 150, 4, 1, true, RGB(255, 0, 255));
	_loading->loadFrameImage("����", "�̹���/�Ҽ�����/��ų/����.bmp", 600, 800, 6, 1, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("�ǰ����", "�̹���/�Ҽ�����/���.bmp", 300, 300, false, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("�ǰ�����Ʈ", "�̹���/�Ҽ�����/�ǰ�����Ʈ.bmp", 900, 900, 3, 3, true, RGB(255, 0, 255));
	_loading->loadSound("����1", "����/�Ҽ�����/����.mp3", false, false);
	_loading->loadSound("���ڷ�Ÿ��", "����/�Ҽ�����/����2.mp3", false, false);
	_loading->loadSound("����3", "����/�Ҽ�����/����3.mp3", false, false);
	_loading->loadSound("����4", "����/�Ҽ�����/����4.mp3", false, false);
	_loading->loadSound("�������", "����/�Ҽ�����/�������.mp3", false, false);
	_loading->loadSound("����������", "����/�Ҽ�����/����������.mp3", false, false);
	_loading->loadSound("����������2", "����/�Ҽ�����/����������2.mp3", false, false);
	_loading->loadSound("����������3", "����/�Ҽ�����/����������3.mp3", false, false);
	_loading->loadSound("����", "����/�Ҽ�����/����.mp3", false, false);
	_loading->loadSound("����1", "����/�Ҽ�����/����1.mp3", false, false);
	_loading->loadSound("����2", "����/�Ҽ�����/����2.mp3", false, false);
	_loading->loadSound("������", "����/�Ҽ�����/������.wav", false, false);
	_loading->loadSound("��ų", "����/�Ҽ�����/��ų.wav", false, true);
	_loading->loadSound("���Ǹ��ñ�", "����/�Ҽ�����/���Ǹ��ñ�.wav", false, false);
	_loading->loadSound("���̾�2", "����/�Ҽ�����/���̾�2.wav", false, false);
	_loading->loadSound("����", "����/�Ҽ�����/����.wav", false, false);
	_loading->loadSound("�߷�", "����/�Ҽ�����/gravity.wav", false, false);
	_loading->loadSound("���ĸԱ�", "����/�Ҽ�����/���ĸԱ�.wav", false, false);
	_loading->loadSound("���ڵ�", "����/�Ҽ�����/���ڵ�.wav", false, false);
	_loading->loadSound("createFood", "����/�Ҽ�����/createFood.wav", false, false);
	_loading->loadSound("Ŀ��", "����/�Ҽ�����/cuss.wav", false, false);
	_loading->loadSound("gravity", "����/�Ҽ�����/gravity.wav", false, false);
	_loading->loadSound("���̽�������", "����/�Ҽ�����/���̽�������.wav", false, false);
	_loading->loadSound("��Ʈ��", "����/�Ҽ�����/petri.wav", false, false);
	_loading->loadSound("�������", "����/�Ҽ�����/�������.wav", false, false);
	_loading->loadSound("��������", "����/�Ҽ�����/��������.wav", false, false);
	_loading->loadSound("stone", "����/�Ҽ�����/stone.wav", false, false);
	_loading->loadSound("thunder", "����/�Ҽ�����/thunderstorm.wav", false, false);
	_loading->loadSound("���̾", "����/�Ҽ�����/���̾.wav", false, false);

	//����
	_loading->loadSound("������", "����/����/������.wav", false, false);
	_loading->loadSound("�䳢����", "����/����/�䳢����.wav", false, false);
	_loading->loadSound("�䳢����2", "����/����/�䳢����2.wav", false, false);
	_loading->loadSound("�䳢����", "����/����/�䳢����.wav", false, false);
	_loading->loadSound("�������", "����/����/�������.wav", false, false);
	_loading->loadSound("���������", "����/����/���������.wav", false, false);
	_loading->loadSound("�������", "����/����/�������.wav", false, false);
	_loading->loadSound("����", "����/����/����.wav", false, false);
	_loading->loadSound("���ɺ��", "����/����/���ɺ��.wav", false, false);
	_loading->loadSound("�䳢����", "����/����/�䳢����.mp3", true, true);
	_loading->loadSound("�������", "����/����/�������.mp3", true, true);
	_loading->loadSound("������������", "����/����/������������.mp3", true, true);
	_loading->loadSound("������������", "����/����/������������.mp3", true, true);
	_loading->loadImage("�̹���/���巡��/dragonHPTop", "�̹���/���巡��/dragonHPTop.bmp", 800, 800, 1340, 58, true, RGB(255, 0, 255), false);
	_loading->loadImage("�̹���/���巡��/dragonHPBottom", "�̹���/���巡��/dragonHPBottom.bmp", 800, 800, 1340, 58, true, RGB(255, 0, 255), false);
	return S_OK;
}

void graveStageLoadingScene::release(void)
{
	SAFE_DELETE(_loading);
}

void graveStageLoadingScene::update(void)
{
	_loading->update();

	if (!_loading->loadNext())
	{
		SCENEMANAGER->changeScene("��������������");
	}
	else {

	}
}

void graveStageLoadingScene::render(void)
{
	_loading->render();
}