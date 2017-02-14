#pragma once
#include "Subject.h"
#include "Open_subject2.h"

class Subject_array
{
	

	CArray<Open_subject2> List_data;
	CArray<Open_subject2> Student_data;
	CArray<Subject> data;

public:
	Subject_array();
	~Subject_array();
	
	void addSubject(Subject &s);
	CArray<Subject> & getData();
	int search(int code);  //�˻�

							  //bool edit(Subject &p, int type);  //���� Ÿ�� = �԰�, ���
							  //bool delproduct(int prodNum);  //����

	void addOpen_Subject1(Open_subject2 &o);
	CArray<Open_subject2> & getList_data();

	void addOpen_Subject2(Open_subject2 &o);
	CArray<Open_subject2> & getStudent_data();
	int search2(int code);


	bool delSelect(int code);  //Student_data ����
	int search3(int code);     //Student_data �˻�

};



