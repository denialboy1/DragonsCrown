#pragma once
#include "gameNode.h"

//�ӵ��� ���� ���漱��
class animation;

class effect : public gameNode
{
protected:
	int			_x;		//����Ʈ ��ǥ��ġ(x) ����Ʈ
	int			_y;		//����Ʈ ��ǥ��ġ(y) ž

	image*		_effectImage;		//����Ʈ �̹���
	animation*	_effectAnimation;	//����Ʈ �ִϸ��̼�
	BOOL		_isRunning;			//����Ʈ Ȱ��ȭ ����
	float		_elapsedTime;		//����Ʈ ����ð�

public:
	effect();
	virtual ~effect();

	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void startEffect(int x, int y);
	virtual void killEffect(void);

	BOOL getIsRunning(void) { return _isRunning; }
};


class effectAlpha : public gameNode
{
protected:
	int			_x;		//����Ʈ ��ǥ��ġ(x) ����Ʈ
	int			_y;		//����Ʈ ��ǥ��ġ(y) ž

	alphaImage*	_effectImage;		//����Ʈ �̹���
	animation*	_effectAnimation;	//����Ʈ �ִϸ��̼�
	BOOL		_isRunning;			//����Ʈ Ȱ��ȭ ����
	float		_elapsedTime;		//����Ʈ ����ð�

	int			_alpha;				//���İ�

public:
	effectAlpha();
	virtual ~effectAlpha();

	virtual HRESULT init(alphaImage* effectImage, int frameW, int frameH, int fps, float elapsedTime,int alpha);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void startEffect(int x, int y);
	virtual void killEffect(void);

	BOOL getIsRunning(void) { return _isRunning; }
};

/*
class pngEffect : public gameNode
{
protected:
	int			_x;		//����Ʈ ��ǥ��ġ(x) ����Ʈ
	int			_y;		//����Ʈ ��ǥ��ġ(y) ž

	pngImage*	_effectImage;		//����Ʈ �̹���
	animation*	_effectAnimation;	//����Ʈ �ִϸ��̼�
	BOOL		_isRunning;			//����Ʈ Ȱ��ȭ ����
	float		_elapsedTime;		//����Ʈ ����ð�

public:
	pngEffect();
	virtual ~pngEffect();

	virtual HRESULT init(pngImage* effectImage, int frameW, int frameH, int fps, float elapsedTime);
	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void startEffect(int x, int y);
	virtual void killEffect(void);

	BOOL getIsRunning(void) { return _isRunning; }
};*/