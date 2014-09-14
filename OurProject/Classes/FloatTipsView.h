#ifndef __FLOAT_TIPS_VIEW_H__
#define __FLOAT_TIPS_VIEW_H__
#include "GameUILayer.h"
//#include "StructProgramInResource.h"

class FloatTipsView : public GameUILayer
{
	UI_SIMPLE_CREATE_CLASS(FloatTipsView, UI_NULL);

	enum TAG_FLOATTIPSVIEW
	{
		TAG_FLOATTIPSVIEW_BACK = 11,
		TAG_FLOATTIPSVIEW_INFO = 111,

	};
	CC_SYNTHESIZE(UIImageView*, m_pImgBack, ImgBack);
	CC_SYNTHESIZE(UILabel*, m_pInfo, Info);

public:
	void InitView(const char* pStr = NULL);

	static FloatTipsView* AddFloatTipsView(const char* pStr);
	void update(float delta);
private:
	float m_fTimeLost;
	
};


#endif // __FLOAT_TIPS_VIEW_H__