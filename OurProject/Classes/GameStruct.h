//
//  GameStruct.h
//  Client
//
//  Created by zy-mac on 13-2-21.
//
//

#ifndef Client_GameStruct_h
#define Client_GameStruct_h

#include "Common.h"
//
//enum ECLientSceneState
//{//�ͻ��˳���״̬
//	CSS_NORMAL = 0,  //��ͨ״̬
//	CSS_READY_FIGHTING,   //׼��ս��
//	CSS_FIGHTING,      //ս��״̬
//};
//
//// #pragma mark -
//// #pragma mark light
//enum ELightType
//{//��Ч����
//	LT_NORMAL           = 0,    //��ͨ
//	LT_HERO_BEENATTACK  = 1,    //Ӣ�����ϵı�����Ч
//	LT_FLY_OBJ          = 2,    //���ж����Ч
//	LT_BUFFER           = 3,    //buffer��Ч
//	LT_DROPTHING        = 4,    //������Ʒ��Ч
//	LT_DEADTH           = 5,    //������Ч
//	// LT_DROP_MONEY       = 6,    //�����Ǯ
//	LT_GUI              = 6,    //�����Ч
//	LT_JOINT            = 7,    //����������Ʒ�Ĺ�Ч
//	LT_BUTTON           = 8,    //��ť��Ч
//	LT_DAMAGE_NUMBER    = 9,    //�˺���ֵ��Ч
//	LT_ANGER            = 10,
//	LT_NORMALLOOP  = 11,   //��ͨѭ������
//};
//
//// #pragma mark -
//// #pragma mark OtherDlg_TabType
//enum OtherDlg_TabType
//{
//	TabType_Msg,    
//	TabType_HeroCard,
//	TabType_Help,
//	TabType_Setting,
//	TabType_Feedback,
//	TabType_About,
//	TabType_Notice,
//
//	TabType_Max
//};
//
//// #pragma mark -
//// #pragma mark Help
//
//// #pragma mark -
//// #pragma mark MallDlg_TabType
//enum MallDlg_TabType
//{
//	Mall_TabType_Prop = 0,
//	Mall_TabType_Material,
//	Mall_TabType_Recharge,
//	Mall_TabType_VIP,
//	Mall_TabType_Card,    
//	Mall_TabType_Max
//};
//
//// #pragma mark -
//// #pragma mark skill
//enum CLIENTSKILL_CFG_DATA
//{
//	CLIENTSKILL_CFG_ANINAME,//  STRING ������ attack1
//	CLIENTSKILL_CFG_ANISOUND,//  STRING ������Ч 0
//	CLIENTSKILL_CFG_FLYEFFECT,//  STRING ������Ч 0
//	CLIENTSKILL_CFG_FLYSOUND,//  STRING ������Ч 0
//	CLIENTSKILL_CFG_AREAEFFECT,//  STRING ��Χ��Ч 0
//	CLIENTSKILL_CFG_AREASOUND,//  STRING ��Χ��Ч 0
//	CLIENTSKILL_CFG_SCREENEFFECT,//  STRING ȫ����Ч 0
//	CLIENTSKILL_CFG_SCREENSOUND,//  STRING ȫ����Ч 0
//	CLIENTSKILL_CFG_AIMEFFECT,//  STRING ������Ч hitlight_tangseng_huoqiu
//	CLIENTSKILL_CFG_AIMSOUND,//  STRING ������Ч 0
//
//	CLIENTSKILL_CFG_MAX
//};
//
//enum CLIENTSKILL_SHAKE_DATA
//{
//	CLIENTSKILL_SHAKE_TIME1,//  INT ����ʱ��1 0
//	CLIENTSKILL_SHAKE_RANGE1,//  INT ��������1 0
//	CLIENTSKILL_SHAKE_TIME2,//  INT ����ʱ��1 0
//	CLIENTSKILL_SHAKE_RANGE2,//  INT ��������1 0
//	CLIENTSKILL_SHAKE_TIME3,//  INT ����ʱ��1 0
//	CLIENTSKILL_SHAKE_RANGE3,//  INT ��������1 0
//
//	CLIENTSKILL_SHAKE_MAX
//};
//typedef struct _tagRES_CLIENT_SKILL
//{//�ͻ��˼����ļ�����Ҫ��������Ϣ���ͼ�����Ч����Ч�����ļ�
//	_UINT32     m_unSkillId;                //����id
//	_UINT32  m_unPrepareTime;//  FLOAT ׼��ʱ�� 1.3
//	_UINT32  m_unFlyStartTime;//  FLOAT ���п�ʼʱ�� 1.3
//	_UINT32  m_unFlyEndTime;//  FLOAT ���н���ʱ�� 1.7
//	_UINT8  m_strConfigName[CLIENTSKILL_CFG_MAX][64];//
//	_UINT32     m_unShake[CLIENTSKILL_SHAKE_MAX];
//
//	static const _UINT8 _MEMBER_NUM = CLIENTSKILL_SHAKE_MAX + CLIENTSKILL_CFG_MAX+4;
//
//	//-----------------------------------------------------------------------
//	// parse call back
//	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
//	{
//		_UINT16 unMemberSize16 = 0;
//		switch (unIndex16)
//		{
//		case 1:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unSkillId);
//				unMemberSize16 = sizeof(m_unSkillId);
//			}
//			break;
//		case 2:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unPrepareTime);
//				unMemberSize16 = sizeof(m_unPrepareTime);
//			}
//			break;
//		case 3:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unFlyStartTime);
//				unMemberSize16 = sizeof(m_unFlyStartTime);
//			}
//			break;
//		case 4:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unFlyEndTime);
//				unMemberSize16 = sizeof(m_unFlyEndTime);
//			}
//			break;
//		case 5+CLIENTSKILL_CFG_ANINAME://  STRING ������ attack1
//		case 5 + CLIENTSKILL_CFG_ANISOUND://  STRING ������Ч 0
//		case 5 + CLIENTSKILL_CFG_FLYEFFECT://  STRING ������Ч 0
//		case 5 + CLIENTSKILL_CFG_FLYSOUND://  STRING ������Ч 0
//		case 5 + CLIENTSKILL_CFG_AREAEFFECT://  STRING ��Χ��Ч 0
//		case 5 + CLIENTSKILL_CFG_AREASOUND://  STRING ��Χ��Ч 0
//		case 5 + CLIENTSKILL_CFG_SCREENEFFECT://  STRING ȫ����Ч 0
//		case 5 + CLIENTSKILL_CFG_SCREENSOUND://  STRING ȫ����Ч 0
//		case 5 + CLIENTSKILL_CFG_AIMEFFECT://  STRING ������Ч hitlight_tangseng_huoqiu
//		case 5 + CLIENTSKILL_CFG_AIMSOUND://  STRING ������Ч 0
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strConfigName[unIndex16 - 5 - CLIENTSKILL_CFG_ANINAME]);
//				unMemberSize16 = sizeof(m_strConfigName[CLIENTSKILL_CFG_ANINAME]);
//			}
//			break;
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_TIME1://  INT ����ʱ��1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_RANGE1://  INT ��������1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_TIME2://  INT ����ʱ��1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_RANGE2://  INT ��������1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_TIME3://  INT ����ʱ��1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_RANGE3://  INT ��������1 0
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unShake[unIndex16 - 5 - CLIENTSKILL_CFG_MAX - CLIENTSKILL_SHAKE_TIME1]);
//				unMemberSize16 = sizeof(m_unShake[CLIENTSKILL_SHAKE_TIME1]);
//			}
//			break;
//		}
//
//		return unMemberSize16;
//	}
//
//	_UINT16 GetMemberNum() const
//	{
//		return _MEMBER_NUM;
//	}
//	RESOURCE_KEY GetKey() const
//	{
//		//  
//		return m_unSkillId;
//	}
//
//	const char *GetConfigName(CLIENTSKILL_CFG_DATA cfg) const
//	{
//		return (char*)m_strConfigName[cfg];
//	}
//}RES_CLIENT_SKILL,*LPRES_CLIENT_SKILL;
//
//// #pragma mark -
//// #pragma mark RES_CLIENT_STATUS
//typedef struct _tagRES_CLIENT_STATUS
//{//״̬Ч������
//	_UINT32     m_unStatusTexID;            //״̬����id
//	_UINT8      m_strStatusName[32];        //״̬����
//	_UINT8      m_strStatusText1[32];       //״̬��������1
//	_UINT32     m_unStatusIcon1;            //״̬�Ƿ��м�ͷͼ��1
//	_UINT32     m_unStatusCorlor1;          //״̬������ɫ����1
//	_UINT8      m_strStatusText2[32];       //״̬��������2
//	_UINT32     m_unStatusIcon2;            //״̬�Ƿ��м�ͷͼ��2
//	_UINT32     m_unStatusCorlor2;          //״̬������ɫ����2
//
//	static const _UINT8 _MEMBER_NUM = 8;
//
//	//-----------------------------------------------------------------------
//	// parse call back
//	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
//	{
//		_UINT16 unMemberSize16 = 0;
//		switch (unIndex16)
//		{
//		case 1:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unStatusTexID);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 2:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strStatusName);
//				unMemberSize16 = sizeof(m_strStatusName);
//			}
//			break;
//		case 3:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strStatusText1);
//				unMemberSize16 = sizeof(m_strStatusText1);
//			}
//			break;
//		case 4:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unStatusIcon1);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 5:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unStatusCorlor1);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 6:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strStatusText2);
//				unMemberSize16 = sizeof(m_strStatusText2);
//			}
//			break;
//		case 7:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unStatusIcon2);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 8:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unStatusCorlor2);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		default:
//			break;
//		}
//
//		return unMemberSize16;
//	}
//
//	_UINT16 GetMemberNum() const
//	{
//		return _MEMBER_NUM;
//	}
//	RESOURCE_KEY GetKey() const
//	{
//		//
//		return m_unStatusTexID;
//	}
//
//}RES_CLIENT_STATUS, *LPRES_CLIENT_STATUS;
//
//// #pragma mark -
//// #pragma mark HEROFILTMENUDIR
//typedef struct _tagRES_CLIENT_HERO
//{//�ͻ���Ӣ��Ч�����ݣ���Ҫ�Ǳ�����Ч����Ч�����ļ�
//	_UINT32     m_unHeroID;                 //Ӣ��id
//	_UINT8      m_strBeenAttLight[32];      //����������Ч
//	_UINT8      m_strBeenAttSound[32];      //����������Ч
//	_UINT8      m_strDeadSound[32];         //������Ч
//	_INT32      m_unScale;                  //���ű���
//	_UINT8      m_strSoundStartFly8[32];    //���08����
//	_UINT8      m_strSoundEndFly7[32];      //���07����
//	_UINT8      m_strSoundEndFly9[32];      //���09����
//
//	static const _UINT8 _MEMBER_NUM = 8;
//
//	//-----------------------------------------------------------------------
//	// parse call back
//	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
//	{
//		_UINT16 unMemberSize16 = 0;
//		switch (unIndex16)
//		{
//		case 1:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unHeroID);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 2:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strBeenAttLight);
//				unMemberSize16 = sizeof(m_strBeenAttLight);
//			}
//			break;
//		case 3:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strBeenAttSound);
//				unMemberSize16 = sizeof(m_strBeenAttSound);
//			}
//			break;
//		case 4:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strDeadSound);
//				unMemberSize16 = sizeof(m_strDeadSound);
//			}
//			break;
//		case 5:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unScale);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 6:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strSoundStartFly8);
//				unMemberSize16 = sizeof(m_strSoundStartFly8);
//			}
//			break;
//		case 7:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strSoundEndFly7);
//				unMemberSize16 = sizeof(m_strSoundEndFly7);
//			}
//			break;
//		case 8:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strSoundEndFly9);
//				unMemberSize16 = sizeof(m_strSoundEndFly9);
//			}
//			break;
//		default:
//			break;
//		}
//
//		return unMemberSize16;
//	}
//
//	_UINT16 GetMemberNum() const
//	{
//		return _MEMBER_NUM;
//	}
//	RESOURCE_KEY GetKey() const
//	{
//		//
//		return m_unHeroID;
//	}
//
//}RES_CLIENT_HERO,*LPRES_CLIENT_HERO;
//
//// #pragma mark -
//// #pragma mark RES_HERO_POSITION
//typedef struct _tagRES_HERO_POSITION
//{//�ͻ���Ӣ��վλ����
//	_UINT32     m_unPtID;          //����id
//	_INT32     m_unPtX;           //x����
//	_INT32     m_unPtY;           //y����
//	static const _UINT8 _MEMBER_NUM = 3;
//
//	//-----------------------------------------------------------------------
//	// parse call back
//	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
//	{
//		_UINT16 unMemberSize16 = 0;
//		switch (unIndex16)
//		{
//		case 1:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unPtID);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 2:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unPtX);
//				unMemberSize16 = sizeof(_INT32);
//			}
//			break;
//		case 3:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unPtY);
//				unMemberSize16 = sizeof(_INT32);
//			}
//			break;
//		default:
//			break;
//		}
//
//		return unMemberSize16;
//	}
//
//	_UINT16 GetMemberNum() const
//	{
//		return _MEMBER_NUM;
//	}
//	RESOURCE_KEY GetKey() const
//	{
//		return m_unPtID;
//	}
//}RES_HERO_POSITION,*LPRES_HERO_POSITION;
//
//
//// #pragma mark -
//// #pragma mark RES_CLIENT_SCENE
//typedef struct _tagRES_CLIENT_SCENE
//{//�ͻ���Ӣ��Ч�����ݣ���Ҫ�Ǳ�����Ч����Ч�����ļ�
//	_UINT32     m_unSceneID;                //����id
//	_UINT8      m_strBgMusic[32];           //��������
//	_UINT8      m_strBgSound1[32];          //������Ч1
//	_UINT8      m_strBgSound2[32];          //������Ч2
//	_UINT8      m_strShakeLight1[32];       //�𶯹�Ч1
//	_UINT8      m_strShakeLight2[32];       //�𶯹�Ч2
//	_UINT8      m_strShakeSound1[32];       //����Ч1
//	_UINT8      m_strShakeSound2[32];       //����Ч2
//	_UINT8      m_strBossBgm[32];           //boss�ر�������
//	static const _UINT8 _MEMBER_NUM = 9;
//
//	//-----------------------------------------------------------------------
//	// parse call back
//	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
//	{
//		_UINT16 unMemberSize16 = 0;
//		switch (unIndex16)
//		{
//		case 1:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unSceneID);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 2:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strBgMusic);
//				unMemberSize16 = sizeof(m_strBgMusic);
//			}
//			break;
//		case 3:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strBgSound1);
//				unMemberSize16 = sizeof(m_strBgSound1);
//			}
//			break;
//		case 4:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strBgSound2);
//				unMemberSize16 = sizeof(m_strBgSound2);
//			}
//			break;
//		case 5:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strShakeLight1);
//				unMemberSize16 = sizeof(m_strShakeLight1);
//			}
//			break;
//		case 6:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strShakeLight2);
//				unMemberSize16 = sizeof(m_strShakeLight2);
//			}
//			break;
//		case 7:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strShakeSound1);
//				unMemberSize16 = sizeof(m_strShakeSound1);
//			}
//			break;
//		case 8:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strShakeSound2);
//				unMemberSize16 = sizeof(m_strShakeSound2);
//			}
//			break;
//		case 9:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strBossBgm);
//				unMemberSize16 = sizeof(m_strBossBgm);
//			}
//			break;
//		default:
//			break;
//		}
//
//		return unMemberSize16;
//	}
//
//	_UINT16 GetMemberNum() const
//	{
//		return _MEMBER_NUM;
//	}
//	RESOURCE_KEY GetKey() const
//	{
//		//
//		return m_unSceneID;
//	}
//
//}RES_CLIENT_SCENE,*LPRES_CLIENT_SCENE;
//
//// #pragma mark -
//// #pragma mark HEROFILTMENUDIR
//enum HeroFilterDir
//{
//	FilterDir_Up,
//	FilterDir_Down,
//};
//
//
//// #pragma mark -
//// #pragma mark TeamerMenuType
//enum TeamerMenuType
//{
//	TeamerMenu_FriendlyArmy,
//	TeamerMenu_BattlePos,
//};
//
//// #pragma mark -
//// #pragma mark FunctionBar_Type
//enum FunctionBar_Type
//{
//	FunctionBar_Home,
//	FunctionBar_Battle,
//	FunctionBar_WarSoul,
//	FunctionBar_Mission,
//	FunctionBar_Social,
//	FunctionBar_JingJi,
//	FunctionBar_Mall,
//	FunctionBar_Others,
//	FunctionBar_Bag,
//
//	FunctionBar_Type_Max
//};
//
//
//
//typedef struct _VipFightValueInfo
//{
//	_UINT32     m_unBaseMoney;
//	_UINT32     m_unBaseExp;
//	_UINT32     m_unVipMoney;
//	_UINT32     m_unVipExp;
//	_UINT32     m_unBufferMoney;
//	_UINT32     m_unBufferExp;
//
//	_VipFightValueInfo()
//	{
//		m_unBaseMoney   = 0;
//		m_unBaseExp     = 0;
//		m_unVipMoney    = 0;
//		m_unVipExp      = 0;
//		m_unBufferMoney = 0;
//		m_unBufferExp   = 0;
//	}
//
//	void Reset()
//	{
//		m_unBaseMoney   = 0;
//		m_unBaseExp     = 0;
//		m_unVipMoney    = 0;
//		m_unVipExp      = 0;
//		m_unBufferMoney = 0;
//		m_unBufferExp   = 0;
//	}
//
//	_VipFightValueInfo &operator+=(_VipFightValueInfo &info)
//	{
//		m_unBaseMoney   += info.m_unBaseMoney;
//		m_unBaseExp     += info.m_unBaseExp;
//		m_unVipMoney    += info.m_unVipMoney;
//		m_unVipExp      += info.m_unVipExp;
//		m_unBufferMoney += info.m_unBufferMoney;
//		m_unBufferExp   += info.m_unBaseExp;
//		return *this;
//	}
//
//}VipFightValueInfo;
//
//// #pragma mark -
//// #pragma mark HelpInfo
//typedef struct tagHELPITEMINFO
//{
//	__String  m_strCat;
//	__String  m_strCaption;
//	__String  m_strDesc;
//}HELPITEMINFO,*LPHELPITEMINFO;
//
//enum HelpItem_Type
//{
//	HELP_PLAYER_INFO   = 1  ,   //�������
//	HELP_HERO_INFO       ,   //Ӣ�����
//	HELP_WAR_INFO        ,   //ս�����
//	HELP_ZH_INFO         ,   //ս�����
//	HELP_TASK_INFO       ,   //����
//	HELP_FRIEND_INFO     ,   //����
//	HELP_PK_INFO         ,   //������
//	HELP_MALL_INFO       ,   //�̳�
//
//	HELP_MAX
//};
//
//// #pragma mark -
//// #pragma mark Store
////---------------------------------------------------------------------------
////  Store VIP Privileged Desc Item
////---------------------------------------------------------------------------
//typedef struct tagRES_VIP_PRIVILEGED_DESC
//{
//	_UINT8             m_uiVIPLevel ;
//	_UINT8              m_szDesc[1000] ;
//	static const _UINT8 _MEMBER_NUM = 2;
//	//-----------------------------------------------------------------------
//	// parse call back
//	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
//	{
//		_UINT16 unMemberSize16 = 0;
//		switch (unIndex16)
//		{
//		case 1:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_uiVIPLevel);
//				unMemberSize16 = sizeof(_UINT8);
//			}
//			break;
//		case 2:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_szDesc);
//				unMemberSize16 = sizeof(m_szDesc);
//
//			}
//			break;
//		default:
//			break;
//
//		}
//
//		return unMemberSize16;
//	}
//	_UINT16 GetMemberNum() const
//	{
//		return _MEMBER_NUM;
//	}
//	RESOURCE_KEY GetKey() const
//	{
//		return m_uiVIPLevel;
//	}
//}RES_VIP_PRIVILEGED_DESC, *LPRES_VIP_PRIVILEGED_DESC;
//
//// #pragma mark -
//// #pragma mark FontType
//enum eFontType
//{
//	FontType_FZKTGH32,
//	FontType_FZKTOUTLINE,
//	FontType_Num22,
//	FontType_Num26,
//	FontType_Num34,
//	FontType_Bat_Green36,
//	FontType_Bat_Red36,
//	FontType_Bat_Red48,
//
//	FontType_MAX
//};
//
//static char FONTTYPE[FontType_MAX][64] =
//{
//	"FZguanghui-32.fnt",
//	"FZKaTong-M19S-Boldoutline.fnt",
//	"shuzi-jiacu-22.fnt",
//	"shuzi-jiacu-26.fnt",
//	"shuzi-jiacu-34.fnt",
//	"zhs-battle-36-green.fnt",
//	"zhs-battle-36-red.fnt",
//	"zhs-battle-48.fnt",
//};
//
//// �ͻ��˶�ȡ���ؽ�ɫ���������ļ�struct
//typedef struct BaseLocalInfo
//{
//	_UINT32 order;                 //��ʾ˳��
//	_UINT32 headFlag;              //ͷ��ID 
//	bool visible;                  //�Ƿ�ɼ�
//	BaseLocalInfo(){};
//	BaseLocalInfo(_UINT32 order, _UINT32 headFlag, bool visible) :
//	order(order),
//		headFlag(headFlag),
//		visible(visible)
//	{
//
//	}
//	BaseLocalInfo& operator ()(_UINT32 order, _UINT32 headFlag, bool visible)
//	{
//		this->order = order;
//		this->headFlag = headFlag;
//		this->visible = visible;
//		return *this;
//	}
//}BaseLocalInfo;
//
//typedef struct _tagRES_FIGHT_EFFECTNAME
//{//�ͻ��˵�Ӣ�۵ı༭����
//	_UINT32 m_unID;
//	_UINT8  m_strName[32];
//
//	static const _UINT8 _MEMBER_NUM = 2;
//	//-----------------------------------------------------------------------
//	// parse call back
//	_UINT16 GetMemberInfo(_UINT16 unIndex16, _UINT8** ppMember)
//	{
//		_UINT16 unMemberSize16 = 0;
//		switch (unIndex16)
//		{
//		case 1:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_unID);
//				unMemberSize16 = sizeof(_UINT32);
//			}
//			break;
//		case 2:
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strName);
//				unMemberSize16 = sizeof(m_strName);
//			}
//			break;
//		default:
//			break;
//		}
//
//		return unMemberSize16;
//	}
//
//	_UINT16 GetMemberNum() const
//	{
//		return _MEMBER_NUM;
//	}
//
//	RESOURCE_KEY GetKey() const
//	{
//		return m_unID;
//	}
//}RES_FIGHT_EFFECTNAME, *LPRES_FIGHT_EFFECTNAME;

#endif