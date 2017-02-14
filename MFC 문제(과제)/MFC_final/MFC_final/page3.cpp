// page3.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "MFC_final.h"
#include "page3.h"
#include "afxdialogex.h"

#include "Open_subject2.h"
#include "Subject.h"
#include "Subject_array.h"

// page3 대화 상자입니다.

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


// page3 메시지 처리기입니다.


BOOL page3::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	char *str[7] = { "과목코드", "과목명", "요일", "시간", "정원인원", "현재인원" , "기타"};
	int colW[7] = { 60, 150, 80, 150, 80, 80,158 };

	LVCOLUMN cols;  //
	cols.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//포맷, 서브항복, 텍스트, 가로길이 => 변경전 설정 할거라고 말함
	cols.fmt = LVCFMT_CENTER; //가운데 정렬


	for (int i = 0; i < 7; i++)
	{
		cols.pszText = str[i];
		cols.iSubItem = i;
		cols.cx = colW[i];  //까지 컬럼을 설정
		mylistCon4.InsertColumn(i, &cols); //컬럼을 추가(i번째 index에다가)
	}

	listView1();
	
	//수강신청한 과목목록
	char *str2[4] = { "과목코드", "과목명", "요일", "시간", };
	int colW2[7] = { 60, 120,70, 100 };

	LVCOLUMN cols2;  //컬럼 객체를 하나 만듬
	cols2.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
	//포맷, 서브항복, 텍스트, 가로길이 => 변경전 설정 할거라고 말함
	cols2.fmt = LVCFMT_CENTER;
	//LVCFMT_LEFT; //왼쪽 정렬

	for (int i = 0; i < 4; i++)
	{
		cols2.pszText = str2[i];
		cols2.iSubItem = i;
		cols2.cx = colW2[i];  //까지 컬럼을 설정
		mylistCon5.InsertColumn(i, &cols2); //컬럼을 추가(i번째 index에다가)
	}
	

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
void page3::OnBnClickedButton2()   //강의계획보기 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	/////////////////////////////////  강의계획 텍스트 파일 저장
	CString title = "";
	CString str = "";
	str.Format("%d", Subject_Code);
	title = "C:/text/" + str;

	Read(title);  //강의계획서 작성한 텍스트 파일 불러오기 ("C:/text/" 폴더에)
}

void page3::listView1()  //리스트 컨트롤 재정렬 해주는 함수!!
{
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();
	CArray<Open_subject2> &List_data = ((CMFC_finalApp*)AfxGetApp())->op.getList_data();
	//AfxGetApp얜 WinAPP에서 가져오는거라 CMFCtapApp내가 만든 클래스의 상위이다.
	//그래서 다운캐스팅으로 앞에 붙여준것!!
	//wh객체를 MFCtap.cpp에 만들어줘서 가져오기 위한것임
	char buf[50] = "";

	LVITEM item;
	item.mask = LVIF_TEXT;
	mylistCon4.DeleteAllItems();

	char *str[7] = { "과목코드", "과목명", "요일", "시간", "정원인원", "현재인원" , "기타" };
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

void page3::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)  //listcontrol클릭
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	POSITION pos = mylistCon4.GetFirstSelectedItemPosition();
	int idx = mylistCon4.GetNextSelectedItem(pos);

	CString tmp;
	tmp = mylistCon4.GetItemText(idx, 0);  //0번이 과목코드
	Subject_Code = _ttoi(tmp);
	//서브젝트 코드에 내가 리스트에서 클릭한 과목의 과목코드 넣어줌.

	*pResult = 0;
}

void page3::OnBnClickedButton1()  //수강신청 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int idx = ((CMFC_finalApp*)AfxGetApp())->sa.search(Subject_Code);  //전체과목의 idx
	//클릭한 과목의 과목코드를 idx에 저장
	Subject s = ((CMFC_finalApp*)AfxGetApp())->sa.getData().GetAt(idx);
	//그 인덱스 자리에 있는 과목을 반환!
	//==> 내가 클릭한 놈의 객체 가지고 온 상태 => sa.getData().SetAt(idx)으로 바꿔치기 하기


	int idx2 = ((CMFC_finalApp*)AfxGetApp())->op.search2(Subject_Code); //LIst_data의 index
	Open_subject2 o = ((CMFC_finalApp*)AfxGetApp())->op.getList_data().GetAt(idx2);
	//LIst_Data배열에 있는 객체를 o에 복사했다.
	//개설된 과목
	int n = o.getNow_number() + 1;

	if (n > o.getMax_number())  //정원초과
	{
		n = o.getMax_number();
		MessageBox("이미 수강신청한 과목입니다.");
		return;

	}
	if (o.getstudent_flag() == true)
	{
		MessageBox("이미 수강신청한 과목입니다.");
		return;
	}

	else if ((n <= o.getMax_number()) && (o.getstudent_flag() == false))
	{
		o.setstudent_flag(true); //수강신청 setstudent_flag => true 바꿔준다.
		o.setNow_number(n);   //현재인원 1증가

		s.setOpen_subject2(o);  //정보 입력된 open객체 =>  subject 객체 안으로 넣음

		((CMFC_finalApp*)AfxGetApp())->op.addOpen_Subject2(o);  
		//정보 수정한 후!! -> 객체 o를 Student_Data 배열에 추가.

		((CMFC_finalApp*)AfxGetApp())->op.getList_data().SetAt(idx2, o);
		//LIst_Data배열 idx2자리에 정보 수정한 객체 o로 바꿔치기. 
		((CMFC_finalApp*)AfxGetApp())->sa.getData().SetAt(idx, s);
		//o객체 포함한 s객체로 교체!

		listView2();
	}
}

void page3::listView2()  //수강신청한 과목 목록 만들기 Open_subject=>flag == true
{
	
	CArray<Subject> &data = ((CMFC_finalApp*)AfxGetApp())->sa.getData();//전체과목 
	CArray<Open_subject2> &Student_data = ((CMFC_finalApp*)AfxGetApp())->op.getStudent_data();
	//수강신청한 과목들 배열Student_data

	char buf[50] = "";
	int code;   //과목코드
	int index;
	LVITEM item;
	item.mask = LVIF_TEXT;
	mylistCon5.DeleteAllItems();

	char *str[4] = { "과목코드", "과목명", "요일", "시간", };
	
	for (int i = 0; i < Student_data.GetSize(); i++)
	{
			code = Student_data.GetAt(i).getCd();  // 과목코드 추출

			index = ((CMFC_finalApp*)AfxGetApp())->sa.search(code);//전체 과목배열의 index추출
			
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

//수강신청한 과목리스트 클릭
void page3::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	POSITION pos = mylistCon5.GetFirstSelectedItemPosition();
	int idx = mylistCon5.GetNextSelectedItem(pos);

	CString tmp;
	tmp = mylistCon5.GetItemText(idx, 0);  //0번이 과목코드
	Subject_Code = _ttoi(tmp);
	//서브젝트 코드에 내가 리스트에서 클릭한 과목의 과목코드 넣어줌.

	*pResult = 0;
}


void page3::OnBnClickedButton3()  //수강취소
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.  
	
	//int idx2 = ((CMFC_finalApp*)AfxGetApp())->op.search3(Subject_Code); //Student_data의 index
	((CMFC_finalApp*)AfxGetApp())->op.delSelect(Subject_Code);
	//Student_data 배열에서 삭제시킴

	
	int idx = ((CMFC_finalApp*)AfxGetApp())->sa.search(Subject_Code);  //전체과목의 idx
																	   //클릭한 과목의 과목코드를 idx에 저장
	Subject s = ((CMFC_finalApp*)AfxGetApp())->sa.getData().GetAt(idx);
	//그 인덱스 자리에 있는 과목을 반환!
	//==> 내가 클릭한 놈의 객체 가지고 온 상태 => sa.getData().SetAt(idx)으로 바꿔치기 하기

	int idx3 = ((CMFC_finalApp*)AfxGetApp())->op.search2(Subject_Code); //List_data의 index
	Open_subject2 o2 = ((CMFC_finalApp*)AfxGetApp())->op.getList_data().GetAt(idx3);

	o2.setstudent_flag(false); 
	//개설된 과목 리스트(List_Data)에서 student_flag를 바꿔준다
	
	int n = o2.getNow_number() - 1;
	o2.setNow_number(n);   //현재인원 -1 감소

	s.setOpen_subject2(o2);  //정보 입력된 open객체 =>  subject 객체 안으로 넣음(수정된 정보)

	((CMFC_finalApp*)AfxGetApp())->op.getList_data().SetAt(idx3, o2);
	//LIst_Data배열 idx3자리에 정보 수정한 객체 o2로 바꿔치기. 
	((CMFC_finalApp*)AfxGetApp())->sa.getData().SetAt(idx, s);
	//o객체 포함한 s객체로 교체!
	
	listView2();
}





void page3::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	listView1();
	listView2();
}



void page3::write(CString title)
{
	UpdateData(true);
	CFile file;        //파일의 정보를 가진 객체
	char buf[255];
	file.Open(title + ".txt", CFile::modeCreate | CFile::modeWrite);  //없으면 생성 & 쓰기
	file.Write(myEdit2, lstrlen(myEdit2));    //lstrlen(content) 컨텐트의 길이만큼
	file.Close();
	myEdit2 = "";
	UpdateData(false);
}


void page3::Read(CString title)
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
	myEdit2.Format("%s", buf);
	UpdateData(false);
	delete[] buf;
}
