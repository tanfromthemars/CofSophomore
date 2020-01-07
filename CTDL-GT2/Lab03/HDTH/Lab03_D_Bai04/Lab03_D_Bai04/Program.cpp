#include <iostream>
#include <fstream>
#include <conio.h>
#define MAX 100

using namespace std;

void file_mat(char* filename, int a[MAX][MAX], int& n);

int main()
{
	int n, a[MAX][MAX], i, j;
	char filename[80];
	
	system("cls");
	cout << "Nhap ten file mo de doc: ";
	cin >> filename;
	file_mat(filename, a, n);
	cout << "\nN = " << n;
	cout << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\n";
		for (j = 0; j < n; j++)
			cout << a[i][j] << '\t';
	}
	return 0;
}

void file_mat(char* filename, int a[MAX][MAX], int& n)
{
	ifstream in(filename); //Doc file
	if (!in)
	{
		cout << "\nLoi mo file!";
		exit(1);
	}
	in >> n;
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			in >> a[i][j];
	in.close();
}