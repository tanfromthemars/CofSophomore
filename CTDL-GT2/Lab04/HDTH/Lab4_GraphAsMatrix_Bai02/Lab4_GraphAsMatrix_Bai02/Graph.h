//Tạo một đỉnh có nhãn Lab
Vertex CreateVertex(LabelType Lab)
{
	Vertex v; //Khai báo 1 biến v kiểu Vertex
	v.Label = Lab; //Gán nhãn Lab cho đỉnh v
	v.Visited = NO; //Gán đỉnh v chưa xét
	return v; //Trả về v
}

//Hiển thị thông tin đỉnh thứ pos trong đồ thị
void DisplayVertex(Graph g, int pos)
{
	cout << g.Vertices[pos].Label << "\t";
}

//Hàm khởi tạo một đồ thị
//directed = true -> đồ thị có hướng
Graph InitGraph(bool Directed)
{
	Graph g; //Khai báo và khởi tạo 1 biến g kiểu Graph
	g.NumEdges = 0; //Khởi tạo số cạnh của g = 0
	g.NumVertices = 0; //Khởi tạo số đỉnh của g = 0
	g.Directed = Directed; //Gán loại đồ thị = directed (có hướng hay không?)

	//Khởi tạo ma trận kề (ma trận trọng số, chi phí)
	for (int i = 0; i < g.NumVertices; i++)
		for (int j = 0; j < g.NumVertices; j++)
		{
			if (i == j) //Đường đi từ một đỉnh tới chính nó thì = 0
				g.Cost[i][j] = 0; //Khởi tạo đường đi từ đỉnh i tới đỉnh j = 0
			else
				g.Cost[i][j] = INF; //Khởi tạo đường đi từ đỉnh i tới đỉnh j = INF
		}
	return g;
}

//Thiết lập lại trạng thái của các đỉnh
void ResetFlags(Graph& g)
{
	for (int i = 0; i < g.NumVertices; i++)
		g.Vertices[i].Visited = NO; //Thiết lập trường Visited của đỉnh i = NO
}

//Kiểm tra 2 đỉnh start và end có được nối với nhau bởi 1 cạnh hay không
int IsConnected(Graph g, int start, int end)
{
	if (g.Cost[start][end] == 0 || g.Cost[start][end] == INF) //Chi phí đi từ start đến end = 0 hoặc INF
		return 0;
	else
		return 1;
}

//Thêm 1 đỉnh có nhãn Lab vào đồ thị g
void AddVertex(Graph& g, LabelType Lab)
{
	Vertex v = CreateVertex(Lab); //Gọi hàm tạo một đỉnh v với nhãn Lab
	g.Vertices[g.NumVertices] = v; //Đưa đỉnh v vào đồ thị g
	g.NumVertices++; //Tăng số đỉnh của g lên 1;
}

//Thêm 1 cạnh có trọng số weight bắt đầu từ đỉnh start và kết thúc tại đỉnh end
//directed = false: Thêm cạnh vô hướng
void AddEdge(Graph& g, int start, int end, CostType weight, bool directed)
{
	if (IsConnected(g, start, end) == 0) //2 đỉnh start, end không kề nhau
	{
		g.NumEdges++;
		g.Cost[start][end] = weight;
	}
	if (directed == false) //Đồ thị vô hướng
		g.Cost[end][start] = weight;
}

//Thêm 1 cạnh có trọng số weight bắt đầu từ đỉnh start và kết thúc tại đỉnh end
void AddEdge(Graph& g, int start, int end, CostType weight)
{
	AddEdge(g, start, end, weight, g.Directed);
}

//Thêm 1 cạnh bắt đầu từ đỉnh start và kết thúc tại đỉnh end. Dùng cho đồ thị không có trọng số
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
	for (int i = 0; i < g.NumVertices; i++)
		os << g.Vertices[i].Label << '\n';

	//Lưu ma trận kề
	for (int i = 0; i < g.NumVertices; i++)
	{
		for (int j = 0; j < g.NumVertices; j++)
		{
			os << g.Cost[i][j] << '\t';
		}
		os << '\n';
	}
	//Đóng tập tin
	os.close();
}

//Đọc dữ liệu từ file để tạo đồ thị
void OpenGraph(Graph& g, char* filename)
{
	//Khai báo biến và mở file để đọc
	ifstream is(filename);
	//Kiểm tra đã mở được file hay chưa?
	if (is.is_open()) //Nếu mở file thành công
	{
		int n = 0, m = 0;
		bool d = false;
		LabelType Lab;

		is >> n; //Đọc số đỉnh của đồ thị đưa vào biến n
		is >> m; //Đọc số cạnh của đồ thị đưa vào biến m
		is >> d; //Đọc loại đồ thị đưa vào biến d

		int t;
		g = InitGraph(d); //Khởi tạo đồ thị g
		g.NumEdges = m; //Gán số cạnh m của đồ thị vào g.NumEdges

		//Khởi tạo nhãn của các đỉnh
		for (int i = 0; i < n; i++)
		{
			is >> Lab;
			AddVertex(g, Lab);
		}
		//Đọc ma trận kề từ file
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				is >> t;
				if (t != 0)
					g.Cost[i][j] = t; //Lưu vào đồ thị g.Cost[i][j]
			}
		is.close(); //Đóng file
	}
}

//Tìm đỉnh đầu tiên kề với curr mà chưa xét
int FindFirstAdjacentVertex(Graph g, int curr)
{
	//Duyệt qua mọi đỉnh
	for (int i = 0; i < g.NumVertices; i++)
	{
		//Kiểm tra đỉnh đã xét chưa và kề với curr không?
		if (g.Vertices[i].Visited == NO && IsConnected(g, curr, i) == 1) //Đỉnh chưa xét và có cạnh nối từ curr đến i
			return i; //Thỏa điều kiện -> tìm thấy
		return NULLDATA;//Không tìm thấy
	}
}