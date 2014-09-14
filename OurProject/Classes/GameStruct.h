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
//{//客户端场景状态
//	CSS_NORMAL = 0,  //普通状态
//	CSS_READY_FIGHTING,   //准备战斗
//	CSS_FIGHTING,      //战斗状态
//};
//
//// #pragma mark -
//// #pragma mark light
//enum ELightType
//{//光效类型
//	LT_NORMAL           = 0,    //普通
//	LT_HERO_BEENATTACK  = 1,    //英雄身上的被击光效
//	LT_FLY_OBJ          = 2,    //飞行对象光效
//	LT_BUFFER           = 3,    //buffer光效
//	LT_DROPTHING        = 4,    //掉落物品光效
//	LT_DEADTH           = 5,    //死亡光效
//	// LT_DROP_MONEY       = 6,    //掉落金钱
//	LT_GUI              = 6,    //界面光效
//	LT_JOINT            = 7,    //连接两个物品的光效
//	LT_BUTTON           = 8,    //按钮光效
//	LT_DAMAGE_NUMBER    = 9,    //伤害数值光效
//	LT_ANGER            = 10,
//	LT_NORMALLOOP  = 11,   //普通循环播放
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
//	CLIENTSKILL_CFG_ANINAME,//  STRING 动作名 attack1
//	CLIENTSKILL_CFG_ANISOUND,//  STRING 动作音效 0
//	CLIENTSKILL_CFG_FLYEFFECT,//  STRING 飞行特效 0
//	CLIENTSKILL_CFG_FLYSOUND,//  STRING 飞行音效 0
//	CLIENTSKILL_CFG_AREAEFFECT,//  STRING 范围特效 0
//	CLIENTSKILL_CFG_AREASOUND,//  STRING 范围音效 0
//	CLIENTSKILL_CFG_SCREENEFFECT,//  STRING 全屏特效 0
//	CLIENTSKILL_CFG_SCREENSOUND,//  STRING 全屏音效 0
//	CLIENTSKILL_CFG_AIMEFFECT,//  STRING 击中特效 hitlight_tangseng_huoqiu
//	CLIENTSKILL_CFG_AIMSOUND,//  STRING 击中音效 0
//
//	CLIENTSKILL_CFG_MAX
//};
//
//enum CLIENTSKILL_SHAKE_DATA
//{
//	CLIENTSKILL_SHAKE_TIME1,//  INT 震屏时间1 0
//	CLIENTSKILL_SHAKE_RANGE1,//  INT 震屏幅度1 0
//	CLIENTSKILL_SHAKE_TIME2,//  INT 震屏时间1 0
//	CLIENTSKILL_SHAKE_RANGE2,//  INT 震屏幅度1 0
//	CLIENTSKILL_SHAKE_TIME3,//  INT 震屏时间1 0
//	CLIENTSKILL_SHAKE_RANGE3,//  INT 震屏幅度1 0
//
//	CLIENTSKILL_SHAKE_MAX
//};
//typedef struct _tagRES_CLIENT_SKILL
//{//客户端技能文件，主要是描述信息，和技能音效，光效配置文件
//	_UINT32     m_unSkillId;                //技能id
//	_UINT32  m_unPrepareTime;//  FLOAT 准备时间 1.3
//	_UINT32  m_unFlyStartTime;//  FLOAT 飞行开始时间 1.3
//	_UINT32  m_unFlyEndTime;//  FLOAT 飞行结束时间 1.7
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
//		case 5+CLIENTSKILL_CFG_ANINAME://  STRING 动作名 attack1
//		case 5 + CLIENTSKILL_CFG_ANISOUND://  STRING 动作音效 0
//		case 5 + CLIENTSKILL_CFG_FLYEFFECT://  STRING 飞行特效 0
//		case 5 + CLIENTSKILL_CFG_FLYSOUND://  STRING 飞行音效 0
//		case 5 + CLIENTSKILL_CFG_AREAEFFECT://  STRING 范围特效 0
//		case 5 + CLIENTSKILL_CFG_AREASOUND://  STRING 范围音效 0
//		case 5 + CLIENTSKILL_CFG_SCREENEFFECT://  STRING 全屏特效 0
//		case 5 + CLIENTSKILL_CFG_SCREENSOUND://  STRING 全屏音效 0
//		case 5 + CLIENTSKILL_CFG_AIMEFFECT://  STRING 击中特效 hitlight_tangseng_huoqiu
//		case 5 + CLIENTSKILL_CFG_AIMSOUND://  STRING 击中音效 0
//			{
//				*ppMember = reinterpret_cast<_UINT8*>(&m_strConfigName[unIndex16 - 5 - CLIENTSKILL_CFG_ANINAME]);
//				unMemberSize16 = sizeof(m_strConfigName[CLIENTSKILL_CFG_ANINAME]);
//			}
//			break;
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_TIME1://  INT 震屏时间1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_RANGE1://  INT 震屏幅度1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_TIME2://  INT 震屏时间1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_RANGE2://  INT 震屏幅度1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_TIME3://  INT 震屏时间1 0
//		case 5 + CLIENTSKILL_CFG_MAX + CLIENTSKILL_SHAKE_RANGE3://  INT 震屏幅度1 0
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
//{//状态效果表现
//	_UINT32     m_unStatusTexID;            //状态文字id
//	_UINT8      m_strStatusName[32];        //状态名称
//	_UINT8      m_strStatusText1[32];       //状态描述文字1
//	_UINT32     m_unStatusIcon1;            //状态是否有箭头图标1
//	_UINT32     m_unStatusCorlor1;          //状态文字颜色字体1
//	_UINT8      m_strStatusText2[32];       //状态描述文字2
//	_UINT32     m_unStatusIcon2;            //状态是否有箭头图标2
//	_UINT32     m_unStatusCorlor2;          //状态文字颜色字体2
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
//{//客户端英雄效果数据，主要是被击音效，光效配置文件
//	_UINT32     m_unHeroID;                 //英雄id
//	_UINT8      m_strBeenAttLight[32];      //攻击被击光效
//	_UINT8      m_strBeenAttSound[32];      //攻击被击音效
//	_UINT8      m_strDeadSound[32];         //死亡音效
//	_INT32      m_unScale;                  //缩放比例
//	_UINT8      m_strSoundStartFly8[32];    //起飞08动作
//	_UINT8      m_strSoundEndFly7[32];      //落地07动作
//	_UINT8      m_strSoundEndFly9[32];      //落地09动作
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
//{//客户端英雄站位数据
//	_UINT32     m_unPtID;          //坐标id
//	_INT32     m_unPtX;           //x坐标
//	_INT32     m_unPtY;           //y坐标
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
//{//客户端英雄效果数据，主要是被击音效，光效配置文件
//	_UINT32     m_unSceneID;                //场景id
//	_UINT8      m_strBgMusic[32];           //背景音乐
//	_UINT8      m_strBgSound1[32];          //背景音效1
//	_UINT8      m_strBgSound2[32];          //背景音效2
//	_UINT8      m_strShakeLight1[32];       //震动光效1
//	_UINT8      m_strShakeLight2[32];       //震动光效2
//	_UINT8      m_strShakeSound1[32];       //震动音效1
//	_UINT8      m_strShakeSound2[32];       //震动音效2
//	_UINT8      m_strBossBgm[32];           //boss关背景音乐
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
//	HELP_PLAYER_INFO   = 1  ,   //玩家属性
//	HELP_HERO_INFO       ,   //英雄相关
//	HELP_WAR_INFO        ,   //战役相关
//	HELP_ZH_INFO         ,   //战魂相关
//	HELP_TASK_INFO       ,   //任务
//	HELP_FRIEND_INFO     ,   //好友
//	HELP_PK_INFO         ,   //竞技场
//	HELP_MALL_INFO       ,   //商城
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
//// 客户端读取本地角色基本配置文件struct
//typedef struct BaseLocalInfo
//{
//	_UINT32 order;                 //显示顺序
//	_UINT32 headFlag;              //头像ID 
//	bool visible;                  //是否可见
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
//{//客户端的英雄的编辑数据
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