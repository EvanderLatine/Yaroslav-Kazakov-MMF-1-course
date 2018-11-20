#pragma once
#include <iostream>

using namespace std;

int binSearch(int*, int, int);

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