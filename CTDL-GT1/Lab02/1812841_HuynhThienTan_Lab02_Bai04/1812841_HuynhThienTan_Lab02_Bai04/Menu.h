#pragma once
void xuatMenu();
int chonMenu(int soMenu);
void xulyMenu(int menu, Nhanvien a[], int& n);

void xuatMenu()
{
	cout << "\n=============== HE THONG CHUC NANG ================\n";
	cout << "\n1. Doc danh sach nhan vien tu file";
	cout << "\n2. Xuat danh sach nhan vien";
	cout << "\n3. Tang dan theo maNV (chen truc tiep)";
	cout << "\n4. Tang dan theo dia chi (chen truc tiep)";
	cout << "\n5. Tang dan theo tien luong (doi cho truc tiep)";
	cout << "\n6. Giam dan theo maNV (chen nhi phan)";
	cout << "\n7. Tang dan theo tien luong (HeapSort)";
	cout << "\n8. Tang dan theo nam sinh (QuickSort";
	cout << "\n0. Thoat chuong trinh";
}

int chonMenu(int soMenu)
{
	int chon;

	while (true)
	{
		system("cls");
		xuatMenu();
		cout << "\nChon 1 chuc nang trong khoang 1.." << soMenu << " >> ";
		cin >> chon;

		if (0 <= chon && chon <= soMenu)
			break;
	}
	
	return chon;
}

void xulyMenu(int menu, Nhanvien a[], int& n)
{
	char filename[MAX];
	int kq;
	unsigned int namsinh, luong;
	Name name;
	char diachi[16];
	const int namhientai = 2019;

	system("cls");
	switch (menu)
	{
	case 1:
		cout << "\n1. Doc danh sach nhan vien tu file";
		cout << "\nNhap ten file de mo >> ";
		cin >> filename;

		kq = Docdanhsachnhanvien(filename, a, n);
		if (kq != 0)
		{
			cout << "\nDanh sach nhan vien hien tai: (co " << n << "nhan vien)\n";
			Xuat_DS_NV(a, n);
		}

		break;

	case 2:
		cout << "\n2. Xuat danh sach nhan vien";
		cout << "\nDanh sach nhan vien hien tai: (co " << n << " nhan vien)\n";
		Xuat_DS_NV(a, n);

		break;

	case 3:
		cout << "\n3. Tang dan theo maNV";
		cout << "\nDanh sach nhan vien truoc khi sap xep: \n";
		Xuat_DS_NV(a, n);

		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo ma so: \n";
		Tang_MaNV(a, n);
		Xuat_DS_NV(a, n);
		
		break;

	case 4:
		cout << "\n4. Tang dan theo dia chi";
		cout << "\nDanh sach nhan vien truoc khi sap xep: \n";
		Xuat_DS_NV(a, n);

		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo dia chi: \n";
		Tang_Diachi(a, n);
		Xuat_DS_NV(a, n);

		break;

	case 5:
		cout << "\n5. Tang dan theo tien luong ";
		cout << "\nDanh sach nhan vien truoc khi sap xep: \n";
		Xuat_DS_NV(a, n);

		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo tien luong: \n";
		Tang_Luong(a, n);
		Xuat_DS_NV(a, n);

		break;

	case 6:
		cout << "\n6. Giam dan theo maNV";
				
		break;

	case 7:
		cout << "\n7. Tang dan theo tien luong";

		break;

	case 8:
		cout << "\n8. Tang dan theo nam sinh";
		cout << "\nDanh sach nhan vien truoc khi sap xep: \n";
		Xuat_DS_NV(a, n);

		cout << "\nDanh sach nhan vien sau khi sap xep tang dan theo tien luong: \n";
		QuickSort(a, 0, n - 1);
		Xuat_DS_NV(a, n);
		break;

	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	}
	system("pause");
}