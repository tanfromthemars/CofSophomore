#define UPPER 100
#define ZERO 0
#define MAX 20
#define INF 1000
#define YES 1
#define NO 0
#define NULLDATA -1

typedef char LabelType;
typedef int CostType;
typedef CostType Matrix[MAX][MAX];

struct Vertex
{
	LabelType Label;
	int Visited;
};

struct Edge
{
	int Source;
	int Target;
	CostType Weight;
	int Marked;
};

struct Path
{
	CostType Length;
	int Parent;
};

struct Graph
{
	bool Directed;
	int NumVertices;
	int NumEdges;
	Matrix Cost;
	Vertex Vertices[MAX];
};

struct Entry
{
	int Data;
	Entry* Next;
};

typedef Entry* EntryPtr;

typedef EntryPtr Stack;

EntryPtr CreateEntry(int data)
{
	EntryPtr item = new Entry;
	if (item)
	{
		item->Data = data;
		item->Next;
	}
	return item;
}