#include <iostream>
#include <typeinfo>                //typeid尻至切 床奄是背
#include "pocket.h"

using namespace std;

void main()
{

	Demon *pd = NULL;
	bool flag = false;

	while (1)
	{
		cout << "持失拝 蝶遣斗研 壱牽獣神. \n";
		cout << "1.杷朝鋳   2.何採奄   3.督戚軒 4.曽戟: ";
		int choice;
		cin >> choice;

		switch (choice)
		{

		case 1:	pd = new Picachu();
			flag = true;
			break;

		case 2:	pd = new Gobook();
			flag = true;
			break;

		case 3:	pd = new Lee();
			flag = true;
			break;

		case 4:
			cout << "惟績聖 曽戟杯艦陥.\n";
			cout << endl;
			flag = false;
			break;
		}
		if (choice == 4)
			break;

		while (flag == true)
		{
			cout << "1.剛股奄   2.節切奄   3.且奄   4.錘疑馬奄   5.什迭尻柔   6.舛左溌昔   7.曽戟 : ";
			int act;
			cin >> act;

			switch (act)
			{
			case 1: pd->eat();
				break;

			case 2: pd->sleep();
				break;

			case 3: 

				if (pd->play() == false)
				{
					cout << "蝶遣斗亜 宋醸柔艦陥ばば\n";
					flag = false;
				}
				break;

			case 4: 

				if (pd->exercise() == false)
				{
					cout << "蝶遣斗亜 宋醸柔艦陥ばば\n";
					flag = false;
				}
				break;

			case 5: 
				if (typeid(*pd) == typeid(Picachu))
				{
					if(((Picachu*)pd)->electric_shock() == false)
					{
						cout << "蝶遣斗亜 宋醸柔艦陥ばば\n";
						flag = false;
					}
				}
				
				else if(typeid(*pd) == typeid(Gobook))
				{
					if(((Gobook*)pd)->water_pump() == false)
					{
						cout << "蝶遣斗亜 宋醸柔艦陥ばば\n";
						flag = false;
					}
				}
				
				else if (typeid(*pd) == typeid(Lee))
				{
					if(((Lee*)pd)->leap_Attack() == false)
					{
						cout << "蝶遣斗亜 宋醸柔艦陥ばば\n";
						flag = false;
					}
				}
				break;

			case 6: pd->printInfo();
				break;

			case 7: flag = false;
					break;

			}
			
			cout << endl;
		}

		delete pd;

	}
}