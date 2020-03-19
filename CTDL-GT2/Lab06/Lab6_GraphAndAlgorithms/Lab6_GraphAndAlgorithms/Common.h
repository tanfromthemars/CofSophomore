//Định nghĩa hằng số
#define UPPER 100 //Số phần tử tối đa
#define ZERO 0 //Giá trị 0
#define MAX 20 //Số đỉnh tối đa
#define INF 1000 //Vô cùng
#define YES 1 //Đã xét
#define NO 0 //Chưa xét
#define NULLDATA -1 //Giả giá trị rỗng

//Định nghĩa các kiểu dữ liệu
typedef char LabelType;
typedef int CostType;
typedef CostType MaTrix[MAX][MAX]; //Ma trận

//Định nghĩa cấu trúc của một đỉnh
struct  Vertex
{
	LabelType Label; //Nhãn của đỉnh
	int Visited; //Trạng thái
};

//Định nghĩa cấu trúc một cạnh
struct Edge
{
	int Source; //Đỉnh đầu
	int Target; //Đỉnh cuối
	CostType Weight; //Trọng số
	int Marked; //Trạng thái
};

//Định nghĩa cấu trúc một đoạn đường đi
struct Path
{
	CostType Length; //Độ dài đường đi
	int Parent; //Đỉnh trước
};

//Định nghĩa kiểu dữ liệu đồ thị
struct Graph
{
	bool Directed; //Đồ thị có hướng?
	int NumVertices; //Số đỉnh
	int NumEdges; //Số cạnh
	MaTrix Cost; //Ma trận kề
	Vertex Vertices[MAX]; //Danh sách đỉnh
};

//Kiểu dữ liệu phần tử của Queue, Stack
struct Entry
{
	//Dữ liệu chứa trong một nút của Queue hoặc Stack
	int Data;
	Entry* Next; //Con trỏ Next
};

//Định nghĩa kiểu con trỏ tới một Entry
typedef Entry* EntryPtr;

//Kiểu dữ liệu ngăn xếp (Stack)
typedef EntryPtr Stack;

//Tạo một phần tử của Stack chứa dữ liệu là data
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