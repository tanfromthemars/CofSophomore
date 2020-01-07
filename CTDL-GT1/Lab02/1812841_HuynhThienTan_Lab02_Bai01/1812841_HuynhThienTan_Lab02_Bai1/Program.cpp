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
	int a[MAX], n;
	int menu, soMenu = 7;

	char filename(MAX);

	do
	{
		menu = chonMenu(soMenu);
		XulyMenu(menu, a, n);
	} while (menu > 0);

	system("pause");
}