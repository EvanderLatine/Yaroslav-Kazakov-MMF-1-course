#include <iostream>
#include "sortSearch.h"

using namespace std;

int inputNumber();
int numbersQuantity();
void inputArray(int, int*); //dimention of array, array pointer
char inputCase();
int useSwitch();
int symbol_10(int, int); // number, digit
int symbol_16(int, int); // number, digit
void seqType(int*, int, int&, int&, int&);
int lessThann(int, int); //dimention of array, comparednumber
void outputResult(int);
void outSeqType(int); //dimention of array

int main()
{
	char esc = 'y';

	while (esc == 'y' || esc == 'y')
	{
		outputResult(useSwitch());
		cout << "you can continue if you press y\n";
		cin >> esc;
		system("cls");
	}
	return 0;
}

int inputNumber()
{
	int num;
	cout << "setting integer:\nnumber =  ";
	cin >> num;
	system("cls");
	return num;
}

int numbersQuantity()
{
	cout << "setting quantity of sequence numbers:\nnumber =  ";
	while (true)
	{
		int num;
		cin >> num;
		system("cls");

		if (num > 1)
		{
			return num;
		}

		cout << "quantity of sequence numbers should be more than 1" << endl;
	}
}

void inputArray(int n, int* array)
{
	cout << "input array numbers:" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
	system("cls");
}

char inputCase()
{
	char letter;

	while (true)
	{
		cout << "choosing algorithm. you need to write algorithm title (letter after => )\ndefine type of sequence => a\nquantity of numbers less than n in decreasing sequence => b\ntitle: ";
		cin >> letter;
		if (64 < letter && letter < 75 || 96 < letter && letter < 107)
		{
			system("cls");
			return tolower(letter);
		}

		system("cls");
	}
}

int useSwitch()
{
	switch (inputCase())
	{
	case 'a':
	{
		cout << "please, define quantity of numbers, from which array'll be consisted\nmaximal dimension of the array is 100, and minimal is 2.\n";
		outSeqType(numbersQuantity());
		break;
	}

	case 'b':
	{
		return lessThann(numbersQuantity(), inputNumber());
		break;
	}

	default:
	{
		break;
	}
	}
}

int symbol_10(int number, int symbol)
{
	int quantity = 0;

	while (number)
	{
		quantity += (number % 10 == symbol) ? 1 : 0;
		number /= 10;
	}

	return quantity;
}

int symbol_16(int number, int symbol)
{
	const int n = 16;
	int array[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int quantity = 0;

	while (number)
	{
		quantity += (number % 16 == array[symbol]) ? 1 : 0;
		number = (number - number % 16) / 16;
	}

	return quantity;
}

void seqType(int* arr, int n, int& equal, int& greater, int& less)
{
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] == arr[i + 1])
		{
			equal++;
		}
		else if (arr[i] < arr[i + 1])
		{
			greater++;
		}
		else
		{
			less++;
		}
	}
}

int lessThann(int arraylength, int compared)
{
	const int N = 100;
	int arr[N] = { 0 };
	int quantity = 0;

	inputArray(arraylength, arr);

	return binSearch(arr, arraylength, compared);
}

void outSeqType(int n)
{
	const int N = 100;
	int arr[N];
	int equal = 0, greater = 0, less = 0;

	inputArray(n, arr);
	seqType(arr, n, equal, greater, less);
	if(greater && less)
	{
		cout << "this sequence is disordered" << endl;
	}
	else if(equal && greater)
	{
		cout << "this sequence is increasing" << endl;
	}
	else if(equal && less)
	{
		cout << "this sequence is decreasing" << endl;
	}
	else if(greater)
	{
		cout << "this sequence is strictly increasing" << endl;
	}
	else if (less)
	{
		cout << "this sequence is strictly decreasing" << endl;
	}
	else 
	{
		cout << "this sequence equal" << endl;
	}	
}

void outputResult(int result)
{
	cout << "Result is: " << result << endl;
}
