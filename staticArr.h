#pragma once
#include "mat.h"

using namespace std;

void inputArr(int, char*); //dimention of array, array pointer
void inputArr(int, int*);
char equalStr(char*, int, char*, int);
char compareStr(char*, int, char*, int);
int wordInStr(char*, char*); // string, word	(returns index of string(word) entry in string)
int wordInStr(char*, int); // string, word length	(returns index of string(word) entry in string)
void shift(char*, int&, int, int, int); // string, link to string length, index of starting symbol, length of replaced word, length of inserted word
void displayArr(char*, int);
void displayArr(int*, int);
void displayArr(char[][N]);

void inputArr(int n, char* array)
{
	cout << "input string:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
	system("cls");
}

void inputArr(int n, int* array)
{
	cout << "input array numbers:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
	system("cls");
}

char equalStr(char* arr1, int n, char* arr2, int m)
{
	bool flag = false;

	if (n == m)
	{
		flag = true;

		for (int i = 0; i < n; i++)
		{
			if (arr1[i] != arr2[i])
			{
				flag = false;
				break;
			}
		}
	}

	if (flag)
	{
		return '=';
	}
	else
	{
		return '?';
	}
}

char compareStr(char* arr1, int n, char* arr2, int m)
{
	int result = 0;

	if (n == m)
	{
		int i = 0;

		while (i < n)
		{
			if (arr1[i] == arr2[i])
			{
				result += 1;
			}
			else if (arr1[i] < arr2[i])
			{
				result += 1;
				break;
			}
			else
			{
				result += 2;
				break;
			}
			i++;
		}
		result -= i;
	}
	else
	{
		cout << "Arrays have different length";
	}

	if (!result)
	{
		return '=';
	}
	else if (result == 1)
	{
		return '<';
	}
	else
	{
		return '>';
	}
}

int wordInStr(char* arr1, char* arr2)
{
	int	n = getLength(arr1),
		m = getLength(arr2);

	for (int i = 0; i <= n - m; i++)
	{
		int j = 0;
		if (arr1[i] == arr2[0])
		{
			j++;

			while (j < m)
			{
				if (arr1[i + j] != arr2[j])
				{
					break;
				}
				j++;
			}
		}
		if (j == m)
		{
			return i;
		}
	}
	return -1;
}

int wordInStr(char* arr1, int m)
{
	int	n = getLength(arr1);

	for (int i = 0; i <= n - m; i++)
	{
		int j = 0;
		if (arr1[i] >= 'a' && arr1[i] <= 'z' || arr1[i] >= 'A' && arr1[i] <= 'Z')
		{
			j++;

			while (arr1[i + j] >= 'a' && arr1[i + j] <= 'z' || arr1[i + j] >= 'A' && arr1[i + j] <= 'Z')
			{
				j++;
			}
		}
		if (j == m)
		{
			return i;
		}
	}
	return -1;
}

void shift(char* target, int& n, int wordIndex, int m, int k = 0)
{
	int shift = abs(k - m);

	if (k > m)
	{
		for (int i = n - 1; i >= wordIndex + m; i--)
		{
			target[i + shift] = target[i];
		}
		n += shift;
	}
	else if (k < m)
	{
		for (int i = wordIndex + m; i <= n; i++)
		{
			target[i - shift] = target[i];
		}
		n -= shift;
	}
}

void displayArr(char* arr)
{
	for (int i = 0, n = getLength(arr); i < n; i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

void displayArr(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void displayArr(char matrix[][N] )
{
	int n = 0;

	while (matrix[n][0])
	{
		int m = 0;

		while (matrix[n][m])
		{
			cout << matrix[n][m];
			m++;
		}
		cout << endl;
		n++;
		m = 0;
	}
}