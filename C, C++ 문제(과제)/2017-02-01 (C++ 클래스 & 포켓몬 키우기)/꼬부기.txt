#include <iostream>
#include "pocket.h"

using namespace std;

Gobook::Gobook()
{
	cout << "꼬부기 생성" << endl;
	hp = 35;
	exp = 0;
	level = 1;
}

void Gobook::eat()
{
	Demon::eat();
	hp += 4;
}

void Gobook::sleep()
{
	Demon::sleep();
	hp += 8;
}

bool Gobook::exercise()
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

bool Gobook::play()
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

void Gobook::levelUp()
{
	if (exp >= 20)
	{
		Demon::levelUp();
		level++;
		exp -= 20;
	}
}

bool Gobook::water_pump()
{
	cout << "물대포 공격!" << endl;

	hp -= 30;
	exp += 25;
	levelUp();

	if (hp <= 0)
		return false;
	else
		return true;
}