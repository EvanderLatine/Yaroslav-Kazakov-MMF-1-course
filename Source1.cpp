#include <iostream>

using namespace std;

const int N = 100;

int nextSmallerThan(int);
void nextSmallerThanTests();
void swap(int*, int);
void swap(int&, int&);
int getLength(int*);

int main()
{
	nextSmallerThanTests();
}

int nextSmallerThan(int number)
{
	int digits[N] = { '\0' };
	int numberCopy = number,
		i = 0;

	while (numberCopy > 0)
	{
		digits[i] = numberCopy % 10;
		numberCopy /= 10;
		i++;
	}

	int length = i;
	swap(digits, length);

	for (int i = length - 1; i > 0; i--)
	{
		int j = 1;

		while (digits[i] > digits[i - j] && i - j >= 0 && digits[1] != 0)
		{
			j++;
		}

		if (i - j >= 0)
		{
			swap(digits[i], digits[i - j]);
			break;
		}
	}

	int result = 0,
		multiplier = 1;

	for (int i = length - 1; i >= 0; i--)
	{
		result += digits[i] * multiplier;
		multiplier *= 10;
	}

	if (result < number)
	{
		return result;
	}

	return -1;
}

void nextSmallerThanTests()
{
	cout << (nextSmallerThan(21) == 12) << endl;
	cout << (nextSmallerThan(531) == 513) << endl;
	cout << (nextSmallerThan(2071) == 2017) << endl;
	cout << (nextSmallerThan(9) == -1) << endl;
	cout << (nextSmallerThan(111) == -1) << endl;
	cout << (nextSmallerThan(135) == -1) << endl;
	cout << (nextSmallerThan(1027) == -1) << endl;
	cout << (nextSmallerThan(20026731) == 20026713) << endl;
	cout << (nextSmallerThan(5303601) == 5303106) << endl;
	cout << (nextSmallerThan(272371) == 272317) << endl;
	cout << (nextSmallerThan(10000) == -1) << endl;
	cout << (nextSmallerThan(22555555) == -1) << endl;
	cout << (nextSmallerThan(37593) == 37539) << endl;
	cout << (nextSmallerThan(12345678) == -1) << endl;
}

void swap(int& left, int& right)
{
	left += right;
	right = left - right;
	left -= right;
}

void swap(int* arr, int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		swap(arr[i], arr[length - 1 - i]);
	}
}

int getLength(int* source)
{
	int length = 0;

	while (source[length]) // \ - escape sequence | source[length] != '\0' == source[length]
	{
		length++;
	}

	return length;
}