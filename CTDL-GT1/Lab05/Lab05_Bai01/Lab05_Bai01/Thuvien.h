int Demsonut(BStree root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Demsonut(root->left) + Demsonut(root->right);
}

int Demnutnhohon(BStree root, Data x)
{
	int sonut;
	if (root == NULL)
		sonut = 0;
	else
		if (root->data < x)
		{
			cout << root->data << '\t';
			sonut = 1 + Demnutnhohon(root->left, x) + Demnutnhohon(root->right, x);
		}
		else
			sonut = Demnutnhohon(root->left, x) + Demnutnhohon(root->right, x);
	return sonut;
}

BStree search(Data x, BStree root)
{
	if (root != NULL)
	{
		if (root->data == x)
			return root;
		else if (root->data < x)
			return search(x, root->right);
		else
			return search(x, root->left);
	}
	return NULL;
}

int isleaf_x(BStree root, Data x)
{
	int kq = 1;
	BStree T = search(x, root);
	if (T == NULL)
		kq = 0;
	else
		kq = (T->left == NULL) && (T->right == NULL);
	return kq;
}

int demnutla(BStree root)
{
	int sonutla;
	if (root == NULL)
		sonutla = 0;
	else
		if (root->right == NULL && root->left == NULL)
		{
			cout << root->data << '\t';
			sonutla = 1;
		}
		else
			sonutla = demnutla(root->left) + demnutla(root->right);
	return sonutla;
}

Data tinhMAX(Data a, Data b)
{
	if (a >= b)
		return a;
	else
		return b;
}

int Tinhchieucao(BStree root)
{
	int h;
	if (root == NULL)
		h = -1;
	else
		if (root->left == NULL && root->right == NULL)
			h = 0;
		else
			h = 1 + tinhMAX(Tinhchieucao(root->left), Tinhchieucao(root->right));
	return h;
}

int Timmuc_x(BStree root, Data x)
{
	int muc = 0;
	BStree T = root;
	while (T != NULL)
	{
		if (T->data == x)
			return muc;
		else
		{
			muc++;
			if (T->data > x)
				T = T->left;
			else
				T = T->right;
		}
	}
	return 0;
}

//OUTPUT:
//1: x > y
//-1: x < y
//0: x = y
int sosanhmuc(BStree root, Data x, Data y)
{
	int kq1, kq2;
	kq1 = Timmuc_x(root, x);
	kq2 = Timmuc_x(root, y);
	if (kq1 > kq2)
		return 1;
	else
		if (kq1 < kq2)
			return -1;
		else
			return 0;
}

Data deletemin(BStree& root)
{
	Data k;
	if (root->left == NULL)
	{
		k = root->data;
		root = root->right;
		return k;
	}
	else
		return deletemin(root->left);
}

int deletenode(Data x, BStree& root)
{
	if (root != NULL)
	{
		if (x < root->data)
			deletenode(x, root->left);
		else
			if (x > root->data)
				deletenode(x, root->right);
			else
				if ((root->left == NULL) && (root->right == NULL))
					root = NULL;
				else
					if (root->left == NULL)
						root = root->right;
					else
						if (root->right == NULL)
							root = root->left;
						else
							root->data = deletemin(root->right);
		return 1;
	}
	return 0;
}