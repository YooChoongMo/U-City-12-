#include "stdafx.h"
#include "Subject.h"

Subject::Subject()
{
}
Subject::~Subject()
{
}
int Subject::cnt = 0;
Subject::Subject(int code, CString name)
{
	if (code == 0)
	{
		cnt++;
		this->Code = cnt;
	}
	else
		this->Code = code;

	this->Name = name;
	
	flag = false;
}

void Subject::setName(CString name)
{
	this->Name = name;
}

CString Subject::getName()
{
	return Name;
}

void Subject::setCode(int code)
{
	this->Code = code;
}

int Subject::getCode()
{
	return Code;
}

void Subject::setFlag(bool flag)
{
	this->flag = flag;
}

bool Subject::getFlag()
{
	return flag;
}


void Subject::setOpen_subject2(Open_subject2 os)
{
this->os = os;
}
Open_subject2 & Subject::getOpen_subject2()
{
return os;
}


