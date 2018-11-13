#include <iostream>
#include "myLibrary.h"

using namespace std;

int inputDecimalDigit();
int inputNumber();
int inputQuantityOfNumbers();
void inputArray(int, int*); //dimention of array, array pointer
char inputCase();
int useSwitch(); 
void resultForEachNumberDecimal();
void resultForEachNumberHexadecimal();
int decimalDigitToBinary(int);
int decimalDigitToHexadecimal();
int quantityOfSymbolForDecimals(int, int); // number, digit
int quantityOfSymbolForHexadecimals(int, int); // number, digit
bool isIncreasing(int*, int); //array pointer, dimention of array
bool isDecreasing(int*, int); //array pointer, dimention of array
bool isStrictlyIncreasing(int*, int); //array pointer, dimention of array
bool isStrictlyDecreasing(int*, int); //array pointer, dimention of array
int defineTypeOfSequence(int);
int numbersLessThanN(int, int); //dimention of array, comparedNumber
void outputResult(int);
void outputSequenceType(int); //dimention of array

int main()
{
	char esc = 'y';

	while (esc == 'y' || esc == 'Y')
	{
		outputResult(useSwitch());
		cout << "You can continue if you press y\n";
		cin >> esc;
		system("cls");
	}
	return 0;
}

int inputNumber()
{
	int num;
	cout << "Setting integer:\nNumber =  ";
	cin >> num;
	system("cls");
	return num;
}

int inputQuantityOfNumbers()
{
	cout << "Setting quantity of sequence numbers:\nNumber =  ";
	while (true)
	{
		int num;
		cin >> num;
		system("cls");

		if (num > 1)
		{
			return num;
		}

		cout << "Quantity of sequence numbers should be more than 1" << endl;
	}
}

int inputDecimalDigit()
{
	int symbol;
	cout << "Setting symbol:\nSymbol =  ";
	cin >> symbol;
	system("cls");
	return symbol;
}

void inputArray(int n, int* array)
{
	cout << "Input array numbers:" << endl;

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
		cout << "Choosing algorithm. You need to write algorithm title (letter after => )\nQuantity of symbol in binary number => a\nQuantity of symbol in hexadecimal number => b\nQuantity of symbol in each binary number from array => c\nQuantity of symbol in each hexadecimal number from array => d\nDefine type of sequence => e\nQuantity of numbers less than N in decreasing sequence => f\nTitle: ";
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
			return quantityOfSymbolForDecimals(decimalDigitToBinary(inputNumber()), inputDecimalDigit());
			break;
		}

		case 'b':
		{
			return quantityOfSymbolForHexadecimals(inputNumber(), decimalDigitToHexadecimal());
			break;
		}

		case 'c':
		{
			resultForEachNumberDecimal();
			break;
		}

		case 'd':
		{
			resultForEachNumberHexadecimal();
			break;
		}

		case 'e':
		{
			cout << "Please, define quantity of numbers, from which array'll be consisted\nMaximal dimension of the array is 100, and minimal is 2.\n";
			outputSequenceType(inputQuantityOfNumbers());
			break;
		}

		case 'f':
		{
			return numbersLessThanN(inputQuantityOfNumbers(), inputNumber());
			break;
		}

		default:
		{
			break;
		}
	}
}

void resultForEachNumberDecimal()
{
	const int N = 100;
	int array[N] = { 0 };
	int n, symbol;
	
	cout << "Symbol to be found in each number from array.\n";
	symbol = inputDecimalDigit();
	cout << "Amount of numbers in array. Maximum amount is 100.\n";
	n = inputNumber();
	inputArray(n, array);

	for (int i = 0; i < n; i++)
	{
		cout << "For number " << array[i] << " & digit " << symbol << ' ';
		outputResult(quantityOfSymbolForDecimals(decimalDigitToBinary(array[i]), symbol));
	}
	
}

void resultForEachNumberHexadecimal()
{
	const int N = 100;
	int array[N] = { 0 };
	int n, symbol;

	cout << "Symbol to be found in each number from array.\n";
	symbol = decimalDigitToHexadecimal();
	cout << "Amount of numbers in array. Maximum amount is 100.\n";
	n = inputNumber();
	inputArray(n, array);

	for (int i = 0; i < n; i++)
	{
		cout << "For number " << array[i] << " & digit " << symbol << ' ';
		outputResult(quantityOfSymbolForHexadecimals(array[i], symbol));
	}

}

int decimalDigitToBinary(int decimal)
{
	int dividend = decimal,
		binary = 0,
		i = 1;

	while (dividend)
	{
		binary += (dividend % 2) * i;
		dividend /= 2;
		i *= 10;
	}

	return binary;
}

int decimalDigitToHexadecimal()
{
	const int N = 16;
	char symbol;
	char hexadecimalDigits[N] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
	cout << "Setting symbol:\nsymbol =  ";
	cin >> symbol;

	if (64 < symbol && symbol < 71)
	{
		symbol += 32;
	}

	for (int i = 0; i < N; i++)
	{
		if (hexadecimalDigits[i] == symbol)
		{
			system("cls");
			return i;
		}
	}
}

int quantityOfSymbolForDecimals(int number, int symbol)
{
	int quantity = 0;

	while (number)
	{
		quantity += (number % 10 == symbol) ? 1 : 0;
		number /= 10;
	}

	return quantity;
}

int quantityOfSymbolForHexadecimals(int number, int symbol)
{
	const int N = 16;
	int array[N] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };
	int quantity = 0;

	while (number)
	{
		quantity += (number % 16 == array[symbol]) ? 1 : 0;
		number = (number - number % 16) / 16;
	}

	return quantity;
}

bool isIncreasing(int* array, int n)
{
	bool result = true;
	int numberOfEqual = 0;
	n-= 2;

	for (int i = 0; i < n; i++)
	{
		if (array[i] > array[i + 1])
		{
			result = false;
			break;
		}

		if (array[i] == array[i + 1])
		{
			numberOfEqual++;
		}
	}

	if (numberOfEqual == n)
	{
		return false;
	}

	return result;
}

bool isDecreasing(int* array, int n)
{
	bool result = true;
	int numberOfEqual = 0;
	n-= 2;

	for (int i = 0; i < n; i++)
	{
		if (array[i] < array[i + 1])
		{
			result = false;
			break;
		}

		if (array[i] == array[i + 1])
		{
			numberOfEqual++;
		}
	}

	if (numberOfEqual == n)
	{
		return false;
	}

	return result;
}

bool isStrictlyIncreasing(int* array, int n)
{
	bool result = true;
	n-= 2;

	for (int i = 0; i < n; i++)
	{
		if (array[i] >= array[i + 1])
		{
			result = false;
			break;
		}
	}

	return result;
}

bool isStrictlyDecreasing(int* array, int n)
{
	bool result = true;
	n-= 2;

	for (int i = 0; i <= n; i++)
	{
		if (array[i] <= array[i + 1])
		{
			result = false;
			break;
		}
	}

	return result;
}

int defineTypeOfSequence(int n)
{
	const int N = 100;
	int array[N] = { 0 };

	inputArray(n, array);

	if (isStrictlyIncreasing(array, n))
	{
	return 3;
	}
	else if (isStrictlyDecreasing(array, n))
	{
	return 4;
	}
	else if (isIncreasing(array, n))
	{
		return 1;
	}
	else if (isDecreasing(array, n))
	{
		return 2;
	}
	else
	{
		return 0;
	}
}

int numbersLessThanN(int arrayLength, int comparedNumber)
{
	const int N = 100;
	int array[N] = { 0 };
	int quantity = 0;

	inputArray(arrayLength, array);

	while (!isDecreasing(array, arrayLength))
	{
		cout << "Sequence should be decreasing.\nPlease, repeat input" << endl;
		inputArray(arrayLength, array);
	}

	for (int i = 0; i < arrayLength; i++)
	{
		if (array[i] < comparedNumber)
		{
			return arrayLength - i;
		}
	}
}

void outputResult(int* result)
{
	cout << "Result is: " << result << endl;
}

void outputResult(int result)
{
	cout << "Result is: " << result << endl;
}

void outputSequenceType(int n)
{
	switch (defineTypeOfSequence(n))
	{
		case 1:
		{
			cout << "This sequence is increasing" << endl;
			break;
		}

		case 2:
		{
			cout << "This sequence is decreasing" << endl;
			break;
		}

		case 3:
		{
			cout << "This sequence is strictly increasing" << endl;
			break;
		}

		case 4:
		{
			cout << "This sequence is strictly decreasing" << endl;
			break;
		}

		default:
		{
			cout << "This sequence is disordered" << endl;
			break;
		}
	}
}
