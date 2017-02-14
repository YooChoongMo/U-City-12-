#pragma once
#include "afxdlgs.h"
#include "Page1.h"
#include "Page2.h"
#include "Page3.h"


class mySheet :
	public CPropertySheet
{
public:
	mySheet();
	~mySheet();
	page1 MyPage1;
	page2 MyPage2;
	page3 MyPage3;



};

