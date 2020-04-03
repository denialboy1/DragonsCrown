#pragma once
#include "singletonBase.h"
#include <vector>

//������ ����ü
struct tagIniData
{
	const char* subject;	//�׸�
	string title;		//�׸�ȿ� ������
	string value;		//�������� ��
};

class iniDataManager : public singletonBase<iniDataManager>
{
private:
	typedef vector<tagIniData> arrIniData;
	typedef vector<tagIniData>::iterator arrIniDataIter;

	typedef vector<arrIniData> arrIniDatas;
	typedef vector<arrIniData>::iterator arrIniDatasIter;


private:
	arrIniData _vIniData;

public:
	HRESULT init();
	void release();

	//save function
	void addData(const char* subject, const char* title, const char* value);
	void iniSave(char* fileName);

	//�б� �Լ�
	string loadDataString(const char* fileName, const char* subject, const char* title);

	// ������ �ҷ����� �Ծ�
	int loadDataInterger(const char* fileName, const char* subject, const char* title);

	iniDataManager();
	~iniDataManager();
};

