#include <iostream>
#include <fstream>
#include <conio.h>
#define MAX 100

using namespace std;

void file_array(char* filename, int arr[MAX], int& n);

int main()
{
	int n, arr[MAX];
	char filename[MAX];
	system("cls");
	cout << "Nhap ten file de doc: ";
	cin >> filename;
	file_array(filename, arr, n);
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\t";
	return 0;
}

void file_array(char* filename, int arr[MAX], int& n)
{
	ifstream in(filename); //Mo tap tin filename
	if (!in) //Kiem tra viec mo tap tin	
	{
		cout << "\nLoi mo file!";
		exit(1);
	}
	in >> n; //Doc du lieu dau tien cua tap tin (hang dau), xac dinh kich thuoc mang
	for (int i = 0; i < n; i++)
	{
		in >> arr[i]; //Lan luot doc du lieu tap tin ghi vao mang 1 chieu
	}
	in.close();
}