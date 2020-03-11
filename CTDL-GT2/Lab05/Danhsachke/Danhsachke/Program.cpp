#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>

#include <stack>
#include <queue>

using namespace std;

#include "Common.h"
#include "Graph.h"
#include "Menu.h"

void Chaychuongtrinh();

int main()
{
	Chaychuongtrinh();
}

void Chaychuongtrinh()
{
	GraphADT g;
	int menu, soMenu = 10;
	do
	{
		menu = ChonMenu(soMenu);
		Xulymenu(menu, g);
	} while (menu > 0);
}