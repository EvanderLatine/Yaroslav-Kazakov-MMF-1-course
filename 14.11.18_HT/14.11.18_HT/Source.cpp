#include <iostream>
#include "myLibrary.h"

using namespace std;

int inputDecimalDigit();
int inputNumber();
int useSwitch();
void resultForEachNumber(int);

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
	cout << "Setting integer:\nnumber =  ";
	cin >> num;
	system("cls");
	return num;
}

int inputDecimalDigit()
{
	int symbol;
	cout << "Setting symbol:\nsymbol =  ";
	cin >> symbol;
	system("cls");
	return symbol;
}

int useSwitch()
{
	switch (inputCase())
	{
		case 'a':
		{
			return quantityOfSymbolForDecimals(decimalToBinary(inputNumber()), inputDecimalDigit());
			break;
		}

		case 'b':
		{
			return quantityOfSymbolForHexadecimals(inputNumber(), convertHexadecimalToDecimal());
			break;
		}

		case 'c':
		{
			resultForEachNumber(inputDecimalDigit());
			break;
		}
		default:
		{
			break;
		}
	}
}

void resultForEachNumber(int symbol)
{
	const int N = 100;
	int array[N] = { 0 };
	int n = inputNumber();

	inputArray(n, array);

	for (int i = 0; i < n; i++)
	{
		cout << "For number " << array[i] << " & digit " << symbol << ' ';
		outputResult(quantityOfSymbolForDecimals(decimalToBinary(array[i]), symbol));
	}
	
}




