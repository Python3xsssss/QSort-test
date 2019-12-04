#pragma once
#ifndef _QSORT_H_
#define _QSORT_H_

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

struct SOMETHING
{
	int value;
	string whatever;

	friend std::ostream& operator<<(std::ostream& ostr, const SOMETHING& op);
};

std::ostream& operator<<(std::ostream& ostr, const SOMETHING& op)
{
	ostr << op.whatever;
	return ostr;
}

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


void CountSort(SOMETHING* mas, int size, size_t max)
{
	int* tmp = new int[max + 1];
	SOMETHING* out = new SOMETHING[size];
	for (int i = 0; i < max + 1; i++)
		tmp[i] = 0;

	for (int i = 0; i < size; i++)
		for (int j = mas[i].value; j < max + 1; j++)
			tmp[j]++;

	for (int i = size - 1; i >= 0; i--)
	{
		out[tmp[mas[i].value] - 1] = mas[i];
		tmp[mas[i].value]--;
	}
		
	for (int i = 0; i < size; i++)
		mas[i] = out[i];
	delete[] tmp;
	delete[] out;
}


void CountSort(int* mas, int size, size_t max)
{
	int* tmp = new int[max + 1];
	int* out = new int[size];
	for (int i = 0; i < max + 1; i++)
		tmp[i] = 0;

	for (int i = 0; i < size; i++)
		for (int j = mas[i]; j < max + 1; j++)
			tmp[j]++;

	for (int i = size - 1; i >= 0; i--)
	{
		out[tmp[mas[i]] - 1] = mas[i];
		tmp[mas[i]]--;
	}

	for (int i = 0; i < size; i++)
		mas[i] = out[i];
	delete[] tmp;
	delete[] out;
}

#endif
