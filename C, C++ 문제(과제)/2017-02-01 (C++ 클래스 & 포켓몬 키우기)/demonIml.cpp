#include <iostream>
#include "pocket.h"

using namespace std;

void Demon::eat()               //����̶� ��������
{
	cout << "��Դ´�." << endl;
}

void Demon::sleep()               //����̶� ��������
{
	cout << "���ܴ�." << endl;
}

bool Demon::exercise()               //����̶� ��������
{
	cout << "��Ѵ�." << endl;
	return false;
}

bool Demon::play()               //����̶� ��������
{
	cout << "���." << endl;
	return false;
}

void Demon::levelUp()
{
	cout << "������." << endl;
}

void Demon::printInfo()
{
	cout << "hp: " << hp << endl;
	cout << "exp: " << exp << endl;
	cout << "level: " << level << endl;
}