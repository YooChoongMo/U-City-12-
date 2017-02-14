#include <iostream>
#include "pocket.h"

using namespace std;

Picachu::Picachu()
{
	cout << "피카츄 생성" << endl;
	hp = 30;
	exp = 0;
	level = 1;
}

void Picachu::eat()
{
	Demon::eat();
	hp += 4;
}

void Picachu::sleep()
{
	Demon::sleep();
	hp += 8;
}

bool Picachu::exercise()
{
	Demon::exercise();
	hp -= 18;
	exp += 10;
	levelUp();

	if (hp <= 0)
		return false;
	else
		return true;
}

bool Picachu::play()
{
	Demon::play();
	hp -= 10;
	exp += 5;
	levelUp();

	if (hp <= 0)
		return false;
	else
		return true;
}

void Picachu::levelUp()
{
	
	if (exp >= 20)
	{
		Demon::levelUp();
		level++;
		exp -= 20;
	}
}

bool Picachu::electric_shock()
{
	cout << "100만 볼트 공격!" << endl;

	hp -= 20;
	exp += 15;
	levelUp();

	if (hp <= 0)
		return false;
	else
		return true;
}

