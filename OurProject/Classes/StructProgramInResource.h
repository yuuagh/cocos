#ifndef __STRUCT_PROGRAM_IN_RESOURCE_H__
#define __STRUCT_PROGRAM_IN_RESOURCE_H__

#include "Common.h"


#define STRUCT_SIMPLE_CREATE_CASE(UNINDEX, DATA) \
 case UNINDEX: \
{ \
	*ppMember = reinterpret_cast<_UINT8*>(&DATA); \
	unMemberSize16 = sizeof(DATA); \
} \
	break;



// vip等级的特权
typedef struct _tagRES_VIP_LEVEL_POWER
{
	_UINT32 m_unVipLevel;      //VIP等级
	_UINT32 m_unNeedCharge;      //需要的充值金额
	_UINT8 m_unIsSweep;      //是否扫荡
	_UINT32 m_unSweepNum;      //免费扫荡次数
	_UINT32 m_unPhysicalBuyNum;     //体力购买次数
	_UINT32 m_unHandToCoinNum;     //点金手使用次数
	_UINT32 m_unEliteChargeNum;     //精英重置次数
	_UINT8 m_unIsBuySkill;      //是否可买技能点
	_UINT8 m_unIsContinueSweep;    //是否连续扫荡
	_UINT8 m_unIsForeverSpecialMall;   //是否永久地精商店
	_UINT8 m_unTempleResetNum;     //天宫重置次数
	_UINT8 m_unIsForeverBlackMarketBoss;  //是否永远黑市老大
	_UINT8 m_unExpeditionAdditional;   //远征额外获得铜钱

	static const _UINT8 _MEMBER_NUM = 13;


	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
			STRUCT_SIMPLE_CREATE_CASE(1,  m_unVipLevel);
			STRUCT_SIMPLE_CREATE_CASE(2,  m_unNeedCharge);
			STRUCT_SIMPLE_CREATE_CASE(3,  m_unIsSweep);
			STRUCT_SIMPLE_CREATE_CASE(4,  m_unSweepNum);
			STRUCT_SIMPLE_CREATE_CASE(5,  m_unPhysicalBuyNum);
			STRUCT_SIMPLE_CREATE_CASE(6,  m_unHandToCoinNum);
			STRUCT_SIMPLE_CREATE_CASE(7,  m_unEliteChargeNum);
			STRUCT_SIMPLE_CREATE_CASE(8,  m_unIsBuySkill);
			STRUCT_SIMPLE_CREATE_CASE(9,  m_unIsContinueSweep);
			STRUCT_SIMPLE_CREATE_CASE(10, m_unIsForeverSpecialMall);
			STRUCT_SIMPLE_CREATE_CASE(11, m_unTempleResetNum);
			STRUCT_SIMPLE_CREATE_CASE(12, m_unIsForeverBlackMarketBoss);
			STRUCT_SIMPLE_CREATE_CASE(13, m_unExpeditionAdditional);
		default:
			{
			}
			break;
		}

		return unMemberSize16;
	}

	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}
	RESOURCE_KEY GetKey() const
	{
		return m_unVipLevel;
	}
}RES_VIP_LEVEL_POWER, *LPRES_VIP_LEVEL_POWER;


// vip等级特权的文字描述
typedef struct _tagRES_VIP_DESCRIPTION
{
	_UINT32 m_unVipLevel;       //VIP等级
	_UINT8 m_szVipDesc[1024];                   //VIP描述


	static const _UINT8 _MEMBER_NUM = 2;


	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
			STRUCT_SIMPLE_CREATE_CASE(1, m_unVipLevel);
			STRUCT_SIMPLE_CREATE_CASE(2, m_szVipDesc);

		default:
			{
			}
			break;
		}

		return unMemberSize16;
	}

	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}
	RESOURCE_KEY GetKey() const
	{
		return m_unVipLevel;
	}
}RES_VIP_DESCRIPTION, *LPRES_VIP_DESCRIPTION;



typedef struct _tagRES_VIP_STORE
{
	_UINT8  m_unID;     //序号
	_UINT32 m_unDiamondNum;      //购买得到相应的钻石（元宝）
	_UINT32 m_unIconID;       //图片ID
	_UINT32 m_unGoodsPrice;           //商品价格
	_UINT8  m_unGoodsName[256];        //商品的名字
	_UINT8  m_unExtraIntroduce[256];   //商品的额外描述

	static const _UINT8 _MEMBER_NUM = 6;

	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
			STRUCT_SIMPLE_CREATE_CASE(1, m_unID);
			STRUCT_SIMPLE_CREATE_CASE(2, m_unDiamondNum);
			STRUCT_SIMPLE_CREATE_CASE(3, m_unIconID);
			STRUCT_SIMPLE_CREATE_CASE(4, m_unGoodsPrice);
			STRUCT_SIMPLE_CREATE_CASE(5, m_unGoodsName);
			STRUCT_SIMPLE_CREATE_CASE(6, m_unExtraIntroduce);
		default:
			{
			}
			break;
		}

		return unMemberSize16;
	}

	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}
	RESOURCE_KEY GetKey() const
	{
		return m_unID;
	}
}RES_VIP_STORE, *LPRES_VIP_STORE;

enum RES_MAKEITEM_DATA
{
	RES_MAKEITEM_SOURCEID,     //合成原材料物品ID
	RES_MAKEITEM_CANMAKEID,     //可合成物品ID 
	RES_MAKEITEM_MAKENUM,  //消耗的数量
	RES_MAKEITEM_MAX
};

typedef struct _tagRES_MAKEITEM
{
	_UINT32  m_unMakeItem[RES_MAKEITEM_MAX];
	static const _UINT8 _MEMBER_NUM = RES_MAKEITEM_MAX;
	//-----------------------------------------------------------------------
	// parse call back
	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
		case RES_MAKEITEM_SOURCEID:
		default:
			{
				*ppMember = reinterpret_cast<_UINT8*>(&m_unMakeItem[unIndex16 - 1]);
				unMemberSize16 = sizeof(m_unMakeItem[unIndex16 - 1]);
			}
			break;
		}

		return unMemberSize16;
	}
	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}
	RESOURCE_KEY GetKey()
	{
		return m_unMakeItem[RES_MAKEITEM_SOURCEID] * 10000000 + m_unMakeItem[RES_MAKEITEM_CANMAKEID];
	}

	RESOURCE_KEY GetSourceItemID() const
	{
		return m_unMakeItem[RES_MAKEITEM_SOURCEID];
	}
}RES_MAKEITEM;


typedef struct _tagRES_MAKECOST
{
	_UINT8 m_unQulity;   // 合成装备的品质
	_UINT32 m_unCost;    // 消耗的钱

	static const _UINT8 _MEMBER_NUM = 2;

	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
			STRUCT_SIMPLE_CREATE_CASE(1, m_unQulity);
			STRUCT_SIMPLE_CREATE_CASE(2, m_unCost);
		default:
			break;
		}
		return unMemberSize16;
	}
	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}
	RESOURCE_KEY GetKey()
	{
		return m_unQulity;
	}

}RES_MAKECOST;


typedef struct _tagRES_PLAYER_NAME
{
	_UINT32 m_unKey;            // 索引
	_UINT8 m_szFirstName[256];  // 名字前缀
	_UINT8 m_szLastName[256];   // 名字后缀

	static const _UINT8 _MEMBER_NUM = 3;
	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
			STRUCT_SIMPLE_CREATE_CASE(1, m_unKey);
			STRUCT_SIMPLE_CREATE_CASE(2, m_szFirstName);
			STRUCT_SIMPLE_CREATE_CASE(3, m_szLastName);
		default:
			break;
		}
		return unMemberSize16;
	}

	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}
	RESOURCE_KEY GetKey()
	{
		return m_unKey;
	}

}RES_PLAYER_NAME;


// 活动
enum RES_ACTIVITY_BASE_DATA
{
	RES_ACTIVITY_BASE_DATA_ID = 1,              // 活动ID
	RES_ACTIVITY_BASE_DATA_CHECKPOINTNAME,      // 关卡名称
	RES_ACTIVITY_BASE_DATA_OPENTIPS,   // 开放时间描述
	RES_ACTIVITY_BASE_DATA_CHECKPOINTDES,  // 关卡描述
	RES_ACTIVITY_BASE_DATA_OPENTIME,   // 开放时间
	RES_ACTIVITY_BASE_DATA_BATTLENAME,   // 战役名称
	RES_ACTIVITY_BASE_DATA_OPENLEVEL,   // 开放等级
	RES_ACTIVITY_BASE_DATA_CONSUMEPHYSICAL,  // 消耗的体力
	RES_ACTIVITY_BASE_DATA_ENTERNUM,   // 每天可进入的次数
	RES_ACTIVITY_BASE_DATA_OPENTIME1,   // 开放时间1
	RES_ACTIVITY_BASE_DATA_OPENTIME2,
	RES_ACTIVITY_BASE_DATA_OPENTIME3,
	RES_ACTIVITY_BASE_DATA_OPENTIME4,
	RES_ACTIVITY_BASE_DATA_MONSTER1,   // 怪物
	RES_ACTIVITY_BASE_DATA_MONSTER2,
	RES_ACTIVITY_BASE_DATA_MONSTER3,

};
typedef struct _tagRES_ACTIVITY_BASE
{
	_UINT32 m_unKeyID;
	_UINT8 m_unCheckPointName[256];
	_UINT8 m_szOpenTips[256];
	_UINT8 m_szCheckPointDes[256];
	_UINT8 m_szOpenTime[256];
	_UINT8 m_szBattleName[64];
	_UINT32 m_unOpenLevel;
	_UINT8 m_unConsumePhysical;
	_UINT8 m_unEnterNum;
	_UINT8 m_unTimeBase[4];
	_UINT32 m_unMonsterBase[3];

	static const _UINT8 _MEMBER_NUM = 16;
	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_ID, m_unKeyID);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_CHECKPOINTNAME, m_unCheckPointName);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_OPENTIPS, m_szOpenTips);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_CHECKPOINTDES, m_szCheckPointDes);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_OPENTIME, m_szOpenTime);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_BATTLENAME, m_szBattleName);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_OPENLEVEL, m_unOpenLevel);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_CONSUMEPHYSICAL, m_unConsumePhysical);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_ENTERNUM, m_unEnterNum);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_OPENTIME1, m_unTimeBase[0]);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_OPENTIME2, m_unTimeBase[1]);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_OPENTIME3, m_unTimeBase[2]);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_OPENTIME4, m_unTimeBase[3]);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_MONSTER1, m_unMonsterBase[0]);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_MONSTER2, m_unMonsterBase[1]);
			STRUCT_SIMPLE_CREATE_CASE(RES_ACTIVITY_BASE_DATA_MONSTER3, m_unMonsterBase[2]);
		default:
			break;
		}
		return unMemberSize16;
	}

	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}
	RESOURCE_KEY GetKey()
	{
		return m_unKeyID;
	}

}RES_ACTIVITY_BASE;


enum RES_SIGN_REWARD_DATA
{
	RES_SIGN_REWARD_DATA_MONTH = 1,
	RES_SIGN_REWARD_DATA_DAY,
	RES_SIGN_REWARD_DATA_REWARD,
	RES_SIGN_REWARD_DATA_REWARD_NUM,
	RES_SIGN_REWARD_DATA_DOUBLE_VIPLEVEL,

};

typedef struct _tagRES_SIGN_REWARD
{
	_UINT8 m_unMonth;
	_UINT8 m_unDay;
	_UINT32 m_unReward;
	_UINT32 m_unRewardNum;
	_UINT32 m_unDoubleVipLevel;

	static const _UINT8 _MEMBER_NUM = 5;

	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
			STRUCT_SIMPLE_CREATE_CASE(RES_SIGN_REWARD_DATA_MONTH, m_unMonth);
			STRUCT_SIMPLE_CREATE_CASE(RES_SIGN_REWARD_DATA_DAY, m_unDay);
			STRUCT_SIMPLE_CREATE_CASE(RES_SIGN_REWARD_DATA_REWARD, m_unReward);
			STRUCT_SIMPLE_CREATE_CASE(RES_SIGN_REWARD_DATA_REWARD_NUM, m_unRewardNum);
			STRUCT_SIMPLE_CREATE_CASE(RES_SIGN_REWARD_DATA_DOUBLE_VIPLEVEL, m_unDoubleVipLevel);

		default:
			break;
		}
		return unMemberSize16;
	}

	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}

	RESOURCE_KEY GetKey()
	{
		return m_unMonth * 1000 + m_unDay;
	}

}RES_SIGN_REWARD;

enum RES_WEEK_DOING_DATA
{
	RES_WEEK_DOING_DATA_DAY = 1,
	RES_WEEK_DOING_DATA_TIME,
	RES_WEEK_DOING_DATA_TEACHER,
};
typedef struct _tagRES_WEEK_DOING
{
	_UINT8 m_unDay;
	_UINT8 m_unTime;
	_UINT8 m_szTeacher[64];

	static const _UINT8 _MEMBER_NUM = 3;
	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
	{
		_UINT16 unMemberSize16 = 0;
		switch (unIndex16)
		{
			STRUCT_SIMPLE_CREATE_CASE(RES_WEEK_DOING_DATA_DAY, m_unDay);
			STRUCT_SIMPLE_CREATE_CASE(RES_WEEK_DOING_DATA_TIME, m_unTime);
			STRUCT_SIMPLE_CREATE_CASE(RES_WEEK_DOING_DATA_TEACHER, m_szTeacher);

		default:
			break;
		}
		return unMemberSize16;
	}

	_UINT16 GetMemberNum() const
	{
		return _MEMBER_NUM;
	}

	RESOURCE_KEY GetKey()
	{
		return m_unDay;
	}
}RES_WEEK_DOING;


#endif // __STRUCT_PROGRAM_IN_RESOURCE_H__