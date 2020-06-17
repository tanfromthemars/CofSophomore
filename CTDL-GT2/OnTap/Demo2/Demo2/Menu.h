void XuatMenu()
{
	cout << "\n=============HE THONG CHUC NANG=================";
	cout << "\n0. Thoat khoi chuong trinh";
	cout << "\n1. Doc du lieu tu tap tin";
	cout << "\n2. Tim cay bao trum toi thieu bang thuat toan Prim";
	cout << "\n3. Tim cay bao trum toi thieu bang thuat toan Kruskal";
	cout << "\n4. Tim duong di ngan nhat tu 1 dinh den cac dinh con lai bang thuat toan Djikstra";
	cout << "\n5. Tim duong di ngan nhat bang thuat toan Floyd";
	cout << "\n================================================";
}

int ChonMenu(int SoMenu)
{
	int stt;
	while (true)
	{
		system("cls");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang[0.." << SoMenu << "]: ";
		cin >> stt;
		if (0 <= stt && stt <= SoMenu)
			break;
	}
	return stt;
}

void XulyMenu(int Menu, Graph& g)
{
	int stt, p1, p2;
	LabelType lab;
	char u, v;
	char filename[10] = "Text_.txt";
	Path tree1[MAX];
	Edge tree2[MAX];
	Path route[MAX][MAX];

	system("cls");
	switch (Menu)
	{
	case 0:
		cout << "\n0. Thoat khoi chuong trinh";
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
		ResetFalgs(g);
		Prim(g, tree1);
		PrintPrimPST(g, tree1);
		break;

	case 3:
		cout << "\n3. Tim cay bao trum toi thieu bang thuat toan Kruskal";
		ResetFalgs(g);
		Kruskal(g, tree2);
		PrintKruskalMST(g, tree2);
		break;

	case 4:
		cout << "\n4. Tim duong di ngan nhat bang thuat toan Djikstra";
		do
		{
			cout << "\nNhap ten dinh bat dau: ";
			cin >> u;
			p1 = FindIndexofVertex(g, u);
		} while (p1 == -1);
		PrintAllPath_Djikstra(g, p1);
		break;

	case 5:
		cout << "\n5. Tim duong di ngan nhat giua moi cap dinh bang thuat toan Floyd";
		Floyd(g, route);
		Print_AllFloydPath(g);
		break;
	default:
		break;
	}
}