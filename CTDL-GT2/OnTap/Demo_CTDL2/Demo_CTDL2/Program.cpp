#include <iostream>
#include <conio.h>
#include <fstream>

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
	Graph g;
	int menu, somenu = 5;
	do
	{
		menu = ChonMenu(somenu);
		XulyMenu(menu, g);
	} while (menu > 0);
}