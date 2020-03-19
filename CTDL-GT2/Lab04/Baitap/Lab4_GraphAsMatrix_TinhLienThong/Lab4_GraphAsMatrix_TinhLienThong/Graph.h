//Tạo một đỉnh có nhãn Lab
Vertex CreateVertex(LabelType lab)
{
	//Khai báo 1 biến v kiểu Vertex
	Vertex v;
	//Gán nhãn lab cho đỉnh v
	v.Label = lab;
	//Gán đỉnh v chưa xét
	v.Visited = NO;
	//Trả về v
	return v;
}

//Tìm chỉ số của một đỉnh, nếu không có thì trả về -1
int FindIndexOfVertex(Graph g, LabelType lab)
{
	for (size_t i = 0; i < MAX; i++)
		if (g.Vertices[i].Label == lab)
			return i;
	return -1;
}

//Hiển thị thông tin của một đỉnh dựa vào vị trí pos
void DisplayInfoVertex(Graph g, int pos)
{
	cout << "\nCac dinh ke voi " << g.Vertices[pos].Label << " la: ";
	for (size_t i = 0; i < g.NumVertices; i++)
		if (g.Cost[pos][i] != ZERO)
			cout << '\t' << g.Vertices[i].Label;
}

//Hiển thị thông tin đỉnh thứ pos trong đồ thị
void DisplayVertex(Graph g, int pos)
{
	cout << g.Vertices[pos].Label << '\t';
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

//Khởi tạo một đồ thị
//Directed = true: Đồ thị có hướng
Graph InitGraph(bool Directed)
{
	//Khai báo và khởi tạo một biến g kiểu graph;
	Graph g;
	//Khởi tạo số cạnh của g = 0
	g.NumEdges = 0;
	//Khởi tạo số đỉnh của g = 0
	g.NumVertices = 0;
	//Gán loại đồ thị = Directed; //Có hướng hay không
	g.Directed = Directed;
	
	//Khởi tạo ma trận kề (ma trận trọng số, chi phí)
	for (size_t i = 0; i < g.NumVertices; i++)//số đỉnh của g
		for (int j = 0; j < g.NumVertices; j++)//số đỉnh của g
		{
			if (i == j)//Đường đi từ một đỉnh tới chính nó thì = 0
				//Khởi tạo đường đi từ đỉnh i đến j = 0
				g.Cost[i][j] = 0;//Đường chéo chính
			else
				//Khởi tạo đường đi từ đỉnh i đến j = INF
				g.Cost[i][j] = INF; //Còn lại là vô cùng
		}
	return g;
}

//Thiết lập lại trạng thái của các đỉnh
void ResetFlags(Graph& g)
{
	for (int i = 0; i < g.NumVertices; i++)//số đỉnh của g
		//Thiết lập trường Visited của đỉnh i = NO
		g.Vertices[i].Visited = NO;
}

//Kiểm tra hai đỉnh start và end có được nối với nhau bởi 1 cạnh hay không
int IsConnected(Graph g, int start, int end)
{
	if (g.Cost[start][end] == 0 || g.Cost[start][end] == INF)//Chi phí đi từ start đến end = 0 hoặc INF
		return 0;//trả về 0
	else
		return 1;//trả về 1
}

//Thêm một đỉnh có nhãn lab vào đồ thị g
void Addvertex(Graph& g, LabelType lab)
{
	//Gọi hàm tạo một đỉnh v với nhãn lab
	Vertex v = CreateVertex(lab);
	//Đưa đỉnh v vào đồ thị g
	g.Vertices[g.NumVertices] = v;
	//Tăng số đỉnh của g lên 1;
	g.NumVertices++;

	g.Cost[g.NumVertices - 1][g.NumVertices - 1] = 0;
	for (size_t i = 0; i < g.NumVertices - 1; i++)
	{
		g.Cost[i][g.NumVertices - 1] = INF;
		g.Cost[g.NumVertices - 1][i] = INF;
	}
}

//Thêm một cạnh có trọng số là weight bắt đầu từ đỉnh start và kết thúc tại đỉnh end
//directed = false: Thêm cạnh vô hướng
void AddEdge(Graph& g, int start, int end, CostType weight, bool directed)
{
	if (IsConnected(g, start, end) == 0) //Hai đỉnh start, end không kề nhau
	{
		//Tăng số cạnh lên 1
		g.NumEdges++;
		//Gán chi phí đi từ start đến end = weight
		g.Cost[start][end] = weight;
		if (directed == false) //Nếu là đồ thị vô hướng
			//Gán chi phí đi từ end đến start = weight
			g.Cost[end][start] = weight;
	}
}

//Thêm một cạnh có trọng số là weight bắt đầu từ đỉnh start và kết thúc tại đỉnh end
void AddEdge(Graph& g, int start, int end, CostType weight)
{
	AddEdge(g, start, end, weight, g.Directed);
}

//Thêm một cạnh bắt đầu từ đỉnh start và kết thúc tại đỉnh end. Dùng cho đồ thị không có trọng số
void AddEdge(Graph& g, int start, int end)
{
	AddEdge(g, start, end, 1);
}

//Lưu đồ thị xuống file
void SaveGraph(Graph g, char* filename)
{
	//Khai báo biến và mở tập tin để ghi
	ofstream os(filename);
	//Lưu số đỉnh
	os << g.NumVertices << '\n';
	//Lưu số cạnh
	os << g.NumEdges << '\n';
	//Lưu loại đồ thị
	os << g.Directed << '\n';
	//Lưu tên các đỉnh
	for (size_t i = 0; i < g.NumVertices; i++)
		os << g.Vertices[i].Label << '\n';
	//Lưu ma trận kề
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			os << g.Cost[i][j] << '\t';
		}
		os << '\n';
	}
	os.close();
}

int OpenGraph(Graph& g, char* filename)
{
	//Khai báo biến và mở file để đọc
	ifstream is(filename);
	//Kiểm tra đã mở được file chưa?
	if (is.is_open())//Nếu mở file thành công
	{
		int n = 0, m = 0;
		bool d = false;
		LabelType lab;

		//Đọc số đỉnh của đồ thị đưa vào biến n
		is >> n;
		//Đọc số cạnh của đồ thị đưa vào biến m
		is >> m;
		//Đọc loại đồ thị đưa vào biến d
		is >> d;

		int t;
		//Khởi tạo đồ thị g
		g = InitGraph(d);
		//Gán số cạnh m của đồ thị vào g.NumEdges
		g.NumEdges = m;
		//Khởi tạo nhãn của các đỉnh
		for (size_t i = 0; i < n; i++)
		{
			//Đọc nhãn đưa vào biến lab
			is >> lab;
			//Gọi hàm thêm đỉnh có nhãn lab vào đồ thị
			Addvertex(g, lab);
		}
		//Đọc ma trận kề từ file
		for (size_t i = 0; i < n; i++)
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

int FindFirstAdjacentVertex(Graph g, int curr)
{
	//Duyệt qua mọi đỉnh
	for (int i = 0; i < g.NumVertices; i++)//số đỉnh của g
	{
		//Kiểm tra đỉnh đã xét chưa và kề với curr không
		if (g.Vertices[i].Visited == NO && IsConnected(g, curr, i) == 1)//Đỉnh i chưa được xét và có cạnh nối từ curr đến i
			return i;//Thỏa điều kiện -> Tìm thấy
	}
	NULLDATA;//Không tìm thấy
}

//Duyệt đồ thị theo chiều sâu (Depth First Search)
//Mô tả: đi tiếp đến khi nào không đi đến được nữa thì lùi lại và tìm đường mới
void DFS_Recursion(Graph& g, int start)
{
	g.Vertices[start].Visited = YES;
	DisplayVertex(g, start);
	while (true)
	{
		int t = FindFirstAdjacentVertex(g, start);
		if (t == NULLDATA)
			break;
		DFS_Recursion(g, t);
	}
}

int DFS_Loop(Graph& g, int start)	
{
	ResetFlags(g);
	g.Vertices[start].Visited = YES;
	DisplayVertex(g, start);
	int count = 1;
	stack<int>s;
	s.push(start);
	int curr, adj;
	while (!s.empty())
	{
		curr = s.top();
		adj = FindFirstAdjacentVertex(g, curr);
		if (adj == NULLDATA)
			s.pop();
		else
		{
			g.Vertices[adj].Visited = YES;
			DisplayVertex(g, adj);
			count++;
			s.push(adj);
		}
	}
	return count;
}

//Duyệt đồ thị theo chiều rộng (Breadth First Search)
//Mô tả: đi từ gốc, sau đó đi tới các đỉnh kề với đỉnh gốc và tiếp tục đi tới các đỉnh khác
void BFS(Graph g, int start)
{
	ResetFlags(g);
	g.Vertices[start].Visited = YES;
	queue<int>q;
	q.push(start);
	int curr, adj;
	while (!q.empty())
	{
		curr = q.front();
		q.pop();
		DisplayVertex(g, curr);
		while (true)
		{
			adj = FindFirstAdjacentVertex(g, curr);
			if (adj == NULLDATA)
				break;
			else
			{
				g.Vertices[adj].Visited = YES;
				q.push(adj);
			}
		}
	}
}

//Kiểm tra tính liên thông của đồ thị
//Mô tả: Một đồ thị được gọi la liên thông (connected) nếu có đường đi giữa mọi cặp đỉnh phân biệt của đồ thị
void TestGraphConnectivity(Graph g)
{
	int count = 0, flag = 0;
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		if (g.Vertices[i].Visited == NO)
		{
			count++;
			cout << "\nThanh phan lien thong thu " << count << ": \t";
			if (DFS_Loop(g, i) == g.NumVertices)
				flag = 1;
		}
	}
	cout << "\nCon lai " << count << " lan duyet.";
	if (flag)
		cout << "\nLien thong!";
	else cout << "\nKhong lien thong!";
}