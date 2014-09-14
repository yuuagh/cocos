
#ifndef Client_ParserManager_h
#define Client_ParserManager_h

#include <memory>
#include <string>
//#include "Parser.h"
//#include "StructProgramInResource.h"
//#include "GameStruct.h"

class ParserManager
{
public:
	ParserManager();
	~ParserManager();

	static ParserManager* singleton(void);

	bool                        Init();
	void                        Release();
	bool                        Load(const std::string& strFileName);

private:

	/*RESDATA_DEFINITION(RES_VIP_LEVEL_POWER);
	RESDATA_DEFINITION(RES_VIP_STORE);
	RESDATA_DEFINITION(RES_MAKEITEM);
	RESDATA_DEFINITION(RES_MAKECOST);
	RESDATA_DEFINITION(RES_WEEK_DOING);*/
};

//#define GETRESBATTLEDATA(ID) ParserManager::singleton()->Get_RES_BATTLE_Data(ID)
#endif // Client_ParserManager_h