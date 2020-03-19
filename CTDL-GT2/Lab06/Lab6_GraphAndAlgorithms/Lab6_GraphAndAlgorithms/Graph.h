//Xuất ma trận kề
void DisplayMatrix(Graph g)
{
	cout << endl;
	int t;
	for (size_t i = 0; i < g.NumVertices; i++)
		cout << '\t' << g.Vertices[i].Label;
	cout << endl;
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		cout << g.Vertices[i].Label << '\t';
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			t = g.Cost[i][j];
			if (t == 1000)
				cout << "INF";
			else
				cout << t;
			cout << '\t';
		}
		cout << endl;
	}
}

//Khởi tạo đồ thị
Graph InitGraph(bool directed)
{
	Graph g;
	g.NumEdges = 0;
	g.NumVertices = 0;
	g.Directed = directed;
	for (size_t i = 0; i < g.NumVertices; i++)
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			if (i == j)
				g.Cost[i][j] = 0; //Đường chéo chính
			else
				g.Cost[i][j] = INF; //Còn lại là vô cùng
		}
	return g;
}

//Tạo một đỉnh có nhãn l
Vertex CreateVertex(LabelType l)
{
	Vertex v;
	v.Label = l;
	v.Visited = NO;
	return v;
}

//Thêm một đỉnh có nhãn l vào đồ thị
void AddVertex(Graph& g, LabelType l)
{
	Vertex v = CreateVertex(l);
	g.Vertices[g.NumVertices] = v;
	g.NumVertices++;
	g.Cost[g.NumVertices - 1][g.NumVertices - 1] = 0;
	for (size_t i = 0; i < g.NumVertices - 1; i++)
	{
		g.Cost[i][g.NumVertices - 1] = INF;
		g.Cost[g.NumVertices - 1][i] = INF;
	}
}

//Đọc dữ liệu từ tập tin
int OpenGraph(Graph& g, char* filename)
{
	ifstream is(filename);
	if (is.is_open())
	{
		int n = 0, m = 0;
		bool d = false;
		LabelType l;
		is >> n;	//Số đỉnh
		is >> m;	//Số cạnh
		is >> d;	//Loại đồ thị
		int t;
		g = InitGraph(d);
		g.NumEdges = m;
		for (size_t i = 0; i < n; i++)	//Khởi tạo nhãn của các đỉnh
		{
			is >> l;
			AddVertex(g, l);
		}
		for (size_t i = 0; i < n; i++)	//Đọc ma trận kề
			for (size_t j = 0; j < n; j++)
			{
				is >> t;
				if (t != 0)
					g.Cost[i][j] = t;
			}
		is.close();
		return 1;
	}
	else
		return 0;
}

//Thiết lập lại trạng thái của các đỉnh
void ResetFlags(Graph& g)
{
	for (int i = 0; i < g.NumVertices; i++)//số đỉnh của g
		//Thiết lập trường Visited của đỉnh i = NO
		g.Vertices[i].Visited = NO;
}

//Prim
void Prim(Graph g, Path tree[MAX])
{
	for (size_t i = 1; i < g.NumVertices; i++)	//Khởi tạo cây ban đầu
	{
		tree[i].Length = g.Cost[0][i];
		tree[i].Parent = 0;
	}
	CostType min;	//Lưu cạnh có trọng số nhỏ nhất
	int minVertex;	//Lưu đỉnh cuối của cạnh đó
	for (size_t i = 1; i < g.NumVertices; i++)	//Tìm n-1 cạnh cho cây
	{
		min = INF;
		minVertex = 1;
		for (size_t j = 1; j < g.NumVertices; j++)	//Tìm cạnh min
			if (g.Vertices[j].Visited == NO && tree[j].Length < min)
			{
				min = tree[j].Length;
				minVertex = j;
			}
		g.Vertices[minVertex].Visited = YES;
		for (size_t j = 0; j < g.NumVertices; j++)	//Thêm vào cây
			if (g.Vertices[j].Visited == NO && g.Cost[minVertex][j] < tree[j].Length)
			{
				tree[j].Length = g.Cost[minVertex][j];
				tree[j].Parent = minVertex;
			}
	}
}

void PrintPrimMST(Graph g, Path tree[MAX])
{
	cout << endl << "Cay bao trum gom cac canh sau: ";
	CostType sum = 0;
	cout << endl << '|' << setw(10) << "Dinh dau " << '|' << setw(10) << "Dinh cuoi" << '|' << setw(10) << "Trong so" << '|';
	for (size_t i = 1; i < g.NumVertices; i++)
	{
		sum += tree[i].Length;
		cout << endl << '|' << setw(10) << g.Vertices[tree[i].Parent].Label << '|' << setw(10) << g.Vertices[i].Label << '|' << setw(10) << tree[i].Length << '|';
	}
	cout << "\nCay bao trum ngan nhat co chieu dai: " << sum;
}

//Kruskal
//Lấy danh sách cạnh
int AdjMatrix2EdgeList(Graph g, Edge edgeList[UPPER])
{
	int count = 0;
		for (size_t  i = 1; i < g.NumVertices; i++)
			for (size_t j = 0; j < i; j++)
				if (g.Cost[i][j] != 0 && g.Cost[i][j] != 1000)
				{
					Edge v;
					v.Source = i;
					v.Target = j;
					v.Weight = g.Cost[i][j];
					v.Marked = NO;
					edgeList[count] = v;
					count++;
				}
		return count;
}

//Sắp xếp danh sách cạnh
void QuickSortEdges(Edge edgeList[MAX], int d, int c)
{
	int i = d, j = c;
	CostType mid = edgeList[(d + c) / 2].Weight;
	while (i <= j)
	{
		while (edgeList[i].Weight < mid)i++;
		while (edgeList[j].Weight > mid)j--;
		if (i <= j)
		{
			swap(edgeList[i], edgeList[j]);
			i++;
			j--;
		}
	}
	if (i < c)QuickSortEdges(edgeList, i, c);
	if (d < j)QuickSortEdges(edgeList, d, j);
}

//Tìm nút gốc của cây chứa đỉnh x
int Find(int leader[MAX], int x)
{
	while (x != leader[x])x = leader[x];
	return x;
}

//Hợp 2 cây bằng cách nối thêm cạnh e
bool Union(int leader[MAX], Edge e)
{
	int x = Find(leader, e.Source);
	int y = Find(leader, e.Target);
	if (x == y)	//Nếu trùng gốc
		return false;
	else if (x < y)	//Nhập cây y vào cây x
		leader[y] = x;
	else leader[x] = y;
	return true;
}

void Kruskal(Graph g, Edge tree[UPPER])
{
	int ne = AdjMatrix2EdgeList(g, tree);
	QuickSortEdges(tree, 0, ne - 1);
	int leader[MAX];
	for (size_t i = 0; i < g.NumVertices + 1; i++)	//Khởi tạo đỉnh gốc của cây con
		leader[i] = i;
	int count = 0;
	for (size_t i = 0; i < ne; i++)
	{
		if (Union(leader, tree[i]))	//Nếu ghép được vào cây bao trùm 
		{
			tree[i].Marked = YES;
			count++;
			if (count == g.NumVertices - 1)	//Nếu đủ n-1 cạnh
				break;
		}
	}
}

void PrintKruskalMST(Graph g, Edge tree[UPPER])
{
	cout << endl << "Cay bao trum gom cac canh sau: ";
	CostType sum = 0;
	cout << endl << '|' << setw(10) << "Dinh dau" << '|' << setw(10) << "Dinh cuoi" << '|' << setw(10) << "Trong so" << '|';
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		if (tree[i].Marked == YES)
		{
			cout << endl << '|' << setw(10) << g.Vertices[tree[i].Source].Label << '|' << setw(10) << g.Vertices[tree[i].Target].Label << '|' << setw(10) << tree[i].Weight << '|';
			sum += tree[i].Weight;
		}
	}
	cout << endl << "Tong chieu dai cay bao trum la " << sum;
}