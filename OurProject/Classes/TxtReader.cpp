#include <string>
#include <map>
#include <assert.h>
#include "TxtReader.h"
#include <exception>
#include <stdlib.h>

int CTxtReader::_ConvertStringToVector(const char* strStrINTgSource,std::vector< std::string >& vRet, const char* szKey, bool bOneOfKey, bool bIgnoreEmpty)
{
	vRet.clear();

	std::string strSrc = strStrINTgSource;
	if(strSrc.empty())
	{
		return 0;
	}

	std::string::size_type nLeft = 0;
	std::string::size_type nRight;
	if(bOneOfKey)
	{
		nRight = strSrc.find_first_of(szKey);
	}
	else
	{
		nRight = strSrc.find(szKey);
	}

	if(nRight == std::string::npos)
	{
		nRight = strSrc.length();
	}
	while(true)
	{
		std::string strItem = strSrc.substr(nLeft, nRight-nLeft);
		if(strItem.length() > 0 || !bIgnoreEmpty)
		{
			vRet.push_back(strItem);
		}

		if(nRight == strSrc.length())
		{
			break;
		}

		nLeft = nRight + (bOneOfKey ? 1 : strlen(szKey));

		if(bOneOfKey)
		{
			std::string strTemp = strSrc.substr(nLeft);
			nRight = strTemp.find_first_of(szKey);
			if(nRight != std::string::npos) nRight += nLeft;
		}
		else
		{
			nRight = strSrc.find(szKey, nLeft);
		}

		if(nRight == std::string::npos)
		{
			nRight = strSrc.length();
		}
	}

	return (int)vRet.size();
}

template < CTxtReader::FIELD_TYPE T>
bool CTxtReader::_FieldEqu(const FIELD& a, const FIELD& b)
{
	if(T == T_INT)
	{
		return a.iValue==b.iValue;
	}
	else if(T == T_FLOAT)
	{
		return a.fValue==b.fValue;
	}
	else
	{
		try
		{
			return (strcmp(a.pString, b.pString)==0);
		}
		catch(...)
		{
			return false;
		}
	}
}

CTxtReader::CTxtReader(unsigned int id)
{
	m_ID = id;
	m_pStringBuf = NULL;
	m_nIndexColum = -1;
}

CTxtReader::~CTxtReader()
{
	if(m_pStringBuf) delete[] m_pStringBuf;
	m_pStringBuf = NULL;
}

//���ڴ����ַ�����ȡһ���ı�(���ջ��з�)
const char* CTxtReader::_GetLineFromMemory(char* pStringBuf, int nBufSize, const char* pMemory, const char* pDeadEnd)
{
	//Ѱ����һ�����з�
	register const char* pMem = pMemory;
	if(pMem >= pDeadEnd || *pMem==0) return 0;

	while(pMem < pDeadEnd && pMem-pMemory+1<nBufSize && 
		*pMem != 0 && *pMem != '\r' && *pMem != '\n') 
		*(pStringBuf++) = *(pMem++);
	//add 'null' end
	*pStringBuf = 0;

	//skip all next \r and \n
	while(pMem < pDeadEnd && *pMem != 0 && (*pMem=='\r' || *pMem=='\n')) pMem++;

	return pMem;
}

bool CTxtReader::OpenFromMemory(const char* pMemory, const char* pDeadEnd, const char* szFileName)
{
	assert(pMemory && pDeadEnd);
	//----------------------------------------------------
	//�ж��Ƿ��Ƕ����Ƹ�ʽ
	if(pDeadEnd - pMemory >=sizeof(FILE_HEAD) && *((unsigned int*)pMemory)==0XDDBBCC00)
	{
		return OpenFromMemoryImpl_Binary(pMemory, pDeadEnd, szFileName);
	}
	else
	{
		return OpenFromMemoryImpl_Text(pMemory, pDeadEnd, szFileName);
	}
}

bool CTxtReader::OpenFromMemoryImpl_Binary(const char* pMemory, const char* pDeadEnd, const char* szFileName)
{
	register const char* pMem = pMemory;

	//----------------------------------------------------
	//Read Head
	FILE_HEAD theHead;
	memcpy(&theHead, pMem, sizeof(FILE_HEAD));
	if(theHead.m_Identify != 0XDDBBCC00 )
	{
		return false;
	}
	//check memory size
	if( sizeof(FILE_HEAD) + 
		sizeof(unsigned int)*theHead.m_nFieldsNum + 
		sizeof(FIELD)*theHead.m_nRecordsNum * theHead.m_nFieldsNum +
		theHead.m_nStringBlockSize > (unsigned int)(pDeadEnd-pMemory))
	{
		return false;
	}

	pMem += sizeof(FILE_HEAD);

	//----------------------------------------------------
	//Init 
	m_nRecordsNum = theHead.m_nRecordsNum;
	m_nFieldsNum  = theHead.m_nFieldsNum;
	m_nStringBufSize = theHead.m_nStringBlockSize;

	//---------------------------------------------
	//Create String Blok
	m_pStringBuf = new char[theHead.m_nStringBlockSize];
	if(!m_pStringBuf) return false;

	//------------------------------------------------------
	// Read Field Types
	std::vector< unsigned int > vFieldType;
	vFieldType.resize(theHead.m_nFieldsNum);
	memcpy(&(vFieldType[0]), pMem, sizeof(unsigned int)*theHead.m_nFieldsNum);
	pMem += sizeof(unsigned int)*theHead.m_nFieldsNum;

	//Check it!
	m_theType.resize(theHead.m_nFieldsNum);
	for(int i=0; i<(int)theHead.m_nFieldsNum; i++)
	{
		switch(vFieldType[i])
		{
		case T_INT:
		case T_FLOAT:
		case T_STRING:
			m_theType[i] = (FIELD_TYPE)vFieldType[i];
			break;

		default:
			delete[] (m_pStringBuf);
			return false;
		}
	}

	//------------------------------------------------------
	// Read All Field
	m_vDataBuf.resize(theHead.m_nRecordsNum * theHead.m_nFieldsNum);
	memcpy(&(m_vDataBuf[0]), pMem, sizeof(FIELD)*theHead.m_nRecordsNum * theHead.m_nFieldsNum);
	pMem += sizeof(FIELD)*theHead.m_nRecordsNum * theHead.m_nFieldsNum;

	//------------------------------------------------------
	// Read String Block
	memcpy(m_pStringBuf, pMem, m_nStringBufSize);
	m_pStringBuf[m_nStringBufSize-1]=0;

	//------------------------------------------------------
	// TO runtime address
	for(int j=0; j<(int)theHead.m_nFieldsNum; j++)
	{
		if(vFieldType[j] != T_STRING) continue;

		for(int i=0; i<(int)theHead.m_nRecordsNum; i++)
		{

			m_vDataBuf[i*GetFieldsNum()+j].pString += reinterpret_cast<unsigned long long>(m_pStringBuf);
		}
	}

	//------------------------------------------------------
	//����������
	CreateIndex(0, szFileName);

	return true;
}

bool CTxtReader::OpenFromMemoryImpl_Text(const char* pMemory, const char* pDeadEnd, const char* szFileName)
{
	//----------------------------------------------------
	//��������������
	char szLine[1024*10] = {0};
	//����һ��
	int unOffset = 0;
	if ((unsigned char)*(pMemory) == 0xEF && (unsigned char)*(pMemory + 1) == 0XBB && (unsigned char)*(pMemory + 2) == 0XBF)
	{//EFBBBF
		unOffset = 3;
	}
	register const char* pMem = pMemory+unOffset;//�����ļ�ǩ��
	pMem = _GetLineFromMemory(szLine, 1024*10, pMem, pDeadEnd);
	if(!pMem) return false;

	//�ֽ�
	std::vector< std::string > vRet;
	_ConvertStringToVector(szLine, vRet, "\t", true, true);
	if(vRet.empty()) return false;
	//����Field Types
	FILEDS_TYPE vFieldsType;
	vFieldsType.resize(vRet.size());

	for(int i=0; i<(int)vRet.size(); i++) 
	{
		//printf("Data Type:%s\n", vRet[i].c_str());
		if(vRet[i] == "INT") vFieldsType[i] = T_INT;
		else if(vRet[i] == "FLOAT") vFieldsType[i] = T_FLOAT;
		else if(vRet[i] == "STRING") vFieldsType[i] = T_STRING;
		else
		{
			return false;
		}
	}

	//--------------------------------------------------------------
	//��ʼ��
	int nRecordsNum = 0;
	int nFieldsNum = (int)vFieldsType.size();

	//��ʱ�ַ�����
	std::vector< std::pair< std::string, int > > vStringBuf;
	//������
	std::map< std::string, int >     mapStringBuf;

	//--------------------------------------------------------------
	//��ʼ��ȡ

	//�ն�һ��
	pMem = _GetLineFromMemory(szLine, 1024*10, pMem, pDeadEnd);
	if(!pMem) return false;

	int nStringBufSize = 0;
	do
	{
		//��ȡһ��
		pMem = _GetLineFromMemory(szLine, 1024*10, pMem, pDeadEnd);
		if(!pMem) break;;

		//�Ƿ���ע����
		if(szLine[0] == '#') continue;

		//�ֽ�
		_ConvertStringToVector(szLine, vRet, "\t", true, false);

		//��������
		if(vRet.empty()) continue;
		if((int)vRet.size() != nFieldsNum) 
		{
			//���Ͽո�
			if((int)vRet.size() < nFieldsNum)
			{
				int nSubNum = nFieldsNum-(int)vRet.size();
				for(int i=0; i<nSubNum; i++)
				{
					vRet.push_back("");
				}
			}
		}

		//��һ�в���Ϊ��
		if(vRet[0].empty()) continue;

		for(register int i=0; i<nFieldsNum; i++)
		{
			FIELD newField;
			switch(vFieldsType[i])
			{
			case T_INT:
				newField.iValue = atoi(vRet[i].c_str());
				m_vDataBuf.push_back(newField);
				break;

			case T_FLOAT:
				newField.fValue = (float)atof(vRet[i].c_str());
				m_vDataBuf.push_back(newField);
				break;

			case T_STRING:
				if(vRet[i].empty())
				{
					newField.iValue = 0;
				}
				else
				{
					// const char * p = vRet[i].c_str();
					std::map< std::string, int >::iterator it = mapStringBuf.find(vRet[i]);
					if(it == mapStringBuf.end())
					{
						vStringBuf.push_back(std::make_pair(vRet[i], nStringBufSize));
						mapStringBuf.insert(std::make_pair(vRet[i], (int)vStringBuf.size()-1));
						newField.iValue = nStringBufSize + 1; // first char is '\0' for blank string

						nStringBufSize += (int)strlen(vRet[i].c_str()) + 1;
					}
					else
					{
						newField.iValue = vStringBuf[it->second].second + 1;
					}
				}

				m_vDataBuf.push_back(newField);
				break;
			}
		}

		nRecordsNum++;
	}while(true);

	//--------------------------------------------------------
	//������ʽ���ݿ�
	m_nRecordsNum = nRecordsNum;
	m_nFieldsNum  = nFieldsNum;
	m_nStringBufSize = nStringBufSize+1;

	//Create String Blok
	m_pStringBuf = new char[m_nStringBufSize];
	if(!m_pStringBuf) return false;

	//------------------------------------------------------
	// Create Field Types
	m_theType = vFieldsType;

	//------------------------------------------------------
	// Create String Block
	//unsigned char byBlank = '\0';
	m_pStringBuf[0] = '\0';

	register char* p = m_pStringBuf + 1;
	for(int i=0; i<(int)vStringBuf.size(); i++)
	{
		memcpy(p, vStringBuf[i].first.c_str(), vStringBuf[i].first.size()); 
		p += vStringBuf[i].first.size();

		*(p++) = '\0';
	}

	//------------------------------------------------------
	// Relocate String Block
	for(register int i=0; i<nFieldsNum; i++)
	{
		if(vFieldsType[i] != T_STRING) continue;

		for(register int j=0; j<nRecordsNum; j++)
		{
			FIELD& theField = m_vDataBuf[j*nFieldsNum+i];
			theField.pString = m_pStringBuf + theField.iValue;
		}
	}

	//------------------------------------------------------
	//����������
	CreateIndex(0, szFileName);

	return true;
}

bool CTxtReader::OpenFromTXT(const char* szFileName)
{
	assert(szFileName);

	//----------------------------------------------------
	//���ļ�
	FILE* fp = fopen(szFileName, "rb");
	if(NULL == fp) return false;

	fseek(fp, 0, SEEK_END);
	int nFileSize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	//�����ڴ�
	char* pMemory = new char[nFileSize+1];
	fread(pMemory, 1, nFileSize, fp);
	pMemory[nFileSize] = 0;

	bool bRet = OpenFromMemory(pMemory, pMemory+nFileSize+1, szFileName);

	delete[] pMemory; pMemory = 0;
	fclose(fp);
	return bRet;
}

void CTxtReader::CreateIndex(int nColum, const char* szFileName)
{
	szFileName;

	if(nColum <0 || nColum >= m_nFieldsNum || m_nIndexColum==nColum) return;

	m_mapIndex.clear();

	for(int i=0; i<(int)m_nRecordsNum; i++)
	{
		FIELD* p = &(m_vDataBuf[i*m_nFieldsNum]);

		FIELD_MAP::iterator itFind = m_mapIndex.find(p->iValue);
		if (itFind != m_mapIndex.end())
		{
			//char szTemp[260];
			//sprintf(szTemp, 260, "[%s]Multi index at line %d(SAME:value=%d)", szFileName, i+1, p->iValue);
#ifdef GAME_CLIENT
			throw std::string(szTemp);
#else
			//AssertEx(false,szTemp);
#endif
			return;
		}
		m_mapIndex.insert(std::make_pair(p->iValue, p));
	}
}

const CTxtReader::FIELD* CTxtReader::Search_Index_EQU(int iIndex) const
{
	FIELD_MAP::const_iterator itFind = m_mapIndex.find(iIndex);
	if (itFind == m_mapIndex.end()) return NULL;

	return itFind->second;
}

const CTxtReader::FIELD* CTxtReader::Search_Posistion(int nRecordLine, int nColumNum) const
{
	int nPosition = nRecordLine*GetFieldsNum() + nColumNum;

	if(nPosition <0 || nPosition >= (int)m_vDataBuf.size()) 
	{
		// char szTemp[260];
		// tsnprintf(szTemp, MAX_FILE_PATH, "DBC:Invalid search request[rec=%d, col=%d]", nRecordLine, nColumNum);
#ifdef GAME_CLIENT
		throw std::string(szTemp);
#else
		// AssertEx(false, szTemp);
#endif
		return NULL;
	}

	return &(m_vDataBuf[nPosition]);
}

const CTxtReader::FIELD_TYPE CTxtReader::Search_Posistion_FieldType(int nColumNum) const
{
	int nPosition = nColumNum;

	if (nPosition < 0 || nPosition >= (int)m_theType.size())
	{
		char szTemp[260];
		sprintf(szTemp, "DBC:Invalid search request[col=%d]", nColumNum);
		return T_NULL;
	}

	return m_theType[nPosition];
}

//����ĳ�е���ָ��ֵ�ĵ�һ��
const CTxtReader::FIELD* CTxtReader::Search_First_Column_Equ(int nColumnNum, const FIELD& value) const
{
	if(nColumnNum < 0 || nColumnNum >= m_nFieldsNum) return 0;
	FIELD_TYPE type = m_theType[nColumnNum];

	for(register int i=0; i<m_nRecordsNum; i++)
	{
		const FIELD& theField = m_vDataBuf[m_nFieldsNum*i + nColumnNum];

		bool bRet;
		if(T_INT == type) 
			bRet = _FieldEqu<T_INT>(theField, value);
		else if(T_FLOAT == type)
			bRet = _FieldEqu<T_FLOAT>(theField, value);
		else
			bRet = _FieldEqu<T_STRING>(theField, value);

		if(bRet) return &(m_vDataBuf[m_nFieldsNum*i]);
	}

	return 0;
}