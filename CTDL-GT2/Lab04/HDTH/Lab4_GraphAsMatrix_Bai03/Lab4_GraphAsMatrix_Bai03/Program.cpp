#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>

using namespace std;

#include "Common.h"
#include <stack>
#include <queue>
#include "Graph.h"
#include "Menu.h"

void ChayChuongTrinh();

int main()
{
	ChayChuongTrinh();
}

void ChayChuongTrinh()
{
	Graph g;
	int menu, somenu = 8;
	do
	{
		menu = ChonMenu(somenu);
		Xulymenu(menu, g);
	} while (menu > 0);
}