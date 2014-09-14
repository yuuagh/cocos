#include "FloatTipsView.h"
#include "ParserManager.h"
#include "GuiMgr.h"

const char* FloatTipsView::m_pszFileName = "FloatTipsView.json";

FloatTipsView::FloatTipsView() :
GameUILayer(m_pszFileName)
{
	m_fTimeLost = 2.0f;
	m_pImgBack = NULL;
	m_pInfo = NULL;
}

FloatTipsView::~FloatTipsView()
{


}

void FloatTipsView::close()
{
	GameUILayer::close();
}

bool FloatTipsView::init()
{
	if(!GameUILayer::init())
		return false;
	setAnchorPoint(CCPointZero);

	scheduleUpdate();

	m_pImgBack = dynamic_cast<UIImageView*>(GetWidgetByTag(TAG_FLOATTIPSVIEW_BACK));
	m_pInfo = dynamic_cast<UILabel*>(GetWidgetByTag(TAG_FLOATTIPSVIEW_INFO));

	return true;
}

void FloatTipsView::touchEvent(CCObject* pSender, TouchEventType type)
{

}

void FloatTipsView::InitView(const char* pStr)
{
	m_pInfo->setText(pStr);
	m_pImgBack->setSize(CCSizeMake(m_pInfo->getContentSize().width * 1.1f, m_pInfo->getContentSize().height * 1.1f));
}

void FloatTipsView::update(float delta)
{
	m_fTimeLost -= delta;
	if(m_fTimeLost <= 0)
	{
		unscheduleUpdate();
		removeFromParent();
	}
}

FloatTipsView* FloatTipsView::AddFloatTipsView(const char* pStr)
{
	FloatTipsView* pView = dynamic_cast<FloatTipsView*>(CreateGameUILayer());
	if(pView)
	{
		pView->InitView(pStr);
		GuiMgr::singleton()->addChild(pView, ZORDER_TOP_2);
	}

	return pView;
}

