#include "stdafx.h"
#include "mySheet.h"
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"

mySheet::mySheet()
{
	AddPage(&MyPage1);
	AddPage(&MyPage2);
	AddPage(&MyPage3);

}


mySheet::~mySheet()
{
}
