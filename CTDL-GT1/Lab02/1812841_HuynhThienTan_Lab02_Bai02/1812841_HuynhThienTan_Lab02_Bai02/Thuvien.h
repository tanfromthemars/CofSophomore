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
void Timkiem_NS(Nhanvien a[], int n, unsigned int namsinh);
void Timkiem_NS_Luong(Nhanvien a[], int n, unsigned int namsinh, unsigned int luong);
void Timkiem_Hoten(Nhanvien a[], int n, Name name, unsigned int namsinh);
void Timkiem_Ten_Diachi(Nhanvien a[], int n, Name name, char diachi[]);

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

void Timkiem_NS(Nhanvien a[], int n, unsigned int namsinh)
{
	int m = 0;
	Nhanvien b[MAX];

	for (int i = 0; i < n; i++)
		if (a[i].date.nam == namsinh)
		{
			b[m] = a[i];
			m++;
		}

	if (m == 0)
		cout << "\nKhong tim thay nhan vien co nam sinh: " << namsinh << endl;
	else
	{
		cout << "\nDa tim thay " << m << " nhan vien co nam sinh: " << namsinh << endl;

		Xuattieude();
		for (int i = 0; i < m; i++)
		{
			Xuat_1_NV(b[i]);
			if ((i + 1) % 3 == 0)
				Xuatduongke('-');
		}
		Xuatduongke('=');
	}
}

void Timkiem_NS_Luong(Nhanvien a[], int n, unsigned int namsinh, unsigned int luong)
{
	int m = 0;
	Nhanvien b[MAX];

	for (int i = 0; i < n; i++)
		if (a[i].date.nam <= namsinh && a[i].luong >= luong)
		{
			b[m] = a[i];
			m++;
		}

	if (m == 0)
		cout << "\nKhong tim thay nhan vien co nam sinh <= " << namsinh << " va co muc luong >= " << luong << endl;
	else
	{
		cout << "\nDa tim thay " << m << "nhan vien co nam sinh <= " << namsinh << " va co muc luong >= " << luong << endl;

		Xuattieude();
		for (int i = 0; i < m; i++)
		{
			Xuat_1_NV(b[i]);
			if ((i + 1) % 3 == 0)
				Xuatduongke('-');
		}
		Xuatduongke('=');
	}
}

void Timkiem_Hoten(Nhanvien a[], int n, Name name, unsigned int namsinh)
{
	int m = 0;
	Nhanvien b[MAX];

	for (int i = 0; i < n; i++)
		if (strcmp(a[i].name.ho, name.ho) == 0 && strcmp(a[i].name.ten, name.ten) == 0 && a[i].date.nam < namsinh)
		{
			b[m] = a[i];
			m++;
		}

	if (m == 0)
		cout << "\nKhong tim thay nhan vien co ho " << name.ho << " va co ten " << name.ten << endl;
	else
	{
		if (namsinh != 9999)
			cout << "\nDa tim thay " << m << "nhan vien co ho " << name.ho << "va co ten " << name.ten << "va co nam sinh " << namsinh << endl;
		else
			cout << "\nDa tim thay " << m << "nhan vien co ho " << name.ho << "va co ten " << name.ten << endl;
		
		Xuattieude();
		for (int i = 0; i < m; i++)
		{
			Xuat_1_NV(b[i]);
			if ((i + 1) % 3 == 0)
				Xuatduongke('-');
		}
		Xuatduongke('=');
	}
}

int Tinhchieudaichuoi(char a[])
{
	int res = 0;

	while (a[res] != '\0')
		res++;

	return res;
}

void Timkiem_Ten_Diachi(Nhanvien a[], int n, Name name, char diachi[])
{
	int m = 0;
	Nhanvien b[MAX];

	for (int i = 0; i < n; i++)
		if (strcmp(a[i].name.ten, name.ten) == 0 && strcmp(a[i].diachi, diachi) == 0)
		{
			b[m] = a[i];
			m++;
		}

	if (m == 0)
		cout << "\nKhong tim thay nhan vien co ten " << name.ten << "va co dia chi " << diachi << endl;

	else
	{
		cout << "\nDa tim thay " << m << "nhan vien co ten " << name.ten << "va co dia chi " << diachi << endl;

		Xuattieude();
		for (int i = 0; i < m; i++)
		{
			Xuat_1_NV(b[i]);
			if ((i + 1) % 3 == 0)
				Xuatduongke('-');
		}
		Xuatduongke('=');
	}
}