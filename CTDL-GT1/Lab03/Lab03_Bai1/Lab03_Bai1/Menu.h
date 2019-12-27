void Xuatmenu()
{
	cout << "\n================= HE THONG CHUC NANG ==================";
	cout << "\n1. Nhap danh sach lien ket tu file";
	cout << "\n2. Xuat danh sach lien ket";
	cout << "\n3. Tinh tong cac phan tu trong danh sach";
	cout << "\n4. Tim phan tu lon nhat trong danh sach";
	cout << "\n5. Tim X (First node)";
	cout << "\n6. Tim X (Final node)";
	cout << "\n7. Chen X vao dau danh sach";
	cout << "\n8. Chen X vao cuoi danh sach";
	cout << "\n9. Chen X vao sau node Y trong danh sach";
	cout << "\n10. Huy nut cuoi";
	cout << "\n11. Huy nut dau";
	cout << "\n12. Huy nut dau tien chua du lieu X";
	cout << "\n13. Huy toan bo danh sach";
	cout << "\n14. Sap tang danh sach (Chon doi du lieu)";
	cout << "\n15. Sap tang danh sach (Hoan doi lien ket)";
	cout << "\n0. Thoat chuong trinh";
}

int Chonmenu(int soMenu)
{
	int menu;

	while (true)
	{
		system("cls");
		Xuatmenu();
		cout << "\nChon chuc nang >> ";
		cin >> menu;

		if (0 <= menu && menu <= soMenu)
			break;
	}
	return menu;
}

void Xulymenu(int menu, LIST& ls)
{
	char filename[MAX];
	int kq, x, y;
	node* res;
	node* node; //Tao node moi

	switch (menu)
	{
	case 1:
		cout << "\n1. Nhap danh sach lien ket tu file";
		cout << "\nNhap ten file de mo: ";
		cin >> filename;
		kq = GetDatafromfile(filename, ls);
		if (!kq)
		{
			cout << "\nKhong the mo tap tin! Vui long kiem tra lai ten tap tin!";
			return;
		}
		displayList(ls);
		break;

	case 2:
		cout << "\n2. Xuat danh sach lien ket";
		displayList(ls);
		break;
		
	case 3:
		cout << "\n3. Tinh tong cac phan tu trong danh sach";
		displayList(ls);
		kq = calcsum(ls);
		cout << "\nTong cac phan tu hien tai: $" << kq << endl;
		break;

	case 4:
		cout << "\n4. Tim phan tu lon nhat trong danh sach";
		displayList(ls);
		res = findMAX(ls);
		cout << "\nPhan tu co gia tri lon nhat: " << res->info;
		break;

	case 5:
		cout << "\n5. Tim X (First node)";
		cout << "\nNhap 1 so bat ki de tim kiem: ";
		cin >> x;

		kq = search_first_index(ls, x);
		if (kq == -1)
			cout << "\nKhong ton tai " << x << " trong danh sach.\n";
		else
			cout << "\nTon tai " << x << " trong danh sach tai vi tri: " << (kq + 1) << endl;
		cout << "\nXem lai danh sach de kiem tra:\n";
		displayList(ls);
		break;

	case 6:
		cout << "\n6. Tim X (Final node)";
		cout << "\nNhap 1 so bat ki de tim kiem: ";
		cin >> x;

		kq = search_final_index(ls, x);
		if (kq == -1)
			cout << "\nKhong ton tai " << x << " trong danh sach.\n";
		else
			cout << "\nTon tai " << x << " trong danh sach tai vi tri: " << (kq + 1) << endl;
		cout << "\nXem lai danh sach de kiem tra: \n";
		displayList(ls);
		break;

	case 7:
		cout << "\n7. Chen X vao dau danh sach";
		cout << "\nMang hien tai: \n";
		displayList(ls);
		cout << "\nNhap gia tri can chen: ";
		cin >> x;
		node = getnode(x);
		insert_begin(ls, node);
		cout << "\nMang sau khi chen: ";
		displayList(ls);
		break;

	case 8:
		cout << "\n8. Chen X vao cuoi danh sach";
		cout << "\nMang hien tai: \n";
		displayList(ls);
		cout << "\nNhap gia tri can chen: ";
		cin >> x;
		node = getnode(x);
		insert_end(ls, node);
		cout << "\nMang sau khi chen: ";
		displayList(ls);
		break;

	case 9:
		cout << "\n9. Chen X vao sau node Y trong danh sach";
		displayList(ls);
		cout << "\nNhap vao gia tri node Y: ";
		cin >> y;

		res = search_first(ls, y);
		if (!res)
		{
			cout << "\nKhong tim thay phan tu " << y << " trong danh sach.\n";
		}
		else
		{
			cout << "\nNhap phan tu can chen: ";
			cin >> x;
			node = getnode(x);
			chenXsauY(ls, res, node);
			cout << "\nMang sau khi chen: \n";
			displayList(ls);
		}
		break;

	case 10:
		break;
	case 11:
		break;
	case 12:
		break;
	case 13:
		break;
	case 14:
		break;
	case 15:
		break;
	case 16:
		break;
	case 0:
		cout << "\nThoat chuong trinh";
		break;
	}
	cout << endl;
	system("pause");
}