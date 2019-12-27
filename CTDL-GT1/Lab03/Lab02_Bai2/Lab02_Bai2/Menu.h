void Xuatmenu()
{
	cout << "\n================ HE THONG CHUC NANG ====================";
	cout << "\n1. Nhap danh sach nhan vien tu file";
	cout << "\n2. Xuat danh sach nhan vien";
	cout << "\n3. Tim theo ten nhan vien - Final node";
	cout << "\n4. Tim nhan vien co luong cao nhat";
	cout << "\n5. Dem nhan vien co tien luong >= X";
	cout << "\n6. Huy toan vo nhan vien co dia chi X";
	cout << "\n7. Huy nhan vien dau tien co ten X";
	cout << "\n8. Sap giam theo nam sinh (Bubble sort)";
	cout << "\n9. Sap giam ma nhan vien (Chen truc tiep)";
	cout << "\n10. Sap tang luong nhan vien (Chon truc tiep)";
	cout << "\n11. Sap tang theo ten nhan vien (Doi cho truc tiep)";
	cout << "\n0. Thoat chuong trinh";
}

int Chonmenu(int somenu)
{
	int menu;

	while (true)
	{
		system("cls");
		Xuatmenu();
		cout << "\nChon chuc nang: ";
		cin >> menu;

		if (0 <= menu && menu <= somenu)
			break;
	}
	return menu;
}

void Xulymenu(int menu, LIST& ls)
{
	char filename[MAX];
	int kq;
	Data nhanvien;
	node* Node = NULL;
	LIST list;

	switch (menu)
	{
	case 1:
		cout << "\n1. Nhap danh sach nhan vien tu file";
		cout << "\nNhap ten file de mo: ";
		cin >> filename;

		kq = getdatafromfile(filename, ls);
		if (kq)
		{
			cout << "\nMo tap tin " << filename << " thanh cong!";
			cout << "\nDanh sach nhan vien hien tai\n";
			Xuat_DS_NV(ls);
		}
		else
			cout << "Tap tin" << filename << " khong ton tai!\n";
		break;

	case 2:
		cout << "\n2. Xuat danh sach nhan vien";
		cout << "\nDanh sach nhan vien hien tai\n";
		Xuat_DS_NV(ls);
		break;

	case 3:
		cout << "\n3. Tim theo ten nhan vien - Final node";
		cout << "\nNhap ten nhan vien can tim kiem:	";
		cin >> nhanvien.name.ten;

		Node = get_final_employee_with_name(ls, nhanvien.name.ten);
		if (Node)
		{
			cout << "\nTim thay nhan vien co ten: " << nhanvien.name.ten;
			cout << "\nThong tin chi tiet ve nhan vien:\n";
			Xuattieude();
			Xuat_1_NV(Node->info);
			Xuatduongke('=');
		}
		else
			cout << "\nKhong tim thay nhan vien co ten: " << nhanvien.name.ten << endl;
		break;

	case 4:
		cout << "\n4. Tim nhan vien co luong cao nhat";
		Node = MAX_salary(ls);
		cout << "\nThong tin chi tiet ve nhan vien co luong cao nhat:\n";
		Xuattieude();
		Xuat_1_NV(Node->info);
		Xuatduongke('=');
		break;

	case 5:
		cout << "\n5. Dem so nhan vien co tien luong >= X";
		cout << "\nNhap muc luong toi thieu: ";
		cin >> nhanvien.luong;

		list = filter_employee(ls, nhanvien.luong);
		kq = get_list_length(list);
		if (kq == 0)
			cout << "\nKhong tim thay nhan vien co muc luong >= " << nhanvien.luong << "\n";
		else
		{
			cout << "\nTim thay " << kq << " nhan vien co muc luong >= " << nhanvien.luong << "\n";
			cout << "\nDanh sach chi tiet: \n";
			Xuat_DS_NV(list);
		}
		break;

	case 6:
		cout << "\n6. Huy toan bo nhan vien co dia chi X";
		cout << "\nNhap dia chi cua nhan vien can xoa (cach bang dau '_' vd: Lam_Dong): ";
		cin >> nhanvien.diachi;

		if (isaddressexist(ls, nhanvien.diachi))
		{
			list = xoa_tatcac_node_co_diachi(ls, nhanvien.diachi);
			if (IsEmptylist(list))
				cout << "\nDanh sach hien tai rong!\n";
			else
			{
				cout << "\nDanh sach nhan vien sau khi xoa tat ca cac nhan vien co dia chi " << nhanvien.diachi << endl;
				Xuat_DS_NV(list);
			}
		}
		else
			cout << "\nKhong tim thay nhan vien co dia chi " << nhanvien.diachi << endl;
		break;

	case 7:
		cout << "\n7. Huy nhan vien dau tien co ten X";
		cout << "\nNhap ten nhan vien can xoa khoi danh sach: ";
		cin >> nhanvien.name.ten;

		Node = get_first_employee_with_name(ls, nhanvien.name.ten);

		if (Node)
		{
			list = remove_node(ls, Node);
			cout << "\nDanh sach nhan vien sau khi xoa bo nhan vien dau tien co ten " << nhanvien.name.ten << endl;
			Xuat_DS_NV(list);
		}
		else
			cout << "\nKhong tim thau nhan vien co ten " << nhanvien.name.ten << " trong danh sach.\n";
		break;

	case 8:
		break;
	case 9:
		break;
	case 10:
		break;
	case 11:
		break;
	case 0:
		cout << "\nThoat chuong trinh!\n";
		break;
	}
	system("pause");
}