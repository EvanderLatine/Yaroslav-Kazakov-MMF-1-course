#pragma once
#include <iostream>
#include "mat.h"

const int N = 256;

using namespace std;

int getLength(char*);
int compare(char*, char*, bool = false);
bool isEqual(char*, char*, bool = true);
char toUpper(char);
int substringPosition(char*, char*);
void wordsInStr(char*, char[][N]);
void swap(char*);
void swap(char&, char&);

int getLength(char* source)
{
	int length = 0;

	while (source[length]) // \ - escape sequence | source[length] != '\0' == source[length]
	{
		length++;
	}

	return length;
}

int compare(char* lhs, char* rhs, bool caseSensitive)
{
	int i = 0;
	int lhsLength = getLength(lhs),
		rhsLength = getLength(rhs);
	int minLength = (lhsLength >= rhsLength) ? lhsLength : rhsLength;

	while (i < minLength)
	{
		char chl = !caseSensitive ? lhs[i] : toUpper(lhs[i]),
			chr = !caseSensitive ? rhs[i] : toUpper(rhs[i]);

		if (chl != chr)
		{
			return (chl > chr) ? 1 : -1;
		}
		i++;
	}

	return 0;
}

bool isEqual(char* lhs, char* rhs, bool caseSensitive)

{
	int n = getLength(lhs),
		m = getLength(rhs);

	if (n != m)
	{
		return false;
	}
	int i = 0;

	while (i < n)
	{
		char chl = caseSensitive ? lhs[i] : toUpper(lhs[i]),
			chr = caseSensitive ? rhs[i] : toUpper(rhs[i]);

		if (chl != chr)
		{
			return false;
		}
		i++;
	}

	return true;
}

char toUpper(char symbol)
{
	const int difference = 'a' - 'A';

	if ('a' <= symbol && 'z' >= symbol)
	{
		symbol -= difference;
	}

	return symbol;
}

int substringPosition(char* string, char* substring)
{
	int n = getLength(string),
		m = getLength(substring);

	if (m > n)
	{
		return -1;
	}
	int index = -1;

	for (int i = 0, j = 0; i < n && j < m; i++)
	{
		if (string[i] == substring[j])
		{
			j++;
		}
		if (j == m && i != n - 1)
		{
			return i;
		}
	}
	return index;
}

void wordsInStr(char* str, char words[][N])
{
	int strLength = getLength(str),
		i = 0, j = 0, k = 0;

	while (i < strLength)
	{
		if ('a' <= str[i] && 'z' >= str[i] || 'A' <= str[i] && 'Z' >= str[i])
		{
			words[j][k] = str[i];
			k++;
			i++;
			continue;
		}

		i++;
		j++;
		k = 0;
	}
}

void swap(char* arr)
{
	int length = getLength(arr);

	for (int i = 0; i < length / 2; i++)
	{
		swap(arr[i], arr[length - 1 - i]);
	}
}

void swap(char& left, char& right)
{
	left += right;
	right = left - right;
	left -= right;
}
