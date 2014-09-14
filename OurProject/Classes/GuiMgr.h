/*
	2014-06-22 by yuding
*/
#ifndef __GUI_MGR_H__
#define __GUI_MGR_H__

#include "Common.h"
#include  <vector>

USING_NS_CC;
USING_NS_CC_EXT;


// The GuiMgr create UI's function easyily.
class GameUILayer;
class HomePage;
class TitleUILayerView;

#define ZORDER_TOP 100
#define ZORDER_TOP_2 200

#define GUI_SIMPLE_CREATE_FUNC_OPEN_AND_CLOSE(UICLASS) \
public: \
	bool Open##UICLASS(); \
	void Close##UICLASS();

class GuiMgr: public Layer
{
	typedef cocos2d::Layer Super;

public:
	GuiMgr();
	virtual ~GuiMgr();
	virtual void update(float seconds);

	virtual void onEnter();
	virtual void onExit();
	static GuiMgr* singleton(void);

	void   AddUI(GameUILayer *pUI)  { m_vecUIOpend.push_back(pUI); };
	GameUILayer* GetBackUI()     { return m_vecUIOpend.size() > 0 ? m_vecUIOpend[m_vecUIOpend.size() - 1] : NULL; };
	void   PopUI()      { m_vecUIOpend.pop_back(); }
	bool   UIOpendListEmpty()   { return m_vecUIOpend.empty(); }
	void   OnBackClicked();

	void ClearGuiWhenEnterScene();
	void OpenGuiWhenExitScene();

	void OnBackLaunchFrame();

	void ReLoadTitleUI(bool fShowHead);
	CC_SYNTHESIZE_PASS_BY_REF(bool, m_fTourister,           IsTourister);                   
	CC_SYNTHESIZE_PASS_BY_REF(bool, m_fEnterGameWorld,      IsEnterGameWorld);              

	Size      m_oWinsize;

	void onClearMemory();

	// new ui
	//CC_SYNTHESIZE(PlayerInfoView*, m_pPlayerInfoView, PlayerInfoView);
	CC_SYNTHESIZE(HomePage*, m_pHomePage, HomePage);
	CC_SYNTHESIZE(TitleUILayerView*, m_pTitleUILayerView, TitleUILayerView);

	//------------------------------------------------------------
	//  new ui
private:
	GUI_SIMPLE_CREATE_FUNC_OPEN_AND_CLOSE(HomePage);
	//GUI_SIMPLE_CREATE_FUNC_OPEN_AND_CLOSE(TitleUILayerView);
	std::vector<GameUILayer*> m_vecUIOpend;
};

#define WIN_WIDTH ((_UINT32)(GuiMgr::singleton()->m_oWinsize.width))
#define WIN_HEIGHT ((_UINT32)(GuiMgr::singleton()->m_oWinsize.height))

//#define FIGHTSCENEVIEW GuiMgr::singleton()->getFightSceneView()
#endif