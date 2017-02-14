// page2.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFC_final.h"
#include "page2.h"
#include "afxdialogex.h"

#include "Subject_array.h"

#include "Open_subject2.h"
#include "Subject.h"

// page2 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(page2, CPropertyPage)

page2::page2()
	: CPropertyPage(IDD_DIALOG2)
	, combo1(_T(""))
	, myEdit(_T(""))
{

}

page2::~page2()
{
}

void page2::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mylistCon2);
	DDX_Control(pDX, IDC_LIST2, mylistCon3);
	DDX_CBString(pDX, IDC_COMBO1, combo1);
	DDX_Text(pDX, IDC_EDIT1, myEdit);
}


BEGIN_MESSAGE_MAP(page2, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON2, &page2::OnBnClickedButton2)
	
	ON_CBN_DROPDOWN(IDC_COMBO1, &page2::OnCbnDropdownCombo1)
	ON_CBN_DROPDOWN(IDC_COMBO2, &page2::OnCbnDropdownCombo2)
	ON_CBN_DROPDOWN(IDC_COMBO3, &page2::OnCbnDropdownCombo3)
	ON_CBN_DROPDOWN(IDC_COMBO4, &page2::OnCbnDropdownCombo4)
	ON_CBN_SELENDOK(IDC_COMBO1, &page2::OnCbnSelendokCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &page2::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &page2::OnLvnItemchangedList1)
	ON_CBN_SELENDOK(IDC_COMBO2, &page2::OnCbnSelendokCombo2)
	ON_CBN_SELENDOK(IDC_COMBO3, &page2::OnCbnSelendokCombo3)
	ON_CBN_SELENDOK(IDC_COMBO4, &page2::OnCbnSelendokCombo4)
	ON_BN_CLICKED(IDC_BUTTON3, &page2::OnBnClickedButton3)
END_MESSAGE_MAP()


// page2 �޽��� ó�����Դϴ�.


BOOL page2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	char *str[2] = { "�����ڵ�", "�����"};
	int colW[2] = { 60, 150 };

	LVCOLUMN cols;  //
	cols.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//����, �����׺�, �ؽ�Ʈ, ���α��� => ������ ���� �ҰŶ�� ����
	cols.fmt = LVCFMT_CENTER; //��� ����
	

	for (int i = 0; i < 2; i++) 
	{
		cols.pszText = str[i];
		cols.iSubItem = i;
		cols.cx = colW[i];  //���� �÷��� ����
		mylistCon2.InsertColumn(i, &cols); //�÷��� �߰�(i��° index���ٰ�)
	}

	LVCOLUMN cols2;  //�÷� ��ü�� �ϳ� ����
	cols2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//����, �����׺�, �ؽ�Ʈ, ���α��� => ������ ���� �ҰŶ�� ����
	cols2.fmt = LVCFMT_CENTER;
	//LVCFMT_LEFT; //���� ����

	for (int i = 0; i < 2; i++) 
	{
		cols2.pszText = str[i];
		cols2.iSubItem = i;
		cols2.cx = colW[i];  //���� �÷��� ����
		mylistCon3.InsertColumn(i, &cols2); //�÷��� �߰�(i��° index���ٰ�)
	}

	listView1();      //�ʱ�ȭ��  =>  ��ϵ� ���� �����ֱ�

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void page2::listView1()  //����Ʈ ��Ʈ�� ������ ���ִ� �Լ�!!
{
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();
	//AfxGetApp�� WinAPP���� �������°Ŷ� CMFCtapApp���� ���� Ŭ������ �����̴�.
	//�׷��� �ٿ�ĳ�������� �տ� �ٿ��ذ�!!
	//wh��ü�� MFCtap.cpp�� ������༭ �������� ���Ѱ���
	char buf[50] = "";

	LVITEM item;
	item.mask = LVIF_TEXT;
	mylistCon2.DeleteAllItems();

	for (int i = 0; i < data.GetSize(); i++)
	{
		item.iItem = i;
		item.iSubItem = 0;
		sprintf(buf, "%d", data.GetAt(i).getCode());
		item.pszText = buf;
		mylistCon2.InsertItem(&item);

		item.iSubItem = 1;
		sprintf(buf, "%s", data.GetAt(i).getName());
		item.pszText = buf;
		mylistCon2.SetItem(&item);
	}
}

void page2::listView2()
//������ ��� ����� / List_data�� ������ ���� ����� �迭**
{
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();
	CArray<Open_subject2> &List_data = ((CMFC_finalApp*)AfxGetApp())->op.getList_data();

	char buf[50] = "";
	LVITEM item;
	item.mask = LVIF_TEXT;
	mylistCon3.DeleteAllItems();

	for (int i = 0; i < List_data.GetSize(); i++)
	{

		int idx = ((CMFC_finalApp*)AfxGetApp())->sa.search(List_data.GetAt(i).getCd());

		item.iItem = i;
		item.iSubItem = 0;
		sprintf(buf, "%d", List_data.GetAt(i).getCd());
		item.pszText = buf;
		mylistCon3.InsertItem(&item);

		item.iSubItem = 1;
		sprintf(buf, "%s", data.GetAt(idx).getName());
		item.pszText = buf;
		mylistCon3.SetItem(&item);
	}
}

void page2::OnBnClickedButton2()  //���� ��ư
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	listView1();
}

void page2::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)  //����ũ ��Ʈ�� Ŭ��
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	POSITION pos = mylistCon2.GetFirstSelectedItemPosition();
	int idx = mylistCon2.GetNextSelectedItem(pos);

	CString tmp;
	tmp = mylistCon2.GetItemText(idx, 0);  //0���� �����ڵ�
	Subject_Code = _ttoi(tmp);
	//������Ʈ �ڵ忡 ���� ����Ʈ���� Ŭ���� ������ �����ڵ� �־���.

	*pResult = 0;
}

void page2::OnBnClickedButton1()  //���� ��ư
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	
	int idx = ((CMFC_finalApp*)AfxGetApp())->sa.search(Subject_Code);  
	//Ŭ���� ������ �����ڵ带 idx�� ����
	Subject s = ((CMFC_finalApp*)AfxGetApp())->sa.getData().GetAt(idx);
	//�� �ε��� �ڸ��� �ִ� ������ ��ȯ!
	//==> ���� Ŭ���� ���� ��ü ������ �� ����   sa.getData().SetAt(idx)���� �ٲ�ġ�� �ϱ�

	
	/////////////////////////////////  ���ǰ�ȹ �ؽ�Ʈ ���� ����
	CString title = "";
	CString str = "";
	str.Format("%d", Subject_Code);
	title = "C:/text/" + str;

	write(title);  //���ǰ�ȹ�� �ۼ��� �ؽ�Ʈ ���� ���� ("C:/text/" ������)

	Open_subject2 o(Subject_Code, Max_num, Date, Time, Count, title);
	//Ŭ���� �����ڵ�, �޺��ڽ����� ������ �׸��� ������� �ʱ�ȭ!

	((CMFC_finalApp*)AfxGetApp())->op.addOpen_Subject1(o);
	//���� �Էµ� open��ü => OpenLIst �迭�� �߰�.
	
	s.setOpen_subject2(o);  //���� �Էµ� open��ü =>  subject ��ü ������ ����
	s.setFlag(true);       //���� => true �ٲ��ش�.

	((CMFC_finalApp*)AfxGetApp())->sa.getData().SetAt(idx, s);   
	//o��ü ������ s��ü�� ��ü!

	listView2();
}

void page2::OnBnClickedButton3()  //������ ��� ����
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	listView2();
}

////////////////////////////////////////////////////////////////////// �޺��ڽ�

void page2::OnCbnDropdownCombo1()  //�ο� �޺�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombo->ResetContent();
	pCombo->AddString("30");
	pCombo->AddString("35");
	pCombo->AddString("40");
	pCombo->AddString("45");
	pCombo->SetCurSel(0);
}
void page2::OnCbnSelendokCombo1()  //������ �ο��� Ŭ���� ����� �Է�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int idx = pCombo->GetCurSel();
	CString str = "";
	pCombo->GetLBText(idx, str);

	Max_num = _ttoi(str);
}

void page2::OnCbnDropdownCombo2()  //���� �޺�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO2);
	pCombo->ResetContent();
	pCombo->AddString("������");
	pCombo->AddString("ȭ����");
	pCombo->AddString("������");
	pCombo->AddString("�����");
	pCombo->AddString("�ݿ���");
	pCombo->SetCurSel(0);
}
void page2::OnCbnSelendokCombo2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO2);
	int idx = pCombo->GetCurSel();
	CString str = "";
	pCombo->GetLBText(idx, str);

	Date = str;
}

void page2::OnCbnDropdownCombo3()  //�ð� �޺�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO3);
	pCombo->ResetContent();
	pCombo->AddString("09:00");
	pCombo->AddString("10:00");
	pCombo->AddString("11:00");
	pCombo->AddString("12:00");
	pCombo->AddString("13:00");
	pCombo->AddString("14:00");
	pCombo->AddString("15:00");
	pCombo->AddString("16:00");
	pCombo->AddString("17:00");
	pCombo->SetCurSel(0);
}
void page2::OnCbnSelendokCombo3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO3);
	int idx = pCombo->GetCurSel();
	CString str = "";
	pCombo->GetLBText(idx, str);

	Time = str;
}

void page2::OnCbnDropdownCombo4()   //�ü� �޺�
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO4);
	pCombo->ResetContent();
	pCombo->AddString("1");
	pCombo->AddString("2");
	pCombo->AddString("3");
	pCombo->SetCurSel(0);
}
void page2::OnCbnSelendokCombo4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO4);
	int idx = pCombo->GetCurSel();
	CString str = "";
	pCombo->GetLBText(idx, str);

	Count = _ttoi(str);
}

void page2::write(CString title)
{
	UpdateData(true);
	CFile file;        //������ ������ ���� ��ü
	char buf[255];
	file.Open(title+".txt", CFile::modeCreate | CFile::modeWrite);  //������ ���� & ����
	file.Write(myEdit, lstrlen(myEdit));    //lstrlen(content) ����Ʈ�� ���̸�ŭ
	file.Close();
	myEdit = "";
	UpdateData(false);
}
void page2::Read(CString title)
{
	UpdateData(true);
	int size = 0;
	CFile file;                       //������ ������ ���� ��ü
	file.Open(title + ".txt", CFile::modeRead);  //�б���� ���� ����
	size = file.GetLength() + 1;
	char *buf = new char[size];
	memset(buf, '\0', size);           //���� �ʱ�ȭ (�����Ⱚ)
	file.Read(buf, size);
	file.Close();
	myEdit.Format("%s", buf);
	UpdateData(false);
	delete[] buf;
}