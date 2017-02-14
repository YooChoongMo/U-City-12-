#include "stdafx.h"
#include "Open_subject2.h"
#include "Subject.h"

Open_subject2::Open_subject2()
{
}


Open_subject2::~Open_subject2()
{
}

int Open_subject2::cnt = 0;

Open_subject2::Open_subject2(int Cd, int Max_number, CString Date, CString Time, int Count, CString Title)
{
	/*
	if (Now_number == 0)
	{
		cnt++;
		this->Now_number = cnt;
	}
	else
		this->Now_number = Now_number;
	*/
	

	this->Max_number = Max_number;
	this->Date = Date;
	this->Time = Time;
	this->Count = Count;
	this->Cd = Cd;
	this->Title = Title;
	student_flag = false;
	Now_number = 0;
}

void Open_subject2::setMax_number(int number)
{
	this->Max_number = number;
}

int Open_subject2::getMax_number()
{
	return Max_number;
}

void Open_subject2::setNow_number(int number)
{
	this->Now_number = number;
}

int Open_subject2::getNow_number()
{
	return Now_number;
}

void Open_subject2::setDate(CString date)
{
	this->Date = date;
}

CString Open_subject2::getDate()
{
	return Date;
}

void Open_subject2::setTime(CString time)
{
	this->Time = time;
}
CString Open_subject2::getTime()
{
	return Time;
}

void Open_subject2::setCount(int count)
{
	this->Count = count;
}

int Open_subject2::getCount()
{
	return Count;
}

void Open_subject2::setCd(int Cd)
{
	this->Cd = Cd;
}

int Open_subject2::getCd()
{
	return Cd;
}

void Open_subject2::setstudent_flag(bool flag)
{
	this->student_flag = flag;
}

bool Open_subject2::getstudent_flag()
{
	return student_flag;
}

void Open_subject2::setTitle(CString title)
{
	this->Title = title;
}
CString Open_subject2::getTitle()
{
	return Title;
}