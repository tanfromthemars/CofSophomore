#pragma once
#define MAX 100

//input: filename, a, n
// output: mang a da duoc nhap du lieu
int Docmang(int a[], int& n, char* filename);
void Xuatmang(int a[], int n);
void Chentructiep(int a[], int n);
void Chentructiep(int arr[], int n);
void Doichotructiep(int a[], int n);
void BubbleSort(int a[], int n);

int Docmang(int a[], int& n, char* filename)
{
	ifstream input(filename);
	
	if (!input)
		return 0;
	
	input >> n;
	for (int i = 0; i < n; i++)
		input >> a[i];

	input.close();
	return 1;
}

void Xuatmang(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}

int Min_AB(int batdau, int ketthuc, int a[MAX], int n)
{
	int kq = a[batdau];
	int vt = batdau;

	for (int i = batdau + 1; i <= ketthuc; i++)
		if (kq > a[i])
		{
			kq = a[i];
			vt = i;
		}

	return vt;
}

void Hoanvi(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

void Chentructiep(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void Doichotructiep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				Hoanvi(a[i], a[j]);
}

void BubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j] < a[j - 1])
				Hoanvi(a[j], a[j - 1]);
}