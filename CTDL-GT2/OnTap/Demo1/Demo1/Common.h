#define UPPER 100 //So phan tu toi da
#define ZERO 0 //Gia tri 0
#define MAX 20 //So dinh toi da
#define INF 1000 //Vo cung
#define YES 1 //Da xet
#define NO 0 //Chua xet
#define NULLDATA -1 //Gia tri rong

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