﻿#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

int m;	//m phần thưởng
int n;	//n học sinh
int r;	//r cách chia
int P[100];	//Mảng p kết quả

using namespace std;

#include "Header_Graph.h"
#include "Graph.h"
#include "Header.h"
#include "Menu.h"

void Chaychuongtrinh();

int main()
{
	Chaychuongtrinh();
	return 0;
}

void Chaychuongtrinh()
{
	int menu, soMenu = 4;
	Mang a;
	do
	{
		menu = ChonMenu(soMenu);
		XulyMenu(menu);
	} while (menu > 0);
}