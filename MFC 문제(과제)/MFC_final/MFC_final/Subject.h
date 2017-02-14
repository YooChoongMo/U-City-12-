#pragma once
#include "Open_subject2.h"


class Subject  //전체 과목들 집합
{
	int Code;
	CString Name;
	bool flag;
	Open_subject2 os;  //개설된 과목(클래스) 포함

public:
	static int cnt;  //과목코드 
	
	Subject();
	~Subject();
	
	Subject(int code, CString name);

	void setCode(int code);
	int getCode();

	void setName(CString name);
	CString getName();

	void setFlag(bool flag);
	bool getFlag();

	
	void setOpen_subject2(Open_subject2 os);
	Open_subject2 & getOpen_subject2();
	

};
