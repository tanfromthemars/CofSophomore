#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string.h>

#include <list>	
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
	int menu, somenu = 12;
	do
	{
		menu = ChonMenu(somenu);
		XulyMenu(menu, g);
	} while (menu > 0);
}