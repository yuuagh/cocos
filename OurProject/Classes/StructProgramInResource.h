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



// vip�ȼ�����Ȩ
typedef struct _tagRES_VIP_LEVEL_POWER
{
	_UINT32 m_unVipLevel;      //VIP�ȼ�
	_UINT32 m_unNeedCharge;      //��Ҫ�ĳ�ֵ���
	_UINT8 m_unIsSweep;      //�Ƿ�ɨ��
	_UINT32 m_unSweepNum;      //���ɨ������
	_UINT32 m_unPhysicalBuyNum;     //�����������
	_UINT32 m_unHandToCoinNum;     //�����ʹ�ô���
	_UINT32 m_unEliteChargeNum;     //��Ӣ���ô���
	_UINT8 m_unIsBuySkill;      //�Ƿ�����ܵ�
	_UINT8 m_unIsContinueSweep;    //�Ƿ�����ɨ��
	_UINT8 m_unIsForeverSpecialMall;   //�Ƿ����õؾ��̵�
	_UINT8 m_unTempleResetNum;     //�칬���ô���
	_UINT8 m_unIsForeverBlackMarketBoss;  //�Ƿ���Զ�����ϴ�
	_UINT8 m_unExpeditionAdditional;   //Զ��������ͭǮ

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


// vip�ȼ���Ȩ����������
typedef struct _tagRES_VIP_DESCRIPTION
{
	_UINT32 m_unVipLevel;       //VIP�ȼ�
	_UINT8 m_szVipDesc[1024];                   //VIP����


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
	_UINT8  m_unID;     //���
	_UINT32 m_unDiamondNum;      //����õ���Ӧ����ʯ��Ԫ����
	_UINT32 m_unIconID;       //ͼƬID
	_UINT32 m_unGoodsPrice;           //��Ʒ�۸�
	_UINT8  m_unGoodsName[256];        //��Ʒ������
	_UINT8  m_unExtraIntroduce[256];   //��Ʒ�Ķ�������

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
	RES_MAKEITEM_SOURCEID,     //�ϳ�ԭ������ƷID
	RES_MAKEITEM_CANMAKEID,     //�ɺϳ���ƷID 
	RES_MAKEITEM_MAKENUM,  //���ĵ�����
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
	_UINT8 m_unQulity;   // �ϳ�װ����Ʒ��
	_UINT32 m_unCost;    // ���ĵ�Ǯ

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
	_UINT32 m_unKey;            // ����
	_UINT8 m_szFirstName[256];  // ����ǰ׺
	_UINT8 m_szLastName[256];   // ���ֺ�׺

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


// �
enum RES_ACTIVITY_BASE_DATA
{
	RES_ACTIVITY_BASE_DATA_ID = 1,              // �ID
	RES_ACTIVITY_BASE_DATA_CHECKPOINTNAME,      // �ؿ�����
	RES_ACTIVITY_BASE_DATA_OPENTIPS,   // ����ʱ������
	RES_ACTIVITY_BASE_DATA_CHECKPOINTDES,  // �ؿ�����
	RES_ACTIVITY_BASE_DATA_OPENTIME,   // ����ʱ��
	RES_ACTIVITY_BASE_DATA_BATTLENAME,   // ս������
	RES_ACTIVITY_BASE_DATA_OPENLEVEL,   // ���ŵȼ�
	RES_ACTIVITY_BASE_DATA_CONSUMEPHYSICAL,  // ���ĵ�����
	RES_ACTIVITY_BASE_DATA_ENTERNUM,   // ÿ��ɽ���Ĵ���
	RES_ACTIVITY_BASE_DATA_OPENTIME1,   // ����ʱ��1
	RES_ACTIVITY_BASE_DATA_OPENTIME2,
	RES_ACTIVITY_BASE_DATA_OPENTIME3,
	RES_ACTIVITY_BASE_DATA_OPENTIME4,
	RES_ACTIVITY_BASE_DATA_MONSTER1,   // ����
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