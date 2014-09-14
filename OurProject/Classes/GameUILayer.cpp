#include "GameUILayer.h"
#include "GuiMgr.h"

GameUILayer::GameUILayer(const std::string strFileName)
:m_strFileName(strFileName),
m_pRootNode(NULL),
m_pRootPanel(NULL),
m_enUIType(UI_NULL),
//m_pBack(NULL),
m_openStyle(OPEN_STYLE_POPUP),
m_closeStyle(CLOSE_STYLE_NO_STYLE)
{
	
}

GameUILayer::~GameUILayer()
{
}

bool GameUILayer::init()
{

	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	if (!Layer::init())
	{
		return false;
	}
	this->setAnchorPoint(Point(0, 0));

	m_pRootNode = static_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile(m_strFileName.c_str()));
//	m_pRootNode->setSize(visibleSize);
//	CCLOG("%d", m_pRootNode->getChildrenCount());
	if (NULL == m_pRootNode)
	{
		return false;
	}

	addChild(m_pRootNode);

	/*m_pRootPanel = static_cast<Layout*>(m_pRootNode->getChildByName("root_Panel"));
	if (NULL == m_pRootPanel)
	{
		return false;
	}

	setContentSize(m_pRootNode->getContentSize());*/
	Register(m_pRootNode);
	return true;
}


void GameUILayer::Register(Widget* root)
{
	if (!root)
	{
		return;
	}
	
	auto arrayRootChildren = root->getChildren();

	if (root->isTouchEnabled())
	{
		root->addTouchEventListener(this, toucheventselector(GameUILayer::touchEvent));
	}

	int length = arrayRootChildren.capacity();
	for (int i = 0; i < length; i++)
	{
		Widget* child = static_cast<Widget*>(arrayRootChildren.at(i));
		if (!child)
		{
			continue;
		}

		if (child->getTag() != -1)
		{
			m_MapWidget.insert(std::make_pair(child->getTag(), child));
		}

		if (child->isTouchEnabled())
		{
			child->addTouchEventListener(this, toucheventselector(GameUILayer::touchEvent));
		}

		Register(child);
	}
}

Widget* GameUILayer::GetWidgetByTag(int nTag)
{
	Widget *pWidget = NULL;
	MAP_WIDGET_ITER iter = m_MapWidget.find(nTag);
	if (iter != m_MapWidget.end())
	{
		pWidget = iter->second;

	}

	return pWidget;
}
//
//void GameUILayer::CloseUI(bool bRemoveFromParent /*= true*/)
//{
//	m_bRemoveFromParentOnClose = bRemoveFromParent;
//	if (CLOSE_STYLE_NO_STYLE != m_closeStyle)
//		EnableCloseStyle();
//	else
//		OnClosed();
//}

//void GameUILayer::CenterToParent(CCSize parentSize /*= CCSize(0, 0)*/)
//{
//	CCNode *pParent = this->getParent();
//	CCAssert(pParent, "");
//
//	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
//
//	// 计算父节点 anchor 到中心点的偏移
//	CCSize contentSize = pParent->getContentSize();
//	if (contentSize.equals(CCSize(0, 0)))
//		contentSize = parentSize;
//
//	CCPoint parentAnchor = pParent->getAnchorPoint();
//	CCSize parentAnchorToCenter
//		= !contentSize.equals( CCSize(0,0)) 
//		? CCSize(contentSize.width / 2, contentSize.height / 2) - CCSize(contentSize.width * parentAnchor.x, contentSize.height * parentAnchor.y)
//		: CCSize(visibleSize.width / 2, visibleSize.height / 2);
//
//	// 因为 root_Panel 的 anchor 是(0,0)，所以自己中心点到 anchor 的偏移计算如下
//	contentSize = this->getContentSize();
//	CCSize centerToAnchor( -contentSize.width/2, -contentSize.height/2);
//
//	// 设置自己的位置使自己位于父节点的中心
//	setPosition(centerToAnchor + parentAnchorToCenter);
//}

void GameUILayer::SetEnable(bool b /*= true*/) // 不可用的时候不可见也不处理消息
{
	Layer::setVisible(b);
	Layer::setTouchEnabled(b);

}

void GameUILayer::onEnter()
{
	Layer::onEnter();
	/*if (OPEN_STYLE_NO_STYLE != m_openStyle)
		EnableOpenStyle();*/
}

void GameUILayer::SetUIType(eUITYPE enUIType)
{
	setUIType(enUIType);

	switch (enUIType)
	{
	case 1:
		{/*
			if (enUIType != UI_TEAMINFO &&enUIType!=UI_FIGHTINFO)
			{
				GuiMgr::singleton()->AddUI(this);
			}
			m_pBack = gui::ImageView::create();
			m_pBack->loadTexture("bg_fullscr_common.png");
			CCPoint pt(m_pBack->getContentSize().width / 2, m_pBack->getContentSize().height/2);
			m_pBack->setPosition(pt);
			addChild(m_pBack);
			m_pBack->setZOrder(Z_ORDER_HIDDEN - 1);*/
		}
		break;
	default:
		break;
	}
}

void GameUILayer::close()
{
	/*GuiMgr::singleton()->OnBackClicked();*/
}

//void GameUILayer::EnableOpenStyle(bool b /*= true*/)
//{
//	ClearStyleAct();
//	if (b)
//	{
//		switch (m_openStyle)
//		{
//		case OPEN_STYLE_POPUP: ShowPopup(); break;
//		case OPEN_STYLE_MOVE_UP: ShowMove(DIRECTION_UP); break;
//		case OPEN_STYLE_MOVE_RIGHT: ShowMove(DIRECTION_RIGHT); break;
//		case OPEN_STYLE_MOVE_DOWN: ShowMove(DIRECTION_DOWN); break;
//		case OPEN_STYLE_MOVE_LEFT: ShowMove(DIRECTION_LEFT); break;
//		case OPEN_STYLE_MOVE_BACK_UP: ShowMoveBack(DIRECTION_UP); break;
//		case OPEN_STYLE_MOVE_BACK_RIGHT: ShowMoveBack(DIRECTION_RIGHT); break;
//		case OPEN_STYLE_MOVE_BACK_DOWN: ShowMoveBack(DIRECTION_DOWN); break;
//		case OPEN_STYLE_MOVE_BACK_LEFT: ShowMoveBack(DIRECTION_LEFT); break;
//
//		default:
//			break;
//		}
//	}
//}
//
//void GameUILayer::EnableCloseStyle(bool b /*= true*/)
//{
//	ClearStyleAct();
//	if (b)
//	{
//		switch (m_closeStyle)
//		{
//		case HIDE_POPOUT: HidePopout(); break;
//		case HIDE_MOVE_DOWN: HideMove(DIRECTION_DOWN); break;
//		case HIDE_MOVE_LEFT: HideMove(DIRECTION_LEFT); break;
//		case HIDE_MOVE_UP: HideMove(DIRECTION_UP); break;
//		case HIDE_MOVE_RIGHT: HideMove(DIRECTION_RIGHT); break;
//		case HIDE_MOVE_BACK_DOWN: HideMoveBack(DIRECTION_DOWN); break;
//		case HIDE_MOVE_BACK_LEFT: HideMoveBack(DIRECTION_LEFT); break;
//		case HIDE_MOVE_BACK_UP: HideMoveBack(DIRECTION_UP); break;
//		case HIDE_MOVE_BACK_RIGHT: HideMoveBack(DIRECTION_RIGHT); break;
//
//		default:
//			break;
//		}
//	}
//}

//void GameUILayer::ShowPopup()
//{
//	CCScaleTo *scaleTo = CCScaleTo::create(UI_ANIM_DURATION, 1.f);
//	CCActionInterval *ease = CCEaseBackOut::create(scaleTo);
//	CCDelayTime *delay = CCDelayTime::create(UI_ANIM_DURATION);
//	CCCallFunc *call = CCCallFunc::create(this, callfunc_selector(GameUILayer::OnOpen));
//	CCSequence *seq = CCSequence::createWithTwoActions(delay, call);
//
//	scaleTo->setTarget(this);
//	this->setScale(0.01f);
//	this->runAction(ease);
//	this->runAction(seq);
//	m_listStyleAct.push_back(ease);
//	m_listStyleAct.push_back(seq);
//}

//void GameUILayer::HidePopout()
//{
//	CCScaleTo *scaleTo = CCScaleTo::create(UI_ANIM_DURATION, 0.01f);
//	CCActionInterval *ease = CCEaseBackIn::create(scaleTo);
//	CCDelayTime *delay = CCDelayTime::create(UI_ANIM_DURATION);
//	CCCallFunc *call = CCCallFunc::create(this, callfunc_selector(GameUILayer::OnClosed));
//	CCSequence *seq = CCSequence::createWithTwoActions(delay, call);
//
//	scaleTo->setTarget(this);
//	this->setScale(1.f);
//	this->runAction(ease);
//	this->runAction(seq);
//	m_listStyleAct.push_back(ease);
//	m_listStyleAct.push_back(seq);
//}

//void GameUILayer::ShowMove(EDirection dir)
//{
//	CCPoint offset = ccpMult(SYOffsetByDirection(dir), 200.f);
//	if (dir == DIRECTION_LEFT || dir == DIRECTION_RIGHT)
//	{
//		offset = ccpMult(offset, 1.5f);
//	}
//	CCActionInterval *move = CCMoveBy::create(UI_ANIM_DURATION, offset);
//	CCActionInterval *ease = CCEaseExponentialOut::create(move);
//	CCDelayTime *delay = CCDelayTime::create(UI_ANIM_DURATION);
//	CCCallFunc *call = CCCallFunc::create(this, callfunc_selector(GameUILayer::OnOpen));
//	CCSequence *seq = CCSequence::createWithTwoActions(delay, call);
//
//	offset.x = -offset.x;
//	offset.y = -offset.y;
//	CCPoint pos = ccpAdd(this->getPosition(), offset);
//
//	this->setPosition(pos);
//	move->setTarget(this);
//	this->runAction(ease);
//	this->runAction(seq);
//	m_listStyleAct.push_back(ease);
//	m_listStyleAct.push_back(seq);
//}

//void GameUILayer::HideMove(EDirection dir)
//{
//	CCPoint offset = ccpMult(SYOffsetByDirection(dir), 320.f);
//	if (dir == DIRECTION_LEFT || dir == DIRECTION_RIGHT)
//	{
//		offset = ccpMult(offset, 1.5f);
//	}
//	CCActionInterval *move = CCMoveBy::create(UI_ANIM_DURATION, offset);
//	CCActionInterval *ease = CCEaseExponentialOut::create(move);
//	CCDelayTime *delay = CCDelayTime::create(UI_ANIM_DURATION);
//	CCCallFunc *call = CCCallFunc::create(this, callfunc_selector(GameUILayer::OnClosed));
//	CCSequence *seq = CCSequence::createWithTwoActions(delay, call);
//
//	//targetPos = target->getPosition();
//	move->setTarget(this);
//	this->runAction(ease);
//	this->runAction(seq);
//	m_listStyleAct.push_back(ease);
//	m_listStyleAct.push_back(seq);
//}
//
//void GameUILayer::ShowMoveBack(EDirection dir)
//{
//	CCPoint offset = ccpMult(SYOffsetByDirection(dir), 160.f);
//	if (dir == DIRECTION_LEFT || dir == DIRECTION_RIGHT)
//	{
//		offset = ccpMult(offset, 1.5f);
//	}
//	CCActionInterval *move = CCMoveBy::create(UI_ANIM_DURATION, offset);
//	CCActionInterval *ease = CCEaseBackOut::create(move);
//	CCDelayTime *delay = CCDelayTime::create(UI_ANIM_DURATION);
//	CCCallFunc *call = CCCallFunc::create(this, callfunc_selector(GameUILayer::OnOpen));
//	CCSequence *seq = CCSequence::createWithTwoActions(delay, call);
//
//	offset.x = -offset.x;
//	offset.y = -offset.y;
//	CCPoint pos = ccpAdd(this->getPosition(), offset);
//
//	this->setPosition(pos);
//	move->setTarget(this);
//	this->runAction(ease);
//	this->runAction(seq);
//	m_listStyleAct.push_back(ease);
//	m_listStyleAct.push_back(seq);
//}
//
//void GameUILayer::HideMoveBack(EDirection dir)
//{
//	CCPoint offset = ccpMult(SYOffsetByDirection(dir), 240.f);
//	if (dir == DIRECTION_LEFT || dir == DIRECTION_RIGHT)
//	{
//		offset = ccpMult(offset, 1.5f);
//	}
//	CCActionInterval *move = CCMoveBy::create(UI_ANIM_DURATION, offset);
//	CCActionInterval *ease = CCEaseBackIn::create(move);
//	CCDelayTime *delay = CCDelayTime::create(UI_ANIM_DURATION);
//	CCCallFunc *call = CCCallFunc::create(this, callfunc_selector(GameUILayer::OnClosed));
//	CCSequence *seq = CCSequence::createWithTwoActions(delay, call);
//
//	//targetPos = target->getPosition();
//	move->setTarget(this);
//	this->runAction(ease);
//	this->runAction(seq);
//	m_listStyleAct.push_back(ease);
//	m_listStyleAct.push_back(seq);
//}
//
//void GameUILayer::ClearStyleAct()
//{
//	if (m_listStyleAct.empty())
//		return;
//
//	LIST_STYLE_ACT::iterator iter = m_listStyleAct.begin();
//	while (iter != m_listStyleAct.end())
//	{
//		stopAction(*iter);
//		++iter;
//	}
//
//	m_listStyleAct.clear();
//}
//
//void GameUILayer::OnOpen()
//{
//	m_listStyleAct.clear();
//}
//
//void GameUILayer::OnClosed()
//{
//	m_listStyleAct.clear();
//	if (m_bRemoveFromParentOnClose)
//	{
//		removeFromParent();
//	}
//	else
//	{
//		setVisible(false);
//		setTouchEnabled(false);
//	}
//}

