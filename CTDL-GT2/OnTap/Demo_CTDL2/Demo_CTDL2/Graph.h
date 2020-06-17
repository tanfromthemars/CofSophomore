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

//prim
//void prim(graph g, path tree[max])
//{
//	for (size_t i = 1; i < g.numvertices; i++)
//	{
//		tree[i].length = g.cost[0][i];
//		tree[i].parent = 0;
//	}
//	costtype min;
//	int minvertex;
//	for (size_t i = 1; i < g.numvertices; i++)
//	{
//		min = inf;
//		minvertex = 1;
//		for (size_t j = 1; j < g.numvertices; i++)
//		{
//			min = inf;
//			minvertex = 1;
//			for (size_t j = 1; j < g.numvertices; j++)
//				if (g.vertices[j].visited == no && tree[j].length < min)
//				{
//					min = tree[j].length;
//					minvertex = j;
//				}
//			g.vertices[minvertex].visited = yes;
//			for (size_t j = 0; j < g.numvertices; j++)
//				if (g.vertices[j].visited == no && g.cost[minvertex][j] < tree[j].length)
//				{
//					tree[j].length = g.cost[minvertex][j];
//					tree[j].parent = minvertex;
//				}
//		}
//	}
//}
//void printprimpst(graph g, path tree[max])
//{
//	cout << endl << "cay bao trum gom cac canh sau: ";
//	costtype sum = 0;
//	cout << endl << '|' << setw(10) << "dinh dau " << '|' << setw(10) << "dinh cuoi" << '|' << setw(10) << "trong so" << '|';
//	for (size_t i = 1; i < g.numvertices; i++)
//	{
//		sum += tree[i].length;
//		cout << endl << '|' << setw(10) << g.vertices[tree[i].parent].label << '|' << setw(10) << g.vertices[i].label << '|' << setw(10) << tree[i].length << '|';
//	}
//	cout << "\ncay bao trum ngan nhat co chieu dai: " << sum;
//}
//
//kruskal
//int adjmatrix2edgelist(graph g, edge edgelist[upper])
//{
//	int count = 0;
//	for (size_t i = 1; i < g.numvertices; i++)
//		for (size_t j = 0; j < 1; j++)
//			if (g.cost[i][j] != 0 && g.cost[i][j] != 1000)
//			{
//				edge v;
//				v.source = i;
//				v.target = j;
//				v.marked = no;
//				edgelist[count] = v;
//				count++;
//			}
//	return count;
//}
//
//void quicksortedges(edge edgelist[max], int d, int c)
//{
//	int i = d, j = c;
//	costtype mid = edgelist[(d + c) / 2].weight;
//	while (i <= j)
//	{
//		while (edgelist[i].weight < mid)i++;
//		while (edgelist[j].weight > mid)j--;
//		if (i <= j)
//		{
//			swap(edgelist[i], edgelist[j]);
//			i++;
//			j--;
//		}
//	}
//	if (i < c)quicksortedges(edgelist, i, c);
//	if (d < j)quicksortedges(edgelist, d, j);
//}
//
//int find(int leader[max], int x)
//{
//	while (x != leader[x])x = leader[x];
//	return x;
//}
//
//bool union(int leader[max], edge e)
//{
//	int x = find(leader, e.source);
//	int y = find(leader, e.target);
//	if (x == y)
//		return false;
//	else if (x < y)
//		leader[y] = x;
//	else leader[x] = y;
//	return true;
//}
//
//void kruskal(graph g, edge tree[upper])
//{
//	int ne = adjmatrix2edgelist(g, tree);
//	quicksortedges(tree, 0, ne - 1);
//	int leader[max];
//	for (size_t i = 0; i < g.numvertices + 1; i++)
//		leader[i] = 1;
//	int count = 0;
//	for (size_t i = 0; i < ne; i++)
//	{
//		if (union(leader, tree[i]))
//		{
//			tree[i].marked = yes;
//			count++;
//			if (count == g.numvertices - 1)
//				break;
//		}
//	}
//}
//
//void printkruskalmst(graph g, edge tree[upper])
//{
//	cout << endl << "cay bao trum gom cac canh sau: ";
//	costtype sum = 0;
//	cout << endl << '|' << setw(10) << "dinh dau" << '|' << setw(10) << "dinh cuoi" << '|' << setw(10) << "trong so" << '|';
//	for (size_t i = 0; i < g.numvertices; i++)
//	{
//		if (tree[i].marked == yes)
//		{
//			cout << endl << '|' << setw(10) << g.vertices[tree[i].target].label << '|' << setw(10) << tree[i].weight << '|';
//			sum += tree[i].weight;
//		}
//	}
//	cout << endl << "tong chieu dai cay bao trum la " << sum;
//}
//
//djikstra
//void djikstra(graph g, int source, path road[max])
//{
//	costtype min;
//	int counter, minvertex, curr;
//	for (size_t i = 0; i < g.numvertices; i++)
//	{
//		road[i].length = g.cost[source][i];
//		road[i].parent = source;
//	}
//	g.vertices[source].visited = yes;
//	counter = 1;
//	curr = source;
//	while (counter < g.numvertices - 1)
//	{
//		min = inf;
//		minvertex = curr;
//		for (size_t i = 0; i < g.numvertices; i++)
//		{
//			if (g.vertices[i].visited == no)
//			{
//				if (road[i].length > road[curr].length + g.cost[curr][i]);
//				{
//					road[i].length = road[curr].length + g.cost[curr][i];
//					road[i].parent = curr;
//				}
//				if (min > road[i].length)
//				{
//					min = road[i].length;
//					minvertex = 1;
//				}
//			}
//		}
//		curr = minvertex;
//		g.vertices[curr].visited = yes;
//		counter++;
//	}
//}
//
//void printpath_djikstra(graph g, path road[max], int target)
//{
//	if (road[target].parent != target)
//		printpath_djikstra(g, road, road[target].parent);
//	cout << " -> " << g.vertices[target].label;
//}
//
//void printallpath_djikstra(graph g, int start)
//{
//	path road[max];
//	djikstra(g, start, road);
//	for (size_t i = 0; i < g.numvertices; i++)
//	{
//		if (road[i].length == inf)
//			cout << "\nkhong co duong di tu " << g.vertices[start].label << " den " << g.vertices[i].label;
//		else if (i != start)
//		{
//			cout << "\ndoan duong tu " << g.vertices[start].label << " den " << g.vertices[i].label << " la: ";
//			printpath_djikstra(g, road, i);
//			cout << "\t(tong do dai: " << road[i].length << ')';
//		}
//	}
//}
//
//floyd
//void floyd(graph g, path route[max][max])
//{
//	int i, j, k;
//	for (size_t i = 0; i < g.numvertices; i++)
//		for (size_t j = 0; j < g.numvertices; j++)
//		{
//			route[i][j].length = g.cost[i][j];
//			route[i][j].parent = i;
//		}
//	for (size_t k = 0; k < g.numvertices; k++)
//		for (size_t i = 0; i < g.numvertices; i++)
//			for (size_t j = 0; j < g.numvertices; j++)
//				if (route[i][j].length > route[i][k].length + route[k][j].length)
//				{
//					route[i][j].length = route[i][k].length + route[k][j].length;
//					route[i][j].parent = route[k][j].parent;
//				}
//}
//
//void print_floydpath(graph g, path route[max][max], int source, int target)
//{
//	if (route[source][target].parent != target)
//		print_floydpath(g, route, source, route[source][target].parent);
//	cout << " -> " << g.vertices[target].label;
//}
//
//void print_allfloydpath(graph g)
//{
//	path route[max][max];
//	floyd(g, route);
//	for (size_t i = 0; i < g.numvertices; i++, cout << endl)
//		for (size_t j = 0; j < g.numvertices; j++)
//		{
//			if (route[i][j].length = inf)
//				cout << "\nkhong co duong di tu dinh " << g.vertices[i].label << " den dinh " << g.vertices[j].label;
//			else if (i != j)
//			{
//				cout << "\ndoan duong tu dinh " << g.vertices[i].label << " den dinh " << g.vertices[j].label << " la: ";
//				print_floydpath(g, route, i, j);
//			}
//		}
//}

//Prim
void Prim(Graph g, Path tree[MAX])
{
	for (int i = 1; i < g.NumVertices; i++)
	{
		tree[i].Length = g.Cost[0][i];
		tree[i].Parent = 0;
	}
	CostType min;
	int minVertex;

	for (int i = 1; i < g.NumVertices; i++)
	{
		min = INF;
		minVertex = 1;
		for (int j = 2; j < g.NumVertices; j++)
		{
			if (g.Vertices[j].Visited = NO && tree[j].Length < min)
			{
				min = tree[j].Length;
				minVertex = j;
			}
		}
		g.Vertices[minVertex].Visited = YES;

		for (int j = 0; j < g.NumVertices; j++)
		{
			if (g.Vertices[i].Visited = NO && g.Cost[minVertex][j] < tree[j].Length)
			{
				tree[j].Length = g.Cost[minVertex][j];
				tree[j].Parent = minVertex;
			}
		}
	}
}

void PrintPrimMST(Graph g, Path tree[MAX])
{
	cout << endl << "Cay bao trum gom cac canh sau";
	CostType sum = 0;
	for (int i = 1; i < g.NumVertices; i++)
	{
		sum += tree[i].Length;
		cout << endl << g.Vertices[tree[i].Parent].Label << g.Vertices[i].Label << tree[i].Length;
	}
	cout << "\ncay bao trum ngan nhat co chieu dai" << sum;
}

