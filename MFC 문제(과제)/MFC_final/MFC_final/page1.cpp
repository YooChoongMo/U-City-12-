// page1.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFC_final.h"
#include "page1.h"
#include "afxdialogex.h"
#include "Subject.h"
#include "Subject_array.h"

// page1 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(page1, CPropertyPage)

page1::page1()
	: CPropertyPage(IDD_DIALOG1)
	, prodName(_T(""))
{

}

page1::~page1()
{
}

void page1::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, prodName);
	DDX_Control(pDX, IDC_LIST1, mylistcon1);
}


BEGIN_MESSAGE_MAP(page1, CPropertyPage)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &page1::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON1, &page1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &page1::OnBnClickedButton2)
END_MESSAGE_MAP()


// page1 �޽��� ó�����Դϴ�.


void page1::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.










	*pResult = 0;
}


BOOL page1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	char *str[3] = { "�����ڵ�", "�����", "��������"};
	int colW[3] = { 60, 130, 60}; //���α���   
									 //�÷��� ����(�̸��� ª��, �̸����� ���)=>�������� �̸�, ������¥ �̷� ĭ

	LVCOLUMN cols;  //�÷� ��ü�� �ϳ� ����
	cols.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//����, �����׺�, �ؽ�Ʈ, ���α��� => ������ ���� �ҰŶ�� ����
	cols.fmt = LVCFMT_LEFT; //���� ����

	for (int i = 0; i < 3; i++) //�׸� 4��
	{
		cols.pszText = str[i];
		cols.iSubItem = i;
		cols.cx = colW[i];  //���� �÷��� ����
		mylistcon1.InsertColumn(i, &cols); //�÷��� �߰�(i��° index���ٰ�)
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}

void page1::listView()  //����Ʈ ��Ʈ�� ������ ���ִ� �Լ�!!
{
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();
	//AfxGetApp�� WinAPP���� �������°Ŷ� CMFCtapApp���� ���� Ŭ������ �����̴�.
	//�׷��� �ٿ�ĳ�������� �տ� �ٿ��ذ�!!
	//wh��ü�� MFCtap.cpp�� ������༭ �������� ���Ѱ���
	char buf[50] = "";

	LVITEM item;
	item.mask = LVIF_TEXT;
	mylistcon1.DeleteAllItems();

	for (int i = 0; i < data.GetSize(); i++)
	{
		item.iItem = i;
		item.iSubItem = 0;
		sprintf(buf, "%d", data.GetAt(i).getCode());
		item.pszText = buf;
		mylistcon1.InsertItem(&item);

		item.iSubItem = 1;
		sprintf(buf, "%s", data.GetAt(i).getName());
		item.pszText = buf;
		mylistcon1.SetItem(&item);

		item.iSubItem = 2;
		if (data.GetAt(i).getFlag())
			sprintf(buf, "%s", "O");
		else
			sprintf(buf, "%s", "X");
		item.pszText = buf;
		mylistcon1.SetItem(&item);
	}
}

void page1::OnBnClickedButton1()  //���� ���
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);
	Subject s(0, prodName);
	((CMFC_finalApp*)AfxGetApp())->sa.addSubject(s);
	
	listView();

	prodName = "";
	UpdateData(false);
}


void page1::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	listView();
}

