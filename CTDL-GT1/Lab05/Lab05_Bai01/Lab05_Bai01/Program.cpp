#include <iostream>
#include <fstream>

using namespace std;

#include "BNStree.h"
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
	BStree root = nullptr;
	int menu, somenu = 13;
	char filename[50];
	int kq;

	createBST(root);

	while (true)
	{
		system("cls");
		cout << "\nNhap ten tap tin de mo: ";
		cin >> filename;

		kq = getdatafromfile(filename, root);

		if (kq == 0) cout << "\nMo tap tin " << filename << " khong thanh cong!\n";
		else break;
		system("pause");
	}

	cout << "\nMo tap tin " << filename << " thanh cong!\n";
	cout << "\nCay hien tai: \n";
	inorder(root);

	do
	{
		menu = Chonmenu(somenu);
		Xulymenu(menu, root);
	} while (menu > 0);
}