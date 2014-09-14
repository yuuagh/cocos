#ifndef __GAME_UILAYER_H__
#define __GAME_UILAYER_H__

#include "Common.h"

#if (CC_TARGET_PLATFORM==CC_PLATFORM_IOS)
#include "UIWidget.h"
#include "UILabel.h"
#include "UIImageView.h"
#include "UIScrollView.h"
#include "UIButton.h"
#endif

#include <map>
#include <list>
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;
using namespace cocostudio;

typedef enum eUI_OPEN_STYLE
{
	OPEN_STYLE_NO_STYLE = 0,
	OPEN_STYLE_POPUP,
	OPEN_STYLE_MOVE_UP,
	OPEN_STYLE_MOVE_RIGHT,
	OPEN_STYLE_MOVE_DOWN,
	OPEN_STYLE_MOVE_LEFT,
	OPEN_STYLE_MOVE_BACK_UP,
	OPEN_STYLE_MOVE_BACK_RIGHT,
	OPEN_STYLE_MOVE_BACK_DOWN,
	OPEN_STYLE_MOVE_BACK_LEFT,

} UI_OPEN_STYLE;

typedef enum eUI_CLOSE_STYLE
{
	CLOSE_STYLE_NO_STYLE = 0,
	CLOSE_STYLE_POPOUT,
	CLOSE_STYLE_MOVE_DOWN,
	CLOSE_STYLE_MOVE_LEFT,
	CLOSE_STYLE_MOVE_UP,
	CLOSE_STYLE_MOVE_RIGHT,
	CLOSE_STYLE_MOVE_BACK_DOWN,
	CLOSE_STYLE_MOVE_BACK_LEFT,
	CLOSE_STYLE_MOVE_BACK_UP,
	CLOSE_STYLE_MOVE_BACK_RIGHT,

} UI_CLOSE_STYLE;


enum eUITYPE
{
	UI_NULL,
	UI_TITLEUILAYER,

};

#define UI_ADD_CLASS_NAME(UICLASS) m_p##UICLASS

#define UI_ADD_VIEW(UICLASS) if(NULL != UI_ADD_CLASS_NAME(UICLASS)) \
{ \
	return false; \
	} \
	UI_ADD_CLASS_NAME(UICLASS) = (UICLASS*)UICLASS::CreateGameUILayer(); \
	if (NULL == UI_ADD_CLASS_NAME(UICLASS)) \
{ \
	return false; \
	} \
	addChild(UI_ADD_CLASS_NAME(UICLASS));

//
#define UI_ADD_VIEW_NAME(UICLASS, UITYPE, JSONNAME) if(NULL != UI_ADD_CLASS_NAME(UICLASS)) \
{ \
	return false; \
	} \
	UI_ADD_CLASS_NAME(UICLASS) = (UICLASS*)UICLASS::CreateGameUILayer(JSONNAME, UITYPE); \
	if (NULL == UI_ADD_CLASS_NAME(UICLASS)) \
{ \
	return false; \
	} \
	addChild(UI_ADD_CLASS_NAME(UICLASS));

//
#define UI_DEL_VIEW(UICLASS) if(NULL != UI_ADD_CLASS_NAME(UICLASS)) \
{\
	removeChild(UI_ADD_CLASS_NAME(UICLASS)); \
	UI_ADD_CLASS_NAME(UICLASS) = NULL; \
	}

#define UI_CREATE_FUNC(GameUILayerType,UITYPE,OPENSTYLE,CLOSESTYLE) \
public: \
	static GameUILayer* CreateGameUILayer() \
{ \
	GameUILayer* pGameUILayer = (GameUILayer*)new GameUILayerType(); \
	if (pGameUILayer && pGameUILayer->init()) \
{ \
	pGameUILayer->SetUIType((eUITYPE)UITYPE); \
	pGameUILayer->setOpenStyle(OPENSTYLE); \
	pGameUILayer->setCloseStyle(CLOSESTYLE); \
	pGameUILayer->autorelease(); \
	} \
 else \
{ \
	CC_SAFE_DELETE(pGameUILayer); \
	} \
	return pGameUILayer; \
	}

//#define UI_LOADING_JSON(UI_CLASS, UI_JSON_PATH) const char* UI_CLASS::m_pszFileName = "UI_JSON_PATH";

#define UI_CREATE_FUNC_NAME(GameUILayerType,UITYPE,JsonName,OPENSTYLE,CLOSESTYLE) \
public: \
	static GameUILayer* CreateGameUILayer(std::string JsonName, eUITYPE UITYPE) \
{ \
	GameUILayer* pGameUILayer = (GameUILayer*)new GameUILayerType(); \
	if (pGameUILayer)\
{\
	pGameUILayer->setFileName(JsonName); \
	}\
	if (pGameUILayer && pGameUILayer->init()) \
{ \
	pGameUILayer->SetUIType(UITYPE); \
	pGameUILayer->setOpenStyle(OPENSTYLE); \
	pGameUILayer->setCloseStyle(CLOSESTYLE); \
	pGameUILayer->autorelease(); \
	} \
 else \
{ \
	CC_SAFE_DELETE(pGameUILayer); \
	} \
	return pGameUILayer; \
	}

#define UI_SIMPLE_CREATE_CLASS_STYLE(UICLASS,UITYPE,OPENSTYLE,CLOSESTYLE) \
private: \
	static const char* m_pszFileName; \
public: \
	bool init(); \
	UICLASS(); \
	UI_CREATE_FUNC(UICLASS, UITYPE, OPENSTYLE, CLOSESTYLE); \
	~UICLASS(); \
	void touchEvent(Ref* pSender, TouchEventType type); \
	void close(); \


#define UI_SIMPLE_CREATE_CLASS_NAME_STYLE(UICLASS,JSONNAME,UITYPE,OPENSTYLE,CLOSESTYLE) \
private: \
	static const char* m_pszFileName; \
public: \
	bool init(); \
	UICLASS(); \
	UI_CREATE_FUNC_NAME(UICLASS, UITYPE, JSONNAME, OPENSTYLE, CLOSESTYLE); \
	~UICLASS(); \
	void touchEvent(Ref* pSender, TouchEventType type); \
	void close(); \

#define UI_SIMPLE_CREATE_CLASS(UICLASS,UITYPE) UI_SIMPLE_CREATE_CLASS_STYLE(UICLASS,UITYPE,OPEN_STYLE_NO_STYLE,CLOSE_STYLE_NO_STYLE)
#define UI_SIMPLE_CREATE_CLASS_NAME(UICLASS,JSONNAME,UITYPE) UI_SIMPLE_CREATE_CLASS_NAME_STYLE(UICLASS,JSONNAME,UITYPE,OPEN_STYLE_NO_STYLE,CLOSE_STYLE_NO_STYLE)




class GameUILayer :
	public cocos2d::Layer
{
	typedef std::map<int, Widget*> MAP_WIDGET;
	typedef MAP_WIDGET::iterator      MAP_WIDGET_ITER;
	typedef std::list<CCAction*> LIST_STYLE_ACT;

public:
	explicit GameUILayer(const std::string strFileName);
	virtual ~GameUILayer();

	virtual bool init();
	virtual void touchEvent(Ref* pSender, cocos2d::ui::TouchEventType type){};
	virtual void    close();
	virtual void onEnter(); // CCNode::onEnter

	void   SetUIType(eUITYPE enUIType);
	void   Register(Widget* root);
	Widget*   GetWidgetByTag(int nTag);
	void   CloseUI(bool bRemoveFromParent=true);
	void   CenterToParent(Size parentSize = Size(0, 0));
	void   SetEnable(bool b=true); // 不可用的时候不可见也不处理消息
	
protected:
	void   EnableOpenStyle(bool b=true);
	void   EnableCloseStyle(bool b=true);
	void   ShowPopup();
	void   HidePopout();
//	void   ShowMove(EDirection dir);
//	void   HideMove(EDirection dir);
//	void   ShowMoveBack(EDirection dir);
//	void   HideMoveBack(EDirection dir);
	void   ClearStyleAct();

	//virtual   void OnOpen();  // 以某种风格显示完成
	//virtual   void OnClosed(); // 以某种风格关闭完成

protected:

	CC_SYNTHESIZE(std::string, m_strFileName, FileName);
	CC_SYNTHESIZE(eUITYPE,  m_enUIType,  UIType);
	CC_SYNTHESIZE(Layout*,  m_pRootPanel, RootPanel);
	CC_SYNTHESIZE(_UINT8, m_openStyle, OpenStyle);
	CC_SYNTHESIZE(_UINT8, m_closeStyle, CloseStyle);

//	GUI_VAR_CCS(gui::UIImageView, m_pBack, Back, TAG_TITLEUI_BACK);
protected:

	Layout*   m_pRootNode;

	MAP_WIDGET  m_MapWidget;
	LIST_STYLE_ACT m_listStyleAct;
	bool   m_bRemoveFromParentOnClose;
};

#endif // __GAME_UILAYER_H__

