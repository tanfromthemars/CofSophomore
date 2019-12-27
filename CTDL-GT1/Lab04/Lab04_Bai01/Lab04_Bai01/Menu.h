void Xuatmenu()
{
	cout << "\n================== HE THONG CHUC NANG ===================";
	cout << "\n1. Them mot node o dau stack.";
	cout << "\n2. Huy mot node o dau stack.";
	cout << "\n3. Dem so lan xuat hien cua X trong stack.";
	cout << "\n4. Xoa toan bo nhung node co du lieu X trong stack.";
	cout << "\n5. Xem du lieu.";
	cout << "\n0. Thoat chuong trinh.";
}

int Chonmenu(int soMenu)
{
	int chon;

	while (true)
	{
		system("cls");
		Xuatmenu();
		cout << "\nChon cac so [0.." << soMenu << "] de chon chuc nang tuong ung: ";
		cin >> chon;

		if (0 <= chon && chon <= soMenu)
			break;
	}
	return chon;
}

void Xulymenu(int menu, stack& s)
{
	Data data;
	NODE* p;
	stack res;

	switch (menu)
	{
	case 1:
		cout << "\n1. Them mot node o dau stack";
		cout << "\nStack truoc khi chen 1 phan tu moi: ";
		displaystack(s);
		cout << "\nNhap vao 1 gia tri: ";
		cin >> data;

		p = Createnode(data);
		inserthead(s, p);

		cout << "\nStack sau khi chen 1 phan tu moi: ";
		displaystack(s);

		break;

	case 2:
		cout << "\n2. Huy mot node o dau stack.";
		cout << "\nstack ban dau: ";
		displaystack(s);

		removehead(s);

		cout << "\nStack sau khi xoa 1 phan tu: ";
		displaystack(s);
		break;

	case 3:
		cout << "\n3. Dem so lan xuat hien cua X trong stack.";
		cout << "\nStack ban dau: ";
		displaystack(s);

		cout << "\nNhap phan tu can dem: ";
		cin >> data;

		cout << "\nSo lan xuat hien cua phan tu " << data << " trong danh sach: " << count_x(s, data);
		break;

	case 4:
		cout << "\n4. Xoa toan bo nhung node co du lieu X trong stack.";
		cout << "\nStack ban dau: ";
		displaystack(s);

		cout << "\nNhap vao 1 phan tu: ";
		cin >> data;
		res = remove_all_x(s, data);

		cout << "\nStack sau khi xoa tat ca phan tu bang X: ";
		displaystack(res);
		break;

	case 5:
		cout << "\n5. Xem du lieu";
		cout << "\nStack hien tai: \n";
		displaystack(s);
		break;

	case 0:
		cout << "\n0. Thoat chuong trinh.";
		break;
	}
	cout << endl;
	system("pause");
}