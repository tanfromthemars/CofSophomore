#define MAX 100

struct tagnode
{
	int info;
	tagnode* pNext;
};

typedef tagnode node;

struct LIST
{
	node* phead;
	node* ptail;
};

//Nguyen mau ham
//1. Doc va xuat file
node* getnode(int data);
void CreateEmptyList(LIST& l);
bool IsEmptyList(LIST l);
void insertTail(LIST& ls, int x);
int GetDatafromfile(char* filename, LIST& ls);
void displayList(LIST ls);

//2. Tinh toan
int calcsum(LIST ls);

//3. Tim kiem
node* findMAX(LIST ls);
node* search_first(LIST ls, int x);
int search_first_index(LIST ls, int x);
int search_final_index(LIST ls, int x);

//Dinh nghia ham
node* getnode(int data)
{
	node* p;
	p = new node;

	if (p != NULL)
	{
		p->info = data;
		p->pNext = NULL;
	}
	//p == NULL neu tao node khong thanh cong	
	return p;
}

//Tao danh sach rong 
void CreateEmptyList(LIST& l)
{
	l.phead = l.ptail = NULL;
}

//Kiem tra danh sach co rong hay khong
bool IsEmptyList(LIST l)
{
	return l.phead == NULL;
}

int GetDatafromfile(char* filename, LIST& ls)
{
	ifstream input(filename);
	if (!input)
	{
		return 0; //Loi mo file
	}

	//Tao danh sach trong	
	CreateEmptyList(ls);
	int x;

	input >> x;
	insertTail(ls, x);

	while (!input.eof())
	{
		input >> x;
		insertTail(ls, x);
	}
	input.close();
	return 1;
}

void displayList(LIST ls)
{
	node* p;
	if (IsEmptyList(ls))
	{
		cout << "\nDanh sach rong!";
		return;
	}
	cout << "\nDanh sach lien ket hien tai: \n";
	p = ls.phead;
	while (p != NULL)
	{
		cout << p->info << '\t';
		p = p->pNext;
	}
}

//Chen phan tu vao cuoi list
void insertTail(LIST& ls, int x)
{
	node* new_node = getnode(x);
	if (!new_node)
	{
		cout << "\nLoi cap phat bo nho! Khong the thuc hien thao tac nay!";
		return;
	}

	//Danh sach trong, phan tu dau tien cung la phan tu cuoi cung
	if (IsEmptyList(ls))
	{
		ls.phead = new_node;
		ls.ptail = new_node;
	}
	else
	{
		//Tao con tro tu node cuoi cung den node moi tao
		//Cap phat con tro cuoi cung luu vi tri cua node moi tao
		ls.ptail->pNext = new_node;
		ls.ptail = new_node;
	}
}

int calcsum(LIST ls)
{
	int sum = 0;
	node* p;

	if (IsEmptyList(ls))
	{
		return sum;
	}

	p = ls.phead;
	while (p != NULL)
	{
		sum += p->info;
		p = p->pNext;
	}
	return sum;
}

node* findMAX(LIST ls)
{
	node* res; //Node chua gia tri lon nhat trong day
	node* cur; //Node hien tai

	cur = ls.phead;
	res = ls.phead;

	while (cur != NULL)
	{
		if (cur->info > res->info)
			res = cur;
		cur = cur->pNext;
	}
	return res; //res == NULL neu danh sach rong
}

node* search_first(LIST ls, int x)
{
	node* res = ls.phead;
	while (res != NULL && res->info != x)
		res = res->pNext;
	return res;
}

int search_first_index(LIST ls, int x)
{
	node* p = ls.phead;
	int i = 0;

	while (p != NULL && p->info != x)
	{
		p = p->pNext;
		i++;
	}
	if (!p)
		i = -1; //Khong tim thay x
	return i;
}

int search_final_index(LIST ls, int x)
{
	node* p = ls.phead;
	int i = 0, kq = -1;

	while (p != NULL)
	{
		if (p->info == x)
			kq = i;
		p = p->pNext;
		i++;
	}
	return kq;
}

void insert_begin(LIST& ls, node* node)
{
	if (IsEmptyList(ls))
	{
		ls.phead = node;
		ls.ptail = node;
	}
	else
	{
		node->pNext = ls.phead;
		ls.phead = node;
	}
}

void insert_end(LIST& ls, node* node)
{
	if (IsEmptyList(ls))
	{
		ls.phead = node;
		ls.ptail = node;
	}
	else
	{
		ls.ptail->pNext = node;
		ls.phead = node;
	}
}

void chenXsauY(LIST& ls, node* y, node* x)
{
	if (y == ls.ptail)
	{
		y->pNext = x;
		ls.ptail = x;
	}
	else
	{
		x->pNext = y->pNext;
		y->pNext = x;
	}
}