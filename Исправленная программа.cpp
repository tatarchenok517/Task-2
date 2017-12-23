// Исправленная программа.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <iomanip>

using namespace std;

void vvod(int **arr, int rows, int cols)
{

	int a;
	printf("1. Заполнить массив случайными числами\n2.Ввести вручную\n");
	do
	{
		cin >> a;
		printf("Введите 1 или 2");
	} while ((a != 1) || (a != 2));
	
	switch (a)
	{
	case 1:
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = rand() % 1000;
				cout << setw(4) << arr[i][j];
			}
			cout << endl;
		}
		cout << endl;
		break;
	}
	case 2:
	{
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				cin >> arr[i][j];
			}
			cout << endl;
		}
		break;
	}
	}
}

void obrabotka(int **arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
		for (int k = 0; k < rows; k++)
			if (((arr[i][0] > arr[k][0]) && (i < k)) || ((arr[i][0] < arr[k][0]) && (i > k)))
			{
				for (int j = 0; j < cols; j++)
				{
					int r = arr[k][j];
					arr[k][j] = arr[i][j];
					arr[i][j] = r;

				}

			}
}

void vuvod(int **arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << setw(4) << arr[i][j];
		}
		cout << endl;
	}

}


int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_ALL, "rus");
	int rows = 0, cols = 0;
	int **arr = NULL;
	do
	{
		printf("Введите кол-во строк и столбцов \n");

		cin >> rows;
		cin >> cols;
		if ((rows <= 0) || (cols <= 0))
		{
			printf("Вводите только натуральные числа \n");
		}

	} while ((rows <= 0) || (cols <= 0));

	arr = new int*[rows];
	for (int i = 0; i < rows; i++)
		arr[i] = new int[cols];

	vvod(arr, rows, cols);
	obrabotka(arr, rows, cols);
	vuvod(arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;

	getchar();
	getchar();

	return 0;
}