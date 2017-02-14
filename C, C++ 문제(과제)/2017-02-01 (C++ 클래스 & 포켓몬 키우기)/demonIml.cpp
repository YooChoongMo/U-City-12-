#include <iostream>
#include "pocket.h"

using namespace std;

void Demon::eat()               //상속이라 간단히만
{
	cout << "밥먹는다." << endl;
}

void Demon::sleep()               //상속이라 간단히만
{
	cout << "잠잔다." << endl;
}

bool Demon::exercise()               //상속이라 간단히만
{
	cout << "운동한다." << endl;
	return false;
}

bool Demon::play()               //상속이라 간단히만
{
	cout << "논다." << endl;
	return false;
}

void Demon::levelUp()
{
	cout << "레벨업." << endl;
}

void Demon::printInfo()
{
	cout << "hp: " << hp << endl;
	cout << "exp: " << exp << endl;
	cout << "level: " << level << endl;
}