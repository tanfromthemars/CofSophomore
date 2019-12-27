#pragma once
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
	char lot[11];
	char ten[11];
};

struct Nhanvien
{
	char maNV[8];
	Name name;
	Date date;
	char diachi[16];
	unsigned int luong;
};

int Docdanhsachnhanvien(char* filename, Nhanvien a[], int& n);
void Xuat_1_NV(Nhanvien nv);
void Xuat_DS_NV(Nhanvien a[], int n);

int Docdanhsachnhanvien(char* filename, Nhanvien a[], int& n)
{
	ifstream input(filename);

	if (!input)
	{
		cout << "\nLoi doc file!" << endl;
		return 0;
	}

	int i = 0;
	while (!input.eof())
	{
		input >> a[i].maNV;
		input >> a[i].name.ho;
		input >> a[i].name.lot;
		input >> a[i].name.ten;
		input >> a[i].date.ngay;
		input >> a[i].date.thang;
		input >> a[i].date.nam;
		input >> a[i].diachi;
		input >> a[i].luong;
		i++;
	}

	n = i;
	input.close();
}

void Xuatduongke(char kitu)
{
	const int chieudai = 89;
	cout << '|';
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
		<< setw(11) << "lot"
		<< setw(11) << "ten"
		<< '|' << setw(13) << "Ngay/Thang/Nam sinh"
		<< '|' << setw(16) << "Dia chi"
		<< '|' << setw(13) << "Luong";
	cout << '|' << endl;
	Xuatduongke('=');
}

void Xuat_1_NV(Nhanvien nv)
{
	cout << setiosflags(ios::left)
		<< '|' << setw(10) << nv.maNV
		<< '|' << setw(11) << nv.name.ho
		<< setw(11) << nv.name.lot
		<< setw(11) << nv.name.ten
		<< '|' << setw(2) << nv.date.ngay
		<< '/' << setw(2) << nv.date.thang
		<< '/' << setw(7) << nv.date.nam
		<< '|' << setw(16) << nv.diachi
		<< '|' << setw(13) << nv.luong;
	cout << '|' << endl;
}

void Xuat_DS_NV(Nhanvien a[], int n)
{
	Xuattieude();

	for (int i = 0; i < n; i++)
	{
		Xuat_1_NV(a[i]);
		if ((i + 1) % 3 == 0)
			Xuatduongke('-');
	}
	Xuatduongke('=');
}

//Tim vi tri cua maNV nho nhat trong doan [begin..end]
int VT_Min(Nhanvien a[], int begin, int end)
{
	int vt = begin;
	char min[8];
	strcpy_s(min, a[begin].maNV);

	for (int i = begin + 1; i <= end; i++)
		if (strcmp(min, a[i].maNV) > 0)
		{
			strcpy_s(min, a[i].maNV);
			vt = i;
		}
	return vt;
}

//Hoan vi 2 nhan vien
void Hoanvi(Nhanvien& a, Nhanvien& b)
{
	Nhanvien t = a;
	a = b;
	b = t;
}

//Sap xep tang theo ma nhan vien, chon truc tiep
void Tang_MaNV(Nhanvien a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int vt_min = VT_Min(a, i, n - 1);
		Hoanvi(a[i], a[vt_min]);
	}
}

//Sap xep tang theo dia chi, chen truc tiep
void Tang_Diachi(Nhanvien arr[], int n)
{
	int i, j;
	char key[16];

	for (i = 1; i < n; i++)
	{
		// key = arr[i];
		strcpy_s(key, arr[i].diachi);
		j = i - 1;

		while (j >= 0 && (strcmp(arr[j].diachi, key) > 0)) //arr[j] > key
		{
			// arr[j + 1] = arr[j];
			strcpy_s(arr[j + 1].diachi, arr[j].diachi);
			j = j - 1;
		}
		// arr[j + 1] = key;
		strcpy_s(arr[j + 1].diachi, key);
	}
}

//Sap xep tang dan theo tien luong, doi cho truc tiep
void Tang_Luong(Nhanvien a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i].luong > a[j].luong)
				Hoanvi(a[i], a[j]);
}

void QuickSort(Nhanvien a[MAX], int l, int r)
{
	int i, j;
	Nhanvien x;
	
	x = a[(l + r) / 2];
	i = l; j = r;

	do
	{
		while (a[i].date.nam < x.date.nam)
			i++;
		while (a[j].date.nam > x.date.nam)
			j--;
		if (i <= j)
		{
			Hoanvi(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);
	if (l < j)
		QuickSort(a, l, j);
	if (i < r)
		QuickSort(a, i, r);
}