void Xuatmenu()
{
	cout << "\n================ HE THONG CHUC NANG =====================";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao bang luong nhan vien";
	cout << "\n2. Xem bang luong nhan vien theo thu tu";
	cout << "\n3. Tinh so nut cua cay";
	cout << "\n4. Thay doi nam sinh cua nhan vien cp ma nhan vien cho truoc";
	cout << "\n5. Huy nhan vien co MaNV cho truoc";
}

int Chonmenu(int somenu)
{
	int chon;

	while (true)
	{
		system("cls");
		Xuatmenu();
		cout << "\nChon 1 chuc nang trong khoang [0.." << somenu << "] de chon chuc nang tuong ung: ";
		cin >> chon;

		if (0 <= chon && chon <= somenu)
			break;
	}
	return chon;
}

void Xulymenu(int menu, BStree& root)
{
	char filename[50];
	char MaNV[10];
	unsigned int Namsinh;
	int kq;
	BStree ketqua;

	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;

	case 1:
		cout << "\n1. Tao bang luong nhan vien";
		cout << "\nNhap ten tap tin de mo: ";
		cin >> filename;

		kq = getdatafromfile(filename, root);

		if (kq)
			cout << "\nDoc du lieu tu tap tin " << filename << " thanh cong!";
		else
			cout << "\nDoc du lieu khong thanh cong!";
		break;

	case 2:
		cout << "\n2. Xem bang luong nhan vien theo thu tu";
		cout << "\nBang luong nhan vien theo thu tu giua - truoc - sau:\n";
		preorder(root);

		cout << "\nBang luong nhan vien theo thu tu truoc - giua - sau:\n";
		inorder(root);
		
		cout << "\nBang luong nhan vien theo thu tu truoc - sau - giua:\n";
		posorder(root);
		break;

	case 3:
		cout << "\n3. Tinh so nut cua cay";

		kq = Demsonut(root);

		if (kq == 0)
			cout << "\nCay hien tai khong co nut\n";
		else
			cout << "\nSo nut hien tai cua cay la: " << kq << endl;
		break;

	case 4:
		cout << "\n4. Thay doi nam sinh cua nhan vien co ma so nhan vien cho truoc";
		cout << "\nNhap vao ma nhan vien: ";
		cin >> MaNV;
		ketqua = Search(MaNV, root);
		if (ketqua)
		{
			cout << "\nThong tin cua nhan vien: \n";
			xuatNV(ketqua->data);

			cout << "\nNhap vao nam sinh: ";
			cin >> Namsinh;

			ketqua->data.Namsinh = Namsinh;

			cout << "\nThong tin nhan vien sau khi cap nhat:\n";
			xuatNV(ketqua->data);
		}
		else
			cout << "\nKhong tim thay nhan vien co ma so: " << MaNV << endl;
		break;

	case 5:
		cout << "\n5. Huy nhan vien co ma nhan vien cho truoc";
		cout << "\nNhap vao ma nhan vien: ";
		cin >> MaNV;

		ketqua = Search(MaNV, root);
		if (ketqua)
		{
			kq = deletenode(MaNV, root);

			if (kq)
				cout << "\nXoa thanh cong nhan vien co MaNV: " << MaNV << endl;
			else
				cout << "\nCo loi xay ra trong qua trinh!" << endl;
		}
		else
			cout << "\nKhong tim thay nhan vien co ma so: " << MaNV << endl;
		break;
	}
	cout << endl;
	system("pause");
}