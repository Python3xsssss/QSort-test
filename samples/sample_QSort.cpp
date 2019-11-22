#include <iostream>
#include "QSort.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	int size = 10;
	int* mas = new int[size];

	cout << "Qsort:" << endl;
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 10;
	Print(mas, size);	
	QuickSort(mas, 0, size - 1, 1);
	Print(mas, size);

	cout << endl << "CountSort:" << endl;
	for (int i = 0; i < size; i++)
		mas[i] = rand() % 10;
	Print(mas, size);
	CountSort(mas, size);
	Print(mas, size);
	_getch();
}
