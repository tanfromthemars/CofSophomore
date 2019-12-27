#include <iostream>
#include <ctime>
#include <cstdlib>

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
	int soMenu = 4, menu;
	do
	{
		system("cls");
		menu = ChonMenu(soMenu);
		Xulymenu(menu);
		system("pause");
	} while (menu > 0);
}