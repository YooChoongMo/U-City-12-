// page3.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "MFC_final.h"
#include "page3.h"
#include "afxdialogex.h"

#include "Open_subject2.h"
#include "Subject.h"
#include "Subject_array.h"

// page3 ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(page3, CPropertyPage)

page3::page3()
	: CPropertyPage(IDD_DIALOG3)
	, myEdit2(_T(""))
{

}

page3::~page3()
{
}

void page3::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, mylistCon4);
	DDX_Control(pDX, IDC_LIST2, mylistCon5);
	DDX_Text(pDX, IDC_EDIT1, myEdit2);
}


BEGIN_MESSAGE_MAP(page3, CPropertyPage)
	ON_BN_CLICKED(IDC_BUTTON1, &page3::OnBnClickedButton1)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &page3::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON2, &page3::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &page3::OnBnClickedButton3)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &page3::OnLvnItemchangedList2)
	ON_BN_CLICKED(IDC_BUTTON4, &page3::OnBnClickedButton4)
END_MESSAGE_MAP()


// page3 �޽��� ó�����Դϴ�.


BOOL page3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	char *str[7] = { "�����ڵ�", "�����", "����", "�ð�", "�����ο�", "�����ο�" , "��Ÿ"};
	int colW[7] = { 60, 150, 80, 150, 80, 80,158 };

	LVCOLUMN cols;  //
	cols.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//����, �����׺�, �ؽ�Ʈ, ���α��� => ������ ���� �ҰŶ�� ����
	cols.fmt = LVCFMT_CENTER; //��� ����


	for (int i = 0; i < 7; i++)
	{
		cols.pszText = str[i];
		cols.iSubItem = i;
		cols.cx = colW[i];  //���� �÷��� ����
		mylistCon4.InsertColumn(i, &cols); //�÷��� �߰�(i��° index���ٰ�)
	}

	listView1();
	
	//������û�� ������
	char *str2[4] = { "�����ڵ�", "�����", "����", "�ð�", };
	int colW2[7] = { 60, 120,70, 100 };

	LVCOLUMN cols2;  //�÷� ��ü�� �ϳ� ����
	cols2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//����, �����׺�, �ؽ�Ʈ, ���α��� => ������ ���� �ҰŶ�� ����
	cols2.fmt = LVCFMT_CENTER;
	//LVCFMT_LEFT; //���� ����

	for (int i = 0; i < 4; i++)
	{
		cols2.pszText = str2[i];
		cols2.iSubItem = i;
		cols2.cx = colW2[i];  //���� �÷��� ����
		mylistCon5.InsertColumn(i, &cols2); //�÷��� �߰�(i��° index���ٰ�)
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
void page3::OnBnClickedButton2()   //���ǰ�ȹ���� ��ư
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	/////////////////////////////////  ���ǰ�ȹ �ؽ�Ʈ ���� ����
	CString title = "";
	CString str = "";
	str.Format("%d", Subject_Code);
	title = "C:/text/" + str;

	Read(title);  //���ǰ�ȹ�� �ۼ��� �ؽ�Ʈ ���� �ҷ����� ("C:/text/" ������)
}

void page3::listView1()  //����Ʈ ��Ʈ�� ������ ���ִ� �Լ�!!
{
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();
	CArray<Open_subject2> &List_data = ((CMFC_finalApp*)AfxGetApp())->op.getList_data();
	//AfxGetApp�� WinAPP���� �������°Ŷ� CMFCtapApp���� ���� Ŭ������ �����̴�.
	//�׷��� �ٿ�ĳ�������� �տ� �ٿ��ذ�!!
	//wh��ü�� MFCtap.cpp�� ������༭ �������� ���Ѱ���
	char buf[50] = "";

	LVITEM item;
	item.mask = LVIF_TEXT;
	mylistCon4.DeleteAllItems();

	char *str[7] = { "�����ڵ�", "�����", "����", "�ð�", "�����ο�", "�����ο�" , "��Ÿ" };
	for (int i = 0; i < List_data.GetSize(); i++)
	{

		int idx = ((CMFC_finalApp*)AfxGetApp())->sa.search(List_data.GetAt(i).getCd());

		item.iItem = i;
		item.iSubItem = 0;
		sprintf(buf, "%d", List_data.GetAt(i).getCd());
		item.pszText = buf;
		mylistCon4.InsertItem(&item);

		item.iSubItem = 1;
		sprintf(buf, "%s", data.GetAt(idx).getName());
		item.pszText = buf;
		mylistCon4.SetItem(&item);

		item.iSubItem = 2;
		sprintf(buf, "%s", List_data.GetAt(i).getDate());
		item.pszText = buf;
		mylistCon4.SetItem(&item);

		item.iSubItem = 3;
		sprintf(buf, "%s", List_data.GetAt(i).getTime());
		item.pszText = buf;
		mylistCon4.SetItem(&item);

		item.iSubItem = 4;
		sprintf(buf, "%d", List_data.GetAt(i).getMax_number());
		item.pszText = buf;
		mylistCon4.SetItem(&item);

		item.iSubItem = 5;
		sprintf(buf, "%d", List_data.GetAt(i).getNow_number());
		item.pszText = buf;
		mylistCon4.SetItem(&item);
		
	}
}

void page3::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)  //listcontrolŬ��
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	POSITION pos = mylistCon4.GetFirstSelectedItemPosition();
	int idx = mylistCon4.GetNextSelectedItem(pos);

	CString tmp;
	tmp = mylistCon4.GetItemText(idx, 0);  //0���� �����ڵ�
	Subject_Code = _ttoi(tmp);
	//������Ʈ �ڵ忡 ���� ����Ʈ���� Ŭ���� ������ �����ڵ� �־���.

	*pResult = 0;
}

void page3::OnBnClickedButton1()  //������û ��ư
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	int idx = ((CMFC_finalApp*)AfxGetApp())->sa.search(Subject_Code);  //��ü������ idx
	//Ŭ���� ������ �����ڵ带 idx�� ����
	Subject s = ((CMFC_finalApp*)AfxGetApp())->sa.getData().GetAt(idx);
	//�� �ε��� �ڸ��� �ִ� ������ ��ȯ!
	//==> ���� Ŭ���� ���� ��ü ������ �� ���� => sa.getData().SetAt(idx)���� �ٲ�ġ�� �ϱ�


	int idx2 = ((CMFC_finalApp*)AfxGetApp())->op.search2(Subject_Code); //LIst_data�� index
	Open_subject2 o = ((CMFC_finalApp*)AfxGetApp())->op.getList_data().GetAt(idx2);
	//LIst_Data�迭�� �ִ� ��ü�� o�� �����ߴ�.
	//������ ����
	int n = o.getNow_number() + 1;

	if (n > o.getMax_number())  //�����ʰ�
	{
		n = o.getMax_number();
		MessageBox("�̹� ������û�� �����Դϴ�.");
		return;

	}
	if (o.getstudent_flag() == true)
	{
		MessageBox("�̹� ������û�� �����Դϴ�.");
		return;
	}

	else if ((n <= o.getMax_number()) && (o.getstudent_flag() == false))
	{
		o.setstudent_flag(true); //������û setstudent_flag => true �ٲ��ش�.
		o.setNow_number(n);   //�����ο� 1����

		s.setOpen_subject2(o);  //���� �Էµ� open��ü =>  subject ��ü ������ ����

		((CMFC_finalApp*)AfxGetApp())->op.addOpen_Subject2(o);  
		//���� ������ ��!! -> ��ü o�� Student_Data �迭�� �߰�.

		((CMFC_finalApp*)AfxGetApp())->op.getList_data().SetAt(idx2, o);
		//LIst_Data�迭 idx2�ڸ��� ���� ������ ��ü o�� �ٲ�ġ��. 
		((CMFC_finalApp*)AfxGetApp())->sa.getData().SetAt(idx, s);
		//o��ü ������ s��ü�� ��ü!

		listView2();
	}
}

void page3::listView2()  //������û�� ���� ��� ����� Open_subject=>flag == true
{
	
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();//��ü���� 
	CArray<Open_subject2> &Student_data = ((CMFC_finalApp*)AfxGetApp())->op.getStudent_data();
	//������û�� ����� �迭Student_data

	char buf[50] = "";
	int code;   //�����ڵ�
	int index;
	LVITEM item;
	item.mask = LVIF_TEXT;
	mylistCon5.DeleteAllItems();

	char *str[4] = { "�����ڵ�", "�����", "����", "�ð�", };
	
	for (int i = 0; i < Student_data.GetSize(); i++)
	{
			code = Student_data.GetAt(i).getCd();  // �����ڵ� ����

			index = ((CMFC_finalApp*)AfxGetApp())->sa.search(code);//��ü ����迭�� index����
			
				if (data.GetAt(index).getCode() == code)
				{
					item.iItem = i;
					item.iSubItem = 0;
					sprintf(buf, "%d", data.GetAt(index).getCode());
					item.pszText = buf;
					mylistCon5.InsertItem(&item);

					item.iSubItem = 1;
					sprintf(buf, "%s", data.GetAt(index).getName());
					item.pszText = buf;
					mylistCon5.SetItem(&item);

					item.iSubItem = 2;
					sprintf(buf, "%s", data.GetAt(index).getOpen_subject2().getDate());
					item.pszText = buf;
					mylistCon5.SetItem(&item);

					item.iSubItem = 3;
					sprintf(buf, "%s", data.GetAt(index).getOpen_subject2().getTime());
					item.pszText = buf;
					mylistCon5.SetItem(&item);
				}
			

		}	
}

//������û�� ���񸮽�Ʈ Ŭ��
void page3::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	POSITION pos = mylistCon5.GetFirstSelectedItemPosition();
	int idx = mylistCon5.GetNextSelectedItem(pos);

	CString tmp;
	tmp = mylistCon5.GetItemText(idx, 0);  //0���� �����ڵ�
	Subject_Code = _ttoi(tmp);
	//������Ʈ �ڵ忡 ���� ����Ʈ���� Ŭ���� ������ �����ڵ� �־���.

	*pResult = 0;
}


void page3::OnBnClickedButton3()  //�������
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.  
	
	//int idx2 = ((CMFC_finalApp*)AfxGetApp())->op.search3(Subject_Code); //Student_data�� index
	((CMFC_finalApp*)AfxGetApp())->op.delSelect(Subject_Code);
	//Student_data �迭���� ������Ŵ

	
	int idx = ((CMFC_finalApp*)AfxGetApp())->sa.search(Subject_Code);  //��ü������ idx
																	   //Ŭ���� ������ �����ڵ带 idx�� ����
	Subject s = ((CMFC_finalApp*)AfxGetApp())->sa.getData().GetAt(idx);
	//�� �ε��� �ڸ��� �ִ� ������ ��ȯ!
	//==> ���� Ŭ���� ���� ��ü ������ �� ���� => sa.getData().SetAt(idx)���� �ٲ�ġ�� �ϱ�

	int idx3 = ((CMFC_finalApp*)AfxGetApp())->op.search2(Subject_Code); //List_data�� index
	Open_subject2 o2 = ((CMFC_finalApp*)AfxGetApp())->op.getList_data().GetAt(idx3);

	o2.setstudent_flag(false); 
	//������ ���� ����Ʈ(List_Data)���� student_flag�� �ٲ��ش�
	
	int n = o2.getNow_number() - 1;
	o2.setNow_number(n);   //�����ο� -1 ����

	s.setOpen_subject2(o2);  //���� �Էµ� open��ü =>  subject ��ü ������ ����(������ ����)

	((CMFC_finalApp*)AfxGetApp())->op.getList_data().SetAt(idx3, o2);
	//LIst_Data�迭 idx3�ڸ��� ���� ������ ��ü o2�� �ٲ�ġ��. 
	((CMFC_finalApp*)AfxGetApp())->sa.getData().SetAt(idx, s);
	//o��ü ������ s��ü�� ��ü!
	
	listView2();
}





void page3::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	listView1();
	listView2();
}



void page3::write(CString title)
{
	UpdateData(true);
	CFile file;        //������ ������ ���� ��ü
	char buf[255];
	file.Open(title + ".txt", CFile::modeCreate | CFile::modeWrite);  //������ ���� & ����
	file.Write(myEdit2, lstrlen(myEdit2));    //lstrlen(content) ����Ʈ�� ���̸�ŭ
	file.Close();
	myEdit2 = "";
	UpdateData(false);
}


void page3::Read(CString title)
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
	myEdit2.Format("%s", buf);
	UpdateData(false);
	delete[] buf;
}
