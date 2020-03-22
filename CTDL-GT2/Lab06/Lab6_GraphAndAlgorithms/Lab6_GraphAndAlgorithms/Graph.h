//Tìm chỉ số của một đỉnh, nếu không có thì trả về -1
int FindIndexOfVertex(Graph g, LabelType l)
{
	for (size_t i = 0; i < MAX; i++)
		if (g.Vertices[i].Label == l)
			return i;
	return -1;
}

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
//Mô tả: Tìm cây bao trùm nhỏ nhất theo thuật toán prim, kết quả được lưu trong mảng tree, chỉ số mảng i là đỉnh nguồn, tree[i].Parent là đỉnh cuối và tree[i].Length là trọng số của cạnh được chọn
void Prim(Graph g, Path tree[MAX])
{
	//Khởi tạo cây ban đầu có tất cả các cạnh xuất phát từ đỉnh đầu tiên (đỉnh 0)
	for (size_t i = 1; i < g.NumVertices; i++)//số đỉnh của g
	{
		tree[i].Length = g.Cost[0][i];
		tree[i].Parent = 0;
	}
	CostType min;	//Lưu cạnh có trọng số nhỏ nhất
	int minVertex;	//Lưu đỉnh cuối của cạnh đó
	//Tìm n-1 cạnh cho cây bao trùm
	for (size_t i = 1; i < g.NumVertices; i++)//số đỉnh của g
	{
		min = INF;	//giả sử min = vô cùng
		minVertex = 1;
		//Duyệt qua các cạnh để tìm cạnh min
		for (size_t j = 1; j < g.NumVertices; j++)
			if (g.Vertices[j].Visited == NO && tree[j].Length < min)//Đỉnh j chưa được xét
			{
				min = tree[j].Length;
				minVertex = j;
			}
		//Đánh dấu đỉnh cuối của cạnh min là đã xét
		g.Vertices[minVertex].Visited = YES;
		//Cập nhật lại trọng số của các cạnh với đỉnh nguồn bây giờ là minVertex
		for (size_t j = 0; j < g.NumVertices; j++)	//Thêm vào cây
			if (g.Vertices[j].Visited == NO && g.Cost[minVertex][j] < tree[j].Length)//Đỉnh j chưa được xét
			{
				tree[j].Length = g.Cost[minVertex][j];
				tree[j].Parent = minVertex;
			}
	}
}
//Xuất danh sách cạnh được chọn làm cây bao trùm theo thuật toán Prim
void PrintPrimMST(Graph g, Path tree[MAX])
{
	cout << endl << "Cay bao trum gom cac canh sau: ";
	CostType sum = 0; //Lưu tổng trọng số
	cout << endl << '|' << setw(10) << "Dinh dau " << '|' << setw(10) << "Dinh cuoi" << '|' << setw(10) << "Trong so" << '|';
	//Duyệt qua các đỉnh để tìm cạnh nối với đỉnh đó và nằm trong cây bao trùm tối thiểu
	for (size_t i = 1; i < g.NumVertices; i++)
	{
		sum += tree[i].Length;//Cập nhật tổng trọng số
		cout << endl << '|' << setw(10) << g.Vertices[tree[i].Parent].Label << '|' << setw(10) << g.Vertices[i].Label << '|' << setw(10) << tree[i].Length << '|';//Xuất nhãn của đỉnh đầu, nhãn của đỉnh cuối, chiều dài (trọng số)
	}
	cout << "\nCay bao trum ngan nhat co chieu dai: " << sum;
}

//Kruskal
//Duyệt ma trận kề và lấy ra danh sách các cạnh của đồ thị. Mỗi cạnh lưu đỉnh đầu, cuối và trọng số
int AdjMatrix2EdgeList(Graph g, Edge edgeList[UPPER])
{
	int count = 0;//lưu số cạnh
		for (size_t  i = 1; i < g.NumVertices; i++)//Duyệt nửa dưới của ma trận kề
			for (size_t j = 0; j < i; j++)
				if (g.Cost[i][j] != 0 && g.Cost[i][j] != 1000)//có cạnh nối 2 đỉnh i và j
				{
					Edge v;//tạo cạnh v
					v.Source = i;//gán đỉnh nguồn của v = i;
					v.Target = j;//gán đỉnh đích của v = j;
					v.Weight = g.Cost[i][j];//gán trọng số của v = chi phí đi từ đỉnh i đến đỉnh j
					v.Marked = NO;//Đánh dấu cạnh v chưa được xét 
					edgeList[count] = v;//Đưa cạnh v vào danh sách edgelist
					count++;//Tăng số cạnh (count) lên 1;
				}
		return count;
}

//Sắp xếp danh sách cạnh tăng dần theo trọng số của cạnh
void QuickSortEdges(Edge edgeList[MAX], int d, int c)
{
	int i = d, j = c;//d = đầu, c = cuối
	//Giá trị ở giữa mảng
	CostType mid = edgeList[(d + c) / 2].Weight;
	//Tiến hành tách mảng thành 2 phần
	while (i <= j)
	{
		//Tìm các phần tử đứng sai vị trí trong mảng
		while (edgeList[i].Weight < mid)i++;
		while (edgeList[j].Weight > mid)j--;
		//Nếu có 2 phần tử sai vị trí -> Hoán vị chúng
		if (i <= j)
		{
			swap(edgeList[i], edgeList[j]);
			i++;
			j--;
		}
	}
	//Sắp xếp mảng con bên phải mid
	if (i < c)QuickSortEdges(edgeList, i, c);
	//Sắp xếp mảng con bên trái mid
	if (d < j)QuickSortEdges(edgeList, d, j);
}

//Tìm nút gốc của cây chứa đỉnh x
int Find(int leader[MAX], int x)
{
	//Chừng nào chưa tìm thấy gốc thì
	while (x != leader[x])x = leader[x];//chuyển đến nút cha
	return x;
}

//Hợp 2 cây bằng cách nối thêm cạnh e
bool Union(int leader[MAX], Edge e)
{
	int x = Find(leader, e.Source);//Tìm nút gốc của cây chứa đỉnh e.Source
	int y = Find(leader, e.Target);//Tìm nút gốc của cây chứa đỉnh e.Target
	if (x == y)	//Nếu trùng gốc
		return false;//->không thêm cạnh
	else if (x < y)	//Nhập chung cây y vào cây x hay cây chứa y có gốc là x
		leader[y] = x;
	else leader[x] = y;//Nhập chung cây x vào y
	return true;
}

//Thuật toán kruskal tìm cây bao trùm tối thiểu. Kết quả được lưu trong mảng tree. Chỉ số mảng i là đỉnh nguồn, tree[i].Parent là đỉnh cuối và tree[i].Length là trọng số của cạnh được chọn
void Kruskal(Graph g, Edge tree[UPPER])
{
	//Tạo ra danh sách các cạnh từ ma trận kề
	int ne = AdjMatrix2EdgeList(g, tree);
	//Sắp xếp các cạnh tăng dần theo trọng số
	QuickSortEdges(tree, 0, ne - 1);
	//Khởi tạo đỉnh gốc của các cây con
	int leader[MAX];
	for (size_t i = 0; i < g.NumVertices + 1; i++)
		leader[i] = i;
	//Duyệt các cạnh tăng dần theo trọng số
	int count = 0;
	for (size_t i = 0; i < ne; i++)
	{
		//Nếu có thể ghép nó vào cây bao trùm
		if (Union(leader, tree[i])) 
		{
			tree[i].Marked = YES;//Đánh dấu chọn
			count++;//Tăng biến đếm
			//Nếu đã chọn đủ n-1 cạnh cho cây
			if (count == g.NumVertices - 1)
				break;//thì dừng
		}
	}
}

//Xuất danh sách các cạnh được chọn để tạo cây bao trùm nhỏ nhất theo thuật toán Kruskal
void PrintKruskalMST(Graph g, Edge tree[UPPER])
{
	cout << endl << "Cay bao trum gom cac canh sau: ";
	CostType sum = 0;//Lưu tổng chiều dài cây
	cout << endl << '|' << setw(10) << "Dinh dau" << '|' << setw(10) << "Dinh cuoi" << '|' << setw(10) << "Trong so" << '|';
	//Duyệt qua các đỉnh
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

//Thuật toán Dijkstra tìm đường đi ngắn nhất từ đỉnh nguồn source đến tất cả các đỉnh còn lại. Độ dài đường đi được lưu trong mảng label, đường đi lưu trong mảng path
void Dijkstra(Graph g, int source, Path road[MAX])
{
	CostType min; //Lưu độ dài đường đi ngắn nhất
	int counter, //Đếm số đỉnh đã xét
		minVertex, //Lưu đỉnh có nhãn nhỏ nhất
		curr; //Đỉnh hiện tại đang xét

	//Khởi gán giá trị cho các đoạn đường đi
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		road[i].Length = g.Cost[source][i];
		road[i].Parent = source;
	}
	g.Vertices[source].Visited = YES;//Đánh dấu đỉnh source đã được xét
	counter = 1;//Có 1 đỉnh đã xét
	curr = source;//Bắt đầu từ nguồn

	//Trong khi chưa xét hết các đỉnh
	while (counter < g.NumVertices - 1)
	{
		min = INF; //Giả sử min = vô cùng
		minVertex = curr; //Đỉnh min = đỉnh hiện tại

		//Duyệt qua từng đỉnh để kiểm tra
		for (size_t i = 0; i < g.NumVertices; i++)
		{
			if (g.Vertices[i].Visited == NO)
			{
				//Gán lại nhãn cho các đỉnh
				if (road[i].Length > road[curr].Length + g.Cost[curr][i]);
				{
					road[i].Length = road[curr].Length + g.Cost[curr][i];
					road[i].Parent = curr;
				}
				//Tìm đỉnh có nhãn nhỏ nhất
				if (min > road[i].Length)
				{
					min = road[i].Length;
					minVertex = i;
				}
			}
		}
		curr = minVertex; //Xét đỉnh có nhãn nhỏ nhất
		g.Vertices[curr].Visited = YES;//Đánh dấu đỉnh curr là đã xét
		counter++;//Tăng số đỉnh đã xét lên 1
	}
}

//In ra đường đi từ đỉnh nguồn tới đỉnh đích target
void PrintPath_Dijkstra(Graph g, Path road[MAX], int target)
{
	//Nếu chưa gặp đỉnh nguồn
	if (road[target].Parent != target)
		//thì tìm đường từ nguồn tới đỉnh trước target
		PrintPath_Dijkstra(g, road, road[target].Parent);
	//Sau đó in ra nhãn của đỉnh trên đường đi
	cout << " -> " << g.Vertices[target].Label;
}

//In các đoạn đường đến casd đỉnh
void PrintAllPath_Dijkstra(Graph g, int start)
{
	Path road[MAX];
	Dijkstra(g, start, road);
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		if (road[i].Length == INF)
			cout << "\nKhong co duong di tu " << g.Vertices[start].Label << " den " << g.Vertices[i].Label;
		else if (i != start)
		{
			cout << "\nDoan duong tu " << g.Vertices[start].Label << " den " << g.Vertices[i].Label << " la: ";
			PrintPath_Dijkstra(g, road, i);
			cout << "\t(Tong do dai: " << road[i].Length << ')';
		}
	}
}

//Tìm đường đi ngắn nhất giữa mọi cặp đỉnh theo thuật toán Floyd
void Floyd(Graph g, Path route[MAX][MAX])
{
	int i, j, k;

	//Khởi tạo chiều dài đường đi giữa các cặp đỉnh
	for (size_t i = 0; i < g.NumVertices; i++)
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			route[i][j].Length = g.Cost[i][j];
			route[i][j].Parent = i;
		}
	//Tính toán lại đường đi giữa các cặp đỉnh
	for (size_t k = 0; k < g.NumVertices; k++)
		for (size_t i = 0; i < g.NumVertices; i++)
			for (size_t j = 0; j < g.NumVertices; j++)
				//Nếu đường đi từ i -> j qua đỉnh k ngắn hơn đường đi trực tiếp i -> j
				if (route[i][j].Length > route[i][k].Length + route[k][j].Length)
				{
					//Thì cập nhật lại độ dài đường đi giữa 2 đỉnh i & j
					route[i][j].Length = route[i][k].Length + route[k][j].Length;
					//Cập nhật đỉnh trung gian
					route[i][j].Parent = route[k][j].Parent;
				}
}

//Xuất đường đi ngắn nhất từ đỉnh source đến đỉnh target 
//Ma trận road lưu độ dài đường đi ngắn nhất và đường đi
void Print_FloydPath(Graph g, Path route[MAX][MAX], int source, int target)
{
	if (route[source][target].Parent != target)
		Print_FloydPath(g, route, source, route[source][target].Parent);
	//Sau đó in ra nhãn của đỉnh trên đường đi
	cout << " -> " << g.Vertices[target].Label;
}

void Print_AllFloydPath(Graph g)
{
	Path route[MAX][MAX];
	Floyd(g, route);
	for (size_t i = 0; i < g.NumVertices; i++, cout << endl)
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			if (route[i][j].Length = INF)
				cout << "\nKhong co duong di tu dinh " << g.Vertices[i].Label << g.Vertices[i].Label << " den dinh " << g.Vertices[j].Label;
			else if (i != j)
			{
				cout << "\nDoan duong tu dinh " << g.Vertices[i].Label << " den dinh " << g.Vertices[j].Label << " la: ";
				Print_FloydPath(g, route, i, j);
			}
		}
}