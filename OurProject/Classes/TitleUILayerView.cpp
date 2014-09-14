#include "TitleUILayerView.h"
#include "ParserManager.h"
#include "FloatTipsView.h"

const char* TitleUILayerView::m_pszFileName = "TitleUILayerView.json";

TitleUILayerView::TitleUILayerView() :
GameUILayer(m_pszFileName)

{

}

TitleUILayerView::~TitleUILayerView()
{


}

void TitleUILayerView::close()
{
	GameUILayer::close();
}

bool TitleUILayerView::init()
{
	if(!GameUILayer::init())
		return false;
	setAnchorPoint(CCPointZero);

	return true;
}

void TitleUILayerView::touchEvent(CCObject* pSender, TouchEventType type)
{
	if(TOUCH_EVENT_ENDED != type)
	{
		return;
	}
	
	FloatTipsView::AddFloatTipsView("The Function Is Not Open!");
	
	
}

void TitleUILayerView::InitView()
{

}
