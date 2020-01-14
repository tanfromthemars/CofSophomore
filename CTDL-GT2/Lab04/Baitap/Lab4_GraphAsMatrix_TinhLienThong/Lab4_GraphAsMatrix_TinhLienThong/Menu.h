void Xuatmenu()
{
	cout << "\n======================== HE THONG CHUC NANG ================================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Doc du lieu tu tap tin";
	cout << "\n2. Them mot dinh co nhan label vao do thi";
	cout << "\n3. Xuat thong tin cua mot dinh trong do thi";
	cout << "\n4. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong";
	cout << "\n5. Them mot canh co trong so ư noi 2 dinh u, v vao do thi";
	cout << "\n6. Luu thong tin do thi xuong file";
	cout << "\n7. Duyet do thi theo chieu rong";
	cout << "\n8. Duyet do thi theo chieu sau";
	cout << "\n9. Kiem tra xem do thi G co lien thong hay khong?";
	cout << "\n10. Xuat ma tran ke";
}

int Chonmenu(int somenu)
{
	int stt;
	while (true)
	{
		system("cls");
		Xuatmenu();
		cout << "\nNhap 1 so trong khoang [0.." << somenu << "]: ";
		cin >> stt;
		if (0 <= stt && stt <= somenu)
			break;
	}
	return stt;
}

void Xulymenu(int menu, Graph& g)
{
	//Khai báo các biến phục vụ các chức năng
	int stt;
	LabelType lab;
	int p1, p2;
	char u, v;
	int w;
	char filename[10];

	//Xử lý chức năng
	system("cls");
	switch (menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh\n";
		break;

	case 1:
		cout << "\n1. Doc du lieu tu tap tin\n";
		do
		{
			cout << "\nNhap thu tu cua file can mo (1 -> 6 tuong ung a -> f): ";
			cin >> stt;
		} while (stt < 1 || stt > 6);
		break;

	case 2:
		cout << "\n2. Them mot dinh co nhan label vao do thi\n";
		cout << "\nNhap ten dinh can them: ";
		cin >> lab;
		cout << "\nMa tran ban dau: ";
		DisplayMatrix(g);
		Addvertex(g, lab);
		cout << "\nMa tran moi: ";
		DisplayMatrix(g);
		break;

	case 3:
		cout << "\n3. Xuat thong tin cua mot dinh trong do thi\n";
		cout << "\nNhap ten dinh can xem: ";
		cin >> u;
		p1 = FindIndexOfVertex(g, u);
		if (p1 != -1)
			DisplayInfoVertex(g, p1);
		else cout << "\nKhong ton tai dinh co nhan la " << u;
		break;

	case 4:
		cout << "\n4. Kiem tra hai dinh u, v co ke nhau (co canh noi giua chung) hay khong";
		cout << "\nNhap dinh u: ";
		cin >> u;
		cout << "\nNhap dinh v: ";
		cin >> v;
		p1 = FindIndexOfVertex(g, u);
		p2 = FindIndexOfVertex(g, v);
		if (IsConnected(g, p1, p2))
			cout << "\nHai dinh " << u << " va " << v << " ke nhau";
		else
			cout << "\nHai dinh " << u << " va " << v << " khong ke nhau";
		break;

	case 5:
		cout << "\n5. Them mot canh co trong so w noi 2 dinh u, v vao do thi\n";
		do
		{
			cout << "\nNhap dinh u: ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		do
		{
			cout << "\nNhap dinh v: ";
			cin >> v;
			p2 = FindIndexOfVertex(g, v);
		} while (p2 == -1);
		do
		{
			cout << "\nNhap trong so w: ";
			cin >> w;
		} while (w < 1);
		cout << "\nDanh sach ban dau: ";
		DisplayMatrix(g);
		AddEdge(g, p1, p2, w);
		cout << "\nDanh sach moi: ";
		DisplayMatrix(g);
		break;

	case 6:
		cout << "\n6. Luu thong tin do thi xuong file\n";
		cout << "\nNhap ten file can luu thong tin do thi: ";
		cin >> filename;
		SaveGraph(g, filename);
		break;

	case 7:
		cout << "\n7. Duyet do thi theo chieu rong\n";
		do
		{
			cout << "\nNhap ten dinh bat dau: ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		BFS(g, p1);
		break;

	case 8:
		cout << "\n8. Duyet do thi theo chieu sau\n";
		do
		{
			cout << "\nNhap ten dinh bat dau: ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		DFS_Loop(g, p1);
		break;

	case 9:
		cout << "\n9.Kiem tra xem do thi G co lien thong hay khong?\n";
		TestGraphConnectivity(g);
		break;
		
	case 10:
		cout << "\n10. Xuat mat tran ke\n";
		DisplayMatrix(g);
		break;
	}
	_getch();
}