int Demsonut(BStree root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Demsonut(root->left) + Demsonut(root->right);
}

BStree Search(char MaNV[], BStree root)
{
	if (root != NULL)
	{
		if (strcmp(root->data.MaNV, MaNV) == 0)
			return root;
		else
			if (strcmp(root->data.MaNV, MaNV) < 0)
				return Search(MaNV, root->right);
			else
				return Search(MaNV, root->left);
	}
	return NULL;
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

int deletenode(char MaNV[], BStree& root)
{
	if (root != NULL)
	{
		if (strcmp(MaNV, root->data.MaNV) < 0)
			deletenode(MaNV, root->left);
		else
			if (strcmp(MaNV, root->data.MaNV) > 0)
				deletenode(MaNV, root->right);
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