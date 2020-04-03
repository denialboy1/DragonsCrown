#include "stdafx.h"
#include "effectManager.h"
#include "effect.h"

effectManager::effectManager()
{
}


effectManager::~effectManager()
{
}

HRESULT effectManager::init(void)
{

	return S_OK;
}

void effectManager::release(void)
{
	iterTotalEffect vIter;
	iterEffect mIter;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	vIter = _vTotalEffects.begin();

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (; vIter != _vTotalEffects.end(); ++vIter)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		mIter = vIter->begin();
		for (; mIter != vIter->end();)
		{
			if (mIter->second.size() != 0)
			{
				iterEffects vArrIter = mIter->second.begin();
				for (; vArrIter != mIter->second.end(); ++vArrIter)
				{
					(*vArrIter)->release();
					delete *vArrIter;
					vArrIter = mIter->second.erase(vArrIter);
				}
			}
			else
			{
				++mIter;
			}

		}
	}
	/*
	//png����
	iterTotalPngEffect vIterPng;
	iterPngEffect mIterPng;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	vIterPng = _vTotalPngEffects.begin();

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (; vIterPng != _vTotalPngEffects.end(); ++vIterPng)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		mIterPng = vIterPng->begin();
		for (; mIterPng != vIterPng->end();)
		{
			if (mIterPng->second.size() != 0)
			{
				iterPngEffects vArrIter = mIterPng->second.begin();
				for (; vArrIter != mIterPng->second.end(); ++vArrIter)
				{
					(*vArrIter)->release();
					delete *vArrIter;
					vArrIter = mIterPng->second.erase(vArrIter);
				}
			}
			else
			{
				++mIterPng;
			}

		}
	}
	*/
}

void effectManager::update(void)
{
	iterTotalEffect vIter;
	iterEffect mIter;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIter = _vTotalEffects.begin(); vIter != _vTotalEffects.end(); ++vIter)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			iterEffects vArrIter;
			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				(*vArrIter)->update();
			}
		}
	}

	iterTotalEffectAlpha vIterAlpha;
	iterEffectAlpha mIterAlpha;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIterAlpha = _vTotalEffectsAlpha.begin(); vIterAlpha != _vTotalEffectsAlpha.end(); ++vIterAlpha)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIterAlpha = vIterAlpha->begin(); mIterAlpha != vIterAlpha->end(); ++mIterAlpha)
		{
			iterEffectsAlpha vArrIter;
			for (vArrIter = mIterAlpha->second.begin(); vArrIter != mIterAlpha->second.end(); ++vArrIter)
			{
				(*vArrIter)->update();
			}
		}
	}
	//png����
	/*
	iterTotalPngEffect vIterPng;
	iterPngEffect mIterPng;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIterPng = _vTotalPngEffects.begin(); vIterPng != _vTotalPngEffects.end(); ++vIterPng)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIterPng = vIterPng->begin(); mIterPng != vIterPng->end(); ++mIterPng)
		{
			iterPngEffects vArrIter;
			for (vArrIter = mIterPng->second.begin(); vArrIter != mIterPng->second.end(); ++vArrIter)
			{
				(*vArrIter)->update();
			}
		}
	}*/
}

void effectManager::render(void)
{
	iterTotalEffect vIter;
	iterEffect mIter;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIter = _vTotalEffects.begin(); vIter != _vTotalEffects.end(); ++vIter)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			iterEffects vArrIter;
			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				(*vArrIter)->render();
			}
		}
	}

	iterTotalEffectAlpha vIterAlpha;
	iterEffectAlpha mIterAlpha;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIterAlpha = _vTotalEffectsAlpha.begin(); vIterAlpha != _vTotalEffectsAlpha.end(); ++vIterAlpha)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIterAlpha = vIterAlpha->begin(); mIterAlpha != vIterAlpha->end(); ++mIterAlpha)
		{
			iterEffectsAlpha vArrIter;
			for (vArrIter = mIterAlpha->second.begin(); vArrIter != mIterAlpha->second.end(); ++vArrIter)
			{
				(*vArrIter)->render();
			}
		}
	}
	/*
	iterTotalPngEffect vIterPng;
	iterPngEffect mIterPng;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIterPng = _vTotalPngEffects.begin(); vIterPng != _vTotalPngEffects.end(); ++vIterPng)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIterPng = vIterPng->begin(); mIterPng != vIterPng->end(); ++mIterPng)
		{
			iterPngEffects vArrIter;
			for (vArrIter = mIterPng->second.begin(); vArrIter != mIterPng->second.end(); ++vArrIter)
			{
				(*vArrIter)->render();
			}
		}
	}
	*/
}

void effectManager::addEffect(string effectName, const char* imageName, int imageWidth,
	int imageHeight, int effectWidth, int effectHeight, int fps, float elapsedTime, int buffer)
{
	image* img;
	arrEffects vEffectBuffer; //����Ʈ ����
	arrEffect mArrEffect;	  //Ű ���� ����Ʈ ���� ����� ��

	//��ϵ� �̹����� �Ŵ����� �̹� ������
	if (IMAGEMANAGER->findImage(imageName))
	{
		img = IMAGEMANAGER->findImage(imageName);
	}
	else
	{
		img = IMAGEMANAGER->addImage(imageName, imageName, imageWidth, imageHeight, true, RGB(255, 0, 255));
	}

	//�� ���۰�����ŭ ���Ϳ� �����
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new effect);
		vEffectBuffer[i]->init(img, effectWidth, effectHeight, fps, elapsedTime);
	}

	//����Ʈ ���۸� �ʿ� �����
	mArrEffect.insert(pair<string, arrEffects>(effectName, vEffectBuffer));

	//Ű ���� ���۸� ���� ���� ��Ż���Ϳ� �����
	_vTotalEffects.push_back(mArrEffect);

}

void effectManager::addEffect(string effectName, const char* imageName, int imageWidth,
	int imageHeight, int effectWidth, int effectHeight, int fps, float elapsedTime, int buffer,int alpha)
{
	alphaImage* img;
	arrEffectsAlpha vEffectBuffer; //����Ʈ ����
	arrEffectAlpha mArrEffect;	  //Ű ���� ����Ʈ ���� ����� ��

	//��ϵ� �̹����� �Ŵ����� �̹� ������
	if (IMAGEMANAGER->findAlphaImage(imageName))
	{
		img = IMAGEMANAGER->findAlphaImage(imageName);
	}
	else
	{
		img = IMAGEMANAGER->addAlphaImage(imageName, imageName, imageWidth, imageHeight, true, RGB(255, 0, 255));
	}

	//�� ���۰�����ŭ ���Ϳ� �����
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new effectAlpha);
		vEffectBuffer[i]->init(img, effectWidth, effectHeight, fps, elapsedTime,alpha);
	}

	//����Ʈ ���۸� �ʿ� �����
	mArrEffect.insert(pair<string, arrEffectsAlpha>(effectName, vEffectBuffer));

	//Ű ���� ���۸� ���� ���� ��Ż���Ϳ� �����
	_vTotalEffectsAlpha.push_back(mArrEffect);

}

/*
void effectManager::addPngEffect(string effectName, const char* imageName, const WCHAR* fileName, int imageWidth,
	int imageHeight, int effectWidth, int effectHeight, int fps, float elapsedTime, int buffer)
{
	pngImage* img;
	arrPngEffects vEffectBuffer; //����Ʈ ����
	arrPngEffect mArrEffect;	  //Ű ���� ����Ʈ ���� ����� ��

	//��ϵ� �̹����� �Ŵ����� �̹� ������
	if (IMAGEMANAGER->findPngImage(imageName))
	{
		img = IMAGEMANAGER->findPngImage(imageName);
	}
	else
	{
		img = IMAGEMANAGER->addPngImage(imageName, fileName,imageWidth, imageHeight);
	}

	//�� ���۰�����ŭ ���Ϳ� �����
	for (int i = 0; i < buffer; i++)
	{
		vEffectBuffer.push_back(new pngEffect);
		vEffectBuffer[i]->init(img, effectWidth, effectHeight, fps, elapsedTime);
	}

	//����Ʈ ���۸� �ʿ� �����
	mArrEffect.insert(pair<string, arrPngEffects>(effectName, vEffectBuffer));

	//Ű ���� ���۸� ���� ���� ��Ż���Ϳ� �����
	_vTotalPngEffects.push_back(mArrEffect);
	
}
*/
void effectManager::play(string effectName, int x, int y)
{
	iterTotalEffect vIter;
	iterEffect mIter;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIter = _vTotalEffects.begin(); vIter != _vTotalEffects.end(); ++vIter)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIter = vIter->begin(); mIter != vIter->end(); ++mIter)
		{
			//����Ʈ �̸��� ���ؼ� ���� ������ ���� ������ ~
			if (!(mIter->first == effectName)) break;

			//����Ʈ Ű�� ��ġ�ϸ� ����Ʈ�� �����Ų��
			iterEffects vArrIter;
			for (vArrIter = mIter->second.begin(); vArrIter != mIter->second.end(); ++vArrIter)
			{
				//����Ʈ ��Ʈ����
				//�̸� ����Ʈ�� Ȱ��ȭ �Ǿ������� ������ ��Ʈ����
				if ((*vArrIter)->getIsRunning()) continue;
				(*vArrIter)->startEffect(x, y);
				return;
			}
		}
	}

	
}
void effectManager::playAlpha(string effectName, int x, int y){
	iterTotalEffectAlpha vIterAlpha;
	iterEffectAlpha mIterAlpha;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIterAlpha = _vTotalEffectsAlpha.begin(); vIterAlpha != _vTotalEffectsAlpha.end(); ++vIterAlpha)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIterAlpha = vIterAlpha->begin(); mIterAlpha != vIterAlpha->end(); ++mIterAlpha)
		{
			//����Ʈ �̸��� ���ؼ� ���� ������ ���� ������ ~
			if (!(mIterAlpha->first == effectName)) break;

			//����Ʈ Ű�� ��ġ�ϸ� ����Ʈ�� �����Ų��
			iterEffectsAlpha vArrIter;
			for (vArrIter = mIterAlpha->second.begin(); vArrIter != mIterAlpha->second.end(); ++vArrIter)
			{
				//����Ʈ ��Ʈ����
				//�̸� ����Ʈ�� Ȱ��ȭ �Ǿ������� ������ ��Ʈ����
				if ((*vArrIter)->getIsRunning()) continue;
				(*vArrIter)->startEffect(x, y);
				return;
			}
		}
	}
}
	/*
	//png����
	iterTotalPngEffect vIterPng;
	iterPngEffect mIterPng;

	//����Ʈ�� ��� �־��� ���͸� �˻�
	for (vIterPng = _vTotalPngEffects.begin(); vIterPng != _vTotalPngEffects.end(); ++vIterPng)
	{
		//��Ż ����Ʈ ���� �ȿ� �ִ� ���� ����Ʈ Ű �˻�
		for (mIterPng = vIterPng->begin(); mIterPng != vIterPng->end(); ++mIterPng)
		{
			//����Ʈ �̸��� ���ؼ� ���� ������ ���� ������ ~
			if (!(mIterPng->first == effectName)) break;

			//����Ʈ Ű�� ��ġ�ϸ� ����Ʈ�� �����Ų��
			iterPngEffects vArrIter;
			for (vArrIter = mIterPng->second.begin(); vArrIter != mIterPng->second.end(); ++vArrIter)
			{
				//����Ʈ ��Ʈ����
				//�̸� ����Ʈ�� Ȱ��ȭ �Ǿ������� ������ ��Ʈ����
				if ((*vArrIter)->getIsRunning()) continue;
				(*vArrIter)->startEffect(x, y);
				return;
			}
		}
	}*/
//}
