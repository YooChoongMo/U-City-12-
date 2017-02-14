#pragma once

class Demon   //상속 목적
{
protected:

	int hp;
	int exp;
	int level;

public:

	virtual void eat();
	virtual void sleep();
	virtual void levelUp();
	virtual bool exercise();
	virtual bool play();
	void printInfo();

};

class Picachu : public Demon
{
public:

	Picachu();
	void eat();
	void sleep();
	void levelUp();
	bool exercise();
	bool play();
	
	bool electric_shock();
};

class Gobook : public Demon
{
public:
	Gobook();
	void eat();
	void sleep();
	void levelUp();
	bool exercise();
	bool play();
	
	bool water_pump();
};

class Lee : public Demon
{
public:
	Lee();
	void eat();
	void sleep();
	void levelUp();
	bool exercise();
	bool play();

	bool leap_Attack();
};