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
	int menu, soMenu = 15;
	LIST ls;
	CreateEmptyList(ls); //Khoi tao danh sach rong	
	char filename[MAX];
	int kq;

	do
	{
		cout << "\nNhap ten file de mo: ";
		cin >> filename;

		kq = GetDatafromfile(filename, ls);
		if (!kq)
		{
			cout << "\nKhong the mo tap tin! Vui long kiem tra lai ten tap tin!";
		}
	} while (kq == 0);

	cout << "\nMo tap tin thanh cong!\n";
	displayList(ls);

	do
	{
		system("cls");
		menu = Chonmenu(soMenu);
		Xulymenu(menu, ls);
	} while (menu > 0);
}