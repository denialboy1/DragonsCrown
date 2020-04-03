 #pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class effect;
//class pngEffect;
class effectAlpha;

class effectManager : public singletonBase<effectManager>
{
private:
	typedef vector<effect*> arrEffects;
	typedef vector<effect*>::iterator iterEffects;

	typedef map<string, arrEffects> arrEffect;
	typedef map<string, arrEffects>::iterator iterEffect;

	typedef vector<map<string, arrEffects>> arrTotalEffect;
	typedef vector<map<string, arrEffects>>::iterator iterTotalEffect;

	typedef vector<effectAlpha*> arrEffectsAlpha;
	typedef vector<effectAlpha*>::iterator iterEffectsAlpha;

	typedef map<string, arrEffectsAlpha> arrEffectAlpha;
	typedef map<string, arrEffectsAlpha>::iterator iterEffectAlpha;

	typedef vector<map<string, arrEffectsAlpha>> arrTotalEffectAlpha;
	typedef vector<map<string, arrEffectsAlpha>>::iterator iterTotalEffectAlpha;

	/*
	typedef vector<pngEffect*> arrPngEffects;
	typedef vector<pngEffect*>::iterator iterPngEffects;

	typedef map<string, arrPngEffects> arrPngEffect;
	typedef map<string, arrPngEffects>::iterator iterPngEffect;

	typedef vector<map<string, arrPngEffects>> arrTotalPngEffect;
	typedef vector<map<string, arrPngEffects>>::iterator iterTotalPngEffect;
	*/

private:
	arrTotalEffect _vTotalEffects;
	arrTotalEffectAlpha _vTotalEffectsAlpha;
//	arrTotalPngEffect _vTotalPngEffects;
public:
	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void addEffect(string effectName, const char* imageName, int imageWidth,
		int imageHeight, int effectWidth, int effectHeight, int fps, float elapsedTime, int buffer);

	void addEffect(string effectName, const char* imageName, int imageWidth,
		int imageHeight, int effectWidth, int effectHeight, int fps, float elapsedTime, int buffer,int alpha);
	
//	void addPngEffect(string effectName, const char* imageName,const WCHAR* fileName, int imageWidth,
//		int imageHeight, int effectWidth, int effectHeight, int fps, float elapsedTime, int buffer);

	void play(string effectName, int x, int y);
	void playAlpha(string effectName, int x, int y);


	effectManager();
	~effectManager();
};

