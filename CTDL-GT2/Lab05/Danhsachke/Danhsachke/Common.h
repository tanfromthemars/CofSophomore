#define UPPER 100	//Số phần tử tối đa
#define ZERO 0		//Giá trị 0
#define MAX 20		//Số đỉnh tối đa
#define INF 1000	//Vô cùng
#define YES 1		//Đã xét
#define NO 0		//Chưa xét
#define NULLDATA -1	//Giá trị rỗng

typedef char LabelType;
typedef int CostType;

//Định nghĩa một cạnh
struct Edge
{
	int marked;		//Trạng thái
	char target;	//Đỉnh cuối
	CostType weight;	//Trọng số
	Edge* Next;		//Cạnh kế tiếp
};

//Định nghĩa một đỉnh
struct Vertex
{
	LabelType Label;	//Nhãn của dỉnh
	int visited;	//Trạng thái
	Edge* Edgelist;		//Danh sách cạnh kề
};

struct Path
{
	CostType Length;	//Độ dài đường đi
	int Parent;		//Đỉnh trước
};

typedef Path* PathPtr;
typedef Edge* EdgePtr;	//Danh sách cạnh
typedef Vertex* VertexPtr;		//Danh sách đỉnh kề với 1 đỉnh nào đó

//Định nghĩa đồ thị
struct GraphADT
{
	bool directed;
	int numVertices;
	int numEdges;
	VertexPtr Vertices[MAX];		//Danh sách các đỉnh chứa các đỉnh kề
};