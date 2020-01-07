#include <iostream>
#include <fstream>
#include <conio.h>

#define MAX 100

using namespace std;

void file_array(char* filename, int arr[MAX], int& n);

int main()
{
	int n, arr[MAX];
	char filename[80];
	
	system("cls");
	cout << "Nhap ten file mo de doc: ";
	cin >> filename;
	
	file_array(filename, arr, n);
	
	cout << "\nN = " << n;
	cout << endl;
	
	for (int i = 0; i < n; i++)
		cout << arr[i] << '\t';
	
	return 0;
}

void file_array(char* filename, int arr[MAX], int& n)
{
	ifstream in(filename); //Mo de doc
	if (!in)
	{
		cout << "\nLoi mo file!";
		exit(1);
	}
	n = 0;
	in >> arr[n];
	while (!in.eof())
	{
		n++;
		in >> arr[n];
	}
	n++;
	in.close();
}