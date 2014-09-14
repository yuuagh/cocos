#include "HomePage.h"
#include "ParserManager.h"

const char* HomePage::m_pszFileName = "HomePage.json";

HomePage::HomePage() :
GameUILayer(m_pszFileName)
{
	
}

HomePage::~HomePage()
{


}

void HomePage::close()
{
	GameUILayer::close();
}

bool HomePage::init()
{
	if(!GameUILayer::init())
		return false;
	setAnchorPoint(Point(0, 0));


	//_UINT32 unNum = ParserManager::singleton()->Get_RES_WEEK_DOING_Size();
	//if(unNum != 0)
	//{
	//	for(_UINT32 i = 0; i < unNum; ++i)
	//	{
	//		const RES_WEEK_DOING* resWeek = ParserManager::singleton()->Get_RES_WEEK_DOING_DataByIndex(i);
	//		UILabel* bat = UILabel::create();
	//		bat->setAnchorPoint(CCPointZero);
	//		char dst[256];
	//		sprintf(dst, "%s", (char*)resWeek->m_szTeacher);
	//		bat->setText(dst);
	//		bat->setPosition(ccp(200 + i * 20, 300 + i * 20));
	//		bat->setFontSize(22);
	//		bat->setColor(ccc3(230, 0, 0));
	//		this->addChild(bat);
	//	}
	//}
	
	return true;
}

void HomePage::touchEvent(Ref* pSender, TouchEventType type)
{

}

void HomePage::InitView()
{
	
}
