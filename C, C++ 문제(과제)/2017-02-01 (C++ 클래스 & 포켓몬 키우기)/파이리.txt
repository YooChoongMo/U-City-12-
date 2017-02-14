#include <iostream>
#include "pocket.h"

using namespace std;

Lee::Lee()
{
	cout << "ÆÄÀÌ¸® »ý¼º" << endl;
	hp = 35;
	exp = 0;
	level = 1;
}

void Lee::eat()
{
	Demon::eat();
	hp += 4;
}

void Lee::sleep()
{
	Demon::sleep();
	hp += 8;
}

bool Lee::exercise()
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

bool Lee::play()
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

void Lee::levelUp()
{
	if (exp >= 20)
	{
		Demon::levelUp();
		level++;
		exp -= 20;
	}
}

bool Lee::leap_Attack()
{
	cout << "³ª¹µÀÙ °ø°Ý!" << endl;

	hp -= 20;
	exp += 15;
	levelUp();

	if (hp <= 0)
		return false;
	else
		return true;
}