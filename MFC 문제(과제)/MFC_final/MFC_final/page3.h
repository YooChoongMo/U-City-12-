#pragma once
#include "afxcmn.h"


// page3 대화 상자입니다.

class page3 : public CPropertyPage
{
	DECLARE_DYNAMIC(page3)

public:
	page3();
	virtual ~page3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mylistCon4;
	CListCtrl mylistCon5;
	CString myEdit2;
	virtual BOOL OnInitDialog();

	void listView1();
	void listView2();

	int Subject_Code;
	void write(CString title);
	void Read(CString title);

	afx_msg void OnBnClickedButton1();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton4();
};
