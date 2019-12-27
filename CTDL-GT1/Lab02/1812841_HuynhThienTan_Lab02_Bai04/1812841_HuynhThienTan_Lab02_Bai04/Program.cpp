#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

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
	Nhanvien a[MAX];
	int n;
	int soMenu = 8, menu;

	//Yeu cau nhap danh sach dau tien
	char filename[MAX];
	int kq;

	do
	{
		cout << "\nNhap ten tap tin de mo >> ";
		cin >> filename;

		kq = Docdanhsachnhanvien(filename, a, n);
	} while (kq == 0);

	//Chay chuong trinh chinh
	do
	{
		menu = chonMenu(soMenu);
		xulyMenu(menu, a, n);
	} while (menu > 0);
}