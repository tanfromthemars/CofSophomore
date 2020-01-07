#include <iostream>
#include <fstream>
#include <iomanip>
#define MAX 100

using namespace std;

struct NHANVIEN
{
	char MaNV[10];
	char Hoten[20];
	int Namsinh;
	char Diachi[20];
	double LuongCB;
};

void MangCT_TTCT(const char* f, NHANVIEN ds[MAX], int n);
int TTCT_MangCT(const char* f, NHANVIEN test[MAX]);
void Xuatmang(NHANVIEN test[MAX], int m);

void main()
{
	NHANVIEN ds[MAX] =
	{
		{"123456", "Tran_Tuan", 1960, "Da Lat", 12500000},
		{"103456", "Truong_Tuan_Ngoc", 1961, "Sai Gon", 12500000},
		{"456780", "Nguyen_Van_Nam", 1970, "Nha Trang", 20200000}
	};
	
	int n = 3;
	cout << "\nDu lieu mang cau truc DS: \n";
	Xuatmang(ds, n);
	
	//Chuyen mang cau truc DS vao tap tin "Nhanvien.txt"
	MangCT_TTCT("Nhanvien.txt", ds, n);

	NHANVIEN test[MAX];

	//Chuyen lai du lieu tap tin "Nhanvien.txt" vao mang cau truc TEST
	int m = TTCT_MangCT("Nhanvien.txt", test);
	cout << "\nDu lieu mang cau truc TEST: \n";
	Xuatmang(test, m);
}

//Mang cau truc -> Tap tin cau truc
void MangCT_TTCT(const char* f, NHANVIEN ds[MAX], int n)
{
	ofstream out(f);
	if (!out)
	{
		cout << "\nLoi mo file!";
		exit(1);
	}
	int i;
	for (i = 0; i < n; i++)
	{
		cout << setiosflags(ios::left)
			<< setw(10) << ds[i].MaNV
			<< setw(20) << ds[i].Hoten
			<< setw(10) << ds[i].Namsinh
			<< setw(20) << ds[i].Diachi
			<< setiosflags(ios::fixed) << setprecision(2)
			<< setw(10) << ds[i].LuongCB << '\n';
	}
	out.close();
}

//Tap tin -> Mang cau truc
int TTCT_MangCT(const char* f, NHANVIEN test[MAX])
{
	ifstream in(f);
	if (!in)
	{
		cout << "\nLoi mo file!";
		exit(1);
	}
	char MaNV[10];
	char Hoten[20];
	int Namsinh;
	char Diachi[20];
	double LuongCB;

	int i = 0;
	in >> MaNV;
	strcpy_s(test[i].MaNV, MaNV);
	in >> Hoten;
	strcpy_s(test[i].Hoten, Hoten);
	in >> Namsinh;
	test[i].Namsinh, Namsinh;
	in >> Diachi;
	strcpy_s(test[i].Diachi, Diachi);
	in >> LuongCB;
	test[i].LuongCB, LuongCB;

	while (!in.eof())
	{
		i++;
		in >> MaNV;
		strcpy_s(test[i].MaNV, MaNV);
		in >> Hoten;
		strcpy_s(test[i].Hoten, Hoten);
		in >> Namsinh;
		test[i].Namsinh, Namsinh;
		in >> Diachi;
		strcpy_s(test[i].Diachi, Diachi);
		in >> LuongCB;
		test[i].LuongCB, LuongCB;
	}
	i++;
	in.close();
	return i;
}

void Xuatmang(NHANVIEN test[MAX], int m)
{
	int i;
	cout << setiosflags(ios::left)
		<< setw(10) << "MaNV"
		<< setw(20) << "Hoten"
		<< setw(10) << "NS"
		<< setw(20) << "Diachi"
		<< setw(10) << "LuongCB";
	cout << endl;
	for (i = 0; i < m; i++)
	{
		cout << setiosflags(ios::left)
			<< setw(10) << test[i].MaNV
			<< setw(20) << test[i].Hoten
			<< setw(10) << test[i].Namsinh
			<< setw(20) << test[i].Diachi
			<< setiosflags(ios::fixed) << setprecision(2) << setw(10)
			<< test[i].LuongCB << '\n';
	}
}