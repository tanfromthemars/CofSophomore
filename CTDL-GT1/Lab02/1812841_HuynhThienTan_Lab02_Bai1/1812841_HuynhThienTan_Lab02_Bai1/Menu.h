#pragma once
void xuatMenu();
int chonMenu(int soMenu);
void XulyMenu(int menu, int a[], int& n);

void xuatMenu()
{
	cout << "\n================= MENU CHUC NANG =================";
	cout << "\n1. Doc mang tu file";
	cout << "\n2. Xuat mang";
	cout << "\n3. Chon truc tiep";
	cout << "\n4. Chen truc tiep";
	cout << "\n5. Doi cho truc tiep";
	cout << "\n6. Noi bot";
	cout << "\n7. Chen nhi phan";
	cout << "\n0. Thoat khoi chuong trinh";
}

int chonMenu(int soMenu)
{
	int chon;
	while (true)
	{
		system("cls");
		xuatMenu();
		cout << "\nChon 1 chuc nang >> ";
		cin >> chon;
		
		if (0 <= chon && chon <= soMenu)
			break;
	}
	return chon;
}

void XulyMenu(int menu, int a[], int& n)
{
	char filename[MAX];
	int kq;
	
	switch (menu)
	{
	case 1:
		cout << "\n1. Doc tu mang tu file";
		cout << "\nNhap ten file: ";
		cin >> filename;
		
		kq = Docmang(a, n, filename);
		if (!kq)
		{
			cout << "\nLoi mo file (" << filename << "). Vui long kiem tra lai tren tap tin: ";
			cout << endl;
			system("pause");
			exit(-1);
		}
		
		cout << "\nMang doc tu file" << filename;
		Xuatmang(a, n);
		
		break;
	
	case 2:
		cout << "\n2. Xuat mang";
		cout << "\nMang hien tai gom " << n << " phan tu: \n";
		Xuatmang(a, n);
		
		break;
	
	case 3:
		cout << "\n3. Chon truc tiep";
		cout << "\nMang truoc khi sap xep: \n";
		Xuatmang(a, n);
		
		Chentructiep(a, n);
		cout << "\nMang sau khi sap xep tang dan:\n";
		Xuatmang(a, n);
		
		break;
	
	case 4:
		cout << "\n4. Chen truc tiep";
		cout << "\nMang truoc khi sap xep: \n";
		Xuatmang(a, n);

		Chentructiep(a, n);
		cout << "\nMang sau khi sap xep tang dan:\n";
		Xuatmang(a, n);

		break;

	case 5:
		cout << "\n5. Doi cho truc tiep";
		cout << "\nMang truoc khi sap xep: \n";
		Xuatmang(a, n);

		Doichotructiep(a, n);
		cout << "\nMang sau khi sap xep tang dan: \n";
		Xuatmang(a, n);

		break;
	
	case 6:
		cout << "\n6. Noi bot";
		cout << "\nMang truoc khi sap xep: \n";
		Xuatmang(a, n);

		BubbleSort(a, n);
		cout << "\nMang sau khi sap xep tang dan: \n";
		Xuatmang(a, n);

		break;
	
	case 0:
		cout << "\n0. Thoat chuong trinh";
		break;
	}
	system("pause");
}