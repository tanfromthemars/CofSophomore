int FindIndexofVertex(Graph g, LabelType l)
{
	for (size_t i = 0; i < MAX; i++)
		if (g.Vertices[i].Label == l)
			return i;
	return -1;
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
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			if (i == j)
				g.Cost[i][j] = 0;
			else
				g.Cost[i][j] = INF;
		}
	return g;
}

Vertex CreateVertex(LabelType l)
{
	Vertex v;
	v.Label = l;
	v.Visited = NO;
	return v;
}

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

int OpenGraph(Graph& g, char* filename)
{
	ifstream is(filename);
	if (is.is_open())
	{
		int n = 0, m = 0;
		bool d = false;
		LabelType l;
		is >> n;
		is >> m;
		is >> d;
		int t;
		g = InitGraph(d);
		g.NumEdges = m;
		for (size_t i = 0; i < n; i++)
		{
			is >> l;
			AddVertex(g, l);
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

void ResetFalgs(Graph& g)
{
	for (int i = 0; i < g.NumVertices; i++)
		g.Vertices[i].Visited = NO;
}

//Prim
void Prim(Graph g, Path tree[MAX])
{
	for (size_t i = 1; i < g.NumVertices; i++)
	{
		tree[i].Length = g.Cost[0][i];
		tree[i].Parent = 0;
	}
	CostType min;
	int minVertex;
	for (size_t i = 1; i < g.NumVertices; i++)
	{
		min = INF;
		minVertex = 1;
		for (size_t j = 1; j < g.NumVertices; i++)
		{
			min = INF;
			minVertex = 1;
			for (size_t j = 1; j < g.NumVertices; j++)
				if (g.Vertices[j].Visited == NO && tree[j].Length < min)
				{
					min = tree[j].Length;
					minVertex = j;
				}
			g.Vertices[minVertex].Visited = YES;
			for (size_t j = 0; j < g.NumVertices; j++)
				if (g.Vertices[j].Visited == NO && g.Cost[minVertex][j] < tree[j].Length)
				{
					tree[j].Length = g.Cost[minVertex][j];
					tree[j].Parent = minVertex;
				}
		}
	}
}
void PrintPrimPST(Graph g, Path tree[MAX])
{
	cout << endl << "Cay bao trum gom cac canh sau: ";
	CostType sum = 0;
	cout << endl << '|' << setw(10) << "Dinh dau " << '|' << setw(10) << "dinh cuoi" << '|' << setw(10) << "Trong so" << '|';
	for (size_t i = 1; i < g.NumVertices; i++)
	{
		sum += tree[i].Length;
		cout << endl << '|' << setw(10) << g.Vertices[tree[i].Parent].Label << '|' << setw(10) << g.Vertices[i].Label << '|' << setw(10) << tree[i].Length << '|';
	}
	cout << "\nCay bao trum ngan nhat co chieu dai: " << sum;
}

//Kruskal
int AdjMatrix2EdgeList(Graph g, Edge edgeList[UPPER])
{
	int count = 0;
	for (size_t i = 1; i < g.NumVertices; i++)
		for (size_t j = 0; j < 1; j++)
			if (g.Cost[i][j] != 0 && g.Cost[i][j] != 1000)
			{
				Edge v;
				v.Source = i;
				v.Target = j;
				v.Marked = NO;
				edgeList[count] = v;
				count++;
			}
	return count;
}

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

int Find(int leader[MAX], int x)
{
	while (x != leader[x])x = leader[x];
	return x;
}

bool Union(int leader[MAX], Edge e)
{
	int x = Find(leader, e.Source);
	int y = Find(leader, e.Target);
	if (x == y)
		return false;
	else if (x < y)
		leader[y] = x;
	else leader[x] = y;
	return true;
}

void Kruskal(Graph g, Edge tree[UPPER])
{
	int ne = AdjMatrix2EdgeList(g, tree);
	QuickSortEdges(tree, 0, ne - 1);
	int leader[MAX];
	for (size_t i = 0; i < g.NumVertices + 1; i++)
		leader[i] = 1;
	int count = 0;
	for (size_t i = 0; i < ne; i++)
	{
		if (Union(leader, tree[i]))
		{
			tree[i].Marked = YES;
			count++;
			if (count == g.NumVertices - 1)
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
			cout << endl << '|' << setw(10) << g.Vertices[tree[i].Target].Label << '|' << setw(10) << tree[i].Weight << '|';
			sum += tree[i].Weight;
		}
	}
	cout << endl << "Tong chieu dai cay bao trum la " << sum;
}

//Djikstra
void Djikstra(Graph g, int source, Path road[MAX])
{
	CostType min;
	int counter, minVertex, curr;
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		road[i].Length = g.Cost[source][i];
		road[i].Parent = source;
	}
	g.Vertices[source].Visited = YES;
	counter = 1;
	curr = source;
	while (counter < g.NumVertices - 1)
	{
		min = INF;
		minVertex = curr;
		for (size_t i = 0; i < g.NumVertices; i++)
		{
			if (g.Vertices[i].Visited == NO)
			{
				if (road[i].Length > road[curr].Length + g.Cost[curr][i]);
				{
					road[i].Length = road[curr].Length + g.Cost[curr][i];
					road[i].Parent = curr;
				}
				if (min > road[i].Length)
				{
					min = road[i].Length;
					minVertex = 1;
				}
			}
		}
		curr = minVertex;
		g.Vertices[curr].Visited = YES;
		counter++;
	}
}

void PrintPath_Djikstra(Graph g, Path road[MAX], int target)
{
	if (road[target].Parent != target)
		PrintPath_Djikstra(g, road, road[target].Parent);
	cout << " -> " << g.Vertices[target].Label;
}

void PrintAllPath_Djikstra(Graph g, int start)
{
	Path road[MAX];
	Djikstra(g, start, road);
	for (size_t i = 0; i < g.NumVertices; i++)
	{
		if (road[i].Length == INF)
			cout << "\nKhong co duong di tu " << g.Vertices[start].Label << " den " << g.Vertices[i].Label;
		else if (i != start)
		{
			cout << "\nDoan duong tu " << g.Vertices[start].Label << " den " << g.Vertices[i].Label << " la: ";
			PrintPath_Djikstra(g, road, i);
			cout << "\t(Tong do dai: " << road[i].Length << ')';
		}
	}
}

//Floyd
void Floyd(Graph g, Path route[MAX][MAX])
{
	int i, j, k;
	for (size_t i = 0; i < g.NumVertices; i++)
		for (size_t j = 0; j < g.NumVertices; j++)
		{
			route[i][j].Length = g.Cost[i][j];
			route[i][j].Parent = i;
		}
	for (size_t k = 0; k < g.NumVertices; k++)
		for (size_t i = 0; i < g.NumVertices; i++)
			for (size_t j = 0; j < g.NumVertices; j++)
				if (route[i][j].Length > route[i][k].Length + route[k][j].Length)
				{
					route[i][j].Length = route[i][k].Length + route[k][j].Length;
					route[i][j].Parent = route[k][j].Parent;
				}
}

void Print_FloydPath(Graph g, Path route[MAX][MAX], int source, int target)
{
	if (route[source][target].Parent != target)
		Print_FloydPath(g, route, source, route[source][target].Parent);
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
				cout << "\nKhong co duong di tu dinh " << g.Vertices[i].Label << " den dinh " << g.Vertices[j].Label;
			else if (i != j)
			{
				cout << "\nDoan duong tu dinh " << g.Vertices[i].Label << " den dinh " << g.Vertices[j].Label << " la: ";
				Print_FloydPath(g, route, i, j);
			}
		}
}