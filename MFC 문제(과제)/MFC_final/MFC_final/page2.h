#pragma once
#include "afxcmn.h"


// page2 ��ȭ �����Դϴ�.

class page2 : public CPropertyPage
{
	DECLARE_DYNAMIC(page2)

public:
	page2();
	virtual ~page2();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl mylistCon2;
	CListCtrl mylistCon3;
	void listView1();
	void listView2();
	afx_msg void OnBnClickedButton2();
	
	afx_msg void OnCbnDropdownCombo1();
	CString combo1;
	afx_msg void OnCbnDropdownCombo2();
	afx_msg void OnCbnDropdownCombo3();
	afx_msg void OnCbnDropdownCombo4();
	afx_msg void OnCbnSelendokCombo1();
	afx_msg void OnBnClickedButton1();

	int Subject_Code;
	int Max_num;
	CString Date;
	CString Time;
	int Count;          //�ü�
	bool student_flag;



	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnCbnSelendokCombo2();
	afx_msg void OnCbnSelendokCombo3();
	afx_msg void OnCbnSelendokCombo4();
	afx_msg void OnBnClickedButton3();
	CString myEdit;

	void write(CString title);
	void Read(CString title);


};
