// page2.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_final.h"
#include "page2.h"
#include "afxdialogex.h"

#include "Subject_array.h"

#include "Open_subject2.h"
#include "Subject.h"

// page2 대화 상자입니다.

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


// page2 메시지 처리기입니다.


BOOL page2::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	char *str[2] = { "과목코드", "과목명"};
	int colW[2] = { 60, 150 };

	LVCOLUMN cols;  //
	cols.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//포맷, 서브항복, 텍스트, 가로길이 => 변경전 설정 할거라고 말함
	cols.fmt = LVCFMT_CENTER; //가운데 정렬
	

	for (int i = 0; i < 2; i++) 
	{
		cols.pszText = str[i];
		cols.iSubItem = i;
		cols.cx = colW[i];  //까지 컬럼을 설정
		mylistCon2.InsertColumn(i, &cols); //컬럼을 추가(i번째 index에다가)
	}

	LVCOLUMN cols2;  //컬럼 객체를 하나 만듬
	cols2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//포맷, 서브항복, 텍스트, 가로길이 => 변경전 설정 할거라고 말함
	cols2.fmt = LVCFMT_CENTER;
	//LVCFMT_LEFT; //왼쪽 정렬

	for (int i = 0; i < 2; i++) 
	{
		cols2.pszText = str[i];
		cols2.iSubItem = i;
		cols2.cx = colW[i];  //까지 컬럼을 설정
		mylistCon3.InsertColumn(i, &cols2); //컬럼을 추가(i번째 index에다가)
	}

	listView1();      //초기화면  =>  등록된 과목 보여주기

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void page2::listView1()  //리스트 컨트롤 재정렬 해주는 함수!!
{
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();
	//AfxGetApp얜 WinAPP에서 가져오는거라 CMFCtapApp내가 만든 클래스의 상위이다.
	//그래서 다운캐스팅으로 앞에 붙여준것!!
	//wh객체를 MFCtap.cpp에 만들어줘서 가져오기 위한것임
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
//개설한 목록 만들기 / List_data가 개설된 과목 모아진 배열**
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

void page2::OnBnClickedButton2()  //갱신 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	listView1();
}

void page2::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)  //리스크 컨트롤 클릭
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	POSITION pos = mylistCon2.GetFirstSelectedItemPosition();
	int idx = mylistCon2.GetNextSelectedItem(pos);

	CString tmp;
	tmp = mylistCon2.GetItemText(idx, 0);  //0번이 과목코드
	Subject_Code = _ttoi(tmp);
	//서브젝트 코드에 내가 리스트에서 클릭한 과목의 과목코드 넣어줌.

	*pResult = 0;
}

void page2::OnBnClickedButton1()  //개설 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	
	int idx = ((CMFC_finalApp*)AfxGetApp())->sa.search(Subject_Code);  
	//클릭한 과목의 과목코드를 idx에 저장
	Subject s = ((CMFC_finalApp*)AfxGetApp())->sa.getData().GetAt(idx);
	//그 인덱스 자리에 있는 과목을 반환!
	//==> 내가 클릭한 놈의 객체 가지고 온 상태   sa.getData().SetAt(idx)으로 바꿔치기 하기

	
	/////////////////////////////////  강의계획 텍스트 파일 저장
	CString title = "";
	CString str = "";
	str.Format("%d", Subject_Code);
	title = "C:/text/" + str;

	write(title);  //강의계획서 작성한 텍스트 파일 저장 ("C:/text/" 폴더에)

	Open_subject2 o(Subject_Code, Max_num, Date, Time, Count, title);
	//클릭한 과목코드, 콤보박스에서 선택한 항목의 정보들로 초기화!

	((CMFC_finalApp*)AfxGetApp())->op.addOpen_Subject1(o);
	//정보 입력된 open객체 => OpenLIst 배열에 추가.
	
	s.setOpen_subject2(o);  //정보 입력된 open객체 =>  subject 객체 안으로 넣음
	s.setFlag(true);       //개설 => true 바꿔준다.

	((CMFC_finalApp*)AfxGetApp())->sa.getData().SetAt(idx, s);   
	//o객체 포함한 s객체로 교체!

	listView2();
}

void page2::OnBnClickedButton3()  //개설한 목록 갱신
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	listView2();
}

////////////////////////////////////////////////////////////////////// 콤보박스

void page2::OnCbnDropdownCombo1()  //인원 콤보
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	pCombo->ResetContent();
	pCombo->AddString("30");
	pCombo->AddString("35");
	pCombo->AddString("40");
	pCombo->AddString("45");
	pCombo->SetCurSel(0);
}
void page2::OnCbnSelendokCombo1()  //선택한 인원을 클래스 멤버에 입력
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO1);
	int idx = pCombo->GetCurSel();
	CString str = "";
	pCombo->GetLBText(idx, str);

	Max_num = _ttoi(str);
}

void page2::OnCbnDropdownCombo2()  //요일 콤보
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO2);
	pCombo->ResetContent();
	pCombo->AddString("월요일");
	pCombo->AddString("화요일");
	pCombo->AddString("수요일");
	pCombo->AddString("목요일");
	pCombo->AddString("금요일");
	pCombo->SetCurSel(0);
}
void page2::OnCbnSelendokCombo2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO2);
	int idx = pCombo->GetCurSel();
	CString str = "";
	pCombo->GetLBText(idx, str);

	Date = str;
}

void page2::OnCbnDropdownCombo3()  //시간 콤보
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO3);
	int idx = pCombo->GetCurSel();
	CString str = "";
	pCombo->GetLBText(idx, str);

	Time = str;
}

void page2::OnCbnDropdownCombo4()   //시수 콤보
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO4);
	pCombo->ResetContent();
	pCombo->AddString("1");
	pCombo->AddString("2");
	pCombo->AddString("3");
	pCombo->SetCurSel(0);
}
void page2::OnCbnSelendokCombo4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_COMBO4);
	int idx = pCombo->GetCurSel();
	CString str = "";
	pCombo->GetLBText(idx, str);

	Count = _ttoi(str);
}

void page2::write(CString title)
{
	UpdateData(true);
	CFile file;        //파일의 정보를 가진 객체
	char buf[255];
	file.Open(title+".txt", CFile::modeCreate | CFile::modeWrite);  //없으면 생성 & 쓰기
	file.Write(myEdit, lstrlen(myEdit));    //lstrlen(content) 컨텐트의 길이만큼
	file.Close();
	myEdit = "";
	UpdateData(false);
}
void page2::Read(CString title)
{
	UpdateData(true);
	int size = 0;
	CFile file;                       //파일의 정보를 가진 객체
	file.Open(title + ".txt", CFile::modeRead);  //읽기모드로 파일 오픈
	size = file.GetLength() + 1;
	char *buf = new char[size];
	memset(buf, '\0', size);           //버프 초기화 (스레기값)
	file.Read(buf, size);
	file.Close();
	myEdit.Format("%s", buf);
	UpdateData(false);
	delete[] buf;
}