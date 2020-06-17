Vertex CreateVertex(LabelType lab)
{
	Vertex v;
	v.Label = lab;
	v.Visited = NO;
	return v;
}

int FindIndexofVertex(Graph g, LabelType lab)
{
	for (size_t i = 0; i < MAX; i++)
		if (g.Vertices[i].Label == lab)
			return i;
	return -1;
}

void DisplayInfoVertex(Graph g, int pos)
{
	cout << "\nCac dinh ke voi " << g.Vertices[pos].Label << " la: ";
	for (size_t i = 0; i < g.NumVertices; i++)
		if (g.Cost[pos][i] != ZERO)
			cout << '\t' << g.Vertices[i].Label;
}

void DisplayVertex(Graph g, int pos)
{
	cout << g.Vertices[pos].Label << '\t';
}

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

Graph InitGraph(bool Directed)
{
	Graph g;
	g.NumEdges = 0;
	g.NumVertices = 0;
	g.Directed = Directed;
	for (size_t i = 0; i < g.NumVertices; i++)
		for (int j = 0; j < g.NumVertices; j++)
		{
			if (i == j)
				g.Cost[i][j] = 0;
			else
				g.Cost[i][j] = INF;
		}
	return g;
}

void ResetFlags(Graph& g)
{
	for (int i = 0; i < g.NumVertices; i++)
		g.Vertices[i].Visited = NO;
}

int IsConnected(Graph g, int start, int end)
{
	if (g.Cost[start][end] == 0 || g.Cost[start][end] == INF)
		return 0;
	else
		return 1;
}

void AddVertex(Graph& g, LabelType lab)
{
	Vertex v = CreateVertex(lab);
	g.Vertices[g.NumVertices] = v;
	g.NumVertices++;
	g.Cost[g.NumVertices - 1][g.NumVertices - 1] = 0;
	for (size_t i = 0; i < g.NumVertices - 1; i++)
	{
		g.Cost[i][g.NumVertices - 1] = INF;
		g.Cost[g.NumVertices - 1][i] = INF;
	}
}

void AddEdge(Graph& g, int start, int end, CostType weight, bool directed)
{
	if (IsConnected(g, start, end) == 0)
	{
		g.NumEdges++;
		g.Cost[start][end] = weight;
		if (directed == false)
			g.Cost[end][start] = weight;
	}
}

void AddEdge(Graph& g, int start, int end, CostType weight)
{
	AddEdge(g, start, end, weight, g.Directed);
}

void AddEdge(Graph& g, int start, int end)
{
	AddEdge(g, start, end, 1);
}

void SaveGraph(Graph g, char* filename)
{
	ofstream os(filename);
	os << g.NumVertices << '\n';
	os << g.NumEdges << '\n';
	os << g.Directed << '\n';
	for (size_t i = 0; i < g.NumVertices; i++)
		os << g.Vertices[i].Label << '\n';
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
	ifstream is(filename);
	if (is.is_open())
	{
		int n = 0, m = 0;
		bool d = false;
		LabelType lab;
		is >> n;
		is >> m;
		is >> d;

		int t;
		g = InitGraph(d);
		g.NumEdges = m;
		for (size_t i = 0; i < n; i++)
		{
			is >> lab;
			AddVertex(g, lab);
		}
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
	return 0;
}

int FindFirstAdjacentVertex(Graph g, int curr)
{
	for (int i = 0; i < g.NumVertices; i++)
	{
		if (g.Vertices[i].Visited == NO && IsConnected(g, curr, i) == 1)
			return i;
	}
	NULLDATA;
}

//Duyet do thi theo chieu sau
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

//Duyet do thi theo chieu rong
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

void TestGraphConnectivity(Graph g)
{
	int count = 0, flag = 0;
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		if (g.Vertices[i].Visited == NO)
		{
			count++;
			cout << "\nThanh phan lien thong thu " << count << ": ";
			if (DFS_Loop(g, i) == g.NumVertices)
				flag = 1;
		}
	}
	cout << "\nCon lai " << count << " lan duyet.";
	if (flag)
		cout << "\nLien thong!";
	else cout << "\nKhong lien thong!";
}