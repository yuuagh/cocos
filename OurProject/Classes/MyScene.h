#ifndef __MY_SCENE_H__
#define __MY_SCENE_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "../android/jni/JniHelper.h"
#include "jni.h"

USING_NS_CC;
USING_NS_CC_EXT;

class MyScene : public CCNode, public CCTouchDelegate
{
public:

	virtual bool init(); 
	static MyScene* CreateMyNode();
	void CallBack();
	// implement the "static node()" method manually
	CREATE_FUNC(MyScene);
	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);

	virtual void onEnter();
	virtual void onExit();
	

	void dataLoaded(float flt);
	void JudgeCallback(float delta);
private:
	CCParticleSystem* m_pPar;
	bool isClicked;

};


#endif
