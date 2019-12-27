#include <iostream>
#include <fstream>

using namespace std;

#include "Thuvien.h"
#include "Menu.h"

void Chaychuongtrinh();

int main()
{
	Chaychuongtrinh();
	return 0;
}

void Chaychuongtrinh()
{
	int kq;
	char filename[MAX];

	stack s;
	createemptystack(s);

	do
	{
		cout << "\nNhap ten tap tin de mo: ";
		cin >> filename;
		kq = getdatafromfile(filename, s);

		if (kq == 0)
			cout << "\nKiem tra lai ten tap tin.\n";
	} while (kq != 1);

	cout << "\nStack hien tai: ";
	displaystack(s);
	system("pause");

	int soMenu = 5, menu;

	do
	{
		menu = Chonmenu(soMenu);
		Xulymenu(menu, s);
	} while (menu > 0);
	cout << endl;
	system("pause");
}