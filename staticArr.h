#pragma once
#include "string.h"

using namespace std;

void inputArr(int, char*); //dimention of array, array pointer
void inputArr(int, int*);
char equalStr(char*, char*);
int compareStr(char*, char*); // +1 if arr1 < arr2, 0 if arr1 = arr2
int wordInStr(char*, char*); // string, word	(returns index of string(word) entry in string)
int wordInStr(char*, int); // string, word length	(returns index of string(word) consisted of n symbols in string)
void splice(char*, int&, int, int, int); // string, link to string length, index of starting symbol, to delete, to insert
void shift(char*, int); // array to change, direction and step of shifting ( - left, + right)
void displayArr(char*, int);
void displayArr(int*, int);
void displayArr(char[][N]);
int abs(int);

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

char equalStr(char* arr1, char* arr2)
{
	int n = getLength(arr1),
		m = getLength(arr2);
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

int compareStr(char* arr1, char* arr2)
{
	int n = getLength(arr1),
		m = getLength(arr2);
	int result = 0;

	if (n == m)
	{
		int i = 0;

		while (i < n)
		{
			if (arr1[i] == arr2[i])
			{
				continue;
			}
			else if (arr1[i] < arr2[i])
			{
				return 1;
				break;
			}
			else
			{
				return -1;
				break;
			}
			i++;
		}

		return result;
	}
	else
	{
		cout << "Strings have different length\n";
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

void splice(char* target, int& n, int wordIndex, int m, int k = 0)
{
	int splice = abs(k - m);

	if (k > m)
	{
		for (int i = n - 1; i >= wordIndex + m; i--)
		{
			target[i + splice] = target[i];
		}
		n += splice;
	}
	else if (k < m)
	{
		for (int i = wordIndex + m; i <= n; i++)
		{
			target[i - splice] = target[i];
		}
		n -= splice;
	}
}

void displayArr(char* arr)
{
	for (int i = 0; i < getLength(arr); i++)
	{
		cout << arr[i];
	}
	cout << endl;
}

void displayArr(int* arr)
{
	for (int i = 0; i < getLength(arr); i++)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void displayArr(char matrix[][N])
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
	}
}

int abs(int n)
{
	if (n > 0)
	{
		return n;
	}
	else
	{
		return n * (-1);
	}
}

void shift(char* arr, int n)
{
	int length = getLength(arr);

	if (n > 0)
	{
		for (int i = 0; i < n; i++)
		{
			int j = 0;
			char last = arr[n - 1];

			while (j < length - 2)
			{
				arr[j + 1] = arr[j];
				j++;
			}

			arr[0] = last;
		}
	}
	else
	{
		for (int i = 0; i < -n; i++)
		{
			int j = length;
			char first = arr[0];

			while (j > 0)
			{
				arr[j - 2] = arr[j - 1];
				j--;
			}

			arr[length] = first;
		}
	}
}