#include "QSort.h"
#include <conio.h>
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	size_t size, max;
	int another;

	do
	{
		cout << "Enter the size of array and max value of the element of array: ";
		cin >> size >> max;
		int* arr = new int[size];
		int change;

		do
		{
			cout << endl << "Qsort ";
			for (int i = 0; i < size; i++)
				arr[i] = rand() % (max + 1);

			clock_t time = clock();
			QuickSort(arr, 0, size - 1, 1);
			time = clock() - time;
			cout << "time: " << int((double)time * 1000 / CLOCKS_PER_SEC) << endl;

			cout << "CountSort ";
			for (int i = 0; i < size; i++)
				arr[i] = rand() % (max + 1);

			time = clock();
			CountSort(arr, size, max);
			time = clock() - time;
			cout << "time: " << int((double)time * 1000 / CLOCKS_PER_SEC) << endl;

			cout << "Wanna sort this array again? (1 - Yes; 0 - No, I want Changes!): ";
			cin >> change;
		} while (change != 0);

		cout << endl << "Wanna sort with new parameters? (1 - Yes; 0 - No, exit!): ";
		cin >> another;
		cout << endl;
	} while (another != 0);
	
	cout << "The end" << endl;
	_getch();
}
