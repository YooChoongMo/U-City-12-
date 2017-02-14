#pragma once


class Open_subject2
{
	int Cd;
	int Max_number;
	int Now_number;

	CString Date;
	CString Time;
	int Count;
	bool student_flag;
	CString Title;
	 

public:
	
	static int cnt;  //수강 신청한 인원

	Open_subject2();
	~Open_subject2();

	Open_subject2(int Cd, int Max_number, CString Date
		, CString Time, int Count, CString Title);

	void setMax_number(int number);
	int getMax_number();

	void setNow_number(int number);
	int getNow_number();

	void setDate(CString date);
	CString getDate();

	void setTime(CString time);
	CString getTime();

	void setCount(int count);
	int getCount();

	void setCd(int Cd);
	int getCd();

	void setstudent_flag(bool flag);
	bool getstudent_flag();

	void setTitle(CString Title);
	CString getTitle();

};

