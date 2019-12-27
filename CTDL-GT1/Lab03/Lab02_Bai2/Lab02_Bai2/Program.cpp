#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

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
	LIST ls;
	CreateEmptylist(ls); 

	int menu, somenu = 0, kq = 0;
	char filename[MAX];

	do
	{
		cout << "\nNhap ten file de mo: ";
		cin >> filename;
		kq = getdatafromfile(filename, ls);
		if (kq == 0)
			cout << "\nTap tin " << filename << " khong ton tai!\n";
	} while (kq == 0);

	//Mo tap tin thanh cong
	cout << "\nMo tap tin " << filename << " thanh cong!";
	cout << "\nDanh sach nhan vien hien tai\n";
	Xuat_DS_NV(ls);
	system("pause");

	//Xu ly menu chuong trinh
	do
	{
		system("cls");
		menu = Chonmenu(somenu);
		Xulymenu(menu, ls);
	} while (menu > 0);
}