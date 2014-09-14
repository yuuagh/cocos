#include "GuiMgr.h"
#include "HomePage.h"

bool GuiMgr::OpenHomePage()
{
	if (NULL != m_pHomePage)
		return false;

	m_pHomePage = (HomePage*)HomePage::CreateGameUILayer();
	if (NULL == m_pHomePage)
		return false;

	addChild(m_pHomePage);

	return true;
}

void GuiMgr::CloseHomePage()
{
	UI_DEL_VIEW(HomePage);

}