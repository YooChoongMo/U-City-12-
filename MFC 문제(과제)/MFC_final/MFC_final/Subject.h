#pragma once
#include "Open_subject2.h"


class Subject  //��ü ����� ����
{
	int Code;
	CString Name;
	bool flag;
	Open_subject2 os;  //������ ����(Ŭ����) ����

public:
	static int cnt;  //�����ڵ� 
	
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
