#pragma once
void xuatMenu();
int chonMenu(int soMenu);
void xulyMenu(int menu, Nhanvien a[], int& n);

void xuatMenu()
{
	cout << "\n=============== HE THONG CHUC NANG ================\n";
	cout << "\n1. Doc danh sach nhan vien tu file";
	cout << "\n2. Xuat danh sach nhan vien";
	cout << "\n3. Tim kiem theo ho va ten nhan vien";
	cout << "\n4. Tim kiem theo nam sinh";
	cout << "\n5. Tim kiem theo ho ten va nam sinh nho hon x cho truoc";
	cout << "\n6. Tim kiem theo ten va dia chi";
	cout << "\n7. Tim kiem theo luong >= x va nam sinh <= y cho truoc";
	cout << "\n8. Tim kiem nhi phan theo ma nhan vien";
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
		cout << "\n3. Tim kiem theo ho va ten nhan vien";

		cin.clear();
		cin.ignore(MAX, '\n');
		
		do
		{
			cout << "\nNhap ho cua nhan vien: ";
			cin >> name.ho;
		} while (Tinhchieudaichuoi(name.ho) > 10);

		do
		{
			cout << "\nNhap ten cua nhan vien: ";
			cin >> name.ten;
		} while (Tinhchieudaichuoi(name.ten) > 10);

		Timkiem_Hoten(a, n, name, 9999);

		break;

	case 4:
		cout << "\n4. Tim kiem theo nam sinh";
		
		do
		{
			cout << "\nNhap nam sinh cua nhan vien: ";
			cin >> namsinh;
		} while (namsinh <= 0 || namsinh >= namhientai || !namsinh);

		Timkiem_NS(a, n, namsinh);
		
		break;

	case 5:
		cout << "\n5. Tim kiem theo ho ten va nam sinh nho hon x cho truoc";
		
		cin.clear();
		cin.ignore(MAX, '\n');

		do
		{
			cout << "\nNhap ho cua nhan vien: ";
			cin >> name.ho;
		} while (Tinhchieudaichuoi(name.ho) > 10);

		do
		{
			cout << "\nNhap ten cua nhan vien: ";
			cin >> name.ten;
		} while (Tinhchieudaichuoi(name.ten) > 10);

		do
		{
			cout << "\nNhap nam sinh cua nhan vien: ";
			cin >> namsinh;
		} while (namsinh <= 0 || namsinh >= namhientai || !namsinh);

		Timkiem_Hoten(a, n, name, namsinh);

		break;

	case 6:
		cout << "\n6. Tim kiem theo ten va dia chi";

		do
		{
			cout << "\nNhap ten cua nhan vien: ";
			cin >> name.ten;
		} while (Tinhchieudaichuoi(name.ten) > 10);

		do
		{
			cout << "\nNhap dia chi cua nhan vien: ";
			cin >> diachi;
		} while (Tinhchieudaichuoi(diachi) > 15);

		Timkiem_Ten_Diachi(a, n, name, diachi);

		break;

	case 7:
		cout << "\n7. Tim kiem theo luong >= x va nam sinh <= y";

		do
		{
			cout << "\nNhap nam sinh cua nhan vien: ";
			cin >> namsinh;
		} while (namsinh <= 0 || namsinh >= namhientai || !namsinh);
		
		Timkiem_NS_Luong(a, n, namsinh,luong);

		break;

	case 8:
		cout << "\n8. Tim kiem nhi phan theo ma nhan vien";
		break;

	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	}
	system("pause");
}