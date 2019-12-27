struct Nhanvien
{
	char MaNV[10];
	char Hoten[30];
	unsigned int Namsinh;
	char Diachi[30];
	unsigned int Luong;
};

typedef Nhanvien Data;

struct BSnode
{
	Data data;
	BSnode* left;
	BSnode* right;
};

typedef BSnode* BStree;

void createBST(BStree& root);
BSnode* createnode(Data data);
int insertnode(BStree& root, Data data);
int getdatafromfile(char* filename, BStree& root);
void preorder(BStree root);
void inorder(BStree root);
void posorder(BStree root);
void xuatNV(Nhanvien nv);

void posorder(BStree root)
{
	if (root)
	{
		posorder(root->left);
		posorder(root->right);
		xuatNV(root->data);
	}
}

void inorder(BStree root)
{
	if (root)
	{
		inorder(root->left);
		xuatNV(root->data);
		inorder(root->right);
	}
}

void preorder(BStree root)
{
	if (root)
	{
		xuatNV(root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

//OUTPUT
//0: doc du lieu khong thanh cong
//1: doc du lieu thanh cong
int getdatafromfile(char* filename, BStree& root)
{
	ifstream input(filename);
	if (!input)
		return 0;

	Data data;
	int kq;

	createBST(root);
	input >> data.MaNV;
	input >> data.Hoten;
	input >> data.Namsinh;
	input >> data.Diachi;
	input >> data.Luong;
	kq = insertnode(root, data);

	if (kq != 1)
		return 0;

	while (!input.eof())
	{
		input >> data.MaNV;
		input >> data.Hoten;
		input >> data.Namsinh;
		input >> data.Diachi;
		input >> data.Luong;
		kq = insertnode(root, data);

		if (kq != 1)
			return 0;
	}
	input.close();
	return 1;
}

//OUTPUT:
//0: nut da ton tai
//-1: Cap phat dong khong thanh cong
//1: Tao nut thanh cong
int insertnode(BStree& root, Data data)
{
	if (root)
	{
		if (strcmp(root->data.MaNV, data.MaNV) == 0)
			return 0;
		if (strcmp(root->data.MaNV, data.MaNV) > 0)
			return insertnode(root->left, data);
		else
			return insertnode(root->right, data);
	}
	root = createnode(data);
	if (!root)
		return -1;
	return 1;
}

BSnode* createnode(Data data)
{
	BSnode* p = new BSnode;
	if (p)
	{
		p->data = data;
		p->left = nullptr;
		p->right = nullptr;
	}
	return p;
}

void createBST(BStree& root)
{
	root = nullptr;
}

void xuatNV(Nhanvien nv)
{
	cout << nv.MaNV << " " << nv.Hoten << " " << nv.Namsinh << " " << nv.Diachi << " " << nv.Luong << endl;
}