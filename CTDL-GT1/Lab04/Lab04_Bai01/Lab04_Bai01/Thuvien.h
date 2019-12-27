#define MAX 100

typedef int Data;

struct tagnode
{
	Data data;
	tagnode* pnext;
};

typedef tagnode NODE;

struct stack
{
	NODE* phead;
	NODE* ptail;
};

void createemptystack(stack& s)
{
	s.phead = s.ptail = NULL;
}

bool isemptystack(stack s)
{
	return s.phead == NULL;
}

void inserthead(stack& s, NODE* p)
{
	if (isemptystack(s))
	{
		s.phead = p;
		s.ptail = p;
	}
	else
	{
		p->pnext = s.phead;
		s.phead = p;
	}
}

NODE* Createnode(Data data)
{
	NODE* p = new NODE;
	if (p)
	{
		p->data = data;
		p->pnext = NULL;
	}
	return p;
}

int getdatafromfile(char* filename, stack& s)
{
	ifstream input(filename);
	if (!input)
		return 0; //Loi mo file	

	NODE* new_ele;
	Data data;

	while (!input.eof())
	{
		input >> data;
		new_ele = Createnode(data);
		if (new_ele)
		{
			inserthead(s, new_ele);
		}
		else
			return -1; //Loi cap phat vung nho
	}
	input.close();
	return 1;
}

void displaystack(stack s)
{
	cout << endl;
	NODE* p = s.phead;

	while (p != NULL)
	{
		cout << p->data << '\t';
		p = p->pnext;
	}
	cout << endl;
}

int count_x(stack s, Data x)
{
	int res = 0;

	NODE* p = s.phead;

	while (p != NULL)
	{
		if (p->data == x) res++;
		p = p->pnext;
	}
	return res;
}

void removehead(stack& s)
{
	if (isemptystack(s))
		return;

	NODE* p = s.phead;
	s.phead = p->pnext;
	delete p;

	if (s.phead == NULL)
		s.ptail = NULL;
}

void inserttail(stack& s, NODE* p)
{
	if (isemptystack(s))
	{
		s.phead = p;
		s.ptail = p;
	}
	else
	{
		s.ptail->pnext = p;
		s.ptail = p;
	}
}

stack remove_all_x(stack s, Data data)
{
	stack res;
	createemptystack(res);

	NODE* p;
	p = s.phead;

	while (p)
	{
		if (p->data != data)
		{
			NODE* new_ele = Createnode(p->data);
			inserttail(res, new_ele);
		}
		p = p->pnext;
	}
	return res;
}

