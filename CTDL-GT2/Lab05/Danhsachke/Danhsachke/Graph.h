//Tạo một đỉnh có nhãn l thành 1 phần tử trong danh sách đỉnh
VertexPtr CreateVertex(LabelType l)
{
	VertexPtr v = new Vertex;		//Vertex* v = new Vertex
	v->Label = l;	//Gán nhãn lab cho đỉnh v
	v->visited = NO;	//Gán đỉnh v chưa xét
	v->Edgelist = NULL;		//Gán danh sach đỉnh liên kết từ v = NULL
	return v;	//Trả về đỉnh v
}

//Tạo một cạnh chỉ đến đỉnh có nhãn label, trọng số w
EdgePtr CreateEdge(char l, CostType w)
{
	EdgePtr e = new Edge;	//Khai báo và khởi tạo biến động e có kiểu EdgePtr
	e->target = l;		//Lưu nhãn đỉnh đích lab vào e
	e->weight = w;		//Lưu trọng số w vào e
	e->marked = NO;		//Đánh dấu e chưa xét
	e->Next = NULL;		//Gán liên kết kế tiếp từ e = NULL;
	return e;	//Trả về cạnh e
}

//Tìm vị trí đỉnh v trong đồ thị g
int FindIndexVertex(GraphADT g, char v)
{
	for (size_t i = 0; i < g.numVertices; i++) //Số đỉnh của đồ thị g
	{
		if (g.Vertices[i]->Label == v)//Nếu đỉnh thứ i có nhãn = v
			return i;
	}
	return -1;
}

//Xuất danh sách các cạnh của 1 đỉnh được trỏ bởi ds
void XuatDSCanh(EdgePtr ds)
{
	while (ds != NULL)//Danh sách khác rỗng
	{
		cout << "\n\tDinh cuoi: " << ds->target << " Trong so: " << ds->weight;		//Xuất ra màn hỉnh target và weight
		ds = ds->Next;		//Đến liên kết kế tiếp
	}
}

//Hiển thị thông tin đỉnh v trong đồ thị
void Xuat1Dinh(char v, GraphADT g)
{
	int s = FindIndexVertex(g, v); //Khai báo biến s và dùng hàm FindIndexVertex để đến đỉnh v
	if (s == -1) //Không tìm thấy v
		cout << "Khong co dinh " << v << " trong do thi";
	else
	{
		cout << "\nDinh dau " << v; //Xuất nhãn đỉnh của s
		XuatDSCanh(g.Vertices[s]->Edgelist); //Xuất danh sách các cạnh của s
	}
}

//Khởi tạo một đồ thị
//Directed = true: Đồ thị có hướng
GraphADT InitGraph(bool directed)
{
	GraphADT g; //Khai báo và khởi tạo đồ thị g
	g.numEdges = 0; //Khởi tạo số cạnh của g = 0
	g.numVertices = 0; //Khởi tạo số đỉnh của g = 0
	g.directed = directed; //Gán đồ thị có hướng hay không có hướng cho đồ thị g
	//Khởi tạo danh sách đỉnh
	for (size_t i = 0; i < g.numVertices; i++)
	{
		g.Vertices[i]->Edgelist = NULL;
		g.Vertices[i]->Label = NULL;
		g.Vertices[i]->visited = NO;
	}
	return g;
}

//Thiết lập trạng thái của các đỉnh
void ResetFlags(GraphADT& g)
{
	for (int i = 0; i < g.numVertices; i++)
		g.Vertices[i]->visited = NO; //Thiết lập trường visited của đỉnh i = NO
}

//Tìm cạnh nối 2 đỉnh start và end
EdgePtr FindEdge(GraphADT g, char start, char end)
{
	//Bắt đầu tìm từ cạnh kề đầu tiên với start
	int v = FindIndexVertex(g, start); //Tìm đỉnh đầu start bằng hàm FindIndexVertex
	EdgePtr ds = g.Vertices[v]->Edgelist;	//Khai báo -> Gán ->Trỏ tới danh sách đỉnh kề với đỉnh start
	//Tìm cạnh với đỉnh cuối là end
	while (ds != NULL) //Duyệt qua các cạnh kề
	{
		if (ds->target == end) //Nếu ds tồn tại	đỉnh end nghĩa là có tồn tại cạnh nối
			break;
		ds = ds->Next;	//Đi đến cạnh kế tiếp
	}
	return ds; //Trả về NULL
}

//Kiểm tra hai đỉnh u, v có kề nhau (có cạnh nối giữa chúng) hay không?
int IsConnected(GraphADT g, int start, int end)
{
	EdgePtr e = new Edge;	//Khai báo biến e có kiểu EdgePtr
	e = FindEdge(g, start, end);	//Gán biến e = FindEdge(g, start, end)
	return (e != NULL);	//true false
}

//Thêm đỉnh v vào đồ thị g
void AddVertex(GraphADT& g, VertexPtr v)
{
	g.Vertices[g.numVertices] = v; //Thêm vào cuối
	g.numVertices++; //Tăng số đỉnh
}

//Thêm một cạnh e vào cạnh v (nối vào danh sách v)
void AddEdge(EdgePtr& v, EdgePtr e)
{
	if (v == NULL)
		v = e;
	else AddEdge(v->Next, e); //Trỏ tới cuối danh sách
}

//Thêm một cạnh chỉ đến đỉnh có nhãn lab với trọng số ư vào danh sách của đỉnh v
void AddEdge(GraphADT& g, char v, char lab, CostType w)
{
	if (v == NULL)
		v = lab;
	else
	{
		if (g.directed == false) //Nếu không có hướng
		{
			EdgePtr h, k;
			h = CreateEdge(lab, w);
			k = CreateEdge(v, w);
			AddEdge(g.Vertices[FindIndexVertex(g, v)]->Edgelist, h);
			AddEdge(g.Vertices[FindIndexVertex(g, lab)]->Edgelist, k);
			g.numEdges = g.numEdges + 2; //Do thêm hai cạnh
		}
		else
		{
			EdgePtr a;
			a = CreateEdge(lab, w);
			AddEdge(g.Vertices[FindIndexVertex(g, v)]->Edgelist, a);
			g.numEdges = g.numEdges + 1;
		}
	}
}

//Lưu đồ thị xuống file
void WriteGraph(GraphADT g, const char* filename)
{
	ofstream out(filename); //Khai báo biến và mở tập tin để ghi
	out << g.numVertices << '\n'; //Lưu số đỉnh
	out << g.numEdges << '\n'; //Lưu số cạnh
	out << g.directed << '\n'; //Lưu loại đồ thị
	//Lưu tên các đỉnh
	for (size_t i = 0; i < g.numVertices; i++)
		out << g.Vertices[i]->Label << '\n';
	//Lưu ma trận kề
	for (size_t i = 0; i < g.numVertices; i++)
	{
		for (size_t j = 0; j < g.numVertices; j++)
		{
			if (i == j)
				out << "0" << "\t";
			else
				if (IsConnected(g, g.Vertices[i]->Label, g.Vertices[j]->Label))
				{
					EdgePtr temp = FindEdge(g, g.Vertices[i]->Label, g.Vertices[j]->Label);
					out << g.Vertices[j]->Edgelist->weight << '\t';
				}
				else
				{
					out << "1000" << '\t';
				}
		}
		if (i != g.numVertices - 1)
			out << "\n";

	//ofstream out(filename);
	//out << g.numVertices << '\n';
	//out << g.numEdges << '\n';
	//out << g.directed << '\n';
	//for (size_t i = 0; i < g.numVertices; i++) //Ghi tên các đỉnh
	//	out << g.Vertices[i]->Label << '\t';
	//out << endl;
	//for (size_t i = 0; i < g.numVertices; i++) //Ghi ma trận kề
	//{
	//	for (size_t j = 0; j < g.numVertices; j++)
	//	{
	//		EdgePtr e = FindEdge(g, g.Vertices[i]->Label, g.Vertices[j]->Label);
	//		if (e == NULL)
	//			if (i == j)
	//				out << 0 << '\t';
	//			else
	//				out << 1000 << '\t';
	//		else out << e->weight << '\t';
	//	}
	//	out << endl;
	//}
	}
	out.close(); //Đóng tập tin
}

//Đọc dữ liệu từ file để tạo đồ thị
int OpenGraph(GraphADT& g, char* filename)
{
	ifstream in(filename);
	if (in.is_open())
	{
		int n = 0, m = 0, w = 0;
		bool d = false;
		char lab;
		in >> n; //Đọc số đỉnh
		in >> m; //Đọc số cạnh
		in >> d; //Đọc loại đồ thị
		g = InitGraph(d);
		for (int i = 0; i < n; i++)
		{
			in >> lab;
			VertexPtr v = CreateVertex(lab);
			AddVertex(g, v);
		}
		lab = ' ';
		int indexvertex;
		for (int i = 0; i < m; i++)
		{
			char dinh, dich;
			int trongso;
			in >> dinh;
			in >> dich;
			in >> trongso;
			if (lab != dinh)
			{
				lab = dinh;
				indexvertex = FindIndexVertex(g, dinh);
			}
			if (trongso == NULL)
			{
				trongso = 1;
			}
			EdgePtr e = CreateEdge(dich, trongso);
			AddEdge(g.Vertices[indexvertex]->Edgelist, e);
			g.numEdges++;
		}
		in.close();
		return 1;
	}
	else
	{
		cout << "\nLoi doc file nhap lai ten file\n";
		system("pause");
		return 0;
	}

	//ifstream in(filename);
	//if (in.is_open())
	//{
	//	int n = 0, m = 0, w = 0, t;
	//	bool d = false;
	//	LabelType l;
	//	in >> n; //Số đỉnh 
	//	in >> m; //Số cạnh
	//	in >> d; //Loại đồ thị
	//	g = InitGraph(d);
	//	for (size_t i = 0; i < n; i++) //Khởi tạo nhãn của các đỉnh
	//	{
	//		in >> l;
	//		VertexPtr v = CreateVertex(l);
	//		AddVertex(g, v);
	//	}
	//	for (size_t i = 0; i < n; i++)
	//	{
	//		for (size_t j = 0; j < n; j++)
	//		{
	//			in >> t;
	//			if (t != 1000 && t != 0)
	//			{
	//				EdgePtr e = CreateEdge(g.Vertices[j]->Label, t);
	//				AddEdge(g.Vertices[i]->Edgelist, e);
	//				g.numEdges++;
	//			}
	//		}
	//	}
	//	in.close();
	//	return 1;
	//}
	//else
	//	return 0;
}

//Tìm đỉnh đầu tiên kề với cur mà chưa xét
char FindFirstAdjacentVertex(GraphADT g, char cur)
{
	//Duyệt qua mọi đỉnh
	for (int i = 0; i < g.numVertices; i++)
	{
		if (g.Vertices[i]->Label == cur)
		{
			EdgePtr p = g.Vertices[i]->Edgelist;
			while (p != NULL)
			{
				for (int j = 0; j < g.numVertices; j++)
					if (g.Vertices[j]->Label == p->target && g.Vertices[j]->visited == NO)
						return p->target; //Thỏa điều kiện -> tìm thấy
				p = p->Next;
			}
		}
	}
	return NULLDATA; //Không tìm thấy

	//int v = FindIndexVertex(g, cur);
	//if (v != -1)
	//{
	//	EdgePtr e = g.Vertices[v]->Edgelist;
	//	while (e != NULL)
	//	{
	//		for (size_t j = 0; j < g.numVertices; j++)
	//			if (g.Vertices[j]->Label == e->target && g.Vertices[j]->visited == NO)
	//				return e->target;
	//		e = e->Next;
	//	}
	//}
	//return NULLDATA;
}

//Duyệt đồ thị theo chiều sâu (Depth First Search)
//Mô tả: Đi tiếp đến khi nào không đi đến được nữa thì lùi lại và tìm đường đi mới, và một đỉnh không đi qua 2 lần
void DFS_Loop(GraphADT& g, char start)
{
	int index = FindIndexVertex(g, start);
	g.Vertices[index]->visited = YES;
	cout << start << '\t';
	stack<char>st;
	st.push(start);
	char cur, adj;
	while (!st.empty())
	{
		cur = st.top();
		adj = FindFirstAdjacentVertex(g, cur);
		if (adj == NULLDATA)
			st.pop();
		else
		{
			int index = FindIndexVertex(g, adj);
			g.Vertices[index]->visited = YES;
			cout << adj << '\t';
			st.push(adj);
		}
	}
	
	//ResetFlags(g);
	//int vt = FindIndexVertex(g, start);
	//g.Vertices[vt]->visited = YES;
	//cout << start << '\t';
	//stack<char>s;
	//s.push(start);
	//char cur, adj;
	//while (!s.empty())
	//{
	//	cur = s.top();
	//	adj = FindFirstAdjacentVertex(g, cur);
	//	if (adj == NULLDATA)
	//		s.pop();
	//	else
	//	{
	//		vt = FindIndexVertex(g, adj);
	//		g.Vertices[vt]->visited = YES;
	//		cout << adj << '\t';
	//		s.push(adj);
	//	}
	//}
}

//Duyệt đồ thị theo chiều rộng
//Dạng lặp, sử dụng queue

void BFS(GraphADT g, char start)
{
	int index = FindIndexVertex(g, start);
	g.Vertices[index]->visited = YES;
	queue<char>q;
	q.push(start);
	char cur, adj;
	cur = q.front();
	cout << cur << '\t';
	while (!q.empty())
	{
		adj = FindFirstAdjacentVertex(g, cur);
		if (adj == NULLDATA)
		{
			q.pop();
			if (q.size() != 0)
				cur = q.front();
			else
				break;
		}
		else
		{
			index = FindIndexVertex(g, adj);
			g.Vertices[index]->visited = YES;
			cout << adj << '\t';
			q.push(adj);
		}
	}
	ResetFlags(g);

	//ResetFlags(g);
	//int vt = FindIndexVertex(g, start);
	//g.Vertices[vt]->visited = YES;
	//cout << start << '\t';
	//queue<int>q;
	//q.push(start);
	//char cur, adj;
	//cur = q.front();
	//while (!q.empty())
	//{
	//	adj = FindFirstAdjacentVertex(g, cur);
	//	if (adj == NULLDATA)
	//	{
	//		q.pop();
	//		if (q.size() != 0)
	//			cur = q.front();
	//		else break;
	//	}
	//	else
	//	{
	//		vt = FindIndexVertex(g, adj);
	//		g.Vertices[vt]->visited = YES;
	//		cout << adj << '\t';
	//		q.push(adj);
	//	}
	//}
}

//Hiển thị ma trận kề
void DisplayMatrix(GraphADT g)
{
	cout << endl;
	for (size_t i = 0; i < g.numVertices; i++) //Ghi tên các dỉnh
		cout << g.Vertices[i]->Label << '\t';
	cout << endl;
	for (size_t i = 0; i < g.numVertices; i++)
	{
		for (size_t j = 0; j < g.numVertices; j++)
		{
			EdgePtr e = FindEdge(g, g.Vertices[i]->Label, g.Vertices[j]->Label);
			if (e == NULL)
				if (i == j)
					cout << "0" << '\t';
				else
					cout << "INF" << '\t';
			else cout << e->weight << '\t';
		}
		cout << endl;
	}
}