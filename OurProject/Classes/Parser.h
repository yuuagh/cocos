#ifndef __PARSER_H__
#define __PARSER_H__


#include "Common.h"
#include <map>
//#include "SLKReader.h"
#include "iostream"
#include "TxtReader.h"
using namespace std;



#define RESDATA_DEFINITION(RES_CLASS) private:\
	std::auto_ptr< Parser<RES_CLASS> > m_p##RES_CLASS; \
	std::string       m_str_##RES_CLASS; \
public:\
	const RES_CLASS* Get_##RES_CLASS##_Data(_UINT32 unID) const\
{\
	if (m_p##RES_CLASS->GetSize() == 0)\
{\
	m_p##RES_CLASS->Init(m_str_##RES_CLASS); \
}\
	return (RES_CLASS*)m_p##RES_CLASS->FindData(unID); \
}\
	const RES_CLASS* Get_##RES_CLASS##_DataByIndex(_UINT32 unIndex) const\
{\
	if (m_p##RES_CLASS->GetSize() == 0)\
{\
	m_p##RES_CLASS->Init(m_str_##RES_CLASS); \
}\
	return (RES_CLASS*)m_p##RES_CLASS->FindDataByIndex(unIndex); \
}\
	_UINT32 Get_##RES_CLASS##_Size()\
{\
	return m_p##RES_CLASS->GetSize(); \
}\
	bool Init_##RES_CLASS##_Data()\
{\
	return m_p##RES_CLASS->Init(m_str_##RES_CLASS); \
}\
	const Parser<RES_CLASS> *const Get_##RES_CLASS##_Ptr() const\
{\
	if (m_p##RES_CLASS->GetSize() == 0)\
{\
	m_p##RES_CLASS->Init(m_str_##RES_CLASS); \
}\
	return m_p##RES_CLASS.get(); \
}

#define INIT_RES_CLASS_PTR(RES_CLASS,FILENAME)  m_p##RES_CLASS(new Parser<RES_CLASS>()),m_str_##RES_CLASS(FILENAME)

#define RELEASE_RES_CLASS_PTR(RES_CLASS) m_p##RES_CLASS->Release();




template<typename T, typename _Compare = std::less<RESOURCE_KEY> >
class Parser
{
public:
	Parser();
	~Parser();

	bool Init(const string& rStrResourceName, bool bReload = false);
	void Release();
	bool Reload();
	const T* const    FindData(_UINT32 keyResource) const;
	const T* const    FindDataByIndex(_UINT32 unIndex) const;
	T* const     FindDataByIndexNotConst(_UINT32 unIndex) const;
	_UINT32      GetSize() const;

	template <class Operation>
	void      ForEach(Operation& rOperation) const
	{
		MAP_RESOURCE_ITOR Itor = m_mapT.begin();
		for (;Itor != m_mapT.end();++Itor)
		{
			rOperation((*Itor).second);
		}
	}
private:
	string   m_strResourceName;

	typedef std::map<_UINT32, T*, _Compare> MAP_RESOURCE;
	typedef typename MAP_RESOURCE::const_iterator MAP_RESOURCE_ITOR;
	MAP_RESOURCE                m_mapT;
};


template<typename T, typename _Compare >
Parser<T, _Compare>::Parser()
	:m_strResourceName("")
{
	m_mapT.clear();
}


template<typename T, typename _Compare >
Parser<T, _Compare>::~Parser()
{
	Release();
}

template<typename T, typename _Compare >
const T* const Parser<T, _Compare>::FindData( _UINT32 keyResource ) const
{
	MAP_RESOURCE_ITOR Itor = m_mapT.find(keyResource);
	if (Itor != m_mapT.end())
	{
		return (*Itor).second;
	}
	return NULL;
}

template<typename T, typename _Compare >
const T* const Parser<T, _Compare>::FindDataByIndex(_UINT32 unIndex) const
{
	_UINT32 unTmpIndex = 0;

	MAP_RESOURCE_ITOR Itor = m_mapT.begin();
	for (;Itor != m_mapT.end();++Itor)
	{
		if(unTmpIndex==unIndex)
		{
			return (*Itor).second;
		}
		unTmpIndex++;
	}

	return NULL;
}

template<typename T, typename _Compare >
T* const Parser<T, _Compare>::FindDataByIndexNotConst(_UINT32 unIndex) const
{
	_UINT32 unTmpIndex = 0;

	MAP_RESOURCE_ITOR Itor = m_mapT.begin();
	for (;Itor != m_mapT.end();++Itor)
	{
		if(unTmpIndex==unIndex)
		{
			return (*Itor).second;
		}
		unTmpIndex++;
	}

	return NULL;
}

template<typename T, typename _Compare >
_UINT32 Parser<T, _Compare>::GetSize() const
{
	return m_mapT.size();
}

template<typename T, typename _Compare >
bool Parser<T, _Compare>::Reload()
{
	return Init(true);
}

template<typename T, typename _Compare >
void Parser<T, _Compare>::Release()
{
	if (!m_mapT.empty())
	{
		for (MAP_RESOURCE_ITOR Itor = m_mapT.begin();
			Itor != m_mapT.end();
			++Itor)
		{
			T* pT = (*Itor).second;
			delete pT;
		}

		m_mapT.clear();
	}
}

template<typename T, typename _Compare >
bool Parser<T, _Compare>::Init( const string& rStrResourceName, bool bReload )
{
	if (!bReload)
	{
		Release();
	}

	m_strResourceName = "../resources/";

	m_strResourceName += rStrResourceName;

	if((-1==m_strResourceName.find(".slk") && -1==m_strResourceName.find(".txt")))
	{
		m_strResourceName += ".txt";
	}

	m_strResourceName = cocos2d::CCFileUtils::sharedFileUtils()->fullPathForFilename(m_strResourceName.c_str());

	CTxtReader ThirdFile(0);
	if (!ThirdFile.OpenFromTXT(m_strResourceName.c_str()))
	{
		printf("Error to Read Data File(%s)\n", m_strResourceName.c_str());
		return false;
	}

	//
	int iTableCount = ThirdFile.GetRecordsNum();
	int iColumnCount = ThirdFile.GetFieldsNum();
	//第一行：数据类型
	//第二行：字段名称
	for (int i = 0; i < iTableCount; i++)
	{
		T* pT = new T();
		if (NULL == pT)
		{
			continue;
		}

		if (iColumnCount >(pT->GetMemberNum()))
		{
			iColumnCount = pT->GetMemberNum();
		}

		for (_UINT16 j = 0; j < iColumnCount; j++)
		{
			_UINT8* pMember = NULL;
			_UINT16 unMemberSize = pT->GetMemberInfo(j+1, &pMember);//与slk同步移植，下标从1开始
			if (0 == unMemberSize || NULL == pMember)
			{
				continue;
			}

			const CTxtReader::FIELD* pField = ThirdFile.Search_Posistion(i, j);
			if (!pField)
			{
				continue;
			}

			const CTxtReader::FIELD_TYPE enType = ThirdFile.Search_Posistion_FieldType(j);
			switch (enType)
			{
			case CTxtReader::T_INT: //整数
				{
					_INT32 nValue = pField->iValue;
					memcpy(pMember, &nValue, unMemberSize);
				}
				break;
			case CTxtReader::T_FLOAT://浮点数
				{
					_FLOAT_32 fValue = pField->fValue;
					//_INT32 nTmpVal = (_INT32)fValue;
					memcpy(pMember, &fValue, unMemberSize);
				}
				break;
			case CTxtReader::T_STRING://字符串
				{
					std::string strValue = pField->pString;
					_UINT32 nLength = unMemberSize - 1;
					if (strValue == "0")
					{
						strValue = "";
					}
					if (strValue.length() < nLength)
					{
						nLength = static_cast<_UINT16>(strValue.length());
					}

					memcpy(pMember, strValue.c_str(), nLength);
					pMember[nLength] = '\0';
				}
				break;
			default:
				{
					printf("Error Data Type(%s)\n",rStrResourceName.c_str());
				}
				break;
			}
		}

		MAP_RESOURCE_ITOR Itor = m_mapT.find(pT->GetKey());
		if (Itor == m_mapT.end())
		{
			m_mapT.insert(make_pair(pT->GetKey(), pT));
		}
		else
		{
			T* const pPrveT = (*Itor).second;
			if (NULL != pPrveT)
			{
				*pPrveT = *pT;
				delete pT;
				pT = NULL;
			}
		}
	}

	return true;
}



#endif // __PARSER_H__
