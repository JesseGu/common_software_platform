// Model1Observer1.cpp: implementation of the CModel1Observer1 class.
//
//////////////////////////////////////////////////////////////////////

#include "Model1Observer1.h"
#include "MyModel1.h"

void CModel1Observer1::UpdateData(CSpxModel* pModel)
{
	CAwsString str;
	str.LoadString(((CMyModel1*)pModel)->GetData());

	SetText(str, true);
}
