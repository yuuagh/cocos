#include "InTextBox.h"
#include "GuiMgr.h"

const char* InTextBox::m_pszFileName = "InTextBox.json";

InTextBox::InTextBox() :
GameUILayer(m_pszFileName)
{
	
}

InTextBox::~InTextBox()
{


}

void InTextBox::close()
{
	GameUILayer::close();
}

bool InTextBox::init()
{
	if(!GameUILayer::init())
		return false;
	setAnchorPoint(CCPointZero);


	return true;
}

void InTextBox::touchEvent(CCObject* pSender, TouchEventType type)
{

}

void InTextBox::InitView()
{

}


InTextBox* InTextBox::AddFloatTipsView()
{
	InTextBox* pView = dynamic_cast<InTextBox*>(CreateGameUILayer());
	if(pView)
	{
		GuiMgr::singleton()->addChild(pView, ZORDER_TOP_2);
	}

	return pView;
}

