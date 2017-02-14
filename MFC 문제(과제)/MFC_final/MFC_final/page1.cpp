// page1.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_final.h"
#include "page1.h"
#include "afxdialogex.h"
#include "Subject.h"
#include "Subject_array.h"

// page1 대화 상자입니다.

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


// page1 메시지 처리기입니다.


void page1::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.










	*pResult = 0;
}


BOOL page1::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	char *str[3] = { "과목코드", "과목명", "개설유무"};
	int colW[3] = { 60, 130, 60}; //가로길이   
									 //컬럼의 길이(이름은 짧고, 이메일은 길고)=>폴더열면 이름, 수정날짜 이런 칸

	LVCOLUMN cols;  //컬럼 객체를 하나 만듬
	cols.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//포맷, 서브항복, 텍스트, 가로길이 => 변경전 설정 할거라고 말함
	cols.fmt = LVCFMT_LEFT; //왼쪽 정렬

	for (int i = 0; i < 3; i++) //항목 4개
	{
		cols.pszText = str[i];
		cols.iSubItem = i;
		cols.cx = colW[i];  //까지 컬럼을 설정
		mylistcon1.InsertColumn(i, &cols); //컬럼을 추가(i번째 index에다가)
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void page1::listView()  //리스트 컨트롤 재정렬 해주는 함수!!
{
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();
	//AfxGetApp얜 WinAPP에서 가져오는거라 CMFCtapApp내가 만든 클래스의 상위이다.
	//그래서 다운캐스팅으로 앞에 붙여준것!!
	//wh객체를 MFCtap.cpp에 만들어줘서 가져오기 위한것임
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

void page1::OnBnClickedButton1()  //과목 등록
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);
	Subject s(0, prodName);
	((CMFC_finalApp*)AfxGetApp())->sa.addSubject(s);
	
	listView();

	prodName = "";
	UpdateData(false);
}


void page1::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	listView();
}

