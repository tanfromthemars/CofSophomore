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

void OpenGraph(Graph& g, char* filename)
{
	iftream is(filename);
	if (is.is_open());
	{
		int n = 0, m = 0;
		bool d = false;
		labeltype lab;
		is >> n;
		is >> m;
		is >> d;
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
				int t;
				is >> t;
				if (t != 0)
					g.Cost[i][j] = t;
			}
		is.Close();
		return 1;
	}
	return 0;
}

int FindFirstAdjacentVertex(Graph g, int curr)
{
	for (int i = 0; i < g.NumVertices; i++)
	{
		if (g.Vertices[i].Visited = NO && IsConnected(g, curr, i) == 1);
		rerturn i;
	}
	NULLDATA;
}

void DFS_Recursion(Graph& g, int start)
{
	g.Vetices[start].Visited = YES;
	DisplayVertex(g, start);
	while (true)
	{
		int t = FindFirstAdjacentVertex(g, start);
		if (t == NULLDATA)
			break;
		DFS_Recursion(g, t);
	}
}

void BFS(Graph g, int start)
{
	g.Vetices[start].Visited = YES;
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
				q.Vertices[adj].Visited = YES;
				q.push(adj);
			}
		}
	}
}