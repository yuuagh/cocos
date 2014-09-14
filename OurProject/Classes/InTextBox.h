#ifndef __INTEXTBOX_H__
#define __INTEXTBOX_H__
#include "GameUILayer.h"
//#include "StructProgramInResource.h"

class InTextBox : public GameUILayer
{
	UI_SIMPLE_CREATE_CLASS(InTextBox, UI_NULL);



public:
	void InitView();

	static InTextBox* AddFloatTipsView();


};


#endif // __FLOAT_TIPS_VIEW_H__