//Nguyên mẫu hàm

#define MAX 100

//Tổng quát
void Nhapday(int a[MAX], int& n);
void Xuatday(int a[MAX], int n);

//Chức năng 1
void MinMax(int a[MAX], int l, int r, int& min, int& max);

//Chức năng 2
void Nhapchiso_TraiPhai(int& l, int& r, int n);
void Hoanvi(int& a, int& b);
void Hoanvichuoi(int a[MAX], int i, int j, int m);
void Chuyenchuoi(int a[MAX], int n, int m);

//Chức năng 3
void Lietke_NP(int i, int a[MAX], int n);

//Chức năng 4
void Nhapday(int a[MAX], int& n)
{
	do
	{
		cout << "\nNhap so phan tu cua mang: ";
		cin >> n;
	} while (n <= 0 || n >= MAX);

	srand((unsigned)time(NULL));
	for (int i = 0; i < n; i++)
		a[i] = -9 + rand() % 18;
}

void Xuatday(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << '\t';
	cout << endl;
}

void MinMax(int a[MAX], int l, int r, int& min, int& max)
{
	if (l == r)
	{
		min = a[l];
		max = a[l];
	}
	else
	{
		int min1, max1, min2, max2;
		MinMax(a, l, (l + r) / 2, min1, max1);
		MinMax(a, (l + r) / 2 + 1, r, min2, max2);
		min = min1 < min2 ? min1 : min2;
		max = max1 > max2 ? max1 : max2;
	}
}

void Nhapchiso_TraiPhai(int& l, int& r, int n)
{
	do
	{
		cout << "\nNhap chi so trai: (0 <= l <= r < " << n << ") ";
		cin >> l;
	} while (l < 0 || l >= n);

	do
	{
		cout << "\nNhap chi so phai: (0 <= " << l << " < r < " << n << ") ";
		cin >> r;
	} while (r < 0 || r < l || r >= n);
}

void Hoanvi(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void Hoanvichuoi(int a[MAX], int i, int j, int m)
{
	for (int k = 0; k < m; k++)
		Hoanvi(a[i + k], a[j + k]);
}

void Chuyenchuoi(int a[MAX], int n, int m)
{
	int i = m;
	int j = n - m;

	while (i != j)
	{
		if (i > j)
		{
			Hoanvichuoi(a, m - i, m, j);
			i = i - j;
		}
		else
		{
			j = j - i;
			Hoanvichuoi(a, m - i, m + j, i);
		}
	}
	Hoanvichuoi(a, m - i, m, i);
}

void Lietke_NP(int i, int a[MAX], int n)
{
	for (int j = 0; j <= 1; j++)
	{
		a[i] = j;
		if (i < n - 1)
			Lietke_NP(i + 1, a, n);
		else
			Xuatday(a, n);
	}
}