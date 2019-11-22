#pragma once
#ifndef _QSORT_H_
#define _QSORT_H_

#include <cstdlib>
#include <ctime>

template <typename ValType>
void Print(ValType* mas, int size)
{
	for (int i = 0; i < size; i++)
		cout << mas[i] << " ";
	cout << endl;
}

template <typename ValType>
void QuickSort(ValType* mas, int down, int up, int mode)
{
	srand(time(NULL));
	int i = down, j = up, fixik = mas[rand() % (up - down + 1) + down];

	while (i <= j)
	{
		while ((mas[j] < fixik) && (mode == -1) || (mas[j] > fixik) && (mode == 1))
			j--;
		while ((mas[i] > fixik) && (mode == -1) || (mas[i] < fixik) && (mode == 1))
			i++;
		if (i <= j)
		{
			ValType tmp = mas[i];
			mas[i] = mas[j];
			mas[j] = tmp;
			i++;
			j--;
		}
	}
	if (down < j)
		QuickSort(mas, down, j, mode);
	if (up > i)
		QuickSort(mas, i, up, mode);
}


void CountSort(int* mas, int size)
{
	int tmp[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int* out = new int[size];

	for (int i = 0; i < size; i++)
		for (int j = mas[i]; j < 10; j++)
			tmp[j]++;
	for (int i = 0; i < size; i++)
	{
		out[tmp[mas[i]] - 1] = mas[i];
		tmp[mas[i]]--;
	}
		
	for (int i = 0; i < size; i++)
		mas[i] = out[i];
	delete[] out;
}

void

#endif
