#include "GuiMgr.h"
#include "TitleUILayerView.h"

bool GuiMgr::OpenTitleUILayerView()
{
	UI_ADD_VIEW(TitleUILayerView);
	m_pTitleUILayerView->setZOrder(ZORDER_TOP);

	return true;
}

void GuiMgr::CloseTitleUILayerView()
{
	UI_DEL_VIEW(TitleUILayerView);

}