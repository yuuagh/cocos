#include "MyScene.h"
//#include "ColorUtils.h"


bool MyScene::init()
{
	if(!CCNode::init())
	{
		return false;
	}
	

	// isClicked  = false;

	// CCSize size = CCDirector::sharedDirector()->getWinSize();

	// CCLabelTTF* ka = CCLabelTTF::create("this isaaaaa test", "Helvetica", 12);
	// ka->setAnchorPoint(ccp(0, 0));
	// ka->setPosition(ccp(0, 0));
	// this->addChild(ka);

	// gui::UIImageView* pView = gui::UIImageView::create();
	// pView->loadTexture("CloseNormal.png");
	// pView->setPosition(ccp(100, 150));
	// this->addChild(pView);

	// gui::UIImageView* pView2 = gui::UIImageView::create();
	// pView2->loadTexture("CloseNormal.png");
	// pView2->setPosition(ccp(100, 200));
	// this->addChild(pView2);
	// CCMoveTo* move = CCMoveTo::create(2.0f, ccp(200, 300));
	// pView2->runAction(move);


	// CCParticleSystem* up = CCParticleSystemQuad::create("Touch.plist");
	// up->setPosition(ccp(size.width / 2, size.height * 0.2));
	// addChild(up);

	// CCCallFunc* func = CCCallFunc::create(this, callfunc_selector(MyScene::CallBack));
	// move = CCMoveTo::create(1.0f, ccp(size.width / 2, size.height * 0.7));

	// up->runAction(CCSequence::create(move, CCHide::create(), NULL));


	// CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

	// CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	// CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	// CCSize glSize = CCEGLView::sharedOpenGLView()->getFrameSize();





// #if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	// JniMethodInfo info;
	// bool isHave = JniHelper::getStaticMethodInfo(info, "com/MyCompany/MyGame/backAd",  "function", "()Ljava/lang/String;");
	// if(isHave)
	// {
		// CCLOG("the function is exist");
		// jstring jstr = (jstring)info.env->CallStaticObjectMethod(info.classID, info.methodID);
		// std::string str = JniHelper::jstring2string(jstr);
		// CCLOG("return: \n%s", str.c_str());
	// }
	// else
	// {
		// CCLOG("the function is not exist");
	// }

// #endif






	return true;
}

void MyScene::CallBack()
{
	// addChild(m_pPar);
}

MyScene* MyScene::CreateMyNode()
{
	return MyScene::create();
}

bool MyScene::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	// CCLOG("touches begin");
	// if(isClicked)
	// {
		// CCLOG("double click");
		// isClicked = false;
	// }
	// else
	// {
		// isClicked = true;
		// scheduleOnce(schedule_selector(MyScene::JudgeCallback), 0.3f);
	// }
	

	// return true;
	return true;
}

void  MyScene::dataLoaded(float flt)
{

}

void MyScene::onEnter()
{



	// CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/bear.ExportJson");
	// CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/Cowboy.ExportJson");
	// CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfo("armature/knight.png", "armature/knight.plist", "armature/knight.xml");


	// CCSize size = CCDirector::sharedDirector()->getVisibleSize();
	// CCDirector::sharedDirector()->getVisibleSize();

	// CCTouchDispatcher* pDispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
	// pDispatcher->addTargetedDelegate(this, 0, true);


	// CCArmature *armature = CCArmature::create("bear");
	// armature->getAnimation()->playWithIndex(0);
	// armature->setPosition(ccp(size.width / 2, size.height / 2));
	// armature->setAnchorPoint(ccp(0, 0));
	// addChild(armature);

	// CCLOG("armature width:%.2f, height:%.2f", armature->getContentSize().width, armature->getContentSize().height);
	// CCLOG("anchorpoint x:%.2f, y: %.2f", armature->getAnchorPoint().x, armature->getAnchorPoint().y);

	// //CCArmatureDataManager::sharedArmatureDataManager()->addArmatureFileInfoAsync("armature/Cowboy.ExportJson", this, 
	// //	schedule_selector(MyScene::dataLoaded));


	// armature = NULL;
	// armature = cocos2d::extension::CCArmature::create("Cowboy");
	// armature->getAnimation()->playWithIndex(0);
	// armature->setScale(0.2f);
	// armature->setAnchorPoint(ccp(0, 0));
	// armature->setPosition(ccp(size.width * 0.2, size.height * 0.2));
	// addChild(armature);

	// ColorUtils::AddColorGray(armature);

	// armature = NULL;
	// armature = cocos2d::extension::CCArmature::create("Cowboy");
	// armature->getAnimation()->play("Fire");
	// armature->setScale(0.2f);
	// armature->setAnchorPoint(ccp(0, 0));
	// armature->setPosition(ccp(size.width * 0.4, size.height * 0.4));
	// addChild(armature);

	// CCArmature *armature2 = cocos2d::extension::CCArmature::create("Cowboy");
	// armature2->getAnimation()->play("Walk");
	// armature2->setScaleX(-0.2f);
	// armature2->setScaleY(0.2f);
	// armature2->setPosition(ccp(size.width * 0.4 - 20, size.height * 0.4 - 20));
	// addChild(armature2);


	// armature = NULL;
	// armature = cocos2d::extension::CCArmature::create("Knight_f/Knight");
	// armature->getAnimation()->playWithIndex(1);
	// armature->setAnchorPoint(ccp(0, 0));
	// armature->setPosition(ccp(size.width * 0.4, size.height * 0.2));
	// addChild(armature);

	CCNode::onEnter();
}

void MyScene::onExit()
{
	// CCTouchDispatcher* pDispatcher = CCDirector::sharedDirector()->getTouchDispatcher();
	// pDispatcher->removeDelegate(this);

	CCNode::onExit();

}

void MyScene::JudgeCallback(float delta)
{
	// if(isClicked)
	// {
		// isClicked = false;
		// CCLOG("single click");
	// }
}