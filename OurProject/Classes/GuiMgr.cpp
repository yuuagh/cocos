//
//  GuiMgr.cpp
//  Client

#include "GuiMgr.h"
#include "cocos2d.h"
#include "GameUILayer.h"

static GuiMgr* s_SharedGuiMgr = NULL;

GuiMgr* GuiMgr::singleton(void)
{
	if (!s_SharedGuiMgr)
	{
		s_SharedGuiMgr = new GuiMgr();
		//s_SharedGuiMgr->init();
	}

	return s_SharedGuiMgr;
}

GuiMgr::GuiMgr() : 
m_pHomePage(NULL)
, m_pTitleUILayerView(NULL)
{   
	this->setAnchorPoint(CCPointZero);
	m_oWinsize =  CCDirector::sharedDirector()->getWinSize();
	CCSize size = CCDirector::sharedDirector()->getVisibleSize();

	m_vecUIOpend.clear();
}

GuiMgr::~GuiMgr()
{
}

void GuiMgr::onEnter()
{
	/*GameListener *l = (GameListener*)this;
	GameController::singleton()->addBackMainFrameObserver( l );*/
	Super::onEnter();
	//    addRollMsgLayer();
	//this->scheduleUpdate();
}
void GuiMgr::onExit()
{
	/*GameListener *l = (GameListener*)this;
	GameController::singleton()->removeBackMainFrameObserver( l );*/
	//this->unscheduleUpdate();
	Super::onExit();
}

void GuiMgr::OnBackClicked()
{
	GameUILayer *pUI = GetBackUI();
	if (pUI == NULL)
	{
	//	TITLEUI_HEADBUTTON_EXCHANGE(true);
		return;
	}

	bool fPop = true;
	switch (pUI->getUIType())
	{

	case 1:
		break;
	
	default:
		{
			fPop = false;
		}
		break;
	}

	if (fPop)
	{
		GuiMgr::singleton()->PopUI();
	}

	if (UIOpendListEmpty())
	{
		/*TITLEUI_HEADBUTTON_EXCHANGE(true);
		if (TITLEVIEW)
		{
			TITLEVIEW->ShowRightBar(true);
			TITLEVIEW->SetFocusVisible();

		}*/
	}
}


void GuiMgr::update(float seconds)
{
	/*
	GameController::singleton()->AnalysisPackData();
	CCExtension::singleton()->handleMsg();
*/
	/*if (m_pFightSceneView)
	{
		m_pFightSceneView->update(seconds);
	}*/
	if(m_fTourister)
	{
		/*if(GuiMgr::singleton()->getIsEnterGameWorld())
		{
		}*/
	}

	/*if(GuiMgr::singleton()->getIsEnterGameWorld())
	{
	}*/
}


void GuiMgr::OnBackLaunchFrame()
{
	//TimeLostView::CloseTimeLostLayer();
//
//#if defined OLD_NETWORK
//	SocketMgr::singleton()->disConnectGame();
//	SocketMgr::singleton()->setConnectState( Con_Unknow );
//#elif defined NEW_NETWORK
//	NetManager::singleton()->DisconnectGameServer();
//#else
//#error undefined Network!
//#endif
//
//	Account::singleton()->SetLoginModeType(Account::LOGIN_MODE_NORMAL);
//
//	//ParserManager::singleton()->Release();
//	GameView::singleton()->OnEnterGameView(false);
//
//	Player::singleton()->Release();
//	GuiMgr::singleton()->setIsEnterGameWorld(false);
//
//	GameView::singleton()->removeChild(GuiMgr::singleton(),true);
//	GuiMgr::singleton()->cleanupSingleton();
//	CCDirector::sharedDirector()->getScheduler()->setTimeScale( g_fSpeedOne );
}

void GuiMgr::onClearMemory()
{
	return;
	cocos2d::SpriteFrameCache::sharedSpriteFrameCache()->removeUnusedSpriteFrames();
	cocos2d::TextureCache::sharedTextureCache()->removeUnusedTextures();
}

//
//bool GuiMgr::OpenHomePageView()
//{
//	UI_ADD_VIEW(HomePageView);
//
//	return true;
//}
//
//void GuiMgr::CloseHomePageView()
//{
//	UI_DEL_VIEW(HomePageView);
//}
//
//void GuiMgr::BuyTokenQuickly()
//{
//	PromptMoneyFetchingUIOpening(MONEY_TYPE_DIAMOND);
//}
