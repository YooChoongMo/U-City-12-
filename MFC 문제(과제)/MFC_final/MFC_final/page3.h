#pragma once
#include "afxcmn.h"


// page3 ��ȭ �����Դϴ�.

class page3 : public CPropertyPage
{
	DECLARE_DYNAMIC(page3)

public:
	page3();
	virtual ~page3();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
