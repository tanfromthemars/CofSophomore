#define MAX 100

struct Date
{
	unsigned int ngay;
	unsigned int thang;
	unsigned int nam;
};

struct Name
{
	char ho[11];
	char tenlot[11];
	char ten[11];
};

struct Nhanvien
{
	char MaNV[8];
	Name name;
	Date date;
	char diachi[16];
	unsigned int luong;
};

typedef Nhanvien Data;

struct tagnode
{
	Data info;
	tagnode* pnext;
};

typedef tagnode node;

struct LIST
{
	node* phead;
	node* ptail;
};

void CreateEmptylist(LIST& ls)
{
	ls.phead = ls.ptail = NULL;
}

node* createnode(Data data)
{
	node* p = new node;

	if (p)
	{
		p->info = data;
		p->pnext = NULL;
	}
	return p;
}

bool IsEmptylist(LIST ls)
{
	return ls.phead == NULL;
}

void insert_tail(LIST& ls, node* node)
{
	if (IsEmptylist(ls))
	{
		ls.phead = node;
		ls.ptail = node;
	}
	else
	{
		ls.ptail->pnext = node;
		ls.ptail = node;
	}
}

int getdatafromfile(char* filename, LIST& ls)
{
	ifstream input(filename);
	node* p;
	Data nhanvien;

	if (!input)
		return 0; //Loi doc file

	while (!input.eof())
	{
		input >> nhanvien.MaNV;
		input >> nhanvien.name.ho;
		input >> nhanvien.name.tenlot;
		input >> nhanvien.name.ten;
		input >> nhanvien.date.ngay;
		input >> nhanvien.date.thang;
		input >> nhanvien.date.nam;
		input >> nhanvien.diachi;
		input >> nhanvien.luong;

		p = createnode(nhanvien);
		if (!p)
		{
			cout << "\nLoi cap phat bo nho!\n";
			exit(-1);
		}
		insert_tail(ls, p);
	}
	input.close();
	return 1;
}

void Xuatduongke(char kitu)
{
	const int chieudai = 89;
	cout << "|";
	for (int i = 0; i < chieudai; i++)
		cout << kitu;
	cout << '|' << endl;
}

void Xuattieude()
{
	Xuatduongke('=');
	cout << setiosflags(ios::left)
		<< '|' << setw(10) << "Ma NV"
		<< '|' << setw(11) << "Ho"
		<< setw(11) << "Ten lot"
		<< setw(11) << "Ten"
		<< '|' << setw(13) << "NTN sinh"
		<< '|' << setw(16) << "Dia chi"
		<< '|' << setw(13) << "Luong";
	cout << '|' << endl;
	Xuatduongke('=');
}

void Xuat_1_NV(Data& nv)
{
	cout << setiosflags(ios::left)
		<< '|' << setw(10) << nv.MaNV
		<< '|' << setw(11) << nv.name.ho
		<< setw(11) << nv.name.tenlot
		<< setw(11) << nv.name.ten
		<< '|' << setw(2) << nv.date.ngay
		<< '/' << setw(2) << nv.date.thang
		<< '/' << setw(7) << nv.date.nam
		<< '|' << setw(16) << nv.diachi
		<< '|' << setw(13) << nv.luong;
	cout << '|' << endl;
}

void Xuat_DS_NV(LIST ls)
{
	Xuattieude();

	if (IsEmptylist(ls))
	{
		cout << "\nDanh sach hien tai rong\n";
		return;
	}

	node* node = ls.phead;
	int i = 1;

	while (node)
	{
		Xuat_1_NV(node->info);
		i++; //Cach 3 dong xuat 1 duong ke don
		if (i % 3 == 0)
			Xuatduongke('-');
		node = node->pnext;
	}
	Xuatduongke('=');
}

node* get_final_employee_with_name(LIST ls, char name[])
{
	if (IsEmptylist(ls))
	{
		cout << "\nDanh sach hien tai rong!\n";
		return NULL;
	}

	node* kq, * p;
	kq = NULL;
	p = ls.phead;

	while (p)
	{
		if (strcmp(p->info.name.ten, name) == 0)
			kq = p;
		p = p->pnext;
	}
	return kq;
}

node* get_first_employee_with_name(LIST ls, char name[])
{
	if (IsEmptylist(ls))
	{
		cout << "\nDanh sach hien tai rong!\n";
		return NULL;
	}

	node* p;
	p = ls.phead;

	while (p)
	{
		if (strcmp(p->info.name.ten, name) == 0)
			return p;
		p = p->pnext;
	}
	return p;
}

node* MAX_salary(LIST ls)
{
	if (IsEmptylist(ls))
	{
		cout << "\nDanh sasch hien tai rong!\n";
		return NULL;
	}

	node* kq, * p;
	
	kq = ls.phead;
	p = ls.phead->pnext;

	while (p)
	{
		if (kq->info.luong < p->info.luong)
			kq = p;
		p = p->pnext;
	}
	return kq;
}

LIST filter_employee(LIST ls, unsigned int luong)
{
	LIST kq;
	CreateEmptylist(kq);

	if (!IsEmptylist(ls))
	{
		node* p, * node;
		p = ls.phead;

		while (p)
		{
			if (p->info.luong >= luong)
			{
				node = createnode(p->info);
				insert_tail(kq, node);
			}
			p = p->pnext;
		}
	}
	return kq;
}

int get_list_length(LIST ls)
{
	if (IsEmptylist(ls))
		return 0;
	int i = 0;
	node* p;
	p = ls.phead;

	while (p)
	{
		i++;
		p = p->pnext;
	}
	return i;
}

int count_salary_greater_than(LIST ls, unsigned int luong)
{
	if (IsEmptylist(ls))
	{
		cout << "\nDanh sach hien tai rong!\n";
		return -1;
	}

	int count;
	node* p;
	count = 0;
	p = ls.phead;

	while (p)
	{
		if (p->info.luong >= luong)
			count++;
		p = p->pnext;
	}
	return count;
}

node* search_node_before(LIST ls, node* cur)
{
	if (IsEmptylist(ls))
		return NULL;
	node* prev, * p;

	prev = NULL;
	p = ls.phead;

	while (p)
	{
		if (p == cur)
			break;
		prev = p;
		p = p->pnext;
	}
	return prev;
}

//node* remove_node(LIST& ls, node* p)
//{
//	if (IsEmptylist(ls))
//		return NULL;
//	node* t;
//	
//	//p la node dau
//	if (p == ls.phead)
//	{
//		ls.phead = ls.phead->pnext;
//		delete p;
//		return ls.phead;
//	}
//
//	t = search_node_before(ls, p);
//	t->pnext = p->pnext;
//	delete p;
//
//	//p la node cuoi
//	if (t->pnext == NULL)
//		ls.ptail = t;
//
//	return t;
//}

bool isaddressexist(LIST ls, char diachi[])
{
	node* p;
	p = ls.phead;

	while (p)
	{
		if (strcmp(p->info.diachi, diachi) == 0)
			return true;
		p = p->pnext;
	}
	return false;
}

LIST xoa_tatcac_node_co_diachi(LIST ls, char diachi[])
{
	LIST kq;
	CreateEmptylist(kq);

	if (!IsEmptylist(ls))
	{
		node* p, * node;
		p = ls.phead;

		while (p)
		{
			if (strcmp(p->info.diachi, diachi) != 0)
			{
				node = createnode(p->info);
				insert_tail(kq, node);
			}
			p = p->pnext;
		}
	}
	return kq;
}

LIST remove_node(LIST ls, node* Node)
{
	LIST list;
	CreateEmptylist(list);

	if (!IsEmptylist(ls))
	{
		node* p, * t;
		p = ls.phead;

		while (p)
		{
			if (p != Node)
			{
				t = createnode(p->info);
				insert_tail(list, t);
			}
			p = p->pnext;
		}
	}
	return list;
}

void swap(node* a, node* b)
{
	node* c;
	c = a;
	a = b;
	b = c;
}

LIST get_list_copy(LIST src)
{
	LIST new_list;
	CreateEmptylist(new_list);

	if (!IsEmptylist(src))
	{
		node* p = src.phead;
		while (p)
		{
			node* t = createnode(p->info);
			insert_tail(new_list, t);
		}
	}
	return new_list;
}