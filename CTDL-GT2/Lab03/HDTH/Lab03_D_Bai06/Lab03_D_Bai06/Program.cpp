#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include <iomanip>

#define MAX 20
#define THOAT 0

using namespace std;

struct date
{
	int ngay;
	int thang;
	int nam;
};

struct Nhanvien
{
	int ms;
	char Hoten[MAX];
	date ntn;
	char Diachi[MAX];
	double Luong;
};

void Xuat(Nhanvien ds[MAX], int n);
int read_struct(char* filename, Nhanvien ds[MAX]);

int main()
{
	char filename[80];
	Nhanvien ds[MAX];
	system("cls");
	cout << "Nhap ten file mo de doc: ";
	cin >> filename;
	int n = read_struct(filename, ds);
	Xuat(ds, n);
	return 0;
}

int read_struct(char* filename, Nhanvien ds[MAX])
{
	ifstream in(filename);
	if (!in)
	{
		cout << "\nLoi mo file!";
		exit(1);
	}
	int ms;
	char hoten[MAX];
	char diachi[MAX];
	double luong;
	int ngay, thang, nam;
	int i = 0;
	in >> ms;
	ds[i].ms = ms;
	in >> hoten;
	strcpy_s(ds[i].Hoten, hoten);
	in >> ngay;
	ds[i].ntn.ngay = ngay;
	in >> thang;
	ds[i].ntn.thang = thang;
	in >> nam;
	ds[i].ntn.nam = nam;
	in >> diachi;
	strcpy_s(ds[i].Diachi, diachi);
	in >> luong;
	ds[i].Luong = luong;

	while (!in.eof())
	{
		in >> ms;
		ds[i].ms = ms;
		in >> hoten;
		strcpy_s(ds[i].Hoten, hoten);
		in >> ngay;
		ds[i].ntn.ngay = ngay;
		in >> thang;
		ds[i].ntn.thang = thang;
		in >> nam;
		ds[i].ntn.nam = nam;
		in >> diachi;
		strcpy_s(ds[i].Diachi, diachi);
		in >> luong;
		ds[i].Luong = luong;
	}
	in.close();
	return i;
}

void Xuat(Nhanvien ds[MAX], int n)
{
	cout << setiosflags(ios::left);
	cout << setw(20) << "MS"
		<< setw(20) << "Ho ten"
		<< setw(20) << "NTN sinh"
		<< setw(20) << "Dia chi"
		<< setw(20) << "Luong"
		<< endl;
	for (int i = 0; i < n; i++)
	{
		cout << setw(20) << ds[i].ms
			<< setw(20) << ds[i].Hoten
			<< setw(2) << ds[i].ntn.ngay << '/'
			<< setw(2) << ds[i].ntn.thang << '/'
			<< setw(16) << ds[i].ntn.nam
			<< setw(20) << ds[i].Diachi
			<< setw(20) << ds[i].Luong
			<< endl;
	}
}