#pragma once
#include <iostream>

using namespace std;

int findMax(int*, int);
int binSearch(int*, int, int);
void bubbleSort(int*, int);
void selectionSort(int*, int);
void insertionSort(int*, int);


int findMax(int* arr, int n)
{
	int k = 0;
	for (int j = 1; j < n; j++)
	{	
		if (arr[j] > arr[k])
		{
			k = j;
		}
	}
	return arr[k];
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;

	for (i = 0; i < n - 1; i++)
	{
		swapped = false;
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
}

void selectionSort(int * array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}

		swap(array[min], array[i]);
	}
}

void insertionSort(int* array, int dimension)
{
	int current, j;
	for (int i = 1; i < dimension; i++)
	{
		current = array[i];
		for (j = i - 1; array[j] > current; j--)
		{
			array[j + 1] = array[j];
		}
		array[j + 1] = current;
	}
}

int binSearch(int* arr, int dimension, int toFind)
{
	dimension = dimension / 2;
	int arrIndex = dimension;

	while (arrIndex)
	{
		if (arr[arrIndex] == toFind)
		{
			return arrIndex;
		}
		else if (arr[arrIndex] < toFind)
		{
			dimension /= (dimension == 1) ? 1 : 2;
			arrIndex += dimension;
		}
		else 
		{
 			dimension /= (dimension == 1) ? 1 : 2;
			arrIndex -= dimension;
		}
	}
}