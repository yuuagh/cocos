#include "MainScene.h"
#include "GuiMgr.h"
#include "InTextBox.h"

USING_NS_CC;

CCScene* MainScene::scene()
{
    CCScene *scene = CCScene::create();
    GuiMgr *layer = GuiMgr::singleton();

	GuiMgr::singleton()->OpenHomePage();
	GuiMgr::singleton()->OpenTitleUILayerView();
//	InTextBox::AddFloatTipsView();

    scene->addChild(layer);

    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    return true;
}

