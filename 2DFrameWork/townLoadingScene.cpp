#include "stdafx.h"
#include "townLoadingScene.h"


townLoadingScene::townLoadingScene()
{
}


townLoadingScene::~townLoadingScene()
{
}


HRESULT townLoadingScene::init(void)
{
	_loading = new loading;
	_loading->init();

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
	_loading->loadAlphaImage("shadow2", "�̹���/�Ҽ�����/shadow.bmp", 320, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow3", "�̹���/�Ҽ�����/shadow.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("shadow6", "�̹���/�Ҽ�����/shadow.bmp", 300, 130, true, RGB(255, 0, 255));
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
	_loading->loadImage("����1", "�̹���/����/town1.bmp", 788, 120, true, RGB(255, 0, 255));
	_loading->loadImage("����2", "�̹���/����/town2.bmp", 905, 143, true, RGB(255, 0, 255));
	_loading->loadImage("����3", "�̹���/����/town3.bmp", 1501, 813, true, RGB(255, 0, 255));
	_loading->loadImage("����4", "�̹���/����/town4.bmp", 1443, 300, true, RGB(255, 0, 255));
	_loading->loadImage("����5", "�̹���/����/town5.bmp", 1700, 250, true, RGB(255, 0, 255));
	_loading->loadImage("����6", "�̹���/����/town6.bmp", 1500, 300, true, RGB(255, 0, 255));
	_loading->loadImage("����7", "�̹���/����/town7.bmp", 1449, 303, true, RGB(255, 0, 255));
	_loading->loadImage("����8", "�̹���/����/town8.bmp", 800, WINSIZEY + 100, true, RGB(255, 0, 255));
	_loading->loadImage("����9", "�̹���/����/town9.bmp", WINSIZEX, WINSIZEY + 300, true, RGB(255, 0, 255));
	_loading->loadImage("����10", "�̹���/����/town10.bmp", 159, 297, true, RGB(255, 0, 255));
	_loading->loadImage("����11", "�̹���/����/town11.bmp", 6083, 1500, true, RGB(255, 0, 255));
	_loading->loadImage("����12", "�̹���/����/stone.bmp", 300, 1200, true, RGB(255, 0, 255));
	_loading->loadImage("����13", "�̹���/����/town12.bmp", 105, 890, true, RGB(255, 0, 255));
	_loading->loadImage("�����浹", "�̹���/����/collision.bmp", 6083, 1500, false, RGB(255, 0, 255));

	//����
	_loading->loadFrameImage("�������Ǿ�", "�̹���/����/����/�������Ǿ�.bmp", 16000, 4500, 10, 5, true, RGB(255, 0, 255));
	_loading->loadImage("������ũ", "�̹���/����/����/����������ũ.bmp", 293, 215, true, RGB(255, 0, 255));
	_loading->loadImage("��������", "�̹���/����/����/������������.bmp", 400, 107, true, RGB(255, 0, 255));
	_loading->loadImage("���Լ�����1", "�̹���/����/����/���Լ�����1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("���Լ�����2", "�̹���/����/����/���Լ�����2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("�Ű�������1", "�̹���/����/����/�Ű�������1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("�Ű�������2", "�̹���/����/����/�Ű�������2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("����������1", "�̹���/����/����/����������1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("����������2", "�̹���/����/����/����������2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("����������1", "�̹���/����/����/����������1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("����������2", "�̹���/����/����/����������2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("�����⼱����1", "�̹���/����/�����⼱����1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadImage("�����⼱����2", "�̹���/����/�����⼱����2.bmp", 467, 80, true, RGB(255, 0, 255));

	//���
	_loading->loadFrameImage("��������", "�̹���/����/���/��������.bmp", 16000, 4500, 10, 5, true, RGB(255, 0, 255));
	_loading->loadImage("��尣��", "�̹���/����/���/��尣��.bmp", 627, 92, true, RGB(255, 0, 255));
	_loading->loadImage("��尣��1", "�̹���/����/���/��尣��.bmp", 400, 92, true, RGB(255, 0, 255));
	_loading->loadImage("��帶ũ", "�̹���/����/���/��帶ũ.bmp", 208, 227, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("��ų������1", "�̹���/����/���/��ų������1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("��ų������2", "�̹���/����/���/��ų������2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("�����⼱����1", "�̹���/����/�����⼱����1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("�����⼱����2", "�̹���/����/�����⼱����2.bmp", 467, 80, true, RGB(255, 0, 255));

	//�Ҽ�������ų,���뽺ų������ �̹���
	_loading->loadImage("��ųâ���", "�̹���/����/���/��ųâ���.bmp", 1600, 146, true, RGB(255, 0, 255));
	_loading->loadImage("��ųâ�ϴ�", "�̹���/����/���/��ųâ�ϴ�.bmp", 1600, 123, true, RGB(255, 0, 255));
	_loading->loadFrameImage("�Ҽ�������ų����Ʈ������", "�̹���/����/���/�Ҽ�������ų����Ʈ������.bmp", 4140, 1200, 12, 2, true, RGB(255, 0, 255));
	_loading->loadFrameImage("���뽺ų������", "�̹���/����/���/���뽺ų������.bmp", 4212, 1248, 12, 2, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("�Ҽ�������ų����Ʈ", "�̹���/����/���/�Ҽ�������ų����Ʈ.bmp", 400, 600, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("���뽺ų����Ʈ", "�̹���/����/���/���뽺ų����Ʈ.bmp", 400, 590, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("���ó��", "�̹���/����/���/���ó��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("���ó��2", "�̹���/����/���/���ó��.bmp", 0, 0, WINSIZEX, WINSIZEY, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��ųâ�ߴ�", "�̹���/����/���/��ųâ�߰�.bmp", 1600, 631, true, RGB(255, 0, 255));

	//�Ҽ�������ų
	_loading->loadAlphaImage("��Ż�ۼҺ�", "�̹���/����/���/��Ż�ۼҺ�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("����Ʈ��Ʈ", "�̹���/����/���/����Ʈ��Ʈ.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�ܼ�Ʈ����Ʈ", "�̹���/����/���/�ܼ�Ʈ����Ʈ.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��������Ʈ��", "�̹���/����/���/��������Ʈ��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("���̽�������", "�̹���/����/���/���̽�������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�����ؼ�4", "�̹���/����/���/�����ؼ�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�׷���Ƽ", "�̹���/����/���/�׷���Ƽ.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("���Ŭ����", "�̹���/����/���/���Ŭ����.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��������", "�̹���/����/���/��������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("���ڵ�4", "�̹���/����/���/���ڵ�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�ִϸ���Ʈ������", "�̹���/����/���/�ִϸ���Ʈ������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�������̼�", "�̹���/����/���/�������̼�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("ũ������ƮǪ��", "�̹���/����/���/ũ������ƮǪ��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("Ŀ��", "�̹���/����/���/Ŀ��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��Ʈ�������̼�", "�̹���/����/���/��Ʈ�������̼�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);

	//���� ��ų
	_loading->loadAlphaImage("�����̵�", "�̹���/����/���/�����̵�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�������", "�̹���/����/���/�������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��彺�ھ", "�̹���/����/���/��彺�ھ.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��Ʈ����Ʈ��", "�̹���/����/���/��Ʈ����Ʈ��.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("Ǫ����������", "�̹���/����/���/Ǫ����������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�����׳ͽ�", "�̹���/����/���/�����׳ͽ�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("����������", "�̹���/����/���/����������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�̺��̵�", "�̹���/����/���/�̺��̵�.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("����Ʈ������", "�̹���/����/���/����Ʈ������.bmp", 0, 0, 250, 400, true, RGB(255, 0, 255), true);

	//��ȭ �̹���
	_loading->loadAlphaImage("��ȭ����", "�̹���/talkBar.bmp", 1600, 118, true, RGB(255, 0, 255));
	_loading->loadImage("no", "�̹���/no.bmp", 184, 185, true, RGB(255, 0, 255));
	_loading->loadImage("yes", "�̹���/yes.bmp", 185, 185, true, RGB(255, 0, 255));
	_loading->loadImage("no_check", "�̹���/no_check.bmp", 236, 234, true, RGB(255, 0, 255));
	_loading->loadImage("yes_check", "�̹���/yes_check.bmp", 234, 235, true, RGB(255, 0, 255));

	//����
	_loading->loadImage("����", "�̹���/����/����/����.bmp", 1920, 957, true, RGB(255, 0, 255));
	_loading->loadFrameImage("��������", "�̹���/����/����/��������.bmp", 14616, 998, 24, 2, true, RGB(255, 0, 255));
	_loading->loadImage("��������", "�̹���/����/����/��������.bmp", 651, 118, true, RGB(255, 0, 255));
	_loading->loadImage("��������1", "�̹���/����/����/��������.bmp", 350, 118, true, RGB(255, 0, 255));
	_loading->loadImage("������ũ", "�̹���/����/����/������ũ.bmp", 191, 171, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("�����⼱����1", "�̹���/����/�����⼱����1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("�����⼱����2", "�̹���/����/�����⼱����2.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("���̺꼱����1", "�̹���/����/����/���̺꼱����1.bmp", 467, 80, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("���̺꼱����2", "�̹���/����/����/���̺꼱����2.bmp", 467, 80, true, RGB(255, 0, 255));

	//������ ��� �̹��� �ҷ����� 
	_loading->loadImage("���̺�å1", "�̹���/����/����/���̺�/���̺�1.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	_loading->loadImage("���̺�å2", "�̹���/����/����/���̺�/���̺�2.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	_loading->loadImage("���̺�å3", "�̹���/����/����/���̺�/���̺�3.bmp", 0, 0, 164, 165, true, RGB(255, 0, 255), true);
	_loading->loadImage("ū���̺�å1", "�̹���/����/����/���̺�/���̺�1.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	_loading->loadImage("ū���̺�å2", "�̹���/����/����/���̺�/���̺�2.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	_loading->loadImage("ū���̺�å3", "�̹���/����/����/���̺�/���̺�3.bmp", 0, 0, 200, 200, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("���̺�", "�̹���/����/����/���̺�/���̺�.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("���̺���ġ����", "�̹���/����/����/���̺�/���̺���ġ����1.bmp", 1505, 206, true, RGB(255, 0, 255));


	//�÷��̾� ����
	_loading->loadAlphaImage("������ǰ���", "�̹���/menu/������ǰ/���_����ǰ.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("������缱����ġ", "�̹���/����/����/���缱����ġ.bmp", 0, 0, 600, 73, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("bgItemBox", "�̹���/menu/�����۹ڽ�/�����۹ڽ�.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("���������缱����ġ", "�̹���/����/����/���缱����ġ.bmp", 0, 0, 900, 100, true, RGB(255, 0, 255), true);

	//�Ŵ�
	_loading->loadAlphaImage("state_bag_choice1", "�̹���/menu/state_bag_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_bag_choice2", "�̹���/menu/state_bag_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_inven_choice1", "�̹���/menu/state_inven_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_inven_choice2", "�̹���/menu/state_inven_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_skill_choice1", "�̹���/menu/state_skill_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_skill_choice2", "�̹���/menu/state_skill_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_state_choice1", "�̹���/menu/state_state_choice1.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("state_state_choice2", "�̹���/menu/state_state_choice2.bmp", 492, 100, true, RGB(255, 0, 255));
	_loading->loadImage("talizman_empty", "�̹���/menu/talizman_empty.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman1", "�̹���/menu/talizman1.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman2", "�̹���/menu/talizman2.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman3", "�̹���/menu/talizman3.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman4", "�̹���/menu/talizman4.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman5", "�̹���/menu/talizman5.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman6", "�̹���/menu/talizman6.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman7", "�̹���/menu/talizman7.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman8", "�̹���/menu/talizman8.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadImage("talizman9", "�̹���/menu/talizman9.bmp", 45, 55, true, RGB(255, 0, 255));
	_loading->loadPngImage("bg_sorceress", L"�̹���/menu/bg_sorceressout.png", 900, 900);
	_loading->loadAlphaImage("state_money", "�̹���/menu/state_money.bmp", 581, 84, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("bgGray", "�̹���/menu/bgGray.bmp", 1600, 900, true, RGB(255, 0, 255));
	_loading->loadImage("menu_talizman", "�̹���/menu/menu_talizman.bmp", 581, 100, true, RGB(255, 0, 255));

	//��ų����
	_loading->loadAlphaImage("bgSkillInfo", "�̹���/menu/��ų/��ųȮ��.bmp", 1600, 900, true, RGB(255, 0, 255));

	//�Ҽ�������ų
	_loading->loadAlphaImage("��Ż�ۼҺ�1", "�̹���/����/���/��Ż�ۼҺ�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("����Ʈ��Ʈ1", "�̹���/����/���/����Ʈ��Ʈ.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�ܼ�Ʈ����Ʈ1", "�̹���/����/���/�ܼ�Ʈ����Ʈ.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��������Ʈ��1", "�̹���/����/���/��������Ʈ��.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("���̽�������1", "�̹���/����/���/���̽�������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�����ؼ�1", "�̹���/����/���/�����ؼ�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�׷���Ƽ1", "�̹���/����/���/�׷���Ƽ.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("���Ŭ����1", "�̹���/����/���/���Ŭ����.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��������1", "�̹���/����/���/��������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("���ڵ�1", "�̹���/����/���/���ڵ�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�ִϸ���Ʈ������1", "�̹���/����/���/�ִϸ���Ʈ������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�������̼�1", "�̹���/����/���/�������̼�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("ũ������ƮǪ��1", "�̹���/����/���/ũ������ƮǪ��.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("Ŀ��1", "�̹���/����/���/Ŀ��.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��Ʈ�������̼�1", "�̹���/����/���/��Ʈ�������̼�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);

	//���� ��ų
	_loading->loadAlphaImage("�����̵�1", "�̹���/����/���/�����̵�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�������1", "�̹���/����/���/�������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��彺�ھ1", "�̹���/����/���/��彺�ھ.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("��Ʈ����Ʈ��1", "�̹���/����/���/��Ʈ����Ʈ��.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("Ǫ����������1", "�̹���/����/���/Ǫ����������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�����׳ͽ�1", "�̹���/����/���/�����׳ͽ�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("����������1", "�̹���/����/���/����������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("�̺��̵�1", "�̹���/����/���/�̺��̵�.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);
	_loading->loadAlphaImage("����Ʈ������1", "�̹���/����/���/����Ʈ������.bmp", 0, 0, 210, 320, true, RGB(255, 0, 255), true);

	//��ų���� ������
	_loading->loadAlphaImage("��ų����������1", "�̹���/menu/��ų/��ų����������1.bmp", 1400, 90, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("��ų����������2", "�̹���/menu/��ų/��ų����������2.bmp", 1400, 90, true, RGB(255, 0, 255));


	//����â
	_loading->loadAlphaImage("stateTop", "�̹���/menu/�������ͽ�/�������ͽ�_top.bmp", 1600, 146, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("stateBottom", "�̹���/menu/�������ͽ�/�������ͽ�_bottom.bmp", 1600, 200, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("������1", "�̹���/menu/�������ͽ�/�������ͽ�_������1.bmp", 840, 570, true, RGB(255, 0, 255));
	_loading->loadImage("�̹���/menu/�������ͽ�/expBarFull", "�̹���/menu/�������ͽ�/expBarFull.bmp", WINSIZEX / 2, 700, 1600, 200, true, RGB(255, 0, 255), true);
	_loading->loadImage("�̹���/menu/�������ͽ�/expBar", "�̹���/menu/�������ͽ�/expBar.bmp", WINSIZEX / 2, 700, 1600, 200, true, RGB(255, 0, 255), true);

	//������
	_loading->loadFrameImage("������", "�̹���/����/item.bmp", 950, 760, 10, 8, true, RGB(255, 0, 255));
	_loading->loadFrameImage("������1", "�̹���/����/item.bmp", 600, 500, 10, 8, true, RGB(255, 0, 255), true);
	_loading->loadFrameImage("������2", "�̹���/����/item.bmp", 400, 300, 10, 8, true, RGB(255, 0, 255), true);

	//����
	_loading->loadAlphaImage("����", "�̹���/����.bmp", 648, 151, false, RGB(255, 0, 255));
	_loading->loadAlphaImage("����", "�̹���/����.bmp", 583, 473, false, RGB(255, 0, 255));

	_loading->loadImage("������ũ", "�̹���/����/����/������ũ.bmp", 218, 209, true, RGB(255, 0, 255));
	_loading->loadImage("��������", "�̹���/����/����/��������.bmp", 400, 112, true, RGB(255, 0, 255));
	_loading->loadImage("��������", "�̹���/����/����/��������.bmp", 658, 112, true, RGB(255, 0, 255));

	//��
	_loading->loadImage("z", "�̹���/��/z.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("zClick", "�̹���/��/zŬ��.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("z����", "�̹���/��/z����.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("t����", "�̹���/��/t����.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("s����", "�̹���/��/s����.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("d����", "�̹���/��/d����.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("e����", "�̹���/��/e����.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("r����", "�̹���/��/r����.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("m����", "�̹���/��/m����.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("z�ߵ�", "�̹���/��/z�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("t�ߵ�", "�̹���/��/t�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("s�ߵ�", "�̹���/��/s�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("d�ߵ�", "�̹���/��/d�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("e�ߵ�", "�̹���/��/e�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("r�ߵ�", "�̹���/��/r�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadImage("m�ߵ�", "�̹���/��/m�ߵ�.bmp", 64, 64, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("rune_room", "�̹���/��/��ĭ.bmp", 100, 100, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("rune_black", "�̹���/��/black.bmp", 1600, 900, false, RGB(255, 0, 255));
	_loading->loadAlphaFrameImage("light", "�̹���/��/light.bmp", 595 * 2, 595 * 2, 4, 4, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("rmz_info", "�̹���/��/rmz_info.bmp", 1600, 113, true, RGB(255, 0, 255));
	_loading->loadAlphaImage("rmz_bg", "�̹���/���巡��/���巡����.bmp", 1600, 900, false, RGB(255, 0, 255));
	return S_OK;
}

void townLoadingScene::release(void)
{
	SAFE_DELETE(_loading);
}

void townLoadingScene::update(void)
{
	_loading->update();

	if (!_loading->loadNext())
	{
		SCENEMANAGER->changeScene("������");
	}
	else {

	}
}

void townLoadingScene::render(void)
{
	_loading->render();
}