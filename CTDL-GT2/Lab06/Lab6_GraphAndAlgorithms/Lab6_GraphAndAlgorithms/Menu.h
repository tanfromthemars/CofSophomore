﻿void Xuatmenu()
{
	cout << "\n======================== HE THONG CHUC NANG ================================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Doc du lieu tu tap tin";
	cout << "\n2. Tim cay bao trum toi thieu bang thuat toan Prim";
	cout << "\n3. Tim cay bao trum toi thieu bang thuat toan Kruskal";
	cout << "\n4. Tim duong di ngan nhat tu 1 dinh den cac dinh con lai bang thuat toan Dijkstra";
	cout << "\n5. Tim duong di ngan nhat giua moi cap dinh bang thuat toan Floyd";
	cout << "\n============================================================================";
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
	int stt, p1, p2;
	LabelType lab;
	char u, v;
	char filename[10] = "Text_.txt";
	Path tree1[MAX];
	Edge tree2[MAX];
	Path route[MAX][MAX];

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
		filename[4] = 'A' + stt - 1;
		if (OpenGraph(g, filename))
		{
			cout << "\nMa tran ke: ";
			DisplayMatrix(g);
		}
		else cout << "\nLoi mo file!";
		break;

	case 2:
		cout << "\n2. Tim cay bao trum toi thieu bang thuat toan Prim";
		ResetFlags(g);
		Prim(g, tree1);
		PrintPrimMST(g, tree1);
		break;

	case 3:
		cout << "\n3. Tim cay bao trum toi thieu bang thuat toan Kruskal";
		ResetFlags(g);
		Kruskal(g, tree2);
		PrintKruskalMST(g, tree2);
		break;

	case 4:
		cout << "\n4. Tim duong di ngan nhat tu 1 dinh den cac dinh con lai bang thuat toan Dijkstra\n";
		do
		{
			cout << "\nNhap ten dinh bat dau: ";
			cin >> u;
			p1 = FindIndexOfVertex(g, u);
		} while (p1 == -1);
		PrintAllPath_Dijkstra(g, p1);
		break;

	case 5:
		cout << "\n5. Tim duong di ngan nhat giua moi cap dinh bang thuat toan Floyd\n";
		Floyd(g, route);
		Print_AllFloydPath(g);
		break;
	default:
		break;
	}
	_getch();
}