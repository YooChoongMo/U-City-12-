#include "stdafx.h"
#include "Subject_array.h"


Subject_array::Subject_array()
{
}


Subject_array::~Subject_array()
{
}


void Subject_array::addSubject(Subject &s)
{
	data.Add(s);
}

CArray<Subject> & Subject_array::getData()
{
	return data;
}

int Subject_array::search(int code)
{	
	for (int i = 0; i < data.GetSize(); i++)
	{
		if (data.GetAt(i).getCode() == code)
		{
			return i;
		}
	}
		
	return -1;   //없으면 -1
}


void Subject_array::addOpen_Subject1(Open_subject2 &o)
{
	List_data.Add(o);
}

CArray<Open_subject2> & Subject_array::getList_data()
{
	return List_data;
}


void Subject_array::addOpen_Subject2(Open_subject2 &o)
{
	Student_data.Add(o);
}

CArray<Open_subject2> & Subject_array::getStudent_data()
{
	return Student_data;
}

int Subject_array::search2(int code)
{
	for (int i = 0; i < List_data.GetSize(); i++)
	{
		if (List_data.GetAt(i).getCd() == code)
		{
			return i;
		}
	}
	return -1;   //없으면 -1
}

bool Subject_array::delSelect(int code)   //Student_data삭제
{
	int idx = search3(code);
	if (idx < 0)
		return false;
	Student_data.RemoveAt(idx);
	//List_data.RemoveAt(idx);
	return true;

}

int Subject_array::search3(int code)
{
	for (int i = 0; i < Student_data.GetSize(); i++)
	{
		if (Student_data.GetAt(i).getCd() == code)
		{
			return i;
		}
	}
	return -1;   //없으면 -1
}