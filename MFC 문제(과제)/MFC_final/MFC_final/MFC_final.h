
// MFC_final.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.
#include "Subject_array.h"


// CMFC_finalApp:
// �� Ŭ������ ������ ���ؼ��� MFC_final.cpp�� �����Ͻʽÿ�.
//

class CMFC_finalApp : public CWinApp
{
public:
	CMFC_finalApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	Subject_array sa;
	Subject_array op;

	DECLARE_MESSAGE_MAP()
};

extern CMFC_finalApp theApp;