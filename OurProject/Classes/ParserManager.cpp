//
//  ParserManager.cpp
//  Client
//
//  Created by zy-mac on 13-3-1.
//
//

#include "Common.h"

#include "ParserManager.h"
//
static ParserManager* s_SharedParserManager = NULL;
ParserManager* ParserManager::singleton(void)
{
	if (!s_SharedParserManager)
	{
		s_SharedParserManager = new ParserManager();
	//	s_SharedParserManager->init();
	}

	return s_SharedParserManager;
}

ParserManager::ParserManager() 
//INIT_RES_CLASS_PTR(RES_VIP_LEVEL_POWER, "vip")
	//, INIT_RES_CLASS_PTR(RES_VIP_STORE, "recharge")
	//, INIT_RES_CLASS_PTR(RES_MAKEITEM, "makelist")
	//, INIT_RES_CLASS_PTR(RES_MAKECOST, "makecost")
	//, INIT_RES_CLASS_PTR(RES_WEEK_DOING, "week")
{
	Init();
}

ParserManager::~ParserManager()
{
	Release();
}

bool ParserManager::Init()
{  
//	Init_RES_WEEK_DOING_Data();
	return true;
}

void ParserManager::Release()
{
	//RELEASE_RES_CLASS_PTR(RES_VIP_LEVEL_POWER);
	//RELEASE_RES_CLASS_PTR(RES_VIP_STORE);
	//RELEASE_RES_CLASS_PTR(RES_MAKEITEM);
	//RELEAS//RES_CLASS_PTR(RES_MAKECOST);
}



