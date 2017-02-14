#pragma once
#include "afxcmn.h"


// page1 대화 상자입니다.

class page1 : public CPropertyPage
{
	DECLARE_DYNAMIC(page1)

public:
	page1();
	virtual ~page1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString prodName;
	CListCtrl mylistcon1;
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();

	void listView();
	afx_msg void OnBnClickedButton2();
	
};
