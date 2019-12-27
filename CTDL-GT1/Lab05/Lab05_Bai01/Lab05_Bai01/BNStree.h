typedef int Data;

struct BSnode
{
	Data data;
	BSnode* left;
	BSnode* right;
};

typedef BSnode* BStree;

void createBST(BStree& root);
int insertnode(BStree& root, Data data);
BSnode* createnode(Data data);

void posorder(BStree root)
{
	if (root)
	{
		posorder(root->left);
		posorder(root->right);
		cout << root->data << '\t';
	}
}

void inorder(BStree root)
{
	if (root)
	{
		inorder(root->left);
		cout << root->data << '\t';
		inorder(root->right);
	}
}

void preorder(BStree root)
{
	if (root)
	{
		cout << root->data << '\t';
		preorder(root->left);
		preorder(root->right);
	}
}

//OUTPUT
//	0: Doc du lieu khong thanh cong
//	1: Doc du lieu thanh cong
int getdatafromfile(char* filename, BStree& root)
{
	ifstream input(filename);
	if (!input)
		return 0;

	Data data;
	int kq;

	createBST(root);
	input >> data;
	kq = insertnode(root, data);

	if (kq != 1)
		return 0;

	while (!input.eof())
	{
		input >> data;
		kq = insertnode(root, data);
		if (kq != 1)
			return 0;
	}
	input.close();
	return 1;
}

//OUTPUT:
//	0: Nut da ton tai
	//-1:Cap phat dong khong thanh cong
	//1: tao nut thanh cong
int insertnode(BStree& root, Data data)
{
	if (root)
	{
		if (root->data == data)
			return 0;

		if (root->data > data)
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